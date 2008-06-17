declare namespace ns1 = "myns";
declare namespace ns2 = "myns";
let $ns1:x := 3 return
using $ns1:x, $ns2:x eval { "$ns1:x" }
