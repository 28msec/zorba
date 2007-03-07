/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "update_values.h"

using namespace std;
namespace xqp {

// upd_insert_before

upd_insert_before::upd_insert_before(
	context& _ctx,
	nodeptr _target_p,
	vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_before::~upd_insert_before()
{
}



// upd_insert_after

upd_insert_after::upd_insert_after(
	context& _ctx,
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_after::~upd_insert_after()
{
}



// upd_insert_into

upd_insert_into::upd_insert_into(
	context& _ctx,
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_into::~upd_insert_into()
{
}



// upd_insert_into_as_first

upd_insert_into_as_first::upd_insert_into_as_first(
	context& _ctx,
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_into_as_first::~upd_insert_into_as_first()
{
}



// upd_insert_into_as_last

upd_insert_into_as_last::upd_insert_into_as_last(
	context& _ctx,
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_into_as_last::~upd_insert_into_as_last()
{
}



// upd_insert_attributes

upd_insert_attributes::upd_insert_attributes(
	context& _ctx,
	nodeptr _target_p,
	std::vector<attribute_node const*> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_insert_attributes::~upd_insert_attributes()
{
}



// upd_delete

upd_delete::upd_delete(
	context& _ctx,
	nodeptr _target_p)
:
	update_value(_ctx,_target_p)
{
}

upd_delete::~upd_delete()
{
}



// upd_replace_node

upd_replace_node::upd_replace_node(
	context& _ctx,
	nodeptr _target_p,
	std::vector<nodeptr> & _content_pv)
:
	update_value(_ctx,_target_p),
	content_pv(_content_pv)
{
}

upd_replace_node::~upd_replace_node()
{
}



// upd_replace_value

upd_replace_value::upd_replace_value(
	context& _ctx,
	nodeptr _target_p,
	std::string const& _content)
:
	update_value(_ctx,_target_p),
	content(_content)
{
}

upd_replace_value::~upd_replace_value()
{
}



// upd_replace_element_content

upd_replace_element_content::upd_replace_element_content(
	context& _ctx,
	nodeptr _target_p,
	text_node const* _content_p)
:
	update_value(_ctx,_target_p),
	content_p(_content_p)
{
}

upd_replace_element_content::~upd_replace_element_content()
{
}



// upd_replace_element_rename

upd_rename::upd_rename(
	context& _ctx,
	nodeptr _target_p,
	qname_value const* _new_name_p)
:
	update_value(_ctx,_target_p),
	new_name_p(_new_name_p)
{
}

upd_rename::~upd_rename()
{
}



} /* namespace xqp */

