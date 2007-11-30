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
  void EmptyIterator::setOffset ( PlanState& planState, int32_t& offset )
  {
    this->stateOffset = offset;
    offset += this->getStateSize();
  }
  /* end class EmptyIterator */

  /* begin class SingletonIterator */
  SingletonIterator::SingletonIterator ( yy::location loc, Item_t aValue) :
      Batcher<SingletonIterator> ( loc ), theValue ( aValue )
  {
  }

  SingletonIterator::~SingletonIterator()
  {
  }

  Item_t SingletonIterator::nextImpl ( PlanState& planState )
  {
    PlanIteratorState* state;
    STACK_INIT ( PlanIteratorState, state, planState );
    STACK_PUSH ( theValue, state );
    STACK_END();
  }

  void SingletonIterator::resetImpl ( PlanState& planState )
  {
    PlanIterator::PlanIteratorState* state;
    GET_STATE ( PlanIteratorState, state, planState );
    state->reset();
  }

  void SingletonIterator::releaseResourcesImpl ( PlanState& planState )
  {
  }

  int32_t SingletonIterator::getStateSize()
  {
    return sizeof ( PlanIterator::PlanIteratorState );
  }

  int32_t SingletonIterator::getStateSizeOfSubtree()
  {
    return this->getStateSize();
  }

  void SingletonIterator::setOffset ( PlanState& planState, int32_t& offset )
  {
    this->stateOffset = offset;
    offset += this->getStateSize();
  }
  /* end class SingletonIterator */

  /* begin class EnclosedIterator */
  EnclosedIterator::EnclosedIterator ( const yy::location& loc,
                                       PlanIter_t& childIter ) :
      UnaryBaseIterator<EnclosedIterator> ( loc, childIter )
  {
  }

  Item_t EnclosedIterator::nextImpl ( PlanState& planState )
  {
    EnclosedState* state;
    STACK_INIT ( EnclosedState, state, planState );

    while ( true )
    {
      state->theContextItem = consumeNext ( theChild, planState );
      if ( state->theContextItem == NULL )
      {
        if ( state->theString != "" )
        {
          STACK_PUSH ( zorba::getItemFactory()->createTextNode ( state->theString ).get_ptr(),
                        state );
          state->theString = "";
        }
        break;
      }
      else if ( state->theContextItem->isNode() )
      {
        if ( state->theString != "" )
        {
          STACK_PUSH ( zorba::getItemFactory()->createTextNode ( state->theString ).get_ptr(),
                        state );
          state->theString = "";
        }
        STACK_PUSH ( state->theContextItem, state );
      }
      else if ( state->theString == "" )
      {
        state->theString = state->theContextItem->getStringProperty();
      }
      else
      {
        state->theString += " "
                            + state->theContextItem->getStringProperty();
      }
    }
    STACK_END();
  }

  void EnclosedIterator::resetImpl ( PlanState& planState )
  {
    UnaryBaseIterator<EnclosedIterator>::resetImpl ( planState );

    EnclosedState* state;
    GET_STATE ( EnclosedState, state, planState );
    state->theString = "";
  }

  void EnclosedIterator::releaseResourcesImpl ( PlanState& planState )
  {
    UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl ( planState );

    EnclosedState* state;
    GET_STATE ( EnclosedState, state, planState );
    state->theContextItem = NULL;
    state->theString.clear();
  }

  void EnclosedIterator::setOffset ( PlanState& planState, int32_t& offset )
  {
    UnaryBaseIterator<EnclosedIterator>::setOffset ( planState, offset );

    EnclosedState* state = new ( planState.block + stateOffset ) EnclosedState;
  }

  void EnclosedIterator::EnclosedState::init()
  {
    PlanIterator::PlanIteratorState::init();
    theString = "";
  }

  /* end class EnclosedIterator */

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
    STACK_INIT ( IfThenElseIteratorState, state, planState );

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
  
  int32_t IfThenElseIterator::getStateSize() {
    return sizeof(IfThenElseIteratorState);
  }
  int32_t IfThenElseIterator::getStateSizeOfSubtree() {
    return getStateSize() 
        + theCondIter->getStateSizeOfSubtree()
        + theThenIter->getStateSizeOfSubtree()
        + theElseIter->getStateSizeOfSubtree();
  }
  void IfThenElseIterator::setOffset ( PlanState& planState, int32_t& offset ) {
    this->stateOffset = offset;
    offset += getStateSize();
    theCondIter->setOffset(planState, offset);
    theThenIter->setOffset(planState, offset);
    theElseIter->setOffset(planState, offset);
  }
} /* namespace xqp */

