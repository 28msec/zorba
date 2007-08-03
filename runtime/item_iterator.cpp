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
#include "values/values.h"
#include "values/nodes.h"
#include "values/qname.h"
#include "runtime/zorba.h"
#include "exprtree/expr.h"

using namespace std;
namespace xqp {

void basic_iterator::open()
{
	assert(!open_b);
	open_b = true;
	
	// Line Info for Duff's device be reset to allow resetting iterators that use Duff's device
	this->current_line = 0;
	_open();
}

void basic_iterator::close()
{
	assert(open_b);
	open_b = false;
	_close();
}

bool basic_iterator::is_open() const
{
	return open_b;
}

void map_iterator::_open() {
	theState = outer;
	theInput->open();
}


item_t map_iterator::_next() {
	basic_iterator& input = *theInput;
	basic_iterator& expr = *theExpr;

	while (true) {
		if (theState==outer) {
			item_t i_h = input.next();
			vector<var_iter_t>::const_iterator itv = varv.begin();
			for (; itv!=varv.end(); ++itv) {
				(*itv)->bind(i_h);
			}
			expr.open();
			theState = inner;
		} 
		if (!expr.done()) {
			return expr.next();
		}
		expr.close();
		theState = outer;
	}
}

void map_iterator::_close() {
	theInput->close();
	if (theState!=outer)
		theExpr->close();
}

bool map_iterator::done() const {
	return (theInput->done() && (theState==outer || theExpr->done()));
}

} /* namespace xqp */

