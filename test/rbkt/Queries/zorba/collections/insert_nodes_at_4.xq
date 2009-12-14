import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  xqddf:create-collection(xs:QName("ns:test1"));
  xqddf:collection(xs:QName("ns:test1"));
};

local:test();
