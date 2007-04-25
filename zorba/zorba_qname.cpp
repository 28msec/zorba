
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
:
	atomic_value(xs_qname)
{
	rep = new qnamerep(uri,prefix,localname);
}

qnamekey_t zorba_qname::qnamekey() const
{
	return hashfun::h64(uri(),hashfun::h64(prefix(),hashfun::h64(localname())));
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

ostream& zorba_qname::put(ostream& os) const
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

iterator_t zorba_qname::atomized_value() const
{ return NULL; }

iterator_t zorba_qname::effective_boolean_value() const
{ return NULL; }

string zorba_qname::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}


} /* namespace xqp */
