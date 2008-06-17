declare namespace ns1 = "myns";
declare variable $ns1:x := 1;
declare variable $ns1:y := 40;
eval { '
declare namespace ns2 = "myns";
declare variable $ns2:x := 2;
$ns1:x + $ns1:y
' }
