using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using OFOSWebApi.DTOs;
using OFOSWebApi.Models;
namespace OFOSWebApi.Controllers
{
    [Route("order")]
    [ApiController]
    public class OrderController : ControllerBase
    {
        private readonly AppDbContext _context;
        private readonly IWebHostEnvironment _environment;

        public OrderController(AppDbContext context, IWebHostEnvironment environment)
        {
            _context = context;
            _environment = environment;
        }

        [Authorize]
        [HttpPost("place_order")]
        public async Task<IActionResult> PlaceOrder(PlaceOrderDto dto)
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            // Here you would typically call a service to handle the order placement logic, such as validating the cart items, calculating totals, and saving the order to the database.
            var order = new Order
            {
                Uid = uid,
                TotalAmount = dto.TotalAmount,
                Odate = DateTime.UtcNow

            };

            _context.Orders.Add(order);
            await _context.SaveChangesAsync();

            foreach(var item in dto.CartItems)
            //here CartItems is a list of CartItemDto which contains Fid, Quantity and Price
            {
                var food = await _context.Foods.FindAsync(item.Fid);
                var orderDetail = new OrderDetail
                {
                    Oid = order.Oid,
                    Fid = item.Fid,
                    Quantity = item.Qty,
                    Price= (decimal)food.Price * item.Qty


                    //why price is showing error it is bcoz in OrderDetail model there is no price property but in OrderDetailDto there is price property so we need to add price property in OrderDetail model and then we can assign the value to it


                };

                _context.OrderDetails.Add(orderDetail);
            }

            await _context.SaveChangesAsync();
            return Ok(ResultHelper.Success( $"Order placed successfully"));

        }

        //for the above api we have to send the request in postman like this http://localhost:xxxx/order/place_order and in body we have to send the json data like this so the data shpold contain the parameters of PlaceOrderDto class which are TotalAmount and CartItems and CartItems is a list of CartItemDto which contains Fid, Quantity and Price
        //get Orders API
        [Authorize]
        [HttpGet("get_orders")]

        public async Task <IActionResult> GetOrders()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            var orders = await _context.Orders
                .Where(o=> o.Uid==uid)
                .Include(o=>o.OrderDetails)
                .ToListAsync();
            return Ok(ResultHelper.Success(orders));
        }

    }
}