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
#ifndef ZORBA_STORE_MINIMAL_COLLECTION
#define ZORBA_STORE_MINIMAL_COLLECTION

#include <set>
#include "zorbautils/latch.h"
#include "common/common.h"

#include "store/api/iterator.h"
#include "store/api/collection.h"

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
class SimpleCollection : public Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public Iterator
	{
  private:
    SimpleCollection_t            theCollection;
    std::set<Item_t>::iterator    theIterator;
    bool                          theHaveLock;

  public:
    CollectionIter(SimpleCollection* collection);

    ~CollectionIter();

    void open();
    bool next(Item_t& result);
    void reset();
    void close();
  };


protected:
  Item_t               theUri;
  std::set<Item_t>     theXmlTrees;
  SYNC_CODE(Latch      theLatch;)

public:
  SimpleCollection(Item_t& uri);
  virtual ~SimpleCollection();

  Item* getUri() { return theUri; }

  ulong size() const { return theXmlTrees.size(); }

  Iterator_t getIterator(bool idsNeeded);

  Item_t addToCollection(std::istream& stream);
  Item_t addToCollection(std::istream* stream);
  void addToCollection(const Item* node);
  void addToCollection(Iterator* nodes);

  void removeFromCollection(const Item* node);  
};

} // namespace store
} // namespace zorba

#endif
