import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test3()
{
  ddl:create-collection($col, (<a/>, <b/>, <c/>, <d/>));

  for $item in dml:collection($col)
  return
    {
      dml:delete-nodes($item);
    }

  fn:empty(dml:collection($col))
};


local:test3()

