import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";
declare namespace ext = "http://zorba.io/extensions";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test3()
{
  ddl:create($col, (<a></a>,<b></b>));

  (# ext:materialize #) {
  for $x in dml:collection($col)
  return
    {
      dml:insert-nodes-last($col, <c></c>);
    }
  };

  dml:collection($col)
};

local:test3()

