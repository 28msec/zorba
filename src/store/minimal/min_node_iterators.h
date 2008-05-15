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
#ifndef ZORBA_MINIMAL_STORE_NODE_ITERATORS
#define ZORBA_MINIMAL_STORE_NODE_ITERATORS

#include "store/api/iterator.h"
#include "common/shared_types.h"
#include "store/minimal/min_ordpath.h"
#include "store/minimal/shared_types.h"
#include "store/util/hashset_item_handle.h"

namespace zorba { namespace store {


/*******************************************************************************
  This iterator is used during the getChildren() method to set the parent
  pointer and the nodeid in each child node of an element or document node.

  theParentNode : The element or doc node whose children are being retrieved.
  theCurrentPos : The next child to be retrieved.
********************************************************************************/
class ChildrenIterator : public Iterator
{
protected:
  XmlNode_t           theParentNode;

  unsigned long       theNumChildren;
  unsigned long       theCurrentPos;

public:
  ChildrenIterator(XmlNode* parent);

  void open();
  Item_t next();
  void reset();
  void close();
};

class ChildrenIteratorLazy : public Iterator
{
protected:
  XmlNode_t           theParentNode;

  //unsigned long       theNumChildren;
  unsigned long       theCurrentPos;

public:
  ChildrenIteratorLazy(XmlNode* parent);

  void open();
  Item_t next();
  void reset();
  void close();
};

/*******************************************************************************
  This iterator is used during the getAttributes() method to set the parent
  pointer and the nodeid in each attribute node of an element node.

  theParentNode : The element node whose attributes are being retrieved.
  theCurrentPos : The next attribute to be retrieved.

********************************************************************************/
class AttributesIterator : public Iterator
{
protected:
  ElementNode_t       theParentNode;

  unsigned long       theNumAttributes;
  unsigned long       theCurrentPos;

public:
  AttributesIterator(ElementNode* parent);

  void open();
  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used to eliminated duplicate nodes in the multiset of nodes
  produced by another iterator.

  theInput   : input iterator
  theNodeSet : A hash-based set used to do the duplicate elimination. The
               elimination is done based on the values of the pointers that
               point to the input nodes.
********************************************************************************/
class StoreNodeDistinctIterator : public Iterator
{
protected:
  Iterator_t         theInput;
  ItemHandleHashSet  theNodeSet;

public:
  StoreNodeDistinctIterator(Iterator* input) 
    :
    theInput(input),
    theNodeSet(1024, false)
  {
  }

  virtual ~StoreNodeDistinctIterator() { close(); }

  void open();
  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This is an extension to StoreNodeDistinctIterator which allows atomic items 
  in the received sequences. The received sequences must contain nodes or atomic
  items, but not a mixture. In case of atomic items, the output sequences
  is equivalent to the input sequence, else, the same operations as in
  StoreNodeDistinctIterator are applied.
********************************************************************************/
class StoreNodeDistinctOrAtomicIterator : public StoreNodeDistinctIterator
{
protected:
  bool theAtomicMode;
  bool theNodeMode;

public:
  StoreNodeDistinctOrAtomicIterator(Iterator* aInput)
    :
    StoreNodeDistinctIterator(aInput),
    theAtomicMode(false),
    theNodeMode(false)
  {
  }

  Item_t next(); 

  void reset() 
  {
    theNodeMode = theAtomicMode = false;
    StoreNodeDistinctIterator::reset(); 
  }

  void close() { StoreNodeDistinctIterator::close(); }
};


/*******************************************************************************
  This iterator is used to sort by document order the nodes produced by another
  iterator.

  theInput  : input iterator
  theNodes  : A vector that stores rchandles to the nodes.
********************************************************************************/
class StoreNodeSortIterator : public Iterator
{
protected:
  class ComparisonFunction
  {
  protected:
    bool theAscending;

  public:
    ComparisonFunction(bool asc = true) : theAscending(asc) { }

    bool operator()(const XmlNode* n1, const XmlNode* n2) const
    {
      return (theAscending ?
              n1->getTreeId() < n2->getTreeId() ||
              n1->getTreeId() == n2->getTreeId() &&
              n1->getOrdPath() < n2->getOrdPath()
              : 
              n1->getTreeId() > n2->getTreeId() ||
              n1->getTreeId() == n2->getTreeId() &&
              n1->getOrdPath() > n2->getOrdPath());
    }
  };

protected:
  Iterator_t              theInput;
  bool                    theAscendant;
  bool                    theDistinct;

  std::vector<XmlNode*>   theNodes;
  long                    theCurrentNode;

public:
  StoreNodeSortIterator(
        const Iterator_t& input,
        bool              ascendant,
        bool              distinct)
    :
    theInput(input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theCurrentNode(-1)
  {
  }

  virtual ~StoreNodeSortIterator() { close(); }

  void open();
  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This is an extension to StoreNodeSortIterator which allows atomic items 
  in the received sequences. The received sequences must contain nodes are atomic
  items, but not a mixture. In case of atomic items, the output sequences
  is equivalent to the input sequence, else, the same operations as in
  StoreNodeSortIterator are applied.
********************************************************************************/
class StoreNodeSortOrAtomicIterator : public StoreNodeSortIterator
{
protected:
  bool theAtomicMode;
  bool theNodeMode;

public:
  StoreNodeSortOrAtomicIterator(const Iterator_t& aInput, bool aAsc, bool aDistinct)
    :
    StoreNodeSortIterator(aInput, aAsc, aDistinct),
    theAtomicMode(false),
    theNodeMode(false)
  {
  }

  Item_t next();

  void reset() 
  {
    theNodeMode = theAtomicMode = false;
    StoreNodeSortIterator::reset(); 
  }

  void close() { StoreNodeSortIterator::close(); }
};


} // namespace store
} // namespace zorba

#endif
