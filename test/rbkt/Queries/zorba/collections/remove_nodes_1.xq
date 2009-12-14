import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  xqddf:create-collection(xs:QName("ns:test1"));
  xqddf:insert-nodes-last(xs:QName("ns:test1"), <a/>);
  xqddf:insert-nodes-last(xs:QName("ns:test1"), <b/>);
  xqddf:insert-nodes-last(xs:QName("ns:test1"), <c/>);
  xqddf:delete-nodes(xs:QName("ns:test1"), xqddf:collection(xs:QName("ns:test1"))[position()<3]);
  exit returning xqddf:collection(xs:QName("ns:test1"));
};

local:test()
