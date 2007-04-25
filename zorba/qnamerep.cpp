/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qnamerep.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "qnamerep.h"
#include "context/common.h"
#include "runtime/item_iterator.h"
#include "util/hashfun.h"

using namespace std;
namespace xqp {
  
qnamerep::qnamerep(
	const string& uri,
	const string& prefix, 
	const string& localname)
:
	atomic_value(xs_qname)
{
	name = string(prefix+':'+localname+':'+uri);
}

qnamekey_t qnamerep::qnamekey() const
{
	return hashfun::h64(uri(),hashfun::h64(prefix(),hashfun::h64(localname())));
}

string qnamerep::prefix() const
{
	string::size_type n = name.find(':');
  return name.substr(0,n);
}

string qnamerep::localname() const
{
	string::size_type n = name.find(':');
	string::size_type m = name.find(':',n+1);
  return name.substr(n+1,(m-n-1));
}

string qnamerep::uri() const
{
	string::size_type n = name.find(':');
	string::size_type m = name.find(':',n+1);
  return name.substr(m+1);
}

ostream& qnamerep::put(ostream& os) const
{
	os << '[' << uri() << ']' << prefix() << ':' << localname();
	return os;
}

string qnamerep::describe() const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(oss) << ')';
	return oss.str();
}

iterator_t qnamerep::atomized_value() const
{ return NULL; }

iterator_t qnamerep::effective_boolean_value() const
{ return NULL; }

string qnamerep::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}


} /* namespace xqp */
