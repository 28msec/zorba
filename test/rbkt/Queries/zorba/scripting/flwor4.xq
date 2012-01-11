import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test3()
{
  ddl:create($col, (<a/>, <b/>, <c/>, <d/>));

  for $i in (1,2,3)
  for $item in dml:collection($col)
  return
    {
      dml:delete-nodes($item);
    }

  fn:empty(dml:collection($col))
};


local:test3()

