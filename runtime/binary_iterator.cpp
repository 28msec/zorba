/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: binary_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "binary_iterator.h"

namespace xqp {

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
	context *const ctx_p,
	rchandle<item_iterator> _it1_h,
	rchandle<item_iterator> _it2_h,
	rchandle<item> (*_op)(rchandle<item> const&, rchandle<item> const&))
:
	item_iterator(ctx_p),
	it1_h(_it1_h),
	it2_h(_it2_h),
	op(_op)
{
}

binary_iterator::~binary_iterator()
{
}

}	/* namespace xqp */
