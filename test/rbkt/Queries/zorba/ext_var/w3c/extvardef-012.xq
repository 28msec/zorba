declare function local:aaa() { 1 };
declare variable $x external := local:bbb() + local:aaa();
declare function local:bbb() { 2 };
$x 
