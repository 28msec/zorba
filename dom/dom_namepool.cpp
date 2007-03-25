/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_namepool.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 *
 */

#include "dom_namepool.h"
#include "dom_nodes.h"
#include "../util/tracer.h"
#include <iostream>

using namespace std;
namespace xqp {

dom_namepool::dom_namepool()
:
	qname_map( 0.6f, 1<<16 )
{
}


qnamekey_t dom_namepool::put_qname(	// return: qname key
	dom_qname* qname_p)								// input:  dom qname*
{
  //cout << TRACE << " : put_qname( [" << (uint32_t)(qname_p) << ']';
  qname_p->put(cout) << ") => ";
	qnamekey_t key = qname_p->nodeid();
	//cout << key << endl;
	if (qname_map.find(key)) return key;
	qname_map.put(key,qname_p);
	return key;
}

bool dom_namepool::get_qname(				// return: true <-> found
	const qnamekey_t& qnamekey,				// input:  qname key
	dom_qname*& qname_p) const				// output: dom qname*
{
  //cout << TRACE << " : get_qname(" << qnamekey << ") => ";
	dom_qname* qn_p;
	if (!qname_map.get(qnamekey,qn_p)) {
  	//cout << "[]\n";
  	return false;
	}
	//cout << '[' << (uint32_t)(qn_p) << "]\n";
	qname_p = qn_p;
	return true;
}


}	/* namespace xqp */

