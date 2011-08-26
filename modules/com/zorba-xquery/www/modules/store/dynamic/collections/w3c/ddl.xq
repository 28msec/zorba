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
 : This modules defines a set of functions for managing persistent, ordered, and
 : updatable collections.
 :
 : <p>Such collections are identified by a URI as defined in the XQuery specification.
 : However, please note that we do not advice users to use collections identified by URIs.
 : Instead, we refer to the <a href="../../html/data_lifecycle.html">data lifecycle
 : documentation</a>. It gives an overview over serveral ways to work with collections,
 : documents, and other data-structures.</p>
 :
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/dml
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 : @project store/collections/w3c
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl";

import module namespace qddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Function used for internal purposes only. It converts a URI
 : given as string into a reserved QName. This QName is used
 : in the module to be able to store collections identified by
 : URIs using dynamic collections which are identified by QNames.
 :
 : @param $name URI to convert to a reserved QName.
 :
 : @return The reserved QName for the given URI.
 :
 :)
declare function ddl:to-qname($name as xs:string) as xs:QName
{
  fn:QName($name, "zorba-internal-name-for-w3c-collections")
};

(:~
 : Function used for internal purposes only. It returns the namespace
 : component of the given QName.
 :
 : @param $name QName whose namespace component should be returned
 :
 : @return the namespace componentn of the given QName
 :)
declare function ddl:from-qname($name as xs:QName) as xs:string
{
  fn:namespace-uri-from-QName($name)
};

(:~
 : The function returns true if a collection with the given URI is available
 : (i.e. has been created).
 :
 : @param $name The URI of the collection that is being checked.
 :
 : @return true if the collection is available and false otherwise.
 :
 :)
declare function ddl:is-available-collection($coll-name as xs:string) as xs:boolean
{
  qddl:is-available-collection(ddl:to-qname($coll-name))
};

(:~
 : The function returns a sequence of URIs of the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of URIs, one for each available collection, or an emtpy sequence.
 :
 :)
declare function ddl:available-collections() as xs:string* 
{
  for $c in qddl:available-collections()
  where fn:local-name-from-QName($c) eq "zorba-internal-name-for-w3c-collections"
  return ddl:from-qname($c)
};

(:~
 : The create function is an updating function which creates
 : the collection with the given URI and the empty-sequence as contents.
 :
 : @param $name The URI of the collection to create.
 :
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list which, once applied, creates a collection
 :         with the given name.
 :
 : @error zerr:ZDDY0002 if a collection with the given URI already exists.
 :
 :)
declare updating function ddl:create($coll-name as xs:string) 
{
  qddl:create(ddl:to-qname($coll-name))
};

(:~
 : The create function is an updating function which creates
 : the collection with the given URI. Moreover, it adds copies
 : of the sequence $content to the new collection.
 :
 : @param $name The URI of the collection to create.
 : @param $content The sequences of nodes that should be added to the new collection.
 :
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list which, once applied, creates a collection
 :         with the given name and inserts the given nodes into it.
 :
 : @error zerr:ZDDY0002 if a collection with the given URI already exists.
 :
 :)
declare updating function ddl:create(
  $coll-name as xs:string,
  $content as node()*) 
{
  qddl:create(ddl:to-qname($coll-name), $content)
};

(:~
 : The delete function is an updating function that removes
 : the collection with the given URI.
 :
 : @param $name The URI of the collection to delete.
 :
 : @return The result of the function is an empty XDM instance and a pending
 :         update list which, once applied, deletes the collection with the given
 :         name.
 :
 : @error zerr:ZDDY0003 if the URI $name is not equal to any of the available collections.
 : @error zerr:ZDDY0015 if any of the in-scope variables references a node that
 :        belongs to the collection with the given URI.
 :
 :)
declare updating function ddl:delete($coll-name as xs:string)
{
  qddl:delete(ddl:to-qname($coll-name))
};
