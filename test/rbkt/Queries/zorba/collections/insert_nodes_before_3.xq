import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:insert-nodes-before((),fn:collection("a")[2], <z/>);
  exit with fn:collection(());
};

local:test()
