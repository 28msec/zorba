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
#include "zorbatypes/collation_manager.h"

#include "store/api/item.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_index.h"
#include "store/naive/simple_index_general.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"

#include <algorithm>

namespace zorba 
{ 

namespace simplestore 
{


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexCompareFunction                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
uint32_t IndexCompareFunction::hash(const store::IndexKey* key) const
{
  uint32_t hval = FNV_32_INIT;

  for (ulong i = 0; i < theNumColumns; ++i)
  {
    if ((*key)[i] == NULL)
      continue;

    hval = hashfun::h32<uint32_t>((*key)[i]->hash(theTimezone, theCollators[i]),
                                  hval);
  }

  return hval;
}


/******************************************************************************

********************************************************************************/
bool IndexCompareFunction::equal(
    const store::IndexKey* key1,
    const store::IndexKey* key2) const
{
  for (ulong i = 0; i < theNumColumns; ++i)
  {
    const store::Item_t& i1 = (*key1)[i];
    const store::Item_t& i2 = (*key2)[i];

    if (i1 == NULL && i2 == NULL)
      continue;

    if (i1 == NULL || i2 == NULL)
      return false;

    if (! (*key1)[i]->equals((*key2)[i].getp(), theTimezone, theCollators[i]))
      return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
long IndexCompareFunction::compare(
    const store::IndexKey* key1,
    const store::IndexKey* key2) const
{
  long result;

#ifndef WIN32
  ulong size = std::min(key1->size(),  key2->size());
#else
  ulong size = std::min(key1->size(),  key2->size());
#endif

  for (ulong i = 0; i < size; i++)
  {
    const store::Item_t& i1 = (*key1)[i];
    const store::Item_t& i2 = (*key2)[i];

    if (i1 == NULL)
    {
      if (i2 != NULL)
        return -1;
    }
    else if (i2 == NULL)
    {
      if (i1 != NULL)
        return +1;
    }
    else if (i1 == IndexBoxCondition::theNegInf)
    {
      return -1;
    }
    else if (i1 == IndexBoxCondition::thePosInf)
    {
      return +1;
    }
    else if (i2 == IndexBoxCondition::theNegInf)
    {
      return +1;
    }
    else if (i2 == IndexBoxCondition::thePosInf)
    {
      return -1;
    }
    else if ((result = i1->compare(i2, theTimezone, theCollators[i])))
    {
      return result;
    }
  }

  return 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Index                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  theQname(qname),
  theSpec(spec)
{
  theCollators.resize(theSpec.getNumColumns());

  for (ulong i = 0; i < theSpec.getNumColumns(); ++i)
  {
    if (!spec.theCollations[i].empty())
    {
      theCollators[i] = CollationFactory::createCollator(spec.theCollations[i]);
    }
    else
    {
      theCollators[i] = NULL;
    }
  }
}


/******************************************************************************

********************************************************************************/
IndexImpl::~IndexImpl()
{
  for (size_t i = 0; i < theCollators.size(); ++i)
  {
    if (theCollators[i])
      delete theCollators[i]; 
  }
}


/******************************************************************************

********************************************************************************/
store::IndexCondition_t IndexImpl::createCondition(store::IndexCondition::Kind k)
{
  switch (k)
  {
  case store::IndexCondition::POINT_VALUE:
    return new IndexPointValueCondition(this);

  case store::IndexCondition::POINT_GENERAL:
    return new IndexPointGeneralCondition(this);

  case store::IndexCondition::BOX_VALUE:
    return new IndexBoxValueCondition(this);

  case store::IndexCondition::BOX_GENERAL:
    return new IndexBoxGeneralCondition(this);

  default:
    ZORBA_ASSERT(false);
  }
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
void IndexPointCondition::pushRange(
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
void IndexPointCondition::pushBound(
    store::Item_t& bound,
    bool isLower,
    bool boundIncl)
{
  ZORBA_ASSERT(false);
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
//  IndexBoxCondition                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


// TODO: proper initialization order is not guaranteed => use factory instead
store::Item_t IndexBoxCondition::theNegInf(new DecimalItem);
store::Item_t IndexBoxCondition::thePosInf(new DecimalItem);


/*******************************************************************************

********************************************************************************/
void IndexBoxCondition::pushItem(store::Item_t& item)
{
  ZORBA_ASSERT(false);
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
  ulong size = theLowerBounds.size();
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


void IndexBoxValueCondition::pushBound(
    store::Item_t& bound, 
    bool isLower,
    bool boundIncl)
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
bool IndexBoxValueCondition::test(const store::IndexKey& key) const
{
  ulong numCols = theLowerBounds.size();

  ZORBA_ASSERT(numCols <= theIndex->getNumColumns());

  long timezone = theIndex->getSpecification().theTimezone;

  for (ulong i = 0; i < numCols; i++)
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



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexBoxGeneralCondition                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
IndexBoxGeneralCondition::IndexBoxGeneralCondition(IndexImpl* idx) 
  :
  IndexBoxCondition(idx)
{
  theRangeFlags.theHaveLowerBound = false;
  theRangeFlags.theHaveUpperBound = false;
  theRangeFlags.theLowerBoundIncl = true;
  theRangeFlags.theUpperBoundIncl = true;
}


/*******************************************************************************

********************************************************************************/
void IndexBoxGeneralCondition::clear()
{
  theBound.clear();
}


/*******************************************************************************

********************************************************************************/
void IndexBoxGeneralCondition::pushRange(
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
void IndexBoxGeneralCondition::pushBound(
    store::Item_t& bound,
    bool isLower, 
    bool boundIncl)
{
  theRangeFlags.theHaveLowerBound = isLower;
  theRangeFlags.theHaveUpperBound = !isLower;
  theRangeFlags.theLowerBoundIncl = boundIncl;
  theRangeFlags.theUpperBoundIncl = boundIncl;

  assert(bound != NULL);

  theBound.transfer_back(bound);
}


/*******************************************************************************

********************************************************************************/
bool IndexBoxGeneralCondition::test(const store::IndexKey& key) const
{
  return true;
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const IndexBoxGeneralCondition& cond)
{
  os << "{ ";

  os << "}";

  return os;
}


/*******************************************************************************

********************************************************************************/
std::string IndexBoxGeneralCondition::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}



}
}

/* vim:set et sw=2 ts=2: */
