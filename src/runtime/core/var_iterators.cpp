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
  NoaryBaseIterator<ForVarIterator, ForVarState >(loc), 
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
  NoaryBaseIterator<LetVarIterator, LetVarState>(loc),
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


void LetVarIterator::bind(Iterator_t it, PlanState& planState)
{
  LetVarState* state;
  GET_STATE(LetVarState, state, planState);
  state->theSourceIter = it;
}

} /* namespace xqp */
