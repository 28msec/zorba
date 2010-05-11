import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-element-declarations() = xs:QName("types:myProduct"),
sctx:in-scope-element-declarations() = xs:QName("xs:myProduct"),
sctx:in-scope-element-declarations() = xs:QName("types:mySimpleType")