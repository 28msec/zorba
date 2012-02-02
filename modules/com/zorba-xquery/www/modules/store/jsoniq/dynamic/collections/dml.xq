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
 : This modules provides a set of functions to modify a collection and retrieve the
 : items contained in a particular collection. Collections that are accessed by the
 : functions of this module may contain any mix of XML nodes, JSON objects, or
 : JSON arrays. The term "structured item" is used in this module to refer to an
 : XML node, JSON object, or JSON array.
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
 : @project store/jsoniq/collections/dynamic
 :)
module namespace dml = "http://www.zorba-xquery.com/modules/store/jsoniq/dynamic/collections/dml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";

declare option ver:module-version "1.0";
declare option ver:zorba-version "2.1";

(:~
 : The insert-nodes-first function is an updating function that inserts copies of the
 : given structured items at the beginning of the collection.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update
 :         list which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function dml:insert-nodes-first(
  $name as xs:QName,
  $content as structured-item()*) external;

(:~
 : The insert-nodes-last function is an updating function that inserts copies of the
 : given structured items at the end of the collection.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 :)
declare updating function dml:insert-nodes-last(
  $name as xs:QName,
  $content as structured-item()*) external;


(:~
 : The insert-nodes-before function is an updating function that inserts copies
 : of the given structured items into a collection at the position directly 
 : preceding the given target item.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The item in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of structured items whose copies should be 
 :        added to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target item is not contained in the collection.
 :
 :)
declare updating function dml:insert-nodes-before(
  $name as xs:QName,
  $target as structured-item(),
  $content as structured-item()*) external;


(:~
 : The insert-nodes-after function is an updating function that inserts copies
 : of the given structured items into a collection at the position directly 
 : following the given target item.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The structured item in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is an empty XDM instance and a pending update list
 :         which, once applied, inserts the items into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 : @error zerr:ZDDY0011 if the target item is not contained in the collection.
 :
 :)
declare updating function dml:insert-nodes-after(
  $name as xs:QName,
  $pos as structured-item(),
  $content as structured-item()*) external;


(:~
 : This function does the same as the insert-nodes function except
 : it immediately applies the resulting pending updates and returns the
 : structured items that have been inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-first
 :
 :)
declare %ann:sequential function dml:apply-insert-nodes-first(
  $name as xs:QName,
  $content as structured-item()*) as structured-item()* external;


(:~
 : This function does the same as the insert-nodes-last function except
 : it immediately applies the resulting pending updates and returns the
 : structured items that have been inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-last
 :
 :)
declare %ann:sequential function dml:apply-insert-nodes-last(
  $name as xs:QName,
  $content as structured-item()*) as structured-item()* external;


(:~
 : This function does the same as the insert-nodes-before function except
 : it immediately applies the resulting pending updates and returns the
 : structured items that have been inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The structured item in the collection before which the $content
 :        sequence should be inserted.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-before
 :
 :)
declare %ann:sequential function dml:apply-insert-nodes-before(
  $name as xs:QName,
  $target as structured-item(),
  $content as structured-item()*) as structured-item()* external;


(:~
 : This function does the same as the insert-nodes-after function except
 : it immediately applies the resulting pending updates and returns the
 : structured items that have been inserted.
 :
 : @param $name The name of the collection to which the items should be added.
 : @param $target The structured item in the collection after which the $content
 :        sequence should be inserted.
 : @param $content The sequences of structured items whose copies should be added
 :        to the collection.
 :
 : @return The result of the function is the sequence of items that have been
 :         inserted into the collection.
 :
 : @error zerr:ZDDY0003 if the collection identified by $name is not available.
 :
 : @see dml:insert-nodes-after
 :
 :)
declare %ann:sequential function dml:apply-insert-nodes-after(
  $name as xs:QName,
  $pos as structured-item(),
  $content as structured-item()*) as structured-item()* external;


(:~
 : The delete-nodes function is an updating function that deletes zero of more
 : structured items from a collection. 
 :
 : @param $target the structured items in the collection that should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the items from their collections.
 :
 : @error zerr:ZDDY0011 if any items in the $target sequence is not a member of
 :        a collection or not all items of the $target sequence belong to the 
 :        same collection.
 :)
declare updating function dml:delete-nodes($target as structured-item()*) external;


(:~
 : The delete-node-first function is an updating function that deletes the
 : first item from a collection.
 :
 : @param $name The name of the collection from which the first item should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the first item from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain any item.
 :
 :)
declare updating function dml:delete-node-first($name as xs:QName) external;


(:~
 : The delete-nodes-first function is an updating function that deletes the
 : first n items from a collection.
 :
 : @param $name The name of the collection from which the first items should be deleted.
 : @param $number The number of items that should be removed from the beginning of
 :        the collection.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the items from the collection.
 :
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of items.
 :
 :)
declare updating function dml:delete-nodes-first(
  $name as xs:QName,
  $number as xs:integer) external;


(:~
 : The delete-node-last function is an updating function that deletes the
 : last item from a collection.
 :
 : @param $name The name of the collection from which the last item should be deleted.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last item from the collection.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain any item.
 :
 :)
declare updating function dml:delete-node-last($name as xs:QName) external;


(:~
 : The delete-nodes-last function is an updating function that deletes the
 : last n items from an ordered collection.
 :
 : @param $name The name of the collection from which the last items should be deleted.
 : @param $number The number of items to delete.
 :
 : @return The result of this function is an empty XDM instance and a pending update
 :         list which, once applied, deletes the last n items.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the expanded QName $name.
 : @error zerr:ZDDY0011 if the collection doesn't contain the given number of items.
 :
 :)
declare updating function dml:delete-nodes-last(
  $name as xs:QName,
  $number as xs:integer) external;


(:~
 : The index-of function returns the index of the given structured item in 
 : the collection.
 :
 : @param $item The structured item to retrieve the index of.
 :
 : @return Returns the position as xs:integer of the given item in the collection.
 :
 : @error zerr:ZDDY0011 if item is not contained in any collection.
 :
 :)
declare function dml:index-of($item as structured-item()) as xs:integer external;


(:~
 : The collection function returns the sequence of structured items of the 
 : collection identified by the given name.
 :
 : @param $name The name of the collection.
 :
 : @return The sequence contained in the given collection.
 :
 : @error zerr:ZDDY0009 If available collections does not provide a mapping
 :        for the expanded QName $name.
 :
 :)
declare function dml:collection($name as xs:QName) as structured-item()* external;


(:~
 : This function returns the name of the collection the given structured item
 : belongs to.
 :
 : @param $item The item for which to get the name of the collection
 : @return The result of this function is a QName which identifies the collection
 :         to which the given item belongs to.
 :
 : @error zerr:ZDDY0011 if the given item does not belong to a collection.
 :
 :)
declare function dml:collection-name($item as structured-item()) as xs:QName external;
