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
 : <a href="http://jsoniq.org/docs/JSONiq/html/chapter-functions.html">chapter 8 (Function Library)</a>.
 : JSONiq extends the XQuery specification to also deal with JSON data natively.
 :
 : @see http://jsoniq.org/
 : @author Ghislain Fourny
 : @project JSONiq/Function Library
 :)
module namespace libjn = "http://jsoniq.org/function-library";

import module namespace jn = "http://jsoniq.org/functions";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";


(:~
 : This function dynamically builds an object, like the {||} syntax, except that
 : it does not throw an error upon pair collision. Instead, it accumulates them
 : into an array, if more than one.
 :
 : @param $items A sequence of items, the objects of which are going to be
 :        accumulated into a single object.
 : @return The accumulated object.
 :)
declare function libjn:accumulate($items as item*) as object
{
  {[ $items ]}
};


(:~
 : This function returns all arrays contained at any depth within a sequence of items.
 :
 : @param $items A sequence of items.
 : @return The descendant arrays of the input sequence.
 :)
declare function libjn:descendant-arrays($items as item*) as array*
{
  for $i in $items
  return libjn:descendant-arrays-priv($i)
};


(:~
 : Helper function for libjn:descendant-arrays()
 :
 : @param $i An item
 : @return The descendant arrays of the item
 :)
declare %private function libjn:descendant-arrays-priv($i as item) as array*
{
  typeswitch ($i)

  case object return
    for $v in libjn:values($i)
    where $v instance of json-item
    return libjn:descendant-arrays-priv($v)

  case array return
    (
    $i,
    for $v in $i[]
    where $v instance of json-item
    return libjn:descendant-arrays-priv($v)
    )

  default return
    ()
};


(:~
 : This function returns all objects contained at any depth within a sequence of items.
 :
 : @param $items A sequence of items.
 : @return The descendant objects of the input sequence.
 :)
declare function libjn:descendant-objects($items as item*) as object*
{
  for $i in $items
  return libjn:descendant-objects-priv($i)
};


(:~
 : Helper function for libjn:descendant-objects()
 :
 : @param $i An item
 : @return The descendant objects of the item
 :)
declare %private function libjn:descendant-objects-priv($i as item) as object*
{
  if ($i instance of object)
  then
    (
      $i,
      for $v in libjn:values($i)
      where $v instance of json-item
      return libjn:descendant-objects-priv($v)
    )
  else if ($i instance of array)
  then
    (
      for $v in $i[]
      where $v instance of json-item
      return libjn:descendant-objects-priv($v)
    )
  else
    ()
};


(:~
 : This function returns all pairs contained at any depth within an sequence of items.
 :
 : @param $o An object.
 : @return All direct and indirect descendant pairs.
 :)
declare function libjn:descendant-pairs($items as item*) as object*
{
  for $i in $items
  return libjn:descendant-pairs-priv($i)
};


(:~
 : Helper function for libjn:descendant-pairs()
 :
 : @param $i An item
 : @return The descendant pairs of the item
 :)
declare function libjn:descendant-pairs-priv($i as item) as object*
{
  typeswitch ($i)

  case $o as object return
    for $k in jn:keys($o)
    return
      (
      { $k : $o($k) },
      libjn:descendant-pairs-priv($o($k))
      )

  case $a as array return
    for $i in $a[]
    where $i instance of json-item
    return libjn:descendant-pairs-priv($i)

  default return
    ()
};


(:~
 : This function returns the intersection of the objects contained in the
 : given sequence of items, aggregating values corresponding to the same key
 : into an array.
 :
 : @param $items A sequence of items.
 : @return The insersection of the objects contained in $items.
 :)
declare function libjn:intersect($items as item*) as object
{
  {|
    let $objects := $items[$$ instance of object]
    for $key in keys(head($objects))
    where every $o in tail($objects)
          satisfies exists(index-of(keys($o), $key))
    return { $key : $objects.$key }
  |}
};


(:~
 : This functions returns all values of all objects contained in a sequence of items.
 :
 : @param $items A sequence of items.
 : @return The values inside the objects of the sequence.
 :)
declare function libjn:values($items as item*) as item*
{
  for $i in $items
  for $k in jn:keys($i)
  return ($i treat as object)($k)
};

