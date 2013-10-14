import module namespace sctx = "http://zorba.io/modules/sctx";

declare variable $test := "test";

count(sctx:in-scope-variables())
