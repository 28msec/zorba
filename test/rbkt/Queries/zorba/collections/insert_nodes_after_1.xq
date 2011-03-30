import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  init:create-collection(xs:QName("ns:test1"));
  manip:insert-nodes-last(xs:QName("ns:test1"), <a/>);
  manip:insert-nodes-last(xs:QName("ns:test1"), <b/>);
  manip:insert-nodes-last(xs:QName("ns:test1"), <c/>);
  manip:insert-nodes-after(xs:QName("ns:test1"), manip:collection(xs:QName("ns:test1"))[2], <z/>);
  exit returning manip:collection(xs:QName("ns:test1"));
};

local:test()
