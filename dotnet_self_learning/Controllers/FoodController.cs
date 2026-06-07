using Microsoft.AspNetCore.Mvc;
using OFOSWebApi.DTOs;
using OFOSWebApi.Models;
using Microsoft.AspNetCore.Cors;
using Microsoft.EntityFrameworkCore;
using System.Linq.Expressions;

namespace OFOSWebApi.Controllers
{
    [Route("food")]
    [ApiController]
    public class FoodController : Controller
    {
        private readonly AppDbContext _context;
        private readonly IWebHostEnvironment _environment;
      
        public FoodController(AppDbContext context, IWebHostEnvironment environment)
        {
            _context = context;
            _environment= environment;
        }
        [HttpGet("menu")]
        public async Task<IActionResult> Menu()
        {
            try
            {
                var foods = await _context.Foods.ToListAsync();
                return Ok(ResultHelper.Success(foods));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }



        }
        [HttpPost]
        public async Task<IActionResult> AddFood([FromForm] FoodCreateDto dto)
        {
            try
            {
                string fileName = "";
                if(dto.Image !=null)
                {
                    fileName = $"{dto.Image.FileName}";
                    string folderPath = Path.Combine(_environment.WebRootPath, "FoodImages");

                    if (!Directory.Exists(folderPath))
                        Directory.CreateDirectory(folderPath);

                    string filePath = Path.Combine(folderPath, fileName);
                    using var stream = new FileStream(filePath, FileMode.Create);
                    await dto.Image.CopyToAsync(stream);

                    var food = new Food
                    {
                        Name = dto.Name,
                        Price = dto.price,
                        Description = dto.Description,
                        Image = fileName

                    };

                    _context.Foods.Add(food);
                    await _context.SaveChangesAsync();
                    return Ok(ResultHelper.Success(food));
                                
                }
                return BadRequest(ResultHelper.Error<string>("Image is required"));

            }
            catch(Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message)) ;
            }
        }

    }
}
