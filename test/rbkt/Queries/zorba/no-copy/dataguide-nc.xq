import module namespace map = "http://zorba.io/modules/unordered-maps";

declare namespace ann = "http://zorba.io/annotations";

declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

declare %ann:assignable variable $co as xs:integer :=0;

declare variable $map1 := "map-co";

declare variable $str := QName ("http://www.w3.org/2001/XMLSchema", "string");

declare variable $input as element()* := doc('books.xml')/*/*;


declare function local:string-name($x as xs:QName)
{
  let $y :=namespace-uri-from-QName($x)
  return
    if(empty($y))
    then local-name-from-QName($x)
    else concat($y, concat ("/", local-name-from-QName($x)))
};


declare %ann:sequential function local:collapseNodes(
  $x as node()*,
  $e as xs:boolean,
  $s as xs:string) as node()*
{
  if(empty($x))
  then ()
  else
    for $y in $x
    let $n := node-name($y)
    group by $n
    order by string($n)
    return local:collapseNodesSameName($y, $e, $s)
};


declare %ann:sequential function local:collapseNodesSameName(
    $x as node()+,
    $e as xs:boolean, 
    $s as xs:string) as node()*
{
  variable $label as xs:integer ?;
  variable $f:= $x[1];
  variable $n :=node-name($f);
  variable $s2 := concat($s, concat("/", local:string-name($n)));
  variable $a :=$x/@*;
  variable $c :=$x/*;
  variable $ca := local:collapseNodes($a, false(), $s2);
  variable $cc := local:collapseNodes($c, true(), $s2);

  $label := map:get($map1, $s2);

  if (empty($label)) then
  {
    $co := $co +1;
    $label := $co;
    map:insert($map1, $s2, $co); 
  }
  else 
  {
  }

  if($e) then
    if(empty($c)) then
    { 
      element  {$n }  { attribute {"L"} {$label}, $ca}
    }
    else
      element {$n } { attribute {"L"} {$label}, $ca, $cc }
  else 
  {
    attribute {$n} {$label}
  }
};


map:create($map1, $str);

variable $DG := local:collapseNodesSameName($input, true(), "");

map:drop($map1);

$DG
