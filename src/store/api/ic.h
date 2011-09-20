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
#ifndef ZORBA_STORE_IC
#define ZORBA_STORE_IC

#include "store/api/shared_types.h"

namespace zorba 
{

namespace store 
{

class IC;


/**
 * Integrity Constraints class. Contains the name of the IC and the
 * collection name.
 */
class IC : public RCObject
{
public:
  enum ICKind
  { 
    ic_collection,
    ic_foreignkey 
  };

protected:
  SYNC_CODE(mutable RCLock theRCLock;)

public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  long* getSharedRefCounter() const { return NULL; } 

public:
  virtual ~IC() {}

  virtual const Item* getICName() const = 0;
  virtual ICKind getICKind() const = 0;
  virtual const Item* getCollectionName() const = 0;
  virtual const Item* getToCollectionName() const = 0;
  virtual const Item* getFromCollectionName() const = 0;
};


class ICChecker
{
public:
  virtual ~ICChecker() {}

  virtual void check(const Item* collName) = 0;
};


} // namespace store
} // namespace zorba

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
