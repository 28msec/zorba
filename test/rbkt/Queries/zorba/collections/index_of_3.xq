import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  exit returning xqddf:index-of((),xqddf:collection(xs:QName("ns:test1"))[2]);
};

local:test()
