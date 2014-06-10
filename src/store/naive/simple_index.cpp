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

#include "diagnostics/assert.h"
#include "zorbautils/hashfun.h"

#include "diagnostics/util_macros.h"

#include "store/api/item.h"
#include "store_defs.h"
#include "simple_index.h"
//#include "simple_index_general.h"
#include "atomic_items.h"
#include "simple_store.h"

#include <algorithm>

namespace zorba 
{ 

namespace simplestore 
{



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Index                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl()
{
}

/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  theQname(qname),
  theSpec(spec)
{
}


/******************************************************************************

********************************************************************************/
IndexImpl::~IndexImpl()
{
}


/******************************************************************************

********************************************************************************/
store::IndexCondition_t IndexImpl::createCondition(store::IndexCondition::Kind k)
{
  if (!isSorted() &&
      (k == store::IndexCondition::BOX_VALUE || 
       k == store::IndexCondition::BOX_GENERAL))
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
    ERROR_PARAMS(IndexConditionImpl::getKindString(k), getName()->getStringValue()));
  }

  if (isGeneral())
  {
    return new GeneralIndexCondition(this, k);
  }
  else if (k == store::IndexCondition::POINT_VALUE)
  {
    return new IndexPointCondition(this, k);
  }
  else if (k == store::IndexCondition::BOX_VALUE)
  {
    return new IndexBoxValueCondition(this, k);
  }
  else
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
    ERROR_PARAMS(IndexConditionImpl::getKindString(k), getName()->getStringValue()));

    ZORBA_ASSERT(false);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexConditionImpl                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  TODO: proper initialization order is not guaranteed => use factory instead
********************************************************************************/
store::Item_t IndexConditionImpl::theNegInf(new DecimalItem(store::XS_DECIMAL));
store::Item_t IndexConditionImpl::thePosInf(new DecimalItem(store::XS_DECIMAL));


/*******************************************************************************
  Static method
********************************************************************************/
std::string IndexConditionImpl::getKindString(store::IndexCondition::Kind k)
{
  switch (k)
  {
  case POINT_VALUE:
    return "POINT_VALUE";
  case POINT_GENERAL:
    return "POINT_GENERAL";
  case BOX_VALUE:
    return "BOX_VALUE";
  case BOX_GENERAL:
    return "BOX_GENERAL";
  default:
    return "";
  }
}


/*******************************************************************************

********************************************************************************/
IndexConditionImpl::IndexConditionImpl(
    IndexImpl* idx,
    store::IndexCondition::Kind kind)
  :
  theIndex(idx),
  theKind(kind)
{
}


/*******************************************************************************

********************************************************************************/
void IndexConditionImpl::pushItem(store::Item_t& item)
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
void IndexConditionImpl::pushRange(
    store::Item_t& lower,
    store::Item_t& upper,
    bool haveLower,
    bool haveUpper,
    bool lowerIncl,
    bool upperIncl)
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
void IndexConditionImpl::pushBound(
    store::Item_t& bound,
    bool isLower,
    bool boundIncl)
{
  ZORBA_ASSERT(false);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralIndexCondition                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
GeneralIndexCondition::GeneralIndexCondition(
    IndexImpl* idx,
    store::IndexCondition::Kind kind)
  :
  IndexConditionImpl(idx, kind),
  theIsSet(false)
{
}


/*******************************************************************************

********************************************************************************/
std::string GeneralIndexCondition::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const GeneralIndexCondition& cond)
{
  os << "{ " << cond.getKindString() << " : ";

  if (!cond.theIsSet)
  {
    os << "not set" << std::endl;
    return os;
  }

  if (cond.theKind == store::IndexCondition::BOX_VALUE || 
      cond.theKind == store::IndexCondition::BOX_GENERAL)
  {
    if (!cond.theRangeFlags.theHaveLowerBound)
    {
      os << "[-INF";
    }
    else 
    {
      if (cond.theRangeFlags.theLowerBoundIncl)
        os << "[" << cond.theLowerBound->getStringValue();
      else
        os << "(" << cond.theLowerBound->getStringValue();
    }
    
    os << ", ";
  
  
    if (!cond.theRangeFlags.theHaveUpperBound)
    {
      os << "+INF] ";
    }
    else 
    {
      if (cond.theRangeFlags.theUpperBoundIncl)
        os << cond.theUpperBound->getStringValue() << "] ";
      else
        os << cond.theUpperBound->getStringValue() << ") ";
    }
  }
  else
  {
    os << "[" << cond.theKey->getStringValue() << "]";
  }

  os << std::endl;
  return os;
}


/*******************************************************************************

********************************************************************************/
void GeneralIndexCondition::clear()
{
  theIsSet = false;
  theKey = NULL;
  theLowerBound = NULL;
  theUpperBound = NULL;
}


/*******************************************************************************

********************************************************************************/
void GeneralIndexCondition::pushItem(store::Item_t& item)
{
  assert(theKind == POINT_VALUE || theKind == POINT_GENERAL);
  assert(!theIsSet);
  assert(item && item->isAtomic());

  theKey.transfer(item);

  store::Item* baseItem = theKey->getBaseItem();
  if (baseItem != NULL)
    theKey = baseItem;

  theIsSet = true;
}


/*******************************************************************************

********************************************************************************/
void GeneralIndexCondition::pushRange(
    store::Item_t& lower,
    store::Item_t& upper,
    bool haveLower,
    bool haveUpper,
    bool lowerIncl,
    bool upperIncl)
{
  assert(theKind == BOX_VALUE);
  assert(!theIsSet);
  assert(!haveLower || (lower && lower->isAtomic()));
  assert(!haveUpper || (upper && upper->isAtomic()));

  theRangeFlags.theHaveLowerBound = haveLower;
  theRangeFlags.theHaveUpperBound = haveUpper;
  theRangeFlags.theLowerBoundIncl = lowerIncl;
  theRangeFlags.theUpperBoundIncl = upperIncl;

  if (haveLower)
  {
    theLowerBound.transfer(lower);

    store::Item* baseItem = theLowerBound->getBaseItem();
    if (baseItem != NULL)
      theLowerBound = baseItem;
  }

  if (haveUpper)
  {
    theUpperBound.transfer(upper);

    store::Item* baseItem = theUpperBound->getBaseItem();
    if (baseItem != NULL)
      theUpperBound = baseItem;
  }

  theIsSet = true;
}


/*******************************************************************************

********************************************************************************/
void GeneralIndexCondition::pushBound(
    store::Item_t& bound,
    bool isLower,
    bool boundIncl)
{
  assert(theKind == BOX_GENERAL);
  assert(!theIsSet);

  assert(bound != NULL);

  if (isLower)
  {
    theRangeFlags.theHaveLowerBound = true;
    theRangeFlags.theHaveUpperBound = false;

    theLowerBound.transfer(bound);

    store::Item* baseItem = theLowerBound->getBaseItem();
    if (baseItem != NULL)
      theLowerBound = baseItem;
  }
  else
  {
    theRangeFlags.theHaveLowerBound = false;
    theRangeFlags.theHaveUpperBound = true;

    theUpperBound.transfer(bound);

    store::Item* baseItem = theUpperBound->getBaseItem();
    if (baseItem != NULL)
      theUpperBound = baseItem;
  }

  theRangeFlags.theLowerBoundIncl = boundIncl;
  theRangeFlags.theUpperBoundIncl = boundIncl;

  theIsSet = true;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexPointCondition                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void IndexPointCondition::clear()
{
  theKey.clear();
}


/*******************************************************************************
  Note: The runtime guarantees that the type of the item is appropriate
********************************************************************************/
void IndexPointCondition::pushItem(store::Item_t& item)
{
  theKey.transfer_back(item);
}


/*******************************************************************************

********************************************************************************/
bool IndexPointCondition::test(const store::IndexKey& key) const
{
  ulong numCols = theKey.size();

  ZORBA_ASSERT(numCols == theIndex->getNumColumns());

  for (ulong i = 0; i < numCols; i++)
  {
    if (! theKey[i]->equals(key[i],
                            theIndex->getSpecification().theTimezone,
                            theIndex->getCollator(i)))
      return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
std::string IndexPointCondition::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const IndexPointCondition& cond)
{
  os << "{ " << cond.getKey() << " }";
  return os;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexBoxValueCondition                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void IndexBoxValueCondition::clear()
{
  theLowerBounds.clear();
  theUpperBounds.clear();
  theRangeFlags.clear();
}


/*******************************************************************************

********************************************************************************/
void IndexBoxValueCondition::pushRange(
    store::Item_t& lower,
    store::Item_t& upper,
    bool haveLower,
    bool haveUpper,
    bool lowerIncl,
    bool upperIncl)
{
  csize size = theLowerBounds.size();
  theLowerBounds.resize(size + 1);
  theUpperBounds.resize(size + 1);
  theRangeFlags.resize(size + 1);

  theLowerBounds[size].transfer(lower);
  theUpperBounds[size].transfer(upper);
  theRangeFlags[size].theHaveLowerBound = haveLower;
  theRangeFlags[size].theHaveUpperBound = haveUpper;
  theRangeFlags[size].theLowerBoundIncl = lowerIncl;
  theRangeFlags[size].theUpperBoundIncl = upperIncl;
}


/*******************************************************************************

********************************************************************************/
bool IndexBoxValueCondition::test(const store::IndexKey& key) const
{
  csize numCols = theLowerBounds.size();

  ZORBA_ASSERT(numCols <= theIndex->getNumColumns());

  long timezone = theIndex->getSpecification().theTimezone;

  for (csize i = 0; i < numCols; i++)
  {
    const XQPCollator* collator = theIndex->getCollator(i);

    if (theRangeFlags[i].theHaveLowerBound)
    {
      long comp = key[i]->compare(theLowerBounds[i], timezone, collator);

      if (comp < 0 || (comp == 0 && !theRangeFlags[i].theLowerBoundIncl))
        return false;
    }

    if (theRangeFlags[i].theHaveUpperBound)
    {
      long comp = key[i]->compare(theUpperBounds[i], timezone, collator);

      if (comp > 0 || (comp == 0 && !theRangeFlags[i].theUpperBoundIncl))
        return false;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const IndexBoxValueCondition& cond)
{
  ulong numCols = cond.theLowerBounds.size();

  os << "{ ";

  for (ulong i = 0; i < numCols; i++)
  {
    if (!cond.theRangeFlags[i].theHaveLowerBound)
    {
    os << "[-INF";
    }
    else 
    {
      if (cond.theRangeFlags[i].theLowerBoundIncl)
        os << "[" << cond.theLowerBounds[i]->getStringValue();
      else
        os << "(" << cond.theLowerBounds[i]->getStringValue();
    }
    
    os << ", ";


    if (!cond.theRangeFlags[i].theHaveUpperBound)
    {
      os << "+INF] ";
    }
    else 
    {
      if (cond.theRangeFlags[i].theUpperBoundIncl)
        os << cond.theUpperBounds[i]->getStringValue() << "] ";
      else
        os << cond.theUpperBounds[i]->getStringValue() << ") ";
    }
  }

  os << "}";

  return os;
}


/*******************************************************************************

********************************************************************************/
std::string IndexBoxValueCondition::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


} // namespace simplestore


namespace store 
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexDelta                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************

********************************************************************************/
void IndexDelta::addValuePair(store::Item_t& node, store::IndexKey* key)
{
  theValueDelta.resize(theValueDelta.size() + 1);
  theValueDelta.back().first.transfer(node);
  theValueDelta.back().second = key;
}


/*******************************************************************************

********************************************************************************/
void IndexDelta::addGeneralPair(store::Item_t& node, store::Item_t& key)
{
  assert(node->isNode() && key->isAtomic());

  theGeneralDelta.resize(theGeneralDelta.size() + 1);
  theGeneralDelta.back().first.transfer(node);
  theGeneralDelta.back().second.transfer(key);
}


/*******************************************************************************

********************************************************************************/
void IndexDelta::clear()
{
  for (csize i = 0; i < theValueDelta.size(); ++i)
  {
    delete theValueDelta[i].second;
  }

  theValueDelta.clear();
  theGeneralDelta.clear();
}

/*******************************************************************************

********************************************************************************/
IndexDelta::~IndexDelta()
{
  clear();
}


} // namespace store


}

/* vim:set et sw=2 ts=2: */
