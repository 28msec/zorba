import module namespace sctx = "http://zorba.io/modules/sctx";

for $var in sctx:in-scope-variables()
order by xs:string($var)
return $var
