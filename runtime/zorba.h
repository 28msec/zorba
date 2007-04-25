/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_H
#define XQP_ZORBA_H

#include "context/common.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "runtime/errors.h"
#include "runtime/item_iterator.h"
#include "store/store.h"
#include "types/sequence_type.h"
#include "util/fxarray.h"
#include "util/fxhashmap.h"
#include "util/rchandle.h"
#include "util/xqp_exception.h"
#include "values/itemid.h"
#include "values/qname.h"
#include "values/values.h"

#include <time.h>
#include <vector>

namespace xqp {

class value_factory;

class zorba : public rcobject
{
		// (put this in the zorba store)
public:
		enum counter_kind { docid_counter = 0, itemid_counter = 1, gen_counter = 2 };

protected:
	rchandle<store> store_h;											// storage interface
	rchandle<value_factory> vfactory_h;						// value factory
	rchandle<static_context> static_context_h;		// static context
	rchandle<dynamic_context> dynamic_context_h;	// dynamic context

		// (put these in the zorba store)
		itemid_t	ctx_itemid;							// itemid of context node
		docid_t		ctx_docid;							// docid of context document
		itemref_t	ctx_docref;							// ref to context doc
	
		fxarray<uint64_t> counters;				// persistent itemid counter
		fxhashmap<nskey_t> nskeymap;			// map: prefix -> nskey
		fxhashmap<string> urimap;					// map: prefix -> uri 
		fxhash64map<itemid_t> docindex;		// map: urikey -> doc node id


public:
	zorba(rchandle<store>, rchandle<value_factory>);
	~zorba() {}

public:
	store* get_store() const { return &*store_h; }
	value_factory* get_value_factory() const { return &*vfactory_h; }
	static_context* get_static_context() const { return &*static_context_h; }
	dynamic_context* get_dynamic_context() const { return &*dynamic_context_h; }

	void set_store(store* v) { store_h = v; }
	void set_value_factory(value_factory* v) { vfactory_h = v; }
	void set_static_context(static_context* v) { static_context_h = v; }
	void set_dynamic_context(dynamic_context* v) { dynamic_context_h = v; }

public:
	// qname services
	qname* get_qname(itemid_t) const;

	// docid services
	docid_t next_docid();
	docid_t context_docid() const { return ctx_docid; }
	void set_context_docid(docid_t docid) { ctx_docid = docid; }
	itemref_t& docref() { return ctx_docref; }

	// itemid services
	itemid_t next_itemid();
	itemid_t context_itemid() const { return ctx_itemid; }

	// generation numbers
	uint32_t gen();
	uint32_t next_gen();

	// namespace service
	bool namespace_uri(uint32_t uri_id, std::string& uri);
	bool get_nskey(const std::string& prefix, nskey_t&) const;
	bool put_nskey(const std::string& prefix, nskey_t);
	bool get_uri(const std::string& prefix, std::string& uri) const;
	bool put_uri(const std::string& prefix, const std::string& uri);
	bool addns(const std::string& prefix, const std::string& uri);

	// docindex
	bool put_dnid(urikey_t uri, itemid_t);
	bool get_dnid(urikey_t uri, itemid_t&) const;

	// context item
  const item* context_item() const
		{ return dynamic_context_h->context_item(); }
	uint32_t context_position() const
		{ return dynamic_context_h->context_position(); }
	uint32_t context_size() const
		{ return dynamic_context_h->context_size(); }

	// default doc/collection
	rchandle<item_iterator> get_document(const std::string&) const
		throw (xqp_exception);
	rchandle<item_iterator> get_collection(const std::string&) const
		throw (xqp_exception);
	rchandle<item_iterator> get_default_collection() const
		throw (xqp_exception);
	sequence_type_t zorba::get_document_type(const std::string&) const
		throw (xqp_exception);
	sequence_type_t zorba::get_collection_type(const std::string&) const
		throw (xqp_exception);
	
	// functions
	/*
	const function* get_function(const qname*) const
	throw (xqp_exception);
	sequence_type_t zorba::get_function_type(const qname* fname_p)
	const throw (xqp_exception);
	*/

public:	// diagnostics
  enum diagnostic_flag_t {
    trace_functions   = 1,
    trace_timing      = 2,
    trace_all         = 4
  };
	
  uint32_t lineno;
  uint32_t charpos;
	errors::errcode zorba_errno;

	errors::errcode get_error() const { return zorba_errno; }
	void set_error(errors::errcode err) { zorba_errno = err; }

};


}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

