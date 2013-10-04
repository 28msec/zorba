
import module namespace util = "http://zorba.io/modules/reflection";

declare namespace ns1 = "NS1";

declare variable $ns1:x := 1;

declare variable $ns1:y := 40;

<result xmlns:ns3 = "NS3">
{
util:eval
( 
'
declare namespace ns2 = "NS1";

variable $ns2:x := 2;

variable $ns3:x := 20;

$ns1:x + $ns1:y + $ns3:x
' 
)
}
</result>
