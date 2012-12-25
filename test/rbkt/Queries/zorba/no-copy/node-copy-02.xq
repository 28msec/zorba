

declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

import module namespace node = "http://www.zorba-xquery.com/modules/node";

declare copy-namespaces no-preserve, inherit;


declare option opt:enable "for-serialization-only";


declare variable $doc := <a xmlns:p1="www.foo1.com"><b><c/></b></a>;


let $node := <node xmlns:p2="www.foo2.com">{$doc/b}</node>
let $new-node := node:copy($node/b)
return $new-node//c
,
"
"

