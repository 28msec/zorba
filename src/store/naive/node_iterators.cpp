
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/store_defs.h"

namespace xqp
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenIterator                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

ChildrenIterator::ChildrenIterator(
    NodeImpl*     parent,
    unsigned long startId)
  :
  theParentNode(parent),
  theChildNodes(parent->getNodeKind() == StoreConsts::documentNode ?
                reinterpret_cast<DocumentNodeImpl*>(parent)->children() :
                reinterpret_cast<ElementNodeImpl*>(parent)->children()),
  theStartingId(startId),
  theCurrentPos(0)
{
  Assert(theParentNode->getNodeKind() == StoreConsts::documentNode ||
         theParentNode->getNodeKind() == StoreConsts::elementNode);
}


Item_t ChildrenIterator::next()
{
  if (theCurrentPos >= theChildNodes.size())
    return NULL;

  Item_t childItem = theChildNodes[theCurrentPos];

  if (theParentNode->isConstructed())
  {
    NodeImpl* pnode = theParentNode.get_ptr();
    NodeImpl* cnode = BASE_NODE(childItem);

    StoreConsts::NodeKind_t pkind = pnode->getNodeKind();
    StoreConsts::NodeKind_t ckind = cnode->getNodeKind();

    if (cnode->getParentPtr() == NULL && !pnode->isCopy())
    {
      cnode->setParent(pnode);

      if (pkind != StoreConsts::documentNode &&
          ckind == StoreConsts::elementNode &&
          (!cnode->isCopy() || pnode->nsInherit()))
      {
        ELEM_NODE(childItem)->setNsContext(pnode->getNsContext());
      }
    }
    else if (pnode->isCopy() && cnode->getParentPtr() != pnode)
    {
      switch (ckind)
      {
      case StoreConsts::elementNode:
        childItem = new ElementNodeImpl(pnode,
                                        ELEM_NODE(childItem),
                                        pnode->typePreserve(),
                                        pnode->nsPreserve());
        break;

      case StoreConsts::textNode:
        childItem = new TextNodeImpl(pnode, TEXT_NODE(childItem));
        break;

      case StoreConsts::piNode:
        childItem = new PiNodeImpl(pnode, PI_NODE(childItem));
        break;

      case StoreConsts::commentNode:
        childItem = new CommentNodeImpl(pnode, COMMENT_NODE(childItem));
        break;

      default:
        Assert(0);
      }

      cnode = BASE_NODE(childItem);
      theChildNodes[theCurrentPos] = childItem;
    }
    else
    {
      // This assertion is not valid because enclosed expressions do not 
      // always make copies of the nodes they produce. 
      // Assert(cnode->getParentPtr() == pnode);
    }

    if (pnode->hasId() &&
        cnode->getParentPtr() == pnode &&
        cnode->getTreeId() != pnode->getTreeId())
    {
      cnode->setId(pnode->getTreeId(), pnode->getOrdPath());
      cnode->appendIdComponent(theStartingId + theCurrentPos * 2 + 1);
    }
  }

  theCurrentPos++;

  return childItem;
}


void ChildrenIterator::reset()
{
  theCurrentPos = 0;
}


void ChildrenIterator::close()
{
  theCurrentPos = 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributesIterator                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

AttributesIterator::AttributesIterator(ElementNodeImpl* parent)
  :
  theParentNode(parent),
  theAttrNodes(parent->attributes()),
  theCurrentPos(0)
{
}


Item_t AttributesIterator::next()
{
  if (theCurrentPos >= theAttrNodes.size())
    return NULL;

  Item_t attrItem = theAttrNodes[theCurrentPos];

  assert(attrItem->getNodeKind() == StoreConsts::attributeNode);

  if (theParentNode->isConstructed())
  {
    NodeImpl* pnode = theParentNode.get_ptr();
    NodeImpl* cnode = BASE_NODE(attrItem);

    if (cnode->getParentPtr() == NULL && !pnode->isCopy())
    {
      cnode->setParent(pnode);
    }
    else if (pnode->isCopy() && cnode->getParentPtr() != pnode)
    {
      attrItem = new AttributeNodeImpl(pnode,
                                       ATTR_NODE(attrItem),
                                       pnode->typePreserve());

      cnode = BASE_NODE(attrItem);
      theAttrNodes[theCurrentPos] = attrItem;
    }
    else
    {
      Assert(cnode->getParentPtr() == pnode);
    }

    if (pnode->hasId() &&
        cnode->getParentPtr() == pnode &&
        cnode->getTreeId() != pnode->getTreeId())
    {
      cnode->setId(pnode->getTreeId(), pnode->getOrdPath());
      cnode->appendIdComponent(theCurrentPos * 2 + 1);
    }
  }

  theCurrentPos++;

  return attrItem;
}


void AttributesIterator::reset()
{
  theCurrentPos = 0;
}


void AttributesIterator::close()
{
  theCurrentPos = 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeDistinctIterator                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

Item_t StoreNodeDistinctIterator::next()
{
  while (true)
  {
    Item_t contextNode = theInput->next();
    if (contextNode == NULL)
      return NULL;

    Assert(contextNode->isNode());

    if (!theNodeSet.insert(contextNode))
      return contextNode;
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
  if (theUsed && theAtomic) {
    Item_t lContextNode = theInput->next();
    if (lContextNode != 0)
      Assert(lContextNode->isAtomic());
    return lContextNode;
  }

  if (!theUsed) {
    Item_t lContextNode = theInput->next();
    if (lContextNode == 0)
      return lContextNode;
    theUsed = true;
    if (lContextNode->isAtomic()) {
      theAtomic = true;
      return lContextNode;
    } else {
      theAtomic = false;
      theNodeSet.insert(lContextNode);
    }
    return lContextNode;
  }
  
  return StoreNodeDistinctIterator::next();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class StoreNodeSortIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

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

      Assert(contextNode->isNode());

      theNodes.push_back(BASE_NODE(contextNode));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      NodeImpl_t result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return result.get_ptr();
    }
    else
    {
      return theNodes[theCurrentNode++].get_ptr();
    }
  }
  else
  {
    return NULL;
  }
}


void StoreNodeSortIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  theNodes.clear();
  theCurrentNode = -1;
}


void StoreNodeSortIterator::close()
{
  // Do not close the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

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
  if (theUsed && theAtomic)
  {
    Item_t lContextNode = theInput->next();
    if (lContextNode != 0)
      Assert(lContextNode->isAtomic());
    return lContextNode;
  }

  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      Item_t contextNode = theInput->next();
      if (contextNode == NULL)
        break;

      if (!theUsed)
      {
        theUsed = true;
        if (contextNode->isAtomic())
        {
          theAtomic = true;
          return contextNode;
        } else {
          theAtomic = false;
        }
      }

      Assert(contextNode->isNode());

      theNodes.push_back(BASE_NODE(contextNode));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      NodeImpl_t result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return result.get_ptr();
    }
    else
    {
      return theNodes[theCurrentNode++].get_ptr();
    }
  }
  else
  {
    return NULL;
  }
 
}

}
