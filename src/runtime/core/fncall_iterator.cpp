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

#include "runtime/core/fncall_iterator.h"

#include <map>

#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/pure_stateless_function.h>
#include <zorba/nonepure_stateless_function.h>
#include <zorba/exception.h>

#include "zorbaerrors/error_manager.h"

#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "functions/udf.h"

#include "runtime/core/var_iterators.h"
#include "runtime/util/flowctl_exception.h"  // for ExitException
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)
END_SERIALIZABLE_CLASS_VERSIONS(UDFunctionCallIterator)

SERIALIZABLE_CLASS_VERSIONS(StatelessExtFunctionCallIterator)
END_SERIALIZABLE_CLASS_VERSIONS(StatelessExtFunctionCallIterator)

UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  :
  theFnBodyStateBlock(NULL),
  thePlan(NULL),
  thePlanStateSize(0),
  thePlanOpen(false)
{ 
}


UDFunctionCallIteratorState::~UDFunctionCallIteratorState()
{
}


void UDFunctionCallIteratorState::openPlan()
{
  uint32_t planOffset = 0;
  if (!thePlanOpen) {
    thePlan->open(*theFnBodyStateBlock, planOffset);
  }
  thePlanOpen = true;
}


void UDFunctionCallIteratorState::closePlan()
{
  if (thePlanOpen) {
    thePlan->close(*theFnBodyStateBlock);
  }
  thePlanOpen = false;
}


void UDFunctionCallIteratorState::resetPlan()
{
  if (thePlanOpen) {
    thePlan->reset(*theFnBodyStateBlock);
  }
}

void UDFunctionCallIteratorState::resetChildIters()
{
  std::vector<store::Iterator_t>::const_iterator lIter = theChildIterators.begin();
  std::vector<store::Iterator_t>::const_iterator lEnd = theChildIterators.end();
  for ( ; lIter != lEnd; ++lIter)
    (*lIter)->close();

  theChildIterators.clear();
}


void UDFunctionCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>*)this);

  ar & theUDF;
}


bool UDFunctionCallIterator::isUpdating() const 
{ 
  return theUDF->isUpdating(); 
}


void UDFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
  openImpl(planState, offset);

  UDFunctionCallIteratorState* state = 
  StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, theStateOffset);

  state->thePlan = theUDF->get_plan(planState.theCompilerCB).getp();
  state->thePlanStateSize = state->thePlan->getStateSizeOfSubtree();

  std::auto_ptr<PlanState> block(new PlanState(state->thePlanStateSize,
                                               planState.theStackDepth + 1));
  block->theCompilerCB = planState.theCompilerCB;
  block->theDebuggerCommons = planState.theDebuggerCommons;

  // Must allocate new dctx, as child of the "current" dctx, because the udf may
  // declare local block vars, some of which may hide vars with the same name in 
  // the scope of the caller. 
  block->theRuntimeCB = new RuntimeCB(*planState.theRuntimeCB);
  block->theRuntimeCB->theDynamicContext = new dynamic_context(block->theRuntimeCB->theDynamicContext);

  block->checkDepth(loc);

  state->theFnBodyStateBlock = block.release();
}


void UDFunctionCallIterator::closeImpl(PlanState& planState)
{
  UDFunctionCallIteratorState* state = 
  StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, theStateOffset);

  state->closePlan();

  if (state->theFnBodyStateBlock != NULL &&
      state->theFnBodyStateBlock->theRuntimeCB != NULL)
  {
    delete state->theFnBodyStateBlock->theRuntimeCB->theDynamicContext;
    delete state->theFnBodyStateBlock->theRuntimeCB;
  }

  delete state->theFnBodyStateBlock;
  state->resetChildIters();

  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
  closeImpl(planState);
}


void UDFunctionCallIterator::resetImpl(PlanState& planState) const
{
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::
  resetImpl(planState);

  UDFunctionCallIteratorState* state =
  StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, theStateOffset);

  state->resetPlan();
  state->resetChildIters();
}


bool UDFunctionCallIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  UDFunctionCallIteratorState *state;
  bool success;
  ZorbaDebuggerCommons* lDebugger = planState.theCompilerCB->theDebuggerCommons;
  std::stringstream name;

  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

  if(lDebugger != 0)
  {
    name << theUDF->getName()->getStringValue() << '(';
  }

  {
    // Bind the args.
    state->openPlan();

    std::vector<LetVarIter_t>& iters = theUDF->get_param_iters();
    for (uint32_t i = 0; i < iters.size (); ++i) 
    {
      LetVarIter_t& ref = iters[i];
      if ( ref != NULL) 
      {
        state->theChildIterators.push_back(new PlanIteratorWrapper(theChildren[i], planState));
        state->theChildIterators.back()->open();

        ref->bind(state->theChildIterators.back(), *state->theFnBodyStateBlock);
 
       if(lDebugger != 0)
        {
          store::Iterator_t it = state->theChildIterators.back();
          it->open();
          store::Item_t item;
          name << '$' << ref->getVarName() << '=';
          while(it->next(item))
          {
            String lValue(item->getStringValue());
            if(lValue.length() > 10)
            {
              name.write(lValue.c_str(), 10);
              name << "...";
            } else {
              name << item->getStringValue();
            }
            name << " (" << item->getType()->getStringValue() << ')';
          }
          it->reset();
        }
      }
    }
  }

  if (lDebugger != 0)
  {
    name << ')';
    //lDebugger->theLastKnownStack = lDebugger->theStack;
    //lDebugger->pushStack(std::make_pair<std::string, const QueryLoc>(name.str(), loc)); 
    //lDebugger->isFunctionExecution = true;
  }
  
  for (;;) 
  {
    try
    {
      success = consumeNext (result, state->thePlan, *state->theFnBodyStateBlock);
    }
    catch (ExitException &e)
    {
      state->exitValue = e.val;
      success = false;
    }
    
    if (success)
      STACK_PUSH(true, state);
    else
      break;
  }

  if (state->exitValue != NULL)
    while (state->exitValue->next (result))
      STACK_PUSH(true, state);

  if(lDebugger != 0)
  {
    //lDebugger->theLastKnownStack = lDebugger->theStack;
    //lDebugger->popStack();
  }
  STACK_END (state);
}


NARY_ACCEPT(UDFunctionCallIterator);


// external functions
class ExtFuncArgItemSequence : public ItemSequence 
{
  public:
    ExtFuncArgItemSequence(PlanIter_t child, PlanState& stateBlock)
      : m_child(child),
      m_stateBlock(stateBlock) { }

    bool next(Item& item) 
    {
      store::Item_t result;
      bool status = m_child->consumeNext(result, m_child.getp(), m_stateBlock);
      item = status ? result : NULL;
      return status;
    }

  private:
    PlanIter_t m_child;
    PlanState& m_stateBlock;
};


StatelessExtFunctionCallIteratorState::StatelessExtFunctionCallIteratorState() 
{ 
}


StatelessExtFunctionCallIteratorState::~StatelessExtFunctionCallIteratorState() 
{
}


void StatelessExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  m_result.reset();
}


StatelessExtFunctionCallIterator::StatelessExtFunctionCallIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    const StatelessExternalFunction *function,
    bool aIsUpdating,
    const xqp_string& aPrefix)
  :
  NaryBaseIterator<StatelessExtFunctionCallIterator, 
                   StatelessExtFunctionCallIteratorState>(sctx, loc, args),
  m_function(function),
  theIsUpdating(aIsUpdating),
  thePrefix(aPrefix)
{ 
}


StatelessExtFunctionCallIterator::~StatelessExtFunctionCallIterator()
{
}


void
StatelessExtFunctionCallIterator::serialize(serialization::Archiver& ar)
{
  ar.dont_allow_delay_for_plan_sctx = true;
  serialize_baseclass(ar,
                      static_cast<NaryBaseIterator<
                                  StatelessExtFunctionCallIterator,
                                  StatelessExtFunctionCallIteratorState>*>(this));
  ar.dont_allow_delay_for_plan_sctx = false;
  if (ar.is_serializing_out()) {
    // serialize out: serialize prefix and localname of the function
    ar & thePrefix;
    xqpStringStore_t lTmp;
    lTmp = Unmarshaller::getInternalString(m_function->getLocalName());
    ar.set_is_temp_field_one_level(true);
    ar & lTmp;
    ar.set_is_temp_field_one_level(false);
  } else {
    // serializing in: get the function from the static context
    //                 using the serialized prefix/uri and localname 
    ar & thePrefix;

    xqpStringStore_t lLocalname;
    ar.set_is_temp_field_one_level(true);
    ar & lLocalname;
    ar.set_is_temp_field_one_level(false);
    xqp_string lURI;
    if(thePrefix.getStore())
    {
      theSctx->lookup_ns(thePrefix, lURI);
      m_function = theSctx->lookup_stateless_external_function(lURI,
                                                               lLocalname.getp());
      if (!m_function) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because "
                             << " the external function with URI " << lURI
                             << " and local name " << lLocalname
                             << " is not available through any of the"
                             << " ExternalModules.");
      } 
    }
    else
      m_function = NULL;
  }
  ar & theIsUpdating;
}


void StatelessExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<StatelessExtFunctionCallIterator, 
                   StatelessExtFunctionCallIteratorState>::openImpl(planState, offset);

  StatelessExtFunctionCallIteratorState* state =
  StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState, 
                                                                   theStateOffset);
  int n = theChildren.size();
  state->m_extArgs.resize(n);
  for(int i = 0; i < n; ++i) 
  {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
  }
}


void StatelessExtFunctionCallIterator::closeImpl(PlanState& planState)
{
  StatelessExtFunctionCallIteratorState* state = 
  StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState,
                                                                   theStateOffset);

  // we have the ownership for the item sequences
  int n = theChildren.size();
  for(int i = 0; i < n; ++i) {
    delete state->m_extArgs[i];
  }

  NaryBaseIterator<StatelessExtFunctionCallIterator, 
                   StatelessExtFunctionCallIteratorState>::closeImpl(planState);
}



bool StatelessExtFunctionCallIterator::nextImpl(store::Item_t& result,
                                                PlanState& planState) const
{
  StatelessExtFunctionCallIteratorState *state;
  Item lOutsideItem;
  const PureStatelessExternalFunction* lPureFct = 0;
  const NonePureStatelessExternalFunction* lNonePureFct = 0;
  DEFAULT_STACK_INIT(StatelessExtFunctionCallIteratorState, state, planState);

  try {
    if (m_function->isDeterministic()) {
      lPureFct = dynamic_cast<const PureStatelessExternalFunction*>(m_function);
      ZORBA_ASSERT(lPureFct);

      state->m_result = lPureFct->evaluate(state->m_extArgs);
    } else {
      lNonePureFct = dynamic_cast<const NonePureStatelessExternalFunction*>(m_function);
      ZORBA_ASSERT(lNonePureFct);

      ZORBA_ASSERT(planState.theRuntimeCB->theQuery);
      state->m_result = lNonePureFct->evaluate(state->m_extArgs,
          planState.theRuntimeCB->theQuery->getStaticContext(),
          planState.theRuntimeCB->theQuery->getDynamicContext());
    }

  } catch(const ZorbaException& e) {
    // take all information from the exception raised in 
    // the external function (e.g. file name) + add loc information
    throw error::ErrorManager::createException(e.getErrorCode(),
                                               e.getDescription().c_str(), 
                                               e.getFileName().c_str(),
                                               e.getFileLineNumber(), 
                                               loc.getLineBegin(),
                                               loc.getColumnBegin(),
                                               loc.getFilenameBegin());
  }
  while (true)
  {
    try {
      if (!state->m_result->next(lOutsideItem)) {
        break;
      }
    } catch(const ZorbaException& e) {
      // take all information from the exception raised in
      // the external function (e.g. file name) + add loc information
      throw error::ErrorManager::createException(e.getErrorCode(),
                                                 e.getDescription().c_str(), 
                                                 e.getFileName().c_str(),
                                                 e.getFileLineNumber(), 
                                                 loc.getLineBegin(),
                                                 loc.getColumnBegin(),
                                                 loc.getFilenameBegin());
    }
    result = Unmarshaller::getInternalItem(lOutsideItem);
    if (theIsUpdating)
    {
      if (!result->isPul())
      {
        ZORBA_ERROR_LOC(XUDY0019, loc);
      }
    }
    else 
    {
      if (result->isPul())
      {
        ZORBA_ERROR_LOC(XUDY0018, loc); 
      }
    }
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


NARY_ACCEPT(StatelessExtFunctionCallIterator);


} /* namespace zorba */

/* vim:set ts=2 sw=2: */
