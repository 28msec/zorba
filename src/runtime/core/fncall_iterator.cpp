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

#include "zorba/item.h"
#include "zorba/item_sequence.h"
#include "zorba/iterator.h"
#include "zorba/function.h"
#include "zorba/vector_item_sequence.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/user_exception.h"
#include "diagnostics/xquery_exception.h"
#include "diagnostics/xquery_stack_trace.h"
#include "diagnostics/util_macros.h"

#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "functions/udf.h"
#include "functions/external_function.h"

#include "runtime/core/var_iterators.h"
#include "runtime/util/flowctl_exception.h"  // for ExitException
#include "runtime/util/item_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/visitors/printer_visitor.h"

#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"

#include "util/string_util.h"

#include "store/api/index.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"

#ifdef ZORBA_WITH_DEBUGGER

#include "debugger/debugger_commons.h"

#define DEBUGGER_COMMONS lState->thePlanState->theDebuggerCommons
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

#else

#define DEBUGGER_PUSH_FRAME
#define DEBUGGER_POP_FRAME

#endif

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)

SERIALIZABLE_CLASS_VERSIONS(ExtFunctionCallIterator)

/*******************************************************************************
********************************************************************************/
FunctionCallIteratorState::FunctionCallIteratorState():
  theCache(0),
  theCacheKeySnapshot(0),
  theCacheHits(0),
  theCacheMisses(0)
{
}

/*******************************************************************************
********************************************************************************/
UDFunctionCallIteratorState::UDFunctionCallIteratorState():
  theLocalDCtx(NULL),
  theIsLocalDCtxOwner(true),
  thePlan(NULL),
  thePlanState(NULL),
  thePlanOpen(false),
  thePlanStateSize(0)
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


/*******************************************************************************
********************************************************************************/
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

  // If the query does not have eval, theFunctionMap and theFunctionArityMap
  // members of static_context are not serialized. This can cause a memory leak
  // if theUDF deserialization occuring above allocates a udf obj that is only
  // pointed to (via a raw pointer) by this UDFunctionCallIterator. To fix the
  // leak, we register the udf in theSctx.
  if (!ar.is_serializing_out() &&
      !ar.get_ccb()->theHasEval &&
      !theUDF->isBuiltin())
  {
    function* f = theSctx->lookup_fn(theUDF->getName(), theUDF->getArity(), false);

    if (!f)
      theSctx->bind_fn(theUDF, theUDF->getArity(), loc);
  }
}

/*******************************************************************************
********************************************************************************/
zstring UDFunctionCallIterator::getNameAsString() const
{
  return theUDF->getName()->getStringValue();
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
  return theUDF->hasCache();
}

/*******************************************************************************
********************************************************************************/
bool UDFunctionCallIterator::isCacheAcrossSnapshots() const
{
  return theUDF->cacheAcrossSnapshots();
}


/*******************************************************************************
********************************************************************************/
void UDFunctionCallIterator::initCache(
    PlanState& aPlanState,
    UDFunctionCallIteratorState* aState)
{
  if (!aState->theCache && theUDF->hasCache())
  {
    aState->theCache = theUDF->getCache();
    csize numArgs = theChildren.size();
    aState->theArgValues.resize(numArgs);
    for (csize i = 0; i < numArgs; ++i)
      aState->theArgValues[i] = new ItemIterator();
  }
}


/*******************************************************************************
********************************************************************************/
bool UDFunctionCallIterator::probeCache(
    PlanState& aPlanState,
    UDFunctionCallIteratorState* aState,
    std::vector<std::vector <store::Item_t> >& aArguments) const
{
  assert(aState->theCache);

  std::vector<store::Iterator_t>::iterator lIte = aState->theArgWrappers.begin();
  std::vector<store::Item_t> lProbeKeys;
  for (; lIte != aState->theArgWrappers.end(); ++lIte)
  {
    store::Iterator_t& lArgWrapper = (*lIte);
    std::vector<store::Item_t> lArgSeq;
    std::vector<store::Item_t> lKeySeq;
    store::Item_t lArgItemValue;

    if (lArgWrapper) // might be 0 if argument is not used
    {
      while (lArgWrapper->next(lArgItemValue))
      {
        lArgItemValue->ensureSeekable();
        lArgSeq.push_back(lArgItemValue);
        lKeySeq.push_back(lArgItemValue);
      }
    }

    aArguments.push_back(lArgSeq);
    lProbeKeys.push_back(store::Item_t(new simplestore::ItemVector(lKeySeq)));
  }

  aState->theCacheKey = store::Item_t(new simplestore::ItemVector(lProbeKeys));
  if (!isCacheAcrossSnapshots())
    aState->theCacheKeySnapshot = aPlanState.theGlobalDynCtx->getSnapshotID();

  FunctionCache::iterator lIt = aState->theCache->find(aState->theCacheKey, aPlanState);
  if (lIt == aState->theCache->end())
  {
    aState->theCachedResult.clear();
    ++aState->theCacheMisses;
    return false;
  }

  aState->theCachedResult = lIt.getValue();
  ++aState->theCacheHits;
  return true;
}

/*******************************************************************************
********************************************************************************/
void UDFunctionCallIterator::insertCacheEntry(
  PlanState& aPlanState,
  UDFunctionCallIteratorState* aState,
  std::vector<store::Item_t>& aResult) const
{
  assert(aState->theCache);
  if (isCacheAcrossSnapshots() || aState->theCacheKeySnapshot == aPlanState.theGlobalDynCtx->getSnapshotID())
  {
    aState->theCache->insert(aState->theCacheKey, aResult, aPlanState);
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
  initCache(planState, state);

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
bool UDFunctionCallIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  try
  {
    if (theUDF->hasCache())
      return nextImplCache(aResult, aPlanState);
    else
      return nextImplNoCache(aResult, aPlanState);
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


/*******************************************************************************
 ********************************************************************************/
bool UDFunctionCallIterator::nextImplCache(store::Item_t& aResult, PlanState& aPlanState) const
{
  std::vector< std::vector <store::Item_t> > lArguments;
  bool lSkipCache = false;
  bool lCacheHit = false;

  UDFunctionCallIteratorState* lState;
  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, lState, aPlanState);

  // Open the plan, if not done already. This cannot be done in the openImpl
  // method because in the case of recursive functions, we will get into an
  // infinite loop.
  if (!lState->thePlanOpen)
  {
    uint32_t planOffset = 0;
    lState->thePlan->open(*lState->thePlanState, planOffset);
    lState->thePlanOpen = true;
  }


  try
  {
    // check if the result is already in the cache
    lCacheHit = probeCache(aPlanState, lState, lArguments);
  }
  catch (const ZorbaException&)
  {
    lSkipCache = true;
  }

  if (lSkipCache)
  {
    //Pulling the argument iterators eagerly raised an error
    //Disable automatic caching
    //Try to evaluate the function as if no cache is present
    theUDF->disableAutomaticCaching();
    bindArguments(lState, true);

    DEBUGGER_PUSH_FRAME;

    while (consumeNext(aResult, lState->thePlan, *lState->thePlanState))
    {
      DEBUGGER_POP_FRAME;
      STACK_PUSH(true, lState);
      DEBUGGER_PUSH_FRAME;
    }

    DEBUGGER_POP_FRAME;
  }
  else
  {
    // if not in the cache, we bind the arguments to the function
    if (!lSkipCache && !lCacheHit)
    {
      const std::vector<ArgVarRefs>& lArgsRefs = theUDF->getArgVarsRefs();
      const std::vector<store::Iterator_t>& lArgWraps = lState->theArgWrappers;

      for (csize i = 0; i < lArgsRefs.size(); ++i)
      {
        if (lArgWraps[i] != NULL)
        {
          const ArgVarRefs& lArgVarRefs = lArgsRefs[i];
          store::Iterator_t lArgWrapper;
          lState->theArgValues[i]->init(lArguments[i]);
          lArgWrapper = lState->theArgValues[i];

          ArgVarRefs::const_iterator lArgVarRefsIte = lArgVarRefs.begin();
          ArgVarRefs::const_iterator lArgVarRefsEnd = lArgVarRefs.end();

          for (; lArgVarRefsIte != lArgVarRefsEnd; ++lArgVarRefsIte)
          {
            const LetVarIter_t& argRef = (*lArgVarRefsIte);
            assert(argRef != NULL);

            if (argRef != NULL)
            {
              argRef->bind(lArgWrapper, *lState->thePlanState);
            }
          }
        }
      }
    }

    if (!lCacheHit)
    {
      DEBUGGER_PUSH_FRAME;

      if (consumeNext(aResult, lState->thePlan, *lState->thePlanState))
      {
        //We cannot insert directly into the cache, or different call iterators
        //for the same function will see partial results in the cache.
        //We cannot do a stack push here or self-recursive UDFs will not be
        //cached
        while (consumeNext(lState->theNextResult, lState->thePlan, *lState->thePlanState))
        {
          if (!aResult.isNull())
          {
            aResult->ensureSeekable();
            lState->theCachedResult.push_back(aResult);

            DEBUGGER_POP_FRAME;
            STACK_PUSH(true, lState);
            DEBUGGER_PUSH_FRAME;
          }
          aResult = lState->theNextResult;
        }

        if (!aResult.isNull())
        {
          aResult->ensureSeekable();
          lState->theCachedResult.push_back(aResult);
          insertCacheEntry(aPlanState, lState, lState->theCachedResult);

          DEBUGGER_POP_FRAME;
          STACK_PUSH(true, lState);
          DEBUGGER_PUSH_FRAME;
        }
      }
      else
      {
        insertCacheEntry(aPlanState, lState, lState->theCachedResult);
      }

      DEBUGGER_POP_FRAME;
    }
    else // cache hit
    {
      lState->theCachedResultIterator = lState->theCachedResult.begin();
      while (lState->theCachedResultIterator != lState->theCachedResult.end())
      {
        aResult = *(lState->theCachedResultIterator++);
        STACK_PUSH(true, lState);
      }
    }
  }
  STACK_END(lState);
}


/*******************************************************************************
********************************************************************************/
bool UDFunctionCallIterator::nextImplNoCache(store::Item_t& aResult, PlanState& aPlanState) const
{
  UDFunctionCallIteratorState* lState;
  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, lState, aPlanState);

  // Open the plan, if not done already. This cannot be done in the openImpl
  // method because in the case of recursive functions, we will get into an
  // infinite loop.
  if (!lState->thePlanOpen)
  {
    uint32_t planOffset = 0;
    lState->thePlan->open(*lState->thePlanState, planOffset);
    lState->thePlanOpen = true;
  }

  bindArguments(lState, false);

  DEBUGGER_PUSH_FRAME;

  while (consumeNext(aResult, lState->thePlan, *lState->thePlanState))
  {
    DEBUGGER_POP_FRAME;
    STACK_PUSH(true, lState);
    DEBUGGER_PUSH_FRAME;
  }

  DEBUGGER_POP_FRAME;

  STACK_END(lState);
}

/*******************************************************************************
********************************************************************************/
void UDFunctionCallIterator::bindArguments(UDFunctionCallIteratorState* aState, bool aReset) const
{
  const std::vector<ArgVarRefs>& lArgsRefs = theUDF->getArgVarsRefs();
  const std::vector<store::Iterator_t>& lArgWraps = aState->theArgWrappers;

  for (csize i = 0; i < lArgsRefs.size(); ++i)
  {
    if (lArgWraps[i] != NULL)
    {
      const ArgVarRefs& lArgVarRefs = lArgsRefs[i];
      store::Iterator_t lArgWrapper;

      if (i < lArgWraps.size())
      {
        lArgWrapper = lArgWraps[i];
        if (aReset)
          lArgWrapper->reset();
      }

      ArgVarRefs::const_iterator lArgVarRefsIte = lArgVarRefs.begin();
      ArgVarRefs::const_iterator lArgVarRefsEnd = lArgVarRefs.end();

      for (; lArgVarRefsIte != lArgVarRefsEnd; ++lArgVarRefsIte)
      {
        const LetVarIter_t& lArgRef = (*lArgVarRefsIte);
        assert(lArgRef != NULL);

        if (lArgRef != NULL)
        {
          lArgRef->bind(lArgWrapper, *aState->thePlanState);
        }
      }
    }
  }
}

//
// We specialize accept() to descend into the separate plan for the UDF, but
// only for a PrinterVisitor and no other kind of visitor.
//
void UDFunctionCallIterator::accept( PlanIterVisitor &v ) const
{
  if (!v.hasToVisit(this))
    return;

  PrinterVisitor *const pv = dynamic_cast<PrinterVisitor*>( &v );

  v.beginVisit( *this );

  if ( pv )
    pv->beginVisitUDFunctionArgs();

  std::vector<PlanIter_t>::const_iterator i( theChildren.begin() );
  std::vector<PlanIter_t>::const_iterator const end( theChildren.end() );
  for ( ; i != end; ++i )
    (*i)->accept( v );

  if ( pv )
    pv->endVisitUDFunctionArgs();

  if ( pv ) {
    PlanState *const state = pv->getPlanState();
    if ( state && Properties::instance().getCollectProfile() ) {
      UDFunctionCallIteratorState *const udf_state =
        StateTraitsImpl<UDFunctionCallIteratorState>::getState(
          *state, getStateOffset()
        );
      if ( udf_state->thePlanOpen ) {
        if ( PlanIterator *const udf_pi = udf_state->thePlan.getp() ) {
          pv->setPlanState( udf_state->thePlanState );
          pv->visitUDFunctionBody( *udf_pi );
          pv->setPlanState( state );
        }
      }
    }
  }
  v.endVisit( *this );
}


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

  virtual void reset()
  {
    theChild->reset(thePlanState);
  }
};


/*******************************************************************************
********************************************************************************/
ExtFunctionCallIteratorState::ExtFunctionCallIteratorState():
    theIsEvaluated(false),
    theProfileDataMap(NULL)
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

  delete theProfileDataMap;
}

void ExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theResultIter = NULL;
  theResult = NULL;
  theIsEvaluated = false;
}


/*******************************************************************************
********************************************************************************/
ExtFunctionCallIterator::ExtFunctionCallIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    const external_function* functionDef,
    const ExternalFunction* function,
    bool isUpdating,
    bool isSequential,
    const zstring& ns,
    static_context* moduleSctx)
  :
  NaryBaseIterator<ExtFunctionCallIterator,
                   ExtFunctionCallIteratorState>(sctx, loc, args),
  theFunctionDef(const_cast<external_function*>(functionDef)),
  theFunction(function),
  theIsUpdating(isUpdating),
  theIsSequential(isSequential),
  theNamespace(ns),
  theModuleSctx(moduleSctx)
{
}


/*******************************************************************************
********************************************************************************/
ExtFunctionCallIterator::~ExtFunctionCallIterator()
{
}


/*******************************************************************************
********************************************************************************/
zstring ExtFunctionCallIterator::getNameAsString() const {
  String const uri( theFunction->getURI() );
  String const local( theFunction->getLocalName() );

  zstring name( '{' + Unmarshaller::getInternalString( uri ) + '}' + Unmarshaller::getInternalString( local ) );
  return name;
}

/*******************************************************************************
********************************************************************************/
void ExtFunctionCallIterator::serialize(serialization::Archiver& ar)
{
  ar.dont_allow_delay_for_plan_sctx = true;
  serialize_baseclass(ar,
                      static_cast<NaryBaseIterator<
                                  ExtFunctionCallIterator,
                                  ExtFunctionCallIteratorState>*>(this));
  ar.dont_allow_delay_for_plan_sctx = false;

  ar & theFunctionDef;

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
  ar & theIsSequential;
}


/*******************************************************************************
********************************************************************************/
void ExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<ExtFunctionCallIterator,
                   ExtFunctionCallIteratorState>::openImpl(planState, offset);

  ExtFunctionCallIteratorState* state =
  StateTraitsImpl<ExtFunctionCallIteratorState>::getState(planState,
                                                          theStateOffset);

  initCache(planState, state);

  ulong n = (ulong)theChildren.size();
  state->m_extArgs.resize(n);
  for(ulong i = 0; i < n; ++i)
  {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
    // the iterator does not have exclusive ownership over the sequences
    state->m_extArgs[i]->addReference();
  }
}

bool ExtFunctionCallIterator::countImpl( store::Item_t &result,
                                     PlanState &planState ) const {
  int64_t count = 0;

  ExtFunctionCallIteratorState *state;
  DEFAULT_STACK_INIT( ExtFunctionCallIteratorState, state, planState );

  try
  {
    evaluate(planState, state, state->m_extArgs);

    if (!state->theResult.isNull())
    {
      count = state->theResultIter->count();
      state->theResultIter->close();
    }
  }
  catch ( ZorbaException &e )
  {
    set_source( e, loc );
    throw;
  }
  catch (std::exception const& e)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0001_DYNAMIC_RUNTIME_ERROR,
      ERROR_PARAMS(e.what()),
      ERROR_LOC(loc));
  }

  GENV_ITEMFACTORY->createInteger(result, xs_integer(count));
  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ExtFunctionCallIterator::skipImpl( int64_t count, PlanState &planState ) const
{
  if (count == 0)
    return true;

  bool more_items = false;

  ExtFunctionCallIteratorState *state =
      StateTraitsImpl<ExtFunctionCallIteratorState>::getState(planState, this->theStateOffset);

  try
  {
    ZORBA_ASSERT(!state->theIsEvaluated);
    evaluate(planState, state, state->m_extArgs);

    if (!state->theResult.isNull())
    {
      more_items = state->theResultIter->skip(count);
      if (!more_items)
        state->theResultIter->close();
    }
  }
  catch ( ZorbaException &e )
  {
    set_source( e, loc );
    throw;
  }
  catch (std::exception const& e)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0001_DYNAMIC_RUNTIME_ERROR,
      ERROR_PARAMS(e.what()),
      ERROR_LOC(loc));
  }
  return more_items;
}

/*******************************************************************************
********************************************************************************/
bool ExtFunctionCallIterator::nextImpl(
   store::Item_t& aResult,
   PlanState& aPlanState) const
{
  try
  {
    if (isCached())
      return nextImplCache(aResult, aPlanState);
    else
      return nextImplNoCache(aResult, aPlanState);
  }
  catch (ZorbaException& e)
  {
    set_source( e, loc );
    throw;
  }
  catch (std::exception const& e)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0001_DYNAMIC_RUNTIME_ERROR,
      ERROR_PARAMS(e.what()),
      ERROR_LOC(loc));
  }
}


/*******************************************************************************
 ********************************************************************************/
bool ExtFunctionCallIterator::nextImplCache(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  Item lOutsideItem;
  std::vector<zorba::VectorItemSequence> lArgValues;
  bool lCacheHit = false;
  bool lSkipCache = false;
  ExtFunctionCallIteratorState* lState;

  DEFAULT_STACK_INIT(ExtFunctionCallIteratorState, lState, aPlanState);

  if (!lState->theIsEvaluated)
  {
    try
    {
      // check if the result is already in the cache
      lCacheHit = probeCache(aPlanState, lState, lArgValues);
    }
    catch (const ZorbaException&)
    {
      lSkipCache = true;
    }

    if (lSkipCache)
    {
      //Pulling the argument iterators eagerly raised an error
      //Disable automatic caching
      //Try to evaluate the function as if no cache is present
      theFunctionDef->disableAutomaticCaching();

      for (unsigned int i=0; i< lState->m_extArgs.size(); ++i)
      {
        static_cast<ExtFuncArgItemSequence*>(lState->m_extArgs[i])->reset();
      }

      {
        evaluate(aPlanState, lState, lState->m_extArgs);

        if (!lState->theResult.isNull()) //The external function returns zorba::ItemSequence_t(NULL)
        {
          while (lState->theResultIter->next(lOutsideItem))
          {
            aResult = Unmarshaller::getInternalItem(lOutsideItem);

            if (theIsUpdating && !aResult->isPul())
              throw XQUERY_EXCEPTION(err::XUDY0019, ERROR_LOC(loc));
            else if (!theIsUpdating && aResult->isPul())
              throw XQUERY_EXCEPTION(err::XUDY0018, ERROR_LOC(loc));

            if (isSequential())
              aPlanState.theGlobalDynCtx->changeSnapshot();

            STACK_PUSH(true, lState);
          }
          lState->theResultIter->close();
        }
      }

      if (isSequential())
        aPlanState.theGlobalDynCtx->changeSnapshot();
    }
    else
    {
      if (!lCacheHit) //The result is not in the cache, evaluate
      {
        std::vector<zorba::ItemSequence*> lArgs;
        lArgs.resize(lArgValues.size());
        for (unsigned int i = 0; i< lArgValues.size(); ++i)
          lArgs[i] = (&lArgValues[i]);

        evaluate(aPlanState, lState, lArgs);
      }

      if (!lCacheHit) //The result is not in the cache, iterate and save
      {
        if (lState->theResult.get() != NULL) //The external function returns zorba::ItemSequence_t(NULL)
        {
          while (lState->theResultIter->next(lOutsideItem))
          {
            aResult = Unmarshaller::getInternalItem(lOutsideItem);

            if (theIsUpdating && !aResult->isPul())
              throw XQUERY_EXCEPTION(err::XUDY0019, ERROR_LOC(loc));
            else if (!theIsUpdating && aResult->isPul())
              throw XQUERY_EXCEPTION(err::XUDY0018, ERROR_LOC(loc));

            if (!aResult.isNull())
            {
              aResult->ensureSeekable();
              lState->theCachedResult.push_back(aResult);
            }

            if (isSequential())
              aPlanState.theGlobalDynCtx->changeSnapshot();

            STACK_PUSH(true, lState);
          }
          lState->theResultIter->close();

          insertCacheEntry(aPlanState, lState, lState->theCachedResult);

          if (isSequential())
            aPlanState.theGlobalDynCtx->changeSnapshot();
        }
        else //The result is zorba::ItemSequence_t(NULL)
        {
          insertCacheEntry(aPlanState, lState, lState->theCachedResult);
        }
      }
      else //The result is in the cache
      {
        lState->theCachedResultIterator = lState->theCachedResult.begin();
        while (lState->theCachedResultIterator != lState->theCachedResult.end())
        {
          aResult = *(lState->theCachedResultIterator++);
          STACK_PUSH(true, lState);
        }
      }
    }
  }
  else //The function has already been partly evaluated by skip, we cannot cache
       //some items of the return iterator have already been consumed
  {
    if (!lState->theResult.isNull() && //The external function returns zorba::ItemSequence_t(NULL)
        lState->theResultIter->isOpen()) //The iterator has not been skipped past its end
    {
      while (lState->theResultIter->next(lOutsideItem))
      {
        aResult = Unmarshaller::getInternalItem(lOutsideItem);

        if (theIsUpdating && !aResult->isPul())
          throw XQUERY_EXCEPTION(err::XUDY0019, ERROR_LOC(loc));
        else if (!theIsUpdating && aResult->isPul())
          throw XQUERY_EXCEPTION(err::XUDY0018, ERROR_LOC(loc));

        if (isSequential())
          aPlanState.theGlobalDynCtx->changeSnapshot();

        STACK_PUSH(true, lState);
      }
      lState->theResultIter->close();

      if (isSequential())
        aPlanState.theGlobalDynCtx->changeSnapshot();
    }


  }
  STACK_END(lState);
}


/*******************************************************************************
********************************************************************************/
bool ExtFunctionCallIterator::nextImplNoCache(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  Item lOutsideItem;
  ExtFunctionCallIteratorState* lState;

  DEFAULT_STACK_INIT(ExtFunctionCallIteratorState, lState, aPlanState);

  {
    if (!lState->theIsEvaluated)
      evaluate(aPlanState, lState, lState->m_extArgs);

    if (!lState->theResult.isNull() && //The external function returns zorba::ItemSequence_t(NULL)
        lState->theResultIter->isOpen()) //The iterator has not been skipped past its end
    {
      while (lState->theResultIter->next(lOutsideItem))
      {
        aResult = Unmarshaller::getInternalItem(lOutsideItem);

        if (theIsUpdating && !aResult->isPul())
          throw XQUERY_EXCEPTION(err::XUDY0019, ERROR_LOC(loc));
        else if (!theIsUpdating && aResult->isPul())
          throw XQUERY_EXCEPTION(err::XUDY0018, ERROR_LOC(loc));

        if (isSequential())
          aPlanState.theGlobalDynCtx->changeSnapshot();

        STACK_PUSH(true, lState);
      }
      lState->theResultIter->close();
    }
  }

  if (isSequential())
    aPlanState.theGlobalDynCtx->changeSnapshot();

  STACK_END(lState);
}


/*******************************************************************************
********************************************************************************/
void ExtFunctionCallIterator::evaluate(PlanState& aPlanState, ExtFunctionCallIteratorState* aState, std::vector<zorba::ItemSequence*>& aArguments) const
{
  if (theFunction->isContextual())
  {
    ContextualExternalFunction const *const lFunction =
      dynamic_cast<ContextualExternalFunction const*>( theFunction );
    ZORBA_ASSERT( lFunction );

    StaticContextImpl lSctx(theModuleSctx,
                            aPlanState.theQuery ?
                              aPlanState.theQuery->getRegisteredDiagnosticHandlerNoSync():
                              nullptr);

    DynamicContextImpl lDctx(nullptr,
                             aPlanState.theGlobalDynCtx,
                             theModuleSctx);

    aState->theResult = lFunction->evaluate(aArguments, &lSctx, &lDctx);
  }
  else
  {
    NonContextualExternalFunction const *const lFunction =
      dynamic_cast<NonContextualExternalFunction const*>( theFunction );
    ZORBA_ASSERT( lFunction );

    aState->theResult = lFunction->evaluate( aArguments );
  }

  aState->theIsEvaluated = true;
  if (!aState->theResult.isNull())
  {
    aState->theResultIter = aState->theResult->getIterator();
    aState->theResultIter->open();
  }

  if (isSequential())
    aPlanState.theGlobalDynCtx->changeSnapshot();

  if (zorba::Properties::instance().getCollectProfile())
  {
    if (!aState->theProfileDataMap)
      aState->theProfileDataMap = new ProfileDataMap();
    else
      aState->theProfileDataMap->clear();

    ProfileDataMap* lProfileDataMap = theFunction->getProfilingData();
    if (lProfileDataMap)
      aState->theProfileDataMap->swap(*lProfileDataMap);
  }
}


/*******************************************************************************
********************************************************************************/
bool ExtFunctionCallIterator::isCached() const
{
  return theFunctionDef->hasCache();
}


/*******************************************************************************
********************************************************************************/
bool ExtFunctionCallIterator::isCacheAcrossSnapshots() const
{
  return theFunctionDef->cacheAcrossSnapshots();
}


/*******************************************************************************
********************************************************************************/
void ExtFunctionCallIterator::initCache(
    PlanState& aPlanState,
    ExtFunctionCallIteratorState* aState)
{
  if (!aState->theCache && isCached())
  {
    aState->theCache = theFunctionDef->getCache();
  }
}


/*******************************************************************************
********************************************************************************/
bool ExtFunctionCallIterator::probeCache(
    PlanState& aPlanState,
    ExtFunctionCallIteratorState* aState,
    std::vector<zorba::VectorItemSequence>& aArguments) const
{
  assert(aState->theCache);

  std::vector<store::Item_t> probeKeys;
  for (unsigned int i=0; i< aState->m_extArgs.size(); ++i)
  {
    zorba::ItemSequence* lArgWrapper = aState->m_extArgs[i];
    zorba::Iterator_t lIterator = lArgWrapper->getIterator();
    std::vector<zorba::Item> lArgSeq;
    std::vector<store::Item_t> lIntArgSeq;

    zorba::Item lArgItem;
    store::Item_t lIntArgItem;
    lIterator->open();
    while (lIterator->next(lArgItem))
    {
      lIntArgItem = Unmarshaller::getInternalItem(lArgItem);
      lIntArgItem->ensureSeekable();

      lArgSeq.push_back(lArgItem);
      lIntArgSeq.push_back(lIntArgItem);
    }
    lIterator->close();

    aArguments.push_back(zorba::VectorItemSequence(lArgSeq));
    probeKeys.push_back(new simplestore::ItemVector(lIntArgSeq));
  }

  aState->theCacheKey = store::Item_t(new simplestore::ItemVector(probeKeys));
  if (!isCacheAcrossSnapshots())
    aState->theCacheKeySnapshot = aPlanState.theGlobalDynCtx->getSnapshotID();

  FunctionCache::iterator lIt = aState->theCache->find(aState->theCacheKey, aPlanState);
  if (lIt == aState->theCache->end())
  {
    aState->theCachedResult.clear();
    ++aState->theCacheMisses;
    return false;
  }

  aState->theCachedResult = lIt.getValue();
  ++aState->theCacheHits;
  return true;
}


/*******************************************************************************
********************************************************************************/
void ExtFunctionCallIterator::insertCacheEntry(
    PlanState& aPlanState,
    ExtFunctionCallIteratorState* aState,
    std::vector<store::Item_t>& aResult) const
{
  assert(aState->theCache);
  if (isCacheAcrossSnapshots() || aState->theCacheKeySnapshot == aPlanState.theGlobalDynCtx->getSnapshotID())
  {
    aState->theCache->insert(aState->theCacheKey, aResult, aPlanState);
  }
}

NARY_ACCEPT(ExtFunctionCallIterator);

} // namespace zorba
/* vim:set et sw=2 ts=2: */
