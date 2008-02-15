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
Item_t SingletonIterator::nextImpl ( PlanState& planState ) const
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

Item_t IfThenElseIterator::nextImpl ( PlanState& planState ) const
{
  Item_t condResult;

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

  STACK_END();
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
} /* namespace xqp */

