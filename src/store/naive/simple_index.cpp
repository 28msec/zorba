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

#include "zorbaerrors/Assert.h"
#include "zorbautils/hashfun.h"
#include "zorbatypes/collation_manager.h"

#include "store/api/item.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_index.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"

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
IndexImpl::IndexImpl(
    const xqpStringStore_t& uri,
    const store::IndexSpecification& spec)
  :
  theSpec(spec),
  theNumColumns(theSpec.theKeyTypes.size())
{
  xqpStringStore_t tmpuri(uri.getp());
  theUri = new AnyUriItemImpl(tmpuri);

  theCollators.resize(theNumColumns);

  for (ulong i = 0; i < theNumColumns; i++)
  {
    if (spec.theKeyTypes[i] == GET_STORE().theSchemaTypeNames[XS_STRING] ||
        spec.theKeyTypes[i] == GET_STORE().theSchemaTypeNames[XS_NORMALIZED_STRING])
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
  for (ulong i = 0; i < theNumColumns; i++)
  {
    if (theCollators[i])
      delete theCollators[i]; 
  }
}


/******************************************************************************

********************************************************************************/
store::IndexEntryReceiver_t IndexImpl::createInsertSession()
{
  return new IndexEntryReceiverImpl(this);
}


/******************************************************************************

********************************************************************************/
store::IndexPointCondition_t IndexImpl::createPointCondition()
{
  return new IndexPointConditionImpl(this);
}


/******************************************************************************

********************************************************************************/
store::IndexBoxCondition_t IndexImpl::createBoxCondition()
{
  return new IndexBoxConditionImpl(this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Hash Index                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
uint32_t HashIndex::CompareFunction::hash(const store::IndexKey* key) const
{
  uint32_t hval = FNV_32_INIT;

  for (ulong i = 0; i < theNumColumns; i++)
  {
    hval = hashfun::h32<uint32_t>((*key)[i]->hash(theTimezone, theCollators[i]),
                                  hval);
  }

  return hval;
}


/******************************************************************************

********************************************************************************/
bool HashIndex::CompareFunction::equal(
    const store::IndexKey* key1,
    const store::IndexKey* key2) const
{
  for (ulong i = 0; i < theNumColumns; i++)
  {
    if (! (*key1)[i]->equals((*key2)[i].getp(), theTimezone, theCollators[i]))
      return false;
  }
  return true;
}


/******************************************************************************

********************************************************************************/
HashIndex::HashIndex(
    const xqpStringStore_t& uri,
    const store::IndexSpecification& spec)
  :
  IndexImpl(uri, spec),
  theCompFunction(theNumColumns, spec.theTimezone, theCollators),
  theMap(theCompFunction, 1024, spec.theIsThreadSafe)
{
}
  

/******************************************************************************

********************************************************************************/
HashIndex::~HashIndex()
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


/******************************************************************************

********************************************************************************/
bool HashIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumColumns)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_PARTIAL_KEY_INSERT,
                      theUri->getStringValue()->c_str(), key.toString());
  }

  ValueSet* valueSet = NULL;

  if (!isUnique() &&
      theMap.get(&key, valueSet))
  {
    valueSet->resize(valueSet->size() + 1);
    (*valueSet)[valueSet->size()-1].transfer(value);
    return true;
  }

  store::IndexKey* keycopy = new store::IndexKey(key.size());

  for (ulong i = 0; i < theNumColumns; i++)
    (*keycopy)[i].transfer(key[i]);

  valueSet = new ValueSet(1);
  (*valueSet)[0].transfer(value);
  
  const store::IndexKey* constkey = keycopy;

  //  std::cout << "Index Entry Insert [" << constkey << "," 
  //          << valueSet << "]" << std::endl;

  theMap.insert(constkey, valueSet);

  return false;
} 



/******************************************************************************

********************************************************************************/
bool HashIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumColumns)
  {
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_REMOVE,
                      theUri->getStringValue()->c_str(), key.toString());
  }

  IndexMap::iterator pos = theMap.get(&key);

  if (pos != theMap.end())
  {
    const store::IndexKey* keyp = (*pos).first;
    ValueSet* valueSet = (*pos).second;

    ValueSet::iterator valIte = std::find(valueSet->begin(),
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


/******************************************************************************

********************************************************************************/
bool HashIndex::probe(const store::IndexKey& key, store::Item_t& result)
{
  return false;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  STL Map Index                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
long STLMapIndex::CompareFunction::compare(
    const store::IndexKey* key1,
    const store::IndexKey* key2) const
{
  long result;

#ifndef WIN32
  ulong size = std::min(key1->size(),  key2->size());
#else
  ulong size = min(key1->size(),  key2->size());
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
    else if (i1 == IndexBoxConditionImpl::theNegInf)
    {
      return -1;
    }
    else if (i1 == IndexBoxConditionImpl::thePosInf)
    {
      return +1;
    }
    else if (i2 == IndexBoxConditionImpl::theNegInf)
    {
      return +1;
    }
    else if (i2 == IndexBoxConditionImpl::thePosInf)
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


/******************************************************************************

********************************************************************************/
STLMapIndex::STLMapIndex(
    const xqpStringStore_t& uri,
    const store::IndexSpecification& spec)
  :
  IndexImpl(uri, spec),
  theCompFunction(theNumColumns, spec.theTimezone, theCollators),
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
bool STLMapIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumColumns)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_PARTIAL_KEY_INSERT,
                      theUri->getStringValue()->c_str(), key.toString());
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  if (!isUnique())
  {
    // TODO: optimize this using the lower_bound() method.
    IndexMap::iterator pos = theMap.find(&key);

    if (pos != theMap.end())
    {
      pos->second->transfer_back(value);
      return true;
    }
  }

  store::IndexKey* keycopy = new store::IndexKey(key.size());

  for (ulong i = 0; i < theNumColumns; i++)
    (*keycopy)[i].transfer(key[i]);
  
  ValueSet* valueSet = new ValueSet(1);
  (*valueSet)[0].transfer(value);

  theMap.insert(STLMapPair(keycopy, valueSet));

  return false;
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumColumns)
  {
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_REMOVE,
                      theUri->getStringValue()->c_str(), "");
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  IndexMap::iterator pos = theMap.find(&key);

  if (pos != theMap.end())
  {
    const store::IndexKey* keyp = pos->first;
    ValueSet* valueSet = (*pos).second;

    ValueSet::iterator valIte = std::find(valueSet->begin(),
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


/******************************************************************************

********************************************************************************/
bool STLMapIndex::probe(const store::IndexKey& key, store::Item_t& result)
{
  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  HashProbeIterator                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void HashProbeIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::EXACT_KEY)
  {
    ZORBA_ERROR_PARAM(STR0006_INDEX_UNSUPPORTED_PROBE_CONDITION,
                      theIndex->getUri()->getStringValue()->c_str(), 
                      cond->getKindString());
  }

  theCondition = reinterpret_cast<IndexPointConditionImpl*>(cond.getp());

  store::IndexKey* key = &(theCondition->theKey);

  if (key->size() != theIndex->getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->getUri()->getStringValue()->c_str(),
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
void HashProbeIterator::open()
{
  if (theResultSet)
    theIte = theResultSet->begin();
}


/******************************************************************************

********************************************************************************/
void HashProbeIterator::reset()
{
  if (theResultSet)
    theIte = theResultSet->begin(); 
}


/******************************************************************************

********************************************************************************/
void HashProbeIterator::close()
{
  theCondition = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool HashProbeIterator::next(store::Item_t& result)
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
//  STLMapProbeIterator                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void STLMapProbeIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() == store::IndexCondition::EXACT_KEY)
  {
    thePointCond = reinterpret_cast<IndexPointConditionImpl*>(cond.getp());

    initExact();
  }
  else
  {
    theBoxCond = reinterpret_cast<IndexBoxConditionImpl*>(cond.getp());

    initBox();
  }
}


/******************************************************************************

********************************************************************************/
void STLMapProbeIterator::initExact()
{
  const store::IndexKey& key = thePointCond->theKey;

  if (key.size() != theIndex->theNumColumns)
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->theUri->getStringValue()->c_str(), 
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
void STLMapProbeIterator::initBox()
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
    ZORBA_ERROR_PARAM(STR0005_INDEX_INVALID_BOX_PROBE, 
                      theIndex->theUri->getStringValue()->c_str(),
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

  const std::vector<IndexBoxConditionImpl::RangeFlags>& flags = 
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
        lowerBounds[i] = IndexBoxConditionImpl::theNegInf;
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
        upperBounds[i] = IndexBoxConditionImpl::thePosInf;
      }
    }

    if (flags[i].theHaveLowerBound && flags[i].theHaveUpperBound)
    {
      long comp = lowerBounds[i]->compare(upperBounds[i], timezone, collator);

      if (comp > 0 || 
          (comp == 0 && (!flags[i].theLowerBoundIncl || !flags[i].theUpperBoundIncl)))
      { 
        ZORBA_ERROR_PARAM(STR0005_INDEX_INVALID_BOX_PROBE, 
                          theIndex->theUri->getStringValue()->c_str(),
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
void STLMapProbeIterator::open()
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
void STLMapProbeIterator::reset()
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
void STLMapProbeIterator::close()
{
  thePointCond = NULL;
  theBoxCond = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool STLMapProbeIterator::next(store::Item_t& result)
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexPointCondition                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void IndexPointConditionImpl::clear()
{
  theKey.clear();
}


/*******************************************************************************

********************************************************************************/
void IndexPointConditionImpl::pushItem(store::Item_t& item)
{
  theKey.transfer_back(item);
}


/*******************************************************************************

********************************************************************************/
bool IndexPointConditionImpl::test(const store::IndexKey& key) const
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
std::string IndexPointConditionImpl::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const IndexPointConditionImpl& cond)
{
  os << "{ " << cond.getKey() << " }";
  return os;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IndexBoxCondition                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


store::Item_t IndexBoxConditionImpl::theNegInf(new AtomicItem);
store::Item_t IndexBoxConditionImpl::thePosInf(new AtomicItem);


/*******************************************************************************

********************************************************************************/
void IndexBoxConditionImpl::clear()
{
  theLowerBounds.clear();
  theUpperBounds.clear();
  theRangeFlags.clear();
}


/*******************************************************************************

********************************************************************************/
void IndexBoxConditionImpl::pushRange(
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


/*******************************************************************************

********************************************************************************/
bool IndexBoxConditionImpl::test(const store::IndexKey& key) const
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
std::string IndexBoxConditionImpl::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const IndexBoxConditionImpl& cond)
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
        os << "[" << cond.theLowerBounds[i]->getStringValue()->c_str();
      else
        os << "(" << cond.theLowerBounds[i]->getStringValue()->c_str();
    }
    
    os << ", ";


    if (!cond.theRangeFlags[i].theHaveUpperBound)
    {
      os << "+INF] ";
    }
    else 
    {
      if (cond.theRangeFlags[i].theUpperBoundIncl)
        os << cond.theUpperBounds[i]->getStringValue()->c_str() << "] ";
      else
        os << cond.theUpperBounds[i]->getStringValue()->c_str() << ") ";
    }
  }

  os << "}";

  return os;
}


}
}
