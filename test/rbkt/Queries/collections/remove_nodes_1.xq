import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:create-collection("a");
  coll:insert-nodes-last("a", <a/>);
  coll:insert-nodes-last("a", <b/>);
  coll:insert-nodes-last("a", <c/>);
  coll:remove-nodes("a", fn:collection("a")[2]);
  exit with fn:collection("a");
};

local:test()
