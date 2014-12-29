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
#include "stdafx.h"

#include <algorithm>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "node_items.h"
#include "node_iterators.h"
#include "store_defs.h"

namespace zorba
{

namespace simplestore
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenIterator                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


bool ChildrenIteratorImpl::next(store::Item_t& result)
{
  if (theIte == theEnd)
  {
    result = NULL;
    return false;
  }

  if ((*theIte)->isConnectorNode())
  {
    result = static_cast<ConnectorNode*>(*theIte)->getNode();
  }
  else
  {
    result = (*theIte);
  }

  ++theIte;

  return true;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenReverseIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


bool ChildrenReverseIteratorImpl::next(store::Item_t& result)
{
  if (theIte == theEnd)
  {
    result = NULL;
    return false;
  }

  if ((*theIte)->isConnectorNode())
  {
    result = static_cast<ConnectorNode*>(*theIte)->getNode();
  }
  else
  {
    result = (*theIte);
  }

  ++theIte;

  return true;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributesIterator                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


bool AttributesIteratorImpl::next(store::Item_t& result)
{
  if (theIte == theEnd)
  {
    result = NULL;
    return false;
  }

  store::Item* node = ((*theIte)->isConnectorNode() ?
                       static_cast<ConnectorNode*>(*theIte)->getNode() :
                       (*theIte));

  assert(node->getNodeKind() == store::StoreConsts::attributeNode);

  AttributeNode* attr = static_cast<AttributeNode*>(node);

  while (attr->isHidden())
  {
    ++theIte;

    if (theIte == theEnd)
    {
      result = NULL;
      return false;
    }

    node = ((*theIte)->isConnectorNode() ?
            static_cast<ConnectorNode*>(*theIte)->getNode() :
            (*theIte));

    assert(node->getNodeKind() == store::StoreConsts::attributeNode);

    attr = static_cast<AttributeNode*>(node);
  }

  ++theIte;

  result = attr;
  return true;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeDistinctIterator                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


void StoreNodeDistinctIterator::open()
{
}


bool StoreNodeDistinctIterator::next(store::Item_t& result)
{
  while (true)
  {
    if (!theInput->next(result))
      return false;

    assert(result->isNode() || result->isObject() || result->isArray());

    if (theNodeSet.insert(result.getp()))
    {
      return true;
    }
    else if (theCheckOnly)
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0045_DUPLICATE_NODE_ERROR);
    }
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeDistinctOrAtomicIterator                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


bool StoreNodeDistinctOrAtomicIterator::next(store::Item_t& result)
{
  store::Item_t contextNode;

  if (theAtomicMode)
  {
    if (!theInput->next(result))
      return false;

    if (result->isNode())
      throw XQUERY_EXCEPTION(err::XPTY0018);

    return true;
  }

  if (!theInput->next(result))
    return false;

  if (!result->isNode())
  {
    if (theNodeMode)
      throw XQUERY_EXCEPTION(err::XPTY0018);

    theAtomicMode = true;
    return true;
  }
  else
  {
    theNodeMode = true;

    while (true)
    {
      if (theNodeSet.insert(result))
        return true;

      if (!theInput->next(result))
        return false;

      if (!result->isNode())
        throw XQUERY_EXCEPTION(err::XPTY0018);
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
  theCurrentNode = 0;
}


bool StoreNodeSortIterator::next(store::Item_t& result)
{
  if (theCurrentNode == 0)
  {
    store::Item_t item;

    // We are not done yet with gathering all XML nodes.
    while (theInput->next(item))
    {
      if (!item->isNode())
      {
        // If no JSON item should be found (like in a path expression), this
        // is handled by the consumer of this iterator.
        ZORBA_ASSERT(item->isJSONItem());

        json::JSONItem* jsonItem = static_cast<json::JSONItem*>(item.getp());

        if (theDistinct)
        {
          std::set<json::JSONItem*>::const_iterator ite = theJSONItems.find(jsonItem);
          if (ite == theJSONItems.end())
          {
            jsonItem = static_cast<json::JSONItem*>(item.release());
            theJSONItems.insert(jsonItem);
          }
          else
          {
            continue;
          }
        }

        result = jsonItem;
        return true;
      }

      theNodes.push_back(reinterpret_cast<XmlNode*>(item.get()));
      item.release();
    }
    
    // We are out of items. We can now begin to output the nodes. In the next
    // iteration, this part of the code will be skipped.
    ComparisonFunction cmp(theAscending);

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < theNodes.size())
  {
    if (theDistinct)
    {
      result = theNodes[theCurrentNode++];

      while (theCurrentNode < theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return true;
    }
    else
    {
      result = theNodes[theCurrentNode++];
      return true;
    }
  }
  else
  {
    reset();
    result = NULL;
    return false;
  }
}


void StoreNodeSortIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  csize numNodes = theNodes.size();
  for (csize i = 0; i < numNodes; i++)
  {
    XmlNode* n = theNodes[i];
    n->removeReference();
  }

  theNodes.clear();
  theCurrentNode = 0;

  for (std::set<json::JSONItem*>::iterator ite = theJSONItems.begin();
      ite != theJSONItems.end();
      ++ite)
  {
    json::JSONItem* n = *ite;
    n->removeReference();
  }
  theJSONItems.clear();
}


void StoreNodeSortIterator::close()
{
  // Do not close the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  csize numNodes = theNodes.size();
  for (csize i = 0; i < numNodes; ++i)
  {
    XmlNode* n = theNodes[i];
    n->removeReference();
  }

  theNodes.clear();
  theCurrentNode = 0;

  for (std::set<json::JSONItem*>::iterator ite = theJSONItems.begin();
      ite != theJSONItems.end();
      ++ite)
  {
    json::JSONItem* n = *ite;
    n->removeReference();
  }
  theJSONItems.clear();

  theInput = NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class StoreNodeSortOrAtomicIterator                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool StoreNodeSortOrAtomicIterator::next(store::Item_t& result)
{
  if (theAtomicMode)
  {
    if (!theInput->next(result))
      return false;

    if (result->isNode())
      throw XQUERY_EXCEPTION(err::XPTY0018);

    return true;
  }

  if (theCurrentNode == 0)
  {
    while (true)
    {
      if (!theInput->next(result))
        break;

      if (!result->isNode())
      {
        if (theNodeMode)
          throw XQUERY_EXCEPTION(err::XPTY0018);

        theAtomicMode = true;
        return true;
      }
      else
      {
        theNodeMode = true;
      }

      theNodes.push_back(reinterpret_cast<XmlNode*>(result.get()));
      result.release();
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < theNodes.size())
  {
    if (theDistinct)
    {
      result = theNodes[theCurrentNode++];
      zorba::csize size = static_cast<zorba::csize>(theNodes.size());
      while ( (theCurrentNode < size) &&
              (theNodes[theCurrentNode] == result) )
      {
        theCurrentNode++;
      }

      return true;
    }
    else
    {
      result = theNodes[theCurrentNode++];
      return true;
    }
  }
  else
  {
    reset();
    result = NULL;
    return false;
  }

}
} // namespace simplestore
} // namespace zorba

/* vim:set et sw=2 ts=2: */
