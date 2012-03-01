declare variable $a external := 6 + local:foo();
declare variable $b external := 12;
declare function local:foo() { $b + 10 };
$a
