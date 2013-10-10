xquery version "3.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This modules defines a set of functions for managing persistent, ordered,
 : and updatable collections.
 : <p/>
 : Please refer to our documentation for
 : <a href="../zorba/data_lifecycle.html">more information</a>
 : about the lifecycle management and the manipulation of such collections.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see http://zorba.io/modules/store/dynamic/collections/dml
 : @see http://zorba.io/errors
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/Dynamic Data Definition
 :)
module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Gets the QNames of the collections that are available, if any.
 :
 : @return A sequence comprising one QName for each available collection
 : or an emtpy sequence if no collections are available.
 :)
declare function ddl:available-collections()
  as xs:QName* external;

(:~
 : Creates a collection.
 :
 : @param $name The name of the collection to create.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection with the given name.
 : @error zerr:ZDDY0002 if a collection with <code>$name</code> already exists.
 :)
declare updating function ddl:create( $name as xs:QName )
  external;

(:~
 : Creates a collection and adds the given sequence as content to the new
 : collection.
 :
 : @param $name The name of the collection to create.
 : @param $content The sequence of items (nodes or JSON items)
 : to be added to the new collection.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection with the given name and inserts the given items into
 : it.
 : @error zerr:ZDDY0002 if a collection with the given name already exists.
 : @see ddl:create
 : @see ddl:insert-last
 :)
declare updating function ddl:create( $name as xs:QName,
                                      $content as item()* )
  external;

(:~
 : Deletes the collection having the given name.
 :
 : @param $name The name of the collection to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the collection with the given name.
 : @error zerr:ZDDY0003 if the collection identified by <code>$name</code> is
 : not available.
 : @error zerr:ZDDY0015 if any of the in-scope variables references an item
 : that belongs to the collection with QName <code>$name</code>.
 :)
declare updating function ddl:delete( $name as xs:QName )
  external;

(:~
 : Gets whether a collection with the given name is available.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection is available and false otherwise.
 :)
declare function ddl:is-available-collection( $name as xs:QName )
  as xs:boolean external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
