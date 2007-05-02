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
#include "values/qname.h"

using namespace std;
namespace xqp {

// node_singleton
// --------------
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


// qname_singleton
// ---------------
const item& qname_singleton::next(uint32_t delta = 1)
{
	const qname* p = qn_p;
	qn_p = NULL;
	return dynamic_cast<const item&>(*qn_p);
}

const item& qname_singleton::peek() const
{
	return dynamic_cast<const item&>(*qn_p);
}

const item& qname_singleton::operator*() const
{
	return dynamic_cast<item&>(*qn_p);
}

qname_singleton& qname_singleton::operator=(
	const qname_singleton& it)
{
	qn_p = it.qn_p;
	return *this;
}


};

}	/* namespace xqp */

