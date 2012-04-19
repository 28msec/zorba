xquery version "3.0";

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
 : This modules provides a set of functions to modify a collection and retrieve the nodes
 : contained in a particular collection.
 :
 : <p>Such collections are identified by a URI as defined in the XQuery specification.
 : However, please note that we do not advice users to use collections identified by URIs.
 : Instead, we refer to the <a href="../../html/data_lifecycle.html">data lifecycle
 : documentation</a>. It gives an overview over serveral ways to work with collections,
 : documents, and other data-structures.</p>
 :
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/dml
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 : @project store/collections/w3c
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl";

import module namespace qdml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace an = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : The insert-nodes-first function is an updating function that inserts copies of the
 : given nodes at the beginning of the collection.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the nodes into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function dml:insert-nodes-first(
  $name as xs:string,
  $content as node()*)
{
  qdml:insert-nodes-first(ddl:to-qname($name), $content)
};

(:~
 : The insert-nodes-last function is an updating function that inserts copies of the
 : given nodes at the end of the collection.
 :
 : @param $name The name of the collection to which the nodes should  be added.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the nodes into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function dml:insert-nodes-last(
  $name as xs:string,
  $content as node()*)
{
  qdml:insert-nodes-last(ddl:to-qname($name), $content)
};

(:~
 : The insert-nodes-before function is an updating function that inserts
 : copies of the given nodes into a collection at the position directly preceding the
 : given target node.
 :
 : @param $name The name of the collection to which the nodes should  be added.
 : @param $target The node in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the nodes into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target node is not contained in the collection.
 :
 :)
declare updating function dml:insert-nodes-before($name as xs:string,
                                                    $target as node(),
                                                    $content as node()*)
{
  qdml:insert-nodes-before(ddl:to-qname($name), $target, $content)
};

(:~
 : The insert-nodes-after function is an updating function that inserts
 : copies of the given nodes into a collection at the position directlry following the
 : given target node.
 :
 : @param $name The name of the collection to which the nodes should be added.
 : @param $target The node in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of nodes whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the nodes into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target node is not contained in the collection.
 :
 :)
declare updating function dml:insert-nodes-after($name as xs:string,
                                                  $pos as node(),
                                                  $content as node()*)
{
  qdml:insert-nodes-after(ddl:to-qname($name), $pos, $content)
};


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
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-first
 :
 :)
declare %an:sequential function dml:apply-insert-nodes-first(
  $name as xs:string,
  $content as node()*) as node()*
{
  qdml:apply-insert-nodes-first(ddl:to-qname($name), $content)
};

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
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-last
 :
 :)
declare %an:sequential function dml:apply-insert-nodes-last(
  $name as xs:string,
  $content as node()*) as node()*
{
  qdml:apply-insert-nodes-last(ddl:to-qname($name), $content)
};

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
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-before
 :
 :)
declare %an:sequential function dml:apply-insert-nodes-before(
  $name as xs:string,
  $target as node(),
  $content as node()*) as node()*
{
  qdml:apply-insert-nodes-before(ddl:to-qname($name), $target, $content)
};

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
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-after
 :
 :)
declare %an:sequential function dml:apply-insert-nodes-after(
  $name as xs:string,
  $pos as node(),
  $content as node()*) as node()*
{
  qdml:apply-insert-nodes-after(ddl:to-qname($name), $pos, $content)
};

(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collection. 
 :
 : @param $target the nodes in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the nodes from their collections.
 :
 : @error zerr:ZDDY0011 if any nodes in the $target sequence is not a member of a collection
 :        or not all nodes of the $target sequence belong to the same collection.
 :        the collection identified by the $name parameter.
 :
 :)
declare updating function dml:delete-nodes($target as node()*)
{
  qdml:delete-nodes($target)
};

(:~
 : The delete-node-first function is an updating function that deletes the
 : first node from a collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the first node from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain any node.
 :
 :)
declare updating function dml:delete-node-first($name as xs:string)
{
  qdml:delete-node-first(ddl:to-qname($name))
};

(:~
 : The delete-nodes-first function is an updating function that deletes the
 : first n nodes from a collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @param $number The number of nodes that should be removed from the beginning of
 :        the collection.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the nodes from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of nodes.
 :)
declare updating function dml:delete-nodes-first(
  $name as xs:string,
  $number as xs:integer)
{
  qdml:delete-nodes-first(ddl:to-qname($name), $number)
};

(:~
 : The delete-node-last function is an updating function that deletes the
 : last node from a collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last node from the collection.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the URI $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain any node.
 :)
declare updating function dml:delete-node-last($name as xs:string)
{
  qdml:delete-node-last(ddl:to-qname($name))
};

(:~
 : The delete-nodes-last function is an updating function that deletes the
 : last n nodes from an ordered collection.
 :
 : @param $name The name of the collection from which the first node should be deleted.
 : @param $number The number of nodes to delete.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last n nodes.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the URI $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of nodes.
 :)
declare updating function dml:delete-nodes-last(
  $name as xs:string,
  $number as xs:integer)
{
  qdml:delete-nodes-last(ddl:to-qname($name), $number)
};

(:~
 : The index-of function return the index of the given node in the collection.
 :
 : @param node The node to retrieve the index from.
 :
 : @return Returns the position as xs:integer of the given node in the collection.
 :
 : @error zerr:ZDDY0011 if node is not contained in any collection.
 :
 :)
declare function dml:index-of($node as node()) as xs:integer
{
  qdml:index-of($node)
};

(:~
 : The collection function returns the sequence of nodes of the collection
 : identified by the given name.
 :
 : @param $name The name of the collection.
 :
 : @return The sequence contained in the given collection.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the URI $name.
 :
 :)
declare function dml:collection($name as xs:string) as node()*
{
  qdml:collection(ddl:to-qname($name))
};

(:~
 : This function returns the name of the collection the given node belongs
 : to.
 :
 : @param $node The node for which to get the name of the collection
 : @return The result of this function is a URI which identifies the collection
 :         to which the given node belongs to.
 :
 : @error zerr:ZDDY0011 if the given node does not belong to a collection.
 :
 :)
declare function dml:collection-name($node as node()) as xs:string
{
  ddl:from-qname(qdml:collection-name($node))
};
