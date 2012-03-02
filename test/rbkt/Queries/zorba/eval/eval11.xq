
import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";


declare function local:dummy($n as node())
{
};


declare function local:foo($n as node()) as node()*
{
  local:dummy($n),
  $n/ancestor::node()
};


declare function local:constr($n as node()) as node()*
{
  local:dummy($n),
  <root>{$n}</root>
};


declare variable $doc :=
<a>
  <b>
    <c/>
  </b>
</a>
;


refl:eval("local:foo(local:constr($doc)//c)")

