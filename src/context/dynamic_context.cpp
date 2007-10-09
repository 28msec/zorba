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
	ItemFactory* itemFactory_p)
{
	if (!dynamic_context::static_init) {
		default_element_type_ns_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","default-element-type")->getQNameKey();
		context_item_type_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","context-item-type")->getQNameKey();
		context_item_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","context-item")->getQNameKey();
		ordering_mode_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","ordering-mode")->getQNameKey();
		namespaces_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","namespaces")->getQNameKey();
		current_time_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","current-time")->getQNameKey();
		implicit_timezone_key =
			itemFactory_p->createQName(ZORBA_NS,"xqp","implicit-timezone")->getQNameKey();


		dynamic_context::static_init = true;
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

const Item&
dynamic_context::default_element_type_namespace() const
{
	Iterator_t it_h = context_value(default_element_type_ns_key);
	IteratorWrapper iw(it_h);
	Item_t i_h = iw.next();
	return dynamic_cast<const Item&>(*i_h);
}

void dynamic_context::set_default_element_type_namespace(
	Item& nn_p)
{
	Iterator_t it_h = new SingletonIterator(yy::location(), &nn_p);
	keymap.put(default_element_type_ns_key,it_h);
}

void add_namespace(const Item*)
{
}

Iterator_t dynamic_context::namespaces() const
{
	return context_value(namespaces_key);
}

sequence_type_t dynamic_context::context_item_type() const
{
	return xs_anyType; //stub
}

dynamic_context::ordering_mode_t dynamic_context::ordering_mode() const
{
	Iterator_t it_h = context_value(ordering_mode_key);
	IteratorWrapper iw(it_h);
	Item_t i_h = iw.next();
	string mode =i_h->getStringProperty();
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
	Iterator_t it_h = new SingletonIterator(yy::location(), this->itemFactory_p->createString(mode));
	keymap.put(ordering_mode_key, it_h);
}


}	/* namespace xqp */

