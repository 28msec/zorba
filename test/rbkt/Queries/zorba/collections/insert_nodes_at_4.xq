import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:collection(xs:QName("ns:test1"));
};

local:test();
