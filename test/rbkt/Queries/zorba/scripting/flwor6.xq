import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test()
{
  ddl:create($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := dml:collection($col)[1]/c
  for $i in (1 to count(dml:collection($col)) + 1)
  order by $i descending
  return
    {
      dml:delete-nodes(dml:collection($col)[$i]);
      dml:insert-nodes-first($col, <x i="{$i}">{$x}-{$i}</x>);
      dml:insert-nodes-last($col, <x i="{$i}">{$x}-{$i}</x>);
    }

  dml:collection($col)
};

local:test()
