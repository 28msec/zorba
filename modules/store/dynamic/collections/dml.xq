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
 : This modules provides a set of functions to modify a collection
 : and retrieve the items contained in a particular collection.
 : <p/>
 : Please refer to our documentation for
 : <a href="../zorba/data_lifecycle.html">more information</a>
 : about the lifecycle management and the manipulation of such collections.
 : 
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see http://zorba.io/modules/store/dynamic/collections/ddl
 : @see http://zorba.io/errors
 :
 : @author Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/Dynamic Data Manipulation
 :)
module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace an = "http://zorba.io/annotations";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Inserts copies of the given items (nodes or JSON items)
 : into a collection at the position directly preceding the given target item.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection before which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if <code>$target</code> is not in the collection.
 :)
declare updating function dml:insert-before( $name as xs:QName,
                                             $target as item(),
                                             $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items)
 : at the beginning of the collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function dml:insert-first( $name as xs:QName,
                                            $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items)
 : at the end of the collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function dml:insert-last( $name as xs:QName,
                                           $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items)
 : into a collection at the position directly following the given target item.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if <code>$target</code> is not in the collection.
 :)
declare updating function dml:insert-after( $name as xs:QName,
                                            $pos as item(),
                                            $content as item()* )
  external;

(:~
 : This function does the same thing as <code>insert-first()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-first
 :)
declare %an:sequential function dml:apply-insert-first( $name as xs:QName,
                                                        $content as item()* )
  as item()* external;

(:~
 : This function does the same thing as <code>insert-last()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-last
 :)
declare %an:sequential function dml:apply-insert-last( $name as xs:QName,
                                                       $content as item()* )
  as item()* external;

(:~
 : This function does the same thing as <code>insert-before()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection before which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @see dml:insert-before
 :)
declare %an:sequential function dml:apply-insert-before( $name as xs:QName,
                                                         $target as item(),
                                                         $content as item()* )
  as item()* external;

(:~
 : This function does the same thing as <code>insert-after()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if <code>$target</code> is not in the collection.
 : @see dml:insert-after
 :)
declare %an:sequential function dml:apply-insert-after( $name as xs:QName,
                                                        $target as item(),
                                                        $content as item()* )
  as item()* external;

(:~
 : Gets the sequence of nodes or JSON items from a collection.
 :
 : @param $name The name of the collection.
 : @return The sequence contained in the given collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare function dml:collection( $name as xs:QName )
  as item()* external;

(:~
 : Gets the sequence of items (nodes or JSON items) from a collection.
 :
 : @param $name The name of the collection.
 : @param $skip The number of collection items to skip.
 : @return The sub-sequence contained in the given collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare function dml:collection( $name as xs:QName,
                                 $skip as xs:integer )
  as item()* external;

(:~
 : Gets the sequence of items (nodes or JSON items) from a collection.
 : The parameters <code>$start</code> and <code>$skip</code> can be used to
 : skip over items at the beginning of the collection.
 : If both are given, both are applied: first, <code>$start</code> to skip to
 : that item and then <code>$skip</code> to skip that additional number of
 : items.
 :
 : @param $name The name of the collection.
 : @param $start A reference to the first item to return.
 : @param $skip The additional number of items to skip.
 : @return The sub-sequence from the given collection.
 : @error zerr:ZAPI0028 If the given URI is not a valid node position computed
 : by the <code>np:node-position</code> function.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZSTR0066 If <code>$start</code> does not reference a node from
 : the collection <code>$name</code>.
 :)
declare function dml:collection( $name as xs:QName, 
                                 $start as xs:anyURI,
                                 $skip as xs:integer )
  as item()* external;

(:~
 : Gets the name of the collection the given item (node or JSON item) belongs
 : to.
 :
 : @param $item The item for which to get the name of the collection.
 : @return The name of the collection to which <code>$item</code> belongs.
 : @error zerr:ZDDY0011 if <code>$item</code> does not belong to a collection.
 :)
declare function dml:collection-name( $item as item() )
  as xs:QName external;

(:~
 : Deletes items (nodes or JSON items) from a collection.
 :
 : @param $items The items in the collection to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the items from their collections.
 : @error zerr:ZDDY0011 if any item in <code>$items</code> is not a member of a
 : collection or not all items belong to the same collection.
 :)
declare updating function dml:delete( $items as item()* )
  external;

(:~
 : Deletes the first item from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the first item from the collection.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function dml:delete-first( $name as xs:QName )
  external;

(:~
 : Deletes the first <i>N</i> items from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of items to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the items from the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function dml:delete-first( $name as xs:QName,
                                            $number as xs:integer )
  external;

(:~
 : Deletes the last item from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the last item from the collection.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function dml:delete-last( $name as xs:QName )
  external;

(:~
 : Deletes the last <i>N</i> items from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of items to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the last N items.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function dml:delete-last( $name as xs:QName,
                                           $number as xs:integer )
  external;

(:~
 : Edits the first supplied item so as to make it look exactly like a copy of
 : the second supplied item while retaining its original identity.
 :
 : @param $target The target item to be edited.
 : @param $content The item that serves as an edit goal.
 : @return An empty XDM instance and a pending update list that, once applied,
 : performs the edit.
 : @error zerr:ZDDY0003 if the collection to which <code>$target</code> belongs
 : is not available.
 : @error zerr:ZDDY0006 if the collection to which <code>$target</code> belongs
 : is append-only, const, or queue.
 : @error zerr:ZDDY0017 if <code>$target</code> is not a member of a collection.
 : @error zerr:ZDDY0037 if the collection is append-only.
 : @error zerr:ZDDY0038 if the collection is a queue.
 : @error zerr:ZDDY0039 if <code>$target</code> is not a root.
 : @error zerr:ZDDY0040 if <code>$target</code> cannot be updated to match the
 : content (for example, because the target is a node and the content is an
 : object).
 :)
declare updating function dml:edit( $target as item(),
                                    $content as item() )
  external;

(:~
 : Gets the position of the given item (node or JSON item) within its
 : collection.
 :
 : @param $item The item to get the index of.
 : @return The position of <code>$item</code> in its collection.
 : @error zerr:ZDDY0011 if <code>$item</code> does not belong to a collection.
 :)
declare function dml:index-of( $item as item() )
  as xs:integer external;

(:~
 : Deletes the entire contents of a collection.
 :
 : @param $name The name of the collection whose contents to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the contents.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function dml:truncate( $name as xs:QName )
  external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
