import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

for $x in ddl:declared-collections()
order by xs:string($x)
return $x
