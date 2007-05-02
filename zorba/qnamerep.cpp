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
#include "runtime/singleton_iterators.h"
#include "util/hashfun.h"

using namespace std;
namespace xqp {
  
qnamerep::qnamerep(
	itemid_t uri_id,
	const string& prefix, 
	const string& localname)
:
	theURIID(uri_id),
	theName(prefix+':'+localname)
{
}

qnamerep::qnamerep(
	itemid_t uri_id,
	const string& name)
:
	theURIID(uri_id),
	theName(name)
{
}

qnamekey_t qnamerep::qnamekey() const
{
	return hashfun::h64(prefix(),hashfun::h64(localname(),theURIID));
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

itemid_t qnamerep::uri_id() const
{
  return theURIID;
}

ostream& qnamerep::put(
	zorba* zorp,
	ostream& os) const
{
	os << '[' << uri_id() << ']' << prefix() << ':' << localname();
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
	item_iterator* it_p = new string_singleton(stringValue(oss.str()));
	return it_p;
}

string qnamerep::str(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}


} /* namespace xqp */
