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

#include "common/shared_types.h"

namespace zorba { namespace store {

class Collection : public SimpleRCObject
{
public:
  virtual ~Collection() {}

  /**
   * Returns the URI of the collection
   * @return URI
   */
  virtual Item_t getUri() = 0;

  /**
   * Reads the whole Collection from beginning to end; it is allowed to have
   * several concurrent iterators on the same Collection.
   * 
   * @param idsNeeded whether the returned items contain ids, e.g. for sorting
   * @return Iterator which iterates over the complete Collection
   * 
   * Ids == false is likely to be faster. 'idsNeeded' should only be set to
   * true if clients wants to sort or compare the items or sub-items generated
   * from the returned iterator.
   */
  virtual Iterator_t getIterator(bool idsNeeded) = 0;

  /**
   * Inserts into the collection an xml document or fragment given as text via
   * an input stream.
   *
   * @param stream The stream providing the data to insert (e.g. from a file).
   * @return The root node of the xml document or fragment.
   */
  virtual Item_t addToCollection(std::istream& stream) = 0;

  /**
   * Inserts into the collection an xml document or fragment given as text via
   * an input stream.
   * The document is lazy loaded. The stream will be freed by Zorba when finished.
   *
   * @param stream The stream providing the data to insert (e.g. from a file). 
   * Is allocated by user and freed by Zorba
   * @return The root node of the xml document or fragment.
   */
  virtual Item_t addToCollection(std::istream* stream) = 0;

  /**
   * Inserts a node to the collection.
   *
   * @param node The node to insert
   */
  virtual void addToCollection(const Item* node) = 0;

  /**
   * Inserts to the collection the set of nodes returned by the given iterator.
   *
   * @param nodeIter The iterator which produces the nodes to insert
   */
  virtual void addToCollection(Iterator* nodeIter) = 0;
		
  /**
   * Removes a node from the collection.
   *
   * @param node to be removed
   */
  virtual void removeFromCollection(const Item* node) = 0;
};

} // namespace store
} // namespace zorba
#endif
