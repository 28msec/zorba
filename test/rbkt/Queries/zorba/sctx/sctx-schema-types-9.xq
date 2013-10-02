import module namespace sctx = "http://zorba.io/modules/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

sctx:in-scope-schema-types() = xs:QName("xs:string"),
sctx:in-scope-schema-types() = xs:QName("xs:int"),
sctx:in-scope-schema-types() = xs:QName("xs:type-not-declared")
