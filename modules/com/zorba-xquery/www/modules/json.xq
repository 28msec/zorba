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
  : In the XQuery specification, XQuery is described as a language capable of
  : expressing queries on XML data.
  : This makes XQuery the perfect choice for a data processing language on the
  : Web because XML is widely used there. However, there are also some other
  : data formats present on the Web.
  : For example, <a href="http://www.json.org/" target="_blank">JSON</a>
  : (JavaScript Object Notation) is the most common data format for applications
  : which are written in JavaScript.
  : Zorba implements a set of functions that opens XQuery developers the door to
  : processing other data formats (like JSon).
  : This module provides functions that allow to process JSON data. That is,
  : it provides functions to convert JSON to XDM and to serialize XDM
  : to JSON.
  :
  : @author Sorin Nasoi
  : @version 1.0
  :
  : <h2><a name="conv_json">1 JSon Functions</a></h2>
  : JSON is a lightweight hierarchical data-interchange format. Like XML, it is
  : easy for humans to read and write. Moreover, it is easy for machines to parse
  : and generate.<br/>
  : In order to process JSON with XQuery, Zorba implements a mapping between JSON
  : and XML that was proposed by John Snelson in his article
  : <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more" target="_blank">Parsing JSON into XQuery</a>.<br/>
  : In this article, he describes the following recursive mapping declarations.<br/>
  : <table border="1" cellpadding="0" cellspacing="0">
  : <tr>
  : <td><b>JSON</b> </td><td><b>type(JSON)</b> </td><td><b>toXML(JSON)</b></td></tr>
  : <tr>
  : <td>JSON </td><td>N/A </td><td>&lt;json type="type(JSON)"&gt;toXML(JSON)&lt;/json&gt;  </td></tr>
  : <tr>
  : <td>{ "key1": value1, "key2": value2 } </td><td>object </td><td>&lt;pair name="key1" type="type(value1)"&gt;toXML(value1)&lt;/pair&gt;&lt;pair name="key2" type="type(value2)"&gt;toXML(value2)&lt;/pair&gt;  </td></tr>
  : <tr>
  : <td>[ value1, value2 ] </td><td>array </td><td>&lt;item type="type(value1)"&gt;toXML(value1)&lt;/item&gt;&lt;item type="type(value2)"&gt;toXML(value2)&lt;/item&gt;  </td></tr>
  : <tr>
  : <td>"value" </td><td>string </td><td>value  </td></tr>
  : <tr>
  : <td>number </td><td>number </td><td>number  </td></tr>
  : <tr>
  : <td>true / false </td><td>boolean </td><td>true / false  </td></tr>
  : <tr>
  : <td>null </td><td>null </td><td>empty  </td></tr>
  : </table>
  : <br/>
  : Zorba implements this mapping in two functions: the <a href="#parse-1">parse</a>
  : function is used for parsing a sequence of JSON strings into a sequence of
  : elements, the <a href="#serialize-1">serialize</a> function implements the
  : reverse process, i.e. serializing a sequence of elements into a sequence of
  : valid JSon strings. <br/>
  :
  : <h2><a name="conv_json_ml">2 JSonML Functions</a></h2>
  : <a href="http://jsonml.org" target="_blank">JSonML</a> (JSON Markup Language)
  :  is an application of the <a href="http://www.json.org/" target="_blank">JSON</a>
  :  (JavaScript Object Notation) format. <br/>
  : The purpose of JSonML is to provide a compact format for transporting
  : XML-based markup as JSon. In contrast to the JSon mapping depicted above (see
  :  <a href="#conv_json">1 JSON Functions</a>), JSonML allows a lossless
  :  conversion back and forth. <br/>
  : Zorba implements the <a href="http://jsonml.org" target="_blank">JSonML</a>
  : structure defined in this article 
  : <a href="https://www.ibm.com/developerworks/library/x-jsonml/" target="_blank">Get to know JSonML</a><br/>
  : Analogoulsy to the JSON conversion, this functionality is implemented in a
  : <a href="#parse-ml-1">parse-ml</a> and <a href="#serialize-ml-1">serialize-ml</a>
  : function, respectively.<br/><br/>
  : Note:<br/>
  : Calling json:serialize-ml(json:parse-ml($some_string)) will not
  : always produce $some_string.<br />
  : This is caused by the fact that json:serialize-ml does dot know the exact type
  :  of the JSON value (true, false, null, numbers) and treats them all as strings. <br />
  :
  :)
module namespace json = "http://www.zorba-xquery.com/modules/json";

 (:~
  : Parsing JSON into the XQuery Data Model (XDM) according to the mapping 
  : described above.
  :
  : @param $text a sequence of valid JSON strings 
  : @return  a sequence of nodes
  : @error API0060 if any of the strings passed as parameter are not a valid JSON
  :)
declare function json:parse(
  $text as xs:string*
) as node()* external;

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to the mapping
 : depicted in John Snelson's article.
 :
 : @param $xml a sequence of nodes conformant to the mapping described above
 : @return a sequence of JSON strings representation of the passed sequence of nodes
 : @error API0061 if the passed elements do not have a valid JSon structure
 : @error API0062 if the passed parameters are not nodes
 :)
declare function json:serialize(
  $xml as node()*
) as xs:string* external;

 (:~
  : This function parses JSON into the XQuery Data Model (XDM)
  : according to the JSonML mapping.
  :
  : @param $text a sequence of valid JSON string
  : @return a sequence of nodes
  : @error API0063 if the string representation of the value passed was empty or
  : any of the passed strings does not represend a valid JSon string
  :)
declare function json:parse-ml(
  $text as xs:string*
) as node()* external;

 (:~
  : The serialize function takes a sequence of elements as parameter and
  : transforms each element into a valid JSon string according to the JSonML
  : mapping
  :
  : @param $xml valid JSon string according to JSonML mapping
  : @return a sequence of JSon strings representation of the passed sequence of nodes
  : @error API0064 if the passed elements do not have a valid JSon structure
  : @error API0065 if any of the passed parameters are not elements
  :)
declare function json:serialize-ml(
  $xml as node()*
) as xs:string* external;
