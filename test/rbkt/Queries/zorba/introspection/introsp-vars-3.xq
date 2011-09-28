import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

declare variable $test := "test";

count(sctx:in-scope-variables())