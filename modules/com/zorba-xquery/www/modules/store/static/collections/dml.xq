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
 : This modules defines a set of functions to modify a collection or retrieve the nodes
 : contained in a particular collection.
 : Such collections are identified by QNames and come into existence (i.e. be available)
 : by calling one of the two create-collection functions of the 
 : <tt>http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl</tt>
 : module.
 :
 : The variable $content passed to any of the insert functions is evaluated
 : as though it were an enclosed expression in an element constructor.
 : The result of this step is a sequence of nodes to be inserted into the collection.
 :
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/collections/static
 :
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

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
declare %sequential function dml:apply-insert-nodes(
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
declare %sequential function dml:apply-insert-nodes-first(
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
declare %sequential function dml:apply-insert-nodes-last(
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
declare %sequential function dml:apply-insert-nodes-before(
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
declare %sequential function dml:apply-insert-nodes-after(
  $name as xs:QName,
  $pos as node(),
  $content as node()*) as node()*  external;

(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collection. 
 :
 : @param $target the nodes in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list that contains one update primitive upd:deleteNode($name, $tnode) for 
 :         node in the target sequence.
 :
 : @error XDDY0006 if the modifier property of the collection $name is const, append-only,
          or queue.
 : @error XDTY0001 if $content does not match the expected type according to the
 :        rules for SequenceType Matching.
 : @error XDDY0011 if any nodes in the $target sequence is not a member of a collection
 :        or not all nodes of the $target sequence belong to the same collection.
 :        the collection identified by the $name parameter.
 :)
declare updating function dml:delete-nodes($target as node()*)  external;

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
