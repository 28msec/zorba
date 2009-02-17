
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

store::IndexKey store::IndexProbeIterator::thePosInfKey;
store::IndexKey store::IndexProbeIterator::theNegInfKey;


namespace simplestore 
{


/******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const store::IndexKey& key)
{
  ulong size = key.size();

  os << "[";

  for (ulong i = 0; i < size; i++)
    os << key[i]->getStringValue()->c_str();

  os << "]";

  return os;
}


/******************************************************************************

********************************************************************************/
std::string toString(const store::IndexKey& key)
{
  std::ostringstream str;
  str << key;
  return str.str();
}


/******************************************************************************

********************************************************************************/
IndexImpl::IndexImpl(
    const xqpStringStore_t& uri,
    const store::IndexSpecification& spec)
  :
  theSpec(spec),
  theNumKeyComps(theSpec.theKeyTypes.size())
{
  xqpStringStore_t tmpuri(uri.getp());
  theUri = new AnyUriItemImpl(tmpuri);

  theCollators.resize(theNumKeyComps);

  for (ulong i = 0; i < theNumKeyComps; i++)
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
HashIndex::HashIndex(
    const xqpStringStore_t& uri,
    const store::IndexSpecification& spec)
  :
  IndexImpl(uri, spec),
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
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_PARTIAL_KEY_INSERT,
                      theUri->getStringValue()->c_str(), "");
  }

  ValueSet* valueSet;

  if (!isUnique() &&
      theMap.get(&key, valueSet))
  {
    valueSet->resize(valueSet->size() + 1);
    (*valueSet)[valueSet->size()-1].transfer(value);
  }

  store::IndexKey* keycopy = new store::IndexKey(key.size());

  for (ulong i = 0; i < theNumKeyComps; i++)
    (*keycopy)[i].transfer(key[i]);

  valueSet = new ValueSet(1);
  (*valueSet)[0].transfer(value);
  
  theMap.insert(keycopy, valueSet);

  return false;
} 



/******************************************************************************

********************************************************************************/
bool HashIndex::remove(const store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumKeyComps)
  {
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_REMOVE,
                      theUri->getStringValue()->c_str(), "");
  }

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
  if (key.size() != theIndex->theNumKeyComps)
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->theUri->getStringValue()->c_str(), "");
  }

  theKey = &key;

  theIndex->theMap.get(theKey, theResultSet);

  if (theResultSet)
  {
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
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
  if (theResultSet)
    theIte = theResultSet->begin();
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::reset()
{
  if (theResultSet)
    theIte = theResultSet->begin(); 
}


/******************************************************************************

********************************************************************************/
void HashIndexProbeIterator::close()
{
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
  result = next();
  return (result != NULL);
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

  ulong size = std::min(key1->size(),  key2->size());

  for (ulong i = 0; i < size; i++)
  {
    if ((result = (*key1)[i]->compare((*key2)[i])))
      return result;
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
  theCompFunction(theNumKeyComps, spec.theTimezone, theCollators),
  theMap(theCompFunction)
{
}


/******************************************************************************

********************************************************************************/
STLMapIndex::~STLMapIndex()
{
}


/******************************************************************************

********************************************************************************/
bool STLMapIndex::insert(store::IndexKey& key, store::Item_t& value)
{
  if (key.size() != theNumKeyComps)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_PARTIAL_KEY_INSERT,
                      theUri->getStringValue()->c_str(), "");
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  if (!isUnique())
  {
    // TODO: optimize this using the lower_bound() method.
    IndexMap::iterator pos = theMap.find(&key);

    if (pos != theMap.end())
    {
      pos->second->push_back(value);
      return true;
    }
  }

  store::IndexKey* keycopy = new store::IndexKey(key.size());

  for (ulong i = 0; i < theNumKeyComps; i++)
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
  if (key.size() != theNumKeyComps)
  {
    ZORBA_ERROR_PARAM(STR0003_INDEX_PARTIAL_KEY_REMOVE,
                      theUri->getStringValue()->c_str(), "");
  }

  SYNC_CODE(AutoMutex lock((isThreadSafe() ? &theMapMutex : NULL));)

  store::IndexKey* keyp = const_cast<store::IndexKey*>(&key);

  IndexMap::iterator pos = theMap.find(keyp);

  if (pos != theMap.end())
  {
    keyp = pos->first;
    ValueSet* valueSet = (*pos).second;

    ValueSet::iterator valIte = std::find(valueSet->begin(),
                                          valueSet->end(),
                                          value);

    if (valIte != valueSet->end())
      valueSet->erase(valIte);

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
void STLMapIndexProbeIterator::init(store::IndexKey& key)
{
  if (key.size() != theIndex->theNumKeyComps)
  {
    ZORBA_ERROR_PARAM(STR0004_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->theUri->getStringValue()->c_str(), "");
  }

  theLowKey = &key;
  theHighKey = NULL;

  theMapBegin = theIndex->theMap.find(theLowKey);

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
void STLMapIndexProbeIterator::init(
    store::IndexKey& lowKey,
    store::IndexKey& highKey,
    bool lowIncl,
    bool highIncl)
{
  theLowKey = &lowKey;
  theHighKey = &highKey;
  theLowIncl = lowIncl;
  theHighIncl = highIncl;

  // Check for invalid range 
  if (theLowKey == &store::IndexProbeIterator::thePosInfKey ||
      theHighKey == &store::IndexProbeIterator::theNegInfKey ||
      (theLowKey != &store::IndexProbeIterator::theNegInfKey &&
       theHighKey != &store::IndexProbeIterator::thePosInfKey &&
       theIndex->theCompFunction.compare(theLowKey, theHighKey) > 0))
  {
    ZORBA_ERROR_PARAM(STR0005_INDEX_INVALID_SCAN_RANGE, 
                      theIndex->theUri->getStringValue()->c_str(), "");
  }


  if (theLowKey == &store::IndexProbeIterator::theNegInfKey)
  {
    theMapBegin = theIndex->theMap.begin();
  }
  else if (theLowIncl)
  {
    theMapBegin = theIndex->theMap.lower_bound(theLowKey);

    if (theMapBegin == theIndex->theMap.end())
    {
      theMapEnd = theMapBegin;
      return;
    }
  }
  else
  {
    theMapBegin = theIndex->theMap.upper_bound(theLowKey);

    if (theMapBegin == theIndex->theMap.end())
    {
      theMapEnd = theMapBegin;
      return;
    }
    else
    {
      ++theMapBegin;
    }
  }


  if (theHighKey == &store::IndexProbeIterator::thePosInfKey)
  {
    theMapEnd = theIndex->theMap.end();
  }
  else if (theHighIncl)
  {
    theMapEnd = theIndex->theMap.upper_bound(theHighKey);

    if (theMapEnd == theIndex->theMap.begin())
    {
      assert(theMapBegin == theMapEnd);

      if (theIndex->theCompFunction.compare(theHighKey, theMapEnd->first) < 0)
      {
        theMapEnd = theMapBegin = theIndex->theMap.end();
        return;
      }
    }
  }
  else
  {
    theMapEnd = theIndex->theMap.lower_bound(theHighKey);

    if (theMapEnd == theIndex->theMap.begin())
    {
      assert(theMapBegin == theMapEnd);

      if (theIndex->theCompFunction.compare(theHighKey, theMapEnd->first) < 0)
      {
        theMapEnd = theMapBegin = theIndex->theMap.end();
        return;
      }
    }
    else if (theMapEnd != theIndex->theMap.end())
    {
      --theMapEnd;
    }
  }
}


/******************************************************************************

********************************************************************************/
void STLMapIndexProbeIterator::open()
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
void STLMapIndexProbeIterator::reset()
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
void STLMapIndexProbeIterator::close()
{
  theLowKey = NULL;
  theHighKey = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
store::Item* STLMapIndexProbeIterator::next()
{
  if (theResultSet != NULL)
  {
    if (theIte != theEnd)
    {
      store::Item* result = (*theIte).getp();
      ++theIte;
      return result;
    }
    else if (theMapIte != theMapEnd)
    {
      theMapIte++;
      theResultSet = theMapIte->second;
      theIte = theResultSet->begin();
      theEnd = theResultSet->end();

      store::Item* result = (*theIte).getp();
      ++theIte;
      return result;
    }
  }

  return NULL;
}


/******************************************************************************

********************************************************************************/
bool STLMapIndexProbeIterator::next(store::Item_t& result)
{
  result = next();
  return (result != NULL);
}


}
}
