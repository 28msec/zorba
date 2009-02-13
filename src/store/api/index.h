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


/******************************************************************************
  Specification for creating an index
********************************************************************************/
struct IndexSpecification
{
  xqpStringStore_t           theUri;
  std::vector<store::Item_t> theKeyTypes;
  store::Item_t              theValueType;
  std::vector<XQPCollator*>  theCollators;
  long                       theTimezone;
  bool                       theIsUnique;
  bool                       theIsOrdering;
  bool                       theIsTemp;
};


/******************************************************************************
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

  virtual Item* getUri() const = 0;

  virtual bool isUnique() const = 0;

  virtual bool isOrdering() const = 0;

  virtual bool isTemporary() const = 0;

  virtual bool isThreadSafe() const = 0;

  virtual bool insert(store::IndexKey& key, store::Item_t& value) = 0;

  virtual bool remove(const store::IndexKey& key, store::Item_t& value) = 0;
};


}
}

#endif
