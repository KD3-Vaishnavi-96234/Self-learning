using System;
using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace OFOSWebApi.Models;

public partial class OrderDetail
{
    public int Oid { get; set; }

    public int Fid { get; set; }

    public int? Quantity { get; set; }

    public decimal Price { get; set; }
    [JsonIgnore]
    public virtual Food FidNavigation { get; set; } = null!;
    [JsonIgnore]
    public virtual Order OidNavigation { get; set; } = null!;
}
