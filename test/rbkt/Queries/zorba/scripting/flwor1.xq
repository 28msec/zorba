import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test3()
{
  ddl:create($col, (<a></a>,<b></b>));

  for $x in dml:collection($col)
  return
    {
      dml:insert-last($col, <c></c>);
    }

  dml:collection($col)
};

local:test3()

