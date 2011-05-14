import module namespace coll = "http://www.zorba-xquery.com/modules/store/collections";

declare variable $col := xs:QName("myCollection");

declare %sequential function local:test()
{
  coll:create-collection($col, (<a><c>1</c></a>,<b>2</b>));

  for $i in (1 to 3)
  where $i > 1
  for $j in (1 to 2)
  let $c := count(coll:collection($col)) + $j
  return
    {
      coll:delete-nodes(coll:collection($col)[$i]);
      coll:insert-nodes-first($col, <x i="{$i}">{$c}</x>);
      coll:insert-nodes-last($col, <x i="{$i}">{$c}</x>);
    }

  coll:collection($col)
};

local:test()


(:

i , j , c

2 , 1 , 3 --> <x i=2 3> <a> <x i=2 3>

2 , 2 , 4 --> <x i=2 4> <x i=2 3> <x i=2 3> <x i=2 4>

3 , 1 , 3 --> <x i=3 3>   <x i=2 4> <x i=2 3> <x i=2 4>   <x i=3 3>

3 , 2 , 4 --> <x i=3 4>   <x i=3 3> <x i=2 4> <x i=2 4> <x i=3 3>   <x i=3 4>
:)
