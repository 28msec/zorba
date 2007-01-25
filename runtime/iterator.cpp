/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "iterator.h"
#include "../types/xs_primitive_types.h"
#include "../values/xs_primitive_values.h"

#include <iostream>


using namespace std;
namespace xqp {


/*...........................................
	: binary iterator                         :
	:.........................................:
*/

void binary_iterator::open()
{
	it1_h->open();
	it2_h->open();
}

void binary_iterator::close()
{
	it1_h->close();
	it2_h->close();
}

rchandle<item> binary_iterator::next()
{
	rchandle<item> i1 = it1_h->next();
	rchandle<item> i2 = it2_h->next();
	return (*op)(i1,i2);
}

bool binary_iterator::done()
{
	return it1_h->done() || it2_h->done();
}

void binary_iterator::rewind()
{
	it1_h->rewind();
	it2_h->rewind();
}

binary_iterator::binary_iterator(
	context const& ctx,
	rchandle<item_iterator> _it1_h,
	rchandle<item_iterator> _it2_h,
	rchandle<item> (*_op)(rchandle<item> const&, rchandle<item> const&))
:
	item_iterator(ctx),
	it1_h(_it1_h),
	it2_h(_it2_h),
	op(_op)
{
}

binary_iterator::~binary_iterator()
{
}



/*...........................................
	: singleton iterator                      :
	:.........................................:
*/

void singleton_iterator::open()
{
}

void singleton_iterator::close()
{
	done_b = false;
}

rchandle<item> singleton_iterator::next()
{
	if (!done_b) {
		done_b = true;
		return i_h;
	}
	else {
		return NULL;
	}
}

bool singleton_iterator::done()
{
	return done_b;
}

void singleton_iterator::rewind()
{
	done_b = false;
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	rchandle<item> _i_h)
:
	item_iterator(ctx),
	i_h(_i_h),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(rchandle<item>)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	item * _i_p)
:
	item_iterator(ctx),
	i_h(_i_p),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(item*)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	string const& s)
:
	item_iterator(ctx),
	i_h(new xs_string_value(s)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(string)\n";
#endif
}

singleton_iterator::~singleton_iterator()
{
}



singleton_iterator::singleton_iterator(
	context const& ctx,
	bool v)
:
	item_iterator(ctx),
	i_h(new xs_boolean_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(bool)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	double v)
:
	item_iterator(ctx),
	i_h(new xs_double_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(double)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	float v)
:
	item_iterator(ctx),
	i_h(new xs_float_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(float)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	int v)
:
	item_iterator(ctx),
	i_h(new xs_int_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(int)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	long long v)
:
	item_iterator(ctx),
	i_h(new xs_long_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(long long)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	short v)
:
	item_iterator(ctx),
	i_h(new xs_short_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(short)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	signed char v)
:
	item_iterator(ctx),
	i_h(new xs_byte_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(signed char)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	unsigned char v)
:
	item_iterator(ctx),
	i_h(new xs_unsignedByte_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(unsigned char)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	unsigned int v)
:
	item_iterator(ctx),
	i_h(new xs_unsignedInt_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(signed int)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	unsigned long long v)
:
	item_iterator(ctx),
	i_h(new xs_nonNegativeInteger_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(unsigned long long)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	unsigned short v)
:
	item_iterator(ctx),
	i_h(new xs_unsignedShort_value(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(unsigned short)\n";
#endif
}


/*...........................................
	: concat iterator                         :
	:.........................................:
*/

void concat_iterator::open()
{
}

void concat_iterator::close()
{
}

rchandle<item> concat_iterator::next()
{
	while (currit_h->done() && ++walker!=sentinel) {
		currit_h = *walker;
	}
	if (done()) return NULL;
	return currit_h->next();
}

bool concat_iterator::done()
{
	return walker==sentinel;
}

void concat_iterator::rewind()
{
	walker = it_list.begin();
	for (; walker!=sentinel; ++walker) {
		(*walker)->rewind();
	}
}

concat_iterator::concat_iterator(
	context const& ctx,
	list<rchandle<item_iterator> > _it_list)
:
	item_iterator(ctx),
	it_list(_it_list),
	walker(_it_list.begin()),
	sentinel(_it_list.end())
{
	currit_h = *walker;
	while (currit_h->done() && ++walker!=sentinel) {
		currit_h = *walker;
	}
}

concat_iterator::~concat_iterator()
{
}



}	/* namespace xqp */


