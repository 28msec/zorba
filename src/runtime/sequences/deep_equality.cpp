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

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "deep_equality.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorbatypes/decimal.h"
#include "zorbatypes/URI.h"
#include "zorbamisc/ns_consts.h"
#include "zorbautils/fatal.h"

// For timing
#include <zorba/util/time.h>

#include <zorba/util/transcode_stream.h>

#include <util/fs_util.h>
#include <util/uri_util.h>

#include <compiler/api/compilercb.h>

#include <runtime/sequences/sequences.h>
#include <runtime/core/arithmetic_impl.h>
#include <runtime/util/iterator_impl.h>
#include <runtime/visitors/planiter_visitor.h>
#include <runtime/util/doc_uri_heuristics.h>

#include <system/globalenv.h>

#include <types/casting.h>
#include <types/typeops.h>
#include <types/typeimpl.h>

#include <store/api/store.h>
#include <store/api/iterator.h>
#include <store/api/item_factory.h>
#include "store/api/temp_seq.h"
#include <store/api/pul.h>

#include <context/static_context.h>

#include "zorbautils/hashset_structured_itemh.h"
#include "zorbautils/hashset_atomic_itemh.h"
namespace zorba
{
namespace equality
{

bool deepEqualChildren(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it1,
    const store::Iterator_t& it2,
    XQPCollator* collator,
    int timezone,
    bool raiseError)
{
  store::Item_t child1, child2;
  bool c1Valid, c2Valid;

  it1->open();
  it2->open();

  while (1)
  {
    while ((c1Valid = it1->next(child1)) &&
           (child1->getNodeKind() == store::StoreConsts::piNode ||
            child1->getNodeKind() == store::StoreConsts::commentNode))
      ;

    while ((c2Valid = it2->next(child2)) &&
            (child2->getNodeKind() == store::StoreConsts::piNode ||
             child2->getNodeKind() == store::StoreConsts::commentNode))
      ;

    if (!c1Valid && !c2Valid)
      return true;
    else if (!c1Valid || !c2Valid)
      return false;
    else if (!deepEqual(loc, sctx, child1, child2, collator, timezone, raiseError))
      return false;
  }

  return true;
}


bool deepEqualAttributes(
  const QueryLoc& loc,
  static_context* sctx,
  const store::Iterator_t& it1,
  const store::Iterator_t& it2,
  XQPCollator* collator,
  int timezone,
  bool raiseError)
{
  store::Item_t child1, child2;
  int c1count = 0, c2count = 0;

  it1->open();
  it2->open();

  while (it1->next(child1))
  {
    c1count++;

    it2->reset();

    bool found = false;
    while (it2->next(child2))
    {
      if (deepEqual(loc, sctx, child1, child2, collator, timezone, raiseError))
      {
        found = true;
        break;
      }
    }

    if (!found)
      return false;
  }

  it2->reset();
  while (it2->next(child2))
    c2count++;

  if (c1count != c2count)
    return false;

  return true;
}


bool deepEqualNodes(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError)
{
  if (item1->getNodeKind() != item2->getNodeKind())
    return false;

  switch (item1->getNodeKind())
  {
  case store::StoreConsts::documentNode:
  {
    return deepEqualChildren(loc,
                             sctx,
                             item1->getChildren(),
                             item2->getChildren(),
                             collator,
                             timezone,
                             raiseError);
    break;
  }
  case store::StoreConsts::elementNode:
  {
    if (! item1->getNodeName()->equals(item2->getNodeName()))
      return false;

    if (!deepEqualAttributes(loc,
                             sctx,
                             item1->getAttributes(),
                             item2->getAttributes(),
                             collator,
                             timezone,
                             raiseError))
      return false;

    if (item1->haveSimpleContent())
    {
      if (!item2->haveSimpleContent())
        return false;

      store::Item_t value1, value2;
      store::Iterator_t ite1, ite2;
      item1->getTypedValue(value1, ite1);
      item2->getTypedValue(value2, ite2);

      if (ite1 == NULL && ite2 == NULL)
      {
        return deepEqual(loc, sctx, value1, value2, collator, timezone, raiseError);
      }
      else if (ite1 != NULL && ite2 != NULL)
      {
        ite1->open();
        ite2->open();

        while (1)
        {
          bool c1Valid = ite1->next(value1);
          bool c2Valid = ite2->next(value2);

          if (!c1Valid && !c2Valid)
            return true;
          else if (!c1Valid || !c2Valid)
            return false;
          else if (!deepEqual(loc, sctx, value1, value2, collator, timezone, raiseError))
            return false;
        }
      }
      else
      {
        return false;
      }
    }
    else if (item2->haveSimpleContent())
    {
      return false;
    }
    else
    {
      store::Item* typename1 = item1->getType();
      store::Item* typename2 = item2->getType();

      if (typename1->equals(typename2))
      {
        return deepEqualChildren(loc,
                                 sctx,
                                 item1->getChildren(),
                                 item2->getChildren(),
                                 collator,
                                 timezone,
                                 raiseError);
      }
      else
      {
        TypeManager* tm = sctx->get_typemanager();

        xqtref_t type1 =
        tm->create_named_type(typename1, SequenceType::QUANT_ONE, loc, raiseError);

        xqtref_t type2 =
        tm->create_named_type(typename2, SequenceType::QUANT_ONE, loc, raiseError);

        ZORBA_ASSERT(type1->isComplex() && type2->isComplex());

        if (type1->contentKind() != type2->contentKind())
          return false;

        return deepEqualChildren(loc,
                                 sctx,
                                 item1->getChildren(),
                                 item2->getChildren(),
                                 collator,
                                 timezone,
                                 raiseError);
      }
    }
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    if (! item1->getNodeName()->equals(item2->getNodeName()))
      return false;

    store::Item_t value1, value2;
    store::Iterator_t ite1, ite2;
    item1->getTypedValue(value1, ite1);
    item2->getTypedValue(value2, ite2);

    if (ite1 == NULL && ite2 == NULL)
    {
      return deepEqual(loc, sctx, value1, value2, collator, timezone, raiseError);
    }
    else if (ite1 != NULL && ite2 != NULL)
    {
      ite1->open();
      ite2->open();

      while (1)
      {
        bool c1Valid = ite1->next(value1);
        bool c2Valid = ite2->next(value2);

        if (!c1Valid && !c2Valid)
          return true;
        else if (!c1Valid || !c2Valid)
          return false;
        else if (!deepEqual(loc, sctx, value1, value2, collator, timezone, raiseError))
          return false;
      }
    }
    else
    {
      return false;
    }

    break;
  }
  case store::StoreConsts::textNode:
  case store::StoreConsts::commentNode:
  {
    return (0 == utf8::compare(item1->getStringValue(),
                               item2->getStringValue(),
                               collator));
  }

  case store::StoreConsts::piNode:
  {
    if (utf8::compare(item1->getNodeName()->getStringValue(),
                      item2->getNodeName()->getStringValue(),
                      collator))
      return false;

    return (0 == utf8::compare(item1->getStringValue(),
                               item2->getStringValue(),
                               collator));
  }

  case store::StoreConsts::namespaceNode:
  {
    if (utf8::compare(item1->getNamespacePrefix(),
                      item2->getNamespacePrefix(),
                      collator))
      return false;

    return (0 == utf8::compare(item1->getStringValue(),
                               item2->getStringValue(),
                               collator));
  }
  default:
    ZORBA_ASSERT(false);
  }

  return true;
}


bool deepEqualObjects(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError)
{
  assert(item1->isObject());
  assert(item2->isObject());

  if (item1->getNumObjectPairs() != item2->getNumObjectPairs())
    return false;

  store::Iterator_t lKeys = item1->getObjectKeys();
  lKeys->open();

  store::Item_t lKey, lValue1, lValue2;

  while (lKeys->next(lKey))
  {
    lValue2 = item2->getObjectValue(lKey);

    if (lValue2 == NULL)
      return false;

    lValue1 = item1->getObjectValue(lKey);

    if (!deepEqual(loc, sctx, lValue1, lValue2, collator, timezone, raiseError))
      return false;
  }

  return true;
}


bool deepEqualArrays(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError)
{
  assert(item1->isArray());
  assert(item2->isArray());

  if (item1->getArraySize() != item2->getArraySize())
    return false;

  store::Iterator_t lValues1 = item1->getArrayValues();
  store::Iterator_t lValues2 = item2->getArrayValues();
  lValues1->open();
  lValues2->open();

  store::Item_t lValue1, lValue2;

  while (lValues1->next(lValue1) && lValues2->next(lValue2))
  {
    if (!deepEqual(loc, sctx, lValue1, lValue2, collator, timezone, raiseError))
      return false;
  }

  return true;
}


bool deepEqual(
    const QueryLoc& loc,
    static_context* sctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError)
{
  if (item1->isFunction() || item2->isFunction())
  {
    if (raiseError)
    {
      RAISE_ERROR(err::FOTY0015, loc,
        ERROR_PARAMS((item1->isFunction() ? item1 : item2)->getFunctionName()->getStringValue()));
    }
    else
      return false;
  }

  if (item1->getKind() != item2->getKind())
    return false;

  switch (item1->getKind())
  {
  case store::Item::ATOMIC:
  {
    assert(item2->isAtomic());

    store::SchemaTypeCode type1 = item1->getTypeCode();
    store::SchemaTypeCode type2 = item2->getTypeCode();

    // check if both items are NaN
    if (((type1 == store::XS_FLOAT && item1->getFloatValue().isNaN()) ||
         (type1 == store::XS_DOUBLE && item1->getDoubleValue().isNaN()))
        &&
        ((type2 == store::XS_FLOAT && item2->getFloatValue().isNaN()) ||
         (type2 == store::XS_DOUBLE && item2->getDoubleValue().isNaN())))
    {
      return true;
    }

    if (raiseError)
    {
      try
      {
        TypeManager* tm = sctx->get_typemanager();
        return CompareIterator::valueEqual(loc, item1, item2, tm, timezone, collator, raiseError);
       }
       catch (ZorbaException const& e)
       {
        if (e.diagnostic() == err::XPTY0004)
          return false;
        throw;
       }
    }
    else
    {
      TypeManager* tm = sctx->get_typemanager();
      return CompareIterator::valueEqual(loc, item1, item2, tm, timezone, collator, raiseError);
    }

    break;
  }
  case store::Item::NODE:
  {
    return deepEqualNodes(loc, sctx, item1, item2, collator, timezone, raiseError);
  }
  case store::Item::OBJECT:
  {
    return deepEqualObjects(loc, sctx, item1, item2, collator, timezone, raiseError);
  }
  case store::Item::ARRAY:
  {
    return deepEqualArrays(loc, sctx, item1, item2, collator, timezone, raiseError);
  }
  default:
  {
    ZORBA_ASSERT(false);  // should never reach here
  }
  }

  return false;
}

uint32_t deHashChildren(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it,
    XQPCollator* collator,
    int timezone)
{
  uint32_t lHash = FNV_32_INIT;
  uint32_t lInnerHash;
  store::Item_t child;
  it->open();

  while (it->next(child))
  {
    if (child->getNodeKind() == store::StoreConsts::piNode
        ||
        child->getNodeKind() == store::StoreConsts::commentNode)
      continue;

    lInnerHash = deHash(loc, sctx, child, collator, timezone);
    lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
  }

  return lHash;
}


uint32_t deHashAttributes(
  const QueryLoc& loc,
  static_context* sctx,
  const store::Iterator_t& it,
  XQPCollator* collator,
  int timezone)
{
  uint32_t lHash = FNV_32_INIT;
  std::vector<uint32_t> lInnerHashes;
  store::Item_t attr;

  it->open();
  while (it->next(attr))
  {
    lInnerHashes.push_back(deHash(loc, sctx, attr, collator, timezone));
  }

  std::sort(lInnerHashes.begin(), lInnerHashes.end());
  for(std::vector<uint32_t>::iterator it = lInnerHashes.begin(); it != lInnerHashes.end(); ++it)
  {
    lHash = hashfun::h32(&(*it), sizeof(*it), lHash);
  }

  return lHash;
}


uint32_t deHashNode(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone)
{
  uint32_t lHash = FNV_32_INIT;
  uint32_t lInnerHash;

  store::NodeKind lNodeKind = item->getNodeKind();
  lHash = hashfun::h32(&lNodeKind, sizeof(lNodeKind), lHash);

  switch (item->getNodeKind())
  {
    case store::StoreConsts::documentNode:
    {
      lInnerHash = equality::deHashChildren(loc, sctx, item->getChildren(), collator, timezone);
      return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
    }
    case store::StoreConsts::elementNode:
    {
      lInnerHash = item->getNodeName()->hash();
      lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      lInnerHash = deHashAttributes(loc, sctx, item->getAttributes(), collator, timezone);
      lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      bool lHaveSimpleContent = item->haveSimpleContent();
      lHash = hashfun::h32(&lHaveSimpleContent, sizeof(lHaveSimpleContent), lHash);

      if (lHaveSimpleContent)
      {
        store::Item_t value;
        store::Iterator_t ite;
        item->getTypedValue(value, ite);
        if (value)
        {
          lInnerHash = deHash(loc, sctx, value, collator, timezone);
          lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
        }
        else if (ite)
        {
          ite->open();
          while (ite->next(value))
          {
            lInnerHash = deHash(loc, sctx, value, collator, timezone);
            lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
          }
        }
        return lHash;
      }
      else
      {
        lInnerHash = deHashChildren(loc, sctx, item->getChildren(), collator, timezone);
        return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
    }
    case store::StoreConsts::attributeNode:
    {
      lInnerHash = item->getNodeName()->hash();
      lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      store::Item_t value;
      store::Iterator_t ite;
      item->getTypedValue(value, ite);
      if (value)
      {
        lInnerHash = deHash(loc, sctx, value, collator, timezone);
        lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      }
      else if (ite)
      {
        ite->open();
        while (ite->next(value))
        {
          lInnerHash = deHash(loc, sctx, value, collator, timezone);
          lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
        }
      }
      return lHash;
    }
    case store::StoreConsts::textNode:
    case store::StoreConsts::commentNode:
    {
      zstring lStringValue = item->getStringValue();
      return hashfun::h32(&lStringValue, sizeof(lStringValue), lHash);
    }
    case store::StoreConsts::piNode:
    {
      lInnerHash = item->getNodeName()->hash();
      lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
      zstring lStringValue = item->getStringValue();
      return hashfun::h32(&lStringValue, sizeof(lStringValue), lHash);
    }

    case store::StoreConsts::namespaceNode:
    {
      zstring lNamespacePrefix = item->getNamespacePrefix();
      lHash = hashfun::h32(&lNamespacePrefix, sizeof(lNamespacePrefix), lHash);
      zstring lStringValue = item->getStringValue();
      return hashfun::h32(&lStringValue, sizeof(lStringValue), lHash);
    }
    default:
    {
      /*
       * The type of the item is one of:
       * PUL, FUNCTION, ERROR_
       */
      return FNV_32_INIT;
    }
  }

  return true;
}

struct ObjectKeyPred
{
    bool operator()(store::Item_t const& a, store::Item_t const& b) const
    {
        return a->getString() < b->getString();
    }
};

uint32_t deHashObject(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone)
{
  uint32_t lHash = FNV_32_INIT;
  uint32_t lInnerHash;
  std::vector<store::Item_t> lKeysVec;
  store::Iterator_t lKeys = item->getObjectKeys();
  store::Item_t lKey;
  lKeys->open();

  while (lKeys->next(lKey))
  {
    lKeysVec.push_back(lKey);
  }

  std::sort(lKeysVec.begin(), lKeysVec.end(), ObjectKeyPred());
  for(std::vector<store::Item_t>::iterator it = lKeysVec.begin(); it != lKeysVec.end(); ++it)
  {
    lInnerHash = deHash(loc, sctx, *it, collator, timezone);
    lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
  }

  return lHash;
}


uint32_t deHashArray(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone)
{
  uint32_t lHash = FNV_32_INIT;
  uint32_t lInnerHash;

  store::Iterator_t lValues = item->getArrayValues();
  store::Item_t lValue;
  lValues->open();

  while (lValues->next(lValue))
  {
    lInnerHash = deHash(loc, sctx, lValue, collator, timezone);
    lHash = hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
  }

  return lHash;
}


uint32_t deHash(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone)
{
  store::Item::ItemKind lKind = item->getKind();
  uint32_t lHash = hashfun::h32(&lKind, sizeof(store::Item::ItemKind), FNV_32_INIT);
  uint32_t lInnerHash;

  switch (item->getKind())
  {
    case store::Item::ATOMIC:
    {
      store::SchemaTypeCode type = item->getTypeCode();
      lHash = hashfun::h32(&type, sizeof(type), lHash);
      lInnerHash = item->hash(timezone, collator);
      return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
    }
    case store::Item::NODE:
    {
      lInnerHash = deHashNode(loc, sctx, item, collator, timezone);
      return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
    }
    case store::Item::OBJECT:
    {
      lInnerHash = deHashObject(loc, sctx, item, collator, timezone);
      return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
    }
    case store::Item::ARRAY:
    {
      lInnerHash = deHashArray(loc, sctx, item, collator, timezone);
      return hashfun::h32(&lInnerHash, sizeof(lInnerHash), lHash);
    }
    default:
    {
      /*
       * The type of the item is one of:
       * PUL, FUNCTION, ERROR_
       */
      return FNV_32_INIT;
    }
  }

  return false;
}



}
}
