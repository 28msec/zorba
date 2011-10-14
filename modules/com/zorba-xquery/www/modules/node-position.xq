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
 : This module provides a function (np:node-position) that given, a node, 
 : returns positional information about the node in the form of an xs:anyURI
 : item. The module also defines functions that use such positional information
 : to determine: (1) structural relationships between two nodes (e.g. if one 
 : is the ancestor of another) and (2) properties of a node (e.g. its level in 
 : the tree).
 :
 : Within this module, the temp "node position" will be used to refer to an
 : xs:anyURI item that is returned by the np:node-position function.
 :
 : @author Federico Cavalieri 
 :)
module namespace np = "http://www.zorba-xquery.com/modules/node-position";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Compute a stable and opaque structural information representation 
 : (with type xs:anyURI) for a given node.
 :
 : <p>The returned URI is stable, i.e. it does not change when other 
 : nodes are inserted, deleted or modified.</p>
 : 
 : <p>Each node in a snapshot has a different URI. Note however that
 : different nodes in different snapshots might have the same URI.</p>  
 :
 : @param $arg the node for which the structural information URI
 :  should be computed
 :
 : @return the opaque structural information URI of the node.
 :)
declare function np:node-position(
  $arg as node()
) as xs:anyURI external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is an ancestor of the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential descendant structural information
 : @param $s-info2 the potential ancestor structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is an ancestor of the node whose structural information is $s-info1;
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function. 
 :)
declare function np:ancestor-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is a descendant of the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential ancestor structural information
 : @param $s-info2 the potential descendant structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is a descendant of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:descendant-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is the parent of the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential child structural information
 : @param $s-info2 the potential parent structural information
 :
 : @return true if the node whose structural information is $s-info2
 : is the parent of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:parent-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is a child of the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential parent structural information
 : @param $s-info2 the potential child structural information
 :
 : @return true if the node whose structural information is $s-info2
 : is a child of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:child-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is an attribute of the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential parent structural information
 : @param $s-info2 the potential attribute structural information
 :
 : @return true if the node whose structural information is $s-info2
 : is an attribute of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:attribute-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is a following-sibling of the node 
 : whose structural information is given as first argument.
 :
 : @param $s-info1 the potential preceding-sibling structural information
 : @param $s-info2 the potential following-sibling structural information
 :
 : @return true if the node whose structural information is $s-info2
 : is a following-sibling of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-sibling-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is a preceding-sibling of the node 
 : whose structural information is given as first argument.
 :
 : @param $s-info1 the potential following-sibling structural information
 : @param $s-info2 the potential preceding-sibling structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is a preceding-sibling of the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-sibling-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is following the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential preceding node structural information
 : @param $s-info2 the potential following node structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is following the node whose structural information is $s-info1;
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

  
(:~
 : Determines whether the node whose structural information is 
 : given as second argument is following in document order the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential preceding node structural information
 : @param $s-info2 the potential following node structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is following in document order the node whose structural information
 : is $s-info1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-in-document-order-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;


(:~
 : Determines whether the node whose structural information is 
 : given as second argument is preceding the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential following node structural information
 : @param $s-info2 the potential preceding node structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is preceding the node whose structural information is $s-info1; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node whose structural information is 
 : given as second argument is preceding the node whose 
 : structural information is given as first argument.
 :
 : @param $s-info1 the potential following node structural information
 : @param $s-info2 the potential preceding node structural information
 :
 : @return true if the node whose structural information is $s-info2 
 : is preceding in document order the node whose structural information 
 : is $s-info1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-in-document-order-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;


(:~
 : Computes the level of a node in the tree given its structural
 : information.
 :
 : Note: The first level has the number one.
 :
 : @param $s-info the structural information of the node which 
 :  level should be computed
 :
 : @return The level in the tree as xs:integer of the node whose 
 : structural information is $s-info.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:level(
  $s-info as xs:anyURI) as xs:integer external;  

(:~
 : Determines whether two nodes are siblings given their structural information.
 :
 : @param $s-info1 a node structural information
 : @param $s-info2 a node structural information
 :
 : @return true if the two nodes whose structural information are $s-info1
 : and $s-info2 are siblings; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:sibling-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node is an attribute given its structural information.
 :
 : @param $s-info the potential attribute structural information
 :
 : @return true if the node whose structural information is $s-info
 : is an attribute; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-attribute(
  $s-info1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node is a comment given its structural information.
 :
 : @param $s-info the potential comment structural information
 :
 : @return true if the node whose structural information is $s-info
 : is a comment; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-comment(
  $s-info1 as xs:anyURI) as xs:boolean external;
  
  (:~
 : Determines whether a node is a document given its structural information.
 :
 : @param $s-info the potential document structural information
 :
 : @return true if the node whose structural information is $s-info
 : is a document; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-document(
  $s-info1 as xs:anyURI) as xs:boolean external;
  
  (:~
 : Determines whether a node is an element given its structural information.
 :
 : @param $s-info the potential element structural information
 :
 : @return true if the node whose structural information is $s-info
 : is an element; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-element(
  $s-info1 as xs:anyURI) as xs:boolean external;
  
  (:~
 : Determines whether a node is a processing-instruction given its structural information.
 :
 : @param $s-info the potential processing-instruction structural information
 :
 : @return true if the node whose structural information is $s-info
 : is a processing-instruction; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-processing-instruction(
  $s-info1 as xs:anyURI) as xs:boolean external;
  
  (:~
 : Determines whether a node is a text given its structural information.
 :
 : @param $s-info the potential text node structural information
 :
 : @return true if the node whose structural information is $s-info
 : is a text node; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-text(
  $s-info1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two nodes belong to the same tree given their
 : structural information.
 :
 : @param $s-info1 a node structural information
 : @param $s-info2 a node structural information
 :
 : @return true if the two node whose structural information are $s-info1
 : and $s-info2 belong to the same tree.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-tree-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node belongs to a collection given its structural
 : information.
 :
 : @param $s-info the node structural information
 :
 : @return true if the node whose structural information is $s-info 
 : is in a collection; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)
declare function np:in-collection(
  $s-info as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two nodes belong to the same collection given their
 : structural information.
 :
 : @param $s-info1 a node structural information
 : @param $s-info2 a node structural information
 :
 : @return true if the two node whose structural information are $s-info1
 : and $s-info2 belong to the same collection.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node structural
 : information computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-collection-of(
  $s-info1 as xs:anyURI,
  $s-info2 as xs:anyURI) as xs:boolean external;
