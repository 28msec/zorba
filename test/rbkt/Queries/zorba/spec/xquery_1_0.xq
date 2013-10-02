xquery version "1.0";

import module namespace util = "http://www.zorba-xquery.com/util" at "xquery_spec.xqi";

import module namespace sctx = "http://zorba.io/modules/sctx";
import module namespace functx = "http://www.functx.com";

declare variable $xquery_version as xs:string := "1.0";

declare variable $specPath as xs:string external;


declare function local:create-zorba-function-arity-sequence($functionNames as xs:QName*)
as xs:string* {
  for $funcQname in $functionNames
  where (fn:namespace-uri-from-QName($funcQname) = "http://www.w3.org/2005/xpath-functions")
  order by fn:local-name-from-QName($funcQname)
  return
    for $arity in sctx:function-arguments-count($funcQname)
    order by $arity
    return
      fn:concat(fn:local-name-from-QName($funcQname),"#", fn:string($arity))
};


(
(:util:download-and-write-spec($xquery_version, $specPath), :)

let $specFuncs := util:create-spec-function-arity-sequence($specPath, $xquery_version),
    $zorbaFuncs := local:create-zorba-function-arity-sequence(sctx:function-names())
return
  <result>
    <notImplemented>{functx:value-except($specFuncs,$zorbaFuncs)}</notImplemented>
    <notInSpec>{functx:value-except($zorbaFuncs,$specFuncs)}</notInSpec>
  </result>
)
