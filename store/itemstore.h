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
#include "data_manager.h"

#include "context/common.h"
#include "util/fxvector.h"
#include "util/fxhashmap.h"
#include "values/primitive_values.h"
#include "zorba/qnamerep.h"

#include <string>

namespace xqp {

#define DEFAULT_SIZE 4096

class document_node;
class update_value;
class node;
class xs_stringValue;



class qname_cache : public rcobject
{
protected:
	fxhash64map<itemid_t> qname_map;	// map: qname key  -> itemid
	fxhash64map<itemid_t> uri_map;		// map: prefix key -> itemid
	fxvector<qnamerep> qnamev;				// qnamev[itemid] = QName
	fxvector<stringValue> uriv;				// uriv[itemid]   = URI

public:
	qname_cache(const std::string& datapath);
	qname_cache();
	~qname_cache() {}

public:
	uint32_t size() const { return qname_map.size(); }
	uint32_t qnamev_size() const { return qnamev.size(); }

	// map: [uri:name] -> qname itemid
	bool put_qname_id(
		itemid_t uri_id, const std::string& name, itemid_t qname_id);
	bool get_qname_id(
		itemid_t uri_id, const std::string& name, itemid_t& qname_id) const;

	// itemid -> qname
	bool put_qname(
		itemid_t qname_id, const qnamerep&);
	bool get_qname(
		itemid_t qname_id, qnamerep&);
	itemid_t add_qname(
		const qnamerep&);

	// map: prefix -> uri itemid
	bool put_uri_id(
		const std::string& prefix, itemid_t uri_id);
	bool get_uri_id(
		const std::string& prefix, itemid_t& uri_id) const;

	// itemid -> uri
	bool put_uri(
		itemid_t uri_id, const stringValue&);
	bool get_uri(
		itemid_t uri_id, stringValue&);

	qnamerep& operator[](int i) { return qnamev[i]; }

};



class itemstore : public data_manager
{
protected:
	fxvector<uint32_t> store;		// binary data store
	fxhash64map<off_t> index;		// map: itemid -> off_t
	qname_cache qncache;

	enum counter_keys {
		docid_counter  = 0,
		itemid_counter = 1,
		gen_counter    = 2
	};

public:
	itemstore(uint32_t initial_size=DEFAULT_SIZE);
	itemstore(const std::string& path,uint32_t initial_size=DEFAULT_SIZE);
	~itemstore();


public:		// data manager interface

	// documents
	iterator_t document(const std::string&);
	bool add_document(const std::string&, const document_node&);
	bool remove_document(const std::string&);

	// collections
	iterator_t collection(const std::string&);
	bool add_collection(const std::string&, iterator_t);
	bool remove_collection(const std::string&);
	bool append_to_collection(const std::string&, iterator_t);

	// updates
	void apply(const update_value*);

	// value cache
	const node* get_node(itemid_t) const;
	const xs_stringValue* get_uri(itemid_t) const;
	const qname* get_qname(itemid_t) const;


public:		// storage interface

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
	off_t add_text(const std::string& content);
	std::string get_text(off_t, uint32_t length) const;
	
	// keys
	off_t add_key(uint64_t key);

	// qnames
	qnamerep& add_qname(const std::string& qname);
	off_t name_space(const std::string& prefix);

	// nodeid index
	bool get_off(itemid_t, off_t&) const;
	bool put_off(itemid_t, off_t);


protected:	// runtime state
	itemid_t ctx_itemid;							// itemid of context node
	docid_t  ctx_docid;								// docid of context document
	off_t    ctx_docref;							// ref to context doc
	fxarray<uint64_t> counters;				// persistent itemid counter
	fxhash64map<itemid_t> docindex;		// map: urikey -> doc node id

public:			// runtime services
	// docid services
	docid_t next_docid();
	docid_t context_docid() const { return ctx_docid; }
	void set_context_docid(docid_t docid) { ctx_docid = docid; }
	off_t& docref() { return ctx_docref; }

	// itemid services
	itemid_t next_itemid();
	itemid_t context_itemid() const { return ctx_itemid; }

	// generation number service
	uint32_t gen();
	uint32_t next_gen();

	// namespace services
	itemid_t in_scope_ns();

};

} /* namespace xqp */
#endif /* XQP_ITEMSTORE_H */

