declare namespace ann = "http://www.zorba-xquery.com/annotations";


declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";


declare function local:collapseNodes($x as node()*) as node()*
{
  for $y in $x
  let $n := node-name($y)
  group by $n
  order by string($n)
  return local:collapseNodesSameName($y)
};


declare function local:collapseNodesSameName($x as node()+) as node()+
{
  variable $f := $x[1];
  variable $n := node-name($f);
  variable $a := $x/@*;
  variable $c := $x/*;
  variable $ca := local:collapseNodes($a);
  variable $cc := local:collapseNodes($c);

  if ($f instance of element()) then
     element {$n} { $ca, $cc }
  else
    attribute {$n} {"a"}
};


declare variable $input as element()* := doc('books.xml')/*/*;

local:collapseNodesSameName($input)

