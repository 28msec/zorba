/*
 * Copyright 2006-2012 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef API_COLLECTION_H
#define API_COLLECTION_H

/** \brief A Collection is a persistent sequence of node items.
 *
 * Instances of this class can be used to modify or retrieve the contents
 * of a collection.
 *
 * The variable aNodes passed to any of the insert functions is evaluated
 * as though it were an enclosed expression in an element constructor.
 * The result of this step is a sequence of nodes to be inserted into the collection.
 *
 */
class Collection
{
private:
  zorba::Collection_t theCollection;

public:
  Collection(const Collection& aMgr) : theCollection(aMgr.theCollection) {}
  Collection(zorba::Collection* aMgr) : theCollection(aMgr) {}

  /**
   * This function returns the sequence of nodes of the collection.
   *
   * @return The sequence contained in the given collection.
   *
   */
  ItemSequence contents();

  /**
   * This function deletes the first node from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  void deleteNodeFirst();
  
  /**
   * This function deletes the last node from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  void deleteNodeLast();

  /**
   * This function deletes zero of more nodes from a collection. 
   *
   * @param aNodes the nodes in the collection that should be deleted.
   *
   * @throw XDDY0011 if any nodes in the given sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  void deleteNodes(const ItemSequence &aNodes );

  /**
   * This function deletes the n first nodes from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  void deleteNodesFirst(unsigned long aNumNodes );

  /**
   * This function deletes the n last nodes from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  void deleteNodesLast(unsigned long aNumNodes );

  /**
   * \brief Get the name of the collection.
   *
   * @return The name of the collection.
   */
  Item getName();

  /**
   * Retrieves the sequence type for this (static declared) collection.
   *
   * @return the sequence type for the said collection, or 0
   *  if this collection is not statically declared.
   *
   * @see isStatic()
   */
  TypeIdentifier getType();

  /**
   * This function returns the index of the given node in the collection.
   *
   * @param aNode The node to retrieve the index from.
   *
   * @return Returns the position of the given node in the collection.
   *
   * @throw XDDY0011 if node is not contained in any collection.
   *
   */
  long long indexOf(const Item &aNode );

  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly following the
   * given target node.
   *
   * @param aTarget the node in the collection after which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XDDY0011 if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  void insertNodesAfter(const Item &aTarget, const ItemSequence &aNodes );

  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly preceding the
   * given target node.
   *
   * @param aTarget the node in the collection before which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XDDY0011 if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  void insertNodesBefore(const Item &aTarget, const ItemSequence &aNodes );

  /**
   * This function inserts copies of the
   * given nodes at the beginning of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
  void insertNodesFirst(const ItemSequence &aNodes );

  /**
   * This function inserts copies of the
   * given nodes at the end of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
  void insertNodesLast(const ItemSequence &aNodes );

  /**
   * The function checks if this collection has been statically declared.
   *
   * @return true if the collection is a static collection, false otherwise.
   */
  bool isStatic();

  //void  registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler );
};

#endif