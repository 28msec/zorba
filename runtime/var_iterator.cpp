/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: var_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "var_iterator.h"

using namespace std;
namespace xqp {

void var_iterator::open()
{
}

void var_iterator::close()
{
}

rchandle<item> var_iterator::next()
{
	return NULL;
}

bool var_iterator::done()
{
	return true;
}

void var_iterator::rewind()
{
}

var_iterator::var_iterator(
	context const& ctx,
	rchandle<QName> _varname_h)
:
	item_iterator(ctx),
	varname_h(_varname_h)
{
}

var_iterator::~var_iterator()
{
}


}	/* namespace xqp */
