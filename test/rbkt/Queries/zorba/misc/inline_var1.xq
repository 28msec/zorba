
declare function local:id($y as node()) as node()
{
  $y
};


declare function local:foo($x as node(), $z as xs:integer) as xs:double
{
  let $y := $x/b
  return
    if ($x/c)
    then $y/@att1 + $z 
    else local:id($y)/@att2 + $z
};


local:foo(<a><b att1="1" att2="20"/></a>, 10)
