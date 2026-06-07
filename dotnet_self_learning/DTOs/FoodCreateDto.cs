namespace OFOSWebApi.DTOs
{
    public class FoodCreateDto
    {
        public string Name { get; set; }
        public decimal price { get; set; }
        public string Description { get; set; }
        public IFormFile? Image {  get; set; }

    }
}
