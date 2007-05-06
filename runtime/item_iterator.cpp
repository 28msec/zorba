/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "util/Assert.h"
#include "util/xqp_exception.h"
#include "values/values.h"
#include "values/nodes.h"
#include "values/qname.h"

using namespace std;
namespace xqp {

// node_singleton
// --------------
const item& node_singleton::next(uint32_t delta)
{
	n_p = NULL;
	throw xqp_exception("iterator overrun");
}

const item& node_singleton::peek() const
{
	Assert<null_pointer>(n_p!=NULL);
	return *n_p;
}

const item& node_singleton::operator*() const
{
	Assert<null_pointer>(n_p!=NULL);
	return *n_p;
}


// qname_singleton
// ---------------
const item& qname_singleton::next(uint32_t delta)
{
	qn_p = NULL;
	throw xqp_exception("iterator overrun");
}

const item& qname_singleton::peek() const
{
	Assert<null_pointer>(qn_p!=NULL);
	return *qn_p;
}

const item& qname_singleton::operator*() const
{
	Assert<null_pointer>(qn_p!=NULL);
	return *qn_p;
}

qname_singleton& qname_singleton::operator=(
	const qname_singleton& it)
{
	qn_p = it.qn_p;
	return *this;
}


}	/* namespace xqp */

