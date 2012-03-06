
import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";


declare function local:dummy($n as node())
{
};


declare function local:foo($n as node()) as node()*
{
  local:dummy($n),
  $n/ancestor::node()
};


declare variable $doc :=
<a>
  <b>
    <c/>
  </b>
</a>
;


let $n := <root>{$doc}</root>
return refl:eval("local:foo($n//c)")

