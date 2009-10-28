import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:create-collection(xs:QName("ns:test2"));
  exit returning dc:is-available-collection(xs:QName("ns:test1")) and dc:is-available-collection(xs:QName("ns:test2"));
};

declare sequential function local:create-and-insert() {
  ddl:create-collection(xs:QName("ns:test3"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning dc:is-available-collection(xs:QName("ns:test3")) and fn:count(dc:collection(xs:QName("ns:test3"))) eq 10;
};

let $create := local:create()
let $create-and-insert := local:create-and-insert()
return
  $create or $create-and-insert
