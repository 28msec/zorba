/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: static_context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */


#include "static_context.h"
#include "../store/itemstore.h"
#include "../values/qname_value.h"

using namespace std;
namespace xqp {

typedef rchandle<abstract_iterator> iterator_t;
bool static_context::static_init = false;


void static_context::init(
	itemstore& istore) const
{
	if (!static_context::static_init) {
		default_function_ns_key = istore.add_qname("xqp:default-function-ns").qnamekey;
		default_collation_key = istore.add_qname("xqp:default-collation").qnamekey;
		in_scope_schema_types_key = istore.add_qname("xqp:in-scope-schema-types").qnamekey;
		in_scope_element_decls_key = istore.add_qname("xqp:in-scope-element-decls").qnamekey;
		in_scope_attribute_decls_key = istore.add_qname("xqp:in-scope-attribute-decls").qnamekey;
		collations_key = istore.add_qname("xqp:collations").qnamekey;
		construction_mode_key = istore.add_qname("xqp:construction-mode").qnamekey;
		order_empty_mode_key = istore.add_qname("xqp:order-empty-mode").qnamekey;
		boundary_space_mode_key = istore.add_qname("xqp:boundary-space-mode").qnamekey;
		inherit_mode_key = istore.add_qname("xqp:inherit-mode").qnamekey;
		preserve_mode_key = istore.add_qname("xqp:preserve-mode").qnamekey;
		baseuri_key = istore.add_qname("xqp:baseuri").qnamekey;
	}
}



/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

rchandle<context>
static_context::parent() const
{
	return parent_h;
}

iterator_t
static_context::context_value(qnamekey_t key) const
{
	iterator_t it_h;
	if (!keymap.get(key, it_h)) return NULL;
	return it_h;
}

abstract_namespace_node*
static_context::default_function_namespace() const
{
	abstract_item* i_p = context_value(default_function_ns_key)->peek();
	if (!i_p->type()==namespaceNode) return NULL;
	return static_cast<abstract_namespace_node*>(i_p);
}

void static_context::set_default_function_namespace(
	abstract_namespace_node* nn_p)
{
	iterator_t it_h = new singleton_iterator(nn_p);
		//reinterpret_cast<abstract_item*>(nn_p));
	keymap.put(default_function_ns_key,it_h);
}

iterator_t static_context::in_scope_schema_types() const
{
	return context_value(in_scope_schema_types_key);
}

iterator_t static_context::in_scope_element_decls() const
{
	return context_value(in_scope_element_decls_key);
}

iterator_t static_context::in_scope_attribute_decls() const
{
	return context_value(in_scope_attribute_decls_key);
}

iterator_t static_context::collations() const
{
	return context_value(collations_key);
}

static_context::construction_mode_t static_context::construction_mode() const
{
	qname_value* qn_p =
		(qname_value*)context_value(construction_mode_key)->peek();
	string mode = qn_p->localname();
	if (mode=="preserve") return cons_preserve;
	return cons_strip;
}

static_context::order_empty_mode_t static_context::order_empty_mode() const
{
	qname_value* qn_p =
		(qname_value*)context_value(order_empty_mode_key)->peek();
	string mode = qn_p->localname();
	if (mode=="empty_greatest") return empty_greatest;
	return empty_least;
}

static_context::boundary_space_mode_t static_context::boundary_space_mode() const
{
	qname_value* qn_p =
		(qname_value*)context_value(boundary_space_mode_key)->peek();
	string mode = qn_p->localname();
	if (mode=="preserve_space") return preserve_space;
	return strip_space;
}

static_context::inherit_mode_t static_context::inherit_mode() const
{
	qname_value* qn_p =
		(qname_value*)context_value(inherit_mode_key)->peek();
	string mode = qn_p->localname();
	if (mode=="inherit_ns") return inherit_ns;
	return no_inherit_ns;
}

static_context::preserve_mode_t static_context::preserve_mode() const
{
	qname_value* qn_p =
		(qname_value*)context_value(preserve_mode_key)->peek();
	string mode = qn_p->localname();
	if (mode=="preserve_ns") return preserve_ns;
	return no_preserve_ns;
}

void static_context::set_construction_mode(
	enum construction_mode_t v)
{
	string mode = (v==cons_preserve?"cons_preserve":"cons_strip");
	iterator_t it_h = new singleton_iterator(vf_p, mode);
	keymap.put(construction_mode_key, it_h);
}

void static_context::set_order_empty_mode(
	enum order_empty_mode_t v)
{
	string mode = (v==empty_greatest?"empty_greatest":"empty_least");
	iterator_t it_h = new singleton_iterator(vf_p,mode);
	keymap.put(order_empty_mode_key, it_h);
}

void static_context::set_boundary_space_mode(
	enum boundary_space_mode_t v)
{
	string mode = (v==preserve_space?"preserve_space":"strip_space");
	iterator_t it_h = new singleton_iterator(vf_p,mode);
	keymap.put(boundary_space_mode_key, it_h);
}

void static_context::set_inherit_mode(
	enum inherit_mode_t v)
{
	string mode = (v==inherit_ns?"inherit_ns":"no_inherit_ns");
	iterator_t it_h = new singleton_iterator(vf_p,mode);
	keymap.put(inherit_mode_key, it_h);
}

void static_context::set_preserve_mode(
	enum preserve_mode_t v)
{
	string mode = (v==preserve_ns?"preserve_ns":"no_preserve_ns");
	iterator_t it_h = new singleton_iterator(vf_p,mode);
	keymap.put(preserve_mode_key, it_h);
}

const abstract_qname* static_context::get_default_collation() const
{
	return (abstract_qname*)context_value(default_collation_key)->peek();
}

std::string static_context::get_baseuri() const
{
	return context_value(baseuri_key)->peek()->string_value();
}

void static_context::set_default_collation(const string& uri)
{
	iterator_t it_h = new singleton_iterator(vf_p,uri);
	keymap.put(default_collation_key, it_h);
}

void static_context::set_baseuri(const std::string& uri)
{
	iterator_t it_h = new singleton_iterator(vf_p,uri);
	keymap.put(default_collation_key, it_h);
}

sequence_type_t static_context::get_function_type(
	const abstract_qname* qname_p) const
throw (xqp_exception)
{
	//stub
	return xs_anyType;
}

sequence_type_t static_context::get_document_type(
	const std::string& doctype) const
throw (xqp_exception)
{
	//stub
	return xs_anyType;
}

sequence_type_t static_context::get_collection_type(
	const std::string& colltype) const
throw (xqp_exception)
{
	//stub
	return xs_anyType;
}


}	/* namespace xqp */

