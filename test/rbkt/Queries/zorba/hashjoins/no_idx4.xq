

declare function local:dummy($x as xs:integer)
{
 $x
};


declare function local:foo($x as xs:integer) as xs:integer+
{
  $x * $x,
  local:dummy($x)
};


for $a in (1, 2)
for $x in (<a>1</a>, <a>2</a>, <a>3</a>)
count $w
let $y := 
  for $z in local:foo($a)
  where xs:integer($x) eq $z
  return $z
return (<res>{$x, $w, count($y), sum($y)}</res>, "&#xA;")
