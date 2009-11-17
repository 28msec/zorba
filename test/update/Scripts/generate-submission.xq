(: Schema for results :)
import schema namespace res = "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_update_reportingresults/XQTSResult.xsd";

(: Test.xml file from ctest :)
declare variable $ctests as document-node() external;

validate lax {
  <res:test-suite-result
     xmlns:red="http://www.w3.org/2005/02/query-test-XQTSResult">
     <res:implementation name="Zorba">
        <res:organization name="FLWOR Foundation"/>
        <res:submittor name="FLWOR Foundation team"/>
        (: add implementation-defined-items and features elements here :)
     </res:implementation>
     <res:syntax>XQuery</res:syntax>
     (: can we compute dateRun from $ctests/Site/Testing/StartTimeTime ? :)
     <res:test-run dateRun="2009-11-16">
        <res:test-suite version="1.0"/>
     </res:test-run>
     {
       for $test in $ctests/Site/Testing/Test
       let $testpath := fn:tokenize(fn:data($test/Name), "/")
       let $testname := $testpath[fn:count($testpath)]
       return
         <res:test-case
           name="{$testname}"
           result="{fn:substring(fn:data($test/@Status), 0, 5)}"
         />
     }
  </res:test-suite-result>
}
