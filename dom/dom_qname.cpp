/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_qname.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_qname.h"
#include "../util/hashfun.h"
#include <string>

using namespace std;
namespace xqp {
  

// dom_qname
// ---------

dom_qname::dom_qname(
	const string& uri,
	const string& prefix,
	const string& localname)
:
	the_uri(uri),
	the_prefix(prefix),
	the_localname(localname)
{}

dom_qname::dom_qname(
	const dom_qname& qn)
:
	the_uri(qn.the_uri),
	the_prefix(qn.the_prefix),
	the_localname(qn.the_localname)
{}

qnamekey_t dom_qname::hashkey(
	const string& uri,
	const string& prefix,
	const string& localname)
{
	return hashfun::h64(uri,hashfun::h64(prefix,hashfun::h64(localname)));
}

qnamekey_t dom_qname::nodeid() const
{
	return dom_qname::hashkey(the_uri,the_prefix,the_localname);
}

ostream& dom_qname::put(ostream& os) const
{
  if (the_uri!="http://nonamespace/") {
	  return os << the_prefix << '[' << the_uri << "]:" << the_localname;
  }
  else {
    return os << the_localname;
  }
}

string dom_qname::describe() const
{
	ostringstream oss;
	if (the_uri!="http://noname") {
	  oss << "qname(" << the_prefix << '[' << the_uri << "]:" << the_localname << ')';
  }
  else {
    oss << "qname(" << the_localname << ')';
  }
	return oss.str();
}


} /* namespace xqp */
