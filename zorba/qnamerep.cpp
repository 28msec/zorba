/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qnamerep.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "qnamerep.h"
#include "valuereps.h"
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
	theURI(uri),
	theName(prefix+':'+localname)
{
}

qnamerep::qnamerep(
	const string& uri,
	const string& name)
:
	theURI(uri),
	theName(name)
{
}

qnamekey_t qnamerep::qnamekey() const
{
	return hashfun::h64(prefix(),hashfun::h64(localname(),hashfun::h64(uri())));
}

string qnamerep::prefix() const
{
	string::size_type n = theName.find(':');
  return theName.substr(0,n);
}

string qnamerep::localname() const
{
	string::size_type n = theName.find(':');
	string::size_type m = theName.find(':',n+1);
  return theName.substr(n+1,(m-n-1));
}

string qnamerep::uri() const
{
  return theURI;
}

ostream& qnamerep::put(
	zorba* zorp,
	ostream& os) const
{
	os << '[' << uri() << ']' << prefix() << ':' << localname();
	return os;
}

string qnamerep::describe(
	zorba* zorp) const
{
	ostringstream oss;
	oss << "xs_qname(";
	put(zorp,oss) << ')';
	return oss.str();
}

iterator_t qnamerep::atomized_value(
	zorba* zorp) const
{
	return NULL;
}

iterator_t qnamerep::effective_boolean_value(
	zorba* zorp) const
{
	return NULL;
}

iterator_t qnamerep::string_value(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return new singleton_iterator(new stringValue(oss.str()));
}

string qnamerep::str(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}


} /* namespace xqp */
