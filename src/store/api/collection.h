/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#ifndef ZORBA_STORE_COLLECTION_H
#define ZORBA_STORE_COLLECTION_H

#include <zorba/config.h>
#include "store/api/shared_types.h"

namespace zorba { namespace store {


class Collection : public RCObject
{
protected:
  SYNC_CODE(mutable RCLock theRCLock;)

public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  long* getSharedRefCounter() const { return NULL; } 

public:
  virtual ~Collection() {}

  /**
   * Returns the Name of the collection.
   *
   * @return Name
   */
  virtual const Item* getName() const = 0;

  /**
   * Returns the number of items in the collection.
   */
  virtual unsigned long size() const = 0;

  /**
   * Get an iterator to iterate over the nodes of the collection.
   *
   * It is allowed to have several concurrent iterators on the same Collection,
   * but each iterator should be used by a single thread only.
   */
  virtual Iterator_t getIterator() = 0;

  /**
   * Loads and inserts into the collection an xml document or fragment given
   * as text via an input stream. 
   *
   * @param stream The stream providing the data to insert (e.g. from a file).
   * @param position The position where the node will be inserted at. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * document will be appended at the end.
   * @return The root node of the xml document or fragment.
   */
  virtual Item_t loadDocument(std::istream& stream, long position = -1) = 0;

  /**
   * Loads and inserts into the collection an xml document or fragment given
   * as text via an input stream. The document is lazy loaded. The stream 
   * will be freed by Zorba when finished.
   *
   * @param stream The stream providing the data to insert (e.g. from a file). 
   * Is allocated by user and freed by Zorba.
   * @param position The position where the node will be inserted at. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * document will be appended at the end.
   * @return The root node of the xml document or fragment.
   */
  virtual Item_t loadDocument(std::istream* stream, long position = -1) = 0;

  /**
   * Inserts a given node to the collection. The node must be the root of an
   * xml tree (i.e., it must not have a parent).
   *
   * @param node The node to insert.
   * @param position The position where the node will be inserted at. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * node will be appended at the end.
   */
  virtual void addNode(Item* node, long position = -1) = 0;

  /**
   * Adds a given node to the Collection before or after the targetNode. The
   * new node must be the root of an xml tree (i.e., it must not have a parent).
   *
   * @param aNode The node to insert.
   * @param aTargetNode The node will be added before or after the target node.
   * @param before If true, the aNode will be inserted before the target node.
   * Otherwise it will be inserted after the target node.
   */
  virtual void
  addNode(Item* aNode, const Item* aTargetNode, bool before) = 0;

  /**
   * Removes a node from the collection.
   *
   * @param node to be removed.
   * @return True if the node was in the collection, false otherwise.
   */
  virtual bool removeNode(Item* node) = 0;

  /**
   * Removes the node at the given position from the collection.
   *
   * @param position The position of the node that will be removed. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * last node is removed. If the position is past the end of the collection,
   * no node is removed.
   * @return True if a node was removed, i.e. if the position was not past the
   * end of the collection; false otherwise.
   */
  virtual bool removeNode(long position = -1) = 0;

  /**
   * Get the node at the given position in the collection.
   * 
   * @param aPosition The position of the node in the collection. 
   * @return The node at the given position, or NULL if the position is <= 0
   * or > than the number of nodes in the collection.
   */
  virtual Item_t
  nodeAt(long aPosition) = 0;

  /**
   * Check if a given node belongs to this collection, and if so return its
   * position within the collection.
   *
   * @param aNode The node whose position we are looking for.
   * @param aPosition The position of the node within the collection, if the
   *        node is indeed in the collection.
   * @return True if the node is in the collection; false otherwise.
   */
  virtual bool
  findNode(const Item* aNode, ulong& position) const = 0;
};

} // namespace store
} // namespace zorba
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
