
declare namespace opt = "http://zorba.io/options/optimizer";

declare construction strip;

import schema namespace s="http://www.zorba-xquery.org/simple" at "simple.xsd";

declare option opt:enable "for-serialization-only";

declare variable $doc := <s:person><s:name>foo</s:name><s:age>25</s:age></s:person>;

let $vdoc := validate { $doc }
let $copy := <root>{$vdoc/s:name}</root>
return $copy/s:name instance of element(*, xs:string)
