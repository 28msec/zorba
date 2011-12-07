declare variable $y external;
declare variable $z external := 10;
declare function local:aaa() { $z };
declare variable $x external := local:bbb() + local:aaa() + 2;
declare function local:bbb() { $y };
$x 
