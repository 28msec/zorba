import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:foo($collName as xs:QName) {
  ddl:create-collection($collName,<a/>);
  let $a := ddl:collection($collName)
  return ddl:insert-nodes-last($collName, <b/>);
  exit returning ();
};


let $collName := xs:QName("ns:collection_1")
return local:foo($collName)
