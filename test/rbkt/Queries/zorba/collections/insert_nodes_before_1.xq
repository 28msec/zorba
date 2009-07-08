import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:create-collection("a");
  coll:insert-nodes-first("a", (<a/>, <b/>, <c/>));
  coll:insert-nodes-before("a", fn:collection("a")[2], <z/>);
  exit returning fn:collection("a");
};

local:test()
