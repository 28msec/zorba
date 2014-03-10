
declare namespace opt = "http://zorba.io/options/optimizer";

import module namespace refl = "http://zorba.io/modules/reflection";

declare option opt:enable "for-serialization-only";


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


local:constr($doc)
,
refl:eval("local:foo(local:constr($doc)//c)")
