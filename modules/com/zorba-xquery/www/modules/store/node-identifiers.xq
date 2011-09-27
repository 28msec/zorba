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
 : Node identifier functions
 :
 : @author Federico Cavalieri
 : @project XDM/node
 :
 :)
module namespace id = "http://www.zorba-xquery.com/modules/store/node-identifiers";
declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : Returns whether the given node has an identifier or not.
 :
 : @param $arg the node
 : @return whether the given node has an identifier or not.
 :)
declare function id:has-identifier(
  $arg as node()  
) as xs:boolean external;

(:~
 : Retrieves the identifier of the given node.
 :
 : @param $arg the node for which the identifier should be retrieved
 : @return the identifier of the node passed as parameter
 :)
declare function id:node-identifier(
  $arg as node(),
  $generateUUID as xs:boolean,
  $registerUUID as xs:boolean
) as xs:string external;

(:~
 : Retrieves the identifier of the given node.
 : It is an error if the specified node do not have an identifier. 
 :
 : @param $arg the node for which the identifier should be retrieved
 : @return the identifier of the node passed as parameter
 :)
declare function id:current-node-identifier(
  $arg as node()
) as xs:string
{
  id:node-identifier($arg,false(),false())
};


(:~
 : Returns the node which is identified by the given identifier.
 : It is an error if the specified node identifier is not registered in the store.
 : 
 : @param $arg the identifier of the node to retrieve
 : @return the node identified by the identifier passed as parameter
 :         or the empty-sequence if no node with that identifier is found.
 :)
declare function id:node-by-identifier(
  $arg as xs:string
) as node() external;
