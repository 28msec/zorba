import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:create-collection("a");
  coll:insert-nodes-last("a", <a/>);
  coll:insert-nodes-last("a", <b/>);
  coll:insert-nodes-last("a", <c/>);
  coll:insert-nodes-at("a", 2, <z/>);
  exit with fn:collection("a");
};

local:test()
