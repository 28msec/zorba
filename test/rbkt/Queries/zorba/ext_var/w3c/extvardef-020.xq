declare variable $x external := 5;
declare variable $a := $x + 2;
declare function local:foo() {$x +$a};
declare variable $y external := 11 + local:foo() + $x;
$y
