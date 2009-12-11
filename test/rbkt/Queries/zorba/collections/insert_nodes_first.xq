import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  ddl:create-collection(xs:QName("ns:test1"));
  exit returning dc:is-available-collection(xs:QName("ns:test1"));
};

declare sequential function local:insert() {
  ddl:insert-nodes-first(xs:QName("ns:test1"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning ddl:collection(xs:QName("ns:test1"));
};


declare variable $x := 0;

set $x := local:create();

if (fn:not($x)) then
  fn:false()
else 
  local:insert();
