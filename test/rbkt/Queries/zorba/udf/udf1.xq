
declare variable $x := 1;

declare function local:foo($x as xs:integer) as xs:integer
{
  $x + 1
};

declare function local:sum($prices as node()*, $x as xs:integer) as xs:integer
{
  local:foo($x) + xs:integer(fn:sum($prices))
};


let $books := 
<books>
<book>
  <price>10</price>
</book>
<book>
  <price>20</price>
</book>
</books>
return local:sum($books//book/price, $x)
