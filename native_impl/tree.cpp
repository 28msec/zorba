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
#include "../values/xs_primitive_values.h"

#include "stdlib.h"

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE(X) item_iterator((X))


////////////////////////////////
//	xqp_node
////////////////////////////////
/*
item_iterator xqp_node::attributes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::base_uri(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::children(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::document_uri(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool xqp_node::is_id(
	context const& ctx) const
{
	return false;
}

bool xqp_node::is_idrefs(
	context const& ctx) const
{
	return false;
}

item_iterator xqp_node::namespace_bindings(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::namespace_nodes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool xqp_node::nilled(
	context const& ctx) const
{
	return false;
}

item_iterator xqp_node::parent(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_type const& xqp_node::get_type(
	context const& ctx) const
{
	return any_item_type::get_instance();
}

string xqp_node::string_value(
	context const& ctx) const
{
	return "";
}

item_iterator xqp_node::unparsed_entity_public_id(
  context const& ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_node::unparsed_entity_system_id(
  context const& ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE(ctx);
}
*/

////////////////////////////////
//	document::child_iterator
////////////////////////////////

xqp_document::child_iterator::child_iterator(
	context const& ctx,
	xqp_document const* doc_p)
:
	item_iterator(ctx),
	parent_p(doc_p)
{
}
	
xqp_document::child_iterator::~child_iterator()
{
}

void xqp_document::child_iterator::open()
{
	child_it = parent_p->child_hv.begin();
	it_end = parent_p->child_hv.end();
}

rchandle<item> xqp_document::child_iterator::next()
{
	rchandle<xqp_node> v = *child_it++;
	rchandle<item> i = dynamic_cast<item*>(&*v);
	return i;
}

bool xqp_document::child_iterator::done()
{
	return child_it == it_end;
}

void xqp_document::child_iterator::rewind()
{
	child_it = parent_p->child_hv.begin();
}


////////////////////////////////
//	xqp_document
////////////////////////////////

item_iterator xqp_document::base_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

item_iterator xqp_document::children(
	context const& ctx) const
{
	return child_iterator(ctx,this);
}

item_iterator xqp_document::document_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,docuri);
}

item_iterator xqp_document::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

string xqp_document::string_value(
	context const& ctx) const
{
	ostringstream oss;
	vector<rchandle<xqp_node> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << (*it)->string_value(ctx);
	}
	return oss.str();
}
	
item_iterator xqp_document::unparsed_entity_public_id(
	context const& ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_document::unparsed_entity_system_id(
	context const& ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE(ctx);
}



////////////////////////////////
//	element::child_iterator
////////////////////////////////

xqp_element::child_iterator::child_iterator(
	context const& ctx,
	xqp_element const* elem_p)
:
	item_iterator(ctx),
	parent_p(elem_p)
{
}
	
xqp_element::child_iterator::~child_iterator()
{
}

void xqp_element::child_iterator::open()
{
	child_it = parent_p->child_hv.begin();
	it_end = parent_p->child_hv.end();
}

rchandle<item> xqp_element::child_iterator::next()
{
	rchandle<xqp_node> v = *child_it++;
	rchandle<item> i = dynamic_cast<item*>(&*v);
	return i;
}

bool xqp_element::child_iterator::done()
{
	return child_it == it_end;
}

void xqp_element::child_iterator::rewind()
{
	child_it = parent_p->child_hv.begin();
}


////////////////////////////////
//	element::attr_iterator
////////////////////////////////

xqp_element::attr_iterator::attr_iterator(
	context const& ctx,
	xqp_element const* elem_p)
:
	item_iterator(ctx),
	parent_p(elem_p)
{
}
	
xqp_element::attr_iterator::~attr_iterator()
{
}

void xqp_element::attr_iterator::open()
{
	attr_it = parent_p->attr_hv.begin();
	it_end = parent_p->attr_hv.end();
}

rchandle<item> xqp_element::attr_iterator::next()
{
	rchandle<xqp_attribute> v = *attr_it++;
	xqp_node* u = dynamic_cast<xqp_node*>(&*v);
	return u;
}

bool xqp_element::attr_iterator::done()
{
	return attr_it == it_end;
}

void xqp_element::attr_iterator::rewind()
{
	attr_it = parent_p->attr_hv.begin();
}


////////////////////////////////
//	xqp_element
////////////////////////////////

item_iterator xqp_element::attributes(
	context const& ctx) const
{
	return attr_iterator(ctx,this);
}

item_iterator xqp_element::base_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

item_iterator xqp_element::children(
	context const& ctx) const
{
	return child_iterator(ctx,this);
}

bool xqp_element::is_id(
	context const& ctx) const
{
	return id_b;
}

bool xqp_element::is_idrefs(
	context const& ctx) const
{
	return idrefs_b;
}

item_iterator xqp_element::namespace_bindings(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_element::namespace_nodes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool xqp_element::nilled(
	context const& ctx) const
{
	return nilled_b;
}

item_iterator xqp_element::node_name(
	context const& ctx) const
{
	return singleton_iterator(ctx,nodename);
}

item_iterator xqp_element::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,&*parent_h);
}

item_iterator xqp_element::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
string xqp_element::string_value(
	context const& ctx) const
{
	ostringstream oss;
	vector<rchandle<xqp_node> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << (*it)->string_value(ctx);
	}
	return oss.str();
}

void xqp_element::add_element_node(
	rchandle<xqp_element> enode_h)
{
	child_hv.push_back(dynamic_cast<xqp_node*>(&*enode_h));
}

void xqp_element::add_text_node(
	rchandle<xqp_text> tnode_h)
{
	child_hv.push_back(dynamic_cast<xqp_node*>(&*tnode_h));
}

void xqp_element::add_comment_node(
	rchandle<xqp_comment> cnode_h)
{
	child_hv.push_back(dynamic_cast<xqp_node*>(&*cnode_h));
}

void xqp_element::add_pi_node(
	rchandle<xqp_pi> pinode_h)
{
	child_hv.push_back(dynamic_cast<xqp_node*>(&*pinode_h));
}

void xqp_element::add_text_node(
	string const& text)
{
	rchandle<xqp_text> tnode_h =
		new xqp_text(rand(),text,this);
	child_hv.push_back(dynamic_cast<xqp_node*>(&*tnode_h));
}

void xqp_element::add_attribute_node(
	rchandle<xqp_attribute> anode_h)
{
	attr_hv.push_back(anode_h);
}

void xqp_element::add_ns_node(
	rchandle<xqp_ns> nsnode_h)
{
	ns_hv.push_back(nsnode_h);
}

xqp_element::xqp_element(
	xqp_nodeid _id,
	string const& _baseuri,
	string const& _nodename,
	rchandle<xqp_node> _parent_h)
:
	xqp_node(_id),
	baseuri(_baseuri),
	nodename(_nodename),
	parent_h(_parent_h)
{
}


////////////////////////////////
//	xqp_attribute
////////////////////////////////

item_iterator xqp_attribute::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

bool xqp_attribute::is_id(
	context const& ctx) const
{
	return id_b;
}

bool xqp_attribute::is_idrefs(
	context const& ctx) const
{
	return idrefs_b;
}

item_iterator xqp_attribute::node_name(
	context const& ctx) const
{
	return singleton_iterator(ctx,name->describe());
}

item_iterator xqp_attribute::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<xqp_node*>(&*parent_h));
}

item_iterator xqp_attribute::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_type const& xqp_attribute::get_type(
	context const& ctx) const
{
	return type;
}

string xqp_attribute::string_value(
	context const& ctx) const
{
	return val;
}

xqp_attribute::xqp_attribute(
	xqp_nodeid _id,
	rchandle<QName> _name,
	string const& _val,
	rchandle<xqp_element> _parent_h)
:
	xqp_node(_id),
	name(_name),
	val(_val),
	parent_h(_parent_h)
{
}


////////////////////////////////
//	xqp_ns nodes
////////////////////////////////

item_iterator xqp_ns::node_name(
	context const& ctx) const
{
	if (prefix.length()==0) return EMPTY_SEQUENCE(ctx);
	return singleton_iterator(ctx,
					new QName(QName::qn_ns,prefix,""));
}

item_iterator xqp_ns::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,parent_h);
}

item_iterator xqp_ns::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
string xqp_ns::string_value(
	context const& ctx) const
{
	return uri;
}

xqp_ns::xqp_ns(
	xqp_nodeid _id,
	string const& _prefix,
	string const& _uri,
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
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

rchandle<QName> xqp_pi::node_name(
	context const& ctx) const
{
	return new QName(QName::qn_pi, target);
}

item_iterator xqp_pi::parent(
context const& ctx) const
{
	return singleton_iterator(ctx,parent_h);
}

item_iterator xqp_pi::typed_value(
	context const& ctx) const
{
	return singleton_iterator(ctx,
					new xs_string_value(content));
}
	
string xqp_pi::string_value(
	context const& ctx) const
{
	return content;
}


xqp_pi::xqp_pi(
	xqp_nodeid _id,
	string const& _target,
	string const& _content,
	string const& _baseuri,
	rchandle<xqp_element> _parent_h)
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

item_iterator xqp_comment::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_comment::parent(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<xqp_node*>(&*parent_h))
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_comment::typed_value(
	context const& ctx) const
{
	return singleton_iterator(ctx,content);
}
	
string xqp_comment::string_value(
	context const& ctx) const
{
	return content;
}

xqp_comment::xqp_comment(
	xqp_nodeid _nodeid,
	string const& _content,
	rchandle<xqp_element> _parent_h)
:
	xqp_node(_nodeid),
	content(_content),
	parent_h(_parent_h)
{
}



/*______________________________________________________________________
|
| 6.7 Text Node 
|_______________________________________________________________________*/

item_iterator xqp_text::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_text::parent(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<xqp_node*>(&*parent_h))
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator xqp_text::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
item_iterator xqp_text::node_name(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
string xqp_text::string_value(
	context const& ctx) const
{
	return content;
}

xqp_text::xqp_text(
	xqp_nodeid _nodeid,
	string const& _content,
	rchandle<xqp_element> _parent_h)
:
	xqp_node(_nodeid),
	content(_content),
	parent_h(_parent_h)
{
}



}	/* namespace xqp */
