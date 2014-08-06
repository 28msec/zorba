import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:create() 
{
  ddl:create(xs:QName("ns:test1"));
  dml:insert-first(xs:QName("ns:test1"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning (fn:count(dml:collection(xs:QName("ns:test1"))) eq 10);
};

declare %ann:sequential function local:insert() 
{
  dml:insert-last(xs:QName("ns:test1"), for $i in 11 to 13 return <b> { $i } </b>);
  exit returning dml:collection(xs:QName("ns:test1"));
};


declare variable $x := 0;

$x := local:create();

if (fn:not($x)) then
  fn:false()
else 
  local:insert()
