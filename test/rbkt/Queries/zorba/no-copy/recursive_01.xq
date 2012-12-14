declare namespace ann = "http://www.zorba-xquery.com/annotations";


declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";


declare function local:collapseNodes($x as node()*) as node()*
{
  for $y in $x
  let $n := node-name($y)
  group by $n
  order by string($n)
  return local:collapseNodesSameName(element {$n} {$y})
};


declare function local:collapseNodesSameName($x as node()) as node()+
{
  variable $f := $x/*[1];
  variable $c := $x/*/*;
  variable $cc := local:collapseNodes($c);

  element { node-name($x/*/..) } { $cc }
};


declare variable $input as element()* := <book>{doc('books.xml')/*/*}</book>;

local:collapseNodesSameName($input)
,
"

"
