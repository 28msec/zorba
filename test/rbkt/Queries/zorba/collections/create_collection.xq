import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:create() {
  ddl:create(xs:QName("ns:test1"));
  ddl:create(xs:QName("ns:test2"));
  exit returning ddl:is-available-collection(xs:QName("ns:test1")) and ddl:is-available-collection(xs:QName("ns:test2"));
};

declare %ann:sequential function local:create-and-insert() {
  ddl:create(xs:QName("ns:test3"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning ddl:is-available-collection(xs:QName("ns:test3")) and fn:count(dml:collection(xs:QName("ns:test3"))) eq 10;
};


{
  variable $create := local:create();

  variable $create-and-insert := local:create-and-insert();

  $create or $create-and-insert
}
