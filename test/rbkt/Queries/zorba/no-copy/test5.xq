declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare construction strip;

declare copy-namespaces preserve, no-inherit;

import schema namespace s="http://www.zorba-xquery.org/simple" at "simple.xsd";

declare option opt:enable "for-serialization-only";

declare variable $doc := <s:person><s:name>foo</s:name><s:age>25</s:age></s:person>;

let $vdoc := validate { $doc }
let $copy := <root>{$vdoc/s:name}</root>
let $copyname := $copy/s:name
return ($copyname, "   ", $copyname instance of element(*, xs:string))
