import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

declare variable $test := "test";

sctx:in-scope-variables() = xs:QName("test")