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
	iuri(uri),
	iprefix(prefix),
	ilocalname(localname)
{}

dom_qname::dom_qname(
	const dom_qname& qn)
:
	iuri(qn.iuri),
	iprefix(qn.iprefix),
	ilocalname(qn.ilocalname)
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
	return dom_qname::hashkey(iuri,iprefix,ilocalname);
}

ostream& dom_qname::put(ostream& os) const
{
	return os << iprefix << '[' << iuri << "]:" << ilocalname;
}

string dom_qname::describe() const
{
	ostringstream oss;
	oss << "qname(" << iprefix << '[' << iuri << "]:" << ilocalname << ')';
	return oss.str();
}


} /* namespace xqp */
