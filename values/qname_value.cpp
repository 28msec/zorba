/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_value.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Authors: John Cowan, Paul Pedersen
 *
 */

#include "qname_value.h"

#include "../context/common.h"
#include "../util/hashfun.h"
#include <ostream>
#include <string>

using namespace std;
namespace xqp {

QName::QName(
	string const& _prefix,
	string const& _name,
	nsid _ns_id)
:
	prefix(_prefix),
	name(_name),
	ns_id(_ns_id)
{ 
}

QName::QName(
	string const& qname)
:
	prefix(""),
	name(qname),
	ns_id(0)
{
	size_t n = qname.find(':');
	if (n!=string::npos) {
		prefix = qname.substr(0,n);
		name = qname.substr(n+1);
	}
}

QName::QName(
	QName const& qn)
:
	prefix(qn.prefix),
	name(qn.name),
	ns_id(qn.ns_id)
{
}

QName::QName()
:
	prefix(""),
	name(""),
	ns_id(0)
{
}

QName::~QName()
{
}

rchandle<item_iterator> QName::atomized_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

rchandle<item_iterator> QName::effective_boolean_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

uint32_t QName::hash32(
	context * ctx_p) const
{
	string uri,name;
	if (!ctx_p->namespace_uri(ns_id,uri)) {
		throw(xqp_exception("failed to find namespace URI");
	}
	if (!ctx_p->namespace_uri(ns_id,uri)) {
		throw(xqp_exception("failed to find namespace URI");
	}
	return hashfun::h32(
}

uint64_t QName::hash64(
	context * ctx_p) const
{
}

}	/* namespace xqp*/

