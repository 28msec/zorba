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

/*******************************************************************************
  Collections container to ease the implementation of stores which contain 
  a different kind of memory management. For the simplestore, the Collections
  is only a wrapper class around an ItemPointerHashMap.
********************************************************************************/
class SimpleCollectionSet : public CollectionSet
{
public:
  ITEM_PTR_HASH_MAP(zorba::store::Collection_t, Set);
  
  static const ulong DEFAULT_COLLECTION_MAP_SIZE;
    
protected:
  Set  theCollections;
    
public:
  SimpleCollectionSet();
      
  virtual
  ~SimpleCollectionSet();
    
  virtual void clear();
    
  virtual bool insert(const store::Item* name, store::Collection_t& collection);
    
  virtual bool get(
      const zorba::store::Item* name,
      store::Collection_t& collection,
      bool isDynamic);
  
  virtual bool remove(const store::Item* name, bool isDynamic);
    
  virtual zorba::store::Iterator_t names(bool isDynamic);
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
