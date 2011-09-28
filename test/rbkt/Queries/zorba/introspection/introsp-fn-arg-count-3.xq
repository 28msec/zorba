import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

count(sctx:function-arguments-count(xs:QName("fn:max")))
