/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_value.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "qname_value.h"

#include <ostream>
#include <string>

using namespace std;
namespace xqp {

QName::QName(
	enum qname_type_t _type,
	string const& _prefix,
	string const& _name,
	uint32_t _ns_id)
:
	type(_type),
	prefix(_prefix),
	name(_name),
	ns_id(_ns_id)
{ 
}

QName::QName(
	enum qname_type_t _type,
	string const& _prefix,
	string const& _name)
:
	type(_type),
	prefix(_prefix),
	name(_name),
	ns_id(0)
{ 
}

QName::QName(
	enum qname_type_t _type,
	string const& qname)
:
	type(_type),
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
	enum qname_type_t _type)
:
	type(_type),
	prefix(""),
	name(""),
	ns_id(0)
{
}

QName::QName(
	QName const& qn)
:
	type(qn.type),
	prefix(qn.prefix),
	name(qn.name),
	ns_id(qn.ns_id)
{
}

QName::QName()
:
	type(qn_none),
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



}	/* namespace xqp*/

