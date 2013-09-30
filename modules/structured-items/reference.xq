xquery version "1.0";

(:
 : Copyright 2006-2012 The FLWOR Foundation.
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
 : The module provides functions to compute an immutable and opaque reference 
 : for nodes, objects, or arrays and to retrieve such items given their
 : identifier, respectively.
 : The identifiers are immutable, i.e. a identifier does not change
 : during the items lifetime and cannot be reused for another item after the
 : original item gets deleted.
 : Identifiers are unique, in that, two different items will never have the same 
 : identifier. A item, at any time during its lifetime, can be retrieved by its 
 : identifier.
 :
 : <p>Please see the <a href="../zorba/data_lifecycle.html">data lifecycle
 : documentation</a> about details on storing items.</p>
 : 
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 :
 : @author Matthias Brantner
 : @project Zorba/XML and JSON Data Model/Node/Reference
 :
 :)
module namespace ref = "http://zorba.io/modules/reference";

declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";

declare option ver:module-version "1.0";

(:~
 : <p>Returns an immutable and opaque reference (with type xs:anyURI) for
 : a given node, object, or array.</p>
 : 
 : <p>The generated identifier is immutable, i.e. a identifier does not
 : change during the item's lifetime and cannot be reused for another node after
 : the original item gets deleted.</p>
 :
 : <p>Identifiers are also unique, in that, two different items will never 
 : have the same identifier.</p>
 :
 : A item, at any time during its lifetime, can be retrieved by its 
 : identifier, using the <tt>ref:dereference</tt> function.
 :
 : Please note that a reference can only be retrieved for a JSON object or JSON
 : array if the item is a member of a collection.
 :
 : @param $arg the node, object, or array for which the URI should be computed
 :
 : @return the opaque URI of the item.
 :
 : @error zerr::ZAPI0080 is raised if the object or array passed as argument
 :   is not a member of a collection.
 :)
declare function ref:reference(
  $arg as item()
) as xs:string external;

(:~
 : <p>Returns the node, object, or array identified by the given reference.</p>
 :
 : <p>The function returns the empty sequence if the item
 : that is referenced does not exist.</p>
 :
 : @param $arg the URI of the item to retrieve.
 :
 : @return the item identified by the URI passed as parameter
 :         or the empty-sequence if no item with that URI is found.
 :)
declare function ref:dereference(
  $arg as xs:string
) as item()? external;
