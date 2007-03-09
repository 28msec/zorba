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

inline bool itemstore::check_words(size_t n)
{
	return (store.size() + n >= store.capacity());
}

inline void itemstore::assure_words(size_t n)
{
	while (store.size() + n >= store.capacity()) store.expand();
}

inline void itemstore::assure_bytes(size_t n)
{
	while (store.size() + (n>>2) >= store.capacity()) store.expand();
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

string itemstore::get_text(off_t n) const
{
	uint32_t type = store[n];
	Assert<bad_arg>(type==xs_string);
	uint32_t length = store[n+1];
	return string((char*)&store[n+1],0,length);
}

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


} /* namespace xqp */

