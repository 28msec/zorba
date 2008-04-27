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
#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "store/api/temp_seq.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"

using namespace std;
namespace zorba
{


/* start class SingletonIterator */
store::Item_t SingletonIterator::nextImpl ( PlanState& planState ) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  STACK_PUSH ( theValue, state );
  STACK_END (state);
}


/* start class IfThenElseIterator */
IfThenElseIterator::IfThenElseIterator(
    const QueryLoc& loc,
    PlanIter_t& aCondIter,
    PlanIter_t& aThenIter,
    PlanIter_t& aElseIter,
    bool aIsUpdating,
    bool aIsBooleanIter )
  :
  Batcher<IfThenElseIterator> ( loc ),
  theCondIter ( aCondIter ),
  theThenIter ( aThenIter ),
  theElseIter ( aElseIter ),
  theIsUpdating ( aIsUpdating ),
  theIsBooleanIter ( aIsBooleanIter )
{ }


store::Item_t IfThenElseIterator::nextImpl ( PlanState& planState ) const
{
  store::Item_t condResult;

  IfThenElseIteratorState* state;
  DEFAULT_STACK_INIT ( IfThenElseIteratorState, state, planState );

  if ( theIsBooleanIter )
    condResult = consumeNext ( theCondIter.getp(), planState );
  else
    condResult = FnBooleanIterator::effectiveBooleanValue ( this->loc,
                 planState, theCondIter );

  if ( condResult->getBooleanValue() )
    state->theThenUsed = true;
  else
    state->theThenUsed = false;

  while ( true )
  {
    STACK_PUSH (
      consumeNext ( (state->theThenUsed ? theThenIter.getp() : theElseIter.getp()), planState ), 
      state 
    );
  }

  STACK_END (state);
}

void IfThenElseIterator::openImpl ( PlanState& planState, uint32_t& offset ) {
  StateTraitsImpl<IfThenElseIteratorState>::createState(planState, this->stateOffset, offset);

  theCondIter->open( planState, offset );
  theThenIter->open( planState , offset);
  theElseIter->open( planState , offset);
}

void IfThenElseIterator::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<IfThenElseIteratorState>::reset(planState, this->stateOffset);
  
  theCondIter->reset( planState );
  theThenIter->reset( planState );
  theElseIter->reset( planState );
}

void IfThenElseIterator::closeImpl ( PlanState& planState ) const
{
  theCondIter->close( planState );
  theThenIter->close( planState );
  theElseIter->close( planState );

  StateTraitsImpl<IfThenElseIteratorState>::destroyState(planState, this->stateOffset);
}

uint32_t IfThenElseIterator::getStateSizeOfSubtree() const {
  return getStateSize() 
      + theCondIter->getStateSizeOfSubtree()
      + theThenIter->getStateSizeOfSubtree()
      + theElseIter->getStateSizeOfSubtree();
}
} /* namespace zorba */

