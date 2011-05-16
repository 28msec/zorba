import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test3()
{
  ddl:create-collection($col, (<a></a>,<b></b>));

  for $x in dml:collection($col)
  return
    {
      dml:insert-nodes-last($col, <c></c>);
    }

  dml:collection($col)
};

local:test3()

