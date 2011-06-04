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

#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/store_defs.h"

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

  result = (*theIte);

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

  result = (*theIte);

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

  AttributeNode* attr = static_cast<AttributeNode*>(*theIte);

  while (attr->isHidden())
  {
    ++theIte;

    if (theIte == theEnd)
    {
      result = NULL;
      return false;
    }

    attr = static_cast<AttributeNode*>(*theIte);
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

    assert(result->isNode());

    if (theNodeSet.insert(result.getp()))
    {
      return true;
    }
    else if (theCheckOnly)
    {
      throw ZORBA_EXCEPTION( zerr::ZSTR0045_DUPLICATE_NODE_ERROR );
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

    if (!result->isAtomic())
      throw XQUERY_EXCEPTION(err::XPTY0018);

    return true;
  }

  if (!theInput->next(result))
    return false;

  if (result->isAtomic())
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

      if (result->isAtomic())
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
  theCurrentNode = -1;
}


bool StoreNodeSortIterator::next(store::Item_t& result)
{
  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      store::Item_t contextNode;
      if (!theInput->next(contextNode))
        break;

      ZORBA_ASSERT(contextNode->isNode());

      theNodes.push_back(reinterpret_cast<XmlNode*>(contextNode.release()));
    }

    ComparisonFunction cmp(theAscending);

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
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

  ulong numNodes = (ulong)theNodes.size();
  for (ulong i = 0; i < numNodes; i++)
  {
    XmlNode* n = theNodes[i];
    n->removeReference();
  }

  theNodes.clear();
  theCurrentNode = -1;
}


void StoreNodeSortIterator::close()
{
  // Do not close the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  ulong numNodes = (ulong)theNodes.size();
  for (ulong i = 0; i < numNodes; i++)
  {
    XmlNode* n = theNodes[i];
    n->removeReference();
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

bool StoreNodeSortOrAtomicIterator::next(store::Item_t& result)
{
  if (theAtomicMode)
  {
    if (!theInput->next(result))
      return false;

    if (!result->isAtomic())
      throw XQUERY_EXCEPTION(err::XPTY0018);

    return true;
  }

  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      if (!theInput->next(result))
        break;

      if (result->isAtomic() || result->isFunction())
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

      theNodes.push_back(reinterpret_cast<XmlNode*>(result.release()));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
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
} // namespace simplestore
} // namespace zorba

