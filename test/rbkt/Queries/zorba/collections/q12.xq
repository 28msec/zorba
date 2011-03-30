import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:foo($collName as xs:QName) {
  init:create-collection($collName,<a/>);
  let $a := manip:collection($collName)
  return manip:insert-nodes-last($collName, <b/>);
  exit returning ();
};


let $collName := xs:QName("ns:collection_1")
return local:foo($collName)
