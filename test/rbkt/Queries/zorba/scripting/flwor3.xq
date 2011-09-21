import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test()
{
  ddl:create($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := dml:collection($col)[1]/c
  return
    {
      dml:delete-nodes(dml:collection($col)[1]);
      dml:insert-nodes-first($col, <x>{$x}</x>);
    }

  dml:collection($col)
};

local:test()

