import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"), <a><b>Foo</b></a>);

  replace value of node dc:collection(xs:QName("ns:test1"))[1]/b with "Bar";

  ddl:insert-nodes-at(xs:QName("ns:test1"), 2, <a />);

  ();
};

local:test();
