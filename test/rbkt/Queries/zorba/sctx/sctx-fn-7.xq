import module namespace sctx = "http://zorba.io/modules/sctx";

for $x in sctx:function-names()
order by fn:namespace-uri-from-QName($x), fn:local-name-from-QName($x)
return $x
