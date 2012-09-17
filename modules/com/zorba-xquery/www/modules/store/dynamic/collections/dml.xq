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
 : This modules provides a set of functions to modify a collection and retrieve the items
 : contained in a particular collection.
 :
 : <p>Please refer to our documentation for <a href="../../html/data_lifecycle.html">
 : more information</a> about the lifecycle management and the manipulation of such
 : collections.</p>
 : 
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 : @project store/collections/dynamic
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

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
 : @deprecated please use the cdml:insert-first#2 function
 :
 :)
declare updating function 
dml:insert-nodes-first($name as xs:QName, $content as node()*) external;


(:~
 : The insert-first function is an updating function that inserts copies of the
 : given items (nodes or json items) at the beginning of the collection.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update
 :         list which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function 
dml:insert-first($name as xs:QName, $content as item()*) external;


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
 : @deprecated please use the cdml:insert-last#2 function
 :
 :)
declare updating function 
dml:insert-nodes-last($name as xs:QName, $content as node()*) external;


(:~
 : The insert-last function is an updating function that inserts copies of the
 : given items (nodes or json items) at the end of the collection.
 :
 : @param $name The name of the collection to which the items should  be added.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function 
dml:insert-last($name as xs:QName, $content as item()*) external;


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
 : @deprecated please use the cdml:insert-before#3 function
 :
 :)
declare updating function 
dml:insert-nodes-before(
  $name as xs:QName,
  $target as node(),
  $content as node()*) external;

(:~
 : The insert-before function is an updating function that inserts copies of
 : the given items (nodes or json items) into a collection at the position 
 : directly preceding the given target item.
 :
 : @param $name The name of the collection to which the items should  be added.
 : @param $target The item in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target item is not contained in the collection.
 :
 :)
declare updating function 
dml:insert-before($name as xs:QName, $target as item(), $content as item()*) external;


(:~
 : The insert-nodes-after function is an updating function that inserts
 : copies of the given nodes into a collection at the position directly following the
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
 : @deprecated please use the cdml:insert-after#3 function
 :
 :)
declare updating function 
dml:insert-nodes-after(
  $name as xs:QName,
  $pos as node(),
  $content as node()*) external;


(:~
 : The insert-after function is an updating function that inserts copies of
 : the given items (nodes and/or json items) into a collection at the position
 : directly following the given target item.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The item in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target node is not contained in the collection.
 :
 :)
declare updating function 
dml:insert-after($name as xs:QName, $pos as item(), $content as item()*) external;


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
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-first
 :
 : @deprecated please use the cdml:apply-insert-first#2 function
 :
 :)
declare %an:sequential function 
dml:apply-insert-nodes-first(
  $name as xs:QName,
  $content as node()*) as node()* external;


(:~
 : This function does the same as the insert-first function except it immediately
 : applies the resulting pending updates and returns the items that have been inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-first
 :
 :)
declare %an:sequential function 
dml:apply-insert-first($name as xs:QName, $content as item()*) as item()* external;


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
 : @deprecated please use the cdml:apply-insert-last#2 function
 :
 :)
declare %an:sequential function dml:apply-insert-nodes-last(
  $name as xs:QName,
  $content as node()*) as node()* external;


(:~
 : This function does the same as the insert-last function except it immediately
 : applies the resulting pending updates and returns the items that have been 
 : inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-last
 :
 :)
declare %an:sequential function dml:apply-insert-last(
  $name as xs:QName,
  $content as item()*) as item()* external;


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
 : @deprecated please use the cdml:apply-insert-before#3 function
 :
 :)
declare %an:sequential function 
dml:apply-insert-nodes-before(
  $name as xs:QName,
  $target as node(),
  $content as node()*) as node()* external;


(:~
 : This function does the same as the insert-before function except it immediately
 : applies the resulting pending updates and returns the items that have been 
 : inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The item in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-before
 :
 :)
declare %an:sequential function 
dml:apply-insert-before(
  $name as xs:QName,
  $target as item(),
  $content as item()*) as item()* external;


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
 : @deprecated please use the cdml:apply-insert-after#3 function
 :
 :)
declare %an:sequential function 
dml:apply-insert-nodes-after(
  $name as xs:QName,
  $pos as node(),
  $content as node()*) as node()* external;


(:~
 : This function does the same as the insert-after function except it immediately
 : applies the resulting pending updates and returns the items that have been 
 : inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The item in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of items whose copies should be added to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-after
 :
 :)
declare %an:sequential function 
dml:apply-insert-after(
  $name as xs:QName,
  $pos as item(),
  $content as item()*) as item()* external;


(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : nodes from a collection. 
 :
 : @param $target the nodes in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the nodes from their collections.
 :
 : @error zerr:ZDDY0011 if any nodes in the $target sequence is not a member of
 :        a collection or not all nodes of the $target sequence belong to the same
 :        collection.
 :
 : @deprecated please use the cdml:delete#1 function
 :
 :)
declare updating function 
dml:delete-nodes($target as node()*) external;


(:~
 : The delete function is an updating function that deletes zero of more items
 : (nodes and/or json items) from a collection. 
 :
 : @param $target the items in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the items from their collections.
 :
 : @error zerr:ZDDY0011 if any item in the $target sequence is not a member of
 :        a collection or not all items of the $target sequence belong to the
 :        same collection.
 :
 :)
declare updating function 
dml:delete($target as item()*) external;


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
 : @deprecated please use the cdml:delete-first#1 function
 :
 :)
declare updating function 
dml:delete-node-first($name as xs:QName) external;


(:~
 : The delete-first function is an updating function that deletes the first item
 : from a collection.
 :
 : @param $name The name of the collection from which the first item should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the first item from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain any item.
 :
 :)
declare updating function 
dml:delete-first($name as xs:QName) external;


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
 :
 : @deprecated please use the cdml:delete-first#2 function
 :
 :)
declare updating function 
dml:delete-nodes-first($name as xs:QName, $number as xs:integer) external;


(:~
 : The delete-first function is an updating function that deletes the first N
 : items from a collection.
 :
 : @param $name The name of the collection from which the first N items should be deleted.
 : @param $number The number N of items that should be removed from the beginning of
 :        the collection.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the items from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of items.
 :
 :)
declare updating function 
dml:delete-first($name as xs:QName, $number as xs:integer) external;


(:~
 : The delete-node-last function is an updating function that deletes the
 : last node from a collection.
 :
 : @param $name The name of the collection from which the last node should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last node from the collection.
 :
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain any node.
 :
 : @deprecated please use the cdml:delete-last#1 function
 :
 :)
declare updating function 
dml:delete-node-last($name as xs:QName) external;


(:~
 : The delete-last function is an updating function that deletes the last item
 : from a collection.
 :
 : @param $name The name of the collection from which the last item should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last item from the collection.
 :
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain any item.
 :
 :)
declare updating function 
dml:delete-last($name as xs:QName) external;


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
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of nodes.
 :
 : @deprecated please use the cdml:delete-last#2 function
 :
 :)
declare updating function 
dml:delete-nodes-last($name as xs:QName, $number as xs:integer) external;


(:~
 : The delete-last function is an updating function that deletes the last N 
 : items from an ordered collection.
 :
 : @param $name The name of the collection from which the lsat N items should be deleted.
 : @param $number The number N of items to delete.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last N items.
 :
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of items.
 :
 :)
declare updating function 
dml:delete-last($name as xs:QName, $number as xs:integer) external;


(:~
 : The truncate function is an updating function that deletes the
 : entire contents of collection.
 :
 : @param $name The name of the collection whose content to delete
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the nodes.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :)
declare updating function dml:truncate($name as xs:QName) external;


(:~
 : The collection function returns the sequence of nodes and/or json items
 : that belong to the collection identified by the given name.
 :
 : @param $name The name of the collection.
 :
 : @return The sequence contained in the given collection.
 :
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 :
 :)
declare function dml:collection($name as xs:QName) as item()* external;


(:~
 : The collection function returns the sequence of nodes and/or json items
 : that belong to the collection identified by the given name.
 :
 : @param $name The name of the collection.
 : @param $skip The number of collection items to skip.
 :
 : @return The sequence contained in the given collection.
 :
 : @error zerr:ZDDY0003 If available collections does not provide a mapping
 :        for the expanded QName $name.
 :
 :)
declare function
dml:collection($name as xs:QName, $skip as xs:integer) as item()* external;


(:~
 : The collection-name function returns the name of the collection the given
 : item (node or json item) belongs to.
 :
 : @param $item The item for which to get the name of the collection
 : @return The result of this function is a QName which identifies the collection
 :         to which the given item belongs to.
 :
 : @error zerr:ZDDY0011 if the given item does not belong to a collection.
 :
 :)
declare function dml:collection-name($item as item()) as xs:QName external;


(:~
 : The index-of function returns the position of the given item (node or 
 : json item) within its containing the collection.
 :
 : @param $item The item to retrieve the index from.
 :
 : @return Returns the position as xs:integer of the given item in the collection.
 :
 : @error zerr:ZDDY0011 if the item is not contained in any collection.
 :
 :)
declare function dml:index-of($item as item()) as xs:integer external;
