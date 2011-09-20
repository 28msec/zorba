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
#pragma once
#ifndef ZORBA_COMPILER_VALUE_IC
#define ZORBA_COMPILER_VALUE_IC

#include "common/shared_types.h"

#include "compiler/expression/expr_utils.h"
#include "runtime/base/plan_iterator.h"
#include "store/api/ic.h"


namespace zorba 
{

/******************************************************************************
 ValueIC is the class representing the integrity constraint
 declaration.

 It represents an IC and it's collection dependecies.
 Contains one of the two kinds of info, either:
   1) - IC name
      - and 1 collection name
   or 2) - IC name
      - and 2 collection names (to and from) for the foreign key ic kind

*******************************************************************************/
class ValueIC : public SimpleRCObject 
{
public:

private:
  static_context                * theSctx;

  store::Item_t                   theName;
  store::IC::ICKind               theICKind;          
  store::Item_t                   theCollectionName;
  store::Item_t                   theFromCollectionName;
  store::Item_t                   theToCollectionName;
  PlanIter_t                      thePlan;
  CompilerCB                      *theCcb;

public:
  SERIALIZABLE_CLASS(ValueIC)
  ValueIC(::zorba::serialization::Archiver& ar) : SimpleRCObject(ar) {};

  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIC(static_context* sctx, const store::Item_t& name,
          const store::Item_t& collName, 
          PlanIter_t icPlan, CompilerCB *ccb)
  :
    theSctx(sctx),
    theName(name),
    theICKind(store::IC::ic_collection),
    theCollectionName(collName),
    thePlan(icPlan),
    theCcb(ccb)
  {}

  ValueIC(static_context* sctx, const store::Item_t& name,
          const store::Item_t& fromCollName, const store::Item_t& toCollName, 
          PlanIter_t icPlan, CompilerCB *ccb)
  :
    theSctx(sctx),
    theName(name),
    theICKind(store::IC::ic_foreignkey),
    theFromCollectionName(fromCollName),
    theToCollectionName(toCollName),
    thePlan(icPlan),
    theCcb(ccb)
  {}


  virtual ~ValueIC() {}

  static_context* getSctx() const 
  { 
    return theSctx; 
  }

  store::Item* getICName() const
  {
    return theName.getp();
  }

  const store::Item_t& getCollectionName() const
  {
    return theCollectionName;
  }

  const store::Item_t& getFromCollectionName() const
  {
    return theFromCollectionName;
  }

  const store::Item_t& getToCollectionName() const
  {
    return theToCollectionName;
  }

  store::IC::ICKind getICKind() const 
  {
    return theICKind; 
  }
  
  store::Iterator_t getIterator() const;

  //void analyze();

  std::string toString();

};

typedef rchandle<ValueIC> ValueIC_t;



/**
 *  Implementation of callback store::ICChecker interface
 */
class ICCheckerImpl
  : public store::ICChecker
{
private:
  static_context* theSctx;
  dynamic_context* theDctx;

public:
  ICCheckerImpl(static_context* sctx, dynamic_context* dctx) : 
    theSctx(sctx), theDctx(dctx) {}

  ~ICCheckerImpl() {}

  void check(const store::Item* collName);

private:
  void actualCheck(const store::Item* collName, 
                   const store::Item* icCollName,
                   const store::Item* icName);

};


}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
