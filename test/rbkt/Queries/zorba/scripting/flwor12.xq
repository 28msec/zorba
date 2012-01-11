

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";


declare variable $col := xs:QName("myCollection");


declare function local:test1()
{
  dml:collection($col)
};


declare %ann:sequential function local:test2()
{
  dml:insert-nodes-last($col, (<c><cc1/></c>, <e/>));

  dml:collection($col)
};


ddl:create($col, (<a/>, <b/>));

for $k in (4, 5)
for $i in local:test2()
for $j in (1, 2, 3)
return <res>{if ($i/*) then $i/* else local-name-from-QName($col)}</res> 
