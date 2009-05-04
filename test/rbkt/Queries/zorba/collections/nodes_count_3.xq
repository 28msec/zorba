import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  exit with coll:nodes-count(());
};

local:test()
