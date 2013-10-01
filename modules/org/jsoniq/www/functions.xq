jsoniq version "1.0";

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
 :     http://jsoniq.org/
 :
 : for details.
 :
 : @author Markos Zaharioudakis, Matthias Brantner, Ghislain Fourny
 : @project JSONiq/Functions
 :)
module namespace jn = "http://jsoniq.org/functions";

import module namespace schema = "http://zorba.io/modules/schema";

declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace jerr = "http://jsoniq.org/errors";
declare namespace js = "http://jsoniq.org/types";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";


(:~
 : This function decodes non-JSON types previously encoded with
 : jn:encode-for-roundtrip.
 : Calling this version of the function is equivalent to calling the
 : 2 argument version of the function with the second argument
 :
 :   { "prefix" : "Q{http://jsoniq.org/roundtrip}" }
 :
 : @param $items the items to be decoded.
 : @return the decoded items.
 :)
declare function jn:decode-from-roundtrip($items as item()*) as item()* external;


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
    $items as item*,
    $options as object) as item* external;


(:~
 : This function recursively encodes non-JSON types in such a way that they
 : can be serialized as JSON while keeping roundtrip capability.
 : Calling this version of the function is equivalent to calling the
 : 2 argument version of the function with the second argument
 :
 :  {
 :    "prefix" : "Q{http://jsoniq.org/roundtrip}"
 :    "serialization-parameters" : <serialization-parameters xmlns="http://www.w3.org/2010/xslt-xquery-serialization"/>
 :  }
 :
 : Note: The computations are made with respect to the static context of the
 : caller, so that the schema type definitions are available.
 :
 : @param $items the items to be encoded.
 : @return the encoded items.
 :)
declare function jn:encode-for-roundtrip($items as item()*) as item()* external;


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
    $items as item*,
    $options as object) as item* external;


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
declare function jn:parse-json($j as string?) as json-item* external;


(:~
 : This function parses a given string as JSON and returns a sequence
 : of Objects or Arrays.
 :
 : @param $j A string containing a valid JSON text.
 : @param $o A JSON object defining options to configure the parser.
 : Allowed options are
 : <ul>
 :   <li>jsoniq-multiple-top-level-items: allow parsing of sequences of JSON Objects and Arrays (boolean; default: true)</li>
 :   <li>jsoniq-strip-top-level-array: if the top-level JSON item is an array, strip it and return its elements as multiple top-level items (boolean; default: false)</li>
 : </ul>
 :
 : @error jerr:JNDY0021 if the given string is not valid JSON or
 :   if jsoniq-multiple-top-level-items is false and there is additional
 :   content after the first JSON Object or Array.
 : @error jerr:JNTY0020 if the value for the option
 :   jsoniq-multiple-top-level-items is not of type boolean.
 :
 : @return a sequence of JSON Object or Array item.
 :)
declare function jn:parse-json($j as string?, $o as object) as json-item* external;


(:~
 : Returns the set of keys belonging to the objects found inside a given
 : sequence of items. The keys are returned in an implementation-defined
 : order. Duplicate keys are eliminated.
 :
 : @param $o A sequence of items. Only object items are actually processed;
 :           items of any other kind are simply skipped.
 : @return The distinct keys of the objects in the input sequence.
 :)
declare function jn:keys($o as item*) as string* external;


(:~
 : For each item in the given sequence, this function returns the item itself,
 : if it is not an object, or its "projected" copy if it is an object. Projecting
 : an object by a set of keys means creating a new object from the specified pairs
 : of the source object. Specifically, for each key in $keys, if the object has a
 : pair with that key, then a copy of that pair is included in the new object.
 :
 : @param $items A sequence of items.
 : @param $keys The keys of the pairs to include from each object in $items.
 : @return The projection of the original sequence.
 :)
declare function jn:project($items as item*, $keys as string*) as item* external;


(:~
 : For each item in the given sequence, this function returns the item itself,
 : if it is not an object, or its "trimmed" copy, if it is an object. Trimming
 : an object by a set of keys means creating a new object containing all the
 : pairs of the source object except the ones whose key appears in the given
 : set of keys.
 :
 : @param $items A sequence of items.
 : @param $keys The keys of the pairs to exclude from each object in $items.
 : @return The trimmed version of the input sequence.
 :)
declare function jn:trim($items as item*, $keys as string*) as item* external;


(:~
 : Returns the size of a JSON array, or the empty sequence if no array is given.
 : The size of an Array is the number of members contained within it.
 :
 : @param $array A JSON array.
 : @return The number of items in $array, or the empty sequence if $array is empty.
 :)
declare function jn:size($a as array?) as integer? external;


(:~
 : Returns the items belonging to the arrays found inside a given sequence
 : of items. The items are returned in an implementation-defined order.
 :
 : @param $a A sequence of items. Only array items are actually processed;
 :           items of any other kind are simply skipped.
 : @return The members of the arrays in the input sequence.
 :)
declare function jn:members($a as item*) as item* external;


(:~
 : For each item in the given sequence, this function returns the item itself,
 : if it is not an array, or a sequence of items "flattened-out" from the array.
 : Flattening an array means replacing the array with its members, and recursively
 : flattening any arrays in the members sequence.
 :
 : Note: The function is equivalent to
 :
 :   define function jn:flatten($args as item()*)
 :   {
 :     for $arg in args
 :     return
 :       if ($arg instance of array())
 :       then
 :         for $value in $arg[]
 :         return
 :           if ($value instance of array())
 :           then jn:flatten($value[])
 :           else $value
 :       else
 :         $arg
 :   };
 :
 : @param $items A sequence of items
 : @return The flattened-out items of the arrays in $items.
 :)
declare function jn:flatten($items as item*) as item* external;


(:~
 : Returns the JSON null.
 :
 : @return The JSON null.
 :)
declare function jn:null() as js:null external;



