import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test3()
{
  ddl:create($col, (<a/>, <b/>, <c/>, <d/>));

  for $item in dml:collection($col)
  return
    {
      dml:delete($item);
    }

  fn:empty(dml:collection($col))
};


local:test3()
