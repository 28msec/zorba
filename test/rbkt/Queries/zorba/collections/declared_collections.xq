import module namespace sc = "http://www.zorba-xquery.com/modules/introspection/sctx";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

for $x in sc:declared-collections()
order by xs:string($x)
return $x
