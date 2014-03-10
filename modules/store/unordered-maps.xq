jsoniq version "1.0";

(:
 : Copyright 2013 The FLWOR Foundation.
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
 : This module defines a set of functions for working with maps. A map
 : is identified by a string and can be created using the map:create function
 : and dropped using the map:drop function.
 : <p/>
 : It is possible to create persistent and transient maps. The lifetime of a
 : transient map is limited by the execution of the current query.
 : A persistent map lives until it is explicitly dropped.
 : Accordingly, it is also available to other requests.
 : <p/>
 : For example,
 : <pre>map:create("my-map", ["string", "integer"], { "persistent" : false })</pre>
 : will create a transient map named my-map having two keys.
 : The types of the keys are string and integer.
 : <p/>
 : The key of a particular entry in the map can consist of a tuple of
 : atomic values (called key attributes). The actual type of each attribute
 : is determined when the map is created. The value of each entry is a
 : sequence of items. If an item in this sequence is a object or array,
 : this item needs to belong to a collection, otherwise, an error is raised.
 :
 : @author Matthias Brantner
 : @project Zorba/Data Store/Data Structures/Unordered Map
 :)
module namespace map = "http://zorba.io/modules/unordered-maps";

declare namespace an = "http://zorba.io/annotations";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Constant containing the field name of the options object
 : indiciating whether a map is persistent or transient.
 :)
declare variable $map:PERSISTENT as string := "persistent";

(:~
 : Create a persistent map with a given name and type identifiers for the key
 : attributes.
 : <p/>
 : If the map has only one key attribute, a single type identifier is given,
 : for more than one key attribute an array of type identifiers is given.
 : Calling this function is equivalent to calling create with the options
 : <code>{ "persistent" : true }</code>
 : Note that the function is sequential and immediately creates the map.
 : <p/>
 : Each key-type should be specified as string (e.g. "integer",
 : "string", "boolean", "double", or "datetime").
 : <p/>
 : For example,
 : <pre>map:create("my-map", "string")</pre> or
 : <pre>map:create("my-map", ["string", "integer"])</pre>.
 :
 : @param $name the name of the map (the restrictions on collection names apply)
 : @param $key-type one type identifier or an array of type identifiers for the
 :        key attributes
 :
 : @return the function is sequential and immediately creates
 :         the corresponding map. It returns the empty-sequence.
 :
 : @error err:XPTY0004 if any of the key attribute types is not a subtype of
 :        anyAtomicType.
 : @error zerr:ZSTR0001 if a map with the given name already exists.
 : @error zerr:ZDDY1000 if the given name is not a legal collection name
 : @error zerr:ZDDY0043 if any of the given options has an invalid type
 :
 : @see map:create#3
 :)
declare %an:sequential function map:create(
  $name as string,
  $key-types as item) as () external;

(:~
 : Create a map with a given name, type identifiers for the key attributes, and
 : options.
 : <p/>
 : If the map has only one key attribute, a single type identifier is given,
 : for more than one key attribute an array of type identifiers is given.
 : Currently only one option is supported: To create a transient map the object
 : <code>{ "persistent" : false }</code>
 : has to be passed to the $options parameter.
 : Note that the function is sequential and immediately creates the map in the
 : store.
 : <p/>
 : Note that a map cannot be created if it already exists in a parent context.
 : For example, a map that was created in an outer query cannot be
 : created again in an inner query executed using the
 : <code>reflection:eval-s</code> function.
 :
 : @param $name the name of the map (the restrictions on collection names apply)
 : @param $key-type one type identifier or an array of type identifiers for the
 :        key attributes
 : @param $options an object describing options for the map
 :
 : @return the function is sequential and immediately creates
 :         the corresponding map but returns the empty-sequence.
 :
 : @error err:XPTY0004 if any of the attribute types is not a subtype of
 :        anyAtomicType.
 : @error zerr:ZSTR0001 if a map with the given name already exists.
 : @error zerr:ZDDY1000 if the given name is not a legal collection name
 : @error zerr:ZDDY0043 if any of the given options has an invalid type
 :
 : @see map:create#2
 :)
declare %an:sequential function map:create(
  $name as string,
  $key-types as item,
  $options as object) as () external;

(:~
 : Deletes the map with the given name.
 : <p/>
 : Note that a map can only be dropped in the context it was created.
 : For example, a map that was created in an outer query cannot be
 : dropped in an inner query executed using the
 : <code>reflection:eval-s</code> function.
 :
 : @param $name the name of the map to drop
 :
 : @return the function is sequential and immediately drops
 :         the map. It returns the empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare %an:sequential function map:drop(
  $name as string) as () external;

(:~
 : Inserts a new entry into the map with the given name.
 : <p/>
 : If the map has only one key attribute, a single key value is given, for
 : more than one key attribute an array of key values is given.
 : If an entry with the given key already exists in the map, the value
 : sequences of the existing entry and the sequence passed using $value
 : argument are concatenated.
 : <p/>
 : If an item in the value sequence is an object or array, this
 : item needs to belong to a collection, otherwise, an an error
 : is raised.
 : <p/>
 : Note that it is possible to insert entries with empty key attributes
 : or key attributes having the value <code>null</code>. However, as 
 : the comparison with an empty sequence or null always returns false, 
 : it is not possible to retrieve these entries.
 : <p/>
 : For example,
 : <pre>map:insert("my-map", "key", "value")</pre> or
 : <pre>map:insert("my-map", [ "key1", "key2" ] , (42, "value"))</pre>.
 :
 :
 : @param $name the name of the map
 : @param $key either a single attribute key or an array of keys
 : @param $value the value of the entry to insert
 :
 : @return the function is sequential and immediately inserts
 :         the entry into the map. It returns the empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error zerr:ZXQD0005 if any of the given key attributes can not
 :        be cast (or is not a subtype) of the corresponding key attribute
 :        specified when creating the map.
 : @error zerr:ZDDY1003 if the value to insert is an object or array
 :        it must belong to a collection.
 :)
declare %an:sequential function map:insert(
  $name as string,
  $key as item,
  $value as item*) as () external;

(:~
 : Returns the value of the entry with the given key from the map.
 : <p/>
 : If the map has only one key attribute, a single key value is given, for
 : more than one key attribute an array of key values is given.
 : <p/>
 : Note that it is possible to insert entries with empty key attributes.
 : However as the getting the entries is based on the "eq" comparison and
 : as "eq" with an empty sequence always return false, it is not possible
 : to retrieve these entries.
 : <p/>
 : For example,
 : <pre>map:get("my-map", "key")</pre> or
 : <pre>map:get("my-map", [ "key1", "key2" ])</pre>.
 :
 : @param $name the name of the map
 : @param $key either a single attribute key or an array of keys
 :
 : @return the value of the entry in the map identified
 :         by the given key. The empty-sequence will be returned
 :         if no entry with the given key is contained in the map.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error zerr:ZXQD0005 if any of the given key attributes can not
 :        be cast (or is not a subtype) of the corresponding key attribute
 :        specified when creating the map.
 :
 : @see map:create
 :)
declare function map:get(
  $name as string,
  $key as item) as item* external;

(:~
 : Removes an entry identified by the given key from the map.
 : <p/>
 : If the map has only one key attribute, a single key value is given, for
 : more than one key attribute an array of key values is given.
 : <p/>
 : Note that it is possible to insert entries with empty key attributes.
 : However as the removing the entries is based on the "eq" comparison and
 : as "eq" with an empty sequence always return false, it is not possible
 : to delete these entries.
 :
 : @param $name the name of the map
 : @param $key either a single attribute key or an array of keys
 :
 : @return the function is sequential and immediately deletes
 :         the entry into the map but returns the
 :         empty-sequence.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 : @error zerr:ZDDY0025 if the given number of key attributes does not match
 :        the number of key attributes specified when creating
 :        the map (see the map:create function).
 : @error zerr:ZXQD0005 if any of the given key attributes can not
 :        be cast (or is not a subtype) of the corresponding key attribute
 :        specified when creating the map.
 :
 : @see map:create
 :)
declare %an:sequential function map:delete(
  $name as string,
  $key as item) as () external;

(:~
 : Returns the keys of all entries of a map. The keys
 : are returned as sequence of arrays.
 : <p/>
 : The following condition always holds:
 : <tt>map:size($name) eq count(map:keys($name))</tt>
 :
 : @param $name the name of the map
 :
 : @return an sequence of arrays each array containing the values of all
 :   attributes of one key.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare function map:keys($name as string) as array* external;

(:~
 : Returns the number of entries in a map.
 : <p/>
 : The following condition always holds:
 : <tt>map:size($name) eq count(map:keys($name))</tt>
 :
 : @param $name the name of the map
 :
 : @return the number of entries in the map.
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare function map:size($name as string) as integer external;

(:~
 : The function returns a sequence of names of the maps that are
 : available (persistent and non-persistent). The sequence will be
 : empty if there are no maps.
 : <p/>
 :
 : @return A sequence of string, one for each available map, or
 : an empty sequence.
 :)
declare function map:available-maps() as string* external;

(:~
 : The function returns the options that were passed during creation or the
 : default options if no options were passed.
 :
 : @param $name the name of the map
 :
 : @return an options object
 :
 : @error zerr:ZDDY0023 if a map with the given name does not exist.
 :)
declare function map:options($name as string) as object external;
