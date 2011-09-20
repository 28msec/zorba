xquery version "1.0";

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
 : @see <a href="http://www.w3.org/TR/xml/#wf-entities">XML 1.0 Well-Formed 
 : Parsed Entities</a>
 : @see <a href="http://www.w3.org/TR/xpath-functions-30/#func-parse-xml">
 : fn:parse-xml() function in XPath and XQuery Functions and Operators 3.0</a>
 :
 : @author Nicolae Brinza
 : @project data processing/data converters
 :
 :)
module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace err = "http://www.w3.org/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
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
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $options as xs:string) as node()* external;


(:~
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
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $base-uri as xs:string,
  $options as xs:string) as node()* external;
