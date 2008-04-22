#include <boost/smart_ptr.hpp>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/stateless_function.h>

#include "errors/error_manager.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/fncall_iterator.h"
#include "functions/function.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "api/unmarshaller.h"

namespace zorba {

UDFunctionCallIteratorState::UDFunctionCallIteratorState()
  : theFnBodyStateBlock(NULL),
    thePlan(NULL),
    thePlanStateSize(0),
    thePlanOpen(false) { }

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

bool UDFunctionCallIterator::isUpdating() const 
{ 
  return theUDF->isUpdating(); 
}

void UDFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::openImpl(planState, offset);
  UDFunctionCallIteratorState *state = StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, this->stateOffset);

  state->thePlan = theUDF->get_plan(planState.theCompilerCB).getp();
  state->thePlanStateSize = state->thePlan->getStateSizeOfSubtree();
  state->theFnBodyStateBlock = new PlanState(state->thePlanStateSize);
  state->theFnBodyStateBlock->theRuntimeCB = planState.theRuntimeCB;
  state->theFnBodyStateBlock->theCompilerCB = planState.theCompilerCB;
}

void UDFunctionCallIterator::closeImpl(PlanState& planState)
{
  UDFunctionCallIteratorState *state = StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, this->stateOffset);

  state->closePlan();
  delete state->theFnBodyStateBlock;
  state->resetChildIters();

  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::closeImpl(planState);
}

void UDFunctionCallIterator::resetImpl(PlanState& planState) const
{
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>::resetImpl(planState);
  UDFunctionCallIteratorState *state = StateTraitsImpl<UDFunctionCallIteratorState>::getState(planState, this->stateOffset);

  state->resetPlan();
  state->resetChildIters();
}

store::Item_t UDFunctionCallIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lSequenceItem;
  UDFunctionCallIteratorState *state;

  DEFAULT_STACK_INIT(UDFunctionCallIteratorState, state, planState);

  {
    // Bind the args.
    state->openPlan();
    std::vector<LetVarIter_t>& iters = theUDF->get_param_iters();
    for (uint32_t i = 0; i < iters.size (); ++i) {
      LetVarIter_t& ref = iters[i];
      if ( ref != NULL) {
        state->theChildIterators.push_back(new PlanIteratorWrapper(theChildren[i], planState));
        state->theChildIterators.back()->open();
        ref->bind(state->theChildIterators.back(), *state->theFnBodyStateBlock);
      }
    }
  }

  while ((lSequenceItem = consumeNext(state->thePlan, *state->theFnBodyStateBlock)) != NULL) {
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END (state);
}


// external functions
class ExtFuncArgItemSequence : public ItemSequence {
  public:
    ExtFuncArgItemSequence(PlanIter_t child, PlanState& stateBlock)
      : m_child(child),
      m_stateBlock(stateBlock) { }

    bool next(Item& item) 
    {
      item = m_child->consumeNext(m_child.getp(), m_stateBlock);
      return !item.isNull();
    }

  private:
    PlanIter_t m_child;
    PlanState& m_stateBlock;
};

StatelessExtFunctionCallIteratorState::StatelessExtFunctionCallIteratorState() { }

StatelessExtFunctionCallIteratorState::~StatelessExtFunctionCallIteratorState() { }

void StatelessExtFunctionCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  m_result.reset();
}

StatelessExtFunctionCallIterator::StatelessExtFunctionCallIterator(const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    const StatelessExternalFunction *function,
    bool aIsUpdating)
  : NaryBaseIterator<StatelessExtFunctionCallIterator, 
                     StatelessExtFunctionCallIteratorState>(loc, args),
    m_function(function), theIsUpdating(aIsUpdating) { }

void StatelessExtFunctionCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<StatelessExtFunctionCallIterator, 
                   StatelessExtFunctionCallIteratorState>::openImpl(planState, offset);

  StatelessExtFunctionCallIteratorState 
    *state = StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState, 
                                                                              this->stateOffset);
  int n = theChildren.size();
  state->m_extArgs.resize(n);
  for(int i = 0; i < n; ++i) {
    state->m_extArgs[i] = new ExtFuncArgItemSequence(theChildren[i], planState);
  }
}

store::Item_t StatelessExtFunctionCallIterator::nextImpl(PlanState& planState) const
{
  StatelessExtFunctionCallIteratorState *state;
  store::Item_t lSequenceItem;
  Item lOutsideItem;
  DEFAULT_STACK_INIT(StatelessExtFunctionCallIteratorState, state, planState);

  state->m_result = m_function->evaluate(state->m_extArgs);
  while (state->m_result->next(lOutsideItem)) {
    lSequenceItem = Unmarshaller::getInternalItem(lOutsideItem);
    if (theIsUpdating)
    {
      if (!lSequenceItem->isPul())
      {
        ZORBA_ERROR_LOC(ZorbaError::XUDY0019, loc);
      }
    } else {
      if (lSequenceItem->isPul())
      {
        ZORBA_ERROR_LOC(ZorbaError::XUDY0018, loc); 
      }
    }
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END (state);
}

void StatelessExtFunctionCallIterator::closeImpl(PlanState& planState)
{
  StatelessExtFunctionCallIteratorState *state = 
    StateTraitsImpl<StatelessExtFunctionCallIteratorState>::getState(planState, this->stateOffset);

  // we have the ownership for the item sequences
  int n = theChildren.size();
  for(int i = 0; i < n; ++i) {
    delete state->m_extArgs[i];
  }

  NaryBaseIterator<StatelessExtFunctionCallIterator, 
                   StatelessExtFunctionCallIteratorState>::closeImpl(planState);
}


}

/* vim:set ts=2 sw=2: */
