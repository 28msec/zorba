/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: 
 */

#include "util/Assert.h"

#include "store/minimal/min_node_items.h"
#include "store/minimal/min_node_iterators.h"
#include "store/minimal/min_store_defs.h"
#include <algorithm>

namespace zorba { namespace store {

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenIterator                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

ChildrenIterator::ChildrenIterator(XmlNode* parent)
  :
  theParentNode(parent),
  theCurrentPos(0)
{
  ZORBA_ASSERT(theParentNode->getNodeKind() == StoreConsts::documentNode ||
               theParentNode->getNodeKind() == StoreConsts::elementNode);

  theNumChildren = parent->numChildren();
}

void ChildrenIterator::open()
{
  theCurrentPos = 0;
}


Item_t ChildrenIterator::next()
{
  if (theCurrentPos >= theNumChildren)
    return NULL;

  XmlNode* cnode = theParentNode->getChild(theCurrentPos);

  theCurrentPos++;

  return cnode;
}


void ChildrenIterator::reset()
{
  theCurrentPos = 0;
}


void ChildrenIterator::close()
{
  theCurrentPos = 0;
  theParentNode = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenIteratorLazy                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

ChildrenIteratorLazy::ChildrenIteratorLazy(XmlNode* parent)
  :
  theParentNode(parent),
  theCurrentPos(0)
{
  ZORBA_ASSERT(theParentNode->getNodeKind() == StoreConsts::documentNode ||
               theParentNode->getNodeKind() == StoreConsts::elementNode);

  //theNumChildren = parent->numChildren();
}

void ChildrenIteratorLazy::open()
{
  theCurrentPos = 0;
}


Item_t ChildrenIteratorLazy::next()
{
  XmlLoader_t   xmlloader;
  while((xmlloader=theParentNode->hasLoaderAttached()) != NULL)
  {
    if(theCurrentPos >= theParentNode->numChildren())
    {
      xmlloader->continueloadXml(XmlLoader::UNTIL_START_ELEMENT, theParentNode->getDepth()+1);
    }
    else
      break;
  }

  if(theCurrentPos >= theParentNode->numChildren())
    return NULL;


  XmlNode* cnode = theParentNode->getChild(theCurrentPos);

  theCurrentPos++;

  return cnode;
}


void ChildrenIteratorLazy::reset()
{
  theCurrentPos = 0;
}


void ChildrenIteratorLazy::close()
{
  theCurrentPos = 0;
  theParentNode = NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributesIterator                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

AttributesIterator::AttributesIterator(ElementNode* parent)
  :
  theParentNode(parent),
  theCurrentPos(0)
{
  theNumAttributes = parent->numAttributes();
}

void AttributesIterator::open()
{
  theCurrentPos = 0;
}

Item_t AttributesIterator::next()
{
  if (theCurrentPos >= theNumAttributes)
    return NULL;

  AttributeNode* cnode =
    reinterpret_cast<AttributeNode*>(theParentNode->getAttr(theCurrentPos));

  while (cnode->isHidden())
  {
    theCurrentPos++;

    if (theCurrentPos >= theNumAttributes)
      return NULL;

    cnode = reinterpret_cast<AttributeNode*>(theParentNode->getAttr(theCurrentPos));
  }

  theCurrentPos++;

  return cnode;
}


void AttributesIterator::reset()
{
  theCurrentPos = 0;
}


void AttributesIterator::close()
{
  theCurrentPos = 0;
  theParentNode = NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeDistinctIterator                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void StoreNodeDistinctIterator::open()
{
}


Item_t StoreNodeDistinctIterator::next()
{
  while (true)
  {
    Item_t contextNode = theInput->next();
    if (contextNode == NULL)
      return NULL;

    ZORBA_ASSERT(contextNode->isNode());

    Item* tmp = contextNode;
    if (theNodeSet.insert(contextNode))
      return tmp;
  }
}


void StoreNodeDistinctIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeDistinctIterator,
  // which wraps this store iterator.

  theNodeSet.clear();
}


void StoreNodeDistinctIterator::close()
{
  // Do not close the input. This is done by the runtime NodeDistinctIterator,
  // which wraps this store iterator.

  theNodeSet.clear();
  theInput = NULL;
}


Item_t StoreNodeDistinctOrAtomicIterator::next()
{
  Item_t contextNode;

  if (theAtomicMode) 
  {
    contextNode = theInput->next();
    if (contextNode == 0)
      return NULL;

    if (!contextNode->isAtomic())
      ZORBA_ERROR (ZorbaError::XPTY0018);

    return contextNode;
  }

  contextNode = theInput->next();
  if (contextNode == 0)
    return NULL;

  if (contextNode->isAtomic())
  {
    if (theNodeMode)
      ZORBA_ERROR (ZorbaError::XPTY0018);

    theAtomicMode = true;
    return contextNode;
  }
  else
  {
    theNodeMode = true;

    while (true)
    {
      Item* tmp = contextNode;
      if (theNodeSet.insert(contextNode))
        return tmp;

      contextNode = theInput->next();
      if (contextNode == NULL)
        return NULL;

      if (contextNode->isAtomic())
        ZORBA_ERROR (ZorbaError::XPTY0018);
    }
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class StoreNodeSortIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void StoreNodeSortIterator::open()
{
  theCurrentNode = -1;
}


Item_t StoreNodeSortIterator::next()
{
  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      Item_t contextNode = theInput->next();
      if (contextNode == NULL)
        break;

      ZORBA_ASSERT(contextNode->isNode());

      theNodes.push_back(reinterpret_cast<XmlNode*>(contextNode.transfer()));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      XmlNode* result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return result;
    }
    else
    {
      return theNodes[theCurrentNode++];
    }
  }
  else
  {
    reset();
    return NULL;
  }
}


void StoreNodeSortIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  ulong numNodes = theNodes.size();
  for (ulong i = 0; i < numNodes; i++)
  {
    XmlNode* n = theNodes[i];
    n->removeReference(n->getSharedRefCounter() SYNC_PARAM2(n->getRCLock()));
  }

  theNodes.clear();
  theCurrentNode = -1;
}


void StoreNodeSortIterator::close()
{
  // Do not close the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  ulong numNodes = theNodes.size();
  for (ulong i = 0; i < numNodes; i++)
  {
    XmlNode* n = theNodes[i];
    n->removeReference(n->getSharedRefCounter() SYNC_PARAM2(n->getRCLock()));
  }

  theNodes.clear();
  theCurrentNode = -1;
  theInput = NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class StoreNodeSortOrAtomicIterator                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

Item_t StoreNodeSortOrAtomicIterator::next()
{
  Item_t contextNode;

  if (theAtomicMode)
  {
    contextNode = theInput->next();
    if (contextNode == 0)
      return NULL;

    if (!contextNode->isAtomic())
      ZORBA_ERROR (ZorbaError::XPTY0018);

    return contextNode;
  }

  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      contextNode = theInput->next();
      if (contextNode == NULL)
        break;

      if (contextNode->isAtomic())
      {
        if (theNodeMode)
          ZORBA_ERROR (ZorbaError::XPTY0018);

        theAtomicMode = true;
        return contextNode;
      }
      else
      {
        theNodeMode = true;
      }

      theNodes.push_back(reinterpret_cast<XmlNode*>(contextNode.transfer()));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      XmlNode* result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return result;
    }
    else
    {
      return theNodes[theCurrentNode++];
    }
  }
  else
  {
    reset();
    return NULL;
  }
 
}
} // namespace store
} // namespace zorba

