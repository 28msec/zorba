import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:remove-node-at(2);
  exit with fn:collection();
};

local:test()
