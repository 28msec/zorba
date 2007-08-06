
/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
#include "store/itemstore.h"
#include "util/hashfun.h"
#include "values/values.h"
#include "values/xs_primitive_values.h"

using namespace std;
namespace xqp {
  
zorba_qname::zorba_qname(
	const string& uri,
	const string& prefix, 
	const string& localname)
{
	rep = new qnamerep(uri,prefix,localname);
}

qnamekey_t zorba_qname::qnamekey() const
{
	return rep->qnamekey();
}

string zorba_qname::prefix() const
{
	return rep->prefix();
}

string zorba_qname::localname() const
{
  return rep->localname();
}

string zorba_qname::uri() const
{
  return rep->uri();
}

ostream& zorba_qname::put(
	ostream& os) const
{
	os << '[' << uri() << ']' << prefix() << ':' << localname();
	return os;
}

string zorba_qname::describe() const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(oss) << ')';
	return oss.str();
}

string zorba_qname::str() const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(oss) << ')';
	return oss.str();
}

iterator_t zorba_qname::atomized_value(
	yy::location &loc) const
{
	return NULL;
}

iterator_t zorba_qname::effective_boolean_value(
	yy::location &loc) const
{
	return NULL;
}

iterator_t zorba_qname::string_value(
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(describe()));
}


} /* namespace xqp */
