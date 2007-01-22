/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "node_values.h"
#include "../values/xs_primitive_values.h"

#include "stdlib.h"

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE(X) item_iterator((X))


/*...........................................
	:             node                        :
	:.........................................:
*/

nodeid node::get_nodeid() const
{
	return id;
}

enum node::node_kind_t node::node_kind() const
{
	return uninitialized_kind;
}

item_iterator node::attributes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::base_uri(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::children(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::document_uri(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool node::is_id(
	context const& ctx) const
{
	return false;
}

bool node::is_idrefs(
	context const& ctx) const
{
	return false;
}

item_iterator node::namespace_bindings(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::namespace_nodes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool node::nilled(
	context const& ctx) const
{
	return false;
}

item_iterator node::parent(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::type_name(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::node_name(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_type const& node::get_type(
	context const& ctx) const
{
	return any_item_type::get_instance();
}

string node::string_value(
	context const& ctx) const
{
	return "";
}

item_iterator node::unparsed_entity_public_id(
  context const& ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator node::unparsed_entity_system_id(
  context const& ctx,
  string const& entity_name) const
{
	return EMPTY_SEQUENCE(ctx);
}



/*...........................................
	:     document_node::child_iterator       :
	:.........................................:
*/

document_node::child_iterator::child_iterator(
	context const& ctx,
	document_node const* doc_p)
:
	item_iterator(ctx),
	parent_p(doc_p)
{
}
	
document_node::child_iterator::~child_iterator()
{
}

void document_node::child_iterator::open()
{
	child_it = parent_p->child_hv.begin();
	it_end = parent_p->child_hv.end();
}

rchandle<item> document_node::child_iterator::next()
{
	rchandle<node> v = *child_it++;
	rchandle<item> i = dynamic_cast<item*>(&*v);
	return i;
}

bool document_node::child_iterator::done()
{
	return child_it == it_end;
}

void document_node::child_iterator::rewind()
{
	child_it = parent_p->child_hv.begin();
}



/*...........................................
	:            document_node                :
	:.........................................:
*/

item_iterator document_node::base_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

item_iterator document_node::children(
	context const& ctx) const
{
	return child_iterator(ctx,this);
}

item_iterator document_node::document_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,docuri);
}

item_iterator document_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

string document_node::string_value(
	context const& ctx) const
{
	ostringstream oss;
	vector<rchandle<node> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << (*it)->string_value(ctx);
	}
	return oss.str();
}

item_iterator document_node::unparsed_entity_public_id(
	context const& ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE(ctx);
}

item_iterator document_node::unparsed_entity_system_id(
	context const& ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return EMPTY_SEQUENCE(ctx);
}

void document_node::add_element_node(
	rchandle<element_node> enode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*enode_h));
}

void document_node::add_text_node(
	rchandle<text_node> tnode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*tnode_h));
}

void document_node::add_comment_node(
	rchandle<comment_node> cnode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*cnode_h));
}

void document_node::add_pi_node(
	rchandle<pi_node> pinode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*pinode_h));
}

void document_node::add_text_node(
	nodeid id,
	string const& text)
{
	text_node* tnode_p = new text_node(id,text,this);
	child_hv.push_back(dynamic_cast<node*>(tnode_p));
}

document_node::document_node(
	nodeid _id,
	string const& _baseuri,
	string const& _docuri)
:
	node(id),
	baseuri(_baseuri),
	entitymap(1024,0.6),
	docuri(_docuri)
{
}

ostream& document_node::put(ostream& os, context const& ctx) const
{
	os << "<?xml version=\"1.0\"?>\n";
	vector<rchandle<node> >::const_iterator child_it = child_hv.begin();
	for (; child_it!=child_hv.end(); ++child_it) {
		(*child_it)->put(os,ctx);
	}
	return os;
}



/*...........................................
	:     element_node::child_iterator        :
	:.........................................:
*/

element_node::child_iterator::child_iterator(
	context const& ctx,
	element_node const* elem_p)
:
	item_iterator(ctx),
	parent_p(elem_p)
{
}
	
element_node::child_iterator::~child_iterator()
{
}

void element_node::child_iterator::open()
{
	child_it = parent_p->child_hv.begin();
	it_end = parent_p->child_hv.end();
}

rchandle<item> element_node::child_iterator::next()
{
	rchandle<node> v = *child_it++;
	rchandle<item> i = dynamic_cast<item*>(&*v);
	return i;
}

bool element_node::child_iterator::done()
{
	return child_it == it_end;
}

void element_node::child_iterator::rewind()
{
	child_it = parent_p->child_hv.begin();
}



/*...........................................
	:     element_node::attr_iterator         :
	:.........................................:
*/

element_node::attr_iterator::attr_iterator(
	context const& ctx,
	element_node const* elem_p)
:
	item_iterator(ctx),
	parent_p(elem_p)
{
}
	
element_node::attr_iterator::~attr_iterator()
{
}

void element_node::attr_iterator::open()
{
	attr_it = parent_p->attr_hv.begin();
	it_end = parent_p->attr_hv.end();
}

rchandle<item> element_node::attr_iterator::next()
{
	return &*(*attr_it++);
}

bool element_node::attr_iterator::done()
{
	return attr_it == it_end;
}

void element_node::attr_iterator::rewind()
{
	attr_it = parent_p->attr_hv.begin();
}



/*...........................................
	:            element nodes                :
	:.........................................:
*/

item_iterator element_node::attributes(
	context const& ctx) const
{
	return attr_iterator(ctx,this);
}

item_iterator element_node::base_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

item_iterator element_node::children(
	context const& ctx) const
{
	return child_iterator(ctx,this);
}

bool element_node::is_id(
	context const& ctx) const
{
	return id_b;
}

bool element_node::is_idrefs(
	context const& ctx) const
{
	return idrefs_b;
}

item_iterator element_node::namespace_bindings(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_iterator element_node::namespace_nodes(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

bool element_node::nilled(
	context const& ctx) const
{
	return nilled_b;
}

item_iterator element_node::node_name(
	context const& ctx) const
{
	return singleton_iterator(ctx,name_h->describe(ctx));
}

item_iterator element_node::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,&*parent_h);
}

item_iterator element_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
item_type const& element_node::get_type(
	context const& ctx) const
{
	return type;
}

string element_node::string_value(
	context const& ctx) const
{
	ostringstream oss;
	vector<rchandle<node> >::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << (*it)->string_value(ctx);
	}
	return oss.str();
}

void element_node::add_element_node(
	rchandle<element_node> enode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*enode_h));
}

void element_node::add_text_node(
	rchandle<text_node> tnode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*tnode_h));
}

void element_node::add_text_node(
	nodeid id,
	string const& text)
{
	text_node* tnode_p = new text_node(id,text,this);
	child_hv.push_back(dynamic_cast<node*>(tnode_p));
}

void element_node::add_comment_node(
	rchandle<comment_node> cnode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*cnode_h));
}

void element_node::add_pi_node(
	rchandle<pi_node> pinode_h)
{
	child_hv.push_back(dynamic_cast<node*>(&*pinode_h));
}

void element_node::add_attribute_node(
	rchandle<attribute_node> anode_h)
{
	attr_hv.push_back(dynamic_cast<node*>(&*anode_h));
}

void element_node::add_ns_node(
	rchandle<ns_node> nsnode_h)
{
	ns_hv.push_back(dynamic_cast<node*>(&*nsnode_h));
}

element_node::element_node(
	nodeid _id,
	string const& _baseuri,
	rchandle<QName> _name_h,
	rchandle<node> _parent_h)
:
	node(_id),
	baseuri(_baseuri),
	name_h(_name_h),
	parent_h(_parent_h)
{
}

ostream& element_node::put(ostream& os, context const& ctx) const
{
	os << '<';
	name_h->put(os,ctx);

	vector<rchandle<node> >::const_iterator ns_it = ns_hv.begin();
	for (; ns_it!=ns_hv.end(); ++ns_it) {
		os << ' ';
		(*ns_it)->put(os,ctx);
	}

	vector<rchandle<node> >::const_iterator attr_it = attr_hv.begin();
	for (; attr_it!=attr_hv.end(); ++attr_it) {
		os << ' ';
		(*attr_it)->put(os,ctx);
	}

	vector<rchandle<node> >::const_iterator child_it = child_hv.begin();
	vector<rchandle<node> >::const_iterator child_en = child_hv.end();

	if (child_it==child_en) {
		os << "/>";
	}
	else {
		os << '>';
		for (; child_it!=child_en; ++child_it) {
			(*child_it)->put(os,ctx);
		}
		os << "</"; name_h->put(os,ctx) << '>';
	}

	return os;
}



/*...........................................
	:           attribute nodes               :
	:.........................................:
*/

item_iterator attribute_node::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

bool attribute_node::is_id(
	context const& ctx) const
{
	return id_b;
}

bool attribute_node::is_idrefs(
	context const& ctx) const
{
	return idrefs_b;
}

item_iterator attribute_node::node_name(
	context const& ctx) const
{
	return singleton_iterator(ctx,name_h->describe(ctx));
}

item_iterator attribute_node::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

item_iterator attribute_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}

item_type const& attribute_node::get_type(
	context const& ctx) const
{
	return type;
}

string attribute_node::string_value(
	context const& ctx) const
{
	return val;
}

attribute_node::attribute_node(
	nodeid _id,
	rchandle<QName> _name_h,
	string const& _val,
	rchandle<element_node> _parent_h)
:
	node(_id),
	name_h(_name_h),
	val(_val),
	parent_h(_parent_h)
{
}

ostream& attribute_node::put(ostream& os, context const& ctx) const
{
	name_h->put(os,ctx);
	return os << "=\"" << val << '"';
}



/*...........................................
	:          namespace nodes                :
	:.........................................:
*/

item_iterator ns_node::node_name(
	context const& ctx) const
{
	if (prefix.length()==0) return EMPTY_SEQUENCE(ctx);
	return singleton_iterator(ctx,
					new QName(QName::qn_ns,prefix,""));
}

item_iterator ns_node::parent(
	context const& ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

item_iterator ns_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
string ns_node::string_value(
	context const& ctx) const
{
	return uri;
}

ns_node::ns_node(
	nodeid _id,
	string const& _prefix,
	string const& _uri,
	rchandle<element_node> _parent_h)
:
	node(_id),
	prefix(_prefix),
	uri(_uri),
	parent_h(_parent_h)
{
}

ostream& ns_node::put(ostream& os, context const& ctx) const
{
	return os << "xmlns:" << prefix << "=\"" << uri << '"';
}



	
/*...........................................
	:    processing instruction nodes         :
	:.........................................:
*/

item_iterator pi_node::base_uri(
	context const& ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

item_iterator pi_node::node_name(
	context const& ctx) const
{
	return singleton_iterator(ctx,
			new QName(QName::qn_pi, target));
}

item_iterator pi_node::parent(
context const& ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

item_iterator pi_node::typed_value(
	context const& ctx) const
{
	return singleton_iterator(ctx,
					new xs_string_value(content));
}
	
string pi_node::string_value(
	context const& ctx) const
{
	return content;
}


pi_node::pi_node(
	nodeid _id,
	string const& _target,
	string const& _content,
	string const& _baseuri,
	rchandle<element_node> _parent_h)
:
	node(_id),
	target(_target),
	content(_content),
	baseuri(_baseuri),
	parent_h(_parent_h)
{
}

ostream& pi_node::put(ostream& os, context const& ctx) const
{
	return os << "<?" << target << " " << content << "?>";
}



/*...........................................
	:          comment nodes                  :
	:.........................................:
*/

item_iterator comment_node::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator comment_node::parent(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<node*>(&*parent_h))
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator comment_node::typed_value(
	context const& ctx) const
{
	return singleton_iterator(ctx,content);
}
	
string comment_node::string_value(
	context const& ctx) const
{
	return content;
}

comment_node::comment_node(
	nodeid _nodeid,
	string const& _content,
	rchandle<element_node> _parent_h)
:
	node(_nodeid),
	content(_content),
	parent_h(_parent_h)
{
}

ostream& comment_node::put(ostream& os, context const& ctx) const
{
	return os << "<!--" << content << "-->";
}



/*...........................................
	:             text nodes                  :
	:.........................................:
*/

item_iterator text_node::base_uri(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator text_node::parent(
	context const& ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<node*>(&*parent_h))
										 : EMPTY_SEQUENCE(ctx);
}

item_iterator text_node::typed_value(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
item_iterator text_node::node_name(
	context const& ctx) const
{
	return EMPTY_SEQUENCE(ctx);
}
	
string text_node::string_value(
	context const& ctx) const
{
	return content;
}

text_node::text_node(
	nodeid _nodeid,
	string const& _content,
	rchandle<node> _parent_h)
:
	node(_nodeid),
	content(_content),
	parent_h(_parent_h)
{
}

ostream& text_node::put(ostream& os, context const& ctx) const
{
	return os << content;
}



}	/* namespace xqp */
