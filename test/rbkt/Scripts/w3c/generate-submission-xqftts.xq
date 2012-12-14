(: Schema for results :)
import schema default element namespace "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_full_text_reportingresults/XQFTTSResult.xsd";

(: Test.xml file from ctest :)
declare variable $ctests as document-node() external;

if(fn:empty($ctests)) then
  fn:error()
else
  validate {
    <test-suite-result>
      <implementation
        name="Zorba" 
        version="trunk, r10831"
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
        For more details please check out http://www.zorba-xquery.com.</p>
      </description>

    {
      let $XQFTTSZorba := fn:doc("XQFTTS.xml")
      return
      (
        <implementation-defined-items>
        {
          for $idi in $XQFTTSZorba//*:implementation-defined-item
          return
             <implementation-defined-item name="{data($idi/@name)}" value="{data($idi/@value)}" />
        }
        </implementation-defined-items>,
        <features>{$XQFTTSZorba//*:feature}</features>,
        <context-properties>
        {
          for $cp in $XQFTTSZorba//*:context-property
          return
             <context-property name="{data($cp/@name)}" context-type="{data($cp/@context-type)}" value="{data($cp/@value)}" />
        }
        </context-properties>
      )
    }

    </implementation>

    <syntax>XQueryX</syntax>

    <test-run dateRun="2012-05-09">
      <test-suite version="current"/>
      <transformation><p>Standard</p></transformation>
      <comparison><p>Standard</p></comparison>
      <otherComments><p>XQFTTS taken from W3C CVS as of 2012-05-09.</p></otherComments>
    </test-run>

    {
      for $test in $ctests/*:Site/*:Testing/*:Test
      let $testname := fn:tokenize(fn:data($test/*:Name), "/")[last()]
      order by $testname
      return
      <test-case       
        name="{$testname}"
        result="{fn:substring(fn:data($test/@Status), 0, 5)}"
      />
     }
  </test-suite-result>
}
