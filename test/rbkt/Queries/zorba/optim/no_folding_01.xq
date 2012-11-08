

declare variable $g := 1;


declare function local:boo()
{
  local:foo(0)
};


declare function local:foo($x) as xs:integer
{
  if ($x > 0)
  then
    local:boo()
  else
    $g
};


local:boo()
