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
 : DDL Module defined in the XQuery Data Definition Facility
 :
 : @author Nicolae Brinza
 : @see <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/html/XQDDF.html" target="_blank">The Zorba 1.0 Data Definition Facility</a>
 :
 :)
module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

(:~
 : The create-collection function is an updating function that adds
 : a mapping from the expanded QName $name to an empty sequence
 : to the map of available collections.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @error if the expanded QName of $name is not equal
 :       (as defined by the eq operator) to the name of any resource
 :       in the statically known collections.
 : @error if available collections already provides a mapping
 :        for the expaned QName $name.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that consists the upd:createCollection($name)
 :         primitive.
 :)
declare updating function xqddf:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function that adds a new
 : mapping from the expanded QName $name to the map of available
 : collections.
 : Moreover, it adds copies (see below) of the sequence $content to
 : this collection.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @param $content The sequences of nodes that should be added to the new
          collection.
 : @error if the expanded QName of $name is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known collections.
 : @error if available collections already provides a mapping
 :        for the expaned QName $name.
 : @error If $content does not match the expected type according
 :        to the rules for SequenceType Matching.
 : @return The variable $content is evaluated as though it were an
 :         enclosed expression in an element constructor (see Rule 1e in
 :         Section 3.7.1.3 ContentXQ of the
 :         <a href="http://www.w3.org/TR/xquery/#id-content">XQuery Update Facility 1.0</a>
 :         specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the
 :         insertion sequence. The result of the function is an empty
 :         XDM instance and a pending update list that consists of the
 :         following update primitives:
 :         <ul>
 :           <li>upd:createCollection($name)</li>
 :           <li>upd:insertNodesFirst($name, $list)</li>
 :         </ul>
 :)
declare updating function xqddf:create-collection($name as xs:QName,
                                                $content as node()*) external;

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
declare updating function xqddf:delete-collection($name as xs:QName) external;

(:~
 : The insert-nodes function is an updating function that inserts
 : copies (see below) of zero or more nodes into a collection. 
 : Note that the insertion position of the nodes in the collection is not
 : defined.
 :
 : @param $name The name of the collection to which the nodes should
 :        be added.
 : @param $content The sequences of nodes that should be added to the
 :        collection.
 : @error If available collections does not provide a mapping for
 :        the expanded QName $name.
 : @error If the modifier property of the collection $name
 :        is append-only, const, or queue.
 : @error If $content does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable $content is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodes($name, $list)
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes($name as xs:QName,
                                             $content as node()*) external;

(:~
 : The insert-nodes-first function is an updating function that inserts
 : copies (see below) of zero or more nodes as first nodes into a collection. 
 :
 : @param $name The name of the collection to which the nodes should
 :        be added.
 : @param $content The sequences of nodes that should be added to the
 :        collection.
 : @error If available collections does not provide a mapping for
 :        the expanded QName $name.
 : @error If the modifier property of the collection $name
 :        is append-only, const, or queue.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If $content does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable $content is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesFirst($name, $list)
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-first($name as xs:QName,
                                                 $content as node()*) external;

(:~
 : The insert-nodes-last function is an updating function that inserts copies
 : (see below) of zero or more nodes as last nodes into a collection.
 :
 : @param $name The name of the collection to which the nodes should
 :        be added.
 : @param $content The sequences of nodes that should be added to the new
 :        collection.
 : @error If available collections does not provide a mapping for
 :        the expanded QName $name.
 : @error If the modifier property of the collection $name
 :        is const.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If $content does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable $content is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesLast($name, $list)
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-last($name as xs:QName,
                                                $content as node()*) external;

(:~
 : The insert-nodes-before function is an updating function that inserts
 : copies of zero or more nodes as preceding siblings of $target
 : into a collection.
 :
 : @param $name The name of the collection to which the nodes should
 :        be added.
 : @param $target The node in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes that should be added to the new
 :        collection.
 : @error If available collections does not provide a mapping for
 :        the expanded QName $name.
 : @error If the modifier property of the collection $name
 :        is const, append-only, or queue.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If $content does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error If the $target node is not a node that is
 :        contained in the collection $name.
 : @return The variable $content is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesBefore($name, $target, $list)
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-before($name as xs:QName,
                                                    $target as node(),
                                                    $content as node()*) external;

(:~
 : The insert-nodes-after function is an updating function that inserts
 : copies of zero or more nodes as following siblings of $target
 : into a collection.
 :
 : @param $name The name of the collection to which the nodes should
 :        be added.
 : @param $target The node in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes that should be added to the new
 :        collection.
 : @error If available collections does not provide a mapping for
 :        the expanded QName $name.
 : @error If $content does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error If the modifier property of the collection $name
 :        is const, append-only, or queue.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If the $target node is not a node that is
 :        contained in the collection $name.
 : @return The variable $content is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let $list be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the upd:insertNodesAfter($name, $target, $list)
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-after($name as xs:QName,
                                                  $pos as node(),
                                                  $content as node()*) external;

(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collection. 
 :
 : @param $name The name of the collection from which the nodes
 :        should be deleted.
 : @param $target The nodes in the collection that should be deleted.
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the modifier property of the statically known
 :        collection identified by QName $name is const,
 :        queue, or append-only.
 : @error If any node of the $target sequence is not a member of
 :        the sequence that is mapped from the expanded QName $name.
 : @return  For each node $tnode in the target sequence $target,
 :          the following update primitive is appended to the pending update list:
 :          <ul>
 :            <li>upd:deleteNode($name\$, $tnode)</li>
 :          </ul>
 :          The resulting pending update list (together with an empty XDM instance)
 :          is the result of the delete-nodes function.
 :)
declare updating function xqddf:delete-nodes($name as xs:QName,
                                             $target as node()*) external;

(:~
 : The delete-node-first function is an updating function that deletes the
 : first node from an ordered collection.
 :
 : @param $name The name of the collection from which the first node
 :        should be deleted.
 : @error XDDY0009 If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the modifier property of the collection $name
 :        is const or append-only.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If the sequences mapped by the expanded QName
 :        $name doesn't contain any nodes.
 : @return Let $tnode be the first node of the sequence in the map
 :         of available collections identified by QName $name.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the upd:deleteNode($name, $tnode)
 :         update primitive.
 :)
declare updating function xqddf:delete-node-first($name as xs:QName) external;

(:~
 : The delete-nodes-first function is an updating function that deletes the
 : first N nodes from an ordered collection, where N is a given number.
 :
 : @param $name The name of the collection from which the last nodes
 :        should be deleted.
 : @param $number The number of nodes to delete.
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the modifier property of the collection $name
 :        is const or append-only.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error XDDY0014 If the collection contains less than $number nodes.
 : @return Let $tnodes be the sequence consisting of the first $number
 :         nodes in the collection. The result of this function is an empty XDM
 :         instance and a pending update list containing the
 :         upd:deleteNodes($name, $tnodes) update primitive.
 :)
declare updating function xqddf:delete-nodes-first($name as xs:QName,
                                                   $number as xs:unsignedLong) external;

(:~
 : The delete-node-last function is an updating function that deletes the
 : last node from an ordered collection.
 :
 : @param $name The name of the collection from which the last node
 :        should be deleted.
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the modifier property of the collection $name
 :        is const, append-only, or queue.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error XDDY0014 If the sequences mapped by the expanded QName
 :        $name doesn't contain any nodes.
 : @return Let $tnode be the last node of the sequence in the map
 :         of available collections identified by QName $name.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the upd:deleteNode($name, $tnode)
 :         update primitive.
 :)
declare updating function xqddf:delete-node-last($name as xs:QName) external;


(:~
 : The delete-nodes-last function is an updating function that deletes the
 : last N nodes from an ordered collection, where N is a given number.
 :
 : @param $name The name of the collection from which the last nodes
 :        should be deleted.
 : @param $number The number of nodes to delete.
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the modifier property of the collection $name
 :        is const, append-only, or queue.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error XDDY0014 If the collection contains less than $number nodes.
 : @return Let $tnodes be the sequence consisting of the last $number
 :         nodes in the collection. The result of this function is an empty XDM
 :         instance and a pending update list containing the
 :         upd:deleteNodes($name, $tnode) update primitive.
 :)
declare updating function xqddf:delete-nodes-last($name as xs:QName,
                                                  $number as xs:unsignedLong) external;

(:~
 : The index-of function is simple function that returns the
 : index of the node $node in the sequence of nodes belonging to
 : the entry with QName $name in the map of available collections.
 :
 : @param $name The name of the collection
 : @param node The node to retrieve the index from.
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @error If the order property of the collection $name
 :        is unordered.
 : @error If the node $node is not contained in the collection.
 : @return The result of this function is the position as xs:integer of
 :         the node $node in the sequence belonging to the entry
 :         with QName $name in the map of available collections.
 :)
declare function xqddf:index-of($name as xs:QName, $node as node()) as xs:integer external;

(:~
 : The collection function is simple function that returns the
 : the sequence of nodes belonging to the entry with QName $name
 : in the map of available collections.
 :
 : @param $name The name of the collection
 : @error If available collections does not provide a mapping
 :        for the expaned QName $name.
 : @return The result of this function is the sequence of nodes
 :         belonging to the entry with QName $name in the map
 :         of available collections.
 :)
declare function xqddf:collection($name as xs:QName) as node()* external;

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
declare updating function xqddf:create-index($name as xs:QName) external;

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
declare updating function xqddf:delete-index($name as xs:QName) external;

(:~
 : The refresh-index function is an updating function that populates
 : the map of index entries indentified by the expanded QName $name
 : in the map of available indexes.
 : Note that if the maintenance property of the index in question is automatic,
 : this function is a NOP.
 :
 : @param $name The QName of the index to refresh.
 : @return The result of the function is an empty XDM instance and a
 :         pending update list that consists of a
 :         upd:refresHindex($name) update primitive.
 : @error If available indexes does not provide a mapping for
 :        the expanded QName $name.
 :)
declare updating function xqddf:refresh-index($name as xs:QName) external;

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
declare updating function xqddf:activate-integrity-constraint(
  $name as xs:QName) external;

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
declare updating function xqddf:deactivate-integrity-constraint(
  $name as xs:QName) external;

(:~
 : The check-integrity-constraint function checks if the constraints
 : specified by the integrity constraints (indentified by the expanded QName
 : $name) are valid in the database.
 :
 : @param $name The QName of the integrity constraint to check.
 : @return true if the constraints are valid in the database, false otherwise.
 : @error If available integrity constraints in the static context
 :        does not provide a mapping for the expanded QName $name.
 :)
declare function xqddf:check-integrity-constraint(
  $name as xs:QName) as xs:boolean external;

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a single key tuple. This function 
 : accept a variable number of arguments.
 : 
 :   xqddf:probe-index-point($indexUri as xs:QName,
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
 :)
(: declare function xqddf:probe-index-point-value($name as xs:QName, 
  $key1 as xs:anyAtomicType*) as node()* external; :)

(:~
 : The probe function retrieves the domain nodes associated with a particular
 : search condition, which is presented as a range of key tuples. This function 
 : accept a variable number of arguments.
 :
 : xqddf:probe-index-range($indexUri                 as xs:QName,
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
 :)
(: declare function xqddf:probe-index-range($name as xs:QName, 
  $rangeLowerBound1         as xs:anyAtomicType?,
  $rangeUpperBound1         as xs:anyAtomicType?,
  $rangeHaveLowerBound1     as xs:boolean,
  $rangeHaveupperBound1     as xs:boolean,
  $rangeLowerBoundIncluded1 as xs:boolean,
  $rangeupperBoundIncluded1 as xs:boolean) as node()* external; :)

