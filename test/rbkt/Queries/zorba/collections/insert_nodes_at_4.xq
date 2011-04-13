import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:test()
{
  init:create-collection(xs:QName("ns:test1"));
  manip:collection(xs:QName("ns:test1"));
};

local:test();
