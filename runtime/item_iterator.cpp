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

int iteratorTreeDepth = -1;


void map_iterator::_open() {
	theState = outer;
	theInput->open();
}


item_t map_iterator::_next() {
	BasicIterator& input = *theInput;
	BasicIterator& expr = *theExpr;

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

std::ostream& map_iterator::_show(std::ostream& os)
const
{
	theInput->show(os);
	if (theState!=outer)
		theExpr->show(os);
	return os;
} 

bool map_iterator::done() const {
	return (theInput->done() && (theState==outer || theExpr->done()));
}

} /* namespace xqp */

