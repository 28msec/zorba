import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx"; 

declare namespace test = "http://www.zorba-xquery.com/test";

sctx:statically-known-namespaces() = "sctx", sctx:statically-known-namespaces() = "test", sctx:statically-known-namespaces() = "namespace-not-declared"
