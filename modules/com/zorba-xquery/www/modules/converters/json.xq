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

xquery version "3.0";

 (:~
  : Using this module, you can parse JSON data into XML, manipulate it like any
  : other XML data using XQuery, and serialize the result back as JSON.
  :
  : There are many ways to represent JSON data in XML, some loss-less ("round
  : tripable") and some lossy ("one way").  Loss-less representations preserve
  : the JSON data types <i>boolean</i>, <i>number</i>, and <i>null</i>; lossy
  : representations convert all data to strings.
  :
  : For a loss-less representation, Zorba implements that proposed by
  : <a href="http://john.snelson.org.uk/parsing-json-into-xquery">John Snelson</a>;
  : for a lossy representation, Zorba implements
  : <a href="http://jsonml.org/">JsonML</a> (the array form).
  :)

module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

import schema namespace json-options =
  "http://www.zorba-xquery.com/modules/converters/json-options";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Parses JSON data from a string and returns an XDM instance using one of the
 : representations described above.
 :
 : @param $json The JSON data to parse.
 : @param $options The parsing options.
 : @return said XDM instance.
 : @error err:XQDY0027 if \a $options can not be validated against the \c
 : json-options schema.
 : @error ZJPE0001 if \a $json contains an illegal JSON character.
 : @error ZJPE0002 if \a $json contains an illegal Unicode code-point.
 : @error ZJPE0003 if \a $json contains an illegal JSON character escape.
 : @error ZJPE0004 if \a $json contains an illegal JSON literal.
 : @error ZJPE0005 if \a $json contains an illegal JSON number.
 : @error ZJPE0007 if \a $json contains an unterminated string.
 : @error ZJPE0008 if \a $json contains an illegal QName.
 :)
declare function json:parse(
  $json as xs:string?,
  $options as element(json-options:options)
) as element(*,xs:untyped)*
{
  let $validated-options := if ( schema:is-validated( $options ) ) then
                              $options
                            else
                              validate { $options }
  return json:parse-internal( $json, $validated-options )
};

(:~
 : Parses JSON data from a string and returns an XDM instance using the Snelson
 : representation described above.
 :
 : @param $json The JSON data to parse.
 : @return said XDM instance.
 : @error ZJPE0001 if \a $json contains an illegal JSON character.
 : @error ZJPE0002 if \a $json contains an illegal Unicode code-point.
 : @error ZJPE0003 if \a $json contains an illegal JSON character escape.
 : @error ZJPE0004 if \a $json contains an illegal JSON literal.
 : @error ZJPE0005 if \a $json contains an illegal JSON number.
 : @error ZJPE0007 if \a $json contains an unterminated string.
 : @error ZJPE0008 if \a $json contains an illegal QName.
 :)
declare function json:parse(
  $json as xs:string?
) as element(*,xs:untyped)*
{
  json:parse-internal(
    $json,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
        <json-format value="Snelson"/>
      </options>
    }
  )
};

(:~
 : Serializes an XDM into JSON using one of the representations described
 : above.
 :
 : @param $xml The XDM to serialize.
 : @param $options The serializing options.
 : @return a JSON string.
 : @error err:XQDY0027 if $options can not be validated against the \c
 : json-options schema.
 : @error ZJSE0001 if \a $xml is not a document or element node.
 : @error ZJSE0002 if \a $xml contains an element that is missing a required
 : attribute.
 : @error ZJSE0003 if \a $xml contains an attribute having an illegal value.
 : @error ZJSE0004 if \a $xml contains an illegal element.
 : @error ZJSE0005 if \a $xml contains an illegal child element for a JSON type.
 : @error ZJSE0006 if \a $xml contains an illegal child element.
 : @error ZJSE0007 if \a $xml contains an illegal text node.
 : @error ZJSE0008 if \a $xml contains an illegal value for a JSON type.
 :)
declare function json:serialize(
  $xml as item()*,
  $options as element(json-options:options)
) as xs:string
{
  let $validated-options := if ( schema:is-validated( $options ) ) then
                              $options
                            else
                              validate { $options }
  return json:serialize-internal( $xml, $validated-options )
};

(:~
 : Serializes an XDM into JSON using one of the representations described
 : above.
 :
 : @param $xml The XDM to serialize.
 : @return a JSON string.
 : @error ZJSE0001 if \a $xml is not a document or element node.
 : @error ZJSE0002 if \a $xml contains an element that is missing a required
 : attribute.
 : @error ZJSE0003 if \a $xml contains an attribute having an illegal value.
 : @error ZJSE0004 if \a $xml contains an illegal element.
 : @error ZJSE0005 if \a $xml contains an illegal child element for a JSON type.
 : @error ZJSE0006 if \a $xml contains an illegal child element.
 : @error ZJSE0007 if \a $xml contains an illegal text node.
 : @error ZJSE0008 if \a $xml contains an illegal value for a JSON type.
 :)
declare function json:serialize(
  $xml as item()*
) as xs:string
{
  json:serialize-internal($xml,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
        <json-format value="Snelson"/>
      </options>
   }
 )
};

(:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::)

declare %private function json:parse-internal(
  $json as xs:string,
  $options as item()?
) as element()* external;

declare %private function json:serialize-internal(
  $xml as item()*,
  $options as item()?
) as xs:string external;

(: vim:set et sw=2 ts=2: :)
