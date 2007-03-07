/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "nodes.h"

#include "xs_primitive_values.h"
#include "../context/context.h"
#include "../runtime/errors.h"
#include "../runtime/iterator.h"
#include "../util/tracer.h"

#include <stdlib.h>

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
	sequence_type_t type,
	size_t length,
	uint32_t gen,
	off_t ref,
	nodeid_t id,
	nodeid_t parentid)
:
	item(type,length),
	m_gen(gen),
	m_ref(ref),
	m_id(id),
	m_parentid(parentid),
	m_offset(0)
{
}

enum node::node_kind_t node::node_kind() const
{
	return uninitialized_kind;
}

rchandle<item_iterator> node::attributes(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::base_uri(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::children(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::document_uri(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

bool node::is_id(context * ctx_p) const { return false; }
bool node::is_idrefs(context * ctx_p) const { return false; }
bool node::nilled(context * ctx_p) const { return false; }

rchandle<item_iterator> node::namespace_bindings(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::namespace_nodes(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::parent(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::typed_value(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::type_name(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> node::node_name(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

string node::string_value(context const* ctx_p) const
{ return ""; }


/*..........................................
 :     child_iterator                      :
 :.........................................*/

child_iterator::child_iterator(
	context * _ctx_p,
	node const* _parent_p)
:
	item_iterator(ctx_p),
	parent_p(_parent_p),
	ctx_p(_ctx_p)
{
	end_p =
		reinterpret_cast<node const*>(
			parent_p->length() +
				reinterpret_cast<uint32_t const*>(parent_p));
	current_p = 
		reinterpret_cast<node const*>(
			parent_p->offset() +
				reinterpret_cast<uint32_t const*>(parent_p));
}
	
child_iterator::child_iterator(
	node const* _parent_p)
:
	item_iterator(ctx_p),
	parent_p(_parent_p),
	ctx_p(NULL)
{
	end_p =
		reinterpret_cast<node const*>(
			parent_p->length() +
				reinterpret_cast<uint32_t const*>(parent_p));
	current_p = 
		reinterpret_cast<node const*>(
			parent_p->offset() +
				reinterpret_cast<uint32_t const*>(parent_p));
}
	
child_iterator::~child_iterator() { }

void child_iterator::open() { }
void child_iterator::close() { }

item* child_iterator::next(uint32_t delta)
{
	++(*this);
	return **this;
}

item * child_iterator::peek() const
{
	return **this;
}

bool child_iterator::done() const
{
	return (current_p >= end_p);
}

void child_iterator::rewind()
{
}

item * child_iterator::operator*() const
{
	switch (current_p->type()) {
	case attributeNode: {
		return new(current_p) attribute_node();
		break;
	}
	case elementNode: {
		return new(current_p) element_node();
		break;
	}
	case processingInstructionNode: {
		return new(current_p) pi_node();
		break;
	}
	case commentNode: {
		return new(current_p) comment_node();
		break;
	}
	case textNode: {
		return new(current_p) text_node();
		break;
	}
	case binaryNode: {
		return new(current_p) binary_node();
		break;
	}
	default: {
		errors::err(errors::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD);
	} }
	return NULL;
}

child_iterator& child_iterator::operator++()
{
	if (current_p >= end_p) {
		errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
	}
	current_p =
		reinterpret_cast<node const*>(
			current_p->length() +
				reinterpret_cast<uint32_t const*>(parent_p));
	return *this;
}



/*..........................................
 :            document_node                :
 :.........................................*/

document_node::document_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid,
	itemref_t baseuri_ref,
	itemref_t uri_ref)
:
	node(documentNode, 0, gen, ref, id, parentid),
	m_docid(docid),
	m_baseuri_ref(baseuri_ref),
	m_uri_ref(uri_ref),
	m_nsseq_ref(0),
	m_childseq_ref(0),
	m_child_count(0)
{
}


rchandle<item_iterator> document_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> document_node::children(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> document_node::document_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> document_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

string document_node::string_value(
	context const* ctx_p) const
{
	ostringstream oss;
	child_iterator it(this);
	while (!it.done()) {
		oss << (*it)->string_value(ctx_p);
	}
	return oss.str();
}

ostream& document_node::put(
	ostream& os,
	context * ctx_p) const
{
	os << "<?xml version=\"1.0\"?>\n";
	child_iterator it(this);
	while (!it.done()) {
		os << (*it)->put(os,ctx_p);
	}
	return os;
}



/*..........................................
 :  collection nodes                       :
 :.........................................*/

rchandle<item_iterator> collection_node::base_uri(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> collection_node::collection_uri(context * ctx_p) const
{ return &item_iterator::empty_sequence; }

rchandle<item_iterator> collection_node::children(context * ctx_p) const
{ return &item_iterator::empty_sequence; }



/*..........................................
 :            element nodes                :
 :.........................................*/

element_node::element_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid,
	itemref_t qname_ref)
:
	node(elementNode, 0, gen, ref, id, parentid),
	m_docid(docid),
	m_qname_ref(qname_ref),
	m_nsseq_ref(0),
	m_attrseq_ref(0),
	m_attr_count(0),
	m_childseq_ref(0),
	m_child_count(0)
{
}

rchandle<item_iterator> element_node::attributes(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::children(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::namespace_bindings(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::namespace_nodes(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::node_name(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> element_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}
	
string element_node::string_value(
	context const* ctx_p) const
{
	return "";
}

ostream& element_node::put(ostream& os, context * ctx_p) const
{
	return os << "<../>";
}



/*..........................................
 :           attribute nodes               :
 :.........................................*/

attribute_node::attribute_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid,
	itemref_t qname_ref)
:
	node(attributeNode, 0, gen, ref, id, parentid),
	m_docid(docid),
	m_qname_ref(qname_ref)
{
}

rchandle<item_iterator> attribute_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> attribute_node::node_name(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> attribute_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> attribute_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

string attribute_node::string_value(
	context const* ctx_p) const
{
	return "";
}

ostream& attribute_node::put(ostream& os, context * ctx_p) const
{
	return os << "@=\"\"";
}



/*..........................................
 :          namespace nodes                :
 :.........................................*/

namespace_node::namespace_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid)
:
	node(namespaceNode, 0, gen, ref, id, parentid)
{
}

rchandle<item_iterator> namespace_node::node_name(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> namespace_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> namespace_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}
	
string namespace_node::string_value(
	context const* ctx_p) const
{
	return "";
}

ostream& namespace_node::put(ostream& os, context * ctx_p) const
{
	return os << "xmlns:pre=\"..\"";
}



	
/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

pi_node::pi_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid)
:
	node(processingInstructionNode, 0, gen, ref, id, parentid),
	m_docid(docid)
{
}

rchandle<item_iterator> pi_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> pi_node::node_name(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> pi_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> pi_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}
	
string pi_node::string_value(
	context const* ctx_p) const
{
	return "";
}

ostream& pi_node::put(ostream& os, context * ctx_p) const
{
	return os << "<?..?>";
}



/*..........................................
 :          comment nodes                  :
 :.........................................*/

comment_node::comment_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid)
:
	node(commentNode, 0, gen, ref, id, parentid),
	m_docid(docid)
{
}

rchandle<item_iterator> comment_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> comment_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> comment_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}
	
string comment_node::string_value(
	context const* ctx_p) const
{
	return "";
}

ostream& comment_node::put(ostream& os, context * ctx_p) const
{
	return os << "<!-- ... -->";
}



/*..........................................
 :             text nodes                  :
 :.........................................*/

void* text_node::operator new(
	size_t node_size,
	size_t text_size,
	itemstore& istore)
{
	istore.assure_words(node_size+text_size);
	return istore.last();
}

void* text_node::operator new(
	size_t node_size,
	void const* p)
{
	return (void*)p;
}

text_node::text_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid)
:
	node(textNode, 0, gen, ref, id, parentid),
	m_docid(docid)
{
}

rchandle<item_iterator> text_node::base_uri(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> text_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> text_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}
	
string text_node::string_value(
	context const* ctx_p) const
{
	return rest;
}

ostream& text_node::put(
	ostream& os,
	context * ctx_p) const
{
	return os << rest;
}



/*..........................................
 :  binary nodes                           :
 :.........................................*/

binary_node::binary_node(
	uint32_t gen,
	itemref_t ref,
	nodeid_t id,
	nodeid_t parentid,
	docid_t docid)
:
	node(binaryNode, 0, gen, ref, id, parentid),
	m_docid(docid)
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
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> binary_node::parent(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> binary_node::type_name(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> binary_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}


}	/* namespace xqp */

