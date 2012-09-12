xquery version "3.0";

(:
 : Copyright 2006-2010 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:~
 : <p>
 : This module provides functions for reading XML files from string inputs. 
 : It allows reading of well-formed XML documents as well as well-formed 
 : external parsed entities, described by 
 : <a href="http://www.w3.org/TR/xml/#wf-entities">XML 1.0 Well-Formed 
 : Parsed Entities</a>. The functions can also perform Schema and DTD 
 : validation of the input documents. 
 : </p>
 :
 : <p>The following example parses a sequence of XML elements and returns
 : them in a streaming fashion - each at a time:</p>
 :
 : <pre class="brush: xquery;">
 : import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
 : import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";
 : parse-xml:parse( 
 :   "&lt;from1>Jani&lt;/from1>&lt;from2>Jani&lt;/from2>&lt;from3>Jani&lt;/from3>",
 :   &lt;opt:options>
 :     &lt;opt:parse-external-parsed-entity/>
 :   &lt;/opt:options> 
 : )
 : </pre>
 :
 : <p>Another useful option allows to skip an arbitrary number of levels
 : before returning a sequence of nodes as shown in the following example:</p>
 :
 : <pre class="brush: xquery;">
 : import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
 : import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";
 : parse-xml:parse(
 :   "&lt;root>
 :     &lt;from1>Jani1&lt;/from1>
 :     &lt;from2>Jani2&lt;/from2>
 :     &lt;from3>Jani3&lt;/from3>
 :   &lt;/root>", 
 :   &lt;opt:options>
 :     &lt;opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
 :   &lt;/opt:options>
 : )
 : </pre>
 :
 : @see <a href="http://www.w3.org/TR/xml/#wf-entities">XML 1.0 Well-Formed 
 : Parsed Entities</a>
 : @see <a href="http://www.w3.org/TR/xpath-functions-30/#func-parse-xml">
 : fn:parse-xml() function in XPath and XQuery Functions and Operators 3.0</a>
 : @see <a href="http://xmlsoft.org/html/libxml-parser.html">LibXml2 parser</a>
 :
 : @author Nicolae Brinza
 : @project data processing/data converters
 :
 :)
module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";

import schema namespace parse-xml-options = "http://www.zorba-xquery.com/modules/xml-options";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace err = "http://www.w3.org/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : A function to parse XML files and fragments (i.e. 
 : <a href="http://www.w3.org/TR/xml/#wf-entities">external general parsed 
 : entities</a>). The functions takes two arguments: the first one is the 
 : string to be parsed and the second argument is an &lt;options/&gt; element that
 : passes a list of options to the parsing function. They are described below.
 : The options element must conform to the xml-options:options element type 
 : from the xml-options.xsd schema. Some of these
 : will be passed to the underlying library (LibXml2) and further documentation 
 : for them can be found at <a href="http://xmlsoft.org/html/libxml-parser.html">
 : LibXml2 parser</a>.
 :
 : The list of available options:
 :
 : <ul>
 : <li>
 : &lt;base-uri/&gt; - the element must have a "value" attribute, which will provide
 : the baseURI that will be used as the baseURI for every node returned by this 
 : function.
 : </li>
 :
 : <li>
 : &lt;no-error/&gt; - if present, the option will disable fatal error processing. Any
 : failure to parse or validate the input in the requested manner will result
 : in the function returning an empty sequence and no error will raised.
 : </li>
 :
 : <li>
 : &lt;schema-validate/&gt; - if present, it will request that the input string be Schema 
 : validated. The element accepts an attribute named "mode" which can have two 
 : values: "strict and "lax". Enabling the option will produce a result that is 
 : equivalent to processing the input with the option disabled, and then copying 
 : the result using the XQuery "validate strict|lax" expression. This option can not
 : be used together with either the &lt;DTD-validate/&gt; or the &lt;parse-external-parsed-entity/&gt;
 : option. Doing so will raise a zerr:ZXQD0003 error.
 : </li>
 :
 : <li>
 : &lt;DTD-validate/&gt; - the option will enable the DTD-based validation. If this 
 : option is enabled and the input references a DTD, then the input must be a 
 : well-formed and DTD-valid XML document. The &lt;DTD-load/&gt; option must be used for
 : external DTD files to be loaded. If the option is enabled and the input does 
 : not reference a DTD then the option is ignored. If the option is disabled, the 
 : input is not required to reference a DTD and if it does reference a DTD then
 : the DTD is ignored for validation purposes. This option can not
 : be used together with either the &lt;schema-validate/&gt; or the &lt;parse-external-parsed-entity&gt;
 : option. Doing so will raise a zerr:ZXQD0003 error.
 : </li>
 :
 : <li> 
 : &lt;DTD-load/&gt; - if present, it will enable loading of external DTD files.
 : </li>
 :
 : <li>
 : &lt;default-DTD-attributes/&gt; - if present, it will enable the default DTD attributes.
 : </li>
 :
 : <li>
 : &lt;parse-external-parsed-entity/&gt; - if present, it will enable the processing of XML 
 : external entities. If the option 
 : is enabled, the input must conform to the syntax extParsedEnt (production 
 : [78] in XML 1.0, see <a href="http://www.w3.org/TR/xml/#wf-entities">
 : Well-Formed Parsed Entities</a>). In addition, by default a DOCTYPE declaration is allowed,
 : as described by the [28] doctypedecl production, see <a href="http://www.w3.org/TR/xml/#NT-doctypedecl">
 : Document Type Definition</a>. A parameter is available to forbid the appearance of the DOCTYPE.
 :
 : The result of the function call is a list 
 : of nodes corresponding to the top-level components of the content of the 
 : external entity: that is, elements, processing instructions, comments, and 
 : text nodes. CDATA sections and character references are expanded, and 
 : adjacent characters are merged so the result contains no adjacent text 
 : nodes. If the option is disabled, the input must be a well-formed XML 
 : document conforming to the Document production 
 : (<a href="http://www.w3.org/TR/xml/#sec-well-formed">production [1] in XML 1.0</a>).
 : This option can not be used together with either the &lt;schema-validate/&gt; or the &lt;DTD-validate/&gt;
 : option. Doing so will raise a zerr:ZXQD0003 error.
 : The &lt;parse-external-parsed-entity/&gt; option has three parameters, given by attributes. The first
 : attribute is "skip-root-nodes" and it can have a non-negative value. Specifying the paramter
 : tells the parser to skip the given number of root nodes and return only their children. E.g.
 : skip-root-nodes="1" is equivalent to parse-xml($xml-string)/node()/node() . skip-root-nodes="2" is equivalent
 : to parse-xml($xml-string)/node()/node()/node() , etc. The second attribute is "skip-top-level-text-nodes" with a 
 : boolean value. Specifying "true" will tell the parser to skip top level text nodes, returning
 : only the top level elements, comments, PIs, etc. This parameter works in combination with
 : the "skip-root-nodes" paramter, thus top level text nodes are skipped after "skip-root-nodes" has 
 : been applied. The third paramter is "error-on-doctype" and will generate an error if a DOCTYPE
 : declaration appears in the input, which by default is allowed.
 : </li>
 :
 : <li>
 : &lt;substitute-entities/&gt; - if present, it will enable the XML entities substitutions.
 : </li>
 :
 : <li>
 : &lt;remove-redundant-ns/&gt; - if present, the parser will remove redundant namespaces declarations.
 : </li>
 :
 : <li>
 : &lt;no-CDATA/&gt; - if present, the parser will merge CDATA nodes as text nodes.
 : </li>
 :
 : <li>
 : &lt;xinclude-substitutions/&gt; - if present, it will enable the XInclude substitutions.
 : </li>
 :
 : <li>
 : &lt;no-xinclude-nodes/&gt; - if present, the parser will not generate XInclude START/END nodes.
 : </li>
 :      
 : </ul>
 :
 : <p>
 : An example that sets the base-uri of the parsed external entities:
 : </p>
 : <pre class="brush: xquery;">
 :   import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
 :   import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";
 :   parse-xml:parse("&lt;from1>Jani&lt;/from1>&lt;from2>Jani&lt;/from2>&lt;from3>Jani&lt;/from3>",
 :     &lt;opt:options>
 :       &lt;opt:base-uri opt:value="urn:test"/>
 :       &lt;opt:parse-external-parsed-entity/>
 :     &lt;/opt:options>
 :   )
 : </pre>
 :
 : @param $xml-string The string that holds the XML to be parsed. If empty,
 :                    the function will return an empty sequence
 : @param $options The options for the parsing
 : @return The parsed XML as a document node or a list of nodes, or an empty
 :         sequence.
 :
 : @error zerr:ZXQD0003 The error will be raised if the options to the function
 :                     are inconsistent.
 :
 : @error err:FODC0006 The error will be raised if the input string is not a
 :                     valid XML document or fragment (external general parsed
 :                     entity) or if DTD validation was enabled and the 
 :                     document has not passed it.
 :
 : @error err:XQDY0027 The error will be raised if schema validation was enabled
 :                     and the input document has not passed it or if the parsing options are not
 :                     conformant to the xml-options.xsd schema.
 :
 :
 :
 : @example test/rbkt/Queries/zorba/parsing_and_serializing/parse-xml-fragment-03.xq
 : @example test/rbkt/Queries/zorba/parsing_and_serializing/parse-xml-fragment-01.xq
 : @example test/rbkt/Queries/zorba/parsing_and_serializing/parse-xml-fragment-07.xq
 :
 :)
declare function parse-xml:parse(
  $xml-string as xs:string?,
  $options as element(parse-xml-options:options)?) as node()* external;
  

(:~
 : <br/><p>
 : Note: this function is included for backwards compatibility purposes. It 
 : is recommended that you use the parse-xml:parse() function instead.
 : </p><br/>
 :
 : A function to parse XML files and fragments (i.e. 
 : <a href="http://www.w3.org/TR/xml/#wf-entities">external general parsed 
 : entities</a>). The functions takes two arguments: the first one is the 
 : string to be parsed and the second argument is a flags string 
 : (eEdDsSlLwWfF]*(;[\p{L}]*)?) selecting the options described below.
 : <br/>
 : <br/>
 : 
 : The convention for the flags is that a lower-case letter enables 
 : an option and the corresponding upper-case letter disables it; specifying 
 : both is an error; specifying neither leaves it implementation-defined 
 : whether the option is enabled or disabled. Specifying the same option twice 
 : is not an error, but specifying inconsistent options (for example "eE") is 
 : a dynamic error. The options are:
 : 
 : <ul>
 : <li>
 : eE - enables or disables processing of XML external entities. If the option 
 : is enabled, the input must conform to the syntax extParsedEnt (production 
 : [78] in XML 1.0, see <a href="http://www.w3.org/TR/xml/#wf-entities">
 : Well-Formed Parsed Entities</a>). The result of the function call is a list 
 : of nodes corresponding to the top-level components of the content of the 
 : external entity: that is, elements, processing instructions, comments, and 
 : text nodes. CDATA sections and character references are expanded, and 
 : adjacent characters are merged so the result contains no adjacent text 
 : nodes. If this option is enabled, none of the options d, s, or l may be 
 : enabled. If the option is disabled, the input must be a well-formed XML 
 : document conforming to the Document production 
 : (<a href="http://www.w3.org/TR/xml/#sec-well-formed">production [1] in XML 1.0</a>).
 : </li>
 :
 : <li>
 : dD - enables or disables DTD-based validation. If this option is enabled and
 : the input references a DTD, then the input must be a well-formed and 
 : DTD-valid XML document. If the option is enabled and the input does not 
 : reference a DTD then the option is ignored. If the option is disabled, the 
 : input is not required to reference a DTD and if it does reference a DTD then 
 : the DTD is ignored for validation purposes (though it will still be read for 
 : purposes such as expanding entity references and identifying ID attributes).
 : </li>
 :
 : <li>
 : sS - enables or disables strict XSD-based validation. If this option is 
 : enabled, the result is equivalent to processing the input with the option 
 : disabled, and then copying the result using the XQuery "validate strict" 
 : expression.
 : </li>
 :
 : <li>
 : lL - enables or disables lax XSD-based validation. If this option is enabled, 
 : the result is equivalent to processing the input with the option disabled, 
 : and then copying the result using the XQuery "validate lax " expression.
 : </li>
 :
 : <li>
 : wW - enables or disables whitespace stripping. If the option is enabled, 
 : any whitespace-only text nodes that remain after any DTD-based or XSD-based 
 : processing are stripped from the input; if it is disabled, such 
 : whitespace-only text nodes are retained. 
 : </li>
 :
 : <li>
 : fF - enables or disables fatal error processing. If fatal error processing 
 : is enabled, then any failure to parse the input in the manner requested 
 : results in a dynamic error. If fatal error processing is disabled, then any 
 : failure to parse the input (and also, in the case of fn:doc, a failure to 
 : obtain the input by dereferencing the supplied URI) results in the function 
 : returning an empty sequence and raising no error. 
 : </li>
 : </ul>
 :
 : @param $xml-string The string that holds the XML to be parsed. If empty,
 :                    the function will return an empty sequence
 : @param $options The options for the parsing
 : @return The parsed XML as a document node or a list of nodes, or an empty
 :         sequence.
 :
 : @error zerr:ZXQD0003 The error will be raised if the options to the function
 :                     are inconsistent.
 :
 : @error err:FODC0006 The error will be raised if the input string is not a
 :                     valid XML document or fragment (external general parsed
 :                     entity) or if DTD validation was enabled and the 
 :                     document has not passed it.
 :
 : @error err:XQDY0027 The error will be raised if schema validation was enabled
 :                     and the input document has not passed it.
 :
 : @deprecated
 :
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $options as xs:string) as node()* 
{
  let $new_options := <parse-xml-options:options>{
      if (contains($options, "e"))
        then <parse-xml-options:parse-external-parsed-entity/> else (),
      if (contains($options, "d"))
        then <parse-xml-options:DTD-validate/> else (),
      if (contains($options, "s"))
        then <parse-xml-options:schema-validate parse-xml-options:mode="strict"/> 
        else (),
      if (contains($options, "l"))
        then <parse-xml-options:schema-validate parse-xml-options:mode="lax"/> 
        else (),
      (: TODO: uncomment once the strip-boundary-space option is implemented
      if (contains($options, "w"))
        then <parse-xml-options:strip-boundary-space/> else (), :)
      if (contains($options, "f"))
        then <parse-xml-options:no-error/> else ()      
    }</parse-xml-options:options>
  return
    parse-xml:parse($xml-string, $new_options)
};


(:~
 : <br/><p>
 : Note: this function is included for backwards compatibility purposes. It 
 : is recommended that you use the parse-xml:parse() function instead.
 : </p><br/>
 :
 : A function to parse XML files and fragments. The behavior is the
 : same as the parse-xml-fragment with two arguments.
 :
 : @param $xml-string The string that holds the XML to be parsed. If empty,
 :                    the function will return an empty sequence
 : @param $base-uri The baseURI that will be used as the baseURI for every
 :                    node returned by this function.
 : @param $options The options for the parsing (see parse-xml-fragment#2)
 : @return The parsed XML as a document node or a list of nodes, or an empty
 :         sequence.
 :
 : @error zerr:ZXQD0003 The error will be raised if the options to the function
 :                     are inconsistent.
 :
 : @error err:FODC0006 The error will be raised if the input string is not a
 :                     valid XML document or fragment (external general parsed
 :                     entity) or if DTD validation was enabled and the 
 :                     document has not passed it.
 :
 : @error err:XQDY0027 The error will be raised if schema validation was enabled
 :                     and the input document has not passed it.
 :
 : @error err:FODC0007 This error will be raised if $base-uri parameter passed
 :                     to the function is not a valid absolute URI.
 :
 : @deprecated
 :
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $base-uri as xs:string,
  $options as xs:string) as node()*
{
    let $new_options := <parse-xml-options:options>{
      if (contains($options, "e"))
        then <parse-xml-options:parse-external-parsed-entity/> else (),
      if (contains($options, "d"))
        then <parse-xml-options:DTD-validate/> else (),
      if (contains($options, "s"))
        then <parse-xml-options:schema-validate parse-xml-options:mode="strict"/> 
        else (),
      if (contains($options, "l"))
        then <parse-xml-options:schema-validate parse-xml-options:mode="lax"/> 
        else (),
      (: TODO: uncomment once the strip-boundary-space option is implemented
      if (contains($options, "w"))
        then <parse-xml-options:strip-boundary-space/> else (), :)
      if (contains($options, "f"))
        then <parse-xml-options:no-error/> else (),
      <parse-xml-options:base-uri>{
        attribute{xs:QName("parse-xml-options:value")}{$base-uri}}
      </parse-xml-options:base-uri>
    }</parse-xml-options:options>
  return 
    parse-xml:parse($xml-string, $new_options)
};
