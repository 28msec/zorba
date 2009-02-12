
#include "zorbaerrors/Assert.h"
#include "zorbautils/hashfun.h"
#include "store/api/item.h"
#include "store/naive/simple_index.h"
#include "store/naive/atomic_items.h"

#include <algorithm>

namespace zorba 
{ 

namespace simplestore 
{

/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(
    const xqpStringStore_t& uri,
    bool unique,
    bool ordering,
    bool temp)
  :
  theIsUnique(unique),
  theIsOrdering(ordering),
  theIsTemp(temp),
  theIsThreadSafe(!temp)
{
  xqpStringStore_t tmpuri(uri.getp());
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
HashIndex::HashIndex(
    const xqpStringStore_t& uri,
    const std::vector<XQPCollator*>& collators,
    long timezone,
    bool temp)
  :
  IndexImpl(uri, false, false, temp),
  theCompFunction(collators.size(), timezone, collators),
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
void HashIndexProbeIterator::open()
{
  theIndex->theMap.get(theKey, theResultSet);

  theIte = theResultSet->begin();
  theEnd = theResultSet->end();
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
bool HashIndexProbeIterator::next(store::Item_t& result)
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
