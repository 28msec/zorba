
declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare function local:dummy()
{
  ()
};


declare %ann:cache function local:foo($x as xs:integer)
{
  if ($x < 10)
  then $x * $x
  else if ($x < 20)
  then local:dummy()
  else ($x, " == ", $x * $x)
};


local:foo(2),
"
",
local:foo(12),
"
",
local:foo(2),
"
",
local:foo(12),
"
",
local:foo(22),
"
",
local:foo(22),
"
"
