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
 : @see <a href="http://www.w3.org/TR/xslt-xquery-serialization/">XSLT 2.0 and XQuery 1.0 Serialization</a>
 : @author Matthias Brantner, Gabriel Petrovay
 : @version 1.0 
 :)
module namespace ser = "http://www.zorba-xquery.com/modules/serialize";


(:~
 : Serialize a sequence of items to a string. 
 :
 : @param $content The content to be serialized to the string.
 : @param $serializer-params Parameters to control the serialization of the
 :        content. This parameter can either be a string (xml, html, xhtml,
 :        text, json, or jsonml) describing the serialization method to
 :        be used or a element node as follows:
 :        &lt;xsl:output  method="xml|html|text|json|jsonml"
 :          version="string" encoding="string"
 :          omit-xml-declaration="yes|no"
 :          standalone="yes|no"
 :          doctype-public="string" doctype-system="string"
 :          cdata-section-elements="namelist"
 :          indent="yes|no" media-type="string"/>

 : @error An error is thrown if serialization problems occur.
 :)
declare function ser:serialize($content as item()*,
                               $serializer-params as item()) as xs:string external;

(:~
 : Serialize a sequence of items to a string. For serialization,
 : the serialization parameters are set as follows:
 : <ul>
 :   <li> serialization method: XML</li>
 :   <li> byte-order-mark: NO</li>
 :   <li> esacpe-uri-attributes: NO</li>
 :   <li> include-content-type: NO</li>
 :   <li> indent: NO</li>
 :   <li> normalization-form: none</li>
 :   <li> omit-xml-declaration: NO</li>
 :   <li> standalone: omit</li>
 :   <li> undeclare-prefixes: NO</li>
 : </ul>
 :
 : @param $content The content to be serialized to the string.
 : @error An error is thrown if serialization problems occur.
 :)
declare function ser:serialize($content as item()*) as xs:string external;
