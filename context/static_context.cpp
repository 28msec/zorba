/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: static_context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */


#include "static_context.h"
#include "common.h"
#include "runtime/singleton_iterators.h"
#include "values/qname.h"
#include "values/value_factory.h"


using namespace std;
namespace xqp {

bool static_context::static_init = false;


void static_context::init(
	value_factory* vf_p)
{
	if (!static_context::static_init) {
		default_function_ns_key =
			vf_p->make_qname(ZORBA_NS,"xqp","default-function-ns")->qnamekey();
		default_collation_key =
			vf_p->make_qname(ZORBA_NS,"xqp","default-collation")->qnamekey();
		in_scope_schema_types_key =
			vf_p->make_qname(ZORBA_NS,"xqp","in-scope-schema-types")->qnamekey();
		in_scope_element_decls_key =
			vf_p->make_qname(ZORBA_NS,"xqp","in-scope-element-decls")->qnamekey();
		in_scope_attribute_decls_key =
			vf_p->make_qname(ZORBA_NS,"xqp","in-scope-attribute-decls")->qnamekey();
		collations_key =
			vf_p->make_qname(ZORBA_NS,"xqp","collations")->qnamekey();
		construction_mode_key =
			vf_p->make_qname(ZORBA_NS,"xqp","construction-mode")->qnamekey();
		order_empty_mode_key =
			vf_p->make_qname(ZORBA_NS,"xqp","order-empty-mode")->qnamekey();
		boundary_space_mode_key =
			vf_p->make_qname(ZORBA_NS,"xqp","boundary-space-mode")->qnamekey();
		inherit_mode_key =
			vf_p->make_qname(ZORBA_NS,"xqp","inherit-mode")->qnamekey();
		preserve_mode_key =
			vf_p->make_qname(ZORBA_NS,"xqp","preserve-mode")->qnamekey();
		baseuri_key =
			vf_p->make_qname(ZORBA_NS,"xqp","baseuri")->qnamekey();
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

iterator_t static_context::default_function_namespace() const
{
	return context_value(default_function_ns_key);
}

void static_context::set_default_function_namespace(
	const namespace_node* nn_p)
{
	iterator_t it_h = new node_singleton((const node*)nn_p);
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
	iterator_t it_h = context_value(construction_mode_key);
	string mode = (**it_h).string_value();
	if (mode=="preserve") return cons_preserve;
	return cons_strip;
}

static_context::order_empty_mode_t static_context::order_empty_mode() const
{
	iterator_t it_h = context_value(order_empty_mode_key);
	string mode = (**it_h).string_value();
	if (mode=="empty_greatest") return empty_greatest;
	return empty_least;
}

static_context::boundary_space_mode_t static_context::boundary_space_mode() const
{
	iterator_t it_h = context_value(boundary_space_mode_key);
	string mode = (**it_h).string_value();
	if (mode=="preserve_space") return preserve_space;
	return strip_space;
}

static_context::inherit_mode_t static_context::inherit_mode() const
{
	iterator_t it_h = context_value(inherit_mode_key);
	string mode = (**it_h).string_value();
	if (mode=="inherit_ns") return inherit_ns;
	return no_inherit_ns;
}

static_context::preserve_mode_t static_context::preserve_mode() const
{
	iterator_t it_h = context_value(preserve_mode_key);
	string mode = (**it_h).string_value();
	if (mode=="preserve_ns") return preserve_ns;
	return no_preserve_ns;
}

void static_context::set_construction_mode(
	enum construction_mode_t v)
{
	string mode = (v==cons_preserve?"cons_preserve":"cons_strip");
	iterator_t it_h = new string_singleton(stringValue(mode));
	keymap.put(construction_mode_key, it_h);
}

void static_context::set_order_empty_mode(
	enum order_empty_mode_t v)
{
	string mode = (v==empty_greatest?"empty_greatest":"empty_least");
	iterator_t it_h = new string_singleton(stringValue(mode));
	keymap.put(order_empty_mode_key, it_h);
}

void static_context::set_boundary_space_mode(
	enum boundary_space_mode_t v)
{
	string mode = (v==preserve_space?"preserve_space":"strip_space");
	iterator_t it_h = new string_singleton(stringValue(mode));
	keymap.put(boundary_space_mode_key, it_h);
}

void static_context::set_inherit_mode(
	enum inherit_mode_t v)
{
	string mode = (v==inherit_ns?"inherit_ns":"no_inherit_ns");
	iterator_t it_h = new string_singleton(stringValue(mode));
	keymap.put(inherit_mode_key, it_h);
}

void static_context::set_preserve_mode(
	enum preserve_mode_t v)
{
	string mode = (v==preserve_ns?"preserve_ns":"no_preserve_ns");
	iterator_t it_h = new string_singleton(stringValue(mode));
	keymap.put(preserve_mode_key, it_h);
}

const qname& static_context::get_default_collation() const
{
	return dynamic_cast<const qname&>(**context_value(default_collation_key));
}

std::string static_context::get_baseuri() const
{
	return (**context_value(baseuri_key)).string_value();
}

void static_context::set_default_collation(const string& uri)
{
	iterator_t it_h = new string_singleton(stringValue(uri));
	keymap.put(default_collation_key, it_h);
}

void static_context::set_baseuri(const std::string& uri)
{
	iterator_t it_h = new string_singleton(stringValue(uri));
	keymap.put(default_collation_key, it_h);
}

sequence_type_t static_context::get_function_type(
	const qname* qname_p) const
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

