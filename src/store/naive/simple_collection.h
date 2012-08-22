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
#include "store/api/collection.h"
#include "tree_id.h"
#include "tree_id_generator.h"

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
  friend class UpdTruncateCollection;

public:
  class CollectionIter : public store::Iterator
	{
  protected:
    rchandle<SimpleCollection>              theCollection;
    checked_vector<store::Item_t>::iterator theIterator;
    checked_vector<store::Item_t>::iterator theEnd;
    bool                                    theHaveLock;
    xs_integer                              theSkip;

  public:
    CollectionIter(SimpleCollection* collection, const xs_integer& aSkip);

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

  TreeIdGenerator                      * theTreeIdGenerator;

  const std::vector<store::Annotation_t> theAnnotations;

  store::Item_t                          theNodeType;

  SYNC_CODE(Latch                        theLatch;)

  // default constructor added in order to allow subclasses to instantiate
  // a collection without name
  SimpleCollection();

public:
  SimpleCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool isDynamic = false);

  virtual ~SimpleCollection();
  
  /********************** All these methods implement the **********************
  ***************** zorba::simplestore::Collection interface ******************/

  ulong getId() const { return theId; }

  const store::Item* getName() const { return theName.getp(); }

  xs_integer size() const { return xs_integer( theXmlTrees.size() ); }

  bool isDynamic() const { return theIsDynamic; }

  void getAnnotations(std::vector<store::Annotation_t>& annotations) const;

  TreeId createTreeId();

  store::Iterator_t getIterator(const xs_integer& aSkip);

  void addNode(store::Item* node, xs_integer position = xs_integer(-1));

  xs_integer addNodes(
      std::vector<store::Item_t>& nodes,
      const store::Item* targetNode,
      bool before);

  bool removeNode(store::Item* node, xs_integer& pos);

  bool removeNode(xs_integer position);

  void removeAll();

  xs_integer removeNodes(xs_integer position, xs_integer num);

  bool findNode(const store::Item* node, xs_integer& position) const;

  store::Item_t nodeAt(xs_integer position);

  void adjustTreePositions();
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
