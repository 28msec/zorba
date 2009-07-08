import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:remove-nodes((),fn:collection("a")[position()<3]);
  exit returning fn:collection(());
};

local:test()
