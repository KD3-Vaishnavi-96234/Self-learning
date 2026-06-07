using static System.Runtime.InteropServices.JavaScript.JSType;

namespace OFOSWebApi.DTOs
{
    public class ApiResult<T>
    {
        public string Status {  get; set; }
        public T Data { get; set; }
        public string Error { get; set; }
    }
    public class ResultHelper
    {
        public static ApiResult <T> Success<T>(T data)
        {
            return new ApiResult <T>
            { 
                Status = "success",
                Data = data, 
                Error = null
            };


        }
        public static ApiResult<T> Error<T>(string error)
        {
            return new ApiResult<T>
            {
                Status = "Error",
                Data = default,
                Error = error
            };

        }

    }
}
