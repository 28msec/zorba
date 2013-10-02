import module namespace sctx = "http://zorba.io/modules/sctx";
import schema namespace types = "http://www.zorba-xquery.com/types" at "types.xsd";

count(sctx:in-scope-schema-types()) > 5
