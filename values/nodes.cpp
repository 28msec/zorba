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

rchandle<item_iterator> node::attributes(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::base_uri(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::children(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::document_uri(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

bool node::is_id(context * ctx_p) const { return false; }
bool node::is_idrefs(context * ctx_p) const { return false; }
bool node::nilled(context * ctx_p) const { return false; }

rchandle<item_iterator> node::namespace_bindings(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::namespace_nodes(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::parent(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::typed_value(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::type_name(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> node::node_name(context * ctx_p) const
{ return &iterator::EMPTY_SEQUENCE; }

sequence_type_t const& node::get_type(context * ctx_p) const
{ return xs_anyNode; }

string node::string_value(context const* ctx_p) const
{ return ""; }


/*..........................................
 :     child_iterator                      :
 :.........................................*/

child_iterator::child_iterator(
	context * ctx_p,
	node const* node_p)
:
	item_iterator(ctx_p),
	parent_p(node_p),
{
}
	
child_iterator::~child_iterator() { }

void child_iterator::open() { }
void child_iterator::close() { }

item* child_iterator::next()
{
	offset += current_node.length();
	if (!itemstore.check(offset)) {
		errors::error(ERR_ITERATOR_OVERRUN);
	}
	switch (itemstore[offset]) {
	case attributeNode: {
		return new(&itemstore[offset]) attribute_node();
		break;
	}
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
	case binaryNode: {
		return new(&itemstore[offset]) binary_node();
		break;
	}
	default: {
		errors::error(ERR_ILLEGAL_DOC_CHILD);
	} }

}

item& child_iterator::peek() const
{
}

bool child_iterator::done() const
{
}

void child_iterator::rewind()
{
}

item& child_iterator::operator*() const
{
	return peek();
}

child_iterator& node::child_iterator::operator++()
{
	next();
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
	return NULL;
}

rchandle<item_iterator> document_node::children(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> document_node::document_uri(
	context * ctx_p) const
{
	return NULL;
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

rchandle<item_iterator> collection_node::base_uri(context * ctx_p) const
{ return &item_iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> collection_node::collection_uri(context * ctx_p) const
{ return &item_iterator::EMPTY_SEQUENCE; }

rchandle<item_iterator> collection_node::children(context * ctx_p) const
{ return &item_iterator::EMPTY_SEQUENCE; }



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
	return NULL;
}

rchandle<item_iterator> element_node::base_uri(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> element_node::children(
	context * ctx_p) const
{
	return NULL;
}

bool element_node::is_id(
	context * ctx_p) const
{
	return false;
}

bool element_node::is_idrefs(
	context * ctx_p) const
{
	return false;
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
	return false;
}

rchandle<item_iterator> element_node::node_name(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> element_node::parent(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> element_node::typed_value(
	context * ctx_p) const
{
	return &item_iterator::EMPTY_SEQUENCE;
}
	
sequence_type_t const& element_node::get_type(
	context * ctx_p) const
{
	return xs_untyped;
}

string element_node::string_value(
	context const* ctx_p) const
{
	return "";
}

void element_node::add_node(
	context * ctx_p,
	nodeid id)
{
}

void element_node::add_node(
	rchandle<node> node_h)
{
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
	return NULL;
}

bool attribute_node::is_id(
	context * ctx_p) const
{
	return false;
}

bool attribute_node::is_idrefs(
	context * ctx_p) const
{
	return false;
}

rchandle<item_iterator> attribute_node::node_name(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> attribute_node::parent(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> attribute_node::typed_value(
	context * ctx_p) const
{
	return NULL;
}

sequence_type_t const& attribute_node::get_type(
	context * ctx_p) const
{
	return xs_untypedAtomic;
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
	nodeid_t parentid,
	docid_t docid,
	itemref_t qname_ref)
:
	node(namespaceNode, 0, gen, ref, id, parentid)
{
}

rchandle<item_iterator> namespace_node::node_name(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> namespace_node::parent(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> namespace_node::typed_value(
	context * ctx_p) const
{
	return NULL;
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
	return NULL;
}

rchandle<item_iterator> pi_node::node_name(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> pi_node::parent(
	context * ctx_p) const
{
	return NULL:
}

rchandle<item_iterator> pi_node::typed_value(
	context * ctx_p) const
{
	return NULL;
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
	return NULL;
}

rchandle<item_iterator> comment_node::parent(
	context * ctx_p) const
{
	return NULL;
}

rchandle<item_iterator> comment_node::typed_value(
	context * ctx_p) const
{
	return NULL;
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
}

rchandle<item_iterator> text_node::parent(
	context * ctx_p) const
{
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

