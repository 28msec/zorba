import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-attribute-declarations() = xs:QName("types:myAttribute"),
sctx:in-scope-attribute-declarations() = xs:QName("xs:myAttribute"),
sctx:in-scope-attribute-declarations() = xs:QName("xs:myComplex"),
sctx:in-scope-attribute-declarations() = xs:QName("types:myComplex"),
sctx:in-scope-attribute-declarations() = xs:QName("types:myProduct")

