
#include "zorbaerrors/Assert.h"
#include "zorbautils/hashfun.h"
#include "store/api/item.h"
#include "store/naive/simple_index.h"
#include "store/naive/atomic_items.h"

#include <algorithm>

namespace zorba 
{ 

store::IndexKey store::Index::thePosInfKey;
store::IndexKey store::Index::theNegInfKey;


namespace simplestore 
{


/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(const store::IndexSpecification& spec)
  :
  theIsUnique(spec.theIsUnique),
  theIsOrdering(spec.theIsOrdering),
  theIsTemp(spec.theIsTemp),
  theIsThreadSafe(!theIsTemp)
{
  xqpStringStore_t tmpuri(spec.theUri.getp());
  theUri = new AnyUriItemImpl(tmpuri);
}


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
  theCompFunction(spec.theCollators.size(), spec.theTimezone, spec.theCollators),
  theMap(theCompFunction, 1024, theIsThreadSafe)
{
}
  

/******************************************************************************

********************************************************************************/
bool HashIndex::insert(store::IndexKey& key, store::Item_t& value)
{
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
  ValueSet* valueSet;

  store::IndexKey* keyp = const_cast<store::IndexKey*>(&key);

  bool found = theMap.get(keyp, valueSet);

  if (found)
  {
    ValueSet::iterator ite = std::find(valueSet->begin(), valueSet->end(), value);
    valueSet->erase(ite);

    if (valueSet->empty())
      theMap.remove(keyp);
  }

  return found;
} 


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::init(store::IndexKey& key)
{
  theKey = &key;
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::init(store::IndexKey& lowKey, store::IndexKey& highKey)
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
  theCompFunction(spec.theCollators.size(), spec.theTimezone, spec.theCollators),
  theMap(theCompFunction)
{
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  SYNC_CODE(AutoMutex lock((theIsThreadSafe ? &theMapMutex : NULL));)

  return true;
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  SYNC_CODE(AutoMutex lock((theIsThreadSafe ? &theMapMutex : NULL));)

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
    store::IndexKey& highKey)
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
  else if (theLowKey != &store::Index::theNegInfKey)
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
