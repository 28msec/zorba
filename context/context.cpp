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
	default_collection("defcol"),
	nodeid_counter("data/nodeid",2),
	string_store_h(new fxcharheap(1<<16)),
	nodestore_h(new nodestore("data/nodestore/")),
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
	string const& prefix,
	string const& uri)
{
	nsid_t id;
	off_t offset = itemstore.add_namespace(prefix,uri, id);
	namespaces.push_back(pair<nsid_t,off_t>(id,offset));
}

bool context::get_default_elem_or_type_ns(
	string& uri) const
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	return nspool_h->get_uri(default_elem_or_type_ns, uri);
}

void context::set_default_elem_or_type_ns(
	string const& uri)
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	default_elem_or_type_ns = nspool_h->put(0,"#def-elem",uri);
}

bool context::get_default_function_ns(
	string& uri) const
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	return nspool_h->get_uri(default_function_ns, uri);
}

void context::set_default_function_ns(
	string const& uri)
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	default_function_ns = nspool_h->put(0,"#def-func",uri);
}

bool context::get_default_collation(
	string& uri) const
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	return nspool_h->get_uri(default_collation, uri);
}

void context::set_default_collation(
	std::string const& uri)
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	default_collation = nspool_h->put(0,"#def-coll",uri);
}

bool context::get_base_uri(
	string& uri) const
{
	rchandle<namespace_pool> nspool_h = nodestore_h->get_namespace_pool();
	uri = base_uri;
	return true;
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
  name(0),
	value_h(NULL),
  type(xs_untypedValue)
{
}

var_binding::var_binding(
	var_binding &  v)
:
  name(v.name),
	value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	var_binding const&  v)
:
  name(v.name),
  value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	qname _name,
	rchandle<item_iterator> _value_h,
	sequence_type_t _type)
:
	name(_name),
	value_h(_value_h),
	type(_type)
{
}


qname_node* var_binding::get_name(
	context * ctx_p) const
{
	return ctx_p->get_qname(name);
}

void context::push_var(
	rchandle<var_binding> vb_h)
{
	varstackref_t s_p;
	string varname = vb_h->get_name(this)->describe(this);
	if (!var_values.get(varname, s_p)) {
		s_p = new stack<varref_t>;
		var_values.put(varname, s_p);
	}
	s_p->push(vb_h);
}

rchandle<item_iterator> context::get_var_value(
	qnameid_t qnid) const
throw (xqp_exception)
{
	return &iterator::EMPTY_SEQUENCE;
}


/*..........................................
 :  functions                              :
 :.........................................*/

sequence_type_t context::get_function_type(
  qnameid_t fname) const 
throw (xqp_exception)
{
	return xs_untyped;
}
	
function_impl const* context::get_function(
	signature const& sig) const
throw (xqp_exception)
{
	return NULL;
}


/*..........................................
 :  context document                       :
 :.........................................*/

item_type context::get_document_type(
	string const& doc_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_documents.get(doc_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static document type for: "+doc_uri);
  }
  return t;
}
	
rchandle<item_iterator> context::get_document(
	string const& doc_uri) const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}


/*..........................................
 :  context collection                     :
 :.........................................*/

item_type context::get_collection_type(
	string const& col_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_collections.get(col_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static collection type for: "+col_uri);
  }
  return t;
}
	
rchandle<item_iterator> context::get_collection(
	string const& col_uri) const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}

rchandle<item_iterator> context::get_default_collection() const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}


/*..........................................
 :  node store                             :
 :.........................................*/

rchandle<node> context::get_node(nodeid id)
{
	rchandle<node> n_h;
	nodestore_h->get(this, id, n_h);
	return n_h;
}

rchandle<node> context::get_node(nodeid id) const
{
	rchandle<node> n_h;
	nodestore_h->get(const_cast<context*>(this), id, n_h);
	return n_h;
}

rchandle<nodestore> context::get_nodestore()
{
	return nodestore_h;
}


}	/* namespace xqp */
