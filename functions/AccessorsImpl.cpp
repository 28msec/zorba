/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "AccessorsImpl.h"

namespace xqp {

Item_t
FnDataIterator::nextImpl()
{
  Item_t item;
  Iterator_t iter;
		
  STACK_INIT();
  while (true) {
    item = this->consumeNext( this->argument );
    if (item == NULL)
      break;
    this->curTypedValue = item->getTypedValue();
			
    while (true) {
      item = this->consumeNext( this->curTypedValue );
      if (item == NULL)
        break;
      STACK_PUSH( item );
    }
  }
  STACK_END();
}
	
void
FnDataIterator::resetImpl()
{
  this->resetChild( this->argument );
}
	
void
FnDataIterator::releaseResourcesImpl()
{
  this->releaseChildResources( this->argument );
}


Item_t FnRootIterator::nextImpl()
{
  Item_t contextNode;
  Item_t parentNode;

  STACK_INIT();

  contextNode = consumeNext(theInput);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZorbaErrorAlerts::error_alert(
         error_messages::XPTY0004_STATIC_TYPE_ERROR,
         error_messages::RUNTIME_ERROR,
         NULL,
         false,
         "Unknown name test kind");
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


void FnRootIterator::resetImpl()
{
  resetChild(theInput);
}

	
void FnRootIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
}


std::ostream& FnRootIterator::_show(std::ostream& os)	const
{
  theInput->show(os);
  return os;
}


} /* namespace xqp */
