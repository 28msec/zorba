/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: signature.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#include "signature.h"

#include "../context/common.h"
#include "../context/context.h"
#include "../util/fxhashmap.h"

using namespace std;
namespace xqp {

fxhashmap<signature const*> signature::sigmap;

signature::signature(
	qname_value const* _qname_p,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	arg_v.push_back(return_type);
}

signature::signature(
	context * ctx_p,
	string const& fname ,
	sequence_type_t return_type)
:
	qname_p(NULL)		// XXX fix this
{
	arg_v.push_back(return_type);
}

signature::~signature()
{
}


} /* namespace xqp */

