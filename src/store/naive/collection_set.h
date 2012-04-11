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
#ifndef ZORBA_SIMPLE_STORE_COLLECTION_SET_H
#define ZORBA_SIMPLE_STORE_COLLECTION_SET_H

#include "store/api/shared_types.h"
#include "shared_types.h"
#include "zorbautils/hashmap_itemp.h"
#include "store/api/collection.h"

namespace zorba {
  
namespace simplestore {

/*******************************************************************************
  Collections container to ease the implementation of stores which contain 
  a different kind of memory management.
********************************************************************************/
class CollectionSet
{
public:
  virtual ~CollectionSet() {}
    
  virtual void
  clear() = 0;
    
  virtual bool
  insert(const store::Item* name, store::Collection_t& collection) = 0;
    
  virtual bool
  get(
      const store::Item* name,
      store::Collection_t& collection,
      bool isDynamic) = 0;
    
  virtual bool
  remove(const store::Item* name, bool isDynamic) = 0;
  
  virtual store::Iterator_t
  names(bool dynamic) = 0;
    
  virtual CollectionSetIterator_t
  collections(bool dynamic) = 0;
};
    

/*******************************************************************************
  Collection iterator
  Returned by the CollectionSet::collections function
********************************************************************************/
class CollectionSetIterator : public SimpleRCObject
{
public:
  virtual ~CollectionSetIterator() {}
    
  virtual void
  open() = 0;
    
  virtual bool
  next(store::Collection_t&) = 0;
    
  virtual void
  reset() = 0;
    
  virtual void
  close() throw() = 0;
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
