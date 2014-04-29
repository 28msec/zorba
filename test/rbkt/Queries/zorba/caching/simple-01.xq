declare namespace an = "http://zorba.io/annotations";

declare function local:dummy()
{
  ()
};


declare %an:cache function local:test-01-cache($x as xs:integer)
{
  if ($x < 10)
  then $x * $x
  else if ($x < 20)
  then local:dummy()
  else ($x, " == ", $x * $x)
};


local:test-01-cache(2),
"
",
local:test-01-cache(12),
"
",
local:test-01-cache(2),
"
",
local:test-01-cache(12),
"
",
local:test-01-cache(22),
"
",
local:test-01-cache(22),
"
"
