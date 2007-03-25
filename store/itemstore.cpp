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
#include "../values/qname_value.h"
#include "../values/nodes.h"

#include <iostream>

using namespace std;
namespace xqp {




/*______________________________________________________________________
|  
|  QName cache
|_______________________________________________________________________*/


qname_cache::qname_cache(
	const string& _datapath)
:
	qname_map( _datapath+"/qncache_",  0.6f, 1<<16),
	uri_map(   _datapath+"/uricache_", 0.6f, 1<<16)
{
}

qname_cache::qname_cache()
:
	qname_map( 0.6f, 1<<16),
	uri_map(   0.6f, 1<<16)
{
}


// URIs by key

bool qname_cache::put_uri(
	const string& prefix,
	nodeid_t uri)
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.put(pkey, uri);
}

bool qname_cache::contains_uri(
	const string& prefix) const
{
	uint32_t index;
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.find(pkey, index);
}

bool qname_cache::get_uri(
	const string& prefix,
	nodeid_t& uri) const
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.get(pkey, uri);
}



// qnames by value

bool qname_cache::put(
	const string& prefix,
	const string& localname,
	nodeid_t qname)
{
	uint64_t ukey = hashfun::h64(prefix);
	qnamekey_t qnkey = hashfun::h64(localname.c_str(),ukey);
	return qname_map.put(qnkey, qname);
}

bool qname_cache::get(
	const string& prefix,
	const string& localname,
	nodeid_t& qname) const
{
	uint64_t ukey = hashfun::h64(prefix);
	qnamekey_t qkey = hashfun::h64(localname.c_str(),ukey);
	return qname_map.get(qkey, qname);
}





/*______________________________________________________________________
|  
|  nodeid index
|_______________________________________________________________________*/


// persistent index
nodeid_index::nodeid_index(const string& path)
: nodeid_map(path+"/nodeid_", 0.6f, 1<<16)
{ }

// transient index
nodeid_index::nodeid_index()
: nodeid_map(0.6f, 1<<16)
{ }


// noderefs by nodeid
inline bool nodeid_index::put(nodeid_t id, itemref_t ref)
{ return nodeid_map.put(id, ref); }

inline bool nodeid_index::get(nodeid_t id, itemref_t& ref) const
{ return nodeid_map.get(id, ref); }








/*______________________________________________________________________
|  
|  32bit-aligned, depth-first, inline XML encoding.
|_______________________________________________________________________*/


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
	qname_value* qname_p;
	itemref_t qnameref;
	if (!qncache.get(prefix,localname,qnameref)) {
		itemref_t uriref;
		if (!qncache.get_uri(prefix, uriref)) {
			errors::err(errors::XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND);
		}
		qnameref = eos();
		qname_p = new(*this) qname_value(*this,uriref,localname);
		qncache.put(prefix,localname,qnameref);
	}
	else {
		qname_p = new(*this,qnameref) qname_value();
	}

	return qnamepair(qname_p->id(*this),qnameref);
}


// nodeid index

inline bool itemstore::get_itemref(
	nodeid_t id, 
	itemref_t& ref) const
{
	return nidindex.get(id, ref);
}

inline bool itemstore::put_itemref(
	nodeid_t id,
	itemref_t ref)
{
	return nidindex.put(id, ref);
}



} /* namespace xqp */

