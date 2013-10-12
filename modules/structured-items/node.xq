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
 : This module defines a set of function which can be used
 : to determine (1) the relationship between two nodes (e.g. if one
 : is the ancestor if another) and (2) properties of given
 : nodes (e.g. their level in the tree).
 :
 : The same functionality can be achieved with simple XPath expressions.
 : However, please note that using the functions in this modules instead
 : of path expressions guarantees better performance.
 :
 : @author Matthias Brantner
 : @project Zorba/XML and JSON Data Model/Node/Node
 :)
module namespace node = "http://zorba.io/modules/node";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Determines whether the node given as second argument is an
 : ancestor of the node given as first argument.
 :
 : @param $node1 the potential descendant
 : @param $node2 the potential ancestor
 :
 : @return true if $node2 is an ancestor of $node1; false otherwise.
 :)
declare function node:ancestor-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is a
 : descendant of the node given as first argument.
 :
 : @param $node1 the potential ancestor
 : @param $node2 the potential descendant
 :
 : @return true if $node2 is a descendant of $node1; false otherwise.
 :)
declare function node:descendant-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is a
 : parent of the node given as first argument.
 :
 : @param $node1 the potential child
 : @param $node2 the potential parent
 :
 : @return true if $node2 is a parent of $node1; false otherwise.
 :)
declare function node:parent-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is a
 : child of the node given as first argument.
 :
 : @param $node1 the potential parent
 : @param $node2 the potential child
 :
 : @return true if $node2 is a child of $node1; false otherwise.
 :)
declare function node:child-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is a
 : following-sibling of the node given as first argument.
 :
 : @param $node1 the potential preceding-sibling
 : @param $node2 the potential following-sibling
 :
 : @return true if $node2 is a following-sibling of $node1; false otherwise.
 :)
declare function node:following-sibling-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is a
 : preceding-sibling of the node given as first argument.
 :
 : @param $node1 the potential following-sibling
 : @param $node2 the potential preceding-sibling
 :
 : @return true if $node2 is a preceding-sibling of $node1; false otherwise.
 :)
declare function node:preceding-sibling-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is
 : following the node given as first argument.
 :
 : @param $node1 the potential preceding node
 : @param $node2 the potential following node
 :
 : @return true if $node2 is following the node $node1; false otherwise.
 :)
declare function node:following-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Determines whether the node given as second argument is
 : preceding the node given as first argument.
 :
 : @param $node1 the potential following node
 : @param $node2 the potential preceding node
 :
 : @return true if $node2 is preceding the node $node1; false otherwise.
 :)
declare function node:preceding-of(
  $node1 as node(),
  $node2 as node()) as xs:boolean external;

(:~
 : Computes the level of a given node in the tree.
 :
 : Note: The first level has the number one.
 :
 : @param $node the node for which the level should be computed
 :
 : @return The level as xs:integer of the given node in the tree.
 :)
declare function node:level(
  $node as node()) as xs:integer external;

(:~
 : Computes the least common ancestor of two given nodes in
 : the tree.
 :
 : @param $node1 the first node
 : @param $node2 the second node
 : 
 : @return the least common ancestor of the two given nodes or
 :   the empty sequence if the two nodes are not part of the same
 :   tree.
 :)
declare function node:least-common-ancestor(
  $node1 as node(),
  $node2 as node()) as node()? external;

(:~
 : Return a deep copy of every given node according to the properties
 : specified in the static context of the invoking module.<p/>
 :
 : Please note that a copy of a node is parentless.
 :
 : @param $input the node to copy
 :
 : @return a deep copy of every node in the input sequence or the empty sequence if
 :   $input is the empty sequence.
 :)
declare function node:copy($input as node()*) as node()* external;
