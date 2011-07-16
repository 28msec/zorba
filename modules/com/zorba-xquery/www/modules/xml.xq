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
 : This module provides functions for manipulating XML files.
 : </p>
 : 
 : @author Nicolae Brinza
 : @project data processing/data converters
 :
 :)
module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : A function to parse XML files and fragments (i.e. external general parsed 
 : entities). The functions takes two arguments: the first one is the string
 : to be parsed. The second argument is a string (eEdDsSlLwWfF]*(;[\p{L}]*)?) 
 : defining the following options.
 : <br/>
 : <br/>
 : 
 : The convention for the standard flags is that a lower-case letter enables 
 : an option, and the corresponding upper-case letter disables it; specifying 
 : both is an error; specifying neither leaves it implementation-defined 
 : whether the option is enabled or disabled. Specifying the same option twice 
 : is not an error, but specifying inconsistent options (for example "eE") is 
 : a dynamic error. The options defined are:
 : 
 : <ul>
 : <li>
 : eE - enables or disables processing of XML external entities. If the option 
 : is enabled, the input must conform to the syntax _extParsedEnt_ (production 
 : [78] in XML 1.0, see <a href="http://www.w3.org/TR/xml/#wf-entities">XML 1.0</a>)
 : The result of the function call is a list of nodes corresponding to the 
 : top-level components of the _content_ of the external entity: that is, 
 : elements, processing instructions, comments, and text nodes. CDATA sections 
 : and character references are expanded, and adjacent characters are merged 
 : so the result contains no adjacent text nodes. If this option is enabled, 
 : none of the options d, s, or, l  may be enabled. If the option is disabled, 
 : the input must be a well-formed XML document conforming to the syntax 
 : document_ (production [1] in XML 1.0).
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
 : expression, or the XSLT xsl:copy-of instruction with validation="strict".
 : </li>
 :
 : <li>
 : lL - enables or disables lax XSD-based validation. If this option is enabled, 
 : the result is equivalent to processing the input with the option disabled, 
 : and then copying the result using the XQuery "validate lax " expression, or 
 : the XSLT xsl:copy-of instruction with validation="lax".
 : </li>
 :
 : <li>
 : wW - enables or disables whitespace stripping. If the option is enabled, 
 : any whitespace-only text nodes that remain after any DTD-based or XSD-based 
 : processing are stripped from the input; if it is disabled, such 
 : whitespace-only text nodes are retained. (In XSLT, if the option is not 
 : specified, the provisions of the xsl:strip-space and xsl:preserve-space 
 : declarations apply.)
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
 : @param $xml-string The string that holds the XML to be parse. If empty,
 :                    the function will return an empty sequence
 : @param $options The options for the parsing
 : @return The parsed XML as a document node or a list of nodes, or an empty
 :         sequence
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $options as xs:string) as node()* external;

(:~
 : A function to parse XML files and fragments. The behavior is the
 : same as the parse-xml-fragment with two arguments.
 : @param $xml-string The string that holds the XML to be parse. If empty,
 :                    the function will return an empty sequence
 : @param $base-uri The baseURI that will be used as the baseURI for every
 :                    node returned by this function.
 : @param $options The options for the parsing (see parse-xml-fragment#2)
 : @return The parsed XML as a document node or a list of nodes, or an empty
 :         sequence
 :)
declare function parse-xml:parse-xml-fragment(
  $xml-string as xs:string?,
  $base-uri as xs:string,
  $options as xs:string) as node()* external;
