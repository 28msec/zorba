xquery version "3.0";

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
 : Using this module, you can parse JSON data into XML, manipulate it like any
 : other XML data using XQuery, and serialize the result back as JSON.<p/>
 :
 : There are many ways to represent JSON data in XML, some loss-less ("round
 : tripable") and some lossy ("one way").  Loss-less representations preserve
 : the JSON data types <i>boolean</i>, <i>number</i>, and <i>null</i>; lossy
 : representations convert all data to strings.
 : <p/>
 : For a loss-less representation, this module implements that proposed by
 : <a href="http://john.snelson.org.uk/parsing-json-into-xquery">John Snelson</a>.
 : For example:
 : <pre class="ace-static" ace-mode="java">
 :   {
 :     "firstName" : "John",
 :     "lastName" : "Smith",
 :     "address" : {
 :       "streetAddress" : "21 2nd Street",
 :       "city" : "New York",
 :       "state" : "NY",
 :       "postalCode" : 10021
 :     },
 :     "phoneNumbers" : [ "212 732-1234", "646 123-4567" ]
 :   }
 : </pre>
 : would be represented as:
 : <pre class="ace-static" ace-mode="xquery">
 :   &lt;json type="object"&gt;
 :     &lt;pair name="firstName" type="string"&gt;John&lt;/pair&gt;
 :     &lt;pair name="lastName" type="string"&gt;Smith&lt;/pair&gt;
 :     &lt;pair name="address" type="object"&gt;
 :       &lt;pair name="streetAddress" type="string"&gt;21 2nd Street&lt;/pair&gt;
 :       &lt;pair name="city" type="string"&gt;New York&lt;/pair&gt;
 :       &lt;pair name="state" type="string"&gt;NY&lt;/pair&gt;
 :       &lt;pair name="postalCode" type="number"&gt;10021&lt;/pair&gt;
 :     &lt;/pair&gt;
 :     &lt;pair name="phoneNumbers" type="array"&gt;
 :       &lt;item type="string"&gt;212 732-1234&lt;/item&gt;
 :       &lt;item type="string"&gt;646 123-4567&lt;/item&gt;
 :     &lt;/pair&gt;
 :   &lt;/json&gt;
 : </pre>
 : For a lossy representation, this module implements
 : <a href="http://jsonml.org/">JsonML</a> (the array form).
 : For example:
 : <pre class="ace-static" ace-mode="java">
 :   [ "person",
 :     { "created" : "2006-11-11T19:23",
 :       "modified" : "2006-12-31T23:59" },
 :     [ "firstName", "Robert" ],
 :     [ "lastName", "Smith" ],
 :     [ "address",
 :       { "type" : "home" },
 :       [ "street", "12345 Sixth Ave" ],
 :       [ "city", "Anytown" ],
 :       [ "state", "CA" ],
 :       [ "postalCode", "98765-4321" ]
 :     ]
 :   ]
 : </pre>
 : would be represented as:
 : <pre class="ace-static" ace-mode="xquery">
 :   &lt;person created="2006-11-11T19:23" modified="2006-12-31T23:59"&gt;
 :     &lt;firstName&gt;Robert&lt;/firstName&gt;
 :     &lt;lastName&gt;Smith&lt;/lastName&gt;
 :     &lt;address type="home"&gt;
 :       &lt;street&gt;12345 Sixth Ave&lt;/street&gt;
 :       &lt;city&gt;Anytown&lt;/city&gt;
 :       &lt;state&gt;CA&lt;/state&gt;
 :       &lt;postalCode&gt;98765-4321&lt;/postalCode&gt;
 :     &lt;/address&gt;
 :   &lt;/person&gt;
 : </pre>
 :
 : @author Paul J. Lucas
 : @project Zorba/Data Converters/JSON
 :)
module namespace jx = "http://zorba.io/modules/json-xml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Converts JSON data into an XDM instance using one of the representations
 : described above.<p/>
 :
 : @param $json The JSON data.
 : @param $options The JSON conversion  options, for example:
 : <pre>
 : { "json-format" : "JsonML-array" }
 : </pre>
 : @return said XDM instance.
 : @example test/rbkt/Queries/zorba/json/json-snelson-j2x-array-01.xq
 : @example test/rbkt/Queries/zorba/json/json-snelson-j2x-object-01.xq
 : @example test/rbkt/Queries/zorba/json/json-jmla-j2x-01.xq
 :)
declare function jx:json-to-xml( $json as json-item()?, $options as object() )
  as element(*,xs:untyped)?
{
  jx:json-to-xml-internal( $json, $options )
};

(:~
 : Converts JSON data into an XDM instance using the Snelson representation
 : described above.<p/>
 :
 : @param $json The JSON data.
 : @return said XDM instance.
 : @example test/rbkt/Queries/zorba/json/json-snelson-j2x-array-01.xq
 : @example test/rbkt/Queries/zorba/json/json-snelson-j2x-object-01.xq
 : @example test/rbkt/Queries/zorba/json/json-jmla-j2x-01.xq
 :)
declare function jx:json-to-xml( $json as json-item()? )
  as element(*,xs:untyped)?
{
  jx:json-to-xml-internal( $json, { "json-format" : "Snelson" } )
};

(:~
 : Converts XML data into a JSON item using one of the respresentations
 : described above.<p/>
 :
 : @param $xml The XML data to convert.
 : @param $options The conversion options, for example:
 : <pre>
 : { "json-format" : "JsonML-array" }
 : </pre>
 : @return said JSON items.
 : @error zerr:ZJSE0001 if $xml is not a document or element node.
 : @error zerr:ZJSE0002 if $xml contains an element that is missing a required
 : attribute.
 : @error zerr:ZJSE0003 if $xml contains an attribute having an illegal value.
 : @error zerr:ZJSE0004 if $xml contains an illegal element.
 : type.
 : @error zerr:ZJSE0007 if $xml contains an element that is missing a required
 : value.
 : @error zerr:ZJSE0008 if $xml contains an illegal value for a JSON type.
 : @example test/rbkt/Queries/zorba/json/json-snelson-x2j-array-01.xq
 : @example test/rbkt/Queries/zorba/json/json-snelson-x2j-object-01.xq
 : @example test/rbkt/Queries/zorba/json/json-jmla-x2j-01.xq
 :)
declare function jx:xml-to-json( $xml as item()*, $options as object() )
  as json-item()*
{
  jx:xml-to-json-internal( $xml, $options )
};

(:~
 : Converts XML data into a JSON item using the Snelson representation
 : described above.<p/>
 :
 : @param $xml The XML data to convert.
 : @return said JSON items.
 : @error zerr:ZJSE0001 if $xml is not a document or element node.
 : @error zerr:ZJSE0002 if $xml contains an element that is missing a required
 : attribute.
 : @error zerr:ZJSE0003 if $xml contains an attribute having an illegal value.
 : @error zerr:ZJSE0004 if $xml contains an illegal element.
 : type.
 : @error zerr:ZJSE0007 if $xml contains an element that is missing a required
 : value.
 : @error zerr:ZJSE0008 if $xml contains an illegal value for a JSON type.
 : @example test/rbkt/Queries/zorba/json/json-snelson-x2j-array-01.xq
 : @example test/rbkt/Queries/zorba/json/json-snelson-x2j-object-01.xq
 : @example test/rbkt/Queries/zorba/json/json-jmla-x2j-01.xq
 :)
declare function jx:xml-to-json( $xml as item()* )
  as json-item()*
{
  jx:xml-to-json-internal( $xml, { "json-format" : "Snelson" } )
};

(:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::)

declare %private function jx:json-to-xml-internal(
  $json as json-item()?,
  $options as object()
) as element()* external;

declare %private function jx:xml-to-json-internal(
  $xml as item()*,
  $options as object()
) as json-item()* external;

(: vim:set et sw=2 ts=2: :)
