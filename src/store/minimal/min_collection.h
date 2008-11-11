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
#include "zorbautils/checked_vector.h"

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
    checked_vector<store::Item_t>::iterator theIterator;
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
  store::Item_t                 theUri;
  checked_vector<store::Item_t> theXmlTrees;
  SYNC_CODE(Latch               theLatch;)

public:
  SimpleCollection(store::Item_t& uri);

  virtual ~SimpleCollection();

  store::Item* getUri() const { return theUri.getp(); }

  ulong size() const { return theXmlTrees.size(); }

  store::Iterator_t getIterator(bool idsNeeded);

  store::Item_t loadDocument(std::istream& stream, const long position = -1);
  store::Item_t loadDocument(std::istream* stream, const long position = -1);

  void addNode(const store::Item* node, const long position = -1);
  void addNode(const store::Item* node, const store::Item* aTargetNode, bool before);

  void addNodes(store::Iterator* nodes, const long position = -1);

  void removeNode(const store::Item* node);
  void removeNode(const long position = -1);

  store::Item_t nodeAt(const long position);
  long indexOf(const store::Item* node);

protected:
  int
  nodePositionInCollection(store::Item* newNode);
};

} // namespace storeminimal
} // namespace zorba

#endif
