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
 : chapter 8 (Function Library). JSONiq extends
 : the XQuery specification to also deal with JSON data natively. See
 :
 :     http://www.jsoniq.org/
 :
 : for details.
 :
 : This module depends on having the JSONiq feature enabled in Zorba,
 : i.e., Zorba must be compiled with ZORBA_WITH_JSON.
 :
 : @author Ghislain Fourny
 :)
module namespace libjn = "http://www.jsoniq.org/function-library";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : This function dynamically builds an object, like jn:object, except that
 : it does not throw an error upon pair collision. Instead, it aggregates them
 : into an array.
 :
 : @param $o A sequence of objects.
 : @return The accumulated object.
 :)
declare function libjn:accumulate($o as object()*) as object()
{
  {[ $o ]}
};

(:~
 : This function returns all Objects contained within a JSON item, regardless of
 : depth.
 :
 : @param $i A JSON item.
 : @return Its descendant objects.
 :)
declare function libjn:descendant-objects($i as json-item()) as object()*
{
  if ($i instance of object())
  then
    (
      $i,
      for $v in libjn:values($i)
      where $v instance of json-item()
      return libjn:descendant-objects($v)
    )
  else if ($i instance of array())
  then
    (
      for $v in libjn:members($i)
      where $v instance of json-item()
      return libjn:descendant-objects($v)
    )
  else
    ()
};

(:~
 : This function returns all pairs contained within an object, recursively.
 :
 : @param $o An object.
 : @return All direct and indirect descendant pairs.
 :)
declare function libjn:descendant-pairs($o as object()) as object()*
{
  for $k in jn:keys($o)
  return (
    { $k : $o($k) },
    if ($o($k) instance of object())
    then
      libjn:descendant-pairs($o($k))
    else ()
  )
};

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
declare function libjn:flatten($a as array()) as item()*
{
  jn:flatten($a)
};

(:~ This function returns the intersection of two objects, and aggregates
 : values corresponding to the same name into an array.
 :
 : @param $o A sequence of objects.
 : @return Their insersection.
 :)
declare function libjn:intersect($o as object()*) as object()
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
 : Returns the members of an Array.
 :
 : @param $a A JSON Array.
 : @return The members of the specified array.
 :)
declare function libjn:members($o as array()) as item()*
{
  jn:members($o)
};

(:~
 : Creates an object from the specified pairs of another given object. 
 : Specifically, for each name in $names, if the object $o has a pair with
 : that name, then a copy of that pair is included in the new object.
 :
 : @param $o A JSON Object.
 : @param $names The names of the pairs to copy out of $o and insert into the new object
 : @return The new object.
 :)
declare function libjn:project($o as object(), $names as xs:string*) as object()
{
  jn:project($o, $names)
};

(:~
 : This functions returns all values in an Object.
 : @param $i An object.
 : @return Its values.
 :)
declare function libjn:values($i as object()) as item()*
{
  for $k in jn:keys($i)
  return $i($k)
};