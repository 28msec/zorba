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

(:~
 : This function allows dynamic object construction by merging all
 : its object parameters into a single object with a so-called "simple
 : object union". A simple object union creates a new object, the pairs
 : property of which is obtained by accumulating the pairs of all operand
 : objects. An error jerr:JNDY0003 is raised if two pairs with the same
 : name are encountered.
 :
 : @param $o A sequence of objects.
 : @return The simple object union.
 :)
declare function jn:object($o as object()*) as object()
{
  {| $o |}
};

(:~
 : This function dynamically builds an object, like jn:object, except that
 : it does not throw an error upon pair collision. Instead, it aggregates them
 : into an array.
 :
 : @param $o A sequence of objects.
 : @return The accumulated object.
 :)
declare function jn:accumulate($o as object()*) as object()
{
  {[ $o ]}
};

(:~
 : This function returns all Objects contained within a JSON item, regardless of
 : depth.
 :
 : @param A JSON item.
 : @return Its descendant objects.
 :)
declare function jn:descendant-objects($i as json-item()) as object()*
{
  if ($i instance of object())
  then
    (
      $i,
      for $v in jn:values($i)
      where $v instance of json-item()
      return jn:descendant-objects($v)
    )
  else if ($i instance of array())
  then
    (
      for $v in jn:members($i)
      where $v instance of json-item()
      return jn:descendant-objects($v)
    )
  else
    ()
};

(:~
 : This function returns all pairs contained within an object, recursively.
 :
 : @param An object.
 : @return All direct and indirect descendant pairs.
 :)
declare function jn:descendant-pairs($o as object())
{
  for $k in jn:keys($o)
  return (
    { $k : $o($k) },
    if ($o($k) instance of object())
    then
      jn:descendant-pairs($o($k))
    else ()
  )
};

(:~ This function returns the intersection of two objects, and aggregates
 : values corresponding to the same name into an array.
 :
 : @param $o A sequence of objects.
 : @return Their insersection.
 :)
declare function jn:intersect($o as object()*)
{
  {|
    let $common-keys := jn:keys($o[1])[ every $object in $o[position() > 1]
                                           satisfies jn:keys($object) = . ]
    for $key in $common-keys
    let $values := $o($key)
    return
      if (count($values) eq 1)
      then { $key : $values }
      else { $key : [ $values ] }
  |}
};

(:~
 : This functions returns all values in an Object.
 : @param $i An object.
 : @return Its values.
 :)
declare function jn:values($i as object()) as item()*
{
  for $k in jn:keys($i)
  return $i($k)
};