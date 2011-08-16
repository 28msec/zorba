
declare function local:collapseNodes($x as node()*, $s as xs:string)
{
  if(empty($x))
  then text {$s}
  else
    for $y in $x
    return local:collapseNodesSameName($y, $s)
};


declare function local:collapseNodesSameName($x as node()+, $s as xs:string)
{
  let $a :=$x/@*
  return local:collapseNodes($a, $s)
};


let $input := (<a b="3"></a>, <a b="4"/> )
return local:collapseNodesSameName($input, "")
