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
 : Such collections are identified by QNames and come into existence (i.e. be available)
 : by calling one of the two create-collection functions and be destroyed by
 : the delete-collection function.
 :
 : In contrast to the functions in the module 
 : <tt>http://www.zorba-xquery.com/modules/store/static/collections/ddl</tt>
 : the function in this module operate on collections which do not have to
 : be statically declared in the prolog of a module.
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

(:~
 : The function returns true if a collection with the given QName is available,
 : i.e. has been created using any of the two create-collection functions of
 : this module.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection is available and false otherwise.
 :)
declare function ddl:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the collections that are
 : available.
 :
 : @return A sequence of QNames, one for each available collection. Any empty
 :         sequence is returned if no collections are available.
 :)
declare function ddl:available-collections() as xs:QName* external;

(:~
 : The create-collection function is an updating function that adds
 : a mapping from the expanded QName $name to an empty sequence
 : to the map of available collections.
 :
 : Once the resulting pending update is applied, ddl:is-available-collection
 : will return true when invoked with $name as a parameter.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that contains the upd:createCollection($name)
 :         primitive.
 :
 : @error XDDY0002 if available collections already contains a collection with the
 :        given name.
 :)
declare updating function ddl:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function that adds
 : a mapping from the expanded QName $name to an empty sequence
 : to the map of available collections.
 : 
 : Also, the functions adds copies of the nodes given by the sequence $arg to the
 : collection.
 : 
 : Once the resulting pending update is applied, ddl:is-available-collection
 : will return true when invoked with $name as a parameter.
 : Moreover, calling the function ddl:collection will return the nodes
 : that have been added to the collection
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @param $content The sequences of nodes whose copies should be added to the new collection.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that contains an upd:createCollection($name)
 :         primitive and an upd:insertNodesFirst($name, $list) update primitive.
 :
 : @error XDDY0002 if available collections already contains a collection with the
 :        given name.
 :
 : @see ddl:create-collection
 : @see ddl:insert-nodes-last
 :)
declare updating function ddl:create-collection(
  $name as xs:QName,
  $content as node()*) external;


(:~
 : The delete-collection function is an updating function that removes
 : the collection with the given name.
 :
 : Once the resulting pending update is applied, ddl:is-available-collection
 : will return false when invoked with $name as a parameter.
 :
 : @param $name The QName of the collection to delete.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:deleteCollection($name)
 :         update primitive.
 :
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0015 when applied any node contained in the collection to be deleted
 :        is still referenced by any variable.
 :
 :)
declare updating function ddl:delete-collection($name as xs:QName) external;
