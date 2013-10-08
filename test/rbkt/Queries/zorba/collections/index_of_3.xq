import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test()
{
  exit returning dml:index-of(dml:collection(xs:QName("ns:test1"))[2]);
};

local:test()
