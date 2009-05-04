import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";
import module namespace zorba = "http://www.zorba-xquery.com/zorba/node-ref-functions";

declare sequential function local:test()
{
  coll:create-collection("a");
  coll:insert-nodes-last("a", (<a/>,<b><z/></b>,<c/>));
  exit with zorba:node-by-reference(zorba:node-reference(fn:collection("a")[2]));
};

local:test()
