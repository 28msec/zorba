/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
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
		
  STACK_INIT();
  while (true) {
    item = this->consumeNext( this->argument, planState );
    if (item == NULL)
      break;
    this->curTypedValue = item->getTypedValue();
			
    while (true) {
      item = this->consumeNext( this->curTypedValue, planState );
      if (item == NULL)
        break;
      STACK_PUSH( item );
    }
  }
  STACK_END();
}
	
void
FnDataIterator::resetImpl(PlanState& planState)
{
  this->resetChild( this->argument, planState );
}
	
void
FnDataIterator::releaseResourcesImpl(PlanState& planState)
{
  this->releaseChildResources( this->argument, planState );
}


Item_t FnRootIterator::nextImpl(PlanState& planState)
{
  Item_t contextNode;
  Item_t parentNode;

  STACK_INIT();

  contextNode = consumeNext(theInput, planState);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZorbaErrorAlerts::error_alert(
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

  STACK_PUSH(contextNode);
  STACK_END();
}


void FnRootIterator::resetImpl(PlanState& planState)
{
  resetChild(theInput, planState);
}

	
void FnRootIterator::releaseResourcesImpl(PlanState& planState)
{
  releaseChildResources(theInput, planState);
}


std::ostream& FnRootIterator::_show(std::ostream& os)	const
{
  theInput->show(os);
  return os;
}


} /* namespace xqp */
