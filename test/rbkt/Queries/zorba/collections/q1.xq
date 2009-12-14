import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  xqddf:create-collection(xs:QName("ns:test1"), <a><b>Foo</b></a>);

  replace value of node xqddf:collection(xs:QName("ns:test1"))[1]/b with "Bar";

  ();
};

local:test();
