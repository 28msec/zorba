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
	uint64_t _namespace_hash)
:
	type(_type),
	prefix(_prefix),
	name(_name),
	namespace_hash(_namespace_hash)
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
	namespace_hash(0)
{ 
}

QName::QName(
	enum qname_type_t _type,
	string const& _name)
:
	type(_type),
	prefix(""),
	name(_name),
	namespace_hash(0)
{
}

QName::QName(
	enum qname_type_t _type)
:
	type(_type),
	prefix(""),
	name(""),
	namespace_hash(0)
{
}

QName::~QName()
{
}

item_iterator QName::atomized_value(
	context const& ctx) const
{
	return item_iterator(ctx);
}

item_iterator QName::effective_boolean_value(
	context const& ctx) const
{
	return item_iterator(ctx);
}



}	/* namespace xqp*/

