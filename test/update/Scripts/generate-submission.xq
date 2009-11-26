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
         version='0.9.9 (svn rev. 7489)'
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
      
         <implementation-defined-items>
           <implementation-defined-item                                                                                             
              name="The revalidation modes that are supported by this implementation."
              value="lax, skip, strict" />

          <implementation-defined-item                                                                                             
             name="The default revalidation mode for this implementation."
             value="lax" />

         </implementation-defined-items>
         
         <features>
            <feature name='Minimum Conformance' supported='true' />
            <feature name="Full Axis Feature" supported='true' />
         </features>
         
         <context-properties>
           <context-property
             name="Revalidation mode"
             value="lax"
             context-type="static"/>
         </context-properties>
            
       </implementation>

       <syntax>XQuery</syntax>

       <test-run dateRun="2009-11-16">
          <test-suite version="1.0.0"/>
          <transformation><p>Standard</p></transformation>
          <comparison><p>Standard</p></comparison>
          <otherComments><p>None</p></otherComments>
       </test-run>

       {
         for $test in $ctests/*:Site/*:Testing/*:Test
         let $testname := fn:tokenize(fn:data($test/*:Name), "/")[last()]
         return
           <test-case
             name="{$testname}"
             result="{fn:substring(fn:data($test/@Status), 0, 5)}"
           />
       }
    </test-suite-result>
  }
