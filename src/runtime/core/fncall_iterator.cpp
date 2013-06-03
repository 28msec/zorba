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
#include "stdafx.h"

#include "runtime/core/fncall_iterator.h"

#include <map>

#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/function.h>

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/user_exception.h"
#include "diagnostics/xquery_exception.h"
#include "diagnostics/xquery_stack_trace.h"
#include "diagnostics/util_macros.h"

#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "functions/udf.h"

#include "runtime/core/var_iterators.h"
#include "runtime/util/flowctl_exception.h"  // for ExitException
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"

#include "util/string_util.h"

#include "store/api/index.h"
#include "store/api/store.h"
#include "store/api/iterator_factory.h"
#include "store/api/temp_seq.h"


#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"

#define DEBUGGER_COMMONS state->thePlanState->theDebuggerCommons
#define DEBUGGER_PUSH_FRAME                                   \
  /* if the debugger is turned on, push the current frame */  \
  if (DEBUGGER_COMMONS) {                                     \
    /* initialize the current stack frame name */             \
    std::string lFrameName;                                   \
    std::stringstream lSs;                                    \
    lSs << theUDF->getName()->getStringValue()                \
        << "#"                                                \
        << theUDF->getArgVars().size();                       \
    lFrameName = lSs.str();                                   \
                                                              \
    /* push the current frame on the stack */                 \
    DEBUGGER_COMMONS->pushStackFrame(loc, lFrameName);        \
  }

#define DEBUGGER_POP_FRAME                                    \
  /* pop the pushed frame */                                  \
  if (DEBUGGER_COMMONS) {                                     \
    DEBUGGER_COMMONS->popStackFrame();                        \
  }
#endif

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)

SERIALIZABLE_CLASS_VERSIONS(ExtFunctionCallIterator)



/*******************************************************************************

********************************************************************************/
UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  :
  theLocalDCtx(NULL),
  theIsLocalDCtxOwner(true),
  thePlan(NULL),
  thePlanState(NULL),
  thePlanOpen(false),
  thePlanStateSize(0),
  theCache(0)
{
}


/*******************************************************************************

********************************************************************************/
UDFunctionCallIteratorState::~UDFunctionCallIteratorState()
{
  if (thePlanOpen)
    thePlan->close(*thePlanState);

  if (thePlanState != NULL)
    delete thePlanState;

  if (theLocalDCtx != NULL && theIsLocalDCtxOwner)
    delete theLocalDCtx;
}


/*******************************************************************************
  Called by the openImpl method of UDFunctionCallIterator.
********************************************************************************/
void UDFunctionCallIteratorState::open(
    PlanState& planState,
    user_function* udf,
    bool isDynamic,
    store::ItemHandle<FunctionItem>& functionItem)
{
  // Must allocate new dctx because the udf may be a recursive udf with local
  // block vars, all of which have the same dynamic-context id, but they are
  // distinct vars.

  if (isDynamic && functionItem->getDctx() != NULL)
  {
    thePlan = udf->getPlan(thePlanStateSize, functionItem->getMaxInScopeVarId()).getp();

    thePlanStateSize = thePlan->getStateSizeOfSubtree();

    theLocalDCtx = functionItem->getDctx();

    theIsLocalDCtxOwner = false;
  }
  else
  {
    thePlan = udf->getPlan(thePlanStateSize, 1).getp();

    thePlanStateSize = thePlan->getStateSizeOfSubtree();

    theLocalDCtx = new dynamic_context(planState.theGlobalDynCtx);

    theIsLocalDCtxOwner = true;
  }

  thePlanState = new PlanState(planState.theGlobalDynCtx,
                               theLocalDCtx,
                               thePlanStateSize,
                               planState.theStackDepth + 1,
                               planState.theMaxStackDepth);

  thePlanState->theCompilerCB = planState.theCompilerCB;
#ifdef ZORBA_WITH_DEBUGGER
  thePlanState->theDebuggerCommons = planState.theDebuggerCommons;
#endif
  thePlanState->theQuery = planState.theQuery;
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (thePlanOpen)
  {
    thePlan->reset(*thePlanState);
  }

  theArgValues.clear();
}


/*******************************************************************************

********************************************************************************/
UDFunctionCallIterator::UDFunctionCallIterator(
    static_context* sctx,
    const QueryLoc& loc, 
    std::vector<PlanIter_t>& args, 
    const user_function* aUDF)
  :
  NaryBaseIterator<UDFunctionCallIterator,
                   UDFunctionCallIteratorState>(sctx, loc, args), 
  theUDF(const_cast<user_function*>(aUDF)),
  theIsDynamic(false)
{
}


UDFunctionCallIterator::~UDFunctionCallIterator()
{
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>*)this);

  ar & theUDF;
  ar & theIsDynamic;
}


/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::isUpdating() const
{
  return theUDF->isUpdating();
}


/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::isCached() const
{
  return theUDF->cacheResults();
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::createCache(
    PlanState& planState,
    UDFunctionCallIteratorState* state)
{
  store::Index_t lIndex = theUDF->getCache();

  if (!lIndex && theUDF->cacheResults())
  {
    const signature& sig = theUDF->getSignature();

    csize numArgs = theChildren.size();

    store::IndexSpecification lSpec;
    lSpec.theNumKeyColumns = numArgs;
    lSpec.theKeyTypes.resize(numArgs);
    lSpec.theCollations.resize(numArgs);
    lSpec.theIsTemp = true;
    lSpec.theIsUnique = true;

    for (csize i = 0; i < numArgs; ++i)
    {
      lSpec.theKeyTypes[i] = sig[i]->getBaseBuiltinType()->getQName().getp();
    }

    lIndex = GENV_STORE.createIndex(theUDF->getName(), lSpec, 0);

    theUDF->setCache(lIndex.getp()); // cache the cache in the function itself

    state->theArgValues.reserve(numArgs);
  }

  state->theCache = lIndex.getp();
}


/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::probeCache(
    PlanState& planState,
    UDFunctionCallIteratorState* state,
    store::Item_t& result,
    std::vector<store::Item_t>& argValues) const
{
  if (!state->theCache)
    return false;

  store::IndexCondition_t cond =
  state->theCache->createCondition(store::IndexCondition::POINT_VALUE);

  std::vector<store::Iterator_t>::iterator ite = state->theArgWrappers.begin();

  for (; ite != state->theArgWrappers.end(); ++ite)
  {
    store::Iterator_t& argWrapper = (*ite);
    store::Item_t argValue;
    if (argWrapper) // might be 0 if argument is not used
    {
      argWrapper->next(argValue); // guaranteed to have exactly one result
    }
    argValues.push_back(argValue);
    cond->pushItem(argValue);
  }

  store::IndexProbeIterator_t probeIte = 
  GENV_STORE.getIteratorFactory()->createIndexProbeIterator(state->theCache);

  probeIte->init(cond);
  probeIte->open();

  return probeIte->next(result);
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::insertCacheEntry(
  UDFunctionCallIteratorState* state,
  std::vector<store::Item_t>& argValues,
  store::Item_t& udfValue) const
{
  if (state->theCache)
  {
    std::auto_ptr<store::IndexKey> k(new store::IndexKey());
    store::IndexKey* k2 = k.get();
    k->theItems = argValues;
    store::Item_t lTmp = udfValue; // insert will eventually transfer the Item_t
    if (!state->theCache->insert(k2, lTmp))
    {
      k.release();
    }
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UDFunctionCallIteratorState* state;

  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    openImpl(planState, offset);

    state = StateTraitsImpl<UDFunctionCallIteratorState>::
            getState(planState, theStateOffset);
  }
  else
  {
    theStateOffset = offset;

    state = new (planState.theBlock + offset) UDFunctionCallIteratorState();

    state->init(planState);
  }

  if (planState.theStackDepth + 1 > planState.theMaxStackDepth)
  {
    RAISE_ERROR(zerr::ZXQP0003_INTERNAL_ERROR, loc,
    ERROR_PARAMS(ZED(StackOverflow)));
  }

  // Create the plan for the udf body (if not done already) and allocate
  // the plan state (but not the state block) and dynamic context.
  state->open(planState, theUDF, theIsDynamic, theFunctionItem);

  // if the results of the function should be cached (prereq: atomic in and out)
  // this functions stores an index in the dynamic context that contains
  // the cached results. The name of the index is the name of the function.
  createCache(planState, state);

  // Create a wrapper over each subplan that computes an argument expr, if the
  // associated param is actually used anywhere in the function body.
  csize numArgs = theChildren.size();

  state->theArgWrappers.resize(numArgs);

  std::vector<PlanIter_t>::const_iterator argsIte = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator argsEnd = theChildren.end();
  std::vector<store::Iterator_t>::iterator argWrapsIte = state->theArgWrappers.begin();

  const std::vector<ArgVarRefs>& argsRefs = theUDF->getArgVarsRefs();
  std::vector<ArgVarRefs>::const_iterator argsRefsIte = argsRefs.begin();

  for (; argsIte != argsEnd; ++argsIte, ++argWrapsIte, ++argsRefsIte)
  {
    const ArgVarRefs& argVarRefs = (*argsRefsIte);

    if (!argVarRefs.empty())
    {
      if ((*argWrapsIte) == NULL)
      (*argWrapsIte) = new PlanIteratorWrapper((*argsIte), planState);

      // Cannot do the arg bind here because the state->thePlan has not been
      // opened yet, and as a result, state->thePlanState has not been
      // initialized either.
      //argRef->bind(*argWrapsIte, *state->thePlanState);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::resetImpl(PlanState& planState) const
{
  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    resetImpl(planState);
  }
  else
  {
    StateTraitsImpl<UDFunctionCallIteratorState>::
    reset(planState, theStateOffset);
  }
}


/*******************************************************************************

********************************************************************************/
void UDFunctionCallIterator::closeImpl(PlanState& planState)
{
  if (!theIsDynamic)
  {
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
    closeImpl(planState);
  }
  else
  {
    StateTraitsImpl<UDFunctionCallIteratorState>::
    destroyState(planState, theStateOffset);
  }
}


/*******************************************************************************

********************************************************************************/
bool UDFunctionCallIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  try
  {
    std::vector<store::Item_t> lKey;
    bool lCacheHit;

    UDFunctionCallIteratorState* state;
    DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

    // Open the plan, if not done already. This cannot be done in the openImpl
    // method because in the case of recursive functions, we will get into an
    // infinite loop.
    if (!state->thePlanOpen) 
    {
      uint32_t planOffset = 0;
      state->thePlan->open(*state->thePlanState, planOffset);
      state->thePlanOpen = true;
    }

    // check if there is a cache and the result is already in the cache
    lCacheHit = probeCache(planState, state, result, lKey);

    // if not in the cache, we bind the arguments to the function
    if (!lCacheHit)
    {
      const std::vector<ArgVarRefs>& argsRefs = theUDF->getArgVarsRefs();
      const std::vector<store::Iterator_t>& argWraps = state->theArgWrappers;

      for (size_t i = 0; i < argsRefs.size(); ++i)
      {
        if (argWraps[i] != NULL)
        {
          const ArgVarRefs& argVarRefs = argsRefs[i];
          store::Iterator_t argWrapper;
          if (state->theCache)
          {
            std::vector<store::Item_t> lParam(1, lKey[i]);
            state->theArgValues.push_back(GENV_STORE.createTempSeq(lParam));
            argWrapper = state->theArgValues.back()->getIterator();
            argWrapper->open();
          }
          else
          {
            if (i < argWraps.size())
              argWrapper = argWraps[i];
          }

          ArgVarRefs::const_iterator argVarRefsIte = argVarRefs.begin();
          ArgVarRefs::const_iterator argVarRefsEnd = argVarRefs.end();

          for (; argVarRefsIte != argVarRefsEnd; ++argVarRefsIte)
          {
            const LetVarIter_t& argRef = (*argVarRefsIte);
            assert(argRef != NULL);
            
            if (argRef != NULL)
            {
              argRef->bind(argWrapper, *state->thePlanState);
            }
          }
        }
      }
    }

    if (lCacheHit)
    {
      STACK_PUSH(true, state);
    }
    else
    {
#ifdef ZORBA_WITH_DEBUGGER
      DEBUGGER_PUSH_FRAME;
#endif
      while (consumeNext(result, state->thePlan, *state->thePlanState))
      {
#ifdef ZORBA_WITH_DEBUGGER
        DEBUGGER_POP_FRAME;
#endif

        insertCacheEntry(state, lKey, result);
        STACK_PUSH(true, state);

#ifdef ZORBA_WITH_DEBUGGER
        DEBUGGER_PUSH_FRAME;
#endif
      }

#ifdef ZORBA_WITH_DEBUGGER
      DEBUGGER_POP_FRAME;
#endif

    }

    STACK_END(state);

  }
  catch (ZorbaException& err)
  {
    recordStackTrace(theUDF->getLoc(),
                     loc,
                     theUDF->getName(),
                     (unsigned int)theUDF->getArgVars().size(),
                     err);
    throw;
  }
}


NARY_ACCEPT(UDFunctionCallIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  External function invocation                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
class ExtFuncArgItemSequence : public ItemSequence
{
  class InternalIterator : public Iterator
  {
  private:
    ExtFuncArgItemSequence * theItemSequence;
    bool                     theIsOpen;
    bool                     theFirstOpen;

  public:
    InternalIterator(ExtFuncArgItemSequence* seq) 
      : 
      theItemSequence(seq),
      theIsOpen(false),
      theFirstOpen(true)
    {
    }

    void open()
    {
      if (theIsOpen)
        throw ZORBA_EXCEPTION(zerr::ZAPI0041_ITERATOR_ALREADY_OPEN);

      if (!theFirstOpen)
        theItemSequence->theChild->reset(theItemSequence->thePlanState);

      theIsOpen = true;
      theFirstOpen = false;
    }

    bool next(Item& item)
    {
      if (!theIsOpen)  
        throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

      store::Item_t result;
      bool status = theItemSequence->theChild->
                    consumeNext(result,
                                theItemSequence->theChild.getp(),
                                theItemSequence->thePlanState);
      item = status ? result : NULL;
      return status;
    }

    void close()
    {
      if (!theIsOpen)  
        throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

      theIsOpen = false;
    }

    bool isOpen() const { return theIsOpen; }
  };

private:
  PlanIter_t   theChild;
  PlanState  & thePlanState;
  bool         theHasIterator;

public:
  ExtFuncArgItemSequence(PlanIter_t& child, PlanState& state)
    :
    theChild(child),
    thePlanState(state),
    theHasIterator(false)
  {
  }

  virtual Iterator_t getIterator() 
  {
    if (theHasIterator)
      throw ZORBA_EXCEPTION(zerr::ZAPI0039_XQUERY_HAS_ITERATOR_ALREADY);

    return new InternalIterator(this);
  }
};


/*******************************************************************************

********************************************************************************/
ExtFunctionCallIteratorState::ExtFunctionCallIteratorState()
{
}


ExtFunctionCallIteratorState::~ExtFunctionCallIteratorState()
{
  theResultIter = NULL;

  csize n = m_extArgs.size();

  for (csize i = 0; i < n; ++i)
  {
    m_extArgs[i]->removeReference();
  }
}


void ExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theResultIter = NULL;
  theResult = NULL;
}


/*******************************************************************************

********************************************************************************/
ExtFunctionCallIterator::ExtFunctionCallIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    const ExternalFunction* function,
    bool isUpdating,
    const zstring& ns,
    static_context* moduleSctx)
  :
  NaryBaseIterator<ExtFunctionCallIterator,
                   ExtFunctionCallIteratorState>(sctx, loc, args),
  theFunction(function),
  theIsUpdating(isUpdating),
  theNamespace(ns),
  theModuleSctx(moduleSctx)
{
}


ExtFunctionCallIterator::~ExtFunctionCallIterator()
{
}


void ExtFunctionCallIterator::serialize(serialization::Archiver& ar)
{
  ar.dont_allow_delay_for_plan_sctx = true;
  serialize_baseclass(ar,
                      static_cast<NaryBaseIterator<
                                  ExtFunctionCallIterator,
                                  ExtFunctionCallIteratorState>*>(this));
  ar.dont_allow_delay_for_plan_sctx = false;
  if (ar.is_serializing_out())
  {
    // serialize out: serialize prefix and localname of the function
    ar & theNamespace;
    zstring lTmp;
    lTmp = Unmarshaller::getInternalString(theFunction->getLocalName());
    ar.set_is_temp_field(true);
    ar & lTmp;
    ar.set_is_temp_field(false);
    ar & theModuleSctx;
  }
  else
  {
    // serializing in: get the function from the static context
    //                 using the serialized prefix/uri and localname
    ar & theNamespace;
    zstring lLocalname;
    ar.set_is_temp_field(true);
    ar & lLocalname;
    ar.set_is_temp_field(false);

    ar & theModuleSctx;
    if (!theNamespace.empty())
    {
      theFunction = theModuleSctx->lookup_external_function(theNamespace, lLocalname);
      if (!theFunction)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
          ERROR_PARAMS(
                ZED( NoExternalFunction_2 ),
                BUILD_STRING( '{', theNamespace, '}', lLocalname )
                )
        );
      }
    }
    else
    {
      theFunction = NULL;
    }
  }

  ar & theIsUpdating;
}


void ExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<ExtFunctionCallIterator,
                   ExtFunctionCallIteratorState>::openImpl(planState, offset);

  ExtFunctionCallIteratorState* state =
  StateTraitsImpl<ExtFunctionCallIteratorState>::getState(planState,
                                                          theStateOffset);
  ulong n = (ulong)theChildren.size();
  state->m_extArgs.resize(n);
  for(ulong i = 0; i < n; ++i)
  {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
    // the iterator does not have exlcusive ownership over the sequences
    state->m_extArgs[i]->addReference();
  }
}


bool ExtFunctionCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  Item lOutsideItem;
  const NonContextualExternalFunction* lPureFct = 0;
  const ContextualExternalFunction* lNonePureFct = 0;

  ExtFunctionCallIteratorState* state;
  DEFAULT_STACK_INIT(ExtFunctionCallIteratorState, state, planState);

  try
  {
    if (!theFunction->isContextual())
    {
      lPureFct = dynamic_cast<const NonContextualExternalFunction*>(theFunction);
      ZORBA_ASSERT(lPureFct);

      state->theResult = lPureFct->evaluate(state->m_extArgs);
      if(state->theResult.get() != NULL)
        state->theResultIter = state->theResult->getIterator();
    }
    else
    {
      lNonePureFct = dynamic_cast<const ContextualExternalFunction*>(theFunction);
      ZORBA_ASSERT(lNonePureFct);

      // The planState.theQuery maybe null, e.g. in the case of constant-folding
      // of global variable expressions

      StaticContextImpl theSctxWrapper(theModuleSctx,
                                       (planState.theQuery == NULL?
                                        NULL :
                                        planState.theQuery->getRegisteredDiagnosticHandlerNoSync()));

      DynamicContextImpl theDctxWrapper(NULL,
                                        planState.theGlobalDynCtx,
                                        theModuleSctx);

      state->theResult = lNonePureFct->evaluate(state->m_extArgs,
                                                &theSctxWrapper,
                                                &theDctxWrapper);
      if(state->theResult.get() != NULL)
        state->theResultIter = state->theResult->getIterator();
    } // if (!theFunction->isContextual())
  }
  catch (XQueryException& e)
  {
		set_source( e, loc );
		throw;
  }

  if(state->theResult.get() != NULL)
  {
    state->theResultIter->open();
  }
  while (true)
  {
    try
    {
      if (state->theResult.get() == NULL) // This will happen if the user's external function returns a zorba::ItemSequence_t(NULL)
        break;

      if (!state->theResultIter->next(lOutsideItem))
      {
        state->theResultIter->close();
        break;
      }
    }
    catch (XQueryException& e)
    {
			set_source( e, loc );
			throw;
    }

    result = Unmarshaller::getInternalItem(lOutsideItem);

    if (theIsUpdating)
    {
      if (!result->isPul())
        throw XQUERY_EXCEPTION(err::XUDY0019, ERROR_LOC(loc));
    }
    else
    {
      if (result->isPul())
        throw XQUERY_EXCEPTION(err::XUDY0018, ERROR_LOC(loc));
    }
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


NARY_ACCEPT(ExtFunctionCallIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
