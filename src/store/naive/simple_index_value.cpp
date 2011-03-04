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
#include <algorithm>

#include "store/naive/simple_index_value.h"
#include "zorbaerrors/error_manager.h"


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


/*******************************************************************************a

********************************************************************************/
void ValueHashIndex::clear()
{
  theMap.clear();
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
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_INSERT,
                      theQname->getStringValue(), key->toString());
  }

  ValueIndexValue* valueSet = NULL;

  if (theMap.get(key, valueSet))
  {
    if (isUnique())
    {
      ZORBA_ERROR_PARAM(XDDY0024_INDEX_UNIQUE_VIOLATION,
                        theQname->getStringValue(), "");
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
  Remove the given item from the value set of the given key. If the value set
  of the key becomes empty, then the key itself is removed from the index.
  Retrun false if the item is not in the value set of the key, or if the key 
  itself is not in the index; true otherwise.
********************************************************************************/
bool ValueHashIndex::remove(const store::IndexKey* key, store::Item_t& value)
{
  if (key->size() != getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_REMOVE,
                      theQname->getStringValue().c_str(), key->toString());
  }

  IndexMap::iterator pos = theMap.get(key);

  if (pos != theMap.end())
  {
    const store::IndexKey* keyp = (*pos).first;
    ValueIndexValue* valueSet = (*pos).second;

    ValueIndexValue::iterator valIte = std::find(valueSet->begin(),
                                                 valueSet->end(),
                                                 value);

    if (valIte != valueSet->end())
      valueSet->theItems.erase(valIte);

    if (valueSet->empty())
    {
      theMap.remove(pos);
      delete keyp;
      delete valueSet;
    }

    return true;
  }

  return false;
} 



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProdeHashValueIndexIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void ProbeHashValueIndexIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::POINT_VALUE)
  {
    ZORBA_ERROR_PARAM(STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
                      theIndex->getName()->getStringValue().c_str(), 
                      cond->getKindString());
  }

  theCondition = reinterpret_cast<IndexPointValueCondition*>(cond.getp());

  store::IndexKey* key = &(theCondition->theKey);

  if (key->size() != theIndex->getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0005_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->getName()->getStringValue().c_str(),
                      key->toString());
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
void ProbeHashValueIndexIterator::open()
{
  if (theResultSet)
    theIte = theResultSet->begin();
}


/******************************************************************************

********************************************************************************/
void ProbeHashValueIndexIterator::reset()
{
  if (theResultSet)
    theIte = theResultSet->begin(); 
}


/******************************************************************************

********************************************************************************/
void ProbeHashValueIndexIterator::close()
{
  theCondition = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeHashValueIndexIterator::next(store::Item_t& result)
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
//  STL Map Value Index                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
STLMapIndex::STLMapIndex(
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
STLMapIndex::~STLMapIndex()
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
void STLMapIndex::clear()
{
  theMap.clear();
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::insert(
    store::IndexKey*& key, 
    store::Item_t& value,
    bool multikey)
{
  if (key->size() != getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_INSERT,
                      theQname->getStringValue().c_str(), key->toString());
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
      ZORBA_ERROR_PARAM(XDDY0024_INDEX_UNIQUE_VIOLATION,
                        theQname->getStringValue().c_str(), "");
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
bool STLMapIndex::remove(const store::IndexKey* key, store::Item_t& value)
{
  if (key->size() != getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_REMOVE,
                      theQname->getStringValue().c_str(), "");
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
      valueSet->theItems.erase(valIte);

    if (valueSet->empty())
    {
      theMap.erase(pos);
      delete keyp;
      delete valueSet;
    }

    return true;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeTreeValueIndexIterator                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void ProbeTreeValueIndexIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::BOX_VALUE &&
      cond->getKind() != store::IndexCondition::POINT_VALUE)
  {
    ZORBA_ERROR_PARAM(STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
                      theIndex->getName()->getStringValue().c_str(), 
                      cond->getKindString());
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
void ProbeTreeValueIndexIterator::initExact()
{
  const store::IndexKey& key = thePointCond->theKey;

  if (key.size() != theIndex->getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0005_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->getName()->getStringValue().c_str(), 
                      key.toString());
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
void ProbeTreeValueIndexIterator::initBox()
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
    ZORBA_ERROR_PARAM(STR0006_INDEX_INVALID_BOX_PROBE, 
                      theIndex->getName()->getStringValue().c_str(),
                      "The box condition has more columns than the index");
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

  if (!flags[0].theHaveUpperBound)
  {
    theMapEnd = theIndex->theMap.end();
    haveUpperBound = false;
  }

  //
  // Neither lower nor upper bound, so we are going to scan the whole index.
  //
  if (!haveLowerBound && !haveUpperBound)
  {
    theMapBegin = theIndex->theMap.begin();
    theMapEnd = theIndex->theMap.end();
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
      if (flags[i].theHaveLowerBound)
      {
        if (!flags[i].theLowerBoundIncl)
          lowIncl = false;
      }
      else
      {
        lowerBounds[i] = IndexBoxCondition::theNegInf;
      }
    }

    if (haveUpperBound)
    {
      if (flags[i].theHaveUpperBound)
      {
        if (!flags[i].theUpperBoundIncl)
          highIncl = false;
      }
      else
      {
        upperBounds[i] = IndexBoxCondition::thePosInf;
      }
    }

    if (flags[i].theHaveLowerBound && flags[i].theHaveUpperBound)
    {
      long comp = lowerBounds[i]->compare(upperBounds[i], timezone, collator);

      if (comp > 0 || 
          (comp == 0 && (!flags[i].theLowerBoundIncl || !flags[i].theUpperBoundIncl)))
      { 
        ZORBA_ERROR_PARAM(STR0006_INDEX_INVALID_BOX_PROBE, 
                          theIndex->getName()->getStringValue().c_str(),
                          theBoxCond->toString());
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
void ProbeTreeValueIndexIterator::open()
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
void ProbeTreeValueIndexIterator::reset()
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
void ProbeTreeValueIndexIterator::close()
{
  thePointCond = NULL;
  theBoxCond = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeTreeValueIndexIterator::next(store::Item_t& result)
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


}
}
