
declare function local:dummy($x as xs:integer)
{
 $x
};


declare function local:foo($x as xs:integer) as xs:integer+
{
  $x * $x,
  local:dummy($x)
};


for $x in (<a>1</a>, <a>2</a>, <a>3</a>)
let $y :=
  { 
    variable $a as xs:integer:= 1;

    for $z in local:foo(1)
    where xs:integer($x) eq $z + $a
    return $z
  }
return (<res>{$x, count($y), sum($y)}</res>, "&#xA;")
