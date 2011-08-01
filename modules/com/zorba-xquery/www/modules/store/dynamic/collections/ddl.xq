xquery version "1.0";

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
 : Such collections are identified by QNames and come into existence (i.e. be made
 : available) by calling one of the two create-collection functions and be destroyed by
 : the delete-collection function.
 :
 : In contrast to the functions in the module 
 : <tt>http://www.zorba-xquery.com/modules/store/static/collections/ddl</tt>
 : the function in this module operate on collections which do not have to
 : be statically declared in the prolog of a module.
 :
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/dml
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/collections/dynamic
 :
 : @project store/collections/dynamic
 :
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : The function returns true if a collection with the given QName is available
 : (i.e. has been created).
 :
 : @param $name The QName of the collection that is being checked.
 :
 : @return true if the collection is available and false otherwise.
 :
 :)
declare function ddl:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames of the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of QNames, one for each available collection, or an emtpy sequence.
 :
 :)
declare function ddl:available-collections() as xs:QName* external;

(:~
 : The create-collection function is an updating function which creates
 : the collection with the given expanded QName.
 :
 : @param $name The QName of the collection to create.
 :
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list which, once applied, creates a collection
 :         with the given name.
 :
 : @error XDDY0002 if a collection with the given expanded QName already
 :        exists.
 :
 :)
declare updating function ddl:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function which creates
 : the collection with the given expanded QName. Moreover, it adds copies
 : of the sequence $content to the new collection.
 :
 : @param $name The QName of the collection to create.
 : @param $content The sequences of nodes that should be added to the new collection.
 :
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list which, once applied, creates a collection
 :         with the given name and inserts the given nodes into it.
 :
 : @error XDDY0002 if a collection with the given expanded QName already
 :        exists.
 :
 : @see ddl:create-collection
 : @see ddl:insert-nodes-last
 :
 :)
declare updating function ddl:create-collection(
  $name as xs:QName,
  $content as node()*) external;


(:~
 : The delete-collection function is an updating function that removes
 : the collection with the given expanded QName.
 :
 : @param $name The QName of the collection to delete.
 :
 : @return The result of the function is an empty XDM instance and a pending
 :         update list which, once applied, deletes the collection with the given
 :         name.
 :
 : @error XDDY0003 if the collection with the given name does not exist.
 : @error ZDDY0015 if any of the in-scope variables references a node that
 :        belongs to the collection with QName $name.
 :
 :)
declare updating function ddl:delete-collection($coll as xs:QName) external;
