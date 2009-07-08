import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:insert-nodes-after((),fn:collection("a")[2], <z/>);
  exit returning fn:collection(());
};

local:test()
