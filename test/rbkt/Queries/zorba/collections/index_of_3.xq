import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  exit returning dc:index-of((),dc:collection(xs:QName("ns:test1"))[2]);
};

local:test()
