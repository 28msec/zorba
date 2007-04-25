/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_iterator.h"
#include "dom_values.h"
#include "dom_primitive_values.h"

#include "../context/context.h"
#include "../util/Assert.h"
#include "../util/xqp_exception.h"

#include <iostream>
#include <sstream>

using namespace std;
namespace xqp {


/*..........................................
 : dom_iterator base                       :
 :.........................................*/

dom_iterator& dom_iterator::operator=(
	const dom_iterator& it)
{
	return *this;
}

dom_iterator& dom_iterator::operator++()
{
	next();
	return *this;
}

string dom_iterator::string_value()
{
	ostringstream oss;
	while (!done()) {
		dom_item* i_p = reinterpret_cast<dom_item*>(next());
		if (i_p==NULL) continue;
		i_p->put(oss);
	}
	return oss.str();
}


/*..........................................
 : singleton iterator                      :
 :.........................................*/

dom_singleton_iterator::dom_singleton_iterator(
	dom_item* _i_p)
:
	i_p(_i_p),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(dom_item*)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	const string& s)
:
	i_p(new dom_stringValue(s)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(dom_item*)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	const dom_singleton_iterator& it)
:
	i_p(it.i_p),
	done_b(it.done_b)
{
}

dom_singleton_iterator& dom_singleton_iterator::operator=(
	const dom_singleton_iterator& it)
{
	i_p = it.i_p;
	done_b = it.done_b;
	return *this;
}


}	/* namespace xqp */

