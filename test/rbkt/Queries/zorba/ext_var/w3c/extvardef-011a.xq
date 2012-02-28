declare variable $x external := 3 + local:foo();
declare variable $b external := 2 + local:foo();

declare function local:foo()
{
  $b
};

$x
