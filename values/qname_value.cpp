
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_value.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "qname_value.h"

#include "values.h"
#include "xs_primitive_values.h"
#include "../store/itemstore.h"
#include "../util/hashfun.h"

using namespace std;
namespace xqp {
  
  
qname_value::qname_value(
	const string& uri,
	const string& prefix, 
	const string& localname)
:
	atomic_value(xs_qname,0)
{
	xs_stringValue* s_p = new(rest) xs_stringValue(prefix+':'+localname+':'+uri);
	uint32_t n = s_p->length();
  m_length = sizeof(qname_value)/4 + n;
}

inline void* qname_value::operator new(
	size_t n,
	itemstore& istore,
	itemref_t offset)
{
	return &istore[offset];
}

inline void* qname_value::operator new(
	size_t n,
	itemstore& istore)
{
	return istore.alloc(n);
}

qnamekey_t qname_value::qnamekey() const
{
	return hashfun::h64(uri(),hashfun::h64(prefix(),hashfun::h64(localname())));
}

string qname_value::prefix() const
{
	xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	string qname = s_p->str();
	string::size_type n = qname.find(':');
  return qname.substr(0,n);
}

string qname_value::localname() const
{
  xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	string qname = s_p->str();
	string::size_type n = qname.find(':');
	string::size_type m = qname.find(':',n+1);
  return qname.substr(n+1,(m-n-1));
}

string qname_value::uri() const
{
  xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	string qname = s_p->str();
	string::size_type n = qname.find(':');
	string::size_type m = qname.find(':',n+1);
  return qname.substr(m+1);
}

ostream& qname_value::put(ostream& os) const
{
	os << '[' << uri() << ']' << prefix() << ':' << localname();
	return os;
}

string qname_value::describe() const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(oss) << ')';
	return oss.str();
}

rchandle<abstract_iterator> qname_value::atomized_value() const
{ return NULL; }

rchandle<abstract_iterator> qname_value::effective_boolean_value() const
{ return NULL; }

string qname_value::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}


} /* namespace xqp */
