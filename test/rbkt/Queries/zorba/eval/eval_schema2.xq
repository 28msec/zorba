
import module namespace util = "http://www.zorba-xquery.com/zorba/util-functions";

import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

import schema namespace any = "http://ns.example.com/any-zorba" at 
                              "$RBKT_SRC_DIR/Queries/zorba/schemas/any.xsd";

refl:eval-simple
(
'
import module namespace util = "http://www.zorba-xquery.com/zorba/util-functions";

import schema namespace a ="http://www.w3.org/XQueryTest" at "../schemas/atomic.xsd";

declare variable $doc as document-node(element(a:root)) := doc("../schemas/atomic.xml");

(
let $vdoc := validate { $doc }
let $x := fn:data(($vdoc//a:decimal)[1])
return ($x instance of xs:decimal, util:schema-type($x))
,
try
{
  validate 
  {
    <any:elem>
      <any_elem xmlns=""/>
    </any:elem>
  }
}
catch * ($code, $desc)
{
   <error>{$desc}</error>
}
)

'
)
