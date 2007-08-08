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
 * @file context/dynamic_context.cpp
 *
 */

#include "dynamic_context.h"
#include "runtime/item_iterator.h"

using namespace std;
namespace xqp {

bool dynamic_context::static_init = false;
qnamekey_t dynamic_context::namespaces_key;
qnamekey_t dynamic_context::default_element_type_ns_key;
qnamekey_t dynamic_context::context_item_key;
qnamekey_t dynamic_context::context_item_type_key;
qnamekey_t dynamic_context::ordering_mode_key;
qnamekey_t dynamic_context::current_time_key;
qnamekey_t dynamic_context::implicit_timezone_key;


void dynamic_context::init(
	value_factory* vfactory_p)
{
	if (!dynamic_context::static_init) {
		default_element_type_ns_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","default-element-type")->qnamekey();
		context_item_type_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","context-item-type")->qnamekey();
		context_item_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","context-item")->qnamekey();
		ordering_mode_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","ordering-mode")->qnamekey();
		namespaces_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","namespaces")->qnamekey();
		current_time_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","current-time")->qnamekey();
		implicit_timezone_key =
			vfactory_p->make_qname(ZORBA_NS,"xqp","implicit-timezone")->qnamekey();


		dynamic_context::static_init = true;
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

const namespace_node&
dynamic_context::default_element_type_namespace() const
{
	iterator_t it_h = context_value(default_element_type_ns_key);
	it_h->open();
	item_t i_h = it_h->next();
	it_h->close();
	return dynamic_cast<const namespace_node&>(*i_h);
}

void dynamic_context::set_default_element_type_namespace(
	namespace_node& nn_p)
{
	iterator_t it_h = new SingletonIterator(yy::location(), &nn_p);
	keymap.put(default_element_type_ns_key,it_h);
}

void add_namespace(const namespace_node*)
{
}

iterator_t dynamic_context::namespaces() const
{
	return context_value(namespaces_key);
}

sequence_type_t dynamic_context::context_item_type() const
{
	return xs_anyType; //stub
}

dynamic_context::ordering_mode_t dynamic_context::ordering_mode() const
{
	iterator_t it_h = context_value(ordering_mode_key);
	it_h->open();
	item_t i_h = it_h->next();
	it_h->close();
	string mode = i_h->str();
	if (mode=="ordered") return ordered;
	return unordered;
}


void dynamic_context::set_context_item_type(
	sequence_type_t v)
{
}

void dynamic_context::set_ordering_mode(
	enum ordering_mode_t v)
{
	string mode = (v==ordered?"ordered":"unordered");
	iterator_t it_h = new SingletonIterator(yy::location(), new stringValue(mode));
	keymap.put(ordering_mode_key, it_h);
}


}	/* namespace xqp */

