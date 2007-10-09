/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: update_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "update_values.h"
#include "runtime/core/item_iterator.h"

using namespace std;
namespace xqp {

// upd_insert_before
// -----------------

insert_before_value::insert_before_value(
	const node* _target_p,
	const vector<const node*>& _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_before_value::~insert_before_value()
{
}

Iterator_t insert_before_value::new_nodes() const
{
	return NULL;
}


// upd_insert_after
// ----------------

insert_after_value::insert_after_value(
	const node* _target_p,
	const vector<const node*>& _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_after_value::~insert_after_value()
{
}

Iterator_t insert_after_value::new_nodes() const
{
	return NULL;
}


// upd_insert_into
// ---------------

insert_into_value::insert_into_value(
	const node* _target_p,
	const vector<const node*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_value::~insert_into_value()
{
}

Iterator_t insert_into_value::new_nodes() const
{
	return NULL;
}


// upd_insert_into_as_first
// ------------------------

insert_into_as_first_value::insert_into_as_first_value(
	const node* _target_p,
	const vector<const node*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_as_first_value::~insert_into_as_first_value()
{
}

Iterator_t insert_into_as_first_value::new_nodes() const
{
	return NULL;
}


// upd_insert_into_as_last
// -----------------------

insert_into_as_last_value::insert_into_as_last_value(
	const node* _target_p,
	const vector<const node*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_as_last_value::~insert_into_as_last_value()
{
}

Iterator_t insert_into_as_last_value::new_nodes() const
{
	return NULL;
}


// upd_insert_attributes
// ---------------------

insert_attributes_value::insert_attributes_value(
	const Item* _target_p,
	const vector<const Item*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_attributes_value::~insert_attributes_value()
{
}

Iterator_t insert_attributes_value::new_nodes() const
{
	return NULL;
}


// upd_delete
// ----------

delete_value::delete_value(
	const Item* _target_p)
:
	update_value(_target_p)
{
}

delete_value::~delete_value()
{
}


// upd_replace_node
// ----------------

replace_node_value::replace_node_value(
	const Item* _target_p,
	const vector<const Item*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

replace_node_value::~replace_node_value()
{
}

Iterator_t replace_node_value::new_nodes() const
{
	return NULL;
}


// upd_replace_value
// -----------------

replace_value_value::replace_value_value(
	const Item* _target_p,
	const string& _content)
:
	update_value(_target_p),
	theContent(_content)
{
}

replace_value_value::~replace_value_value()
{
}


// upd_replace_element_content
// ---------------------------

replace_element_content_value::replace_element_content_value(
	const Item* _target_p,
	const Item* _content)
:
	update_value(_target_p),
	theContent(_content)
{
}

replace_element_content_value::~replace_element_content_value()
{
}


// upd_replace_element_rename
// --------------------------

rename_value::rename_value(
	const Item* _target_p,
	const Item* _name_p)
:
	update_value(_target_p),
	theName(_name_p)
{
}

rename_value::~rename_value()
{
}



} /* namespace xqp */

