import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ann = "http://zorba.io/annotations";


declare variable $col := xs:QName("myCollection");


declare function local:test1()
{
  dml:collection($col)
};


declare %ann:sequential function local:test2()
{
  dml:insert-last($col, (<c><cc1/></c>, <e/>));

  dml:collection($col)
};


ddl:create($col, (<a/>, <b/>));

for $k in (4, 5)
for $i in local:test2()
for $j in (1, 2, 3)
return <res>{if ($i/*) then $i/* else local-name-from-QName($col)}</res> 
