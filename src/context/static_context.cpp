/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author John Cowan,Paul Pedersen (pcp071098@yahoo.com)
 * @file context/static_context.cpp
 *
 */

#include "context/static_context.h"
#include "context/common.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"


using namespace std;
namespace xqp {

bool static_context::static_init = false;
qnamekey_t static_context::default_function_ns_key;
qnamekey_t static_context::default_collation_key;
qnamekey_t static_context::in_scope_schema_types_key;
qnamekey_t static_context::in_scope_element_decls_key;
qnamekey_t static_context::in_scope_attribute_decls_key;
qnamekey_t static_context::collations_key;
qnamekey_t static_context::construction_mode_key;
qnamekey_t static_context::order_empty_mode_key;
qnamekey_t static_context::boundary_space_mode_key;
qnamekey_t static_context::inherit_mode_key;
qnamekey_t static_context::preserve_mode_key;
qnamekey_t static_context::baseuri_key;


void static_context::init(
	ItemFactory* itemFactory_p)
{
	
	if (!static_context::static_init) {
		default_function_ns_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","default-function-ns")->getQNameKey();
		default_collation_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","default-collation")->getQNameKey();
		in_scope_schema_types_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","in-scope-schema-types")->getQNameKey();
		in_scope_element_decls_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","in-scope-element-decls")->getQNameKey();
		in_scope_attribute_decls_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","in-scope-attribute-decls")->getQNameKey();
		collations_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","collations")->getQNameKey();
		construction_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","construction-mode")->getQNameKey();
		order_empty_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","order-empty-mode")->getQNameKey();
		boundary_space_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","boundary-space-mode")->getQNameKey();
		inherit_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","inherit-mode")->getQNameKey();
		preserve_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","preserve-mode")->getQNameKey();
		baseuri_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","baseuri")->getQNameKey();

		static_context::static_init = true;
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

Iterator_t static_context::default_function_namespace() const
{
	return context_value(default_function_ns_key);
}

void static_context::set_default_function_namespace(
	const namespace_node* nn_p)
{
	Iterator_t it_h = new SingletonIterator(yy::location(), (Item*)nn_p);
	keymap.put(default_function_ns_key,it_h);
}

Iterator_t static_context::in_scope_schema_types() const
{
	return context_value(in_scope_schema_types_key);
}

Iterator_t static_context::in_scope_element_decls() const
{
	return context_value(in_scope_element_decls_key);
}

Iterator_t static_context::in_scope_attribute_decls() const
{
	return context_value(in_scope_attribute_decls_key);
}

Iterator_t static_context::collations() const
{
	return context_value(collations_key);
}

static_context::construction_mode_t 
static_context::construction_mode() const
{
	Iterator_t it_h = context_value(construction_mode_key);
	IteratorWrapper iw(it_h);
	string mode = iw.next()->getStringProperty();
	if (mode=="preserve") return cons_preserve;
	return cons_strip;
}

static_context::order_empty_mode_t 
static_context::order_empty_mode() const
{
	Iterator_t it_h = context_value(order_empty_mode_key);
	IteratorWrapper iw(it_h);
	string mode = iw.next()->getStringProperty();
	if (mode=="empty_greatest") return empty_greatest;
	return empty_least;
}

static_context::boundary_space_mode_t static_context::boundary_space_mode() const
{
	Iterator_t it_h = context_value(boundary_space_mode_key);
	IteratorWrapper iw(it_h);
	string mode = iw.next()->getStringProperty();
	if (mode=="preserve_space") return preserve_space;
	return strip_space;
}

static_context::inherit_mode_t static_context::inherit_mode() const
{
	Iterator_t it_h = context_value(inherit_mode_key);
	IteratorWrapper iw(it_h);
	string mode = iw.next()->getStringProperty();
	if (mode=="inherit_ns") return inherit_ns;
	return no_inherit_ns;
}

static_context::preserve_mode_t static_context::preserve_mode() const
{
	Iterator_t it_h = context_value(preserve_mode_key);
	IteratorWrapper iw(it_h);
	string mode = iw.next()->getStringProperty();
	if (mode=="preserve_ns") return preserve_ns;
	return no_preserve_ns;
}

void static_context::set_construction_mode(
	enum construction_mode_t v)
{
	string mode = (v==cons_preserve?"cons_preserve":"cons_strip");
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(construction_mode_key, it_h);
}

void static_context::set_order_empty_mode(
	enum order_empty_mode_t v)
{
	string mode = (v==empty_greatest?"empty_greatest":"empty_least");
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(order_empty_mode_key, it_h);
}

void static_context::set_boundary_space_mode(
	enum boundary_space_mode_t v)
{
	string mode = (v==preserve_space?"preserve_space":"strip_space");
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(boundary_space_mode_key, it_h);
}

void static_context::set_inherit_mode(
	enum inherit_mode_t v)
{
	string mode = (v==inherit_ns?"inherit_ns":"no_inherit_ns");
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(inherit_mode_key, it_h);
}

void static_context::set_preserve_mode(
	enum preserve_mode_t v)
{
	string mode = (v==preserve_ns?"preserve_ns":"no_preserve_ns");
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(preserve_mode_key, it_h);
}

const Item& static_context::get_default_collation() const
{
	Iterator_t it_h = context_value(default_collation_key);
	IteratorWrapper iw(it_h);
	Item_t i_h = iw.next();
	return *i_h;
}

std::string static_context::get_baseuri() const
{
	Iterator_t it_h = context_value(baseuri_key);
	IteratorWrapper iw(it_h);
	Item_t i_h = iw.next();
	return i_h->getStringProperty();
}

void static_context::set_default_collation(const string& uri)
{
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(uri));
	keymap.put(default_collation_key, it_h);
}

void static_context::set_baseuri(const std::string& uri)
{
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(uri));
	keymap.put(default_collation_key, it_h);
}

sequence_type_t static_context::get_function_type(
	const Item* qname_p) const
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

