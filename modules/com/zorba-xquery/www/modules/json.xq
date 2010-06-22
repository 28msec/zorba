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
  : <p><table border="1">
  :   <tr>
  :     <td><b>JSON</b> </td><td><b>type(JSON)</b> </td><td><b>toXML(JSON)</b></td></tr>
  :   <tr>
  :     <td>JSON</td>
  :     <td>N/A</td>
  :     <td>&lt;json type="type(JSON)"&gt;toXML(JSON)&lt;/json&gt;</td>
  :   </tr>
  :   <tr>
  :     <td>{ "key1": value1, "key2": value2 }</td>
  :     <td>object </td>
  :     <td>&lt;pair name="key1" type="type(value1)"&gt;toXML(value1)&lt;/pair&gt;&lt;pair name="key2" type="type(value2)"&gt;toXML(value2)&lt;/pair&gt;</td>
  :   </tr>
  :   <tr>
  :     <td>[ value1, value2 ]</td>
  :     <td>array </td>
  :     <td>&lt;item type="type(value1)"&gt;toXML(value1)&lt;/item&gt;&lt;item type="type(value2)"&gt;toXML(value2)&lt;/item&gt;</td>
  :   </tr>
  :   <tr>
  :     <td>"value"</td>
  :     <td>string</td>
  :     <td>value</td>
  :   </tr>
  :   <tr>
  :     <td>number</td>
  :     <td>number</td>
  :     <td>number</td>
  :   </tr>
  :   <tr>
  :     <td>true/false</td>
  :     <td>boolean</td>
  :     <td>true/false</td>
  :   </tr>
  :   <tr>
  :     <td>null</td>
  :     <td>null</td>
  :     <td>empty</td>
  :   </tr>
  : </table></p>
  :
  : <p>Zorba implements the simple mapping in two functions:
  : <ul>
  :  <li>the <a href="#parse-1">parse</a> function is used for parsing a
  :      sequence of JSON strings into a sequence of elements</li>
  :  <li>the <a href="#serialize-1">serialize</a> function implements the
  :      reverse process, i.e. serializing a sequence of elements into a
  :      sequence of valid JSON strings.</li>
  : </ul></p>
  :
  : <h2>JsonML Mapping</h2>
  : <p>
  : <a href="http://jsonml.org" target="_blank">JSonML</a> (JSON Markup Language)
  : is an application of the JSON format.
  : The purpose of JSonML is to provide a compact format for transporting
  : XML-based markup as JSon. In contrast to the simple JSON mapping described above
  : JsonML allows a lossless conversion back and forth.</p>
  :
  : <p>Zorba implements the JsonML-XDM mapping in two functions:
  : <ul>
  :  <li>the <a href="#parse-ml-1">parse-ml</a> function is used for parsing a
  :      sequence of JsonML strings into a sequence of elements</li>
  :  <li>the <a href="#serialize-ml-1">serialize-ml</a> function implements the
  :      reverse process, i.e. serializing a sequence of elements into a
  :      sequence of valid JsonML strings.</li>
  : </ul></p>
  :
  : @author Sorin Nasoi
  :
  :)
module namespace json = "http://www.zorba-xquery.com/modules/json";

(:~
 : This function parses a JSON string and returns an XDM instance according
 : to the simple JSON-XDM mapping described above.
 : 
 : <p><b>Query:</b></p>
 : <pre><code>
 : json:parse('{
 :      "firstName": "John",
 :      "lastName": "Smith",
 :      "address": {
 :          "streetAddress": "21 2nd Street",
 :          "city": "New York",
 :      },
 :      "phoneNumbers": [
 :          "646 123-4567"
 :      ]
 :  }')</code></pre>
 :
 : <p><b>Result:</b></p>
 : <pre><code>
 : &lt;json type="object">
 :   &lt;pair name="firstName" type="string">John&lt;/pair>
 :   &lt;pair name="lastName" type="string">Smith&lt;/pair>
 :   &lt;pair name="address" type="object">
 :     &lt;pair name="streetAddress" type="string">21 2nd Street&lt;/pair>
 :     &lt;pair name="city" type="string">New York&lt;/pair>
 :   &lt;/pair>
 :   &lt;pair name="phoneNumbers" type="array">
 :     &lt;item type="string">212 732-1234&lt;/item>
 :   &lt;/pair>
 : &lt;/json></code></pre>
 :
 : @param $text a sequence of valid JSON strings
 : @return  a sequence of nodes according to the simple JSON-XDM mapping
 : @error API0060 if any of the strings passed as parameter is not valid JSON.
 :)
declare function json:parse(
  $text as xs:string*
) as node()* external;

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to the
 : simple mapping described above.
 :
 : <p><b>Query:</b></p>
 : <pre><code>
 : json:serialize(
 :   &lt;json type="object">
 :     &lt;pair name="firstName" type="string">John&lt;/pair>
 :     &lt;pair name="lastName" type="string">Smith&lt;/pair>
 :     &lt;pair name="address" type="object">
 :       &lt;pair name="streetAddress" type="string">21 2nd Street&lt;/pair>
 :       &lt;pair name="city" type="string">New York&lt;/pair>
 :     &lt;/pair>
 :     &lt;pair name="phoneNumbers" type="array">
 :       &lt;item type="string">212 732-1234&lt;/item>
 :     &lt;/pair>
 :   &lt;/json>
 : )</code></pre>
 :
 : <p><b>Result:</b></p>
 : <pre><code>
 : {
 :   "firstName": "John",
 :   "lastName": "Smith",
 :   "address": {
 :    "streetAddress": "21 2nd Street",
 :    "city": "New York",
 :   },
 :   "phoneNumbers": [
 :     "212 732-1234"
 :   ]
 : }</code></pre>
 :
 : @param $xml a sequence of nodes conformant to the simple mapping described above
 : @return a sequence of JSON strings
 : @error API0061 if the passed elements do not have a valid JSON structure
 :)
declare function json:serialize(
  $xml as node()*
) as xs:string* external;

(:~
 : This function parses JSON and returns an XDM instances according
 : to the JsonML mapping described above.
 :
 : <p><b>Query:</b></p>
 : <pre><code>
 : json:parse-ml(
 :   '["table", {"class":"maintable"},
 :      ["tr", {"class":"odd"},
 :        ["th", {}, "Situation"],
 :        ["th", "Result"] ],
 :      ["tr", {"class":"even"},
 :        ["td", ["a",  {"href" : "driving.html", "title" : "Driving"}, "Driving"]],
 :        ["td", "Busy"] ]
 :    ]'
 : )</code></pre>
 :
 : <p><b>Result:</b></p>
 : <pre><code>
 : &lt;table class="maintable">
 :   &lt;tr class="odd">
 :     &lt;th>Situation&lt;/th>
 :     &lt;th>Result&lt;/th>
 :   &lt;/tr>
 :   &lt;tr class="even">
 :     &lt;td>&lt;a href="driving.html" title="Driving">Driving&lt;/a>&lt;/td>
 :     &lt;td>Busy&lt;/td>
 :   &lt;/tr>
 : &lt;/table></code></pre>
 :
 : @param $text a sequence of valid JSON strings
 : @return a sequence of nodes that result from parsing the given
 :         JSON strings according to the JsonML mapping
 : @error API0063 if the string representation of the value passed
 :        was empty or any of the passed strings are not valid JSON
 :)
declare function json:parse-ml(
  $text as xs:string*
) as node()* external;

(:~
 : This function serializes a sequence of elements by
 : transforming each element into a valid JSON string according to the JsonML
 : mapping described above.
 :
 : <p><b>Query:</b></p>
 : <pre><code>
 : json:serialize-ml(
 :   &lt;ul>
 :     &lt;li>true&lt;/li>
 :     &lt;li href="driving.html" title="Driving">Second item&lt;/li>
 :     &lt;li/>
 :     &lt;li>-1.4&lt;/li>
 :   &lt;/ul>
 : )</code></pre>
 :
 : <p><b>Result:</b></p>
 : <pre><code>
 : ["ul",
 :   ["li", "true"],
 :   ["li", {"href":"driving.html"}, {"title":"Driving"}, "Second item"],
 :   ["li"],
 :   ["li", "-1.4"]
 : ]</code></pre>
 :
 : @param $xml the sequence of nodes that should be converted to JsonML
 : @return a sequence of JSON strings resulting from transforming the
 :         given parameter to JSON according to the XDM-JsonML mapping
 :)
declare function json:serialize-ml(
  $xml as node()*
) as xs:string* external;
