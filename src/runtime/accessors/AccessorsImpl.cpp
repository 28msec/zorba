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
  STACK_INIT(FnDataIteratorState, lState, planState);
  
  while (true) {
    item = this->consumeNext( theChild, planState );
    if (item == NULL)
      break;
    lState->theTypedValue = item->getTypedValue();
      
    while (true) {
      item = lState->theTypedValue->next();
      if (item == NULL)
        break;
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
  STACK_INIT(PlanIteratorState, lState, planState);

  contextNode = consumeNext(theChild, planState);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZORBA_ERROR_ALERT(
         error_messages::XPTY0004_STATIC_TYPE_ERROR,
         error_messages::RUNTIME_ERROR,
         NULL,
         false,
         "The argument of the fn:root function is not a node");
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


} /* namespace xqp */
