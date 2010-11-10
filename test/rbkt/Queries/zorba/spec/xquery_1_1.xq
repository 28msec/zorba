xquery version "1.1";

import module namespace util = "http://www.zorba-xquery.com/util" at "xquery_spec.xqi";

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import module namespace functx = "http://www.functx.com" at "functx.xqi";


declare variable $specPath as xs:string external;
declare variable $specURI  as xs:string := "http://www.w3.org/TR/xpath-functions-11/";

declare sequential function local:create-zorba-function-arity-sequence()
as xs:string* {
  let $funcQnames as xs:QName* := sctx:function-names()
  return
    for $funcQname in $funcQnames
    where (fn:namespace-uri-from-QName($funcQname) = "http://www.w3.org/2005/xpath-functions" and
           fn:prefix-from-QName($funcQname) = "fn")
    order by fn:local-name-from-QName($funcQname)
    return
      for $arity in sctx:function-arguments-count($funcQname)
      order by $arity
      return
        fn:concat(fn:local-name-from-QName($funcQname),"#", fn:string($arity))
};

(
(:util:download-and-write-spec($specURI, $specPath), :)

let $implementedTranslator := ("string-length#0", "normalize-space#0", "root#0",
                               "base-uri#0", "namespace-uri#0", "local-name#0",
                               "name#0", "string#0", "number#0", "number#1", "last#0",
                               "lang#1", "resolve-uri#1", "position#0", "static-base-uri#0"),
    $specFuncs := util:create-spec-function-arity-sequence($specPath),
    $zorbaFuncs := local:create-zorba-function-arity-sequence(),
    $zorbaFuncs := functx:value-union($zorbaFuncs, $implementedTranslator)

return
  <result>
    <notImplemented>{functx:value-except($specFuncs,$zorbaFuncs)}</notImplemented>
    <notInSpec>{functx:value-except($zorbaFuncs,$specFuncs)}</notInSpec>
  </result>
)