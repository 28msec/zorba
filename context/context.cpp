/** -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "context.h"

#include "../runtime/iterator.h"
#include "../types/sequence_type.h"
#include "../util/hashfun.h"
#include "../util/tracer.h"
#include "../util/xqp_exception.h"
#include "../values/values.h"

#include <stdlib.h>
#include <sstream>
#include <string>


using namespace std;
namespace xqp {


/*...........................................
	:  default constructor                    :
	:.........................................:
*/

/*
	Expecting directories:
		data/docindex
				 nodestore/nspool
									 qnpool
*/

context::context()
:
	parent_h(NULL),
	namespaces(),
	in_scope_schema_types(),
	in_scope_elem_decls(),
	in_scope_attr_decls(),
	in_scope_vars(),
	collations(),
	//statically_known_collection_types(32,0.6),
	signature_map(256,0.6),
	statically_known_documents(256,0.6),
	statically_known_collections(64,0.6),

	context_item_h(NULL),
	context_position(0),
	context_size(0),

	var_values(1024,0.6),
	function_lib(NULL),
	timezone(-8),
	available_documents(1024,0.6),
	available_collections(1024,0.6),
	default_collection(NULL),
	counters("data/nodeid",256),
	string_store_h(new fxcharheap(1<<16)),		// XXX obsolete
	istore_h(new itemstore("data/itemstore")),

	ctx_nodeid(0),
	ctx_docid(0),
	ctx_nsseqid(0),
	ctx_nsseqref(0),

	nskeymap("data/nskeymap", 0.6f, 6),
	urimap("data/urimap", 0.6f, 6),
	docindex("data/docindex", 0.6f, 6),
	nodeindex("data/nodeindex", 0.6f, 6),
	err(0)
{
	// XXX read these out of a config file
	addns("xml","http://www.w3.org/XML/1998/namespace");
	addns("xmlns","http://www.w3.org/2000/xmlns/");
	addns("xh","http://www.w3.org/1999/xhtml/");
	// .. and others

}

context::~context()
{
}

/*..........................................
 :  strings                                :
 :.........................................*/

off_t context::put_string(
	string const& s)
{
	return string_store_h->put(s.c_str());
}

string context::get_string(
	off_t sref)
throw (xqp_exception)
{
	return string_store_h->get(sref);
}


/*..........................................
 :  namespaces, collation, base URIs       :
 :.........................................*/

void context::add_namespace(
	namespace_node* ns_p)
{
	namespaces.push_back(ns_p);
}

namespace_node* context::get_default_ns() const
{
	return default_ns_p;
}

void context::set_default_ns(
	namespace_node* ns_p)
{
	default_ns_p = ns_p;
}

namespace_node* context::get_default_function_ns() const
{
	return default_function_ns_p;
}

void context::set_default_function_ns(
	namespace_node* ns_p)
{
	default_function_ns_p = ns_p;
}

string context::get_default_collation() const
{
	return default_collation;
}

void context::set_default_collation(const string& s)
{
	default_collation = s;
}

string context::get_base_uri() const
{
	return base_uri;
}

void context::set_base_uri(
	std::string const& uri)
{
	base_uri = uri;
}


/*..........................................
 :  docids                                 :
 :.........................................*/

uint32_t context::next_docid()
{
	return (++counters[docid_counter]);
}


/*..........................................
 :  nodeids                                :
 :.........................................*/

uint32_t context::next_nodeid()
{
	return (++counters[nodeid_counter]);
}


/*..........................................
 :  generation number                      :
 :.........................................*/

uint32_t context::gen()
{
	return (counters[gen_counter]);
}

uint32_t context::next_gen()
{
	return (++counters[gen_counter]);
}


/*..........................................
 :  docindex                               :
 :.........................................*/

bool context::put_dnid(
	urikey_t uri,
	nodeid_t dnid)
{
	return docindex.put(uri, dnid);
}

bool context::get_dnid(
	urikey_t uri,
	nodeid_t & dnid) const
{
	return docindex.get(uri, dnid);
}


/*..........................................
 :  nodeindex                              :
 :.........................................*/

bool context::put_noderef(
	nodeid_t id,
	itemref_t ref)
{
	return nodeindex.put(id, ref);
}

bool context::get_noderef(
	nodeid_t id,
	itemref_t& ref) const
{
	return nodeindex.get(id, ref);
}


/*..........................................
 :  namespaces                             :
 :.........................................*/

bool context::get_nskey(
	const string& prefix,
	nskey_t& key) const
{
	return nskeymap.get(prefix,key);
}

bool context::put_nskey(
	const string& prefix,
	nskey_t key) 
{
	return nskeymap.put(prefix,key);
}

bool context::get_uri(
	const string& prefix,
	string& uri) const
{
	return urimap.get(prefix,uri);
}

bool context::put_uri(
	const string& prefix,
	const string& uri) 
{
	return urimap.put(prefix,uri);
}

bool context::addns(
	const string& prefix,
	const string& uri) 
{
	if (!urimap.put(prefix,uri)) return false;
	return nskeymap.put(prefix,hashfun::h64(uri));
}


/*..........................................
 :  variables                              :
 :.........................................*/

var_binding::var_binding()
:
  qname_p(NULL),
	value_h(NULL),
  type(xs_untypedValue)
{
}

var_binding::var_binding(
	var_binding &  v)
:
  qname_p(v.qname_p),
	value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	var_binding const&  v)
:
  qname_p(v.qname_p),
  value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	qname_value* _qname_p,
	rchandle<item_iterator> _value_h,
	sequence_type_t _type)
:
	qname_p(_qname_p),
	value_h(_value_h),
	type(_type)
{
}

void context::push_var(
	rchandle<var_binding> vb_h)
{
	
}

rchandle<item_iterator> context::get_var_value(
	qname_value*) const
throw (xqp_exception)
{
	return NULL;
}


/*..........................................
 :  functions                              :
 :.........................................*/

sequence_type_t context::get_function_type(
  qname_value const* fname_p) const 
throw (xqp_exception)
{
	return xs_untypedValue;
}
	
function const* context::get_function(
	qname_value const*) const
throw (xqp_exception)
{
	return NULL;
}


/*..........................................
 :  context document                       :
 :.........................................*/

sequence_type_t context::get_document_type(
	uri_value const* doc_uri) const
throw (xqp_exception)
{
  return xs_untypedValue;
}
	
rchandle<item_iterator> context::get_document(
	uri_value const* doc_uri) const
throw (xqp_exception)
{
  return NULL;
}


/*..........................................
 :  context collection                     :
 :.........................................*/

sequence_type_t context::get_collection_type(
	uri_value const* col_uri) const
throw (xqp_exception)
{
	return xs_untypedValue;
}
	
rchandle<item_iterator> context::get_collection(
	uri_value const* col_uri) const
throw (xqp_exception)
{
  return NULL;
}

rchandle<item_iterator> context::get_default_collection() const
throw (xqp_exception)
{
  return NULL;
}


}	/* namespace xqp */

