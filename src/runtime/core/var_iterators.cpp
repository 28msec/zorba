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

ForVarIterator::ForVarIterator(xqpString name, yy::location loc, const void* origin) 
  : 
  NoaryBaseIterator<ForVarIterator>(loc), 
  theVarName(name),
  theOrigin(origin)
{
}


Item_t ForVarIterator::nextImpl(PlanState& planState)
{
  ForVarState* state;
  DEFAULT_STACK_INIT(ForVarState, state, planState);
  STACK_PUSH(state->theValue, state);
  STACK_END();
}

 
void ForVarIterator::resetImpl(PlanState& planState)
{
  // Do not reset the current value of this var. Only reset the duffs line so
  // that when nextImpl() is called again, the same value will be returned to
  // the caller.
  NoaryBaseIterator<ForVarIterator>::resetImpl(planState);
}


void ForVarIterator::releaseResourcesImpl(PlanState& planState)
{
  NoaryBaseIterator<ForVarIterator>::releaseResourcesImpl(planState);

  ForVarState* state;
  GET_STATE(ForVarState, state, planState);
  state->theValue = NULL;
}


void ForVarIterator::bind(Item_t value, PlanState& planState)
{
  ForVarState* state;
  GET_STATE(ForVarState, state, planState);
  state->theValue = value;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  LetVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


LetVarIterator::LetVarIterator(xqpString vn, yy::location loc, const void* origin)
  :
  NoaryBaseIterator<LetVarIterator>(loc),
  theVarName(vn),
  theOrigin(origin)
{
}


Item_t LetVarIterator::nextImpl(PlanState& planState)
{
  LetVarState* state;
  GET_STATE(LetVarState, state, planState);
  ZORBA_ASSERT (state->theSourceIter != NULL);
  return state->theSourceIter->next();
}


void LetVarIterator::resetImpl(PlanState& planState)
{
  NoaryBaseIterator<LetVarIterator>::resetImpl(planState);

  LetVarState* state;
  GET_STATE(LetVarState, state, planState);
  if (state->theSourceIter != NULL)
    state->theSourceIter->reset();
}


void LetVarIterator::releaseResourcesImpl(PlanState& planState)
{
  NoaryBaseIterator<LetVarIterator>::releaseResourcesImpl(planState);

  LetVarState* state;
  GET_STATE(LetVarState, state, planState);
  if (state->theSourceIter != NULL)
  {
    state->theSourceIter->close();
    state->theSourceIter = NULL;
  }
}


void LetVarIterator::bind(Iterator_t it, PlanState& planState)
{
  LetVarState* state;
  GET_STATE(LetVarState, state, planState);
  state->theSourceIter = it;
}

}
