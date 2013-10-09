import module namespace sctx = "http://zorba.io/modules/sctx";

declare variable $test := "test";

sctx:in-scope-variables() = xs:QName("test")
