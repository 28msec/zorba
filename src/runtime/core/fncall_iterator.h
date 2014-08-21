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
#ifndef ZORBA_RUNTIME_FNCALL_ITERATOR
#define ZORBA_RUNTIME_FNCALL_ITERATOR

#include <zorba/api_shared_types.h>
#include <zorba/function.h>

#include "common/shared_types.h"

#include "runtime/hof/function_item.h"
#include "runtime/util/single_item_iterator.h"
#include "runtime/base/narybase.h"

#include "context/static_context.h"
#include "functions/external_function.h"

namespace zorba {

class StaticContextImpl;

class external_function;

class VectorItemSequence;

class FunctionCache;

class PrinterVisitor;

/*******************************************************************************
theCache:
---------
Is a map which is set in the state if caching for the invoked function
should be done. The cache is owned by the UD/ext function itself and shared
across all function invocations.
********************************************************************************/
class FunctionCallIteratorState : public PlanIteratorState
{
public:
  FunctionCallIteratorState();

  FunctionCache* theCache;
  store::Item_t  theCacheKey;
  uint64_t       theCacheKeySnapshot;
  unsigned int   theCacheHits;
  unsigned int   theCacheMisses;

  std::vector<store::Item_t>                 theCachedResult;
  std::vector<store::Item_t>::const_iterator theCachedResultIterator;
};



/*******************************************************************************

  theLocalDCtx:
  -------------
  The dynamic context for this udf call. It is where the values of the udf's
  local block-variables are stored.  It is created during 
  UDFunctionCallIterator::openImpl().

  thePlan:
  --------
  The runtime plan for the function body. This is created during 
  UDFunctionCallIterator::openImpl(), if it has not been created already (during
  the openImpl() method of another UDFunctionCallIterator on the same udf). A
  pointer to this plan is also stored in the udf obj itself, and that's how we
  know if it has been created already or not.

  thePlanState:
  -------------
  The plan state to run thePlan with. The PlanState obj is created during 
  UDFunctionCallIterator::openImpl(), but the actual state block is created and
  initialized the 1st time that UDFunctionCallIterator::nextImpl() is called 
  (at that time open() is invoked on thePlan).

  thePlanOpen:
  ------------
  Whether thePlan has been opened already or not.

  thePlanStateSize:
  -----------------
  The size of the plan state block.

  theArgWrappers:
  ---------------
  For each argument of this function call, theArgWrappers stores a plan iterator
  wrapper over the sub plan that computes the arg expr. This wrapping is needed 
  because the udf-body plan and the arg sub plans operate in different plan states. 
  Note: Withinh the function body, there may exist more than one references to 
  an arg var V, but these references are "mutually exclusive", ie, at most one
  of the references will actually be reached during each particular execution of
  the body. So, it is never the case that the arg expr will have more than one 
  consumers, and as a result we can bind all those V references to the same arg
  wrapper.

  theArgValues:
  -------------
  If caching is used, this vector contains the results of all arguments
  of the function evaluation. It's used to bind the arg variables if the
  cache didn't give a result in order to avoid duplicate evaluation of
  the arguments.
********************************************************************************/
class UDFunctionCallIteratorState : public FunctionCallIteratorState
{
public:
  dynamic_context* theLocalDCtx;
  bool theIsLocalDCtxOwner;

  PlanIter_t thePlan;
  PlanState* thePlanState;
  bool thePlanOpen;
  uint32_t thePlanStateSize;

  std::vector<ItemIterator_t> theArgValues;
  std::vector<store::Iterator_t> theArgWrappers;

  store::Item_t theNextResult;

  UDFunctionCallIteratorState();

  ~UDFunctionCallIteratorState();

  void open(
      PlanState& planState,
      user_function* udf,
      bool theIsDynamic,
      store::ItemHandle<FunctionItem>& theFunctionItem);

  void reset(PlanState& planState);
};


/*******************************************************************************

  theUDF: 
  -------
  Pointer to the udf object.

  theIsDynamic:
  -------------
  True if this is a UDFunctionCallIterator that is allocated on the fly during
  DynamicFnCallIterator::nextImpl().

  theFunctionItem:
  ----------------

********************************************************************************/
class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator, 
                                                       UDFunctionCallIteratorState> 
{
  friend class PrinterVisitor;

  typedef std::vector<LetVarIter_t> ArgVarRefs;

protected:
  user_function                 * theUDF;
  bool                            theIsDynamic;
  store::ItemHandle<FunctionItem> theFunctionItem;

public:
  SERIALIZABLE_CLASS(UDFunctionCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  UDFunctionCallIterator,
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  UDFunctionCallIterator(
      static_context* sctx,
      const QueryLoc& loc, 
      std::vector<PlanIter_t>& args, 
      const user_function* aUDF);

  virtual ~UDFunctionCallIterator();

  zstring getNameAsString() const;

  bool isUpdating() const;

  void setDynamic() { theIsDynamic = true; }

  void setFunctionItem(const FunctionItem* fnItem) { theFunctionItem = fnItem; }

  bool isCached() const;

  bool isCacheAcrossSnapshots() const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);

  bool nextImpl(store::Item_t& aResult, PlanState& aPlanState) const;

private:
  bool nextImplCache(store::Item_t& aResult, PlanState& aPlanState) const;

  bool nextImplNoCache(store::Item_t& aResult, PlanState& aPlanState) const;

  void bindArguments(UDFunctionCallIteratorState* aState, bool aReset) const;

protected:
  void initCache(
    PlanState& aPlanState,
    UDFunctionCallIteratorState* aState);

  bool probeCache(
    PlanState& aPlanState,
    UDFunctionCallIteratorState* aState,
    std::vector< std::vector <store::Item_t> >& aArguments) const;

  void insertCacheEntry(
      PlanState& aPlanState,
      UDFunctionCallIteratorState* aState,
      std::vector<store::Item_t>& aResult) const;
};


/*******************************************************************************

********************************************************************************/
class ExtFunctionCallIteratorState : public FunctionCallIteratorState
{
 public:
  std::vector<ItemSequence*> m_extArgs;
  ItemSequence_t             theResult;
  Iterator_t                 theResultIter;
  bool                       theIsEvaluated;
  ProfileDataMap           * theProfileDataMap;

  ExtFunctionCallIteratorState();

  ~ExtFunctionCallIteratorState();

  ProfileDataMap* getProfileDataMap() const { return theProfileDataMap; }

  void reset(PlanState&);
};


class ExtFunctionCallIterator : public NaryBaseIterator<ExtFunctionCallIterator,
                                                        ExtFunctionCallIteratorState>
{
  friend class PrinterVisitor;

protected:
  rchandle<external_function> theFunctionDef;
  const ExternalFunction * theFunction;
  bool                     theIsUpdating;
  bool                     theIsSequential;
  zstring                  theNamespace;
  static_context         * theModuleSctx;

public:
  SERIALIZABLE_CLASS(ExtFunctionCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ExtFunctionCallIterator, 
  NaryBaseIterator<ExtFunctionCallIterator, ExtFunctionCallIteratorState>);

  void serialize(serialization::Archiver& ar);

public:
  ExtFunctionCallIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        const external_function* functionDef,
        const ExternalFunction* function,
        bool isUpdating,
        bool isSequential,
        const zstring& ns,
        static_context* moduleSctx);

  virtual ~ExtFunctionCallIterator();

  zstring getNameAsString() const;

  virtual bool isUpdating() const { return theIsUpdating; }

  virtual bool isSequential() const { return theIsSequential; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool countImpl(store::Item_t& result, PlanState& planState) const;

  bool skipImpl(int64_t count, PlanState &planState) const;

  bool nextImpl(store::Item_t& aResult, PlanState& aPlanState) const;

  bool nextImplCache(store::Item_t& aResult, PlanState& aPlanState) const;

  bool nextImplNoCache(store::Item_t& aResult, PlanState& aPlanState) const;

  void evaluate(PlanState& aPlanState, ExtFunctionCallIteratorState* aState, std::vector<zorba::ItemSequence*>& aArguments) const;

  bool isCached() const;

  bool isCacheAcrossSnapshots() const;

protected:
  void initCache(
    PlanState& aPlanState,
    ExtFunctionCallIteratorState* aState);

  bool probeCache(
    PlanState& aPlanState,
    ExtFunctionCallIteratorState* aState,
    std::vector<zorba::VectorItemSequence>& aArguments) const;

  void insertCacheEntry(
      PlanState& aPlanState,
      ExtFunctionCallIteratorState* aState,
      std::vector<store::Item_t>& aResult) const;
};

}

#endif /* ZORBA_FNCALL_ITERATOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
