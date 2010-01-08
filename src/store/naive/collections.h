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
#ifndef ZORBA_SIMPLE_STORE_COLLECTIONS
#define ZORBA_SIMPLE_STORE_COLLECTIONS

#include "zorbautils/hashmap_itemp.h"
#include "store/api/collection.h"

namespace zorba { namespace simplestore {


/*******************************************************************************
  Collections container to ease the implementation of stores which contain 
  a different kind of memory management. For the simplestore, the Collections
  is only a wrapper class around an ItemPointerHashMap.
********************************************************************************/
class Collections {
public:
  typedef ItemPointerHashMap<store::Collection_t> CollectionSet;
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;

private:
  CollectionSet                                   theCollections;

public:
  class iterator {
  private:
    CollectionSet::iterator theIterator;

  public:
    iterator(CollectionSet::iterator aIterator) : theIterator(aIterator) {}

    bool operator!=(const iterator& aIter) { return theIterator != aIter.theIterator; }
    iterator& operator++() { ++theIterator; return *this; }
    store::Collection_t operator*() { return (*theIterator).second; }
  };

public:
  Collections();
  void clear();
  bool insert ( const store::Item* aName, store::Collection_t& aCollection );  
  bool get ( const store::Item* aName, store::Collection_t& aCollection );
  bool remove ( const store::Item* aName ); 
  store::Iterator_t names();
  iterator begin();
  iterator end();
};

}}

#endif
