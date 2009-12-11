import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"), <a><b>Foo</b></a>);

  replace value of node ddl:collection(xs:QName("ns:test1"))[1]/b with "Bar";

  ();
};

local:test();
