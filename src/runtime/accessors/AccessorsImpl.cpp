/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "runtime/accessors/AccessorsImpl.h"

namespace xqp {

Item_t
FnDataIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  PlanIter_t iter;
  
  FnDataIteratorState* lState;
  DEFAULT_STACK_INIT(FnDataIteratorState, lState, planState);
  
  while (true) {
    item = this->consumeNext( theChild, planState );
    if (item == NULL)
      break;
    lState->theTypedValue = item->getTypedValue();
      
    while (true) {
      item = lState->theTypedValue->next();
      if (item == NULL)
        break;
      Assert(!item->isNode());
      STACK_PUSH( item, lState );
    }
  }
  lState->theTypedValue = 0;
  STACK_END();
}
  
void
FnDataIterator::resetImpl(PlanState& aPlanState)
{
  FnDataIteratorState* lState;
  GET_STATE(FnDataIteratorState, lState, aPlanState);
  lState->reset();
  this->resetChild( theChild, aPlanState );
}
  
void
FnDataIterator::releaseResourcesImpl(PlanState& planState)
{
  FnDataIteratorState* lState;
  GET_STATE(FnDataIteratorState, lState, planState);
  lState->theTypedValue = 0;
  this->releaseChildResources( theChild, planState );
}

Item_t FnRootIterator::nextImpl(PlanState& planState)
{
  Item_t contextNode;
  Item_t parentNode;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  contextNode = consumeNext(theChild, planState);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0004,
         &loc, false, "The argument of the fn:root function is not a node");
  }

  parentNode = contextNode->getParent();

  while (parentNode != NULL)
  {
    contextNode = parentNode;
    parentNode = parentNode->getParent();
  }

  STACK_PUSH(contextNode, lState);
  STACK_END();
}

Item_t FnNodeNameIterator::nextImpl(PlanState& planState)
{
  Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChild, planState);

  if (inNode == NULL) {
    return NULL;
  }

  if (!inNode->isNode()) {
    ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0004,
         &loc, false, "The argument of the fn:node-name function is not a node");
  }
  
  STACK_PUSH(inNode->getNodeName(), state);
  STACK_END();
}

Item_t FnStringIterator::nextImpl(PlanState& planState)
{
  Item_t inVal;

  FnStringIteratorState *state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while((inVal = consumeNext(theChild, planState)) != NULL) {
    state->hasOutput = true;
    STACK_PUSH(Zorba::getItemFactory()->createString(inVal->getStringValue()), state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) {
    state->hasOutput = true;
    STACK_PUSH(Zorba::getItemFactory()->createString(""), state);
  }

  STACK_END();
}

void FnStringIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<FnStringIterator>::resetImpl(planState);

  FnStringIteratorState* state;
  GET_STATE(FnStringIteratorState, state, planState);
  state->reset();
}

void FnStringIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<FnStringIterator>::releaseResourcesImpl(planState);
  
  FnStringIteratorState* state;
  GET_STATE(FnStringIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}

void FnStringIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<FnStringIterator>::setOffset(planState, offset);
  FnStringIteratorState* state = 
    new (planState.block + stateOffset) FnStringIteratorState;
}

void FnStringIterator::FnStringIteratorState::init()
{
  PlanIterator::PlanIteratorState::init();
  hasOutput = false;
}

void FnStringIterator::FnStringIteratorState::reset()
{
  PlanIterator::PlanIteratorState::reset();
  hasOutput = false;
}


} /* namespace xqp */
/* vim:set ts=2 sw=2: */
