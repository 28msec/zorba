/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#include "simple_collection_set.h"
#include "store/api/iterator.h"
#include "name_iterator.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleCollectionSetIterator::SimpleCollectionSetIterator(
    SimpleCollectionSet::Set* aCollections,
    bool aDynamicCollection) 
  : 
  theCollections(aCollections),
  theOpened(false),
  theDynamicCollections(aDynamicCollection)
{ 
}


SimpleCollectionSetIterator::~SimpleCollectionSetIterator()
{
  close();
}


void
SimpleCollectionSetIterator::open()
{
  theIterator = theCollections->begin();
  theOpened = true;
}


bool
SimpleCollectionSetIterator::next(zorba::store::Collection_t& aResult) 
{
  while (theIterator != theCollections->end()) 
  {
    aResult = (*theIterator).second;
    if (aResult->isDynamic() != theDynamicCollections) {
      ++theIterator;
      continue;
    } else {
      ++theIterator;
      return true;
    }
  }
  aResult = NULL;
  return false;
}


void
SimpleCollectionSetIterator::reset()
{
  theIterator = theCollections->begin();
}


void
SimpleCollectionSetIterator::close() throw()
{
  if (!theOpened) {
    return;
  }
  theOpened = false;
}


/*******************************************************************************

********************************************************************************/
const ulong SimpleCollectionSet::DEFAULT_COLLECTION_MAP_SIZE = 32;


SimpleCollectionSet::SimpleCollectionSet()
  :
  theCollections(HashMapItemPointerCmp(0, NULL), DEFAULT_COLLECTION_MAP_SIZE, true)
{
}


SimpleCollectionSet::~SimpleCollectionSet()
{
}


void SimpleCollectionSet::clear() 
{
  theCollections.clear();
}


bool SimpleCollectionSet::insert(
    const zorba::store::Item* aName,
    zorba::store::Collection_t& aCollection)
{
  store::Item* qname = const_cast<store::Item*>(aName);

  return theCollections.insert(qname, aCollection);
}


bool SimpleCollectionSet::get(
    const zorba::store::Item* aName,
    zorba::store::Collection_t& aCollection,
    bool aDynamicCollection) 
{
  if (theCollections.get(const_cast<zorba::store::Item*>(aName), aCollection)) 
  {
    return aCollection->isDynamic() == aDynamicCollection;
  }
  else 
  {
    return false;
  }
}


bool SimpleCollectionSet::remove(
    const zorba::store::Item* aName,
    bool aDynamicCollection) 
{
  zorba::store::Collection_t lColl;
  if (!get(aName, lColl, aDynamicCollection))
  {
    return false;
  }
  else
  {
    return theCollections.erase(const_cast<zorba::store::Item*>(aName));
  }
}


zorba::store::Iterator_t SimpleCollectionSet::names(bool aDynamicCollections) 
{
  return new NameIterator<Set>(theCollections, aDynamicCollections);
}


CollectionSetIterator_t SimpleCollectionSet::collections(bool aDynamicCollections) 
{
  return new SimpleCollectionSetIterator(&theCollections,
                                         aDynamicCollections);
}

// specialize the next function of the NameIterator for
// the SimpleCollectionSet in order to be able to handle dynamic collections
template<> bool
NameIterator<SimpleCollectionSet::Set>::next(zorba::store::Item_t& aResult)
{
  while (theIterator != theItems.end())
  {
    if ((*theIterator).second->isDynamic() != theDynamicCollections)
    {
      ++theIterator;
      continue;
    } else
    {
      aResult = (*theIterator).first;
      ++theIterator;
      return true;
    }
  }
  aResult = NULL;
  return false;
}


} /* namespace simplestore */
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
