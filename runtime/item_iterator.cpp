/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "util/Assert.h"
#include "errors/Error.h"
#include "values/item.h"
#include "runtime/zorba.h"
#include "exprtree/expr.h"

using namespace std;
namespace xqp {

int32_t iteratorTreeDepth = -1;



Item_t MapIterator::nextImpl() {
	Item_t item;
	vector<var_iter_t>::const_iterator itv;

	STACK_INIT();
	
	while (true) {
		item = this->consumeNext(this->theInput);
		itv = varv.begin();
		for (; itv!=varv.end(); ++itv) {
			(*itv)->bind(item);
		}
		
		item = this->consumeNext(this->theExpr);
		while (item != NULL) {
			STACK_PUSH(item);
			item = this->consumeNext(this->theExpr);
		}
		
		this->resetChild(this->theExpr);
	}
	
	STACK_END();
}

void MapIterator::resetImpl() {
	this->resetChild(this->theInput);
	this->resetChild(this->theExpr);
}

void MapIterator::releaseResourcesImpl() {
	this->releaseChildResources(this->theInput);
	this->releaseChildResources(this->theExpr);
}

std::ostream& MapIterator::_show(std::ostream& os)
const
{
	theInput->show(os);
	theExpr->show(os);
	return os;
} 

} /* namespace xqp */

