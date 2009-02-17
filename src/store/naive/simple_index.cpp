
#include "zorbaerrors/Assert.h"
#include "zorbautils/hashfun.h"
#include "zorbatypes/collation_manager.h"
#include "store/api/item.h"
#include "store/naive/simple_index.h"
#include "store/naive/atomic_items.h"

#include <algorithm>

namespace zorba 
{ 

store::IndexKey store::IndexProbeIterator::thePosInfKey;
store::IndexKey store::IndexProbeIterator::theNegInfKey;


namespace simplestore 
{


/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(const store::IndexSpecification& spec)
  :
  theSpec(spec),
  theNumKeyComps(theSpec.theKeyTypes.size())
{
  xqpStringStore_t tmpuri(spec.theUri.getp());
  theUri = new AnyUriItemImpl(tmpuri);

  theCollators.resize(theNumKeyComps);

  for (ulong i = 0; i < theNumKeyComps; i++)
    theCollators[i] = CollationFactory::createCollator(spec.theCollations[i]);
}


/******************************************************************************

********************************************************************************/
IndexImpl::~IndexImpl()
{
  for (ulong i = 0; i < theNumKeyComps; i++)
    delete theCollators[i]; 
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

  for (ulong i = 0; i < theNumKeyComps; i++)
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
  for (ulong i = 0; i < theNumKeyComps; i++)
  {
    if (! (*key1)[i]->equals((*key2)[i].getp(), theTimezone, theCollators[i]))
      return false;
  }
  return true;
}


/******************************************************************************

********************************************************************************/
HashIndex::HashIndex(const store::IndexSpecification& spec)
  :
  IndexImpl(spec),
  theCompFunction(theNumKeyComps, spec.theTimezone, theCollators),
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
    delete (*ite).first;
    delete (*ite).second;
  }
}


/******************************************************************************

********************************************************************************/
bool HashIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumKeyComps)
    ZORBA_ERROR_PARAM(STR0002_INDEX_PARTIAL_KEY_INSERT,
                      theUri->getStringValue()->c_str(), "");

  ValueSet* valueSet;

  bool found = theMap.get(&key, valueSet);

  if (found)
  {
    valueSet->resize(valueSet->size() + 1);
    (*valueSet)[valueSet->size()-1].transfer(value);
  }
  else
  {
    ulong numKeyComps = theCompFunction.theNumKeyComps;

    store::IndexKey* keycopy = new store::IndexKey(key.size());

    for (ulong i = 0; i < numKeyComps; i++)
      (*keycopy)[i].transfer(key[i]);

    valueSet = new ValueSet(1);
    (*valueSet)[0].transfer(value);

    theMap.insert(keycopy, valueSet);
  }

  return found;
} 



/******************************************************************************

********************************************************************************/
bool HashIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumKeyComps)
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_REMOVE,
                      theUri->getStringValue()->c_str(), "");

  store::IndexKey* keyp = const_cast<store::IndexKey*>(&key);

  IndexMap::iterator pos = theMap.get(keyp);

  if (pos != theMap.end())
  {
    keyp = (*pos).first;
    ValueSet* valueSet = (*pos).second;

    ValueSet::iterator valIte = std::find(valueSet->begin(),
                                          valueSet->end(),
                                          value);

    if (valIte != valueSet->end())
      valueSet->erase(valIte);

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
void HashIndexProbeIterator::init(store::IndexKey& key)
{
  theKey = &key;
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::init(
    store::IndexKey& lowKey,
    store::IndexKey& highKey,
    bool lowInclusive,
    bool highInclusive)
{
  ZORBA_ASSERT(false);
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::open()
{
  theIndex->theMap.get(theKey, theResultSet);

  if (theResultSet)
  {
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::reset()
{
  theResultSet = NULL;
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::close()
{
  theIndex = NULL;
  theKey = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
store::Item* HashIndexProbeIterator::next()
{
  if (theResultSet && theIte != theEnd)
  {
    store::Item* result = (*theIte).getp();
    ++theIte;
    return result;
  }

  return NULL;
}


/******************************************************************************

********************************************************************************/
bool HashIndexProbeIterator::next(store::Item_t& result)
{
  if (theResultSet && theIte != theEnd)
  {
    result = (*theIte);
    ++theIte;
    return result;
  }

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

  ulong size1 = key1->size();
  ulong size2 = key2->size();

  if (size1 < size2)
  {
    for (ulong i = 0; i < size1; i++)
    {
      if ((result = (*key1)[i]->compare((*key2)[i])))
        return result;
    }

    return -1;
  }
  else if (size1 == size2)
  {
    for (ulong i = 0; i < size1; i++)
    {
      if ((result = (*key1)[i]->compare((*key2)[i])))
        return result;
    }

    return 0;
  }
  else
  {
    for (ulong i = 0; i < size2; i++)
    {
      if ((result = (*key1)[i]->compare((*key2)[i])))
        return result;
    }

    return 1;
  }
}


/******************************************************************************

********************************************************************************/
STLMapIndex::STLMapIndex(const store::IndexSpecification& spec)
  :
  IndexImpl(spec),
  theCompFunction(theNumKeyComps, spec.theTimezone, theCollators),
  theMap(theCompFunction)
{
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  return true;
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  return true;
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::init(store::IndexKey& key)
{
  theLowKey = &key;
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::init(
    store::IndexKey& lowKey,
    store::IndexKey& highKey,
    bool lowIncl,
                                    bool highIncl)
{
  theLowKey = &lowKey;
  theHighKey = &highKey;
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::open()
{
  if (theHighKey == NULL)
  {
    theResultSet = theIndex->theMap[theLowKey];
  }
  else if (theLowKey != &store::IndexProbeIterator::theNegInfKey)
  {
    theResultSet = theIndex->theMap.begin()->second;
  }
  else
  {
    STLMapIndex::STLMapPair key(theLowKey, NULL);

    STLMapIndex::IndexMap::iterator res =
      std::lower_bound(theIndex->theMap.begin(),
                       theIndex->theMap.end(),
                       key,
                       theIndex->theCompFunction);

    theResultSet = res->second;
  }

  theIte = theResultSet->begin();
  theEnd = theResultSet->end();
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::reset()
{
  theResultSet = NULL;
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::close()
{
  theIndex = NULL;
  theLowKey = NULL;
  theHighKey = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
store::Item* STLMapIndexProbeIterator::next()
{
  ZORBA_ASSERT(theResultSet != NULL);

  if (theIte != theEnd)
  {
    store::Item* result = (*theIte).getp();
    ++theIte;
    return result;
  }

  return NULL;
}


/******************************************************************************

********************************************************************************/
bool STLMapIndexProbeIterator::next(store::Item_t& result)
{
  ZORBA_ASSERT(theResultSet != NULL);

  if (theIte != theEnd)
  {
    result = (*theIte);
    ++theIte;
    return result;
  }

  return false;
}


}
}
