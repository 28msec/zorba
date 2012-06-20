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

declare namespace jdm = "http://www.jsoniq.org/";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";


(:~
 : This function has the same semantics as fn:parse-xml(), except that
 : it parses the string as JSON (not XML), and returns an Object or
 : Array rather than an XML document.
 :
 : @param $j A string containing a valid JSON text.
 : @return a JSON Object or Array item.
 :)
declare function jn:parse-json($j as xs:string) as json-item()? external;


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

