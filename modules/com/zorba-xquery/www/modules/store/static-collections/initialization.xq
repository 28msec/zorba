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
 : This module defines a set of functions to deal with XQueries's Data Definition Facility
 : in Zorba (XQDDF).
 : For example, it provides functions to create, delete, or introspect statically declard
 : collections, indexes, and integrity contraints, respectively.
 :
 : @see <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/html/XQDDF.html" target="_blank">Zorba Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static-collections/manipulation
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 :)
module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";

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
declare updating function init:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function that adds a new
 : mapping from the expanded QName $name to the map of available collections.
 : Moreover, it adds copies (see below) of the sequence $content to this collection.
 : The copies are computed by evaluating the variable $content as though it were an
 : enclosed expression in an element constructor.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @param $content The sequences of nodes that should be added to the new
 :        collection.
 :
 : @return The result of the function is an empty XDM instance and
 :         a pending update list that consists of the
 :         following update primitives:
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
declare updating function init:create-collection(
  $name as xs:QName,
  $content as node()*)  external;

(:~
 : The delete-collection function is an updating function that removes a
 : resource from the map of available collections. The QName $name
 : is the name of the resource.
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
declare updating function init:delete-collection(
  $name as xs:QName)  external;

(:~
 : The create-index function is an updating function that adds a
 : mapping from the expanded QName $name to a map of index entries
 : to the map of available indexes.
 :
 : @param $name The QName of the index to add to the map of available
 :        indexes.
 : @error if the expanded QName of $name is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known indexes.
 : @error if available indexes already provides a mapping
 :        for the expaned QName $name.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:createIndex($name)
 :         update primitive.
 :)
declare updating function init:create-index(
  $name as xs:QName)  external;

(:~
 : The delete-index function is an updating function that removes a resource
 : from the map of available indexes. The QName $name is the name
 : of the resource.
 :
 : @param $name The QName of the index to delete from the map of available
 :        indexes.
 : @error XDDY0009 If available indexes does not provide a mapping for
 :        the expaned QName $name.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:deleteIndex($name)
 :         update primitive.
 :)
declare updating function init:delete-index(
  $name as xs:QName)  external;

(:~
 : The activate-integrity-constraint function is an updating function
 : that activates the integrity constraint indentified by the expanded QName
 : $name in the dynamic context.
 :
 : @param $name The QName of the integrity constraint to activate.
 : @return The result of the function is an empty XDM instance and a
 :         pending update list that consists of a
 :         upd:activateIntegrityConstraint($name) update primitive.
 : @error If available integrity constraints in the static context
 :        does not provide a mapping for the expanded QName $name.
 :)
declare updating function init:activate-integrity-constraint(
  $name as xs:QName)  external;

(:~
 : The deactivate-integrity-constraint function is an updating function
 : that deactivates the integrity constraint indentified by the expanded QName
 : $name in the dynamic context.
 :
 : @param $name The QName of the integrity constraint to deactivate.
 : @return The result of the function is an empty XDM instance and a
 :         pending update list that consists of a
 :         upd:deActivateIntegrityConstraint($name) update primitive.
 : @error If available integrity constraints in the static context
 :        does not provide a mapping for the expanded QName $name.
 :)
declare updating function init:deactivate-integrity-constraint(
  $name as xs:QName)  external;

(:~
 : The function returns true if an index with the given QName has been declared.
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index has been declared and false otherwise.
 :)
declare function init:is-declared-index(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns a sequence of QNames representing the indexes that have
 : been previously created. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each created index, or an empty
 : sequence if none exist.
 :)
declare function init:declared-indexes() as xs:QName*  external;

(:~
 : The function returns a sequence of QNames representing the integrity
 : constraints that have been declared, as described by the Zorba Data
 : Definition Language extension. The sequence will be empty if there are no
 : integrity constraints.
 :
 : @return A sequence of QNames, one for each declared integrity constraint,
 : or an empty sequence if none are declared.
 :)
declare function init:declared-integrity-constraints() as xs:QName*  external;

(:~
 : The function checks if an integrity constraint with the given QName has
 : been declared.
 :
 : @param $name The QName of the constraint that is being checked.
 : @return true if the integrity constraint has been declared and false
 : otherwise.
 :)
declare function init:is-declared-integrity-constraint(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns true if a collection with the given QName has been declared.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection has been created and false otherwise.
 :)
declare function init:is-declared-collection(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns a sequence of QNames representing the collections that have
 : been previously declared. The sequence will be empty if there are no collections declared.
 :
 : @return A sequence of QNames, one for each created collection, or an emtpy sequence.
 :)
declare function init:declared-collections() as xs:QName*  external;


