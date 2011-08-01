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
 : Node reference functions
 :
 : @author Matthias Brantner
 : @project XDM/node
 :
 :)
module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Computes the URI for the given node.
 :
 : @param $arg the node for which the URI should be computed
 : @return the URI of the node passed as parameter
 :)
declare function ref:node-reference(
  $arg as node()
) as xs:anyURI external;

(:~
 : Returns the node which is identified by a reference.
 : 
 : @param $arg the URI of the node to retrieve
 : @return the node identified by the URI passed as parameter
 :         or the empty-sequence if no node with that URI is found.
 :)
declare function ref:node-by-reference(
  $arg as xs:anyURI
) as node() external;
