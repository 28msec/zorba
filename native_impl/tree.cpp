/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tree.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "tree.h"

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE item_iterator()


////////////////////////////////
//	xqp_node
////////////////////////////////
	
item_iterator xqp_node::attributes(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::base_uri(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::children(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::document_uri(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

bool xqp_node::is_id(
	context const* ctx) const
{
	return false;
}

bool xqp_node::is_idrefs(
	context const* ctx) const
{
	return false;
}

item_iterator xqp_node::namespace_bindings(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::namespace_nodes(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::nilled(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::parent(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_type const& xqp_node::get_type(
	context const* ctx) const
{
	return any_item_type::get_instance();
}

string xqp_node::string_value(
	context const* ctx) const
{
	return "";
}

item_iterator xqp_node::unparsed_entity_public_id(
  context const* ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE;
}

item_iterator xqp_node::unparsed_entity_system_id(
  context const* ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE;
}



////////////////////////////////
//	xqp_document
////////////////////////////////
	
item_iterator xqp_document::base_uri(
	context const* ctx) const
{
	return new singleton_iterator(ctx,baseuri);
}

item_iterator xqp_document::children(
	context const* ctx) const
{
	return new vector_iterator(ctx,child_hv);
}

item_iterator xqp_document::document_uri(
	context const* ctx) const
{
	return new singleton_iterator(ctx,docuri);
}

item_iterator xqp_document::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE:
}

string xqp_document::string_value(
	context const* ctx) const
{
	ostringstream oss;
	vector<rchandle<snode> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << it->string_value();
	}
	return oss.str();
}
	
item_iterator xqp_document::unparsed_entity_public_id(
	context const* ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return new singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE;
}

item_iterator xqp_document::unparsed_entity_system_id(
	context const* ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return new singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE;
}



////////////////////////////////
//	xqp_element
////////////////////////////////

item_iterator xqp_element::attributes(
	context const* ctx) const
{
	return new vector_iterator(ctx,attr_hv);
}

item_iterator xqp_element::base_uri(
	context const* ctx) const
{
	return new singleton_iterator(ctx,baseuri);
}

item_iterator xqp_element::children(
	context const* ctx) const
{
	return new vector_iterator(ctx,child_hv);
}

bool xqp_element::is_id(
	context const* ctx) const
{
	return new singleton_iterator(ctx,id_b);
}

bool xqp_element::is_idrefs(
	context const* ctx) const
{
	return new singleton_iterator(ctx,idrefs_b);
}

item_iterator xqp_element::namespace_bindings(
	context const* ctx) const
{
	return new nspair_iterator(ctx,ns_hv);
}

item_iterator xqp_element::namespace_nodes(
	context const* ctx) const
{
	return new vector_iterator(ctx,ns_hv);
}

item_iterator xqp_element::nilled(
	context const* ctx) const
{
	return new singleton_iterator(ctx,nilled_b);
}

item_iterator xqp_element::node_name(
	context const* ctx) const
{
	return new singleton_iterator(ctx,nodename);
}

item_iterator xqp_element::parent(
	context const* ctx) const
{
	return new singleton_iterator(ctx,parent_h);
}

item_iterator xqp_element::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}
	
enum type::type_name_t xqp_element::type_name(
	context const* ctx) const
{
	return typename;
}

string element_node::string_value(
	context const* ctx) const
{
	ostringstream oss;
	vector<rchandle<snode> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << it->string_value();
	}
	return oss.str();
}

void xqp_element::add_element_node(
	rchandle<xqp_element> enode_h)
{
	child_hv.push_back(dynamic_cast<snode*>(&*enode_h));
}

void xqp_element::add_text_node(
	rchandle<text_snode> tnode_h)
{
	child_hv.push_back(dynamic_cast<snode*>(&*tnode_h));
}

void xqp_element::add_comment_node(
	rchandle<comment_snode> cnode_h)
{
	child_hv.push_back(dynamic_cast<snode*>(&*cnode_h));
}

void xqp_element::add_pi_node(
	rchandle<comment_snode> pinode_h)
{
	child_hv.push_back(dynamic_cast<snode*>(&*pinode_h));
}

void xqp_element::add_text_node(
	string const& text)
{
	rchandle<text_snode> tnode_h =
		new text_snode(nodeid_allocator::next(),text,this);
	child_hv.push_back(dynamic_cast<snode*>(&*tnode_h));
}

void xqp_element::add_attribute_node(
	rchandle<attribute_snode> anode_h)
{
	attr_hv.push_back(anode_h);
}

void xqp_element::add_ns_node(
	rchandle<ns_snode> nsnode_h)
{
	ns_hv.push_back(anode_h);
}

xqp_element(
	xqp_nodeid _id,
	string const& _baseuri,
	string const& _nodename,
	rchandle<xqp_node> _parent)
:
	xqp_node(_id),
	baseuri(_baseuri),
	nodename(_nodename),
	parent(_parent)
{
}

////////////////////////////////
//	xqp_attribute
////////////////////////////////

item_iterator xqp_attribute::base_uri(
	context const* ctx) const
{
	return (parent!=NULL) parent->base_uri(ctx) : NULL;
}

bool xqp_attribute::is_id(
	context const* ctx) const;
{
	return new singleton_iterator(ctx,id_b);
}

bool xqp_attribute::is_idrefs(
	context const* ctx) const
{
	return new singleton_iterator(ctx,idrefs_b);
}

item_iterator xqp_attribute::node_name(
	context const* ctx) const
{
	return new singleton_iterator(ctx,nodename);
}

item_iterator xqp_attribute::parent(
	context const* ctx) const
{
	return new singleton_iterator(ctx,parent_h);
}

item_iterator xqp_attribute::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}

item_type const& get_type(
	context const* ctx) const
{
	return typename;
}

string xqp_attribute::string_value(
	context const* ctx) const
{
	return stringval;
}

xqp_namespace(
	xqp_nodeid _id,
	string cosnt& _prefix;
	string const& _uri;
	rchandle<xqp_element> _parent)
:
	xqp_node(_id),
	prefix(_prefix),
	uri(_uri),
	parent(_parent)
{
}


////////////////////////////////
//	xqp_namespace nodes
////////////////////////////////

item_iterator xqp_namespace::node_name(
	context const* ctx) const
{
	if (prefix.length()==0) return EMPTY_SEQUENCE;
	return new singleton_iterator(ctx,
					new QName(QName::qn_ns,prefix,""));
}

item_iterator xqp_namespace::parent(
	context const* ctx) const
{
	return new singleton_iterator(ctx,parent);
}

item_iterator xqp_namespace::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}
	
string xqp_namespace::string_value(
	context const* ctx) const
{
	return uri;
}

xqp_namespace::xqp_namespace(
	xqp_nodeid _id,
	string const& _prefix;
	string const& _uri;
	rchandle<xqp_element> _parent_h)
:
	xqp_node(_id),
	prefix(_prefix),
	uri(_uri),
	parent_h(_parent_h)
{
}



////////////////////////////////
//	xqp_pi
////////////////////////////////
	
item_iterator xqp_pi::base_uri(
	context const* ctx) const
{
	return new singleton_iterator(ctx,baseuri);
}

rchandle<QName> xqp_pi::node_name(
	context const* ctx) const
{
	return new QName(QName::qn_pi, target);
}

item_iterator xqp_pi::parent(
context const* ctx) const
{
	return new singleton_iterator(ctx,parent_h);
}

item_iterator xqp_pi::typed_value(
	context const* ctx) const
{
	return new singleton_iterator(ctx,
					new xs_string(content));
}
	
string string_value(
	context const* ctx) const
{
	return content;
}


xqp_pi::xqp_pi(
	xqp_nodeid _id,
	string const& _target,
	string const& _content,
	string const& _baseuri,
	rchandle<xqp_element _parent_h)
:
	xqp_node(_id),
	target(_target),
	content(_content),
	baseuri(_baseuri),
	parent_h(_parent_h)
{
}



/*______________________________________________________________________
|
| 6.6 Text Node 
|_______________________________________________________________________*/

item_iterator text_snode::base_uri(
	context const* ctx) const
{
	return (parent!=NULL) ? parent->base_uri(ctx) : NULL;
}

item_iterator text_snode::parent(
	context const* ctx) const
{
	return
		(parent!=NULL) ? new singleton_iterator(ctx,parent) : NULL;
}

enum type::type_name_t text_snode::type_name(
	context const* ctx) const
{
	return type::UNTYPED_ATOMIC;
}

item_iterator text_snode::typed_value(
	context const* ctx) const
{
	return EMPTY_SEQUENCE;
}
	
string text_snode::string_value(
	context const* ctx) const
{
	return content;
}

text_snode::text_snode(
	uint64_t _nodeid,
	string const& _content,
	rchandle<element_snode> _parent_h)
:
	snode(_nodeid),
	content(_content),
	parent_h(_parent_h)
{
}



}	/* namespace xqp */
