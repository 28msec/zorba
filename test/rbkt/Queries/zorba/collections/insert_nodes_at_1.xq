import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:insert-nodes-last(xs:QName("ns:test1"), <a/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <b/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <c/>);
  ddl:insert-nodes-at(xs:QName("ns:test1"), 2, <z/>);
  exit returning ddl:collection(xs:QName("ns:test1"));
};

local:test()
