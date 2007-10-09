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
FnDataIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t item;
  Iterator_t iter;
		
  STACK_INIT();
  while (true) {
    item = this->consumeNext( this->argument, stateBlock );
    if (item == NULL)
      break;
    this->curTypedValue = item->getTypedValue();
			
    while (true) {
      item = this->consumeNext( this->curTypedValue, stateBlock );
      if (item == NULL)
        break;
      STACK_PUSH( item );
    }
  }
  STACK_END();
}
	
void
FnDataIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  this->resetChild( this->argument, stateBlock );
}
	
void
FnDataIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  this->releaseChildResources( this->argument, stateBlock );
}


Item_t FnRootIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t contextNode;
  Item_t parentNode;

  STACK_INIT();

  contextNode = consumeNext(theInput, stateBlock);

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


void FnRootIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  resetChild(theInput, stateBlock);
}

	
void FnRootIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  releaseChildResources(theInput, stateBlock);
}


std::ostream& FnRootIterator::_show(std::ostream& os)	const
{
  theInput->show(os);
  return os;
}


} /* namespace xqp */
