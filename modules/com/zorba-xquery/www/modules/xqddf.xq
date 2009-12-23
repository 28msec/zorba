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
 : @version 1.0 
 :)
module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

(:~
 : The <tt>create-collection</tt> function is an updating function that adds
 : a mapping from the expanded QName <tt>$name</tt> to an empty sequence
 : to the map of available collections.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @error <tt></tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the eq operator) to the name of any resource
 :       in the statically known collections.
 : @error <tt></tt> if available collections already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that consists the <tt>upd:createCollection($name)</tt>
 :         primitive.
 :)
declare updating function xqddf:create-collection($name as xs:QName) external;

(:~
 : The <tt>create-collection</tt> function is an updating function that adds a new
 : mapping from the expanded QName <tt>$name</tt> to the map of available
 : collections.
 : Moreover, it adds copies (see below) of the sequence <tt>$content</tt> to
 : this collection.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @param $content The sequences of nodes that should be added to the new
          collection.
 : @error <tt></tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known collections.
 : @error <tt></tt> if available collections already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If $content does not match the expected type according
 :        to the rules for SequenceType Matching.
 : @return The variable <tt>$content</tt> is evaluated as though it were an
 :         enclosed expression in an element constructor (see Rule 1e in
 :         Section 3.7.1.3 ContentXQ of the
 :         <a href="http://www.w3.org/TR/xquery/#id-content">XQuery Update Facility 1.0</a>
 :         specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the
 :         insertion sequence. The result of the function is an empty
 :         XDM instance and a pending update list that consists of the
 :         following update primitives:
 :         <ul>
 :           <li><tt>upd:createCollection($name)</tt></li>
 :           <li><tt>upd:insertNodesFirst($name, $list)</tt></li>
 :         </ul>
 :)
declare updating function xqddf:create-collection($name as xs:QName,
                                                $content as node()*) external;

(:~
 : The <tt>delete-collection</tt> function is an updating function that removes a
 : resource from the map of available collections. The QName <tt>$name</tt>
 : is the name of the resource.
 :
 : @param $name The QName of the collection to remove from the map of available
 :        collections.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If If any of the in-scope variables references a node that
 :        belongs to the collection with QName <tt>$name</tt>.
 : @error <tt></tt> If the domain or key expression of any of the available
 :        indexes access the collection with name <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:deleteCollection($name)</tt>
 :         update primitive.
 :)
declare updating function xqddf:delete-collection($name as xs:QName) external;

(:~
 : The <tt>insert-nodes</tt> function is an updating function that inserts
 : copies (see below) of zero or more nodes into a collection. 
 : Note that the insertion position of the nodes in the collection is not
 : defined.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the
 :        collection.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>append-only</tt>, <tt>const</tt>, or <tt>queue</tt>.
 : @error <tt></tt> If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable <tt>$content</tt> is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the <tt>upd:insertNodes($name, $list)</tt>
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes($name as xs:QName,
                                             $content as node()*) external;

(:~
 : The <tt>insert-nodes-first</tt> function is an updating function that inserts
 : copies (see below) of zero or more nodes as first nodes into a collection. 
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the
 :        collection.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>append-only</tt>, <tt>const</tt>, or <tt>queue</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable <tt>$content</tt> is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the <tt>upd:insertNodesFirst($name, $list)</tt>
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-first($name as xs:QName,
                                                 $content as node()*) external;

(:~
 : The <tt>insert-nodes-last</tt> function is an updating function that inserts copies
 : (see below) of zero or more nodes as last nodes into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>const</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @return The variable <tt>$content</tt> is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the <tt>upd:insertNodesLast($name, $list)</tt>
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-last($name as xs:QName,
                                                $content as node()*) external;

(:~
 : The <tt>insert-nodes-before</tt> function is an updating function that inserts
 : copies of zero or more nodes as preceding siblings of <tt>$target</tt>
 : into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$target</tt> The node in the collection before which the <tt>$content</tt>
 :        sequence should be inserted.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>const</tt>, <tt>append-only</tt>, or <tt>queue</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error <tt></tt> If the <tt>$target</tt> node is not a node that is
 :        contained in the collection <tt>$name</tt>.
 : @return The variable <tt>$content</tt> is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the <tt>upd:insertNodesBefore($name, $target, $list)</tt>
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-before($name as xs:QName,
                                                    $target as node(),
                                                    $content as node()*) external;

(:~
 : The <tt>insert-nodes-after</tt> function is an updating function that inserts
 : copies of zero or more nodes as following siblings of <tt>$target</tt>
 : into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$target</tt> The node in the collection after which the <tt>$content</tt>
 :        sequence should be inserted.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error <tt></tt> If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error <tt></tt> If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>const</tt>, <tt>append-only</tt>, or <tt>queue</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If the <tt>$target</tt> node is not a node that is
 :        contained in the collection <tt>$name</tt>.
 : @return The variable <tt>$content</tt> is evaluated as though it were
 :         an enclosed expression in an element constructor
 :         (see Rule 1e in Section 3.7.1.3 ContentXQ of the
 :         XQuery Update Facility 1.0 specification).
 :         The result of this step is a sequence of nodes to be inserted,
 :         called the insertion sequence. Let <tt>$list</tt> be the insertion sequence.
 :         The result of the function is an empty XDM instance and a pending update list
 :         that contains the <tt>upd:insertNodesAfter($name, $target, $list)</tt>
 :         update primitive.
 :)
declare updating function xqddf:insert-nodes-after($name as xs:QName,
                                                  $pos as node(),
                                                  $content as node()*) external;

(:~
 : The <tt>delete-nodes</tt> function is an updating function that deletes zero of more
 : nodes from a collections. The keywords node and nodes may be used
 : interchangeably, regardless of how many nodes are actually deleted.
 :
 : @param <tt>$name</tt> The name of the collection from which the nodes
 :        should be deleted.
 : @param <tt>$target</tt> The nodes in the collection that should be deleted.
 : @error <tt></tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the statically known
 :        collection identified by QName <tt>$name</tt> is <tt>const</tt>,
 :        <tt>queue</tt>, or <tt>append-only</tt>.
 : @error <tt></tt> If any node of the <tt>$target</tt> sequence is not a member of
 :        the sequence that is mapped from the expanded QName <tt>$name</tt>.
 : @return  For each node <tt>$tnode</tt> in the target sequence <tt>$target</tt>,
 :          the following update primitive is appended to the pending update list:
 :          <ul>
 :            <li><tt>upd:deleteNode($name\$, $tnode)</tt></li>
 :          </ul>
 :          The resulting pending update list (together with an empty XDM instance)
 :          is the result of the delete-nodes function.
 :)
declare updating function xqddf:delete-nodes($name as xs:QName,
                                           $target as node()*) external;

(:~
 : The <tt>delete-node-first</tt> function is an updating function that deletes the
 : first node from an ordered collection.
 :
 : @param <tt>$name</tt> The name of the collection from which the first node
 :        should be deleted.
 : @error <tt>XDDY0009</tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>const</tt> or <tt>append-only</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If the sequences mapped by the expanded QName
 :        <tt>$name</tt> doesn't contain any nodes.
 : @return Let <tt>$tnode</tt> be the first node of the sequence in the map
 :         of available collections identified by QName <tt>$name</tt>.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the <tt>upd:deleteNode($name, $tnode)</tt>
 :         update primitive.
 :)
declare updating function xqddf:delete-node-first($name as xs:QName) external;

(:~
 : The <tt>delete-node-last</tt> function is an updating function that deletes the
 : last node from an ordered collection.
 :
 : @param <tt>$name</tt> The name of the collection from which the last node
 :        should be deleted.
 : @error <tt></tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If the modifier property of the collection <tt>$name</tt>
 :        is <tt>const</tt>, <tt>append-only</tt>, or <tt>queue</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt>XDDY0014</tt> If the sequences mapped by the expanded QName
 :        <tt>$name</tt> doesn't contain any nodes.
 : @return Let <tt>$tnode</tt> be the last node of the sequence in the map
 :         of available collections identified by QName <tt>$name</tt>.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the <tt>upd:deleteNode($name, $tnode)</tt>
 :         update primitive.
 :)
declare updating function xqddf:delete-node-last($name as xs:QName) external;

(:~
 : The <tt>index-of</tt> function is simple function that returns the
 : index of the node <tt>$node</tt> in the sequence of nodes belonging to
 : the entry with QName $name in the map of available collections.
 :
 : @param <tt>$name</tt> The name of the collection
 : @param <tt>node</tt> The node to retrieve the index from.
 : @error <tt></tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt></tt> If the order property of the collection <tt>$name</tt>
 :        is <tt>unordered</tt>.
 : @error <tt></tt> If the node <tt>$node</tt> is not contained in the collection.
 : @return The result of this function is the position as xs:integer of
 :         the node <tt>$node</tt> in the sequence belonging to the entry
 :         with QName $name in the map of available collections.
 :)
declare function xqddf:index-of($name as xs:QName, $node as node()) as xs:integer external;

(:~
 : The <tt>collection</tt> function is simple function that returns the
 : the sequence of nodes belonging to the entry with QName <tt>$name</tt>
 : in the map of available collections.
 :
 : @param <tt>$name</tt> The name of the collection
 : @error <tt></tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @return The result of this function is the sequence of nodes
 :         belonging to the entry with QName <tt>$name</tt> in the map
 :         of available collections.
 :)
declare function xqddf:collection($name as xs:QName) as node()* external;

(:~
 : The <tt>create-index</tt> function is an updating function that adds a
 : mapping from the expanded QName <tt>$name</tt> to a map of index entries
 : to the map of available indexes.
 :
 : @param $name The QName of the index to add to the map of available
 :        indexes.
 : @error <tt></tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known indexes.
 : @error <tt></tt> if available indexes already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:createIndex($name)</tt>
 :         update primitive.
 :)
declare updating function xqddf:create-index($name as xs:QName) external;

(:~
 : The <tt>delete-index</tt> function is an updating function that removes a resource
 : from the map of available indexes. The QName <tt>$name</tt> is the name
 : of the resource.
 :
 : @param $name The QName of the index to delete from the map of available
 :        indexes.
 : @error XDDY0009 If available indexes does not provide a mapping for
 :        the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:deleteIndex($name)</tt>
 :         update primitive.
 :)
declare updating function xqddf:delete-index($name as xs:QName) external;

(:~
 : The <tt>refresh-index</tt> function is an updating function that populates
 : the map of index entries indentified by the expanded QName <tt>$name</tt>
 : in the map of available indexes.
 : Note that if the maintenance property of the index in question is automatic,
 : this function is a NOP.
 :
 : @param $name The QName of the index to refresh.
 : @error <tt></tt> If available indexes does not provide a mapping for
 :       the expanded QName <tt>$name</tt>.
 :)
declare updating function xqddf:refresh-index($name as xs:QName) external;
