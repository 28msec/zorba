import module namespace sctx = "http://zorba.io/modules/sctx";

fn:distinct-values(
  for $funcQname in sctx:function-names()
  order by fn:namespace-uri-from-QName($funcQname)
  return fn:namespace-uri-from-QName($funcQname)
)
