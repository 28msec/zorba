import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";

fn:distinct-values(
for $funcQname in sctx:function-names()
order by fn:namespace-uri-from-QName($funcQname)
return fn:namespace-uri-from-QName($funcQname))