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
 : updatable collections which are declared in the prolog (context) of a module.
 : For example, it provides functions to create, delete, or introspect collections.
 :
 : Such collections are identified by QNames and come into existence (i.e. be available)
 : by calling one of the two create-collection functions and be destroyed by
 : the delete-collection function.
 :
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/collections/static
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

(:~
 : The function returns true if a collection with the given QName is available
 : (i.e. has been created).
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection is available and false otherwise.
 :)
declare function ddl:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames of the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of QNames, one for each available collection, or an emtpy sequence.
 :)
declare function ddl:available-collections() as xs:QName*  external;


(:~
 : The create-collection function is an updating function that adds
 : a mapping from the expanded QName $name to an empty sequence
 : to the map of available collections.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that consists the upd:createCollection($name)
 :         primitive.
 :
 : @error XDDY0001 if the expanded QName of $name is not equal
 :        (as defined by the eq operator) to the name of any resource
 :        in the statically known collections.
 : @error XDDY0002 if available collections already provides a mapping
 :        for the expaned QName $name.
 :)
declare updating function ddl:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function that adds a new
 : mapping from the expanded QName $name to the map of available collections.
 : Moreover, it adds copies (see below) of the sequence $content to this collection.
 : The copies are computed by evaluating the variable $content as though it were an
 : enclosed expression in an element constructor.
 :
 : @param $name The QName of the collection to add to the map of available collections.
 : @param $content The sequences of nodes that should be added to the new collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update
 :         list that consists of the following update primitives:
 :         <ul>
 :           <li>upd:createCollection($name)</li>
 :           <li>upd:insertNodesFirst($name, $list)</li>
 :         </ul>
 :        where $list is the sequence of nodes which are copies of $content.
 :
 : @error XDDY0001 if the expanded QName of $name is not equal
 :        (as defined by the eq operator) to the name of any resource
 :        in the statically known collections.
 : @error XDDY0002 if available collections already provides a mapping
 :        for the expaned QName $name.
 : @error XDTY0001 If $content does not match the expected type according
 :        to the rules for SequenceType Matching.
 :)
declare updating function ddl:create-collection(
  $name as xs:QName,
  $content as node()*)  external;

(:~
 : The delete-collection function is an updating function that removes a
 : resource from the map of available collections. The QName $name
 : is the name of the collection.
 :
 : @param $name The QName of the collection to remove from the map of available
 :        collections.
 : @error If available collections does not provide a mapping for
 :        the expaned QName $name.
 : @error If If any of the in-scope variables references a node that
 :        belongs to the collection with QName $name.
 : @error If the domain or key expression of any of the available
 :        indexes access the collection with name $name.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:deleteCollection($name)
 :         update primitive.
 :)
declare updating function ddl:delete-collection(
  $name as xs:QName)  external;

(:~
 : The function returns true if a collection with the given QName has been declared.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection has been created and false otherwise.
 :)
declare function ddl:is-declared-collection(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns a sequence of QNames representing the collections that have
 : been previously declared. The sequence will be empty if there are no collections declared.
 :
 : @return A sequence of QNames, one for each created collection, or an emtpy sequence.
 :)
declare function ddl:declared-collections() as xs:QName*  external;
