import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

for $x in init:declared-collections()
order by xs:string($x)
return $x
