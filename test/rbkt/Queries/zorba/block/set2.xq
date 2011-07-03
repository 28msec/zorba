declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $x := 1;

declare %ann:sequential function local:f()
{
  $x := $x + 2;
};

$x := $x + 1;
local:f();
$x
