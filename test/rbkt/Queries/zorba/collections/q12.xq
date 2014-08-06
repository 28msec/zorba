import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:foo($collName as xs:QName) {
  ddl:create($collName,<a/>);
  let $a := dml:collection($collName)
  return dml:insert-last($collName, <b/>);
  exit returning ();
};


let $collName := xs:QName("ns:collection_1")
return local:foo($collName)
