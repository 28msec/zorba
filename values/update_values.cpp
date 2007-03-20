/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "update_values.h"
#include "../runtime/iterator.h"

using namespace std;
namespace xqp {

// upd_insert_before
// -----------------

insert_before_value::insert_before_value(
	nodeptr _target_p,
	const vector<nodeptr>& _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_before_value::~insert_before_value()
{
}

iterator_t insert_before_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_insert_after
// ----------------

insert_after_value::insert_after_value(
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_after_value::~insert_after_value()
{
}

iterator_t insert_after_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_insert_into
// ---------------

insert_into_value::insert_into_value(
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_value::~insert_into_value()
{
}

iterator_t insert_into_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_insert_into_as_first
// ------------------------

insert_into_as_first_value::insert_into_as_first_value(
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_as_first_value::~insert_into_as_first_value()
{
}

iterator_t insert_into_as_first_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_insert_into_as_last
// -----------------------

insert_into_as_last_value::insert_into_as_last_value(
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_into_as_last_value::~insert_into_as_last_value()
{
}

iterator_t insert_into_as_last_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_insert_attributes
// ---------------------

insert_attributes_value::insert_attributes_value(
	nodeptr _target_p,
	std::vector<const attribute_node*> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

insert_attributes_value::~insert_attributes_value()
{
}

iterator_t insert_attributes_value::new_nodes()
{
	return new attribute_vector_iterator(content_pv);
}


// upd_delete
// ----------

delete_value::delete_value(
	nodeptr _target_p)
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
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_target_p),
	content_pv(_content_pv)
{
}

replace_node_value::~replace_node_value()
{
}

iterator_t replace_node_value::new_nodes()
{
	return new node_vector_iterator(content_pv);
}


// upd_replace_value
// -----------------

replace_value_value::replace_value_value(
	nodeptr _target_p,
	std::string const& _content)
:
	update_value(_target_p),
	content(_content)
{
}

replace_value_value::~replace_value_value()
{
}


// upd_replace_element_content
// ---------------------------

replace_element_content_value::replace_element_content_value(
	nodeptr _target_p,
	const text_node* _content_p)
:
	update_value(_target_p),
	content_p(_content_p)
{
}

replace_element_content_value::~replace_element_content_value()
{
}


// upd_replace_element_rename
// --------------------------

rename_value::rename_value(
	nodeptr _target_p,
	const qname_value* _new_name_p)
:
	update_value(_target_p),
	new_name_p(_new_name_p)
{
}

rename_value::~rename_value()
{
}



} /* namespace xqp */

