
import module namespace refl = "http://zorba.io/modules/reflection";


declare variable $doc :=
<a>
  <b>
    <c/>
  </b>
</a>
;


declare variable $x := <root>{$doc/b}</root>;


declare function local:dummy($n as node())
{
  $n
};


declare function local:foo($n as node()) as node()*
{
  local:dummy($n),
  $x/b
};


refl:eval("local:foo(<a/>)/..")
