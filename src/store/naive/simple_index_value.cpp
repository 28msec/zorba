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

#include "store/naive/simple_index_value.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

namespace zorba 
{ 

namespace simplestore 
{


/******************************************************************************

********************************************************************************/
ValueIndex::ValueIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  IndexImpl(qname, spec)
{
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Hash Map Value Index                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ValueHashIndex::KeyIterator::KeyIterator(const IndexMap& aMap)
  :
  theMap(aMap)
{
}


/*******************************************************************************

********************************************************************************/
ValueHashIndex::KeyIterator::~KeyIterator()
{
};


/*******************************************************************************

********************************************************************************/
void ValueHashIndex::KeyIterator::open()
{
  theIterator = theMap.begin();
}


/*******************************************************************************

********************************************************************************/
bool ValueHashIndex::KeyIterator::next(store::IndexKey& aKey)
{
  if (theIterator != theMap.end())
  {
    const store::IndexKey* lKey = (*theIterator).first;
    aKey = *lKey;

    ++theIterator;
    return true;
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
void ValueHashIndex::KeyIterator::close()
{
  theIterator = theMap.end();
};


/******************************************************************************

********************************************************************************/
ValueHashIndex::ValueHashIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  ValueIndex(qname, spec),
  theCompFunction(getNumColumns(), spec.theTimezone, theCollators),
  theMap(theCompFunction, 1024, spec.theIsThreadSafe)
{
}
  

/******************************************************************************

********************************************************************************/
ValueHashIndex::~ValueHashIndex()
{
  IndexMap::iterator ite = theMap.begin();
  IndexMap::iterator end = theMap.end();
 
  for (; ite != end; ++ite)
  {
    //std::cout << "Index Entry Delete [" << (*ite).first << "," 
    //          << (*ite).second << "]" << std::endl;

    delete (*ite).first;
    delete (*ite).second;
  }
}


/*******************************************************************************

********************************************************************************/
void ValueHashIndex::clear()
{
  theMap.clear();
}


/*******************************************************************************

********************************************************************************/
ulong ValueHashIndex::size() const
{
  return theMap.size();
}


/*******************************************************************************

********************************************************************************/
store::Index::KeyIterator_t ValueHashIndex::keys() const
{
  return new KeyIterator(theMap);
}


/*******************************************************************************
  Insert the given item in the value set of the given key. If the key is not
  in the index already, then the key itself is inserted as well. Return true
  if the key was already in the index, false otherwise
********************************************************************************/
bool ValueHashIndex::insert(
    store::IndexKey*& key,
    store::Item_t& value,
    bool multikey)
{
  if (key->size() != getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0003_INDEX_PARTIAL_KEY_INSERT,
    ERROR_PARAMS(key->toString(), theQname->getStringValue()));
  }

  ValueIndexValue* valueSet = NULL;

  if (theMap.get(key, valueSet))
  {
    if (isUnique())
    {
      RAISE_ERROR_NO_LOC(zerr::ZDDY0024_INDEX_UNIQUE_VIOLATION,
      ERROR_PARAMS(theQname->getStringValue()));
    }

    valueSet->resize(valueSet->size() + 1);
    (*valueSet)[valueSet->size()-1].transfer(value);
    
    return true;
  }

  valueSet = new ValueIndexValue(1);
  (*valueSet)[0].transfer(value);
  
  //std::cout << "Index Entry Insert [" << key << "," 
  //          << valueSet << "]" << std::endl;

  const store::IndexKey* key2 = key;
  theMap.insert(key2, valueSet);
  key = NULL; // ownership of the key obj passes to the index.

  return false;
} 


/******************************************************************************
  Remove either (a) the given key and all of its associated values, or (b) only
  the given value from the value set of the given key. In (b) if the value set
  of the key becomes empty, then the key itself is removed from the index.

  If (a), return false if the key is not in the index; otherwise return true.
  If (b), return false if the value is not in the value set of the key, or if
  the key itself is not in the index; true otherwise.
********************************************************************************/
bool ValueHashIndex::remove(
    const store::IndexKey* key,
    store::Item_t& value,
    bool all)
{
  if (key->size() != getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0004_INDEX_PARTIAL_KEY_REMOVE,
    ERROR_PARAMS(key->toString(), theQname->getStringValue()));
  }

  IndexMap::iterator pos = theMap.find(key);

  if (pos != theMap.end())
  {
    const store::IndexKey* keyp = (*pos).first;
    ValueIndexValue* valueSet = (*pos).second;

    ValueIndexValue::iterator valIte = std::find(valueSet->begin(),
                                                 valueSet->end(),
                                                 value);

    if (all)
    {
      theMap.erase(pos);
      delete keyp;
      delete valueSet;

      return true;
    }

    if (valIte != valueSet->end())
    {
      valueSet->theItems.erase(valIte);
        
      if (valueSet->empty())
      {
        theMap.erase(pos);
        delete keyp;
        delete valueSet;
      }

      return true;
    }
  }

  return false;
} 



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProdeValueHashIndexIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void ProbeValueHashIndexIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::POINT_VALUE)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
    ERROR_PARAMS(cond->getKindString(), theIndex->getName()->getStringValue()));
  }

  theCondition = reinterpret_cast<IndexPointValueCondition*>(cond.getp());

  store::IndexKey* key = &(theCondition->theKey);

  if (key->size() != theIndex->getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0005_INDEX_PARTIAL_KEY_PROBE,
    ERROR_PARAMS(key->toString(), theIndex->getName()->getStringValue()));
  }

  theIndex->theMap.get(key, theResultSet);

  if (theResultSet)
  {
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueHashIndexIterator::open()
{
  if (theResultSet)
    theIte = theResultSet->begin();
}


/******************************************************************************

********************************************************************************/
void ProbeValueHashIndexIterator::reset()
{
  if (theResultSet)
    theIte = theResultSet->begin(); 
}


/******************************************************************************

********************************************************************************/
void ProbeValueHashIndexIterator::close()
{
  theCondition = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeValueHashIndexIterator::next(store::Item_t& result)
{
  if (theResultSet && theIte != theEnd)
  {
    result = (*theIte);
    ++theIte;
    return true;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Value Tree Index                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
ValueTreeIndex::KeyIterator::~KeyIterator()
{
};


void ValueTreeIndex::KeyIterator::open()
{
  assert(false);
}


bool ValueTreeIndex::KeyIterator::next(store::IndexKey&)
{
  assert(false);
  return false;
}


void ValueTreeIndex::KeyIterator::close()
{
  assert(false);
}


/******************************************************************************

********************************************************************************/
ValueTreeIndex::ValueTreeIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  ValueIndex(qname, spec),
  theCompFunction(getNumColumns(), spec.theTimezone, theCollators),
  theMap(theCompFunction)
{
}


/******************************************************************************

********************************************************************************/
ValueTreeIndex::~ValueTreeIndex()
{
  IndexMap::iterator ite = theMap.begin();
  IndexMap::iterator end = theMap.end();
 
  for (; ite != end; ++ite)
  {
    delete (*ite).first;
    delete (*ite).second;
  }
}


/******************************************************************************

********************************************************************************/
void ValueTreeIndex::clear()
{
  theMap.clear();
}


/******************************************************************************

********************************************************************************/
ulong ValueTreeIndex::size() const
{
  assert(false);
  return 0;
}


/******************************************************************************

********************************************************************************/
store::Index::KeyIterator_t ValueTreeIndex::keys() const
{
  assert(false);
  return 0;
}


/******************************************************************************

********************************************************************************/
bool ValueTreeIndex::insert(
    store::IndexKey*& key, 
    store::Item_t& value,
    bool multikey)
{
  if (key->size() != getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0003_INDEX_PARTIAL_KEY_INSERT,
    ERROR_PARAMS(key->toString(), theQname->getStringValue()));
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

#if 0
  std::cout << "inserting entry : [(";

  for (ulong i = 0; i < getNumColumns(); i++)
  {
    if (key[i] != NULL)
      std::cout << key[i]->getStringValue() << ", ";
    else
      std::cout << "NULL, ";
  }

  std::cout << "), " << value->getStringValue() << "]" << std::endl;
#endif

  // TODO: optimize this using the lower_bound() method.
  IndexMap::iterator pos = theMap.find(key);

  if (pos != theMap.end())
  {
    if (isUnique())
    {
      RAISE_ERROR_NO_LOC(zerr::ZDDY0024_INDEX_UNIQUE_VIOLATION,
      ERROR_PARAMS(theQname->getStringValue()));
    }

    pos->second->transfer_back(value);
    return true;
  }

  ValueIndexValue* valueSet = new ValueIndexValue(1);
  (*valueSet)[0].transfer(value);

  theMap.insert(IndexMapPair(key, valueSet));
  key = NULL; // ownership of the key obj passes to the index.

  return false;
}


/******************************************************************************

********************************************************************************/
bool ValueTreeIndex::remove(
    const store::IndexKey* key,
    store::Item_t& value,
    bool all)
{
  if (key->size() != getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0004_INDEX_PARTIAL_KEY_REMOVE,
    ERROR_PARAMS(key->toString(), theQname->getStringValue()));
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  IndexMap::iterator pos = theMap.find(key);

  if (pos != theMap.end())
  {
    const store::IndexKey* keyp = pos->first;
    ValueIndexValue* valueSet = (*pos).second;

    ValueIndexValue::iterator valIte = std::find(valueSet->begin(),
                                                   valueSet->end(),
                                                   value);

    if (valIte != valueSet->end())
    {
      valueSet->theItems.erase(valIte);

      if (valueSet->empty())
      {
        theMap.erase(pos);
        delete keyp;
        delete valueSet;
      }

      return true;
    }
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeValueTreeIndexIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::BOX_VALUE &&
      cond->getKind() != store::IndexCondition::POINT_VALUE)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
    ERROR_PARAMS(cond->getKindString(), theIndex->getName()->getStringValue()));
  }

  if (cond->getKind() == store::IndexCondition::POINT_VALUE)
  {
    thePointCond = reinterpret_cast<IndexPointValueCondition*>(cond.getp());

    initExact();
  }
  else
  {
    theBoxCond = reinterpret_cast<IndexBoxValueCondition*>(cond.getp());

    initBox();
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::initExact()
{
  const store::IndexKey& key = thePointCond->theKey;

  if (key.size() != theIndex->getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0005_INDEX_PARTIAL_KEY_PROBE,
    ERROR_PARAMS(key.toString(), theIndex->getName()->getStringValue()));
  }

  theMapBegin = theIndex->theMap.find(&key);

  if (theMapBegin != theIndex->theMap.end())
  {
    theMapEnd = theMapBegin;
    ++theMapEnd;
  }
  else
  {
    theMapEnd = theMapBegin;
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::initBox()
{
  ulong numRanges = theBoxCond->numRanges();

  if (numRanges == 0)
  {
    theMapBegin = theIndex->theMap.begin();
    theMapEnd = theIndex->theMap.end();
    return;
  }

  if (numRanges > theIndex->getNumColumns())
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0006_INDEX_INVALID_BOX_PROBE,
    ERROR_PARAMS(theIndex->getName()->getStringValue(), ZED(BoxCondTooManyColumns)));
  }

  theDoExtraFiltering = (numRanges > 1);

  long timezone = theIndex->getTimezone();

  bool haveLowerBound = true;
  bool haveUpperBound = true;
  bool lowIncl = true;
  bool highIncl = true;

  store::IndexKey& lowerBounds = theBoxCond->theLowerBounds;
  store::IndexKey& upperBounds = theBoxCond->theUpperBounds;

  const std::vector<IndexBoxCondition::RangeFlags>& flags = 
    theBoxCond->theRangeFlags;

  //
  // Check if there is going to be a lower/upper bound
  //
  if (!flags[0].theHaveLowerBound)
  {
    theMapBegin = theIndex->theMap.begin();
    haveLowerBound = false;
  }
  else if (!flags[0].theLowerBoundIncl)
  {
    lowIncl = false;
  }

  if (!flags[0].theHaveUpperBound)
  {
    theMapEnd = theIndex->theMap.end();
    haveUpperBound = false;
  }
  else if (!flags[0].theUpperBoundIncl)
  {
    highIncl = false;
  }

  //
  // Neither lower nor upper bound, so we are going to scan the whole index.
  //
  if (!haveLowerBound && !haveUpperBound)
  {
    return;
  }

  //
  // Adjust the lower and/or upper bound index keys before probing the index.
  //
  for (ulong i = 0; i < numRanges; i++)
  {
    const XQPCollator* collator = theIndex->getCollator(i);

    if (haveLowerBound)
    {
      if (!flags[i].theHaveLowerBound)
        lowerBounds[i] = IndexBoxCondition::theNegInf;
    }

    if (haveUpperBound)
    {
      if (!flags[i].theHaveUpperBound)
        upperBounds[i] = IndexBoxCondition::thePosInf;
    }

    if (flags[i].theHaveLowerBound && flags[i].theHaveUpperBound)
    {
      long comp = lowerBounds[i]->compare(upperBounds[i], timezone, collator);

      if (comp > 0 || 
          (comp == 0 && (!flags[i].theLowerBoundIncl || !flags[i].theUpperBoundIncl)))
      { 
        throw ZORBA_EXCEPTION(
          zerr::ZSTR0006_INDEX_INVALID_BOX_PROBE,
          ERROR_PARAMS(
            theIndex->getName()->getStringValue(), theBoxCond->toString()
          )
        );
      }
    }
  }

  //
  // Do the probing
  //
  if (haveLowerBound && lowIncl)
  {
    theMapBegin = theIndex->theMap.lower_bound(&lowerBounds);

    if (theMapBegin == theIndex->theMap.end())
    {
      theMapEnd = theMapBegin;
      return;
    }
  }
  else if (haveLowerBound)
  {
    theMapBegin = theIndex->theMap.upper_bound(&lowerBounds);

    if (theMapBegin == theIndex->theMap.end())
    {
      theMapEnd = theMapBegin;
      return;
    }
  }

  if (haveUpperBound && highIncl)
  {
    theMapEnd = theIndex->theMap.upper_bound(&upperBounds);
  }
  else if (haveUpperBound)
  {
    theMapEnd = theIndex->theMap.lower_bound(&upperBounds);
  }

  if (theMapEnd == theMapBegin)
  {
    theMapEnd = theMapBegin = theIndex->theMap.end();
    return;
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::open()
{
  if (theMapBegin != theIndex->theMap.end())
  {
    theMapIte = theMapBegin;

    theResultSet = theMapBegin->second;
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::reset()
{
  if (theMapBegin != theIndex->theMap.end())
  {
    theMapIte = theMapBegin;

    theResultSet = theMapIte->second;
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
}


/******************************************************************************

********************************************************************************/
void ProbeValueTreeIndexIterator::close()
{
  thePointCond = NULL;
  theBoxCond = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeValueTreeIndexIterator::next(store::Item_t& result)
{
  while (theResultSet != NULL)
  {
    while (theIte != theEnd)
    {
      result = (*theIte);
      ++theIte;
      return true;
    }

    theResultSet = NULL;
    theMapIte++;

    while (theMapIte != theMapEnd)
    {
      if (!theDoExtraFiltering || theBoxCond->test(*(theMapIte->first)))
      {
        theResultSet = theMapIte->second;
        theIte = theResultSet->begin();
        theEnd = theResultSet->end();
        break;
      }

      theMapIte++;
    }
  }

  return false;
}


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
