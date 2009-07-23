import module namespace coll =
"http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:test()
{
  coll:create-collection("test", <a><b>Foo</b></a>);

  replace value of node collection("test")[1]/b with "Bar";

  coll:insert-nodes-at("test", 2, <a />);

  ();
};

local:test();
