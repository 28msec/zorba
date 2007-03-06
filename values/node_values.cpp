/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "node_values.h"
#include "xs_primitive_values.h"
#include "../context/context.h"
#include "../runtime/iterator.h"
#include "../util/tracer.h"

#include "stdlib.h"

using namespace std;
namespace xqp {

/*...........................................
	:             node                        :
	:.........................................*/

string node::decode(node_kind_t kind) const
{
	switch (kind) {
	case doc_kind: return "doc";
	case elem_kind: return "elem";
	case attr_kind: return "attr";
	case ns_kind: return "ns";
	case pi_kind: return "pi";
	case text_kind: return "text";
	case comment_kind: return "comment";
	case binary_kind: return "binary";
	case collection_kind: return "collection";
	case uninitialized_kind: return "uninitialized";
	default: return "??";
	}
}

node::node(
	sequence_type_t _type,
	size_t _length,
	uint32_t _gen,
	off_t _ref,
	nodeid_t _id,
	nodeid_t _parentid)
:
	item(_type,_length),
	gen(_gen),
	ref(_ref),
	id(_id),
	parentid(_parentid)
{
}

enum node::node_kind_t node::node_kind() const
{
	return uninitialized_kind;
}

rchandle<item_iterator> node::attributes(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::base_uri(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::children(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::document_uri(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

bool node::is_id(
	context * ctx_p) const
{
	return false;
}

bool node::is_idrefs(
	context * ctx_p) const
{
	return false;
}

rchandle<item_iterator> node::namespace_bindings(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::namespace_nodes(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

bool node::nilled(
	context * ctx_p) const
{
	return false;
}

rchandle<item_iterator> node::parent(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::typed_value(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::type_name(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> node::node_name(
	context * ctx_p) const
{
	return &iterator::EMPTY_SEQUENCE;
}

sequence_type_t const& node::get_type(
	context * ctx_p) const
{
	return xs_anyNode;
}

string node::string_value(
	context const* ctx_p) const
{
	return "";
}


/*..........................................
 :     document_node::child_iterator       :
 :.........................................*/

document_node::child_iterator::child_iterator(
	context * ctx_p,
	document_node const* doc_p)
:
	item_iterator(ctx_p),
	parent_p(doc_p),
{
}
	
document_node::child_iterator::~child_iterator()
{
}

void document_node::child_iterator::open()
{
}

void document_node::child_iterator::close()
{
}

item* document_node::child_iterator::next()
{
	offset += current_node.length();
	if (!itemstore.check(offset)) {
		errors::error(ERR_ITERATOR_OVERRUN);
	}
	switch (itemstore[offset]) {
	case elementNode: {
		return new(&itemstore[offset]) element_node();
		break;
	}
	case processingInstructionNode: {
		return new(&itemstore[offset]) pi_node();
		break;
	}
	case commentNode: {
		return new(&itemstore[offset]) comment_node();
		break;
	}
	case textNode: {
		return new(&itemstore[offset]) text_node();
		break;
	}
	default: {
		errors::error(ERR_ILLEGAL_DOC_CHILD);
	} }

}

item& document_node::child_iterator::peek() const
{
}

bool document_node::child_iterator::done() const
{
}

void document_node::child_iterator::rewind()
{
}

item& document_node::child_iterator::operator*() const
{
	return peek();
}

document_node::child_iterator& document_node::child_iterator::operator++()
{
	next();
	return *this;
}



/*..........................................
 :            document_node                :
 :.........................................*/

rchandle<item_iterator> document_node::base_uri(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,baseuri);
}

rchandle<item_iterator> document_node::children(
	context * ctx_p) const
{
	return new child_iterator(ctx_p,this);
}

rchandle<item_iterator> document_node::document_uri(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,docuri);
}

rchandle<item_iterator> document_node::typed_value(
	context * ctx_p) const
{
	return &iterm_iterator::EMPTY_SEQUENCE;
}

string document_node::string_value(
	context const* ctx_p) const
{
	ostringstream oss;
	child_iterator it(ctx_p, this);
	while (!it.done()) {
		oss << (*it).string_value(ctx_p);
	}
	return oss.str();
}

ostream& document_node::put(
	ostream& os,
	context * ctx_p) const
{
	os << "<?xml version=\"1.0\"?>\n";
	child_iterator it(ctx_p, this);
	while (!it.done()) {
		oss << (*it).put(os,ctx_p);
	}
	return os;
}



/*..........................................
 :  collection nodes                       :
 :.........................................*/

rchandle<item_iterator> collection_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> collection_node::collection_uri(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> collection_node::children(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}



/*..........................................
 :  qname 'node'                           :
 :.........................................*/
void* qname_node::operator new(
	size_t sz,
	itermstore& store)
{
	void * result = itemstore.last();
}



/*..........................................
 :  element_node::child_iterator           :
 :.........................................*/

element_node::child_iterator::child_iterator(
	context * ctx_p,
	element_node const* elem_p)
:
	item_iterator(ctx_p),
	parent_p(elem_p),
	current_node()
{
}
	
element_node::child_iterator::~child_iterator()
{
}

void element_node::child_iterator::open()
{
}

void element_node::child_iterator::close()
{
}

rchandle<item> element_node::child_iterator::next()
{
	offset += current_node.length();
	if (!itemstore.check(offset)) {
		errors::error(ERR_ITERATOR_OVERRUN);
	}
	switch (itemstore[offset]) {
	case elementNode: {
		return new(&itemstore[offset]) element_node();
		break;
	}
	case processingInstructionNode: {
		return new(&itemstore[offset]) pi_node();
		break;
	}
	case commentNode: {
		return new(&itemstore[offset]) comment_node();
		break;
	}
	case textNode: {
		return new(&itemstore[offset]) text_node();
		break;
	}
	default: {
		errors::error(ERR_ILLEGAL_DOC_CHILD);
	} }

}

rchandle<item> element_node::child_iterator::peek() const
{
	rchandle<node> n_h = ctx_p->get_node(*child_it);
	return (n_h==NULL) ? NULL : &*n_h;
}

bool element_node::child_iterator::done() const
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
	++child_it;
	return *this;
}



/*..........................................
 :  element_node::attr_iterator            :
 :.........................................*/

element_node::attr_iterator::attr_iterator(
	context * ctx_p,
	element_node const* elem_p)
:
	item_iterator(ctx_p),
	parent_p(elem_p),
	attr_it(elem_p->attr_hv.begin()),
	it_end(elem_p->attr_hv.end())
{
}

element_node::attr_iterator::~attr_iterator()
{
}

void element_node::attr_iterator::open()
{
}

void element_node::attr_iterator::close()
{
}

rchandle<item> element_node::attr_iterator::next()
{
	rchandle<node> n_h = ctx_p->get_node(*++attr_it);
	return (n_h==NULL) ? NULL : &*n_h;
}

rchandle<item> element_node::attr_iterator::peek() const
{
	rchandle<node> n_h = ctx_p->get_node(*attr_it);
	if (n_h==NULL) {
		cout << TRACE << ": n_h==NULL\n";
	}
	return (n_h==NULL) ? NULL : &*n_h;
}

bool element_node::attr_iterator::done() const
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
	++attr_it;
	return *this;
}



/*..........................................
 :            element nodes                :
 :.........................................*/

element_node::element_node(
	nodeid _id,
	nodeid _parentid,
	nodeid _docid,
	rchandle<QName> _name_h)
:
	node(_id,_parentid),
	docid(_docid),
	name_h(_name_h)
{
}

element_node::element_node(
	nodeid _id)
:
	node(_id)
{
}

element_node::~element_node()
{
}

rchandle<item_iterator> element_node::attributes(
	context * ctx_p) const
{
	return new attr_iterator(ctx_p,this);
}

rchandle<item_iterator> element_node::base_uri(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(docid);
	return (n_h==NULL) ? NULL : n_h->base_uri(ctx_p);
}

rchandle<item_iterator> element_node::children(
	context * ctx_p) const
{
	return new child_iterator(ctx_p,this);
}

bool element_node::is_id(
	context * ctx_p) const
{
	return id_b;
}

bool element_node::is_idrefs(
	context * ctx_p) const
{
	return idrefs_b;
}

rchandle<item_iterator> element_node::namespace_bindings(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> element_node::namespace_nodes(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

bool element_node::nilled(
	context * ctx_p) const
{
	return nilled_b;
}

rchandle<item_iterator> element_node::node_name(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,name_h->describe(ctx_p));
}

rchandle<item_iterator> element_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> element_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}
	
sequence_type_t const& element_node::get_type(
	context * ctx_p) const
{
	return type;
}

string element_node::string_value(
	context const* ctx_p) const
{
	ostringstream oss;
	vector<nodeid>::const_iterator it = child_hv.begin();
	for (; it!=child_hv.end(); ++it) {
		rchandle<node> n_h = ctx_p->get_node((*it));
		if (n_h!=NULL) oss << n_h->string_value(ctx_p);
	}
	return oss.str();
}

void element_node::add_node(
	context * ctx_p,
	nodeid id)
{
	rchandle<node> n_h = ctx_p->get_node(id);
	add_node(n_h);
}

void element_node::add_node(
	rchandle<node> node_h)
{
	nodeid id = node_h->get_nodeid();
	node_kind_t kind = node_h->node_kind();

	switch (kind) {
	case elem_kind: case text_kind: {
		child_hv.push_back(node_h->get_nodeid());
		break;
	}
	case attr_kind: {
		attr_hv.push_back(node_h->get_nodeid());
		break;
	}
	case ns_kind: {
		ns_hv.push_back(node_h->get_nodeid());
		break;
	}
	default : {
		throw bad_arg(__FUNCTION__,"Illegal element child node type: "+decode(kind));
	}
	}
}

ostream& element_node::put(ostream& os, context * ctx_p) const
{
	os << '<';
	name_h->put(os,ctx_p);

	vector<nodeid>::const_iterator ns_it = ns_hv.begin();
	for (; ns_it!=ns_hv.end(); ++ns_it) {
		os << ' ';
		rchandle<node> n_h = ctx_p->get_node((*ns_it));
		if (n_h!=NULL) n_h->put(os,ctx_p);
	}

	vector<nodeid>::const_iterator attr_it = attr_hv.begin();
	for (; attr_it!=attr_hv.end(); ++attr_it) {
		os << ' ';
		rchandle<node> n_h = ctx_p->get_node((*attr_it));
		if (n_h!=NULL) n_h->put(os,ctx_p);
	}

	vector<nodeid>::const_iterator child_it = child_hv.begin();
	vector<nodeid>::const_iterator child_en = child_hv.end();

	if (child_it==child_en) {
		os << "/>";
	}
	else {
		os << '>';
		for (; child_it!=child_en; ++child_it) {
			rchandle<node> n_h = ctx_p->get_node((*child_it));
			if (n_h!=NULL) n_h->put(os,ctx_p);
		}
		os << "</"; name_h->put(os,ctx_p) << '>';
	}

	return os;
}



/*..........................................
 :           attribute nodes               :
 :.........................................*/

attribute_node::attribute_node(
	nodeid _id,
	nodeid _parentid,
	rchandle<QName> _name_h,
	string const& _val)
:
	node(_id,_parentid),
	name_h(_name_h),
	val(_val)
{
}

attribute_node::attribute_node(
	nodeid _id)
:
	node(_id)
{
}

attribute_node::~attribute_node()
{
}

rchandle<item_iterator> attribute_node::base_uri(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	if (n_h==NULL) return NULL;
	node_kind_t kind = n_h->node_kind();
	if (kind!=elem_kind) {
		throw xqp_exception(__FUNCTION__,"illegal attr parent "+decode(kind));
	}
	rchandle<element_node> e_h = dynamic_cast<element_node*>(&*n_h);
	if (e_h==NULL) {
		throw xqp_exception(__FUNCTION__,"failed element_node conversion");
	}
	return e_h->base_uri(ctx_p);
}

bool attribute_node::is_id(
	context * ctx_p) const
{
	return id_b;
}

bool attribute_node::is_idrefs(
	context * ctx_p) const
{
	return idrefs_b;
}

rchandle<item_iterator> attribute_node::node_name(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,name_h->string_value(ctx_p));
}

rchandle<item_iterator> attribute_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> attribute_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

sequence_type_t const& attribute_node::get_type(
	context * ctx_p) const
{
	return type;
}

string attribute_node::string_value(
	context const* ctx_p) const
{
	return val;
}

ostream& attribute_node::put(ostream& os, context * ctx_p) const
{
	name_h->put(os,ctx_p);
	return os << "=\"" << val << '"';
}



/*..........................................
 :          namespace nodes                :
 :.........................................*/

ns_node::ns_node(
	nodeid _id,
	nodeid _parentid,
	string const& _prefix,
	string const& _uri)
:
	node(_id,_parentid),
	prefix(_prefix),
	uri(_uri)
{
}

ns_node::ns_node(
	nodeid _id)
:
	node(_id)
{
}

ns_node::~ns_node()
{
}

rchandle<item_iterator> ns_node::node_name(
	context * ctx_p) const
{
	if (prefix.length()==0) return &item_iterator::EMPTY_SEQUENCE;
	return new singleton_iterator(ctx_p, new QName(prefix,""));
}

rchandle<item_iterator> ns_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> ns_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}
	
string ns_node::string_value(
	context const* ctx_p) const
{
	return uri;
}

ostream& ns_node::put(ostream& os, context * ctx_p) const
{
	return os << "xmlns:" << prefix << "=\"" << uri << '"';
}



	
/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

pi_node::pi_node(
	nodeid _id,
	nodeid _parentid,
	string const& _target,
	string const& _content,
	string const& _baseuri)
:
	node(_id,_parentid),
	target(_target),
	content(_content),
	baseuri(_baseuri)
{
}

pi_node::pi_node(
	nodeid _id)
:
	node(_id)
{
}

pi_node::~pi_node()
{
}

rchandle<item_iterator> pi_node::base_uri(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,baseuri);
}

rchandle<item_iterator> pi_node::node_name(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p, new QName(target));
}

rchandle<item_iterator> pi_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> pi_node::typed_value(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p, new xs_string_value(content));
}
	
string pi_node::string_value(
	context const* ctx_p) const
{
	return content;
}

ostream& pi_node::put(ostream& os, context * ctx_p) const
{
	return os << "<?" << target << " " << content << "?>";
}



/*..........................................
 :          comment nodes                  :
 :.........................................*/

comment_node::comment_node(
	nodeid _nodeid,
	nodeid _parentid,
	string const& _content)
:
	node(_nodeid,_parentid),
	content(_content)
{
}

comment_node::comment_node(
	nodeid _nodeid)
:
	node(_nodeid)
{
}

comment_node::~comment_node()
{
}

rchandle<item_iterator> comment_node::base_uri(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	if (n_h==NULL) return NULL;
	node_kind_t kind = n_h->node_kind();
	if (kind!=elem_kind) {
		throw xqp_exception(__FUNCTION__,"illegal attr parent "+decode(kind));
	}
	rchandle<element_node> e_h = dynamic_cast<element_node*>(&*n_h);
	if (e_h==NULL) {
		throw xqp_exception(__FUNCTION__,"failed element_node conversion");
	}
	return e_h->base_uri(ctx_p);
}

rchandle<item_iterator> comment_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> comment_node::typed_value(
	context * ctx_p) const
{
	return new singleton_iterator(ctx_p,content);
}
	
string comment_node::string_value(
	context const* ctx_p) const
{
	return content;
}

ostream& comment_node::put(ostream& os, context * ctx_p) const
{
	return os << "<!--" << content << "-->";
}



/*..........................................
 :             text nodes                  :
 :.........................................*/

void* text_node::operator new(
	size_t node_size,
	size_t text_size,
	itemstore& istore)
{
	istore.check(node_size+text_size);
	return istore.last();
}

void* text_node::operator new(
	size_t node_size,
	void* p)
{
	return p;
}

void* text_node::operator new(
	size_t node_size,
	itemstore& istore,
	uint64_t offset)
{
	return (void*)&istore[offset];
}

text_node::text_node(
	nodeid _id,
	nodeid _parentid,
	string const& _content)
:
	node(_id,_parentid),
	content(_content)
{
}

text_node::text_node(
	nodeid _id,
	nodeid _parentid,
	char const* data,
	uint32_t datalen)
:
	node(_id,_parentid),
	content(data,0,datalen)
{
}

text_node::text_node(
	nodeid _id)
:
	node(_id)
{
}

text_node::~text_node()
{
}

rchandle<item_iterator> text_node::base_uri(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	if (n_h==NULL) return NULL;
	node_kind_t kind = n_h->node_kind();
	if (kind!=elem_kind) {
		throw xqp_exception(__FUNCTION__,"illegal attr parent "+decode(kind));
	}
	rchandle<element_node> e_h = dynamic_cast<element_node*>(&*n_h);
	if (e_h==NULL) {
		throw xqp_exception(__FUNCTION__,"failed element_node conversion");
	}
	return e_h->base_uri(ctx_p);
}

rchandle<item_iterator> text_node::parent(
	context * ctx_p) const
{
	rchandle<node> n_h = ctx_p->get_node(parentid);
	return (n_h==NULL) ? NULL : new singleton_iterator(ctx_p, &*n_h);
}

rchandle<item_iterator> text_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}
	
rchandle<item_iterator> text_node::node_name(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}
	
string text_node::string_value(
	context const* ctx_p) const
{
	return content;
}

ostream& text_node::put(
	ostream& os,
	context * ctx_p) const
{
	return os << content;
}



/*..........................................
 :  binary nodes                           :
 :.........................................*/

binary_node::binary_node(
	nodeid _id)
:
	node(_id)
{
}

binary_node::~binary_node()
{
}

std::string binary_node::string_value(
	context const* ctx_p) const
{
	return "";
}
 
rchandle<item_iterator> binary_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> binary_node::parent(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> binary_node::type_name(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}

rchandle<item_iterator> binary_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}


}	/* namespace xqp */

