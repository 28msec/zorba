xquery version "3.0";

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
 : This module defines a set of functions for working with
 : maps. A map is identified by a QName and can
 : be created using the map:create function and deleted
 : using the map:delete function, respectively. However, its
 : actual lifetime depends on the particular store implementation.
 :
 : The key of a particular entry in the map can consist
 : out of a set of atomic values (called attributes).
 : The actual type of each attribute can be determined when the
 : map is created. The value can be an arbitrary sequence
 : of items.
 :
 : @see <a href="../../html/storing_manipulating_data.html">Data Lifecycle</a>
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Matthias Brantner
 :
 : @project store/data structures
 :)
module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Create a map with a given name and a set of types for
 : each key attribute. Note that the function is variadic
 : and might take an arbitrary amount of types for the key
 : attributes. Also note that the function is sequential
 : and immediately creates the map in the store.
 :
 : @param $name the name of the map
 : @param $key-type an arbitrary number of types, one
 :        for each key attribute.
 :
 : @return the function is sequential and immediately creates
 :         the corresponding map but returns the empty-sequence.
 :
 : @error err:XPTY0004 if any of the attribute types is not a subtype of
 :        xs:anyAtomicType.
 : @error zerr:ZSTR0001 if a map with the given name already exists.
 :)
declare %ann:variadic %ann:sequential function map:create(
  $name as xs:QName,
  $key-type as xs:QName) as empty-sequence() external;

(:~
 : Destroys the map with the given name.
 : 
 : @param $name the name of the map to delete
 :
 : @return the function is sequential and immediately deletes
 :         the map but returns the empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare %ann:sequential function map:delete(
  $name as xs:QName) as empty-sequence() external;

(:~
 : Inserts a new entry into the map with the given
 : name. Note that the function is variadic
 : and might take an arbitrary amount of key attributes.
 : If an entry with the given key already exists in the
 : map, the value sequences of the existing entry and the
 : sequence passed using $value argument are concatenated.
 : 
 : @param $name the name of the map
 : @param $value the value of the entry to insert
 : @param $key an arbitrary number of key attributes.
 :
 : @return the function is sequential and immediately inserts
 :         the entry into the map but returns the
 :         empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error err:XPTY0004 if any of the given key attributes is
 :        not a subtype of the corresponding key attribute
 :        specified when creating the map.
 :
 : @see map:create
 :
 :)
declare %ann:variadic %ann:sequential function map:insert(
  $name as xs:QName,
  $value as item()*,
  $key as xs:anyAtomicType?) as empty-sequence() external;

(:~
 : Returns the value of the entry with the given key
 : from the map.
 :
 : @param $name the name of the map
 : @param an arbitrary number of search key attributes.
 :
 : @return the value of the entry in the map identified
 :         by the given key. The empty-sequence will be returned
 :         if no entry with the given key is contained in the map.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error err:XPTY0004 if any of the given key attributes is
 :        not a subtype of the corresponding key attribute
 :        specified when creating the map.
 :
 : @see map:create
 :)
declare %ann:variadic function map:get(
  $name as xs:QName,
  $key as xs:anyAtomicType?) as item()* external;

(:~
 : Removes an entry identified by the given key from the map.
 :
 : @param $name the name of the map
 : @param an arbitrary number of search key attributes.
 :
 : @return the function is sequential and immediately removes
 :         the entry into the map but returns the
 :         empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error err:XPTY0004 if any of the given key attributes is
 :        not a subtype of the corresponding key attribute
 :        specified when creating the map.
 :
 : @see map:create
 :
 :)
declare %ann:variadic %ann:sequential function map:remove(
  $name as xs:QName,
  $key as xs:anyAtomicType?) as empty-sequence() external;

(:~
 : Returns the keys of all entries of a map. The keys
 : are returned as sequence of nodes of the form:
 :
 : <pre>
 : &lt;key xmlns="http://www.zorba-xquery.com/modules/store/data-structures/unordered-map">
 :   &lt;attribute value="key1_value"/>
 :   &lt;attribute value="key2_value"/>
 :   &lt;attribute value="key3_value"/>
 : &lt;/key>
 : </pre>
 :
 : The following condition always holds:
 : <tt>map:size($name) eq fn:count(map:keys($name))</tt>
 :
 : @param $name the name of the map
 :
 : @return all keys in the map.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : 
 :)
declare function map:keys(
  $name as xs:QName) as node()* external;

(:~
 : The number of entries in a map.
 :
 : The following condition always holds:
 : <tt>map:size($name) eq fn:count(map:keys($name))</tt>
 : 
 : @param $name the name of the map
 :
 : @return the number of entries in the map.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare function map:size(
  $name as xs:QName) as xs:integer external;

(:~
 : The function returns a sequence of QNames of the maps that are
 : available. The sequence will be empty if there are no maps.
 :
 : @return A sequence of QNames, one for each available map, or an emtpy sequence.
 :
 :)
declare function map:available-maps() as xs:QName* external;
