import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $col := xs:QName("myCollection");

declare %ann:sequential function local:test()
{
  ddl:create($col, (<a><c>1</c></a>,<b>2</b>));

  for $i in (1 to 3)
  where $i > 1
  for $j in (1 to 2)
  let $c := count(dml:collection($col)) + $j
  return
    {
      dml:delete-nodes(dml:collection($col)[$i]);
      dml:insert-nodes-first($col, <x i="{$i}">{$c}</x>);
      dml:insert-nodes-last($col, <x i="{$i}">{$c}</x>);
    }

  dml:collection($col)
};

local:test()


(:

i , j , c

2 , 1 , 3 --> <x i=2 3> <a> <x i=2 3>

2 , 2 , 4 --> <x i=2 4> <x i=2 3> <x i=2 3> <x i=2 4>

3 , 1 , 3 --> <x i=3 3>   <x i=2 4> <x i=2 3> <x i=2 4>   <x i=3 3>

3 , 2 , 4 --> <x i=3 4>   <x i=3 3> <x i=2 4> <x i=2 4> <x i=3 3>   <x i=3 4>
:)
