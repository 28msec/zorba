xquery version "1.0";
(:
 : Copyright 2006-2011 The FLWOR Foundation.
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
 : This module provides a function (np:node-position) that, given a node, 
 : returns positional information about the node in the form of an xs:anyURI
 : item. The module also defines functions that use such positional information
 : to determine: (1) positional relationships between two nodes (e.g. if one 
 : is the ancestor of another) and (2) positional properties of a single node
 : (e.g. its level in the tree).
 :
 : Within this module, the term "node position" will be used to refer to an
 : xs:anyURI item that is returned by the np:node-position function.
 :
 : @author Federico Cavalieri 
 :)
module namespace np = "http://www.zorba-xquery.com/modules/node-position";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Compute a stable and opaque positional information representation 
 : (with type xs:anyURI) for a given node.
 :
 : <p>The returned URI is stable, i.e. it does not change when other 
 : nodes are inserted, deleted or modified.</p>
 : 
 : <p>Each node in a snapshot has a different URI. Note however that
 : different nodes in different snapshots might have the same URI.</p>  
 :
 : @param $arg the node for which the positional information URI
 :  should be computed
 :
 : @return the opaque positional information URI of the node.
 :)
declare function np:node-position(
  $arg as node()
) as xs:anyURI external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is an ancestor of the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential descendant node position
 : @param $n-pos2 the potential ancestor node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is an ancestor of the node whose node position is $n-pos1;
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function. 
 :)
declare function np:ancestor-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument belongs to the subtree rooted 
 : at the node whose node position is given as first argument.
 :
 : @param $n-pos1 the potential subtree root node position
 : @param $n-pos2 the potential node in the subtree node position
 :
 : @return true if the node whose node position is $n-pos2 
 : belongs to the subtree rooted at the node whose node position 
 : is $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:in-subtree-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is a descendant of the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential ancestor node position
 : @param $n-pos2 the potential descendant node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is a descendant of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:descendant-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is the parent of the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential child node position
 : @param $n-pos2 the potential parent node position
 :
 : @return true if the node whose node position is $n-pos2
 : is the parent of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:parent-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is a child of the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential parent node position
 : @param $n-pos2 the potential child node position
 :
 : @return true if the node whose node position is $n-pos2
 : is a child of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:child-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is an attribute of the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential parent node position
 : @param $n-pos2 the potential attribute node position
 :
 : @return true if the node whose node position is $n-pos2
 : is an attribute of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:attribute-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is a following-sibling of the node 
 : whose node position is given as first argument.
 :
 : @param $n-pos1 the potential preceding-sibling node position
 : @param $n-pos2 the potential following-sibling node position
 :
 : @return true if the node whose node position is $n-pos2
 : is a following-sibling of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is a preceding-sibling of the node 
 : whose node position is given as first argument.
 :
 : @param $n-pos1 the potential following-sibling node position
 : @param $n-pos2 the potential preceding-sibling node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is a preceding-sibling of the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is following the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential preceding node position
 : @param $n-pos2 the potential following node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is following the node whose node position is $n-pos1;
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

  
(:~
 : Determines whether the node whose node position is given as 
 : second argument is following in document order the node 
 : whose node position is given as first argument.
 :
 : @param $n-pos1 the potential preceding node position
 : @param $n-pos2 the potential following node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is following in document order the node whose node position
 : is $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-in-document-order-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;


(:~
 : Determines whether the node whose node position is 
 : given as second argument is preceding the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential following node position
 : @param $n-pos2 the potential preceding node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is preceding the node whose node position is $n-pos1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose node position is 
 : given as second argument is preceding the node whose 
 : node position is given as first argument.
 :
 : @param $n-pos1 the potential following node position
 : @param $n-pos2 the potential preceding node position
 :
 : @return true if the node whose node position is $n-pos2 
 : is preceding in document order the node whose node position 
 : is $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-in-document-order-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;


(:~
 : Computes the level of a node in the tree given its node position.
 :
 : Note: The first level has the number one.
 :
 : @param $n-pos the node position of the node whose level should be 
 : determined.
 :
 : @return the level in the tree of the node whose node position is 
 : $n-pos as xs:integer.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:level(
  $n-pos as xs:anyURI) as xs:integer external;  

(:~
 : Determines whether two nodes are siblings given their node position.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two nodes whose node positions are $n-pos1
 : and $n-pos2 are siblings; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node is an attribute given its node position.
 :
 : @param $n-pos the potential attribute node position
 :
 : @return true if the node whose node position is $n-pos
 : is an attribute; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-attribute(
  $n-pos1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node is a comment given its node position.
 :
 : @param $n-pos the potential comment node position
 :
 : @return true if the node whose node position is $n-pos
 : is a comment; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-comment(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
 (:~
 : Determines whether a node is a document given its node position.
 :
 : @param $n-pos the potential document node position
 :
 : @return true if the node whose node position is $n-pos
 : is a document; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-document(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
 (:~
 : Determines whether a node is an element given its node position.
 :
 : @param $n-pos the potential element node position
 :
 : @return true if the node whose node position is $n-pos
 : is an element; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-element(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
 (:~
 : Determines whether a node is a processing-instruction given its 
 : node position.
 :
 : @param $n-pos the potential processing-instruction node position
 :
 : @return true if the node whose node position is $n-pos
 : is a processing-instruction; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-processing-instruction(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
 (:~
 : Determines whether a node is a text given its node position.
 :
 : @param $n-pos the potential text node position
 :
 : @return true if the node whose node position is $n-pos
 : is a text; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-text(
  $n-pos1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two nodes belong to the same tree given their
 : node position.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two nodes whose node positions are $n-pos1
 : and $n-pos2 belong to the same tree.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-tree-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node belongs to a collection given its 
 : node position.
 :
 : @param $n-pos the node position
 :
 : @return true if the node whose node position is $n-pos 
 : belongs to a collection; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:in-collection(
  $n-pos as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two nodes belong to the same collection given 
 : their node position.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two nodes whose node positions are $n-pos1
 : and $n-pos2 belong to the same collection.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-collection-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;
