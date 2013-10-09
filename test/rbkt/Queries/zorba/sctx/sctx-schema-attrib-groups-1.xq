import module namespace sctx = "http://zorba.io/modules/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-attribute-groups() = xs:QName("types:personattr"),
sctx:in-scope-attribute-groups() = xs:QName("xs:personattr"),
sctx:in-scope-attribute-groups() = xs:QName("types:custGroup")
