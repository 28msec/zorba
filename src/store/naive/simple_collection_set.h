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
#ifndef ZORBA_SIMPLE_STORE_SIMPLE_COLLECTION_SET_H
#define ZORBA_SIMPLE_STORE_SIMPLE_COLLECTION_SET_H

#include "zorbautils/hashmap_itemp.h"
#include "collection_set.h"
#include "store/api/shared_types.h"

namespace zorba {
  
  namespace simplestore {

    class CollectionIterator;
    
    /*******************************************************************************
      Collections container to ease the implementation of stores which contain 
      a different kind of memory management. For the simplestore, the Collections
      is only a wrapper class around an ItemPointerHashMap.
    ********************************************************************************/
    class SimpleCollectionSet : public zorba::store::CollectionSet
    {
    public:
      typedef ItemPointerHashMap<zorba::store::Collection_t> Set;
      static const ulong DEFAULT_COLLECTION_MAP_SIZE;
    
    protected:
      Set  theCollections;
    
    public:
      SimpleCollectionSet();
      
      virtual
      ~SimpleCollectionSet();
    
      virtual void
      clear();
    
      virtual bool
      insert(
          const zorba::store::Item* aName,
          zorba::store::Collection_t& aCollection);
    
      virtual bool
      get(
          const zorba::store::Item* aName,
          zorba::store::Collection_t& aCollection,
          bool aDynamicCollection = false);
    
      virtual bool
      remove(const zorba::store::Item* aName, bool aDynamicCollection = false);
    
      virtual zorba::store::Iterator_t
      names(bool aDynamicCollection = false);
    
      // needs to be virtual to allow implementation of additional stores
      virtual zorba::store::CollectionSetIterator_t
      collections(bool aDynamicCollection = false);
    
    }; /* class CollectionSet */
    
    /*******************************************************************************
      Collection iterator
      Returned by the CollectionSet::collections function
    ********************************************************************************/
    class SimpleCollectionSetIterator : public zorba::store::CollectionSetIterator
    {
    protected:
      SimpleCollectionSet::Set*          theCollections;
      SimpleCollectionSet::Set::iterator theIterator;
      bool                                       theOpened;
      bool                                       theDynamicCollections;
    
    public:
      SimpleCollectionSetIterator(
          SimpleCollectionSet::Set* aCollections,
          bool aDynamicCollections);
    
      virtual ~SimpleCollectionSetIterator();
    
      virtual void
      open();
    
      virtual bool
      next(zorba::store::Collection_t&);
    
      virtual void
      reset();
    
      virtual void
      close() throw();
    };

  } /* namespace simplestore */
} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
