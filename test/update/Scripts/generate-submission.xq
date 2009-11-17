(: Schema for results :)
import schema namespace res = "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_update_reportingresults/XQTSResult.xsd";

(: Test.xml file from ctest :)
declare variable $ctests as document-node() external;

if(fn:empty($ctests)) then
  fn:error()
else
validate lax {
  <test-suite-result
     xmlns="http://www.w3.org/2005/02/query-test-XQTSResult">
     <implementation name="Zorba" 
            version='1.0 beta'
            anonymous-result-column="false">

          <organization
             name='FLWOR Foundation'
             website="http://zorba-xquery.com"
             anonymous="false" />
    
          <submittor
             name="Zorba team"
             email="contact@zorba-xquery.com" />
    
          <description>
             <p>An open source XQuery processor that is fast and spec compliant. 
                Implements XQuery 1.0, XQuery Update, XQueryX, XQuery Script.</p>
          </description>
    
          <implementation-defined-items>
          </implementation-defined-items>
          
          <features>
             <feature name='Minimum Conformance' supported='true' />
             <feature name="Update Facility Static Typing Feature" supported='true' />
          </features>
          
          <context-properties>
          </context-properties>
          
     </implementation>
     <syntax>XQuery</syntax>
     (: can we compute dateRun from $ctests/Site/Testing/StartTimeTime ? :)
     <test-run dateRun="2009-11-16">
        <test-suite version="1.0.0"/>
        <transformation><p>No transformations.</p></transformation>
        <comparison><p>Text or xml comparison.</p></comparison>
     </test-run>
     <test-case name="not tested" result="not tested"></test-case>
     {
       for $test in $ctests/Site/Testing/Test
       let $testpath := fn:tokenize(fn:data($test/Name), "/")
       let $testname := $testpath[fn:count($testpath)]
       return
         <test-case
           name="{$testname}"
           result="{fn:substring(fn:data($test/@Status), 0, 5)}"
         />
     }
  </test-suite-result>
}
