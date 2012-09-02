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

#include "runtime/function_item/function_item.h"

// TODO remove the next three includes
#include "api/unmarshaller.h"
#include "context/static_context.h"

#include "runtime/base/narybase.h"


namespace zorba {

class StaticContextImpl;


/*******************************************************************************
  thePlan:
  --------
  The runtime plan for the function body. This is created during
  UDFunctionCallIterator::openImpl(), if it has not not been created already
  (during the openImpl() method of another UDFunctionCallIterator on the same
  udf). A pointer to this plan is also stored in the udf obj itself, and that's
  how we know if it has been created already or not.

  thePlanState:
  -------------
  The plan state to run thePlan with. The PlanState obj is created during
  UDFunctionCallIterator::openImpl(), but the actual state block is created an
  initialized the 1st time that UDFunctionCallIterator::nextImpl() is called
  (at that time open() is invoked on thePlan).

  thePlanStateSize:
  -----------------
  The size of the plan state block.

  thePlanOpen:
  ------------
  Whether thePlan has been opened already or not.

  theArgWrappers:
  ---------------
  For each argument of this function call, theArgWrappers stores a plan iterator
  wrapper over the sub plan that computes the arg expr. This wrapping is needed
  because the body plan and the arg sub plans operate in different plan states.
  Note: Withinh the function body, there may exist more than one references to
  an arg var V, but these references are "mutually exclusive", ie, at most one
  of the references will actually be reached during each particular execution of
  the body. So, it is never the case that the arg expr will have more than one
  consumers, and as a result we can bind all those V references to the same arg
  wrapper.

  theCache:
  ---------
  Is an Index which is set in the state if caching for the invoked function
  should be done. The cache is owned by the UDF itself and shared across
  all function invocations.

  theCacheHits:
  -------------
  If caching is used, this vector contains the results of all arguments
  of the function evaluation. It's used to bind the variables if the
  cache didn't give a result in order to avoid duplicate evaluation of
  the arguments.
********************************************************************************/
class UDFunctionCallIteratorState : public PlanIteratorState
{
public:
  PlanIter_t                       thePlan;
  PlanState                      * thePlanState;
  uint32_t                         thePlanStateSize;
  dynamic_context                * theLocalDCtx;
  bool                             thePlanOpen;
  std::vector<store::Iterator_t>   theArgWrappers;
  store::Index                   * theCache;
  std::vector<store::TempSeq_t>    theArgValues;

  UDFunctionCallIteratorState();

  ~UDFunctionCallIteratorState();

  void open(PlanState& planState, user_function* udf);

  void reset(PlanState& planState);
};


/*******************************************************************************
  theUDF:
  -------
  Pointer to the udf object.

  theIsDynamic:
  -------------

********************************************************************************/
class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator,
                                                       UDFunctionCallIteratorState>
{
  friend class PrinterVisitor;

  typedef std::vector<LetVarIter_t> ArgVarRefs;

protected:
  user_function  * theUDF;
  bool             theIsDynamic;
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

  ~UDFunctionCallIterator() {}

  bool isUpdating() const;

  void setDynamic() { theIsDynamic = true; }

  void setFunctionItem(const FunctionItem* fnItem) { theFunctionItem = fnItem; }

  bool isCached() const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

protected:
  void createCache(
    PlanState& planState,
    UDFunctionCallIteratorState* state);

  bool probeCache(
    PlanState& planState,
    UDFunctionCallIteratorState* state,
    store::Item_t& result,
    std::vector<store::Item_t>& aKey) const;

  void insertCacheEntry(
    UDFunctionCallIteratorState* state,
    std::vector<store::Item_t>& aKey,
    store::Item_t& aValue) const;
};


/*******************************************************************************

********************************************************************************/
class ExtFunctionCallIteratorState : public PlanIteratorState
{
 public:
  std::vector<ItemSequence*> m_extArgs;
  ItemSequence_t             theResult;
  Iterator_t                 theResultIter;

  ExtFunctionCallIteratorState();

  ~ExtFunctionCallIteratorState();

  void reset(PlanState&);
};


class ExtFunctionCallIterator : public NaryBaseIterator<ExtFunctionCallIterator,
                                                        ExtFunctionCallIteratorState>
{
protected:
  const ExternalFunction * theFunction;
  bool                     theIsUpdating;
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
        const ExternalFunction* function,
        bool isUpdating,
        const zstring& ns,
        static_context* moduleSctx);

  virtual ~ExtFunctionCallIterator();

  virtual bool isUpdating() const { return theIsUpdating; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};

}

#endif /* ZORBA_FNCALL_ITERATOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
