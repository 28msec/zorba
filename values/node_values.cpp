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
#include "xs_primitive_values.h"
#include "../context/context.h"

#include "stdlib.h"

using namespace std;
namespace xqp {


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

rchandle<item_iterator> node::attributes(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::base_uri(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::children(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::document_uri(
	context & ctx) const
{
	return new item_iterator(ctx);
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

rchandle<item_iterator> node::namespace_bindings(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::namespace_nodes(
	context & ctx) const
{
	return new item_iterator(ctx);
}

bool node::nilled(
	context const& ctx) const
{
	return false;
}

rchandle<item_iterator> node::parent(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::type_name(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::node_name(
	context & ctx) const
{
	return new item_iterator(ctx);
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

rchandle<item_iterator> node::unparsed_entity_public_id(
  context & ctx,
  string const& entity_name) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> node::unparsed_entity_system_id(
  context & ctx,
  string const& entity_name) const
{
	return new item_iterator(ctx);
}



/*...........................................
	:     document_node::child_iterator       :
	:.........................................:
*/

document_node::child_iterator::child_iterator(
	context & ctx,
	document_node const* doc_p)
:
	item_iterator(ctx),
	parent_p(doc_p)
{
	child_it = parent_p->child_hv.begin();
	it_end = parent_p->child_hv.end();
}
	
document_node::child_iterator::~child_iterator()
{
}

rchandle<item> document_node::child_iterator::next()
{
	nodeid id = *child_it++;
	rchandle<node> v_h = ctx.get_node(id);
	rchandle<item> i_h = dynamic_cast<item*>(&*v_h);
	return i_h;
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

rchandle<item_iterator> document_node::base_uri(
	context & ctx) const
{
	return new singleton_iterator(ctx,baseuri);
}

rchandle<item_iterator> document_node::children(
	context & ctx) const
{
	return new child_iterator(ctx,this);
}

rchandle<item_iterator> document_node::document_uri(
	context & ctx) const
{
	return new singleton_iterator(ctx,docuri);
}

rchandle<item_iterator> document_node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
}

string document_node::string_value(
	context const& ctx) const
{
	ostringstream oss;
	vector<nodeid>::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << ctx.get_node((*it))->string_value(ctx);
	}
	return oss.str();
}

rchandle<item_iterator> document_node::unparsed_entity_public_id(
	context & ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return new item_iterator(ctx);
}

rchandle<item_iterator> document_node::unparsed_entity_system_id(
	context & ctx,
	string const& entity_name) const
{
	string val;
	if (get_entity(entity_name, val))
		return singleton_iterator(ctx,val);
	else
		return new item_iterator(ctx);
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
	vector<nodeid>::const_iterator child_it = child_hv.begin();
	for (; child_it!=child_hv.end(); ++child_it) {
		ctx.get_node((*child_it))->put(os,ctx);
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
	rchandle<node> v_h = ctx.get_node(*child_it++);
	return v_h.item_value();
}

rchandle<item> element_node::child_iterator::peek()
{
	rchandle<node> v_h = ctx.get_node(*child_it++);
	return v_h.item_value();
}

bool element_node::child_iterator::done()
{
	return child_it == it_end;
}

void element_node::child_iterator::rewind()
{
	child_it = parent_p->child_hv.begin();
}

rchandle<item> element_node::child_iterator::operator*() const
{
	return peek();
}

element_node::child_iterator& element_node::child_iterator::operator++()
{
	next();
	return *this;
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
	rchandle<node> n_h = ctx.get_node(*attr_it++);
	return n_h->item_value();
}

rchandle<item> element_node::attr_iterator::peek()
{
	return ctx.get_node(*attr_it);
}

bool element_node::attr_iterator::done()
{
	return attr_it == it_end;
}

void element_node::attr_iterator::rewind()
{
	attr_it = parent_p->attr_hv.begin();
}

rchandle<item> element_node::attr_iterator::operator*() const
{
	return peek();
}

element_node::attr_iterator& element_node::attr_iterator::operator++()
{
	next();
	return *this;
}



/*...........................................
	:            element nodes                :
	:.........................................:
*/

rchandle<item_iterator> element_node::attributes(
	context & ctx) const
{
	return attr_iterator(ctx,this);
}

rchandle<item_iterator> element_node::base_uri(
	context & ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

rchandle<item_iterator> element_node::children(
	context & ctx) const
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

rchandle<item_iterator> element_node::namespace_bindings(
	context & ctx) const
{
	return new item_iterator(ctx);
}

rchandle<item_iterator> element_node::namespace_nodes(
	context & ctx) const
{
	return new item_iterator(ctx);
}

bool element_node::nilled(
	context const& ctx) const
{
	return nilled_b;
}

rchandle<item_iterator> element_node::node_name(
	context & ctx) const
{
	return singleton_iterator(ctx,name_h->describe(ctx));
}

rchandle<item_iterator> element_node::parent(
	context & ctx) const
{
	return singleton_iterator(ctx,&*parent_h);
}

rchandle<item_iterator> element_node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
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
	vector<nodeid>::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		oss << ctx.get_node((*it))->string_value(ctx);
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
	nodeid _parentid,
	rchandle<QName> _name_h,
	string const& _baseuri)
:
	node(_id),
	parentid(_parentid),
	name_h(_name_h),
	baseuri(_baseuri)
{
}

element_node::element_node(
	nodeid _id,
	nodeid _parentid,
	rchandle<QName> _name_h)
:
	node(_id),
	parentid(_parentid),
	name_h(_name_h),
	baseuri("")
{
}

ostream& element_node::put(ostream& os, context const& ctx) const
{
	os << '<';
	name_h->put(os,ctx);

	vector<nodeid>::const_iterator ns_it = ns_hv.begin();
	for (; ns_it!=ns_hv.end(); ++ns_it) {
		os << ' ';
		ctx.get_node((*ns_it))->put(os,ctx);
	}

	vector<nodeid>::const_iterator attr_it = attr_hv.begin();
	for (; attr_it!=attr_hv.end(); ++attr_it) {
		os << ' ';
		ctx.get_node((*attr_it))->put(os,ctx);
	}

	vector<nodeid>::const_iterator child_it = child_hv.begin();
	vector<nodeid>::const_iterator child_en = child_hv.end();

	if (child_it==child_en) {
		os << "/>";
	}
	else {
		os << '>';
		for (; child_it!=child_en; ++child_it) {
			ctx.get_node((*child_it))->put(os,ctx);
		}
		os << "</"; name_h->put(os,ctx) << '>';
	}

	return os;
}



/*...........................................
	:           attribute nodes               :
	:.........................................:
*/

rchandle<item_iterator> attribute_node::base_uri(
	context & ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : new item_iterator(ctx);
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

rchandle<item_iterator> attribute_node::node_name(
	context & ctx) const
{
	return singleton_iterator(ctx,name_h->describe(ctx));
}

rchandle<item_iterator> attribute_node::parent(
	context & ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

rchandle<item_iterator> attribute_node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
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

rchandle<item_iterator> ns_node::node_name(
	context & ctx) const
{
	if (prefix.length()==0) return new item_iterator(ctx);
	return singleton_iterator(ctx,
					new QName(QName::qn_ns,prefix,""));
}

rchandle<item_iterator> ns_node::parent(
	context & ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

rchandle<item_iterator> ns_node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
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

rchandle<item_iterator> pi_node::base_uri(
	context & ctx) const
{
	return singleton_iterator(ctx,baseuri);
}

rchandle<item_iterator> pi_node::node_name(
	context & ctx) const
{
	return singleton_iterator(ctx,
			new QName(QName::qn_pi, target));
}

rchandle<item_iterator> pi_node::parent(
	context & ctx) const
{
	return singleton_iterator(ctx,
			dynamic_cast<node*>(&*parent_h));
}

rchandle<item_iterator> pi_node::typed_value(
	context & ctx) const
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

rchandle<item_iterator> comment_node::base_uri(
	context & ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : new item_iterator(ctx);
}

rchandle<item_iterator> comment_node::parent(
	context & ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<node*>(&*parent_h))
										 : new item_iterator(ctx);
}

rchandle<item_iterator> comment_node::typed_value(
	context & ctx) const
{
	return singleton_iterator(ctx,content);
}
	
string comment_node::string_value(
	context & ctx) const
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

rchandle<item_iterator> text_node::base_uri(
	context & ctx) const
{
	return
		(parent_h!=NULL) ? parent_h->base_uri(ctx)
										 : new item_iterator(ctx);
}

rchandle<item_iterator> text_node::parent(
	context & ctx) const
{
	return
		(parent_h!=NULL) ? singleton_iterator(ctx,
													dynamic_cast<node*>(&*parent_h))
										 : new item_iterator(ctx);
}

rchandle<item_iterator> text_node::typed_value(
	context & ctx) const
{
	return new item_iterator(ctx);
}
	
rchandle<item_iterator> text_node::node_name(
	context & ctx) const
{
	return new item_iterator(ctx);
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
