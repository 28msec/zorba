/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include  "library.h"
#include  "function.h"

using namespace std;
namespace xqp {

library::library()
{
}

library::~library()
{
}

void library::put(const function* func_p)
{
	funtab.put(func_p->get_fname()->string_value(), func_p);
}

const function* library::get(const qname_value* qname_p)
{
	const function* func_p = NULL;
	funtab.get(qname_p->string_value(), func_p);
	return func_p;
}

} /* namespace xqp */

