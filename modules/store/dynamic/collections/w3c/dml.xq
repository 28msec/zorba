xquery version "3.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This modules provides a set of functions to modify a collection and retrieve
 : the nodes contained in a particular collection.
 : <p/>
 : Such collections are identified by a URI as defined in the XQuery
 : specification.
 : However, please note that we do not advice users to use collections
 : identified by URIs.
 : Instead, we refer to the
 : <a href="../zorba/data_lifecycle.html">data lifecycle documentation</a>.
 : It gives an overview of several ways to work with collections, documents,
 : and other data-structures.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see http://zorba.io/modules/store/dynamic/collections/w3c/ddl
 : @see http://zorba.io/modules/store/dynamic/collections/ddl
 : @see http://zorba.io/modules/store/dynamic/collections/dml
 : @see http://zorba.io/errors
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/W3C Data Manipulation
 :)
module namespace dml = "http://zorba.io/modules/store/dynamic/collections/w3c/dml";

import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/w3c/ddl";

import module namespace qdml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace an = "http://zorba.io/annotations";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Inserts copies of the given nodes at the beginning of the collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts <code>$content</code> into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function dml:insert-nodes-first( $name as xs:string,
                                                  $content as node()* )
{
  qdml:insert-first( ddl:to-qname( $name ), $content )
};

(:~
 : Inserts copies of the given nodes at the end of the collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the nodes into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function dml:insert-nodes-last( $name as xs:string,
                                                 $content as node()* )
{
  qdml:insert-last( ddl:to-qname( $name ), $content )
};

(:~
 : Inserts copies of the given nodes into a collection at the position directly
 : preceding the given target node.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The node in the collection before which <code>$content</code>
 : will be inserted.
 : @param $content The sequences of nodes whose copies will be inserted.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the nodes into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if <code>$target</code> node is not contained in the
 : collection.
 :)
declare updating function dml:insert-nodes-before( $name as xs:string,
                                                   $target as node(),
                                                   $content as node()* )
{
  qdml:insert-before( ddl:to-qname( $name ), $target, $content )
};

(:~
 : Inserts copies of the given nodes into a collection at the position
 : directly following the given target node.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The node in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the nodes into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if <code>$target</code> node is not contained in the
 : collection.
 :)
declare updating function dml:insert-nodes-after( $name as xs:string,
                                                  $pos as node(),
                                                  $content as node()* )
{
  qdml:insert-after( ddl:to-qname( $name ), $pos, $content )
};

(:~
 : This function does the same as the <code>insert-nodes()</code> function
 : except it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return The sequence of nodes that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-nodes-first
 :)
declare %an:sequential function
dml:apply-insert-nodes-first( $name as xs:string, $content as node()* )
  as node()*
{
  qdml:apply-insert-first( ddl:to-qname( $name ), $content )
};

(:~
 : This function does the same as the <code>insert-nodes-last()</code> function
 : except it immediately applies the resulting pending updates and returns the
 : nodes that have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return The sequence of nodes that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-nodes-last
 :)
declare %an:sequential function
dml:apply-insert-nodes-last( $name as xs:string, $content as node()* )
  as node()*
{
  qdml:apply-insert-last( ddl:to-qname( $name ), $content )
};

(:~
 : This function does the same as the <code>insert-nodes-before()</code>
 : function except it immediately applies the resulting pending updates and
 : returns the nodes that have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The node in the collection before which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return The sequence of nodes that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-nodes-before
 :)
declare %an:sequential function
dml:apply-insert-nodes-before( $name as xs:string,
                               $target as node(),
                               $content as node()* )
  as node()*
{
  qdml:apply-insert-before( ddl:to-qname( $name ), $target, $content )
};

(:~
 : This function does the same as the <code>insert-nodes-after()</code>
 : function except it immediately applies the resulting pending updates and
 : returns the nodes that have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The node in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of nodes whose copies will be inserted.
 : @return The sequence of nodes that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-nodes-after
 :)
declare %an:sequential function
dml:apply-insert-nodes-after( $name as xs:string,
                              $pos as node(),
                              $content as node()* )
  as node()*
{
  qdml:apply-insert-after( ddl:to-qname( $name ), $pos, $content )
};

(:~
 : Gets the sequence of nodes of the collection identified by the given name.
 :
 : @param $name The name of the collection.
 : @return The sequence contained in the given collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare function dml:collection( $name as xs:string )
  as node()*
{
  qdml:collection( ddl:to-qname( $name ) )
};

(:~
 : Gets the name of the collection the given node belongs to.
 :
 : @param $node The node for which to get the name of the collection.
 : @return The URI of the collection to which <code>$node</code> belongs.
 : @error zerr:ZDDY0011 if <code>$node</code> does not belong to a collection.
 :)
declare function dml:collection-name( $node as node() )
  as xs:string
{
  ddl:from-qname( qdml:collection-name( $node ) )
};

(:~
 : Deletes nodes from a collection. 
 :
 : @param $nodes the nodes in the collection that should be deleted.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the nodes from their collections.
 : @error zerr:ZDDY0011 if any nodes are not a member of a collection or not
 : all nodes of belong to the same collection.
 :)
declare updating function dml:delete-nodes( $nodes as node()* )
{
  qdml:delete( $nodes )
};

(:~
 : Deletes the first node from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the first node from the collection.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function dml:delete-node-first( $name as xs:string )
{
  qdml:delete-first( ddl:to-qname( $name ) )
};

(:~
 : Deletes the first <i>N</i> nodes from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of nodes to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the nodes from the collection.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function dml:delete-nodes-first( $name as xs:string,
                                                  $number as xs:integer )
{
  qdml:delete-first( ddl:to-qname( $name ), $number )
};

(:~
 : Deletes the last node from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the last node from the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function dml:delete-node-last( $name as xs:string )
{
  qdml:delete-last( ddl:to-qname( $name ) )
};

(:~
 : Deletes the last <i>N</i> nodes from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of nodes to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the last n nodes.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function dml:delete-nodes-last( $name as xs:string,
                                                 $number as xs:integer )
{
  qdml:delete-last( ddl:to-qname( $name ), $number )
};

(:~
 : Gets the index of the given node in the collection.
 :
 : @param $node The node to get the index of.
 : @return Returns the position of <code>$node</code> in the collection.
 : @error zerr:ZDDY0011 if <code>$node</code> is not contained in any
 : collection.
 :)
declare function dml:index-of( $node as node() )
  as xs:integer
{
  qdml:index-of( $node )
};

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
