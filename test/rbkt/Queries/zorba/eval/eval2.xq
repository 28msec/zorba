
import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare variable $var := 42;

declare function local:getQuery() as xs:string 
{
  "$x + $y + local:f()"
};


declare function local:f() 
{
  1 + 1
};


for $y in 1 to 10
let $x := $var
where $y mod 2 eq 0
return refl:eval(local:getQuery())
