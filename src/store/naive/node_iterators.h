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

#include <cassert>
#include <set>
#include <vector>

#include "store/api/iterator.h"
#include "shared_types.h"
#include "node_items.h"
#include "json_items.h"

#include "zorbautils/hashfun.h"
#include "zorbautils/hashset_structured_itemh.h"


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
  store::ItemHandle<InternalNode>  theParentNode;

  InternalNode::iterator           theEnd;
  InternalNode::iterator           theStart;
  InternalNode::iterator           theIte;

public:
  ChildrenIteratorImpl() { }

  void init(store::Item_t& parent, const store::Item* child = NULL)
  {
    theParentNode.transfer(parent);
    theEnd = theParentNode->childrenEnd();
    theStart = theParentNode->childrenBegin();

    if (child != NULL && theStart != theEnd)
    {
      XmlNode* myChild = ((*theStart)->isConnectorNode() ? 
                          static_cast<ConnectorNode*>(*theStart)->getNode() :
                          (*theStart));

      while (myChild != child)
      {
        ++theStart;

        myChild = ((*theStart)->isConnectorNode() ? 
                   static_cast<ConnectorNode*>(*theStart)->getNode() :
                   (*theStart));
      }

      ++theStart;
    }

    theIte = theStart;
  }


  void init(const store::Item* parent, const store::Item* child = NULL)
  {
    theParentNode = parent;
    theEnd = theParentNode->childrenEnd();
    theStart = theParentNode->childrenBegin();

    if (child != NULL && theStart != theEnd)
    {
      XmlNode* myChild = ((*theStart)->isConnectorNode() ? 
                          static_cast<ConnectorNode*>(*theStart)->getNode() :
                          (*theStart));

      while (myChild != child)
      {
        ++theStart;

        myChild = ((*theStart)->isConnectorNode() ? 
                   static_cast<ConnectorNode*>(*theStart)->getNode() :
                   (*theStart));
      }

      ++theStart;
    }

    theIte = theStart;
  }


  store::Item* next()
  {
    if (theIte == theEnd)
      return NULL;

    if ((*theIte)->isConnectorNode())
    {
      store::Item* res = static_cast<ConnectorNode*>(*theIte)->getNode();
      ++theIte;
      return res;
    }
    else
    {
      return *theIte++;
    }
  }


  void open() { theIte = theStart; }

  void reset() { theIte = theStart; }

  void close() { theIte = theEnd; theParentNode = NULL; }

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
  store::ItemHandle<InternalNode>  theParentNode;

  InternalNode::reverse_iterator   theEnd;
  InternalNode::reverse_iterator   theStart;
  InternalNode::reverse_iterator   theIte;

public:
  ChildrenReverseIteratorImpl() { }

  void init(store::Item_t& parent, const store::Item* child = NULL)
  {
    theParentNode.transfer(parent);
    theEnd = theParentNode->childrenREnd();
    theStart = theParentNode->childrenRBegin();

    if (child != NULL && theStart != theEnd)
    {
      XmlNode* myChild = ((*theStart)->isConnectorNode() ? 
                          static_cast<ConnectorNode*>(*theStart)->getNode() :
                          (*theStart));

      while (myChild != child)
      {
        ++theStart;

        myChild = ((*theStart)->isConnectorNode() ? 
                   static_cast<ConnectorNode*>(*theStart)->getNode() :
                   (*theStart));
      }

      ++theStart;
    }

    theIte = theStart;
  }


  void init(const store::Item* parent, const store::Item* child = NULL)
  {
    theParentNode = parent;
    theEnd = theParentNode->childrenREnd();
    theStart = theParentNode->childrenRBegin();

    if (child != NULL && theStart != theEnd)
    {
      XmlNode* myChild = ((*theStart)->isConnectorNode() ? 
                          static_cast<ConnectorNode*>(*theStart)->getNode() :
                          (*theStart));

      while (myChild != child)
      {
        ++theStart;

        myChild = ((*theStart)->isConnectorNode() ? 
                   static_cast<ConnectorNode*>(*theStart)->getNode() :
                   (*theStart));
      }

      ++theStart;
    }

    theIte = theStart;
  }


  store::Item* next()
  {
    if (theIte == theEnd)
      return NULL;

    if ((*theIte)->isConnectorNode())
    {
      store::Item* res = static_cast<ConnectorNode*>(*theIte)->getNode();
      ++theIte;
      return res;
    }
    else
    {
      return *theIte++;
    }
  }


  void open()
  {
    theIte = theStart;
  }

  void reset()
  {
    theIte = theStart;
  }

  void close()
  {
    theIte = theEnd;
    theParentNode = NULL;
  }

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
  store::ItemHandle<ElementNode>  theParentNode;

  InternalNode::iterator          theEnd;
  InternalNode::iterator          theIte;

public:
  AttributesIteratorImpl() { }

  void init(store::Item_t& parent)
  {
    theParentNode.transfer(parent);
    theEnd = theParentNode->attrsEnd();
    theIte = theParentNode->attrsBegin();
  }

  void init(const store::Item* parent)
  {
    theParentNode = parent;
    theEnd = theParentNode->attrsEnd();
    theIte = theParentNode->attrsBegin();
  }

  store::Item* next()
  {
    if (theIte == theEnd)
      return NULL;

    store::Item* node = ((*theIte)->isConnectorNode() ?
                         static_cast<ConnectorNode*>(*theIte)->getNode() :
                         (*theIte));

    assert(node->getNodeKind() == store::StoreConsts::attributeNode);

    AttributeNode* attr = static_cast<AttributeNode*>(node);

    while (attr->isHidden())
    {
      ++theIte;

      if (theIte == theEnd)
        return NULL;

      node = ((*theIte)->isConnectorNode() ?
              static_cast<ConnectorNode*>(*theIte)->getNode() :
              (*theIte));

      assert(node->getNodeKind() == store::StoreConsts::attributeNode);

      attr = static_cast<AttributeNode*>(node);
    }

    ++theIte;

    return attr;
  }


  void open()
  {
    theIte = theParentNode->attrsBegin();
  }

  void reset()
  {
    if (theParentNode)
      theIte = theParentNode->attrsBegin();
  }

  void close()
  {
    theParentNode = NULL;
  }

  bool next(store::Item_t& result);
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
  StructuredItemHandleHashSet   theNodeSet;
  bool                theCheckOnly;

public:
  StoreNodeDistinctIterator(store::Iterator* input, bool checkOnly)
    :
    theInput(input),
    theNodeSet(1024, false),
    theCheckOnly(checkOnly)
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
    StoreNodeDistinctIterator(aInput, false),
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
  csize                   theCurrentNode;
  
  std::set<json::JSONItem*>  theJSONItems;

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
  in the received sequences. The received sequences must contain nodes or atomic
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

/* vim:set et sw=2 ts=2: */
