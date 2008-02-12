/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "runtime/accessors/AccessorsImpl.h"
#include "util/Assert.h"

namespace xqp {

// 2.4 fn:data
//---------------------
Item_t
FnDataIterator::nextImpl(PlanState& planState)
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
Item_t FnRootIterator::nextImpl(PlanState& planState)
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
Item_t FnNodeNameIterator::nextImpl(PlanState& planState)
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
Item_t FnStringIterator::nextImpl(PlanState& planState)
{
  Item_t inVal;

  FnStringIteratorState *state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while((inVal = consumeNext(theChild.getp(), planState)) != NULL) {
    state->hasOutput = true;
    STACK_PUSH(Zorba::getItemFactory()->createString(inVal->getStringValue()), state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) {
    state->hasOutput = true;
    STACK_PUSH(Zorba::getItemFactory()->createString(""), state);
  }

  STACK_END();
}

} /* namespace xqp */
/* vim:set ts=2 sw=2: */
