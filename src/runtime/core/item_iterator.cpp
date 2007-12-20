/* 
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska, David Graf
 *
 */

#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"

using namespace std;
namespace xqp
{

  /* begin class EmptyIterator */
  void EmptyIterator::setOffset ( PlanState& planState, uint32_t& offset )
  {
    this->stateOffset = offset;
    offset += this->getStateSize();
  }
  /* end class EmptyIterator */

  /* begin class SingletonIterator */
  SingletonIterator::SingletonIterator ( yy::location loc, Item_t aValue) :
      NoaryBaseIterator<SingletonIterator> ( loc ), theValue ( aValue )
  {
  }

  SingletonIterator::~SingletonIterator()
  {
  }

  Item_t SingletonIterator::nextImpl ( PlanState& planState )
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    STACK_PUSH ( theValue, state );
    STACK_END();
  }
  /* end class SingletonIterator */



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

  void IfThenElseIterator::resetImpl ( PlanState& planState )
  {
    IfThenElseIteratorState* state;
    GET_STATE ( IfThenElseIteratorState, state, planState );
    state->reset();
    
    this->resetChild ( theCondIter, planState );
    this->resetChild ( theThenIter, planState );
    this->resetChild ( theElseIter, planState );
  }

  void IfThenElseIterator::releaseResourcesImpl ( PlanState& planState )
  {
    this->releaseChildResources ( theCondIter, planState );
    this->releaseChildResources ( theThenIter, planState );
    this->releaseChildResources ( theElseIter, planState );
  }
  
  uint32_t IfThenElseIterator::getStateSizeOfSubtree() const {
    return getStateSize() 
        + theCondIter->getStateSizeOfSubtree()
        + theThenIter->getStateSizeOfSubtree()
        + theElseIter->getStateSizeOfSubtree();
  }
  void IfThenElseIterator::setOffset ( PlanState& planState, uint32_t& offset ) {
    this->stateOffset = offset;
    offset += getStateSize();
    theCondIter->setOffset(planState, offset);
    theThenIter->setOffset(planState, offset);
    theElseIter->setOffset(planState, offset);
  }
} /* namespace xqp */

