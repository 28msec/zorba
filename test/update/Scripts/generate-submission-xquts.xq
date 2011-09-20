(: Schema for results :)
import schema default element namespace "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_update_reportingresults/XQTSResult.xsd";

(: Test.xml file from ctest :)
declare variable $ctests as document-node() external;

if(fn:empty($ctests)) then
  fn:error()
else
  validate {
    <test-suite-result>
       <implementation name="Zorba" 
         version='2.0 (svn rev. 11228)'
         anonymous-result-column="false">
  
      <organization
        name='FLWOR Foundation'
        website="http://zorba-xquery.com/"
        anonymous="false" />
    
      <submittor
        name="Zorba Team"
        email="contact@zorba-xquery.com" />
      
      <description>
        <p>Zorba is a general purpose XQuery processor implementing in C++
        the W3C family of specifications. It is not an XML database.
        The query processor has been designed to be embeddable in a
        variety of environments such as other programming languages
        extended with XML processing capabilities, browsers,
        database servers, XML message dispatchers, or smartphones.
        Its architecture employes a modular design, which allows customizing
        the Zorba query processor to the environment’s needs.
        In particular the architecture of the query processor allows a
        pluggable XML store (e.g. main memory, DOM stores, persistent
        disk-based large stores, S3 stores). Zorba runs on most platforms
        and is available under the Apache license v2. Currently, Zorba
        implements the following W3C specifications: XQuery 1.0, XQuery Update
        Facility 1.0, XQuery Scripting Extension 1.0, and XSLT 2.0 and XQuery 1.0
        Serialization.</p>
      </description>
      
    {
      let $XQUTSZorba := fn:doc("XQUTS.xml")
      return
      (
        <implementation-defined-items>{$XQUTSZorba//*:implementation-defined-item}</implementation-defined-items>,
        <features>{$XQUTSZorba//*:feature}</features>,
        <context-properties>{$XQUTSZorba//*:context-property}</context-properties>
      )
    }
            
    </implementation>

    <syntax>XQuery</syntax>
    
    <test-run dateRun="2011-07-13">
      <test-suite version="current"/>
      <transformation><p>Standard</p></transformation>
      <comparison><p>Standard</p></comparison>
      <otherComments><p>XQUTS version taken from CVS as of July 13th 2011.</p></otherComments>
    </test-run>
  
    {
      for $test in $ctests/*:Site/*:Testing/*:Test
      let $testname := fn:tokenize(fn:data($test/*:Name), "/")[last()]
      return
      if(fn:exists(fn:index-of(('revalidation-declaration-01-fail','revalidation-declaration-03-fail','revalidation-declaration-05-fail','revalidate-valtrans-ins-003'
      ,'fn-put-003-fail','fn-put-004-fail','fn-put-005-fail','fn-put-006-fail'),$testname))) then
      <test-case
         name="{$testname}"
         result="not applicable"
         comment="this test was not run by Zorba: please consult the 'Guidelines for Running the XML Query Update Test Suite' for more details."
       />
      else if (fn:contains(fn:data($test),'StaticTypingFeature')) then
      <test-case
         name="{$testname}"
         result="not applicable"
         comment="Zorba does not support the 'Update Facility Static Typing Feature'"
       />
      else
       <test-case
         name="{$testname}"
         result="{fn:substring(fn:data($test/@Status), 0, 5)}"
       />
     }
  </test-suite-result>
}
