/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "values/values.h"
#include "values/nodes.h"

using namespace std;
namespace xqp {

const item& node_singleton::next(
	uint32_t delta = 1)
{
	done_b = true;
	return dynamic_cast<const item&>(*n_p);
}

const item& node_singleton::peek() const
{
	return dynamic_cast<const item&>(*n_p);
}

const item& node_singleton::operator*() const
{
	return dynamic_cast<const item&>(*n_p);
}



}	/* namespace xqp */

