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
  : expressing queries on XML data.<br/>
  : This makes XQuery the perfect choice for a data processing language on the
  : Web because XML is widely used there. However, there are also some other
  : data formats present on the Web.<br/>
  : For example, <a href="http://www.json.org/" target="_blank">JSon</a>
  : (JavaScript Object Notation) is the most common data format for applications
  : which are written in JavaScript.<br/>
  : Zorba implements a set of functions that opens XQuery developers the door to
  : processing other data formats (like JSon).<br/>
  : In this module, we describe these functions in detail.
  :
  : @author Sorin Nasoi
  : @version 1.0
  :
  :<h2><a name="conv_json">1 JSon Functions</a></h2>
  :JSon is a lightweight hierarchical data-interchange format. Like XML, it is
  :easy for humans to read and write. Moreover, it is easy for machines to parse
  : and generate.<br/>
  :In order to process JSon with XQuery, Zorba implements a mapping between JSon
  : and XML that was proposed by John Snelson in his article
  : <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more" target="_blank">Parsing JSon into XQuery</a>.<br/>
  : In this article, he describes the following recursive mapping declarations.<br/>
  :<table border="1" cellpadding="0" cellspacing="0">
  :<tr>
  :<td><b>JSon</b> </td><td><b>type(JSon)</b> </td><td><b>toXML(JSon)</b></td></tr>
  :<tr>
  :<td>JSon </td><td>N/A </td><td>&lt;json type="type(JSon)"&gt;toXML(JSon)&lt;/json&gt;  </td></tr>
  :<tr>
  :<td>{ "key1": value1, "key2": value2 } </td><td>object </td><td>&lt;pair name="key1" type="type(value1)"&gt;toXML(value1)&lt;/pair&gt;&lt;pair name="key2" type="type(value2)"&gt;toXML(value2)&lt;/pair&gt;  </td></tr>
  :<tr>
  :<td>[ value1, value2 ] </td><td>array </td><td>&lt;item type="type(value1)"&gt;toXML(value1)&lt;/item&gt;&lt;item type="type(value2)"&gt;toXML(value2)&lt;/item&gt;  </td></tr>
  :<tr>
  :<td>"value" </td><td>string </td><td>value  </td></tr>
  :<tr>
  :<td>number </td><td>number </td><td>number  </td></tr>
  :<tr>
  :<td>true / false </td><td>boolean </td><td>true / false  </td></tr>
  :<tr>
  :<td>null </td><td>null </td><td>empty  </td></tr>
  :</table>
  :<br/>
  :Zorba implements this mapping in two functions: the <a href="#parse-1">parse</a>
  : function is used for parsing a sequence of JSon strings into a sequence of
  : elements, the <a href="#serialize-1">serialize</a> function implements the
  : reverse process, i.e. serializing a sequence of elements into a sequence of
  :valid JSon strings. <br/>
  :
  :<h2><a name="conv_json_ml">2 JSonML Functions</a></h2>
  :<a href="http://jsonml.org" target="_blank">JSonML</a> (JSon Markup Language)
  : is an application of the <a href="http://www.json.org/" target="_blank">JSon</a>
  : (JavaScript Object Notation) format. <br/>
  :The purpose of JSonML is to provide a compact format for transporting
  :XML-based markup as JSon. In contrast to the JSon mapping depicted above (see
  : <a href="#conv_json">1 JSon Functions</a>), JSonML allows a lossless
  : conversion back and forth. <br/>
  :Zorba implements the <a href="http://jsonml.org" target="_blank">JSonML</a>
  :structure defined in this article 
  :<a href="https://www.ibm.com/developerworks/library/x-jsonml/" target="_blank">Get to know JSonML</a><br/>
  :Analogoulsy to the JSon conversion, this functionality is implemented in a
  :<a href="#parse-ml-1">parse-ml</a> and <a href="#serialize-ml-1">serialize-ml</a>
  :function, respectively.<br/><br/>
  :Note:<br/>
  :Calling json:serialize-ml(json:parse-ml($some_string)) will not
  :always produce $some_string.<br />
  :This is caused by the fact that json:serialize-ml does dot know the exact type
  : of the JSon value (true, false, null, numbers) and treats them all as strings. <br />
  :Here are some possible cases where this can happen: <br />
  :<pre class="fragment">
  :import module namespace json = "http://www.zorba-xquery.com/modules/json";<br /><br />
  :
  :  json:serialize-ml(json:parse-ml(('[ "ul",<br />
  :                  [ "li", true],<br />
  :                  [ "li", null],<br />
  :                  [ "li", -14e12]<br />
  :                  ]')))<br />
  :</pre><br />
  :will output the following result:<br /><br />
  :<pre class="fragment"><br />
  :["ul",<br />
  :  ["li", "true"],<br />
  :  ["li"],<br />
  :  ["li", "-1.4E+13"]<br />
  :]<br />
  :</pre>
  :
  :<h2><a name="conv_json_ml">3 Examples</a></h2>
  :<h3><a name="examples_json_parse">3.1 parse</a></h3>
  :<pre class="fragment">
  :import module namespace json = "http://www.zorba-xquery.com/modules/json";<br /><br />
  :json:parse(('{<br />
  :     "firstName": "John",<br />
  :     "lastName": "Smith",<br />
  :     "address": {<br />
  :       "streetAddress": "21 2nd Street",<br />
  :       "city": "New York",<br />
  :       "state": "NY",<br />
  :       "postalCode": 10021<br />
  :     },<br />
  :     "phoneNumbers": [<br />
  :       "212 732-1234",<br />
  :       "646 123-4567"<br />
  :     ]<br />
  : }',<br />
  :'{<br />
  :   "firstName": "John",<br />
  :   "state": null,<br />
  :   "bool": true ,<br />
  :   "numbers": [1,2,3] ,<br />
  :   "address": {<br />
  :     "streetAddress": "21 2nd Street",<br />
  :     "state": null,<br />
  :     "postalCode": 10021 ,<br />
  :     "literals": [true,false,null],<br />
  :     "delivery": {<br />
  :       "streetAddress": "StreetName",<br />
  :       "city": "CityName",<br />
  :       "state": "StateName",<br />
  :     }<br />
  :   } ,<br />
  :   "strings": [<br />
  :     "one",<br />
  :     "two",<br />
  :     "three",<br />
  :     "four" ]<br />
  :}'))<br />
  :</pre><br />
  :
  :Executing this query and serializing its result to XML yields the following:
  :<pre class="fragment">
  :  <json type="object"><br />
  :    <pair name="firstName" type="string">John</pair><br />
  :    <pair name="lastName" type="string">Smith</pair><br />
  :    <pair name="address" type="object"><br />
  :      <pair name="streetAddress" type="string">21 2nd Street</pair><br />
  :      <pair name="city" type="string">New York</pair><br />
  :      <pair name="state" type="string">NY</pair><br />
  :      <pair name="postalCode" type="number">10021</pair><br />
  :    </pair><br />
  :    <pair name="phoneNumbers" type="array"><br />
  :      <item type="string">212 732-1234</item><br />
  :      <item type="string">646 123-4567</item><br />
  :    </pair><br />
  :  </json><br />
  :  <json type="object"><br />
  :    <pair name="firstName" type="string">John</pair><br />
  :    <pair name="state" type="null"/><br />
  :    <pair name="bool" type="boolean">true</pair><br />
  :    <pair name="numbers" type="array"><br />
  :      <item type="number">1</item><br />
  :      <item type="number">2</item><br />
  :      <item type="number">3</item><br />
  :    </pair><br />
  :    <pair name="address" type="object"><br />
  :    <pair name="streetAddress" type="string">21 2nd Street</pair><br />
  :    <pair name="state" type="null"/><br />
  :    <pair name="postalCode" type="number">10021</pair><br />
  :    <pair name="literals" type="array"><br />
  :      <item type="boolean">true</item><br />
  :      <item type="boolean">false</item><br />
  :      <item type="null"/><br />
  :    </pair><br />
  :    <pair name="delivery" type="object"><br />
  :      <pair name="streetAddress" type="string">StreetName</pair><br />
  :      <pair name="city" type="string">CityName</pair><br />
  :      <pair name="state" type="string">StateName</pair><br />
  :    </pair><br />
  :  </pair><br />
  :  <pair name="strings" type="array"><br />
  :    <item type="string">one</item><br />
  :    <item type="string">two</item><br />
  :    <item type="string">three</item><br />
  :    <item type="string">four</item><br />
  :  </pair><br />
  :</json><br />
  :</pre><br />
  :
  :<h3><a name="examples_json_serialize">3.2 serialize</a></h3>
  :<pre class="fragment">
  :import module namespace json = "http://www.zorba-xquery.com/modules/json";<br /><br />
  :
  :declare variable $str as xs:string := '{"firstName": "John","state": null,"bool": true,"numbers": [1,2,3],"address": {"streetAddress": "21 2nd Street","state": null,"postalCode": 10021,"literals": [true,false,null],"delivery": {"streetAddress": "StreetName","city": "CityName","state": "StateName"}},"strings": ["one","two","three","four"]}';<br /><br />
  :
  :json:serialize(json:parse($str)) eq $str<br />
  :</pre><br />
  :
  :<h3><a name="examples_json_ml_parse">3.3 parse-ml</a></h3>
  :
  :<pre class="fragment">
  :import module namespace json = "http://www.zorba-xquery.com/modules/json";<br /><br />
  :
  :json:parse-ml(('[ "ul",<br />
  :                [ "li",<br />
  :                  true],<br />
  :                [ "li",<br />
  :                  {"href":"driving.html", "title":"Driving"},<br />
  :                  "Second item"],<br />
  :                [ "li", null],<br />
  :                [ "li", -14]<br />
  :                ]', '["table",{"class":"maintable"},<br />
  :                      ["tr",{"class":"odd"},<br />
  :                      ["th",{},"Situation"],<br />
  :                      ["th","Result"]],<br />
  :                      ["tr", {"class":"even"},<br />
  :                      ["td",  ["a",  {"href":"driving.html", "title":"Driving"},"Driving"]],<br />
  :                      ["td", "Busy"] ] ]'))<br />
  :</pre><br />
  :Result :<br /><br />
  :<pre class="fragment"><br />
  :<ul><br />
  :<li>true</li><br />
  :<li href="driving.html" title="Driving">Second item</li><br />
  :<li/><br />
  :<li>-1.4E+13</li><br />
  :</ul><br />
  :<table class="maintable"><br />
  :  <tr class="odd"><br />
  :    <th>Situation</th><br />
  :    <th>Result</th><br />
  :  </tr><br />
  :  <tr class="even"><br />
  :    <td><a href="driving.html" title="Driving">Driving</a></td><br />
  :    <td>Busy</td><br />
  :  </tr><br />
  :</table><br />
  :</pre><br />
  :
  :<h3><a name="examples_json_ml_serialize">3.4 serialize-ml</a></h3>
  :
  :<pre class="fragment">
  :import module namespace json = "http://www.zorba-xquery.com/modules/json";<br /><br />
  :
  :json:serialize-ml((<ul><li>true</li><li href="driving.html" title="Driving">Second item</li><li/><li>-1.4</li></ul>
  :,<table class="maintable"><tr class="odd"><th>Situation</th><th>Result</th></tr><tr class="even"><td><a href="driving.html" title="Driving">Driving</a></td><td>Busy</td></tr></table>))<br />
  :</pre><br />
  :Result :<br /><br />
  :<pre class="fragment"><br />
  :  ["ul",<br />
  :["li", "true"],<br />
  :  ["li",{"href":"driving.html"}, {"title":"Driving"}, "Second item"],<br />
  :  ["li"],<br />
  :  ["li", "-1.4E+13"]<br />
  :]<br />
  :["table", {"class":"maintable"},<br />
  :  ["tr", {"class":"odd"},<br />
  :    ["th", "Situation"],<br />
  :    ["th", "Result"]<br />
  :  ],<br />
  :  ["tr", {"class":"even"},<br />
  :    ["td", ["a", {"href":"driving.html"}, {"title":"Driving"}, "Driving"]],<br />
  :    ["td", "Busy"]<br />
  :  ]<br />
  :]<br />
  :</pre><br />
  :
  :
  :)
module namespace json = "http://www.zorba-xquery.com/modules/json";

 (:~
  : Parsing JSon into the XQuery Data Model (XDM) according to the mapping in
  :John Snelson's article
  :
  : @param $text a sequence of valid JSon strings 
  : @return  a sequence of nodes
  : @error API0060 if any of the strings passed as parameter are not a valid JSon
  :)
declare function json:parse(
  $text as xs:string*
) as node()* external;

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSon string according to the mapping
 : depicted in John Snelson's article.
 :
 : @param $xml a sequence of nodes conformant to the mapping described above
 : @return a sequence of JSon strings representation of the passed sequence of nodes
 : @error API0061 if the passed elements do not have a valid JSon structure
 : @error API0062 if the passed parameters are not nodes
 :)
declare function json:serialize(
  $xml as node()*
) as xs:string* external;

 (:~
  : Parsing JSon into the XQuery Data Model (XDM) according to the JSonML mapping
  :
  : @param $text a sequence of valid JSon string
  : @return a sequence of nodes
  : @error API0063 if the string representation of the value passed was empty or
  :any of the passed strings does not represend a valid JSon string
  :)
declare function json:parse-ml(
  $text as xs:string*
) as node()* external;

 (:~
  : The serialize function takes a sequence of elements as parameter and
  : transforms each element into a valid JSon string according to the JSonML
  :mapping
  : @param $xml valid JSon string according to JSonML mapping
  : @return a sequence of JSon strings representation of the passed sequence of nodes
  : @error API0064 if the passed elements do not have a valid JSon structure
  : @error API0065 if any of the passed parameters are not elements
  :)
declare function json:serialize-ml(
  $xml as node()*
) as xs:string* external;
