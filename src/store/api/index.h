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

#include "zorbamisc/config/platform.h"
#include "common/shared_types.h"


namespace zorba { namespace store {


typedef std::vector<store::Item_t> IndexKey;

typedef std::vector<std::pair<xqpStringStore, xqpStringStore> > IndexProperties;


/******************************************************************************
  Abstract index class.

  Index instances are created via the store::createIndex() method. Index updates
  are done via pul primitives. And index probing is done via IndexIterators (see
  iterator.h). So, the Index class itself does not have much of an api.
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

  virtual bool isOrdering() const = 0;
};


}
}

#endif
