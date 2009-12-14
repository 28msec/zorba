import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  xqddf:create-collection(xs:QName("ns:test1"));
  xqddf:create-collection(xs:QName("ns:test2"), for $i in 1 to 10 return <a> { $i } </a> );
  exit returning dc:is-available-collection(xs:QName("ns:test1")) and dc:is-available-collection(xs:QName("ns:test2"));
};

declare sequential function local:delete() {
  xqddf:delete-collection(xs:QName("ns:test1"));
  xqddf:delete-collection(xs:QName("ns:test2"));
  exit returning fn:not(dc:is-available-collection(xs:QName("ns:test1")) or dc:is-available-collection(xs:QName("ns:test2")));
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

