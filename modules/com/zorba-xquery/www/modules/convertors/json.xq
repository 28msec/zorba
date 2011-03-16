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
  : <p>In the XQuery specification, XQuery is described as a language
  : capable of expressing queries on XML data.
  : This makes XQuery the perfect choice for data processing on the
  : Web because XML is widely used there. However, there are also some
  : other data formats present on the Web.
  : For example, <a href="http://www.json.org/" target="_blank">JSON
  : (JavaScript Object Notation)</a> is the most common data format for
  : applications which are written in JavaScript.
  : JSON is a lightweight hierarchical data-interchange format. Like XML,
  : it is easy for humans to read and write. Moreover, it is easy for
  : machines to parse and generate.</p>
  :
  : <p>In order to enable JSON processing with XQuery, Zorba implements a set
  : of functions that open XQuery developers the door to process JSON
  : data. Specifically, this module provides two types of functions. Functions
  : to
  : <ul>
  :   <li>parse JSON and convert it to XDM and</li>
  :   <li>serialize XDM in order to output JSON.</li>
  : </ul>
  : </p>
  :
  : <p>Both types of functions are available to parse and serialize two
  : types of XDM-JSON mappings, respectively. The first mapping has been
  : <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more">
  : proposed by John Snelson</a>. The second mapping is called 
  : <a href="http://jsonml.org/">JsonML</a>. In the following, we
  : briefly describe both mappings.</p>
  : 
  : <h2>Simple XDM-JSON Mapping</h2>
  : <p>In order to process JSON with XQuery, Zorba implements a mapping between
  : JSON and XML that was initially proposed by John Snelson in his article
  : <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more"
  : target="_blank">Parsing JSON into XQuery</a>.
  : In this article, he describes the following recursive mapping declarations.
  : </p>
  :
  : <h2>JsonML Mapping</h2>
  : <p>
  : <a href="http://jsonml.org" target="_blank">JSonML</a> (JSON Markup Language)
  : is an application of the JSON format.
  : The purpose of JSonML is to provide a compact format for transporting
  : XML-based markup as JSon. In contrast to the simple JSON mapping described above
  : JsonML allows a lossless conversion back and forth.</p>
  :
  : <h2>Important Notes:</h2>
  : <p>
  : Zorba uses <a xmlns:xqdoc="http://www.xqdoc.org/1.0" href="http://www.digip.org/jansson/">Jansson library</a>
  : for manipulating JSON data that implements the <a href="http://tools.ietf.org/html/rfc4627.html"><strong>RFC 4627</strong></a>. <br />
  : <a xmlns:xqdoc="http://www.xqdoc.org/1.0" href="http://www.digip.org/jansson/">Jansson library</a> guarantees that the items are <strong>UNIQUE</strong>, it <strong>DOES NOT</strong> guarantee that they 
  : are returned in the same exact order.<br />However, this is an approved behaviour because returning the items in the same exact order if not specified in the to the 
  : <a href="http://tools.ietf.org/html/rfc4627#section-4"><strong>RFC 4627 section 4</strong></a>.</p>
  : <p>Also, please make sure that the JSON strings you want to pass to Zorba are valid. <br />
  : According to the <a href="http://tools.ietf.org/html/rfc4627.html"><strong>RFC 4627</strong></a> a valid JSON string begins with either an 
  : <a href="http://www.json.org/array.gif">array</a> or an <a href="http://www.json.org/object.gif">object</a>.<br />
  : You can use for instance <a href="http://www.jsonlint.com/">JSONLint JSON Validator</a> to make sure the JSON is valid.</p>
  : <p>We have tested against the following Jansson library versions:
  : <ul><li><a href="http://www.digip.org/jansson/doc/1.2/">Jansson 1.2.1</a></li>
  :     <li><a href="http://www.digip.org/jansson/doc/1.3/">Jansson 1.3</a></li>
  :     <li><a href="http://www.digip.org/jansson/doc/2.0/">Jansson 2.0</a></li></ul> available from <a href="http://www.digip.org/jansson/releases/">Jansson releases</a>.</p>
  :
  : @author Sorin Nasoi
  : @library <a href="http://www.digip.org/jansson/">Jansson library for encoding, decoding and manipulating JSON data</a>
  :
  : @see <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more">Mapping proposed by John Snelson</a>
  : @see <a href="http://jsonml.org" target="_blank">JSonML</a>
  : @see <a href="http://www.digip.org/jansson/doc/2.0/">Jansson library for encoding, decoding and manipulating JSON data</a>
  :
  :)
module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";

(:~
 : Import module for checking if html options element is validated.
 :)
import module namespace zorba-schema = "http://www.zorba-xquery.com/modules/schema";

(:~
 : Contains the definitions of the json options element.
 :)
import schema namespace json-options = "http://www.zorba-xquery.com/modules/convertors/json-options";

(:~
 : Errors namespace URI.
:)
declare variable $json:jsonNS as xs:string := "http://www.zorba-xquery.com/modules/convertors/json";

(:~
 : Error code for wrong parameter situations.<br/>
 : Possible error messages:<br/>
 : * "Options field must be of element options instead of ..."<br/>
:)
declare variable $json:errWrongParam as xs:QName := fn:QName($json:jsonNS, "json:errWrongParam");

(:~
 : This function parses a JSON string and returns an XDM instance according
 : to either one of the mappings described above.
 :
 : @param $arg a sequence of valid JSON strings.
 : @param $options a set of name and value pairs that provide options
 :        to configure the JSON mapping process that have to be validated against the 
 :        "http://www.zorba-xquery.com/modules/convertors/json-options" schema.
 : @return  a sequence of nodes according to either one of the mappings described above.
 : @error API0060 if any of the strings passed as parameter is not valid JSON.
 : @example rbkt/Queries/zorba/converters/jansson/parse_json_02.xq
 : @example rbkt/Queries/zorba/converters/jansson/parse_json_ml_01.xq
 :)
declare function json:parse(
  $arg as xs:string?,
  $options as element(json-options:options)?
) as document-node(element(*, xs:untyped)) external;

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to one of the
 : mappings described above.
 :
 : @param $xml a sequence of nodes.
 : @param $options a set of name and value pairs that provide options
 :        to configure the JSON mapping process that have to be validated against the 
 :        "http://www.zorba-xquery.com/modules/convertors/json-options" schema.
 : @return a JSON string.
 : @error API0061 if the passed elements do not have a valid JSON structure.
 : @example rbkt/Queries/zorba/converters/jansson/serialize_json_01.xq
 : @example rbkt/Queries/zorba/converters/jansson/serialize_json_ml_01.xq
 :)
declare function json:serialize(
  $xml as item()*, 
  $options as element(json-options:options)? 
) as xs:string external;
