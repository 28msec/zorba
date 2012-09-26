import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

for $var in sctx:in-scope-variables()
order by xs:string($var)
return $var
