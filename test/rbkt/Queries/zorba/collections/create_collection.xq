import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  init:create-collection(xs:QName("ns:test1"));
  init:create-collection(xs:QName("ns:test2"));
  exit returning manip:is-available-collection(xs:QName("ns:test1")) and manip:is-available-collection(xs:QName("ns:test2"));
};

declare sequential function local:create-and-insert() {
  init:create-collection(xs:QName("ns:test3"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning manip:is-available-collection(xs:QName("ns:test3")) and fn:count(manip:collection(xs:QName("ns:test3"))) eq 10;
};

let $create := local:create()
let $create-and-insert := local:create-and-insert()
return
  $create or $create-and-insert
