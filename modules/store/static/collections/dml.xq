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
 : This module is part of
 : <a href="../zorba/xqddf.html">Zorba's XQuery Data Definition Facility</a>.
 : All the collections managed by this module have to be pre-declared in the
 : prolog of a module.
 : Please refer to the
 : <a href="../zorba/data_lifecycle.html">general documentation</a>
 : for more information and examples.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../zorba/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://zorba.io/modules/store/static/collections/ddl
 : @see http://zorba.io/modules/store/static/indexes/ddl
 : @see http://zorba.io/modules/store/static/indexes/dml
 : @see http://zorba.io/modules/store/static/integrity-constraints/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/errors
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Collections/Static Data Manipulation
 :)
module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

declare namespace an = "http://zorba.io/annotations";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Gets the sequence of nodes or JSON items from a collection.
 :
 : @param $name The name of the collection.
 : @return The seqnence of items from the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare function cdml:collection( $name as xs:QName )
  as item()* external;

(:~
 : Gets the sequence of nodes or JSON items from a collection.
 :
 : @param $name The name of the collection.
 : @param $skip The initial number of items to skip.
 : @return The (sub)sequence of items from the collection.
 :
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare function cdml:collection( $name as xs:QName, $skip as xs:integer )
  as item()* external;

(:~
 : Gets the sequence of items (nodes or JSON items) from a collection.
 : The parameters <code>$start</code> and <code>$skip</code> can be used to
 : skip over some items at the beginning of the collection.
 : If both are given, both are applied:
 : first <code>$start</code> to skip to the referenced item
 : and then <code>$skip</code> to skip that additional number of items.
 :
 : @param $name The name of the collection.
 : @param $start The reference to the first item to return.
 : @param $skip The number of additional items to skip.
 : @return The sub-sequence from the collection.
 : @error zerr:ZAPI0028 If the given URI is not a valid node position computed
 : by the <code>np:node-position</code> function.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZSTR0066 if <code>$start</code> does not reference a node from
 : the collection.
 :)
declare function cdml:collection( $name as xs:QName, 
                                  $start as xs:anyURI,
                                  $skip as xs:integer )
  as item()* external;

(:~
 : Inserts copies of the given items (nodes or JSON items) into a collection.
 : Note that the insertion position of the items in the collection is not
 : defined.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 :
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is append-only, const, or queue.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 :)
declare updating function cdml:insert( $name as xs:QName,
                                       $content as item()* )
  external;

(:~
 : The insert-after function is an updating function that inserts copies of the
 : given items (nodes or JSON items) into a collection at the position 
 : directly following the given target item.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const, append-only, or queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @error zerr:ZDDY0011 if <code>$target</code> is not a node that is contained
 : in the collection.
 :)
declare updating function cdml:insert-after( $name as xs:QName,
                                             $target as item(),
                                             $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items) into a collection at
 : the position directly preceding the given target item.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection before which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const, append-only, or queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @error zerr:ZDDY0011 if <code>$target</code> is not an item that is
 : contained in the collection.
 :)
declare updating function cdml:insert-before( $name as xs:QName,
                                              $target as item(),
                                              $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items) at the beginning of
 : a collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is append-only, const, or queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 :)
declare updating function cdml:insert-first( $name as xs:QName,
                                             $content as item()* )
  external;

(:~
 : Inserts copies of the given items (nodes or JSON items) at the end of a
 : collection.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of itemss whose copies to insert.
 : @return An empty XDM instance and a pending update list that, once applied,
 : inserts the items into the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 :)
declare updating function cdml:insert-last( $name as xs:QName,
                                            $content as item()* )
  external;

(:~
 : This function does the same thing as <code>insert()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is append-only, const, or queue.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @see cdml:insert
 :)
declare %an:sequential function cdml:apply-insert( $name as xs:QName,
                                                   $content as item()* )
  as item()* external;

(:~
 : This function does the same thing as <code>insert-first()</code> except it
 : immediately applies the resulting pending updates and returns the items that
 : have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $content The sequence of items whose copies to insert.
 : @return The Sequence of items that have been inserted.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection $name is append-only, const, or
 : queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @see cdml:insert-first
 :)
declare %an:sequential function cdml:apply-insert-first( $name as xs:QName,
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
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @see cdml:insert-last
 :)
declare %an:sequential function cdml:apply-insert-last( $name as xs:QName,
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
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection $name is const, append-only, or
 : queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @error zerr:ZDDY0011 if <code>$target</code> is not an item that is
 : contained in the collection.
 : @see cdml:insert-before
 :)
declare %an:sequential function cdml:apply-insert-before( $name as xs:QName,
                                                          $target as item(),
                                                          $content as item()* )
  as item()* external;

(:~
 : This function does the same thing as the <code>insert-after()</code>
 : function except it immediately applies the resulting pending updates and
 : returns the items that have been inserted.
 :
 : @param $name The name of the collection to insert into.
 : @param $target The item in the collection after which <code>$content</code>
 : will be inserted.
 : @param $content The sequence of items whose copies to insert.
 : @return The sequence of items that have been inserted.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const, append-only, or queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type as specified in the collection declaration according to the rules for
 : SequenceType Matching.
 : @error zerr:ZDDY0011 if <code>$target</code> is not in the collection.
 : @see cdml:insert-after
 :)
declare %an:sequential function cdml:apply-insert-after( $name as xs:QName,
                                                         $pos as item(),
                                                         $content as item()* )
  as item()* external;

(:~
 : Deletes items (nodes or JSON items) from a collection.
 :
 : @param $items The items in the collection to delete.
 :
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the items from their collections.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const, append-only, or queue.
 : @error zerr:ZDDY0011 if any item in <code>$items</code> is not a member of a
 : collection or not all items belong to the same collection.
 :)
declare updating function cdml:delete( $items as item()* )
  external;

(:~
 : Deletes the first item from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the first item from the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const or append-only.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function cdml:delete-first( $name as xs:QName )
  external;

(:~
 : Deletes the first <i>N</i> items from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of items to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the items from the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const or append-only.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function cdml:delete-first( $name as xs:QName,
                                             $number as xs:integer )
  external;

(:~
 : Deletes the last item from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the last item from the collection.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0006 if the collection is const, append-only, or queue.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDDY0011 if the collection is empty.
 :)
declare updating function cdml:delete-last( $name as xs:QName )
  external;

(:~
 : Deletes the last <i>N</i> items from a collection.
 :
 : @param $name The name of the collection to delete from.
 : @param $number The number of items to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the items.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 : @error zerr:ZDDY0012 if the collection is unordered.
 : @error zerr:ZDDY0011 if the collection contains less than
 : <code>$number</code> items.
 :)
declare updating function cdml:delete-last( $name as xs:QName,
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
 : @error zerr:ZDDY0001 if the collection to which <code>$target</code> belongs
 : is not declared.
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
 : @error zerr:ZDTY0001 if <code>$content</code> does not match the expected
 : type (as specified in the collection declaration) according to the rules for
 : SequenceType Matching.
 :)
declare updating function cdml:edit( $target as item(),
                                     $content as item() )
  external;

(:~
 : Deletes the entire contents of collection.
 : Please note that applying this function can not be undone in case
 : an error happens during the application of the containing PUL.
 :
 : @param $name The name of the collection whose content to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the nodes.
 : @error zerr:ZDDY0001 if the collection is not declared.
 : @error zerr:ZDDY0003 if the collection is not available.
 :)
declare updating function cdml:truncate( $name as xs:QName )
  external;

(:~
 : Gets the name of the collection the given item (node or JSON item) belongs
 : to.
 :
 : @param $item The item for which to get the name of its collection.
 : @return The name of the collection to which the given item belongs.
 : @error zerr:ZDDY0011 if <code>$item</code> does not belong to a collection.
 :)
declare function cdml:collection-name( $item as item() )
  as xs:QName external;

(:~
 : Gets the position of the given item (node or JSON item) within its
 : collection.
 :
 : @param $item The item to get the index of.
 : @return The position of <code>$item</code> in its collection.
 : @error zerr:ZDDY0011 if <code>$item</code> does not belong to a collection.
 : @error zerr:ZDDY0012 if the collection is unordered.
 :)
declare function cdml:index-of( $item as item() )
  as xs:integer external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
