import module namespace coll = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test()
{
  coll:create-collection($col, (<a><c>1</c></a>,<b>2</b>));

  let $x := coll:collection($col)[1]/c
  for $i in (1 to count(coll:collection($col)) + 1)
  order by $i descending
  return
    {
      coll:delete-nodes(coll:collection($col)[$i]);
      coll:insert-nodes-first($col, <x i="{$i}">{$x}-{$i}</x>);
      coll:insert-nodes-last($col, <x i="{$i}">{$x}-{$i}</x>);
    }

  coll:collection($col)
};

local:test()
