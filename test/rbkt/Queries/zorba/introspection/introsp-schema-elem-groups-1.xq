import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-element-groups() = xs:QName("types:custGroup"),
sctx:in-scope-element-groups() = xs:QName("xs:custGroup"),
sctx:in-scope-element-groups() = xs:QName("types:personattr")