import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() 
{
  xqddf:create-collection(xs:QName("ns:test1"));
  xqddf:insert-nodes-first(xs:QName("ns:test1"), for $i in 1 to 10 return <a> { $i } </a>);
  exit returning (fn:count(xqddf:collection(xs:QName("ns:test1"))) eq 10);
};

declare sequential function local:insert() 
{
  xqddf:insert-nodes-last(xs:QName("ns:test1"), for $i in 11 to 13 return <b> { $i } </b>);
  exit returning xqddf:collection(xs:QName("ns:test1"));
};


declare variable $x := 0;

set $x := local:create();

if (fn:not($x)) then
  fn:false()
else 
  local:insert();
