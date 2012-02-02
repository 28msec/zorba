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

#include "store/naive/collection_set.h"
#include "store/api/iterator.h"
#include "store/naive/name_iterator.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
CollectionIterator::CollectionIterator(
    CollectionSet::Set* aCollections,
    bool aDynamicCollection) 
  : 
  theCollections(aCollections),
  theOpened(false),
  theDynamicCollections(aDynamicCollection)
{ 
}


CollectionIterator::~CollectionIterator()
{
  close();
}


void
CollectionIterator::open()
{
  theIterator = theCollections->begin();
  theOpened = true;
}


bool
CollectionIterator::next(store::Collection_t& aResult) 
{
  while (theIterator != theCollections->end()) 
  {
    aResult = (*theIterator).second;
    if (aResult->isDynamic() != theDynamicCollections) 
    {
      ++theIterator;
      continue;
    }
    else
    {
      ++theIterator;
      return true;
    }
  }
  aResult = NULL;
  return false;
}


void
CollectionIterator::reset()
{
  theIterator = theCollections->begin();
}


void
CollectionIterator::close()
{
  if (!theOpened) 
  {
    return;
  }
  theOpened = false;
}


/*******************************************************************************

********************************************************************************/
const ulong CollectionSet::DEFAULT_COLLECTION_MAP_SIZE = 32;


CollectionSet::CollectionSet()
  :
  theCollections(0, NULL, DEFAULT_COLLECTION_MAP_SIZE, true)
{
}


void CollectionSet::clear() 
{
  theCollections.clear();
}


bool CollectionSet::insert(const store::Item* name, store::Collection_t& collection)
{
  store::Item* qname = const_cast<store::Item*>(name);

  return theCollections.insert(qname, collection);
}


bool CollectionSet::get(
    const store::Item* name,
    store::Collection_t& collection,
    bool isDynamic,
    bool isJSONIQ) 
{
  if (theCollections.get(const_cast<store::Item*>(name), collection)) 
  {
    return (collection->isDynamic() == isDynamic &&
            collection->isJSONIQ() == isJSONIQ);
  }
  else 
  {
    return false;
  }
}


bool CollectionSet::remove(
    const store::Item* name,
    bool isDynamic,
    bool isJSONIQ) 
{
  store::Collection_t lColl;
  if (!get(name, lColl, isDynamic, isJSONIQ))
  {
    return false;
  }
  else
  {
    return theCollections.erase(const_cast<store::Item*>(name));
  }
}


store::Iterator_t CollectionSet::names(bool dynamic, bool jsoniq)
{
  return new NameIterator<Set>(theCollections, dynamic, jsoniq);
}


CollectionIterator_t CollectionSet::collections(bool dynamic) 
{
  return new CollectionIterator(&theCollections, dynamic);
}


// specialize the next function of the NameIterator for
// the CollectionSet in order to be able to handle dynamic collections
template<> bool
NameIterator<CollectionSet::Set>::next(store::Item_t& aResult)
{
  while (theIterator != theItems.end())
  {
    if ((*theIterator).second->isDynamic() != theDynamicCollections)
    {
      ++theIterator;
      continue;
    } 
    else if ((*theIterator).second->isJSONIQ() != theJSONIQCollections)
    {
      ++theIterator;
      continue;
    } 
    else
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
