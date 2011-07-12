import module namespace z="http://www.zorba-xquery.com/module-dependencies" at "zorba_module_dependencies.xqi";

import module namespace dot="http://www.zorba-xquery.com/modules/image/graphviz";

(: make xqdoc has to be run prior to thins in order to generate the XQDoc XML's :)
(: this variable sets the destination of the XQDoc XML's :)
declare variable $xqdocXMLPath as xs:string external;

(
z:create-collections($xqdocXMLPath)
, dot:dot(z:create_graph(),()) 
(:, z:create_graph():)
,z:delete-collections()
)