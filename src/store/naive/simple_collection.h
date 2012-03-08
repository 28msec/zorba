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

#include "shared_types.h"

#include "collection.h"

#include "store/api/iterator.h"

#include "zorbautils/latch.h"
#include "zorbautils/checked_vector.h"


namespace zorba { namespace simplestore {


/*******************************************************************************
  theId          : An internally generated unique id.
  theName        : The user provided qname of the collection.
  theXmlTrees    : The set of root nodes comprising this collection. Implemented
                   as vector of rchandles to nodes.
  theTreeCounter : Incremented every time a new tree is added to the collection.
                   The current value of the counter is then assigned as the id
                   the new tree.
********************************************************************************/
class SimpleCollection : public Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public store::Iterator
	{
  protected:
    rchandle<SimpleCollection>              theCollection;
    checked_vector<store::Item_t>::iterator theIterator;
    checked_vector<store::Item_t>::iterator theEnd;
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
  ulong                                  theId;
  store::Item_t                          theName;
  checked_vector<store::Item_t>          theXmlTrees;
  bool                                   theIsDynamic;
  bool                                   theIsJSONIQ;

  ulong                                  theTreeCounter;

  const std::vector<store::Annotation_t> theAnnotations;
  store::Item_t                          theNodeType;

  SYNC_CODE(Latch                        theLatch;)

  SimpleCollection();

public:
  SimpleCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool isDynamic = false,
      bool isJSONIQ = false);

  virtual ~SimpleCollection();
  
  /********************** All these methods implement the **********************
  ***************** zorba::simplestore::Collection interface ******************/

  const store::Item* getName() const { return theName.getp(); }

  xs_integer size() const { return theXmlTrees.size(); }

  bool isDynamic() const { return theIsDynamic; }

  bool isJSONIQ() const { return theIsJSONIQ; }

  void getAnnotations(std::vector<store::Annotation_t>& annotations) const;

  store::Iterator_t getIterator();

  void addNode(store::Item* node, xs_integer position = -1);

  bool findNode(const store::Item* node, xs_integer& position) const;

  store::Item_t nodeAt(xs_integer position);

  //
  // The following methods are virtual to allow extension by subclasses
  //

  virtual ulong getId() const { return theId; }

  virtual ulong createTreeId() { return theTreeCounter++; }

  virtual xs_integer addNodes(
        std::vector<store::Item_t>& nodes,
        const store::Item* targetNode,
        bool before);

  virtual bool removeNode(store::Item* node, xs_integer& pos);

  virtual bool removeNode(xs_integer position);

  virtual xs_integer removeNodes(xs_integer position, xs_integer num);

  virtual void adjustTreePositions();
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
