/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: itemstore.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "itemstore.h"
#include "../types/sequence_type.h"

/*______________________________________________________________________
|  
|  32bit-aligned, depth-first, inline XML encoding.
|_______________________________________________________________________*/

using namespace std;
namespace xqp {

itemstore::itemstore(
	uint32_t initial_size)
:
	store(),
	index(0.6f, initial_size),
	qncache()
{
}

itemstore::itemstore(
	string const& datapath,
	uint32_t initial_size)
:
	store( datapath+"/store_" ),
	index( datapath+"/idx_", 0.6f, initial_size ),
	qncache( datapath )
{
}
 
itemstore::~itemstore()
{
}

inline bool itemstore::check_words(uint32_t n)
{
	return (store.size() + n >= store.capacity());
}

inline void itemstore::assure_words(uint32_t n)
{
	while (store.size() + n >= store.capacity()) store.expand();
}

inline void * itemstore::alloc(size_t n)
{
	return store.alloc(n);
}

itemref_t itemstore::add_text(
	std::string const& content)
{
	uint32_t n = content.length();
	uint32_t m = n >> 2;
	uint32_t sz = store.size();
	assure_words(m + 2);
	store.push_back(xs_string);
	store.push_back(n);
	store.raw_copy(content.c_str(), n);
	return sz;
}

itemref_t itemstore::add_key(
	uint64_t key)
{
	uint32_t sz = store.size();
	store.push_back(key>>32);
	store.push_back(key&0xffffffff);
	return sz;
}


itemref_t itemstore::add_namespace(
	std::string const& uri,
	std::string const& prefix)
{
	Assert<bad_arg>(uri.length()!=0);

	uint32_t sz = store.size();
	urikey_t ukey = hashfun::h64(uri);
	uint64_t nkey = ukey + 3*hashfun::h64(prefix);

	itemref_t uriref = qncache.get_uri(ukey);
	if (uriref) {
		store.push_back(xs_anyURIRef);
		store.push_back(0);				// length
		add_key(nkey);						// [prefix+uri] hash key
		add_text(prefix);					// prefix string
		store.push_back(uriref);	// uri reference
	}
	else {
		store.push_back(xs_anyURI);
		store.push_back(0);				// length
		add_key(nkey);						// [prefix+uri] hash key
		add_text(prefix);					// prefix string
		uriref = store.size()+1;
		store.push_back(uriref);	// uri ref
		add_text(uri);						// uri string
	}
	store[sz+1] = store.size() - sz;
	return sz;
}


itemref_t itemstore::add_qname(
	std::string const& name,
	std::string const& prefix,
	std::string const& uri)
{
	Assert<bad_arg>(uri.length()!=0);

	uint32_t sz = store.size();
	uint64_t nkey = hashfun::h64(name);
	uint64_t pkey = hashfun::h64(prefix);
	uint64_t ukey = hashfun::h64(uri);
	uint64_t qkey = ukey + 3*(nkey + 3*pkey);

	itemref_t qnref = qncache.get_qname(qkey);
	if (qnref) {
		store.push_back(xs_qname);
		store.push_back(0);				// length
		add_key(qkey);						// [prefix+uri+localname] hash key
		store.push_back(qnref);		// qname reference
	}
	else {
		store.push_back(xs_qname);
		store.push_back(0);				// length
		add_key(qkey);						// [prefix+uri+localname] hash key
		qnref = store.size()+1;
		store.push_back(qnref);		// qname reference
		add_text(name);
		add_text(prefix);
		add_text(uri);
	}
	store[sz+1] = store.size() - sz;
	return sz;
}


void* itemstore::last()
{
	return static_cast<void*>(&store[store.size()]);
}


} /* namespace xqp */

