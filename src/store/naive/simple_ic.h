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
#ifndef ZORBA_SIMPLE_STORE_IC
#define ZORBA_SIMPLE_STORE_IC

#include "store/api/ic.h"
#include "store/api/iterator.h"
#include "store/api/shared_types.h"

#include "diagnostics/assert.h"



namespace zorba 
{ 

namespace simplestore 
{

/**
  Implementation for IC interface in simple store.
*/
class ICImpl : public store::IC
{
protected:
  store::Item_t theICQName;
  ICKind        theICKind;

public:
  ICImpl(const store::Item_t& icQName, ICKind icKind) 
    : theICQName(icQName), theICKind(icKind) {}

  virtual ~ICImpl() {}

  virtual const store::Item* getICName() const { return theICQName.getp(); }
  
  virtual ICKind getICKind() const { return theICKind; }
};

class ICCollectionImpl : public ICImpl
{
protected:
  store::Item_t theCollectionQName;

public:
  ICCollectionImpl(const store::Item_t& icQName, 
                   const store::Item_t& collQName) 
    : ICImpl(icQName, IC::ic_collection), 
      theCollectionQName( collQName ) {}

  const store::Item* getCollectionName() const 
  { return theCollectionQName.getp(); }

  const store::Item* getToCollectionName() const 
  { ZORBA_ASSERT(false); /* invalid icImplKind */ };

  const store::Item* getFromCollectionName() const
  { ZORBA_ASSERT(false); /* invalid icImplKind */ };

};

class ICForeignKeyImpl : public ICImpl
{
protected:
  store::Item_t theToCollectionQName;
  store::Item_t theFromCollectionQName;

public:
  ICForeignKeyImpl(const store::Item_t& icQName, 
                   const store::Item_t& toCollQName,
                   const store::Item_t& fromCollQName) 
    : ICImpl(icQName, IC::ic_foreignkey), 
      theToCollectionQName( toCollQName ), 
      theFromCollectionQName( fromCollQName) {}

  const store::Item* getToCollectionName() const
  { return theToCollectionQName.getp(); }

  const store::Item* getFromCollectionName() const
  { return theFromCollectionQName.getp(); }

  const store::Item* getCollectionName() const 
  { ZORBA_ASSERT(false); /* invalid icImplKind */ };
};



}  // namespace store
}  // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
