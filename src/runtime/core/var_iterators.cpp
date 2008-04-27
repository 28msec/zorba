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
#include "store/api/iterator.h"
#include "store/api/item.h"
#include "util/Assert.h"
#include "runtime/base/noarybase.h"
#include "runtime/core/var_iterators.h"


namespace zorba
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ForVarIterator::ForVarIterator(
    xqpString name,
    const QueryLoc& loc,
    const void* origin) 
  : 
  NoaryBaseIterator<ForVarIterator, ForVarState >(loc), 
  theVarName(name),
  theOrigin(origin)
{
}


store::Item_t ForVarIterator::nextImpl(PlanState& planState) const
{
  ForVarState* state;
  DEFAULT_STACK_INIT(ForVarState, state, planState);
  STACK_PUSH(state->theValue, state);
  STACK_END (state);
}


void ForVarIterator::bind(store::Item_t value, PlanState& planState)
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

LetVarState::LetVarState()
{
}


LetVarState::~LetVarState()
{
  if (theSourceIter != NULL)
    theSourceIter->close();
}


void LetVarState::reset(PlanState& planState) 
{ 
  PlanIteratorState::reset(planState); 
  if (theSourceIter != NULL) 
    theSourceIter->reset();
}


LetVarIterator::LetVarIterator(xqpString vn, const QueryLoc& loc, const void* origin)
  :
  NoaryBaseIterator<LetVarIterator, LetVarState>(loc),
  theVarName(vn),
  theOrigin(origin)
{
}


store::Item_t LetVarIterator::nextImpl(PlanState& planState) const
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, this->stateOffset);

  ZORBA_ASSERT (state->theSourceIter != NULL);
  return state->theSourceIter->next();
}


void LetVarIterator::bind(store::Iterator_t it, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, this->stateOffset);

  state->theSourceIter = it;
}

} /* namespace zorba */
