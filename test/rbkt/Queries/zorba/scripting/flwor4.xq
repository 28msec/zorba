import module namespace dyn = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test3()
{
  dyn:create-collection($col, (<a/>, <b/>, <c/>, <d/>));

  for $i in (1,2,3)
  for $item in dyn:collection($col)
  return
    block
    {
      dyn:delete-nodes($item);
    };

  fn:empty(dyn:collection($col));
};


local:test3()

