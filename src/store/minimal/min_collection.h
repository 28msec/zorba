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

namespace zorba { namespace storeminimal {

/*******************************************************************************

********************************************************************************/
class SimpleCollection : public store::Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public store::Iterator
	{
  private:
    rchandle<SimpleCollection>           theCollection;
    std::set<store::Item_t>::iterator    theIterator;
    bool                          theHaveLock;

  public:
    CollectionIter(SimpleCollection* collection);

    ~CollectionIter();

    void open();
    bool next(store::Item_t& result);
    void reset();
    void close();
  };


protected:
  store::Item_t               theUri;
  std::set<store::Item_t>     theXmlTrees;
  SYNC_CODE(Latch      theLatch;)

public:
  SimpleCollection(store::Item_t& uri);
  virtual ~SimpleCollection();

  store::Item* getUri() { return theUri; }

  ulong size() const { return theXmlTrees.size(); }

  store::Iterator_t getIterator(bool idsNeeded);

  store::Item_t addToCollection(std::istream& stream);
  store::Item_t addToCollection(std::istream* stream);
  void addToCollection(const store::Item* node);
  void addToCollection(store::Iterator* nodes);

  void removeFromCollection(const store::Item* node);  
};

} // namespace storeminimal
} // namespace zorba

#endif
