import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:foo($collName as xs:QName) {
  ddl:create-collection($collName,<a/>);
  let $a := dc:collection($collName)
  return ddl:insert-nodes-last($collName, <b/>);
  exit returning ();
};


let $collName := xs:QName("ns:collection_1")
return local:foo($collName)
