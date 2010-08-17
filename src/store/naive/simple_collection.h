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
#ifndef ZORBA_STORE_SIMPLE_COLLECTION
#define ZORBA_STORE_SIMPLE_COLLECTION

#include "store/naive/shared_types.h"

#include "store/api/iterator.h"
#include "store/api/collection.h"

#include "zorbautils/latch.h"
#include "zorbautils/checked_vector.h"


namespace zorba { namespace simplestore {


/*******************************************************************************
  theId          : An internally generated unique id.
  theName        : The user provided qname of the collection.
  theXmlTrees    : The set of xml tress comprising this collection. Implemented
                   as vector of rchandle to nodes.
  theTreeCounter : Incremented every time a new tree is added to the collection.
                   The current value of the counter is then assigned as the id
                   the new tree.
********************************************************************************/
class SimpleCollection : public store::Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public store::Iterator
	{
  protected:
    rchandle<SimpleCollection>              theCollection;
    checked_vector<store::Item_t>::iterator theIterator;
    bool                                    theHaveLock;

  public:
    CollectionIter(SimpleCollection* collection);

    ~CollectionIter();

    void open();
    bool next(store::Item_t& result);
    void reset();
    void close();
  };


protected:
  ulong                         theId;
  store::Item_t                 theName;
  checked_vector<store::Item_t> theXmlTrees;

  ulong                         theTreeCounter;

  SYNC_CODE(Latch               theLatch;)

  SimpleCollection();

public:
  SimpleCollection(store::Item_t& aName);

  virtual ~SimpleCollection();

  virtual ulong getId() const { return theId; }

  const store::Item* getName() const { return theName.getp(); }

  ulong size() const { return theXmlTrees.size(); }

  virtual ulong createTreeId() { return theTreeCounter++; }

  store::Iterator_t getIterator();

  store::Item_t loadDocument(
        std::istream& stream,
        long position = -1);

  void addNode(
        store::Item* node,
        long position = -1);

  virtual ulong addNodes(
        std::vector<store::Item_t>& nodes,
        const store::Item* aTargetNode,
        bool before);

  virtual bool removeNode(store::Item* node, ulong& pos);

  virtual bool removeNode(ulong position);

  virtual ulong removeNodes(ulong position, ulong num);

  bool findNode(const store::Item* node, ulong& position) const;

  store::Item_t nodeAt(ulong position);

  virtual void adjustTreePositions();

  virtual void getIndexes(std::vector<store::Index*>& indexes);

  /**
     Returns active integrity constraints referencing this collection.
  */
  virtual void getActiveICs(std::vector<store::IC*>& ics);
};

} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
