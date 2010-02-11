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
#include "store/naive/collection_set.h"
#include "store/api/iterator.h"
#include "store/naive/name_iterator.h"

namespace zorba { namespace simplestore {

/*******************************************************************************
********************************************************************************/
CollectionIterator::CollectionIterator(CollectionSet::Set* aCollections) 
  : theCollections(aCollections),
    theOpened(false)
{ }

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
  if (theIterator == theCollections->end()) 
  {
    aResult = NULL;
    return false;
  }
  else
  {
    aResult = (*theIterator).second;
    ++theIterator;
    return true;
  }
}

void
CollectionIterator::reset()
{
  theIterator = theCollections->begin();
}

void
CollectionIterator::close()
{
  if (!theOpened) {
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


bool CollectionSet::insert(const store::Item* aName, store::Collection_t& aCollection )
{
  return theCollections.insert(aName, aCollection);
}


bool CollectionSet::get(const store::Item* aName, store::Collection_t& aCollection ) 
{
  return theCollections.get(aName, aCollection);
}


bool CollectionSet::remove(const store::Item* aName ) 
{
  return theCollections.remove(aName);
}


store::Iterator_t CollectionSet::names() 
{
  return new NameIterator<Set>(theCollections);
}


CollectionIterator_t CollectionSet::collections() 
{
  return new CollectionIterator(&theCollections);
}


} /* namespace simplestore */
} /* namespace zorba */
