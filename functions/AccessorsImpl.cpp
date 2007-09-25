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
		STACK_PUSH( NULL );
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
} /* namespace xqp */
