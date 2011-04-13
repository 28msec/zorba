declare variable $x := 1;

declare %sequential function local:f () 
{
  set $x := $x + 2
};

set $x := $x + 1;
local:f ();
$x;
