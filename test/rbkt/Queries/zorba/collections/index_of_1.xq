import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:insert-nodes-last(xs:QName("ns:test1"), <a/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <b/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <c/>);
  exit returning dc:index-of(xs:QName("ns:test1"),dc:collection(xs:QName("ns:test1"))[2]);
};

local:test()
