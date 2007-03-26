
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
	itemstore& istore,
	itemref_t uriref,
	const string& qname)
:
	atomic_value(xs_qname,0),
	m_uriref(uriref)
{
	xs_stringValue* s_p = new(istore) xs_stringValue(istore,qname);
  m_length = sizeof(qname_value)/4 + s_p->length();
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

nodeid_t qname_value::id(itemstore& istore) const
{
	return hashfun::h32(uri(istore),hashfun::h32(prefix(),hashfun::h32(localname())));
}

string qname_value::prefix() const
{
	xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	string name = s_p->str();
	string::size_type n = name.find(':');
  return name.substr(0,n);
}

string qname_value::localname() const
{
  xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	string name = s_p->str();
	string::size_type n = name.find(':');
  return name.substr(n+1);
}

string qname_value::uri(
	itemstore& istore) const
{
	xs_stringValue* s_p = new(istore,m_uriref) xs_stringValue();
	return s_p->str();
}

ostream& qname_value::put(ostream& os) const
{
	xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	return s_p->put(os);
}

string qname_value::describe() const
{
  xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	ostringstream oss;
	oss << "xs_qname(" << s_p->str() << ')';
	return oss.str();
}

rchandle<abstract_iterator> qname_value::atomized_value() const
{ return NULL; }

rchandle<abstract_iterator> qname_value::effective_boolean_value() const
{ return NULL; }

string qname_value::string_value() const
{
  xs_stringValue* s_p = new((void*)rest) xs_stringValue();
	return s_p->str();
}


} /* namespace xqp */
