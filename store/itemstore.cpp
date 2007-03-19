/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: itemstore.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "itemstore.h"

#include "../context/common.h"
#include "../runtime/errors.h"
#include "../types/sequence_type.h"
#include "../util/hashfun.h"
#include "../util/tracer.h"
#include "../values/nodes.h"

#include <iostream>

/*______________________________________________________________________
|  
|  32bit-aligned, depth-first, inline XML encoding.
|_______________________________________________________________________*/

using namespace std;
namespace xqp {


// transient store

itemstore::itemstore(
	uint32_t initial_size)
:
	store(),
	index(0.6f, initial_size),
	qncache()
{
}


// persistent store

itemstore::itemstore(
	string const& datapath,
	uint32_t initial_size)
:
	store( datapath+"/store" ),
	index( datapath+"/idx_", 0.6f, initial_size ),
	qncache( datapath )
{
}
 
itemstore::~itemstore() { }


// text

itemref_t itemstore::add_text(
	const string& content)
{
	uint32_t sz = store.size();
	store.raw_copy(content.c_str(), content.length());
	return sz;
}

string itemstore::get_text(
	itemref_t ref,
	uint32_t length) const
{
	return string((char*)&store[ref],0,length);
}


// keys

itemref_t itemstore::add_key(
	uint64_t key)
{
	uint32_t sz = store.size();
	store.push_back(key>>32);
	store.push_back(key&0xffffffff);
	return sz;
}

void* itemstore::last()
{
	return static_cast<void*>(&store[store.size()]);
}


// qnames

qnamepair_t itemstore::add_qname(
	const string& qname)
{
	string prefix = NON_PREFIX;
	string localname = qname;

	string::size_type n = qname.find(':');
	if (n!=string::npos) {
		prefix = qname.substr(0,n);
		localname = qname.substr(n+1);
	}
	itemref_t qnameref;
	if (!qncache.get(prefix,localname,qnameref)) {
		itemref_t uriref;
		if (!qncache.get_uri(prefix, uriref)) {
			errors::err(errors::XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND);
		}
		qnameref = eos();
		new(*this) qname_value(*this,uriref,localname);
		qncache.put(prefix,localname,qnameref);
	}
	return qnameref;
}


// nodeid index

inline bool itemstore::get_itemref(
	nodeid_t id, 
	itemref_t& ref) const
{
	return nodeid_index.get(id, ref);
}

inline bool itemstore::put_itemref(
	nodeid_t id,
	itemref_t ref)
{
	return nodeid_index.put(id, ref);
}



} /* namespace xqp */

