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
 : This modules defines a set of functions for managing collections that are
 : declared in the prolog of a module.
 : For example, it provides functions to create, delete, or introspect
 : collections.
 : <p/>
 : This module is part of <a href="../zorba/xqddf.html">Zorba's XQuery Data
 : Definition Facility</a>. All the collections managed by this module
 : have to be pre-declared in the prolog of a module. Please refer to the
 : <a href="../zorba/data_lifecycle.html">general documentation</a>
 : for more information and examples.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../zorba/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://zorba.io/modules/store/static/collections/dml
 : @see http://zorba.io/modules/store/static/indexes/ddl
 : @see http://zorba.io/modules/store/static/indexes/dml
 : @see http://zorba.io/modules/store/static/integrity-constraints/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/errors
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/Static Data Definition
 :)
module namespace cddl = "http://zorba.io/modules/store/static/collections/ddl";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Gets the QNames of the collections that have been statically declared and
 : are available, if any.
:
 : @return A sequence comprising one QName for each statically declared and
 : available collection or an emtpy sequence if no such collections are
 : available.
 :)
declare function cddl:available-collections()
  as xs:QName* external;

(:~
 : Creates a collection.
 :
 : @param $name The of the collection to create.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection with the given name.
 : @error zerr:ZDDY0001 if <code>$name</code> is not equal to any of the
 : declared collections in the static context.
 : @error zerr:ZDDY0002 if a collection with <code>$name</code> already exists.
 :)
declare updating function cddl:create( $name as xs:QName ) external;

(:~
 : Creates a collection and adds the given sequence as content to the new
 : collection.
 :
 : @param $name The name of the collection to create.
 : @param $content The sequences of items (nodes or JSON items) to be added to
 : the new collection.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection with the given name and inserts the given items into
 : it.
 : @error zerr:ZDDY0001 if <code>$name</code> is not equal to any of the
 : declared collections in the static context.
 : @error zerr:ZDDY0002 if a collection with <code>$name</code> already exists.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type declared by the collection according to the rules for SequenceType
 : Matching.
 :)
declare updating function cddl:create( $name as xs:QName,
                                       $content as item()* )
  external;

(:~
 : Gets the collections that have been declared in the prolog of the static
 : context.
 :
 : @return A sequence of QNames, one for each collection created in the static
 : context, or an emtpy sequence.
 :)
declare function cddl:declared-collections()
  as xs:QName* external;

(:~
 : Deletes a collection.
 :
 : @param $name The collection to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the collection with the given name.
 : @error zerr:ZDDY0001 if <code>$name</code> is not equal to any of the
 : declared collections in the static context.
 : @error zerr:ZDDY0003 if the collection identified by <code>$name</code> is
 : not available.
 : @error zerr:ZDDY0013 if the domain or key expression of any of the available
 : indexes access the collection having <code>$name</code>.
 : @error zerr:ZDDY0015 if any of the in-scope variables references an item
 : that belongs to the collection having <code>$name</code>
 :)
declare updating function cddl:delete( $name as xs:QName )
  external;

(:~
 : Gets whether a collection is statically declared and available.
 :
 : @param $name The name of the collection to check.
 : @return true if the collection was statically declared and is available;
 : false otherwise.
 :)
declare function cddl:is-available-collection( $name as xs:QName )
  as xs:boolean external;

(:~
 : Gers whether a collection was declared in the prolog of the static context.
 :
 : @param $name The name of the collection to check.
 : @return true if the collection was declared; false otherwise.
 :)
declare function cddl:is-declared-collection( $name as xs:QName )
  as xs:boolean external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
