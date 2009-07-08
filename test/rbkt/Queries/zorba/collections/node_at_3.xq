import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  exit returning coll:node-at((),2);
};

local:test()
