xquery version "3.0";

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
 : This module provides functions to compute a string identifier for
 : any node, either temporary or stored in a collection and for retrieving
 : nodes given their identifier. The identifiers are immutable, i.e. a node 
 : identifier do not change during the node lifetime. Identifiers are also 
 : unique in that an already generated identifier cannot be generated again.
 : Morever a node, at any time during its lifetime can be retrieved by its 
 : identifier.
 :
 : @author Federico Cavalieri 
 :)
module namespace id = "http://www.zorba-xquery.com/modules/node-identifier";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Computes a UUID string identifier (with type xs:string) for the given node.
 : If an identifier has been already generated for the the given node it is 
 : returned. Otherwise a new identifier is generated and returned.
 :
 : <p>The returned identifier is immutable, i.e., a node identifier
 : do not change during the node lifetime.</p>
 :
 : <p>The returned identifier is unique, i.e. the same identifier cannot be
 : generated again.</p>
 :
 : @param $arg the node for which the identifier should be computed 
 :
 : @return the identifier of the node
 :
 :)
declare function id:node-identifier(
  $node as node()
) as xs:string external;

(:~
 : Computes a UUID string identifier (with type xs:string) for the given node.
 : If an identifier has been already generated for the the given node it is 
 : returned.
 :
 : <p>The returned identifier is stable, i.e. the corresoponding node
 : can be retrieved at any time during its lifetime.</p>
 :
 : <p>The returned identifier is unique, i.e. the same identifier cannot be
 : generated again.</p>
 :
 : @param $arg the node for which the identifier should be computed 
 :
 : @return the identifier of the node
 :
 : @error zerr::ZAPI0091 if no identifier has been generated for the given node
 : computed by the <pre>id:node-identifier</pre> function
 :
 :)
declare function id:current-node-identifier(
  $node as node()
) as xs:string external;
 
(:~
 : Returns whether an identifier has already been generated the given node or not.
 :  
 : @param $node a node 
 :
 : @return whether an identifier has already been generated the given node or not
 :)
declare function id:has-identifier(
  $node as node()  
) as xs:boolean external;

(:~
 : Returns the node which is identified by the given identifier.
 :
 : <p>The function return the empty sequence if the corresponding 
 : node has been deleted or if the given identifier has never been
 : generated.</p>  
 :
 : @param $node-identifier the identifier of the node to retrieve
 :
 : @return the node identified by the given identifier or empty-sequence
 : if it cannot be retrieved
 :
 : @error zerr::ZAPI0091 if the given identifier is not a valid identifier
 : computed by the <pre>id:node-identifier</pre> function
 :)
declare function id:node-by-identifier(
  $arg as xs:string
) as node()? external;
