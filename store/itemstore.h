/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: itemstore.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITEMSTORE_H
#define XQP_ITEMSTORE_H

#include "store_common.h"
#include "qname_cache.h"
#include "nodeid_index.h"

#include "../context/common.h"
#include "../util/fxvector.h"
#include "../util/fxhashmap.h"
#include <sys/types.h>

namespace xqp {

#define DEFAULT_SIZE 4096

class itemstore : public rcobject
{
protected:
	fxvector<uint32_t> store;		// binary data store
	fxhash64map<off_t> index;		// map: nodeid -> off_t
	qname_cache qncache;
	nodeid_index nidindex;

public:
	itemstore(uint32_t initial_size=DEFAULT_SIZE);
	itemstore(const std::string& path,uint32_t initial_size=DEFAULT_SIZE);
	~itemstore();

public:	
	uint32_t eos() const { return store.size(); }
	void* eos_p() { return &store[store.size()]; }
	void* last();
	bool index_put(off_t id, off_t res) { return index.put(id, res); }

	// word access
	void put(uint32_t u) { store.push_back(u); }
	uint32_t& operator[](uint32_t n) { return store[n]; }

	// allocator
	bool check_words(size_t n)
	{ return (store.size() + n >= store.capacity()); }
	
	void assure_words(size_t n)
	{ while (store.size() + n >= store.capacity()) store.expand(); }
	
	void assure(size_t n)
	{ while (store.size() + (n>>2) >= store.capacity()) store.expand(); }

	void* alloc(size_t n) { return store.alloc(n); }

	// text
	itemref_t add_text(const std::string& content);
	std::string get_text(itemref_t, uint32_t length) const;
	
	// keys
	itemref_t add_key(uint64_t key);

	// qnames
	qnamepair_t add_qname(const std::string& qname);
	itemref_t name_space(const std::string& prefix);

	// nodeid index
	bool get_itemref(nodeid_t, itemref_t&) const;
	bool put_itemref(nodeid_t, itemref_t);

};

} /* namespace xqp */
#endif /* XQP_ITEMSTORE_H */

