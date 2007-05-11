/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: signature.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#include "signature.h"

#include "context/common.h"
#include "types/sequence_type.h"
#include "util/fxhashmap.h"

using namespace std;
namespace xqp {

fxhashmap<signature const*> signature::sigmap;

signature::signature(
	const qname* _qname_p,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	argv.push_back(return_type);
}

signature::signature(
	const qname* _qname_p,
	sequence_type_t arg1,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
}

signature::signature(
	const qname* _qname_p,
	sequence_type_t arg1,
	sequence_type_t arg2,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
}

signature::signature(
	const qname* _qname_p,
	sequence_type_t arg1,
	sequence_type_t arg2,
	sequence_type_t arg3,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
	argv.push_back(arg3);
}

signature::signature(
	const qname* _qname_p,
	sequence_type_t arg1,
	sequence_type_t arg2,
	sequence_type_t arg3,
	sequence_type_t arg4,
	sequence_type_t return_type)
:
	qname_p(_qname_p)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
	argv.push_back(arg3);
	argv.push_back(arg4);
}

signature::signature(
	const qname* _qname_p,
	const vector<sequence_type_t>& _argv)
:
	qname_p(_qname_p),
	argv(_argv)
{
}

signature::~signature()
{
}

void signature::set_return_type(
	sequence_type_t t)
{
	if (argv.size()>0) argv[0] = t; else argv.push_back(t);
}


} /* namespace xqp */

