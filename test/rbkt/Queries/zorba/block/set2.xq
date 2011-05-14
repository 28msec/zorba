declare variable $x := 1;

declare %sequential function local:f()
{
  $x := $x + 2;
};

$x := $x + 1;
local:f();
$x
