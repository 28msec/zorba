/* 
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska, David Graf
 *
 */

#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"

using namespace std;
namespace xqp
{


/* start class SingletonIterator */
Item_t SingletonIterator::nextImpl ( PlanState& planState )
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  STACK_PUSH ( theValue, state );
  STACK_END();
}


/* start class IfThenElseIterator */
IfThenElseIterator::IfThenElseIterator ( const yy::location& loc,
        PlanIter_t& aCondIter, PlanIter_t& aThenIter,
        PlanIter_t& aElseIter, bool aIsBooleanIter ) :
    Batcher<IfThenElseIterator> ( loc ), theCondIter ( aCondIter ),
    theThenIter ( aThenIter ), theElseIter ( aElseIter ),
    theIsBooleanIter ( aIsBooleanIter )
{
}

Item_t IfThenElseIterator::nextImpl ( PlanState& planState )
{
  Item_t condResult;

  IfThenElseIteratorState* state;
  DEFAULT_STACK_INIT ( IfThenElseIteratorState, state, planState );

  if ( theIsBooleanIter )
    condResult = this->consumeNext ( theCondIter, planState );
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
      this->consumeNext ( 
        (state->theThenUsed ? theThenIter : theElseIter), planState 
      ), 
      state 
    );
  }

  STACK_END();
}

void IfThenElseIterator::openImpl ( PlanState& planState, uint32_t& offset ) {
  this->stateOffset = offset;
  offset += getStateSize();

  IfThenElseIteratorState* state = new (planState.theBlock + this->stateOffset) IfThenElseIteratorState;

  theCondIter->open( planState, offset );
  theThenIter->open( planState , offset);
  theElseIter->open( planState , offset);
}

void IfThenElseIterator::resetImpl ( PlanState& planState )
{
  IfThenElseIteratorState* state;
  GET_STATE ( IfThenElseIteratorState, state, planState );
  state->reset(planState);
  
  theCondIter->reset( planState );
  theThenIter->reset( planState );
  theElseIter->reset( planState );
}

void IfThenElseIterator::closeImpl ( PlanState& planState )
{
  theCondIter->close( planState );
  theThenIter->close( planState );
  theElseIter->close( planState );

  IfThenElseIteratorState* state;
  GET_STATE ( IfThenElseIteratorState, state, planState );
  state->~IfThenElseIteratorState();
}

uint32_t IfThenElseIterator::getStateSizeOfSubtree() const {
  return getStateSize() 
      + theCondIter->getStateSizeOfSubtree()
      + theThenIter->getStateSizeOfSubtree()
      + theElseIter->getStateSizeOfSubtree();
}
} /* namespace xqp */

