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

#include "diagnostics/assert.h"

#include "runtime/core/item_iterator.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"


using namespace std;
namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(EmptyIterator)
END_SERIALIZABLE_CLASS_VERSIONS(EmptyIterator)

SERIALIZABLE_CLASS_VERSIONS(SingletonIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SingletonIterator)

SERIALIZABLE_CLASS_VERSIONS(IfThenElseIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IfThenElseIterator)


/*******************************************************************************

********************************************************************************/
bool EmptyIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  return false;
}


NOARY_ACCEPT(EmptyIterator);


/*******************************************************************************

********************************************************************************/
bool SingletonIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  result = theValue;
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


NOARY_ACCEPT(SingletonIterator);


/*******************************************************************************

********************************************************************************/
IfThenElseIterator::IfThenElseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aCondIter,
    PlanIter_t& aThenIter,
    PlanIter_t& aElseIter,
    bool aIsUpdating,
    bool aIsBooleanIter)
  :
  Batcher<IfThenElseIterator>(sctx, loc),
  theCondIter(aCondIter),
  theThenIter(aThenIter),
  theElseIter(aElseIter),
  theIsUpdating(aIsUpdating),
  theIsBooleanIter(aIsBooleanIter)
{ }


void IfThenElseIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);
  theCondIter->accept(v);
  theThenIter->accept(v);
  theElseIter->accept(v);
  v.endVisit(*this);
}


bool IfThenElseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  IfThenElseIteratorState* state;
  DEFAULT_STACK_INIT(IfThenElseIteratorState, state, planState);

  if (theIsBooleanIter) 
  {
    store::Item_t condResult;
    consumeNext ( condResult, theCondIter.getp(), planState );
    state->theThenUsed = condResult->getBooleanValue();
  }
  else
  {
    state->theThenUsed = FnBooleanIterator::effectiveBooleanValue(this->loc,
                                                                  planState,
                                                                  theCondIter);
  }

  while (true)
  {
    STACK_PUSH(consumeNext(result,
                           (state->theThenUsed ? theThenIter.getp() : theElseIter.getp()),
                           planState), 
               state);
  }

  STACK_END(state);
}


void IfThenElseIterator::openImpl(PlanState& planState, uint32_t& offset) 
{
  StateTraitsImpl<IfThenElseIteratorState>::
  createState(planState, theStateOffset, offset);

  theCondIter->open(planState, offset);
  theThenIter->open(planState , offset);
  theElseIter->open(planState , offset);
}


void IfThenElseIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<IfThenElseIteratorState>::reset(planState, theStateOffset);
  
  theCondIter->reset(planState);
  theThenIter->reset(planState);
  theElseIter->reset(planState);
}


void IfThenElseIterator::closeImpl(PlanState& planState) const
{
  theCondIter->close(planState);
  theThenIter->close(planState);
  theElseIter->close(planState);

  StateTraitsImpl<IfThenElseIteratorState>::destroyState(planState, theStateOffset);
}


uint32_t IfThenElseIterator::getStateSizeOfSubtree() const 
{
  return getStateSize() 
      + theCondIter->getStateSizeOfSubtree()
      + theThenIter->getStateSizeOfSubtree()
      + theElseIter->getStateSizeOfSubtree();
}


} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
