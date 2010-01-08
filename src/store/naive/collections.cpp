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
#include "store/naive/collections.h"
#include "store/api/iterator.h"

namespace zorba { namespace simplestore {

class NamesIterator : public store::Iterator {
private:
  Collections::CollectionSet*          theCollections;
  Collections::CollectionSet::iterator theIterator;

public:
  NamesIterator(Collections::CollectionSet& aCollections) 
  {
    theCollections = &aCollections;
  }

  virtual ~NamesIterator() { close(); }

  virtual void open() { theIterator = theCollections->begin(); }

  virtual bool next(store::Item_t& aResult) 
  {
    if (theIterator == theCollections->end()) 
    {
       aResult = NULL;
      return false;
    }
    else
    {
      aResult = (*theIterator).first;
      ++theIterator;
      return true;
    }
  }

  virtual void reset() { theIterator = theCollections->begin(); }

  virtual void close() {}
};

const ulong Collections::DEFAULT_COLLECTION_MAP_SIZE = 32;

Collections::Collections()
  : theCollections(0, NULL, DEFAULT_COLLECTION_MAP_SIZE, true)
{}

void Collections::clear() {
  theCollections.clear();
}

bool Collections::insert ( const store::Item* aName, store::Collection_t& aCollection ) {
  return theCollections.insert(aName, aCollection);
}

bool Collections::get ( const store::Item* aName, store::Collection_t& aCollection ) {
  return theCollections.get(aName, aCollection);
}

bool Collections::remove ( const store::Item* aName ) {
  return theCollections.remove(aName);
}

store::Iterator_t Collections::names () {
  return new NamesIterator(theCollections);
}

Collections::iterator Collections::begin () {
  Collections::iterator lIter (theCollections.begin());
  return lIter;
}

Collections::iterator Collections::end () {
  Collections::iterator lIter (theCollections.end());
  return lIter;
}

}}
