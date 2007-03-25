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

#include "../context/context.h"
#include "../util/Assert.h"
#include "../util/xqp_exception.h"
#include "../values/xs_primitive_values.h"

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
	abstract_item* _i_p)
:
	i_p(_i_p),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(item*)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	const string& s)
:
	i_p(new(s.length()) xs_stringValue(s)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(string)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	bool v)
:
	i_p(new xs_booleanValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(bool)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	double v)
:
	i_p(new xs_doubleValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(double)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	int v)
:
	i_p(new xs_intValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(int)\n";
#endif
}

dom_singleton_iterator::dom_singleton_iterator(
	long v)
:
	i_p(new xs_longValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "dom_singleton_iterator(long)\n";
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

