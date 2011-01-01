(:
 : Copyright 2006-2009 The FLWOR Foundation.
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
 : XSLT 2.0 and XQuery 1.0 Serialization Module
 :
 : @author Matthias Brantner, Gabriel Petrovay
 :
 : @see <a href="http://www.w3.org/TR/xslt-xquery-serialization/"
 : target="_blank">XSLT 2.0 and XQuery 1.0 Serialization</a>
 :)
module namespace ser = "http://www.zorba-xquery.com/modules/serialize";

(:~
 : Serialize a sequence of items to a string.
 :
 : The $serializer-params parameter can be used to control the $content serialization.
 : This argument can be either a string value or an
 : <a href="http://www.w3.org/TR/xslt20/#element-output" target="_blank">xsl:output</a>
 : element as defined in the the XSLT 2.0 specification recommendation. If a string
 : value is provided, this will be interpreted as: &lt;xsl:output method="string_value"/&gt;.
 : Currently, Zorba supports the following methods:  xml, html, xhtml, text, json, and jsonml.
 : 
 : In this version Zorba supports only the following attributes of the xsl:output element:
 : <br/>
 : <pre>&lt;output method="xml|html|xhtml|text|json|jsonml"
 : doctype-public="string"
 : doctype-system="string"
 : encoding="string"
 : indent="yes|no"
 : media-type="string"
 : omit-xml-declaration="yes|no"
 : standalone="yes|no"
 : undeclare-prefixes="yes|no"
 : version="string"/&gt;</pre>
 :
 : @param $content The item sequence to be serialized.
 : @param $serializer-params Parameter to control the serialization.
 : @error An error is thrown if serialization problems occur.
 : @return A string representing the serialized sequence of items.
 : @see <a href="http://www.w3.org/TR/xslt20/#element-output"
 :    target="_blank">XSLT 2.0 xsl:output element</a>
 :)
declare function ser:serialize($content as item()*,
                               $serializer-params as item()) as xs:string external;

(:~
 : Serialize a sequence of items to a string. The supported serialization
 : parameters that require a value are set as follows:
 : <ul>
 :   <li>method: xml</li>
 :   <li>encoding: UTF-8</li>
 :   <li>indent: no</li>
 :   <li>omit-xml-declaration: no</li>
 :   <li>standalone: omit</li>
 :   <li>undeclare-prefixes: no</li>
 :   <li>version: 1.0</li>
 : </ul>
 :
 : @param $content The item sequence to be serialized.
 : @error An error is thrown if serialization problems occur.
 : @return A string representing the serialized sequence of items.
 :)
declare function ser:serialize($content as item()*) as xs:string external;
