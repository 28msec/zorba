/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "update_values.h"

using namespace std;
namespace xqp {

upd_insert_before::upd_insert_before(
	context& _ctx,
	rchandle<node> _target_h,
	vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_before::~upd_insert_before()
{
}



upd_insert_after::upd_insert_after(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_after::~upd_insert_after()
{
}



upd_insert_into::upd_insert_into(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_into::~upd_insert_into()
{
}



upd_insert_into_as_first::upd_insert_into_as_first(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_into_as_first::~upd_insert_into_as_first()
{
}



upd_insert_into_as_last::upd_insert_into_as_last(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_into_as_last::~upd_insert_into_as_last()
{
}



upd_insert_attributes::upd_insert_attributes(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<attribute_node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_insert_attributes::~upd_insert_attributes()
{
}



upd_delete::upd_delete(
	context& _ctx,
	rchandle<node> _target_h)
:
	update_value(_ctx,_target_h)
{
}

upd_delete::~upd_delete()
{
}



upd_replace_node::upd_replace_node(
	context& _ctx,
	rchandle<node> _target_h,
	std::vector<rchandle<node> > & _content_hv)
:
	update_value(_ctx,_target_h),
	content_hv(_content_hv)
{
}

upd_replace_node::~upd_replace_node()
{
}



upd_replace_value::upd_replace_value(
	context& _ctx,
	rchandle<node> _target_h,
	std::string const& _content)
:
	update_value(_ctx,_target_h),
	content(_content)
{
}

upd_replace_value::~upd_replace_value()
{
}



upd_replace_element_content::upd_replace_element_content(
	context& _ctx,
	rchandle<node> _target_h,
	rchandle<text_node> _content_h)
:
	update_value(_ctx,_target_h),
	content_h(_content_h)
{
}

upd_replace_element_content::~upd_replace_element_content()
{
}



upd_rename::upd_rename(
	context& _ctx,
	rchandle<node> _target_h,
	rchandle<QName> _new_name_h)
:
	update_value(_ctx,_target_h),
	new_name_h(_new_name_h)
{
}

upd_rename::~upd_rename()
{
}



} /* namespace xqp */

