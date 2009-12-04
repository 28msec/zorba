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
module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare variable $ddl:XDDY0014 as xs:QName := xs:QName("err:XDDY0014");

(:~
 : The create-collection function is an updating function that adds
 : a mapping from the expanded QName <tt>$name</tt> to an empty sequence
 : to the map of available collections.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @error <tt>XDST0010</tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the eq operator) to the name of any resource
 :       in the statically known collections.
 : @error <tt>XDDY0012</tt> if available collections already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a 
 :         pending update list that consists the <tt>upd:createCollection($name)</tt>
 :         primitive.
 :)
declare updating function ddl:create-collection($name as xs:QName) external;

(:~
 : The create-collection function is an updating function that adds a new
 : mapping from the expanded QName <tt>$name</tt> to the map of available
 : collections.
 : Moreover, it adds copies (see below) of the sequence <tt>$content</tt> to
 : this collection.
 :
 : @param $name The QName of the collection to add to the map of available
 :        collections.
 : @param $content The sequences of nodes that should be added to the new
          collection.
 : @error <tt>XDST0010</tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known collections.
 : @error <tt>XDDY0012</tt> if available collections already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt>XPTY0004</tt> If $content does not match the expected type according
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
declare updating function ddl:create-collection($name as xs:QName,
                                                $content as node()*) external;

(:~
 : The delete-collection function is an updating function that removes a
 : resource from the map of available collections. The QName <tt>$name</tt>
 : is the name of the resource.
 :
 : @param $name The QName of the collection to remove from the map of available
 :        collections.
 : @error XDST0010 If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in the
 :        statically known collections.
 : @error XDDY0009 If available collections does not provide a mapping for
 :        the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:deleteCollection($name)</tt>
 :         update primitive.
 :)
declare updating function ddl:delete-collection($name as xs:QName) external;

(:~
 : The insert-nodes-first function is an updating function that inserts
 : copies (see below) of zero or more nodes as first nodes into a collection. 
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error XDST0010 If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in
 :        the statically known collections.
 : @error XDDY0009 If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error XPTY0004 If <tt>$content</tt> does not match the expected type
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
declare updating function ddl:insert-nodes-first($name as xs:QName,
                                                 $content as node()*) external;

(:~
 : The insert-nodes-last function is an updating function that inserts copies
 : (see below) of zero or more nodes as last nodes into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error XDST0010 If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in
 :        the statically known collections.
 : @error XDDY0009 If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error XPTY0004 If <tt>$content</tt> does not match the expected type
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
declare updating function ddl:insert-nodes-last($name as xs:QName,
                                                $content as node()*) external;

(:~
 : The insert-nodes-before function is an updating function that inserts
 : copies of zero or more nodes as preceding siblings of <tt>$target</tt>
 : into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$target</tt> The node in the collection before which the <tt>$content</tt>
 :        sequence should be inserted.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error XDST0010 If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in
 :        the statically known collections.
 : @error XDDY0009 If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error XPTY0004 If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error XDDY0011 If the result is not a node that is contained in the sequence
 :        identified by <tt>$name</tt> in the available collections. 
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
declare updating function ddl:insert-nodes-before($name as xs:QName,
                                                  $target as node(),
                                                  $content as node()*) external;

(:~
 : The insert-nodes-after function is an updating function that inserts
 : copies of zero or more nodes as following siblings of <tt>$target</tt>
 : into a collection.
 :
 : @param <tt>$name</tt> The name of the collection to which the nodes should
 :        be added.
 : @param <tt>$target</tt> The node in the collection after which the <tt>$content</tt>
 :        sequence should be inserted.
 : @param <tt>$content</tt> The sequences of nodes that should be added to the new
 :        collection.
 : @error XDST0010 If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in
 :        the statically known collections.
 : @error XDDY0009 If available collections does not provide a mapping for
 :        the expanded QName <tt>$name</tt>.
 : @error XPTY0004 If <tt>$content</tt> does not match the expected type
 :        according to the rules for SequenceType Matching.
 : @error XDDY0011 If the result is not a node that is contained in the sequence
 :        identified by <tt>$name</tt> in the available collections. 
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
declare updating function ddl:insert-nodes-after($name as xs:QName,
                                                  $pos as node(),
                                                  $content as node()*) external;

(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collections. The keywords node and nodes may be used
 : interchangeably, regardless of how many nodes are actually deleted.
 :
 : @param <tt>$name</tt> The name of the collection from which the nodes
 :        should be deleted.
 : @param <tt>$target</tt> The nodes in the collection that should be deleted.
 : @error <tt>XDST0010</tt> If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource in the
 :        statically known collections.
 : @error <tt>XDST0011</tt> If the modifier property of the statically known
 :        collection identified by QName <tt>$name</tt> is <tt>const</tt>,
 :        <tt>queue</tt>, or <tt>append-only</tt>.
 : @error <tt>XDDY0009</tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt>XDDY0011</tt> If any node from resulting sequence is not part of
 :        the sequence that is mapped from the expanded QName <tt>$name</tt>.
 : @return  For each node <tt>$tnode</tt> in the target sequence <tt>$target</tt>,
 :          the following update primitive is appended to the pending update list:
 :          <ul>
 :            <li><tt>upd:deleteNode($name\$, $tnode)</tt></li>
 :          </ul>
 :          The resulting pending update list (together with an empty XDM instance)
 :          is the result of the delete-nodes function.
 :)
declare updating function ddl:delete-nodes($name as xs:QName,
                                           $target as node()*) external;

(:~
 : The delete-node-first function is an updating function that deletes the
 : first node from an ordered collection.
 :
 : @param <tt>$name</tt> The name of the collection from which the first node
 :        should be deleted.
 : @error <tt>XDST0010</tt> If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource
 :        in the statically known collections.
 : @error <tt>XDST0011</tt> If the modifier property of the statically known
 :        collection identified by the QName <tt>$name</tt> is not <tt>queue</tt>
 :        or the order property is not <tt>ordered</tt>.
 : @error <tt>XDDY0009</tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt>XDDY0014</tt> If the sequences mapped by the expanded QName
 :        <tt>$name</tt> doesn't contain any nodes.
 : @return Let <tt>$tnode</tt> be the first node of the sequence in the map
 :         of available collections identified by QName <tt>$name</tt>.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the <tt>upd:deleteNode($name, $tnode)</tt>
 :         update primitive.
 :)
declare updating function ddl:delete-node-first($name as xs:QName) {
  (: TODO implement in C++ :)
  if (fn:empty(ddl:collection($name))) 
  then
    fn:error($ddl:XDDY0014,
             "Cannot delete the first node of a collection that is empty")
  else
    (: raises XDDY0009 or deletes the last node :)
    ddl:delete-nodes($name, ddl:collection($name)[last()])
};

(:~
 : The delete-node-last function is an updating function that deletes the
 : last node from an ordered collection.
 :
 : @param <tt>$name</tt> The name of the collection from which the last node
 :        should be deleted.
 : @error <tt>XDST0010</tt> If the expanded QName of <tt>$name</tt> is not equal
 :        (as defined by the eq operator) to the name of any resource
 :        in the statically known collections.
 : @error <tt>XDST0011</tt> If the modifier property of the statically known
 :        collection identified by the QName <tt>$name</tt> is not <tt>queue</tt>
 :        or the order property is not <tt>ordered</tt>.
 : @error <tt>XDDY0009</tt> If available collections does not provide a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @error <tt>XDDY0014</tt> If the sequences mapped by the expanded QName
 :        <tt>$name</tt> doesn't contain any nodes.
 : @return Let <tt>$tnode</tt> be the last node of the sequence in the map
 :         of available collections identified by QName <tt>$name</tt>.
 :         The result of this function is an empty XDM instance and a pending
 :         update list containing the <tt>upd:deleteNode($name, $tnode)</tt>
 :         update primitive.
 :)
declare updating function ddl:delete-node-last($name as xs:QName) {
  (: TODO implement in C++ :)
  if (fn:empty(ddl:collection($name))) 
  then
    fn:error($ddl:XDDY0014,
             "Cannot delete the last node of a collection that is empty")
  else
    (: raises XDDY0009 or deletes the first node :)
    ddl:delete-nodes($name, ddl:collection($name)[1])
};

(:~
 : The create-index function is an updating function that adds a mapping from
 : the expanded QName <tt>$name</tt> to an empty map of index entries to the map of
 : available indexes.
 :
 : @param $name The QName of the index to add to the map of available
 :        indexes.
 : @error <tt>XDST0010</tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known indexes.
 : @error <tt>XDDY0012</tt> if available indexes already provides a mapping
 :        for the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:createIndex($name)</tt>
 :         update primitive.
 :)
declare updating function ddl:create-index($name as xs:QName) external;

(:~
 : The delete-index function is an updating function that removes a resource
 : from the map of available indexes. The QName <tt>$name</tt> is the name
 : of the resource.
 :
 : @param $name The QName of the index to delete from the map of available
 :        indexes.
 : @error <tt>XDST0010</tt> if the expanded QName of <tt>$name</tt> is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known indexes.
 : @error XDDY0009 If available indexes does not provide a mapping for
 :        the expaned QName <tt>$name</tt>.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the <tt>upd:deleteIndex($name)</tt>
 :         update primitive.
 :)
declare updating function ddl:delete-index($name as xs:QName) external;

(:~
  TODO documentation
 :)
declare updating function ddl:refresh-index($name as xs:QName) external;

