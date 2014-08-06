import module namespace sctx = "http://zorba.io/modules/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-schema-types() = xs:QName("types:myComplex"),
sctx:in-scope-schema-types() = xs:QName("types:person"),
sctx:in-scope-schema-types() = xs:QName("types:myProduct"),
sctx:in-scope-schema-types() = xs:QName("types:custGroup")
