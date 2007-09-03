/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: itemstore.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "itemstore.h"

#include "context/common.h"
#include "errors/errors.h"
#include "types/sequence_type.h"
#include "util/hashfun.h"
#include "util/tracer.h"
#include "values/qname.h"
#include "values/nodes.h"
#include "values/primitive_values.h"
#include "zorba/qnamerep.h"
#include "errors/Error.h"

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
	qname_map(_datapath+"/qncache_",  0.6f, 1<<16),
	uri_map(  _datapath+"/uricache_", 0.6f, 1<<16)
{
}

qname_cache::qname_cache()
:
	qname_map(0.6f, 1<<16),
	uri_map(  0.6f, 1<<16)
{
}


// URIs by key
// -----------
bool qname_cache::put_uri_id(
	const string& prefix,
	itemid_t uri_id)
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.put(pkey, uri_id);
}

bool qname_cache::get_uri_id(
	const string& prefix,
	itemid_t& uri_id) const
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.get(pkey, uri_id);
}

bool qname_cache::put_uri(
	itemid_t uri_id, const stringValue& rep)
{
	while (uriv.capacity() <= uri_id) uriv.expand();
	uriv[uri_id] = rep;
	return true;
}

bool qname_cache::get_uri(
	itemid_t uri_id, stringValue& rep)

{
	if (uri_id < uriv.size()) return false;
	rep = uriv[uri_id];
	return true;
}


// qnames by value
// ---------------
bool qname_cache::put_qname_id(
	itemid_t uri_id,
	const string& localname,
	itemid_t qname_id)
{
	qnamekey_t qnkey = hashfun::h64(localname,uri_id);
	return qname_map.put(qnkey, qname_id);
}

bool qname_cache::get_qname_id(
	itemid_t uri_id,
	const string& localname,
	itemid_t& qname_id) const
{
	qnamekey_t qkey = hashfun::h64(localname,uri_id);
	return qname_map.get(qkey, qname_id);
}

bool qname_cache::put_qname(
	itemid_t qname_id,
	const qnamerep& rep)
{
	while (qnamev.capacity() <= qname_id) qnamev.expand();
	qnamev[qname_id] = rep;
	return true;
}

bool qname_cache::get_qname(
	itemid_t qname_id,
	qnamerep& rep)
{
	if (qname_id < qnamev.size()) return false;
	rep = qnamev[qname_id];
	return true;
}

itemid_t qname_cache::add_qname(
	const qnamerep& rep)
{
	itemid_t id(qnamev.size());
	qnamev.push_back(rep);
	return id;
}



// transient store
// ---------------

itemstore::itemstore(
	uint32_t initial_size)
:
	store(),
	index(0.6f, initial_size),
	qncache()
{
}


// persistent store
// ----------------
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



// data manager interface
// ----------------------
Iterator_t itemstore::document(
	const string& uri)
{
	return NULL;
}

bool itemstore::add_document(
	const string& uri,
	const document_node& dn)
{
	return false;
}

bool itemstore::remove_document(
	const string& uri)
{
	return false;
}

Iterator_t itemstore::collection(
	const string& uri)
{
	return NULL;
}

bool itemstore::add_collection(
	const string& uri,
	Iterator_t it)
{
	return false;
}

bool itemstore::remove_collection(
	const string& uri)
{
	return false;
}

bool itemstore::append_to_collection(
	const string& uri,
	Iterator_t it)
{
	return false;
}

void itemstore::apply(
	const update_value* vap_p)
{
	return;
}

const node* itemstore::get_node(itemid_t id) const
{
	return NULL;
}

const xs_stringValue* itemstore::get_uri(itemid_t  id) const
{
	return NULL;
}

const qname* itemstore::get_qname(itemid_t  id) const
{
	return NULL;
}



// text
// ----
off_t itemstore::add_text(
	const string& content)
{
	uint32_t sz = store.size();
	store.raw_copy(content.c_str(), content.length());
	return sz;
}

string itemstore::get_text(
	off_t ref,
	uint32_t length) const
{
	return string((char*)&store[ref],0,length);
}


// keys
// ----
off_t itemstore::add_key(
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
// ------
qnamerep& itemstore::add_qname(
	const string& qn)
{
	string prefix = NONS_PREFIX;
	string localname = qn;

	string::size_type n = qn.find(':');
	if (n!=string::npos) {
		prefix = qn.substr(0,n);
		localname = qn.substr(n+1);
	}

	itemid_t qname_id;
	itemid_t uri_id;

	if (!qncache.get_uri_id(prefix, uri_id)) {
		//daniel errors::err(errors::XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND);
		ZorbaErrorAlerts::error_alert(error_messages::XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, 
																	error_messages::RUNTIME_ERROR,
																	NULL//get the location from current iterator saved in zorba object
																	);
	}
	if (!qncache.get_qname_id(uri_id, localname, qname_id)) {
		qname_id = qncache.add_qname(qnamerep(/*uri_id*/"xxx", prefix, localname));
	}
	
	return qncache[qname_id];
}


// runtime services
// ----------------
uint32_t itemstore::next_docid()
{
	return (++counters[docid_counter]);
}

uint32_t itemstore::next_itemid()
{
	return (++counters[itemid_counter]);
}

uint32_t itemstore::gen()
{
	return (counters[gen_counter]);
}

uint32_t itemstore::next_gen()
{
	return (++counters[gen_counter]);
}



} /* namespace xqp */

