import schema namespace s = "http://www.zorba-xquery.org/schema" at "node_type.xsd";

let $x := <s:person><s:name>blabla</s:name></s:person>
return
  typeswitch($x)
  case $y as element(s:person) return $y/s:name
  default return false()
