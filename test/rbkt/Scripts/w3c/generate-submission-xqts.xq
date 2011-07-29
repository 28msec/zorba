(: Schema for results :)
import schema default element namespace "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_reportingresults/XQTSResult.xsd";

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

    
      <implementation-defined-items>        
        <implementation-defined-item name="expressionUnicode" value=""/>
        <implementation-defined-item name="collations" value=""/>
        <implementation-defined-item name="implicitTimezone" value=""/>
        <implementation-defined-item name="warningsMethod" value=""/>
        <implementation-defined-item name="errorsMethod" value=""/>
        <implementation-defined-item name="XMLVersion" value=""/>
        <implementation-defined-item name="overwrittenContextComponents" value=""/>
        <implementation-defined-item name="axes" value=""/>
        <implementation-defined-item name="defaultOrderEmpty" value=""/>
        <implementation-defined-item name="pragmas" value=""/>
        <implementation-defined-item name="optionDeclarations" value=""/>
        <implementation-defined-item name="externalFunctionProtocols" value=""/>
        <implementation-defined-item name="moduleLocationHints" value=""/>
        <implementation-defined-item name="staticTypingExtensions" value=""/>
        <implementation-defined-item name="serializationInvocation" value=""/>
        <implementation-defined-item name="serializationDefaults" value=""/>
        <implementation-defined-item name="externalFunctionCall" value=""/>
        <implementation-defined-item name="limits" value=""/>
        <implementation-defined-item name="traceDestination" value=""/>
        <implementation-defined-item name="integerOperations" value=""/>
        <implementation-defined-item name="decimalDigits" value=""/>
        <implementation-defined-item name="roundOrTruncate" value=""/>
        <implementation-defined-item name="Unicode" value=""/>
        <implementation-defined-item name="normalizationForms" value=""/>
        <implementation-defined-item name="collationUnits" value=""/>
        <implementation-defined-item name="secondsDigits" value=""/>
        <implementation-defined-item name="stringToDecimal" value=""/>
        <implementation-defined-item name="docProcessing" value=""/>
        <implementation-defined-item name="weakenStable" value=""/>
        <implementation-defined-item name="additionalTypes" value=""/>
        <implementation-defined-item name="undefinedProperties" value=""/>
        <implementation-defined-item name="sequenceNormalization" value=""/>
        <implementation-defined-item name="outputMethods" value=""/>
        <implementation-defined-item name="normalizationFormBehavior" value=""/>
        <implementation-defined-item name="additionalParams" value=""/>
        <implementation-defined-item name="encodingPhase" value=""/>
        <implementation-defined-item name="CDATASerialization" value=""/>
        <implementation-defined-item name="Tokenization" value=""/>
        <implementation-defined-item name="phrase" value=""/>
        <implementation-defined-item name="sentence" value=""/>
        <implementation-defined-item name="paragraph" value=""/>
        <implementation-defined-item name="Markup Effect Token Boundaries" value=""/>
        <implementation-defined-item name="Scoring Expressions" value=""/>
        <implementation-defined-item name="Matching" value=""/>
        <implementation-defined-item name="Match Option Order" value=""/>
        <implementation-defined-item name="Language Option Tokenization" value=""/>
        <implementation-defined-item name="Language Option Valid ID" value=""/>
        <implementation-defined-item name="Language Option Undefined" value=""/>
        <implementation-defined-item name="Mismatched Languages" value=""/>
        <implementation-defined-item name="Thesaurus Option" value=""/>
        <implementation-defined-item name="Thesaurus Relationships" value=""/>
        <implementation-defined-item name="Thesaurus Levels" value=""/>
        <implementation-defined-item name="Stemming Option" value=""/>
        <implementation-defined-item name="Query Token In Stopword List" value=""/>
        <implementation-defined-item name="StopWord Option Match Number" value=""/>
        <implementation-defined-item name="StopWord Option Default" value=""/>
        <implementation-defined-item name="Extension Option" value=""/>
        <implementation-defined-item name="Extension Selection" value=""/>
        <implementation-defined-item name="Equal Items Different Tokens" value=""/>
        <implementation-defined-item name="FTIgnoreOption" value=""/>
        <implementation-defined-item name="Static Context Items" value=""/>
      </implementation-defined-items>

      <features>
        <feature name="Minimal Conformance" supported="true"/>
        <feature name="Schema Import" supported="true"/>
        <feature name="Schema Validation" supported="true"/>
        <feature name="Static Typing" supported="false"/>
        <feature name="Static Typing Extensions" supported="false"/>
        <feature name="Full Axis" supported="true"/>
        <feature name="Module" supported="true"/>
        <feature name="Serialization" supported="true"/>
      </features>

      <context-properties>
        <context-property name="Statically known namespaces" context-type="static" value=""/>
        <context-property name="Default element/type namespace" context-type="static" value=""/>
        <context-property name="Default function namespace" context-type="static" value="http://www.w3.org/2005/xpath-functions"/>
        <context-property name="In-scope schema types" context-type="static" value=""/>
        <context-property name="In-scope element declarations" context-type="static" value=""/>
        <context-property name="In-scope attribute declarations" context-type="static" value=""/>
        <context-property name="In-scope variables" context-type="static" value=""/>
        <context-property name="Context item static type" context-type="static" value="item()"/>
        <context-property name="Function signatures" context-type="static" value=""/>
        <context-property name="Statically known collations" context-type="static" value=""/>
        <context-property name="Default collation" context-type="static" value="http://www.w3.org/2005/xpath-functions/collation/codepoint"/>
        <context-property name="Construction mode" context-type="static" value="preserve"/>
        <context-property name="Ordering mode" context-type="static" value="ordered"/>
        <context-property name="Default order for empty sequences" context-type="static" value="empty greatest"/>
        <context-property name="Boundary-space policy" context-type="static" value="strip"/>
        <context-property name="Copy-namespaces mode" context-type="static" value="inherit preserve"/>
        <context-property name="Base URI" context-type="static" value=""/>
        <context-property name="Statically known documents" context-type="static" value=""/>
        <context-property name="Statically known collections" context-type="static" value=""/>
        <context-property name="Statically known default collection type" context-type="static" value=""/>
        <context-property name="Context item" context-type="dynamic" value=""/>
        <context-property name="Context position" context-type="dynamic" value=""/>
        <context-property name="Context size" context-type="dynamic" value=""/>
        <context-property name="Variable values" context-type="dynamic" value=""/>
        <context-property name="Function implementations" context-type="dynamic" value=""/>
        <context-property name="Current dateTime" context-type="dynamic" value=""/>
        <context-property name="Implicit timezone" context-type="dynamic" value=""/>
        <context-property name="Available documents" context-type="dynamic" value=""/>
        <context-property name="Available collections" context-type="dynamic" value=""/>
        <context-property name="Default collection" context-type="dynamic" value=""/>     
      </context-properties>

    </implementation>
  
    <syntax>XQuery</syntax>
  
    <test-run dateRun="2011-07-13">
      <test-suite version="current"/>
      <transformation><p>Standard</p></transformation>
      <comparison><p>Standard</p></comparison>
      <otherComments><p>XQTS taken from W3C CVS as of 2011-07-13.</p></otherComments>
    </test-run>

    {
      for $test in $ctests/*:Site/*:Testing/*:Test
      let $testname := fn:tokenize(fn:data($test/*:Name), "/")[last()]
      return
      if (fn:contains(fn:data($test),'StaticTyping')) then
        <test-case
          name="{$testname}"
          result="not applicable"
          comment="Zorba does not support the 'Static Typing Feature'"
        />
      else if(($testname = 'Constr-cont-nsmode-7') or ($testname = 'Constr-cont-nsmode-8') or ($testname = 'Constr-cont-nsmode-10')) then
      <test-case
          name="{$testname}"
          result="pass"
          comment="Opened W3C bug #11813."
        />
      else if($testname = 'K2-ExternalVariablesWith-22') then
      <test-case
          name="{$testname}"
          result="pass"
          comment="Opened W3C bug #11584."
        />
      else if($testname = 'fn-collection-2')then
      <test-case
          name="{$testname}"
          result="pass"
          comment="Opened W3C bug #12542."
        />
      else
        <test-case
          name="{$testname}"
          result="{fn:substring(fn:data($test/@Status), 0, 5)}"
        />
     }
  </test-suite-result>
}
