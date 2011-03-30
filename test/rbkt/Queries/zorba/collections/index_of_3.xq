import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  exit returning manip:index-of((),manip:collection(xs:QName("ns:test1"))[2]);
};

local:test()
