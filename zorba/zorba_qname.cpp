
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_qname.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba_qname.h"
#include "qnamerep.h"

#include "context/common.h"
#include "runtime/singleton_iterators.h"
#include "store/itemstore.h"
#include "util/hashfun.h"
#include "values/values.h"
#include "values/xs_primitive_values.h"

using namespace std;
namespace xqp {
  
  
zorba_qname::zorba_qname(
	itemid_t uri_id,
	const string& prefix, 
	const string& localname)
{
	rep = new qnamerep(uri_id,prefix,localname);
}

qnamekey_t zorba_qname::qnamekey() const
{
	return hashfun::h64(prefix(),hashfun::h64(localname(),uri_id()));
}

string zorba_qname::prefix() const
{
	return rep->prefix();
}

string zorba_qname::localname() const
{
  return rep->localname();
}

itemid_t zorba_qname::uri_id() const
{
  return rep->uri_id();
}

ostream& zorba_qname::put(
	zorba* zorp,
	ostream& os) const
{
	os << '[' << uri() << ']' << prefix() << ':' << localname();
	return os;
}

string zorba_qname::describe(
	zorba* zorp) const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(zorp,oss) << ')';
	return oss.str();
}

string zorba_qname::str(
	zorba* zorp) const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(zorp,oss) << ')';
	return oss.str();
}

iterator_t zorba_qname::atomized_value() const
{
	return NULL;
}

iterator_t zorba_qname::effective_boolean_value() const
{
	return NULL;
}

iterator_t zorba_qname::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(describe(zorp)));
}


} /* namespace xqp */
