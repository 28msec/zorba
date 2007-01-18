/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "node_types.h"

using namespace std;
namespace xqp {


////////////////////////////////
//	node_type
////////////////////////////////

node_type const& node_type::get_instance()
{
	return node_type::the_instance;
}

bool node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* node_type::get_atomized_type() const
{
	return NULL;
}

std::string node_type::describe() const
{
	return "node_type";
}



////////////////////////////////
//	document_node_type
////////////////////////////////

document_node_type const& document_node_type::get_instance()
{
	return document_node_type::the_instance;
}

bool document_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* document_node_type::get_atomized_type() const
{
	return NULL;
}

std::string document_node_type::describe() const
{
	return "document_node_type";
}



////////////////////////////////
//	element_node_type
////////////////////////////////

element_node_type const& element_node_type::get_instance()
{
	return element_node_type::the_instance;
}

bool element_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* element_node_type::get_atomized_type() const
{
	return NULL;
}

std::string element_node_type::describe() const
{
	return "element_node_type";
}



////////////////////////////////
//	comment_node_type
////////////////////////////////

comment_node_type const& comment_node_type::get_instance()
{
	return comment_node_type::the_instance;
}

bool comment_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* comment_node_type::get_atomized_type() const
{
	return NULL;
}

std::string comment_node_type::describe() const
{
	return "comment_node_type";
}



////////////////////////////////
//	attribute_node_type
////////////////////////////////

attribute_node_type const& attribute_node_type::get_instance()
{
	return attribute_node_type::the_instance;
}

bool attribute_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* attribute_node_type::get_atomized_type() const
{
	return NULL;
}

std::string attribute_node_type::describe() const
{
	return "attribute_node_type";
}



////////////////////////////////
//	ns_node_type
////////////////////////////////

ns_node_type const& ns_node_type::get_instance()
{
	return ns_node_type::the_instance;
}

bool ns_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* ns_node_type::get_atomized_type() const
{
	return NULL;
}

std::string ns_node_type::describe() const
{
	return "ns_node_type";
}



////////////////////////////////
//	pi_node_type
////////////////////////////////

pi_node_type const& pi_node_type::get_instance()
{
	return pi_node_type::the_instance;
}

bool pi_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* pi_node_type::get_atomized_type() const
{
	return NULL;
}

std::string pi_node_type::describe() const
{
	return "pi_node_type";
}



////////////////////////////////
//	text_node_type
////////////////////////////////

text_node_type const& text_node_type::get_instance()
{
	return text_node_type::the_instance;
}

bool text_node_type::matches(item const*, context const*) const
{
	return false;
}

xs_anyAtomicType const* text_node_type::get_atomized_type() const
{
	return NULL;
}

std::string text_node_type::describe() const
{
	return "text_node_type";
}


}	/* namespace xqp */

