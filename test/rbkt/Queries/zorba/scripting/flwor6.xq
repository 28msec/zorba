import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test()
{
  ddl:create($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := dml:collection($col)[1]/c
  for $i in (1 to count(dml:collection($col)) + 1)
  order by $i descending
  return
    {
      dml:delete(dml:collection($col)[$i]);
      dml:insert-first($col, <x i="{$i}">{$x}-{$i}</x>);
      dml:insert-last($col, <x i="{$i}">{$x}-{$i}</x>);
    }

  dml:collection($col)
};

local:test()
