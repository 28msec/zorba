/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dynamic_context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "dynamic_context.h"
#include "runtime/item_iterator.h"
#include "zorba/zorba_iterator.h"

using namespace std;
namespace xqp {

bool dynamic_context::static_init = false;
#define ZORBA "http://www.zorba.org/"

void dynamic_context::init(
	value_factory* vfactory_p)
{
	if (!dynamic_context::static_init) {
		default_element_type_ns_key =
			vfactory_p->make_qname(ZORBA,"xqp","default-element-type")->qnamekey();
		context_item_type_key =
			vfactory_p->make_qname(ZORBA,"xqp","context-item-type")->qnamekey();
		context_item_key =
			vfactory_p->make_qname(ZORBA,"xqp","context-item")->qnamekey();
		ordering_mode_key =
			vfactory_p->make_qname(ZORBA,"xqp","ordering-mode")->qnamekey();
		namespaces_key =
			vfactory_p->make_qname(ZORBA,"xqp","namespaces")->qnamekey();
		current_time_key =
			vfactory_p->make_qname(ZORBA,"xqp","current-time")->qnamekey();
		implicit_timezone_key =
			vfactory_p->make_qname(ZORBA,"xqp","implicit-timezone")->qnamekey();
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

const namespace_node*
dynamic_context::default_element_type_namespace() const
{
	item* i_p = context_value(default_element_type_ns_key)->peek();
	return dynamic_cast<namespace_node*>(i_p);
}

void dynamic_context::set_default_element_type_namespace(
	namespace_node* nn_p)
{
	iterator_t it_h = new singleton_iterator(nn_p);
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
	item* i_p = context_value(ordering_mode_key)->peek();
	string mode = i_p->string_value();
	if (mode=="ordered") return ordered;
	return unordered;
}

void dynamic_context::set_context_item_type(sequence_type_t v)
{
}

void dynamic_context::set_ordering_mode(enum ordering_mode_t v)
{
	string mode = (v==ordered?"ordered":"unordered");
	iterator_t it_h = new singleton_iterator(vfactory_p,mode);
	keymap.put(ordering_mode_key, it_h);
}

}	/* namespace xqp */

