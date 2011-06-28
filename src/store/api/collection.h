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
   * Get the node at the given position in the collection.
   * 
   * @param  aPosition The position of the node in the collection. 
   * @return The node at the given position, or NULL if the position is
   *         >= than the number of nodes in the collection.
   */
  virtual Item_t nodeAt(ulong aPosition) = 0;

  /**
   * Check if a given root node belongs to this collection, and if so return
   * its position within the collection.
   *
   * @param  aNode The node whose position we are looking for.
   * @param  aPosition The position of the node within the collection, if the
   *         node is indeed in the collection.
   * @return True if the node is in the collection; false otherwise.
   */
  virtual bool findNode(const Item* aNode, ulong& position) const = 0;

  /**
   * Returns true if the collection is dynamic or static
   */
  virtual bool isDynamic() const = 0;

  /**
   * Returns true if the collection is constant, false otherwise
   */
  virtual bool isConst() const = 0;

  /**
   * Returns true if the collection is append-only, false otherwise
   */
  virtual bool isAppendOnly() const = 0;

  /**
   * Returns true if the collection is a queue (fifo), false otherwise
   */
  virtual bool isQueue() const = 0;

  /**
   * Returns true if the collection is mutable, false otherwise
   */
  virtual bool isMutable() const = 0;

  /**
   * Returns true if the collection is ordered, false otherwise
   */
  virtual bool isOrdered() const = 0;

  /**
   * Returns true if the nodes in a collection
   * cannot be modified, false otherwise
   */
  virtual bool areNodesReadOnly() const = 0;

public:
  // Properties of a collection
  // They are specified when the collection is created
  // see PUL::addCreateCollection
  enum Properties
  {
    // Collection update mode
    coll_const = 1,
    coll_append_only = 2,
    coll_queue = 4,
    coll_mutable = 8,

    // Collection ordering
    coll_ordered = 16,
    coll_unordered = 32,

    // properties of nodes in a collection
    node_read_only = 64,
    node_mutable = 128
  };
};

} // namespace store
} // namespace zorba
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
