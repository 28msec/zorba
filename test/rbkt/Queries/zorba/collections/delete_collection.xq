import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  init:create-collection(xs:QName("ns:test1"));
  init:create-collection(xs:QName("ns:test2"), for $i in 1 to 10 return <a> { $i } </a> );
  exit returning manip:is-available-collection(xs:QName("ns:test1")) and manip:is-available-collection(xs:QName("ns:test2"));
};

declare sequential function local:delete() {
  init:delete-collection(xs:QName("ns:test1"));
  init:delete-collection(xs:QName("ns:test2"));
  exit returning fn:not(manip:is-available-collection(xs:QName("ns:test1")) or manip:is-available-collection(xs:QName("ns:test2")));
};

if (
     let $create := local:create()
     let $delete := local:delete()
     return
       fn:not($create or $delete)
  ) then
  fn:false()
else
  let $create := local:create()
  return
    $create

