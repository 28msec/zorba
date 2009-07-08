import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  exit returning coll:index-of(fn:collection("a")[2]);
};

local:test()
