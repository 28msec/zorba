/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: signature.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#include "signature.h"

#include <vector>
#include <string>
#include "../context/context.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../values/qname_value.h"

 
using namespace std;
namespace xqp {

hashmap<signature const*> signature::sigmap;

signature::signature(
	qnameid _qname,
	sequence_type_t return_type)
:
	qname(_qname)
{
	arg_v.push_back(return_type);
}

signature::~signature()
{
}

rchandle<QName> signature::get_name(context * ctx_p) const
{
	return ctx_p->get_qname(qname);
}


} /* namespace xqp */

