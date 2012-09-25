xquery version "1.0";

(:
 : Copyright 2006-2012 The FLWOR Foundation.
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
 : This module provides the functions defined by the JSONiq specification,
 : sections 1.7 (Functions) and 1.10 (Update Primitives). JSONiq extends
 : the XQuery specification to also deal with JSON data natively. See
 :
 :     http://www.jsoniq.org/
 :
 : for details.
 :
 : This module depends on having the JSONiq feature enabled in Zorba,
 : i.e., Zorba must be compiled with ZORBA_WITH_JSON.
 :
 : @author Markos Zaharioudakis, Matthias Brantner, Ghislain Fourny
 :)
module namespace jn = "http://www.jsoniq.org/functions";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace jerr = "http://www.jsoniq.org/errors";
declare namespace js = "http://www.jsoniq.org/types";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";


(:~
 : This function decodes non-JSON types previously encoded with
 : jn:encode-for-roundtrip.
 : Calling this version of the function is equivalent to calling the
 : 2 argument version of the function with the second argument
 :
 :   { "prefix" : "Q{http://www.jsoniq.org/roundtrip}" }
 :
 : @param $items the items to be decoded.
 : @return the decoded items.
 :)
declare function jn:decode-from-roundtrip(
    $items as item()*) as item()* external;


(:~
 : This function decodes non-JSON types previously encoded with
 : jn:encode-for-roundtrip.
 : The $options parameter contains options for the decoding process.
 : Currently the only supported option is "prefix". It specifies the prefix
 : that determines if this function decodes an item.
 :
 : Example:
 :   jn:decode-from-roundtrip(
 :     { "nan" : { "pre-type" : "xs:double", "pre-value" : "NaN" } },
 :     { "prefix" : "pre-" }
 :   )
 : returns the same instance that would be constructed by
 :   { "nan" : xs:double("NaN") }
 :
 : So
 :   let $decoded := jn:decode-from-roundtrip(
 :           { "nan" : { "pre-type" : "xs:double", "pre-value" : "NaN" } },
 :           { "prefix" : "pre-" }
 :       )
 :   let $nan := $decoded("nan")
 :   return
 :       ($nan instance of xs:double, $nan)
 : returns
 :   true NaN
 :
 : @param $items the items to be decoded.
 : @param $options the decoding options.
 :
 : @error jerr:JNTY0023 if $options("prefix") is not a string
 :
 : @return the decoded items.
 :)
declare function jn:decode-from-roundtrip(
    $items as item()*,
    $options as object()) as item()* external;


(:~
 : This function recursively encodes non-JSON types in such a way that they
 : can be serialized as JSON while keeping roundtrip capability.
 : Calling this version of the function is equivalent to calling the
 : 2 argument version of the function with the second argument
 :
 :  {
 :    "prefix" : "Q{http://www.jsoniq.org/roundtrip}"
 :    "serialization-parameters" : <serialization-parameters xmlns="http://www.w3.org/2010/xslt-xquery-serialization"/>
 :  }
 :
 : Note: The computations are made with respect to the static context of the
 : caller, so that the schema type definitions are available.
 :
 : @param $items the items to be encoded.
 : @return the encoded items.
 :)
declare function jn:encode-for-roundtrip(
    $items as item()*) as item()* external;


(:~
 : This function recursively encodes non-JSON types in such a way that they
 : can be serialized as JSON while keeping roundtrip capability.
 :
 : Note: The computations are made with respect to the static context of the
 : caller, so that the schema type definitions are available.
 :
 : Example:
 :   jn:encode-for-roundtrip(
 :     { "nan" : xs:double("NaN") },
 :     { "prefix" : "pre-" }
 :   )
 : returns
 :   { "nan" : { "pre-type" : "xs:double", "pre-value" : "NaN" } }
 :
 : @param $items the items to be encoded.
 : @param $options the encoding options.
 :
 : @error jerr:JNTY0023 if $options("prefix") is not a string or
          $options("serialization-parameters") is not an element node
 : @error err:XQDY0027 if $options("serialization-parameters") is not a valid
 :        serialization-parameters element
 : @return the encoded items.
 :)
declare function jn:encode-for-roundtrip(
    $items as item()*,
    $options as object()) as item()* external;


(:~
 : This function parses a given string as JSON and returns a sequence
 : of Objects or Arrays.
 :
 : Please note that this function allows to parse sequences of whitespace
 : separated objects and arrays.
 :
 : @param $j A string containing a valid JSON text.
 :
 : @return A sequence of JSON Object or Array item.
 :
 : @error jerr:JNDY0021 if the given string is not valid JSON.
 :)
declare function jn:parse-json($j as xs:string?) as json-item()* external;

(:~
 : This function parses a given string as JSON and returns a sequence
 : of Objects or Arrays.
 :
 : @param $j A string containing a valid JSON text.
 : @param $o A JSON object defining options to configure the parser.
 : Allowed options are
 : <ul>
 :   <li>jsoniq-multiple-top-level-items: allow parsing of sequences of JSON Objects and Arrays (boolean; default: true)</li>
 : </ul>
 :
 : @error jerr:JNDY0021 if the given string is not valid JSON or
 :   if jsoniq-multiple-top-level-items is false and there is additional
 :   content after the first JSON Object or Array.
 : @error jerr:JNTY0020 if the value for the option
 :   jsoniq-multiple-top-level-items is not of type xs:boolean.
 :
 : @return a sequence of JSON Object or Array item.
 :)
declare function jn:parse-json(
  $j as xs:string?,
  $o as object()) as json-item()* external;


(:~
 : Returns the names used in the object. 
 : The names will be returned in an implementation-defined order
 :
 : @param $o A JSON Object.
 : @return The names of pairs in the object.
 :)
declare function jn:keys($o as object()) as xs:string* external;


(:~
 : Returns the value of a JSON Pair with a given name within a given JSON object.
 : If no such pair exists in the object, returns the empty sequence.
 :
 : @param $o A JSON Object.
 : @param $name The name of the pair whose value is to be retrieved
 : @return the value of specified pair within the given object, or the empty sequence.
 :)
(: obsolete - use $o($name) instead :)
declare function jn:value($o as object(), $name as xs:string) as item()? external;


(:~
 : Returns the size of a JSON Array. The size of an Array is
 : the number of members contained within it.
 :
 : @param $j A JSON Array.
 : @return The number of items in $j.
 :)
declare function jn:size($j as array()) as xs:integer external;


(:~
 : Returns the member of an Array at the specified position (starting from 1).
 : If the position is out of bounds of the array, returns the empty sequence.
 :
 : @param $a A JSON Array.
 : @param $p The position in the array.
 : @return The member at the specified position, or empty sequence.
 :)
(: obsolete - use $a($p) instead :)
declare function jn:member($a as array(), $p as xs:integer) as item()? external;


(:~
 : Creates an object from the specified pairs of another given object. 
 : Specifically, for each name in $names, if the object $o has a pair with
 : that name, then a copy of that pair is included in the new object.
 :
 : @param $o A JSON Object.
 : @param $names The names of the pairs to copy out of $o and insert into the new object
 : @return The new object.
 :)
declare function jn:project($o as object(), $names as xs:string*) as object() external;

(:~
 : Returns the members of an Array.
 :
 : @param $a A JSON Array.
 : @return The members of the specified array.
 :)
declare function jn:members($o as array()) as item()* external;


(:~
 : Recursively "flatten" a JSON Array, by replacing any arrays with their
 : members. Equivalent to
 :
 :   define function jn:flatten($arg as array()) {
 :     for $value in jn:values($arg)
 :     return
 :       if ($value instance of array())
 :       then jn:flatten($value)
 :       else $value
 :   };
 :
 : @param $a A JSON Array.
 : @return The flattened version of $a.
 :)
declare function jn:flatten($a as array()) as item()* external;

(:~
 : This function allows dynamic object construction by merging all
 : its object parameters into a single object with a so-called "simple
 : object union". A simple object union creates a new object, the pairs
 : property of which is obtained by accumulating the pairs of all operand
 : objects. An error jerr:JNDY0003 is raised if two pairs with the same
 : name are encountered.
 :
 : @param $o A sequence of objects.
 :
 : @return The simple object union.
 :
 : @error jerr:JNDY0003 if there is a pair collision.
 :)
declare function jn:object($o as object()*) as object() external;

(:~
 : Returns the JSON null.
 :
 : @return The JSON null.
 :)
declare function jn:null() as js:null external;

(:~
 : Tests whether the supplied atomic item is a JSON null.
 :
 : @param An atomic item.
 :
 : @return true if the item is of type js:null.
 :)
declare function jn:is-null($i as xs:anyAtomicType) as xs:boolean external;



