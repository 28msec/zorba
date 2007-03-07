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

void library::put(
	function const& func)
{
	funtab.put(func.get_qname()->stringValue(), func);
}

function* library::get(
	qname_value const* qname_p)
{
	return NULL;
}

} /* namespace xqp */

