xquery version "1.1";

import module namespace util = "http://www.zorba-xquery.com/util" at "xquery_spec.xqi";

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import module namespace functx = "http://www.functx.com";

declare variable $xquery_version as xs:string := "1.1";

declare variable $specPath as xs:string external;
declare variable $specURI  as xs:string external;


(
(:util:download-and-write-spec($specURI, $specPath), :)

let $specFuncs := util:create-spec-function-arity-sequence($specPath, $xquery_version),
    $zorbaFuncs := util:create-zorba-function-arity-sequence(sctx:function-names())
return
  <result>
    <notImplemented>{functx:value-except($specFuncs,$zorbaFuncs)}</notImplemented>
    <notInSpec>{functx:value-except($zorbaFuncs,$specFuncs)}</notInSpec>
  </result>
)