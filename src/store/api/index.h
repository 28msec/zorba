/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#ifndef ZORBA_STORE_INDEX
#define ZORBA_STORE_INDEX

#include "store/api/shared_types.h"


namespace zorba 
{

namespace store 
{


/***************************************************************************//**
  Specification for creating a value index.

  theUri          : The uri identifying the index. 
  theKeyTypes     : The data types of the key components. Each type must be 
                    atomic, and for ordering indices, it must have an ordering. 
  theValueType    : The data type of the values associated with the keys.
  theCollations   : The names of the colltions to use when comparing the string
                    components of a key. Note: the size of this vector is the
                    same as that of theKeyTypes; if a key component is not a 
                    string, the associated entry in theCollations is simply
                    ignored.   
  theTimezone     : The timezone is needed to compare date/time key values.
  theIsUnique     : Whether the index is unique, i.e., there is exactly one
                    value associated with each key.
  theIsOrdering   : 
  theIsTemp       : Whether the index is temporary or not.
  theIsThreadSafe : Whether the index can be shared among multiple threads or not
********************************************************************************/
struct IndexSpecification
{
  std::vector<store::Item_t> theKeyTypes;
  store::Item_t              theValueType;
  std::vector<std::string>   theCollations;
  long                       theTimezone;
  bool                       theIsUnique;
  bool                       theIsOrdering;
  bool                       theIsTemp;
  bool                       theIsThreadSafe;
};


/***************************************************************************//**
  Abstract index class.

  Index instances are created (but not populated) via the store::createIndex()
  method; they are populated via the Index::insert() and Index::remove() methods,
  and are probed via IndexIterators (see iterator.h). 
********************************************************************************/
class Index : public RCObject
{
protected:
  SYNC_CODE(mutable RCLock theRCLock;)

public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

public:

  virtual ~Index() {}

  /**
   *  Return a reference to the specification object that describes this index. 
   */
  virtual const IndexSpecification& getSpecification() const = 0;

  /**
   *  Insert into the index a mapping between the given key and value.
   *  Return true if the key was already in the index, otherwise (i.e.,
   *  this was the first mapping for this key) return false.
   */
  virtual bool insert(store::IndexKey& key, store::Item_t& value) = 0;

  /**
   *  Remove from the index the mapping between the given key and value.
   *  If this mapping does not appearin theindex return false; otherwise
   *  return true.
   */
  virtual bool remove(const store::IndexKey& key, store::Item_t& value) = 0;
};


}
}

#endif
