#include <zorba/item.h>
#include <zorba/iterator.h>

#include "util/Assert.h"
#include "runtime/base/noarybase.h"
#include "runtime/core/var_iterators.h"


namespace xqp
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
LetVarState::LetVarState(){}

LetVarState::~LetVarState()
{
  if (theSourceIter != NULL)
    theSourceIter->close();
}

void LetVarState::reset(PlanState& planState) 
{ 
  PlanIteratorState::reset(planState); 
  if (theSourceIter != NULL) {
    theSourceIter->reset();
  }
}


ForVarIterator::ForVarIterator(xqpString name, yy::location loc, const void* origin) 
  : 
  NoaryBaseIterator<ForVarIterator, ForVarState >(loc), 
  theVarName(name),
  theOrigin(origin)
{
}


Item_t ForVarIterator::nextImpl(PlanState& planState) const
{
  ForVarState* state;
  DEFAULT_STACK_INIT(ForVarState, state, planState);
  STACK_PUSH(state->theValue, state);
  STACK_END();
}


void ForVarIterator::bind(Item_t value, PlanState& planState)
{
  ForVarState* state;
  state = StateTraitsImpl<ForVarState>::getState(planState, this->stateOffset);

  state->theValue = value;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  LetVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


LetVarIterator::LetVarIterator(xqpString vn, yy::location loc, const void* origin)
  :
  NoaryBaseIterator<LetVarIterator, LetVarState>(loc),
  theVarName(vn),
  theOrigin(origin)
{
}


Item_t LetVarIterator::nextImpl(PlanState& planState) const
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, this->stateOffset);

  ZORBA_ASSERT (state->theSourceIter != NULL);
  return state->theSourceIter->next();
}


void LetVarIterator::bind(Iterator_t it, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, this->stateOffset);

  state->theSourceIter = it;
}

} /* namespace xqp */
