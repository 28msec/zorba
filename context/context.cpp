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
	nodeid_counter("data/nodeid",2),
	string_store_h(new fxcharheap(1<<16)),
	itemstore_h(new itemstore("data/itemstore/")),
	ctx_nodeid(0),
	ctx_docid(0),
	in_scope_ns(0),
	docindex("data/docindex/", 0.6f, 6)
{
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

qname_value* context::get_default_collation() const
{
	return default_collation_p;
}

void context::set_default_collation(qname_value* q_p)
{
	default_collation_p = q_p;
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
	return (++nodeid_counter[0]);
}


/*..........................................
 :  nodeids                                :
 :.........................................*/

uint32_t context::next_nodeid()
{
	return (++nodeid_counter[1]);
}


/*..........................................
 :  docindex                               :
 :.........................................*/

bool context::put_docuri(
	char const* uri,
	uint32_t dnid)
{
	return docindex.put(uri, dnid);
}

bool context::put_docuri(
	std::string const& uri,
	uint32_t dnid)
{
	return docindex.put(uri, dnid);
}

bool context::get_dnid(
	char const* uri,
	uint32_t & dnid) const
{
	return docindex.get(uri, dnid);
}

bool context::get_dnid(
	std::string const& uri,
	uint32_t & dnid) const
{
	return docindex.get(uri, dnid);
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
	return &item_iterator::empty_sequence;
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


/*..........................................
 :  node store                             :
 :.........................................*/

rchandle<itemstore> context::get_itemstore()
{
	return itemstore_h;
}


}	/* namespace xqp */
