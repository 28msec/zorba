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
 : Such collections are identified by a URI as defined in the XQuery
 : specification.
 : However, please note that we do not advise users to use collections
 : identified by URIs.
 : Instead, we refer to the
 : <a href="../zorba/data_lifecycle.html">data lifecycle documentation</a>.
 : It gives an overview of several ways to work with collections, documents,
 : and other data-structures.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see http://zorba.io/modules/store/dynamic/collections/w3c/dml
 : @see http://zorba.io/modules/store/dynamic/collections/ddl
 : @see http://zorba.io/modules/store/dynamic/collections/dml
 : @see http://zorba.io/errors
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/W3C Data Definition
 :)
module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/w3c/ddl";

import module namespace qddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : THIS FUNCTION IS FOR INTERNAL USE ONLY.
 : Converts a URI given as a string into a reserved QName.
 : This QName is used in the module to be able to store collections identified
 : by URIs using dynamic collections that are identified by QNames.
 :
 : @param $uri URI to convert to a reserved QName.
 : @return The reserved QName for the given URI.
 :)
declare function ddl:to-qname( $uri as xs:string )
  as xs:QName
{
  fn:QName( $uri, "zorba-internal-name-for-w3c-collections" )
};

(:~
 : THIS FUNCTION IS FOR INTERNAL USE ONLY.
 : Gets the namespace component of the given QName.
 :
 : @param $name The QName whose namespace component should be returned.
 : @return The namespace component of <code>$name</code>
 :)
declare function ddl:from-qname( $name as xs:QName )
  as xs:string
{
  fn:namespace-uri-from-QName( $name )
};

(:~
 : Checks whether a collection with the given URI exists.
 :
 : @param $uri The URI of the collection to check.
 : @return true if the collection is available and false otherwise.
 :)
declare function ddl:is-available-collection( $uri as xs:string )
  as xs:boolean
{
  qddl:is-available-collection( ddl:to-qname( $uri ) )
};

(:~
 : The function returns a sequence of URIs of the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of URIs, one for each available collection, or an emtpy
 : sequence.
 :)
declare function ddl:available-collections()
  as xs:string* 
{
  for $c in qddl:available-collections()
  where fn:local-name-from-QName( $c )
        eq "zorba-internal-name-for-w3c-collections"
  return ddl:from-qname( $c )
};

(:~
 : Creates the collection with the given URI.
 :
 : @param $uri The URI of the collection to create.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection with the given URI.
 : @error zerr:ZDDY0002 if a collection identified by <code>$uri</code> already
 : exists.
 :)
declare updating function ddl:create( $uri as xs:string )
{
  qddl:create( ddl:to-qname( $uri ) )
};

(:~
 : Creates the collection with the given URI and adds copies of the given
 : sequence to the new collection.
 :
 : @param $uri The URI of the collection to create.
 : @param $content The sequence of nodes to add to the new collection.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates a collection identified by <code>$uri</code> and inserts
 : <code>$content</code> into it.
 : @error zerr:ZDDY0002 if a collection identified by <code>$uri</code> already
 : exists.
 :)
declare updating function ddl:create( $uri as xs:string,
                                      $content as node()* )
{
  qddl:create( ddl:to-qname( $uri ), $content )
};

(:~
 : Deletes the collection with the given URI.
 :
 : @param $uri The URI of the collection to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the collection identified by <code>$uri</code>.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0015 if any of the in-scope variables reference a node that
 : belongs to the collection identified by <code>$uri</code>.
 :)
declare updating function ddl:delete( $uri as xs:string )
{
  qddl:delete( ddl:to-qname( $uri ) )
};

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
