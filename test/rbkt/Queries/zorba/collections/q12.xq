import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:foo($collName as xs:QName) {
  xqddf:create-collection($collName,<a/>);
  let $a := xqddf:collection($collName)
  return xqddf:insert-nodes-last($collName, <b/>);
  exit returning ();
};


let $collName := xs:QName("ns:collection_1")
return local:foo($collName)
