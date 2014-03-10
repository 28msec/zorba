import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test()
{
  ddl:create($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := dml:collection($col)[1]/c
  return
    {
      dml:delete(dml:collection($col)[1]);
      dml:insert-first($col, <x>{$x}</x>);
    }

  dml:collection($col)
};

local:test()
