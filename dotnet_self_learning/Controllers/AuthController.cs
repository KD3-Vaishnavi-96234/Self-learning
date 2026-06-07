using Microsoft.AspNetCore.Mvc;
using OFOSWebApi.DTOs;
using OFOSWebApi.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Cors;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using Microsoft.EntityFrameworkCore;



namespace OFOSWebApi.Controllers
{
    [ApiController]
    [Route("user")]
    //[EnableCors("ReactPolicy")]
    public class AuthController : ControllerBase
    {
        private readonly AppDbContext _context;
        private readonly IConfiguration _configuration;

        public AuthController(AppDbContext context, IConfiguration configuration)
        {
            _context = context;
            _configuration = configuration;
        }
        [AllowAnonymous]
        [HttpPost("signup")]
        public async Task<IActionResult> Signup(RegisterDto dto)
        {

            try
            {
                string hashedPassword = BCrypt.Net.BCrypt.HashPassword(dto.Password);
                var user = new User
                {
                    Name = dto.Name,
                    Email = dto.Email,
                    Password = hashedPassword,
                    Mobile = dto.Mobile
                };
                _context.Users.Add(user);
                await _context.SaveChangesAsync();
                return Ok(ResultHelper.Success(user));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }


        [AllowAnonymous]
        [HttpPost("signin")]

        public async Task<IActionResult> Signin(LoginDto dto)
        {
            try
            {

                var dbuser = await _context.Users.FirstOrDefaultAsync(x => x.Email == dto.Email);
                if (dbuser == null)
                {
                    return BadRequest(ResultHelper.Error<string>("Invalid Email"));
                }

                bool isPasswordCorrect = BCrypt.Net.BCrypt.Verify(dto.Password, dbuser.Password);

                if (!isPasswordCorrect)
                {
                    return BadRequest(ResultHelper.Error<string>("Invalid Password"));
                }
                var response = new
                {
                    Name = dbuser.Name
                };
                var token = GenerateJwtToken(dbuser);

                return Ok(ResultHelper.Success(new { token, response }));

            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }


        private string GenerateJwtToken(User user)
        {
            var claims = new[]
            {
                new Claim("uid", user.Uid.ToString())
            };
            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_configuration["Jwt:Key"]!));
            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                issuer: _configuration["Jwt:Issuer"],
                audience: _configuration["Jwt:Audience"],
                claims: claims,
                expires: DateTime.Now.AddHours(1),
                signingCredentials: creds
            );
            return new JwtSecurityTokenHandler().WriteToken(token);





        }

        //get User Profile
        [Authorize] //why it is written here because only authorized user can access this api  it is bulit in attribute in file Microsoft.AspNetCore.Authorization
        [HttpGet("profile")]
        //for this in postman we have to set the header key as Authorization and value as Bearer token which we get from signin api. api will be like this http://localhost:xxxx/user/profile/uid is coming from token and we will get it in controller by using User.FindFirst("uid")?.Value
        public async Task<IActionResult> GetProfile()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            var user = await _context.Users.FindAsync(uid);

            if (user == null)
            {
                return NotFound(ResultHelper.Error<string>("User not found"));
            }
            return Ok(ResultHelper.Success(new
            {
                user.Name,
                user.Email,
                user.Mobile
            }));
        }



        //Update Mobile & Delete Account
        [Authorize]
        [HttpPut("update")]
        public async Task<IActionResult> UpdateMobile(UpdateMobileDto dto)
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            //in above syntax we are converting the uid which is in string format to int because in database it is int and we have to find the user by uid and then update the mobile number
            //public virtual DbSet<User> Users { get; set; } ...<User> is in database means in database we have table name Users and in that table we have columns like Uid, Name, Email, Password,
            //Mobile and we have to find the user by uid and then update the mobile number
            //but why we are not using Users here bcoz we are in controller and we have to use _context.Users because _context is the instance of AppDbContext which is the class that inherits
            //from DbContext and in that class we have defined the DbSet<User> Users { get; set; } which is the table in database and we have to use that table to find the user by uid and then update the mobile number
            var user = await _context.Users.FindAsync(uid);
            user!.Mobile = dto.Mobile;
            //why user! this symbol is used because we are sure that user will not be null because we
            //are finding the user by uid which is coming from token and if token is valid then user will
            //be there in database and if token is invalid then it will not reach to this point because of
            //[Authorize] attribute and it will return 401 unauthorized error
            await _context.SaveChangesAsync();
            return Ok(ResultHelper.Success<string>("Mobile number updated successfully"));

        }


        //Delete Account
        [Authorize]
        [HttpDelete("delete")]
        public async Task<IActionResult> DeleteAccount()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            var user = await _context.Users.FindAsync(uid);
            _context.Users.Remove(user!);//why ! is mandatory because we are sure that user will not be null because we are finding the user by uid which is coming from token and if token is valid then user will be there in database and if token is invalid then it will not reach to this point because of [Authorize] attribute and it will return 401 unauthorized error
            await _context.SaveChangesAsync();
            return Ok(ResultHelper.Success<string>("Account deleted successfully"));

        }
    }
}
