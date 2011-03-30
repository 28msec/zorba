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
 : For example, it provides functions to check if a given collection, index, or integrity
 : constraint has been created using any of the create-* functions of the initialization module.
 : Moreover it provides function to insert or remove nodes from a collection, check an
 : integrity contraint, or explicitly probe an index.
 :
 : The variable $content passed to any of the insert functions is evaluated
 : as though it were an enclosed expression in an element constructor.
 : The result of this step is a sequence of nodes to be inserted into the collection.
 :
 : @see <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/html/XQDDF.html"
 :        target="_blank">Zorba Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static-collections/initialization
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

(:~
 : The function returns true if a collection with the given QName is available
 : (i.e. has been created).
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection is available and false otherwise.
 :)
declare function dml:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames of the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of QNames, one for each available collection, or an emtpy sequence.
 :)
declare function dml:available-collections() as xs:QName*  external;

(:~
 : The function returns true if an index with the given QName is available.
 : (i.e. has been created).
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index is available and false otherwise.
 :)
declare function dml:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the indexes that are
 : available. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each available index, or an empty
 : sequence if none are.
 :)
declare function dml:available-indexes() as xs:QName* external;

(:~
 : The function checks if an integrity constraint with the given QName is activated.
 :
 : @param $name The QName of the constraint that is being checked.
 : @return true if the integrity constraint has is activated and false otherwise.
 :)
declare function dml:is-activated-integrity-constraint($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the integrity 
 : constraints that are activated. The sequence will be empty if there are 
 : none.
 :
 : @return A sequence of QNames, one for each activated integrity constraint,
 : or an empty sequence.
 :)
declare function dml:activated-integrity-constraints() as xs:QName*  external;

(:~
 : The insert-nodes function is an updating function that inserts
 : copies of zero or more nodes into a collection. 
 : Note that the insertion position of the nodes in the collection is not defined.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodes($name, $list) update primitive.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is append-only,
 :        const, or queue.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 :)
declare updating function dml:insert-nodes(
  $name as xs:QName,
  $content as node()*) external;

(:~
 : The insert-nodes-first function is an updating function that inserts
 : copies of zero or more nodes at the beginning of a collection. 
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 : @return The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesFirst($name, $list) update primitive.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is append-only,
 :        const, or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 :)
declare updating function dml:insert-nodes-first(
  $name as xs:QName,
  $content as node()*)  external;

(:~
 : The insert-nodes-last function is an updating function that inserts
 : copies of zero or more nodes at the end of a collection. 
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 : @return The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesLast($name, $list) update primitive.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 :)
declare updating function dml:insert-nodes-last(
  $name as xs:QName,
  $content as node()*)  external;

(:~
 : The insert-nodes-before function is an updating function that inserts
 : copies of zero or more nodes into a collection at the position directly preceding the
 : target node.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $target The node in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 : @return The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesAfter($name, $taret, $list) update primitive.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
 :        or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if the $target node is not a node that is
 :        contained in the collection $name.
 :)
declare updating function dml:insert-nodes-before(
  $name as xs:QName,
  $target as node(),
  $content as node()*)  external;

(:~
 : The insert-nodes-after function is an updating function that inserts
 : copies of zero or more nodes into a collection at the position directly following the
 : target node.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $target The node in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesAfter($name, $target, $list) update primitive.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
 :        or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if the $target node is not a node that is contained in the collection $name.
 :)
declare updating function dml:insert-nodes-after(
  $name as xs:QName,
  $target as node(),
  $content as node()*)  external;


(:~
 : This function does the same as the insert-nodes function except
 : it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of nodes that have been
 :         inserted into the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is append-only,
 :        const, or queue.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @see dml:insert-nodes
 :)
declare sequential function dml:apply-insert-nodes(
  $name as xs:QName,
  $content as node()*) as node()*  external;

(:~
 : This function does the same as the insert-nodes-first function except
 : it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of nodes that have been
 :         inserted into the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is append-only,
 :        const, or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @see dml:insert-nodes-first
 :)
declare sequential function dml:apply-insert-nodes-first(
  $name as xs:QName,
  $content as node()*) as node()*  external;

(:~
 : This function does the same as the insert-nodes-last function except
 : it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of nodes that have been
 :         inserted into the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @see dml:insert-nodes-last
 :)
declare sequential function dml:apply-insert-nodes-last(
  $name as xs:QName,
  $content as node()*) as node()*  external;

(:~
 : This function does the same as the insert-nodes-before function except
 : it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $target The node in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of nodes that have been
 :         inserted into the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
 :        or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if the $target node is not a node that is
 :        contained in the collection $name.
 : @see dml:insert-nodes-before
 :)
declare sequential function dml:apply-insert-nodes-before(
  $name as xs:QName,
  $target as node(),
  $content as node()*) as node()*  external;

(:~
 : This function does the same as the insert-nodes-after function except
 : it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $target The node in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of nodes that have been
 :         inserted into the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
 :        or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if the $target node is not a node that is
 :        contained in the collection $name.
 : @see dml:insert-nodes-after
 :)
declare sequential function dml:apply-insert-nodes-after(
  $name as xs:QName,
  $pos as node(),
  $content as node()*) as node()*  external;

(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collection. 
 :
 : @param $name the name of the collection from which the first node should be deleted.
 : @param $target the nodes in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNode($name, $tnode) for 
 :         node in the target sequence.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
          or queue.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if any nodes in the $target sequence is not a member of
 :        the collection identified by the $name parameter.
 :)
declare updating function dml:delete-nodes(
  $name as xs:QName,
  $target as node()*)  external;

(:~
 : The delete-node-first function is an updating function that deletes the
 : first node from an ordered collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNode($name, $tnode) for the
 :         first node in the collection.

 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const or append-only.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDDY0011 if any nodes in the $target sequence is not a member of
 :        the collection identified by the $name parameter.
 :)
declare updating function dml:delete-node-first($name as xs:QName)  external;

(:~
 : The delete-nodes-first function is an updating function that deletes the
 : first n nodes from an ordered collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @param $number The number of nodes that should be removed from the beginning of
 :        the collection.
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNodes($name, $tnode) for 
 :         each of the n nodes (specified by the $number parameter) in the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const or append-only.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDDY0011 If the collection contains less than $number nodes.
 :)
declare updating function dml:delete-nodes-first(
  $name as xs:QName,
  $number as xs:unsignedLong)  external;

(:~
 : The delete-node-last function is an updating function that deletes the
 : last node from an ordered collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNode($name, $tnode) for the
 :         last node in the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0006 if the modifier property of the collection $name is const,
 :        append-only, or queue.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDDY0011 If the collection is empty.
 :)
declare updating function dml:delete-node-last($name as xs:QName)  external;


(:~
 : The delete-nodes-last function is an updating function that deletes the
 : last n nodes from an ordered collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @param $number The number of nodes to delete.
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNodes($name, $tnode) for 
 :         each of the n nodes (specified by the $number parameter) in the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDDY0011 If the collection contains less than $number nodes.
 :
 :)
declare updating function dml:delete-nodes-last(
  $name as xs:QName,
  $number as xs:unsignedLong)  external;

(:~
 : The index-of function is simple function that returns the
 : index of the node $node in the sequence of nodes belonging to
 : the entry with QName $name in the map of available collections.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @param $node The node to retrieve the index from.
 : @return Returns the position as xs:integer of the node $node in the collection.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 : @error XDDY0012 if the order property of the collection $name is unordered.
 : @error XDDY0011 if the collection doesn't contain the node.
 :
 :)
declare function dml:index-of(
  $name as xs:QName,
  $node as node()) as xs:integer  external;

(:~
 : The collection function returns the sequence of nodes contained
 : in the collection identified by the given name.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @return The result of this function is the sequence of nodes belonging
 :         to the entry with QName $name in the map of available collections.
 :
 : @error XDDY0001 if the collection identified by $name is not declared.
 : @error XDDY0003 if the collection identified by $name is not available.
 :)
declare function dml:collection($name as xs:QName) as node()*  external;

(:~
 : The check-integrity-constraint function checks if the constraints
 : specified by the expanded QName $name is valid in the database.
 :
 : @param $name The QName of the integrity constraint to check.
 : @return true if the constraints are valid in the database, false otherwise.
 :
 : @error XDDY0031 if the integrity constraint identified by $name is not declared.
 : @error XDDY0032 if the integrity constraint identified by $name is not available.
 :)
declare function dml:check-integrity-constraint(
  $name as xs:QName) as xs:boolean external;

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a single key tuple. This function 
 : accept a variable number of arguments.
 : 
 :   dml:probe-index-point($indexUri as xs:QName,
 :                        $key1     as xs:anyAtomictType,
 :                        ...,
 :                        $keyM     as xs:anyAtomicType) as node()*
 :
 : The first argument is always a QName identifying an index. The rest of the 
 : arguments specify the search condition, which is given as a number of 
 : atomic items comprising a key tuple. This number must be equal to the number
 : of indexspecs found in the index declaration [err:XDDY0025]. If the index 
 : contains an entry with the given key tuple, the associated domain nodes are
 : returned. Otherwise, the empty sequence is returned.
 :
 : @param $name The QName of the index.
 : @param $key1 The search condition.
 : @return The sequence of domain nodes or an empty sequence.
 : @error If available indexes does not provide a mapping for
 :        the expanded QName $name.
declare function dml:probe-index-point-value(
  $name as xs:QName, 
  $key1 as xs:anyAtomicType*) as node()*  external; 
:)

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a range of key tuples. This function 
 : accept a variable number of arguments.
 :
 : dml:probe-index-range($indexUri                 as xs:QName,
 :                         $rangeLowerBound1         as xs:anyAtomicType?,
 :                         $rangeUpperBound1         as xs:anyAtomicType?,
 :                         $rangeHaveLowerBound1     as xs:boolean,
 :                         $rangeHaveupperBound1     as xs:boolean,
 :                         $rangeLowerBoundIncluded1 as xs:boolean,
 :                         $rangeupperBoundIncluded1 as xs:boolean,
 :                         ....,
 :                         $rangeLowerBoundM         as xs:anyAtomicType?,
 :                         $rangeUpperBoundM         as xs:anyAtomicType?,
 :                         $rangeHaveLowerBoundM     as xs:boolean,
 :                         $rangeHaveupperBoundM     as xs:boolean,
 :                         $rangeLowerBoundIncludedM as xs:boolean,
 :                         $rangeupperBoundIncludedM as xs:boolean) as node()*
 :
 : To describe the semantics of this function, we start by defining the i-th 
 : key column of an index as the set of key items produced by evaluating the 
 : i-th keyspec of the index for every domain node. Then, the search condition 
 : of a range probe can be defined as a number of rangespecs, where a 
 : rangespec describes a constraint on the values of a key column. The first 
 : rangespec applies to the first key column, the second rangespec to the 
 : second key column, etc. The number of rangespecs must be less or equal to 
 : the number of keyspecs found in the declaration of the given index. 
 : Each rangespec consists of 6 values:
 :
 :   * rangeLowerBound : The lower bound in a range of key values.
 :   * rangeUpperBound : The upper bound in a range of key values.
 :   * rangeHaveLowerBound : If false, then there is no lower bound, or 
 :     equivalently, the lower bound is -INFINITY (the actual rangeLowerBound 
 :     value is ignored). Otherwise, the lower bound is the one given by the 
 :     rangeLowerBound value. The effective lower bound of the range is either 
 :     the rangeLowerBound if rangeHaveLowerBound is true, or -INFINITY if 
 :     rangeHaveLowerBound is false.
 :   * rangeHaveUpperBound : If false, then there is no upper bound, or 
 :     equivalently, the upper bound is +INFINITY (the actual rangeUpperBound 
 :     value is ignored). Otherwise, the upper bound is the one given by the 
 :     rangeUpperBound value. The effective upper bound of the range is either
 :     the rangeUpperBound if rangeHaveUpperBound is true, or +INFINITY if 
 :     rangeHaveUpperBound is false.
 :   * rangeLowerBoundIncluded : If false, then the range is open from below,
 :     i.e., the rangeLowerBound value is not considered part of the range. 
 :     Otherwise, the range is closed from below, i.e., the rangeLowerBound 
 :     value is part of the range.
 :   * rangeUpperBoundIncluded : If false, then the range is open from above,
 :     i.e., the rangeUpperBound value is not considered part of the range. 
 :     Otherwise, the range is closed from above, i.e., the rangeUpperBound 
 :     value is part of the range.
 :
 : @param $name The QName of the index.
 : @param $rangeLowerBound1 The lower bound in a range of key values.
 : @param $rangeUpperBound1 The upper bound in a range of key values.
 : @param $rangeHaveLowerBound If false, then there is no lower bound, or 
 :          equivalently, the lower bound is -INFINITY. Otherwise, the lower 
 :          bound is the one given by the rangeLowerBound value. 
 : @param $rangeHaveUpperBound If false, then there is no upper bound, or 
 :          equivalently, the upper bound is +INFINITY. Otherwise, the upper 
 :          bound is the one given by the rangeUpperBound value. 
 : @param $rangeLowerBoundIncluded If false, then the range is open from below, 
 :          i.e., the rangeLowerBound value is not considered part of the 
 :          range. Otherwise, the range is closed from below, i.e., the 
 :          rangeLowerBound value is part of the range. 
 : @param $rangeUpperBoundIncluded If false, then the range is open from above, 
 :          i.e., the rangeUpperBound value is not considered part of the 
 :          range. Otherwise, the range is closed from above, i.e., the 
 :          rangeUpperBound value is part of the range.  
 : @return The sequence of domain nodes.
 : @error If available indexes does not provide a mapping for
 :        the expanded QName $name.
declare function dml:probe-index-range($name as xs:QName, 
  $rangeLowerBound1         as xs:anyAtomicType?,
  $rangeUpperBound1         as xs:anyAtomicType?,
  $rangeHaveLowerBound1     as xs:boolean,
  $rangeHaveupperBound1     as xs:boolean,
  $rangeLowerBoundIncluded1 as xs:boolean,
  $rangeupperBoundIncluded1 as xs:boolean) as node()*  external;
:)

