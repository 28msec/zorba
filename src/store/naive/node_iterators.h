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
#ifndef ZORBA_SIMPLE_STORE_NODE_ITERATORS
#define ZORBA_SIMPLE_STORE_NODE_ITERATORS

#include "store/api/iterator.h"
#include "store/naive/shared_types.h"
#include "store/naive/node_items.h"
//#include "store/naive/ordpath.h"

#include "zorbautils/hashfun.h"
#include "zorbautils/hashset.h"


namespace zorba { namespace simplestore {


/*******************************************************************************
  This iterator is used to iterate over the children of a document or element
  node. It implements the interface of a generic iterator, but also offers the
  following additional methods:
 
  - An init method that takes as input a document or element node and
    initializes the iterator so that it will start returning the children of
    this node. The method also takes an optional child parameter; if a child
    is given, the iterator will position itself on that child, so that the next
    next() call will return the right sibling of that child.
  - A next method that returns pointers to the children instead of rchandles.
    These pointers should not be used beyond the lifetime of the ChildrenIterator
    object. 
 
  theParentNode : The element or doc node whose children are being retrieved.
  theCurrentPos : The next child to be retrieved.
  theNumChildren: The number of children.
********************************************************************************/
class ChildrenIteratorImpl : public store::ChildrenIterator
{
protected:
  rchandle<InternalNode>  theParentNode;

  ulong                   theNumChildren;
  ulong                   theInitPos;
  ulong                   theCurrentPos;

public:
  ChildrenIteratorImpl() : theNumChildren(0), theInitPos(0), theCurrentPos(0) { }

  void init(store::Item_t& parent, const store::Item* child = NULL)
  {
    theParentNode.transfer(parent);
    theNumChildren = theParentNode->numChildren();
    theInitPos = 0;

    if (child != NULL && theNumChildren > 0)
    {
      assert(child->getParent() == theParentNode);

      while (theParentNode->getChild(theInitPos++) != child)
      {
        ;
      }
    }
  }


  void init(const store::Item* parent, const store::Item* child = NULL)
  {
    theParentNode = parent;
    theNumChildren = theParentNode->numChildren();
    theInitPos = 0;

    if (child != NULL && theNumChildren > 0)
    {
      assert(child->getParent() == theParentNode);

      while (theParentNode->getChild(theInitPos++) != child)
      {
        ;
      }
    }
  }


  store::Item* next()
  {
    if (theCurrentPos >= theNumChildren) 
      return NULL;

    return theParentNode->getChild(theCurrentPos++);
  }


  void open() { theCurrentPos = theInitPos; }

  void reset() { theCurrentPos = theInitPos; }

  void close() { theCurrentPos = theNumChildren; theParentNode = NULL; }

  bool next(store::Item_t& result);
};


/*******************************************************************************
  This iterator is used to iterate over the children of a document or element
  node in reverse document order. It implements the interface of a generic
  iterator, but also offers the following additional methods:
 
  - An init method that takes as input a document or element node and
    initializes the iterator so that it will start returning the children of
    this node. The method also takes an optional child parameter; if a child
    is given, the iterator will position itself on that child, so that the next
    next() call will return the left sibling of that child.
  - A next method that returns pointers to the children instead of rchandles.
    These pointers should not be used beyond the lifetime of the ChildrenIterator
    object. 
 
  theParentNode : The element or doc node whose children are being retrieved.
  theCurrentPos : The next child to be retrieved.
  theNumChildren: The number of children.
********************************************************************************/
class ChildrenReverseIteratorImpl : public store::ChildrenReverseIterator
{
protected:
  rchandle<InternalNode>  theParentNode;

  ulong                   theNumChildren;
  long                    theInitPos;
  long                    theCurrentPos;

public:
  ChildrenReverseIteratorImpl() 
    :
    theNumChildren(0),
    theInitPos(-1),
    theCurrentPos(-1)
  {
  }

  void init(store::Item_t& parent, const store::Item* child = NULL)
  {
    theParentNode.transfer(parent);
    theNumChildren = theParentNode->numChildren();
    theInitPos = theNumChildren - 1;

    if (child != NULL && theNumChildren > 0)
    {
      assert(child->getParent() == theParentNode);

      while (theParentNode->getChild(theInitPos--) != child)
      {
        ;
      }
    }
  }


  void init(const store::Item* parent, const store::Item* child = NULL)
  {
    theParentNode = parent;
    theNumChildren = theParentNode->numChildren();
    theInitPos = theNumChildren - 1;

    if (child != NULL && theNumChildren > 0)
    {
      assert(child->getParent() == theParentNode);

      while (theParentNode->getChild(theInitPos--) != child)
      {
        ;
      }
    }
  }


  store::Item* next()
  {
    if (theCurrentPos < 0) 
      return NULL;

    return theParentNode->getChild(theCurrentPos--);
  }


  void open() { theCurrentPos = theInitPos; }

  void reset() { theCurrentPos = theInitPos; }

  void close() { theCurrentPos = -1; theParentNode = NULL; }

  bool next(store::Item_t& result);
};


/*******************************************************************************
  This iterator is used during the getAttributes() method to set the parent
  pointer and the nodeid in each attribute node of an element node.

  theParentNode : The element node whose attributes are being retrieved.
  theCurrentPos : The next attribute to be retrieved.

********************************************************************************/
class AttributesIteratorImpl : public store::AttributesIterator
{
protected:
  rchandle<ElementNode>  theParentNode;

  ulong                  theNumAttributes;
  ulong                  theCurrentPos;

public:
  AttributesIteratorImpl() : theNumAttributes(0), theCurrentPos(0) { }

  void init(store::Item_t& parent)
  {
    theParentNode.transfer(parent);
    theNumAttributes = theParentNode->numAttributes();
    theCurrentPos = 0;
  }

  void init(const store::Item* parent)
  {
    theParentNode = parent;
    theNumAttributes = theParentNode->numAttributes();
    theCurrentPos = 0;
  }

  store::Item* next()
  {
    if (theCurrentPos >= theNumAttributes) 
      return NULL;

    AttributeNode* attr =
      reinterpret_cast<AttributeNode*>(theParentNode->getAttr(theCurrentPos));

    while (attr->isHidden())
    {
      theCurrentPos++;

      if (theCurrentPos >= theNumAttributes) 
        return NULL;

      attr = reinterpret_cast<AttributeNode*>(theParentNode->getAttr(theCurrentPos));
    }

    theCurrentPos++;

    return attr;
  }


  void open() { theCurrentPos = 0; }

  void reset() { theCurrentPos = 0; }

  void close() { theParentNode = NULL; }

  bool next(store::Item_t& result);
};


/*******************************************************************************
  A hash-based set container of item pointers, where equality is based on
  object identity (i.e. pointer equality) rather than object value.

  It is used by the NodeDistinctIterator below. 

  NOTE: Although the set uses raw item pointers instead of rchandles, reference
        counting is still done, but done manually (see insert and clear methods)
********************************************************************************/
class ItemPointerHashSet
{
public:

  class CompareFunction
  {
  public:
    static bool equal(const store::Item* t1, const store::Item* t2)
    {
      return t1 == t2;
    }

    static uint32_t hash(const store::Item* t)
    {
      return hashfun::h32((void*)(&t), sizeof(void*), FNV_32_INIT);
    }
  };

private:
  HashSet<store::Item*, CompareFunction>  theSet;

public:
  ItemPointerHashSet(ulong size, bool sync) : theSet(size, sync) { }

  void clear();

  bool find(store::Item* const key) 
  {
    return theSet.find(key); 
  }

  bool insert(store::Item* key) 
  {
    return theSet.insert(key); 
  }
};


/*******************************************************************************
  This iterator is used to eliminated duplicate nodes in the multiset of nodes
  produced by another iterator.

  theInput   : input iterator
  theNodeSet : A hash-based set used to do the duplicate elimination. The
               elimination is done based on the values of the pointers that
               point to the input nodes.
********************************************************************************/
class StoreNodeDistinctIterator : public store::Iterator
{
protected:
  store::Iterator_t   theInput;
  ItemPointerHashSet  theNodeSet;

public:
  StoreNodeDistinctIterator(store::Iterator* input) 
    :
    theInput(input),
    theNodeSet(1024, false)
  {
  }

  virtual ~StoreNodeDistinctIterator() { close(); }

  void open();
  bool next(store::Item_t& result);
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
  StoreNodeDistinctOrAtomicIterator(store::Iterator* aInput)
    :
    StoreNodeDistinctIterator(aInput),
    theAtomicMode(false),
    theNodeMode(false)
  {
  }

  bool next(store::Item_t& result); 

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
class StoreNodeSortIterator : public store::Iterator
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
      if (theAscending)
      {
        return (n1->compare2(n2) < 0);
      }
      else
      {
        return (n2->compare2(n1) < 0);
      }
    }
  };

protected:
  store::Iterator_t       theInput;
  bool                    theAscending;
  bool                    theDistinct;

  std::vector<XmlNode*>   theNodes;
  long                    theCurrentNode;

public:
  StoreNodeSortIterator(
        const store::Iterator_t& input,
        bool                     ascendant,
        bool                     distinct)
    :
    theInput(input),
    theAscending(ascendant),
    theDistinct(distinct),
    theCurrentNode(-1)
  {
  }

  virtual ~StoreNodeSortIterator() { close(); }

  void open();
  bool next(store::Item_t& result);
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
  StoreNodeSortOrAtomicIterator(const store::Iterator_t& input, bool asc, bool distinct)
    :
    StoreNodeSortIterator(input, asc, distinct),
    theAtomicMode(false),
    theNodeMode(false)
  {
  }

  bool next(store::Item_t& result);

  void reset() 
  {
    theNodeMode = theAtomicMode = false;
    StoreNodeSortIterator::reset(); 
  }

  void close() { StoreNodeSortIterator::close(); }
};


} // namespace simplestore
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

