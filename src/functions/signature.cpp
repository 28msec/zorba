/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: signature.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#include "signature.h"

#include "context/common.h"
#include "util/fx/fxhashmap.h"

using namespace std;
namespace xqp {

  signature::signature (QNameItem_t name, TypeSystem::xqtref_t arg1,
                        bool variadic, TypeSystem::xqtref_t return_type)
    : signature_base (variadic),
      qname_p(name)
  {
    argv.push_back(return_type);
    argv.push_back(arg1);
  }

signature::signature(
	QNameItem_t name,
	TypeSystem::xqtref_t return_type)
:
	qname_p(name)
{
	argv.push_back(return_type);
}

signature::signature(
  QNameItem_t name,
	TypeSystem::xqtref_t arg1,
	TypeSystem::xqtref_t return_type)
:
	qname_p(name)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
}

signature::signature(
  QNameItem_t name,
	TypeSystem::xqtref_t arg1,
	TypeSystem::xqtref_t arg2,
	TypeSystem::xqtref_t return_type)
:
	qname_p(name)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
}

signature::signature(
  QNameItem_t name,
	TypeSystem::xqtref_t arg1,
	TypeSystem::xqtref_t arg2,
	TypeSystem::xqtref_t arg3,
	TypeSystem::xqtref_t return_type)
:
	qname_p(name)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
	argv.push_back(arg3);
}

signature::signature(
  QNameItem_t name,
	TypeSystem::xqtref_t arg1,
	TypeSystem::xqtref_t arg2,
	TypeSystem::xqtref_t arg3,
	TypeSystem::xqtref_t arg4,
	TypeSystem::xqtref_t return_type)
:
	qname_p(name)
{
	argv.push_back(return_type);
	argv.push_back(arg1);
	argv.push_back(arg2);
	argv.push_back(arg3);
	argv.push_back(arg4);
}

signature::signature(
  QNameItem_t name,
	const vector<TypeSystem::xqtref_t>& _argv)
:
	qname_p(name),
	argv(_argv)
{
}

signature::~signature()
{
}


} /* namespace xqp */

