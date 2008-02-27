/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */
#include <zorba/item.h>
#include <zorba/iterator.h>

#include "system/zorba.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "util/Assert.h"
#include "store/api/item_factory.h"

namespace xqp {

// 2.4 fn:data
//---------------------
FnDataIteratorState::FnDataIteratorState() {}
FnDataIteratorState::~FnDataIteratorState() {}

void FnDataIteratorState::init(PlanState& planState) 
{ 
  PlanIteratorState::init( planState );
  theTypedValue = NULL;
}

void FnDataIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset( planState );
  theTypedValue = NULL;
}

Item_t
FnDataIterator::nextImpl(PlanState& planState) const
{
  Item_t item;
  PlanIter_t iter;
  
  FnDataIteratorState* lState;
  DEFAULT_STACK_INIT(FnDataIteratorState, lState, planState);
  
  while (true) {
    item = consumeNext( theChildren[0].getp(), planState );
    if (item == NULL)
      break;
    lState->theTypedValue = item->getTypedValue();
    lState->theTypedValue->open();
      
    while (true) {
      item = lState->theTypedValue->next();
      if (item == NULL)
        break;
      Assert(!item->isNode());
      STACK_PUSH( item, lState );
    }
  }
  lState->theTypedValue = 0; // TODO remove???
  STACK_END();
}
  

// 14.9 fn:root
//---------------------
Item_t FnRootIterator::nextImpl(PlanState& planState) const
{
  Item_t contextNode;
  Item_t parentNode;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  contextNode = consumeNext(theChildren[0].getp(), planState);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0004,
         &loc, DONT_CONTINUE_EXECUTION, "The argument of the fn:root function is not a node");
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

// 14.9 fn:node-name
//---------------------
Item_t FnNodeNameIterator::nextImpl(PlanState& planState) const
{
  Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode == NULL) {
    return NULL;
  }

  if (!inNode->isNode()) {
    ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0004,
         &loc, DONT_CONTINUE_EXECUTION, "The argument of the fn:node-name function is not a node");
  }
  
  STACK_PUSH(inNode->getNodeName(), state);
  STACK_END();
}


// 2.3 fn:string
//---------------------
Item_t FnStringIterator::nextImpl(PlanState& planState) const
{
  Item_t inVal;
  xqpStringStore_t empty;

  FnStringIteratorState *state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while((inVal = consumeNext(theChildren[0].getp(), planState)) != NULL) {
    state->hasOutput = true;
    STACK_PUSH(Zorba::getItemFactory()->createString(inVal->getStringValue().getStore()), state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) {
    state->hasOutput = true;
    empty = new xqpStringStore("");
    STACK_PUSH(Zorba::getItemFactory()->createString(empty), state);
  }

  STACK_END();
}

} /* namespace xqp */
/* vim:set ts=2 sw=2: */
