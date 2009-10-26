import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:create-collection(xs:QName("ns:test2"), for $i in 1 to 10 return <a> { $i } </a> );
  exit returning dc:is-available-collection(xs:QName("ns:test1")) and dc:is-available-collection(xs:QName("ns:test2"));
};

declare sequential function local:drop() {
  ddl:drop-collection(xs:QName("ns:test1"));
  ddl:drop-collection(xs:QName("ns:test2"));
  exit returning fn:not(dc:is-available-collection(xs:QName("ns:test1")) or dc:is-available-collection(xs:QName("ns:test2")));
};

declare sequential function local:drop-all() {
  ddl:drop-all-collections();
  exit returning fn:not(dc:is-available-collection(xs:QName("ns:test1")) or dc:is-available-collection(xs:QName("ns:test2")));
};

if (fn:not(local:create() or local:drop())) then
  fn:false()
else
  local:create() and local:drop-all()

