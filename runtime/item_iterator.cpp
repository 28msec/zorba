/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "../values/xs_primitive_values.h"

namespace xqp {


////////////////////////////////
//	binary_iterator
////////////////////////////////

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



////////////////////////////////
//	singleton_iterator
////////////////////////////////

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
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	item * _i_p)
:
	item_iterator(ctx),
	i_h(_i_p),
	done_b(false)
{
}

singleton_iterator::singleton_iterator(
	context const& ctx,
	string const& s)
:
	item_iterator(ctx),
	i_h(new xs_string_value(s)),
	done_b(false)
{
}

singleton_iterator::~singleton_iterator()
{
}


}	/* namespace xqp */

