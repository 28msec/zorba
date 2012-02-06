xquery version "3.0";

import module namespace util = "http://www.zorba-xquery.com/util" at "xquery_spec.xqi";

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import module namespace functx = "http://www.functx.com/";
import module namespace file = "http://expath.org/ns/file";

import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare variable $xquery_version as xs:string := "3.0";

declare variable $specPath as xs:string external;
declare variable $reportPath as xs:string external;

declare function local:generate-report(
  $specFuncs as xs:string*,
  $zorbaFuncs as xs:string*
) {
  <html>
  <head><title>Unimplemented functions</title></head>
  <body>
    <ul>Unimplemented functions ({fn:count($specFuncs)} functions)
      {
        for $func in $specFuncs
        let $funcSpec := fn:concat("http://www.w3.org/XML/Group/qtspecs/specifications/xpath-functions-30/html/Overview.html#func-",
                         fn:substring-before($func,"#"))
        return
          <li><a href="{$funcSpec}">{$func}</a></li>
      }
    </ul>
    <ul>Functions that are not implemented correctly ({fn:count($zorbaFuncs)} functions)
      {
        for $func in $zorbaFuncs
        return
          <li>{$func}</li>
      }
    </ul>
  </body>
  </html>
};

(
 (:util:download-and-write-spec($xquery_version, $specPath),:)

let $specFuncs := util:create-spec-function-arity-sequence($specPath, $xquery_version),
    $zorbaFuncs := util:create-zorba-function-arity-sequence(sctx:function-names()),

    (: remove the following functins :)
    $zorbaFuncs := functx:value-except($zorbaFuncs, ('put#2'))

return
(: in order to generate the html report, comment the <result> node below and uncomment the file:write part :)
  <result>
    <notImplemented>{functx:value-except($specFuncs,$zorbaFuncs)}</notImplemented>
    <notInSpec>{functx:value-except($zorbaFuncs,$specFuncs)}</notInSpec>
  </result>
(:
  file:write(
    $reportPath,
    local:generate-report(
      functx:value-except($specFuncs, $zorbaFuncs),
      functx:value-except($zorbaFuncs, $specFuncs)),
    <output:serialization-parameters>
      <output:method value="xml"/>
      <output:indent value="yes"/>
    </output:serialization-parameters>)
:)
)