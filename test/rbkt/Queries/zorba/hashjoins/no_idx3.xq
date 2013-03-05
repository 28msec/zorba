
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
let $y := 2
for $z in local:foo($y)
count $w
where xs:integer($x) eq $z
return <res>{$z, $y, $w}</res>
