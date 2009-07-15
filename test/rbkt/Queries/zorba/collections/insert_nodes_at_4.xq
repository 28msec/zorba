import module namespace coll = "http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:create-collection("test");
  coll:insert-nodes-at("test", 0, <a />);
  fn:collection("test");
};

local:test();
