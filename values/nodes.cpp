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
	case collection_kind: return "collection";
	case uninitialized_kind: return "uninitialized";
	default: return "??";
	}
}

node::node(
	sequence_type_t type,		// node type
	size_t length,					// item length
	uint32_t gen,						// genration number
	off_t ref,							// forwarding item reference
	nodeid_t id,						// ordinal node id
	nodeid_t parentid)			// parent node id
:
	item(type,length),
	m_gen(gen),
	m_ref(ref),
	m_id(id),
	m_parentid(parentid)
{
}

enum node::node_kind_t node::node_kind() const
{
	return uninitialized_kind;
}

rchandle<item_iterator> node::attributes(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::children(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::document_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::namespace_bindings(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::namespace_nodes(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::parent(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::typed_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::type_name(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::node_name(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> node::string_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

bool node::is_id(context * ctx_p) const { return false; }
bool node::is_idrefs(context * ctx_p) const { return false; }
bool node::nilled(context * ctx_p) const { return false; }


/*..........................................
 :     child_iterator                      :
 :.........................................*/

child_iterator::child_iterator(
	context * _ctx_p,
	node * _parent_p,
	off_t offset)
:
	item_iterator(ctx_p),
	parent_p(_parent_p),
	ctx_p(_ctx_p)
{
	end_p =
		reinterpret_cast<node *>(
			parent_p->length() +
				reinterpret_cast<uint32_t *>(parent_p));
	current_p = 
		reinterpret_cast<node *>(
			offset + reinterpret_cast<uint32_t *>(parent_p));
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
		reinterpret_cast<node *>(
			current_p->length() +
				reinterpret_cast<uint32_t *>(parent_p));
	return *this;
}


/*..........................................
 :     child_const_iterator                :
 :.........................................*/

child_const_iterator::child_const_iterator(
	context const* _ctx_p,
	node const* _parent_p,
	off_t offset)
:
	item_iterator(const_cast<context*>(ctx_p)),
	parent_p(_parent_p),
	ctx_p(_ctx_p)
{
	end_p =
		reinterpret_cast<node const*>(
			parent_p->length() +
				reinterpret_cast<uint32_t const*>(parent_p));
	current_p = 
		reinterpret_cast<node const*>(
			offset + reinterpret_cast<uint32_t const*>(parent_p));
}
	
item * child_const_iterator::operator*() const
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
	default: {
		errors::err(errors::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD);
	} }
	return NULL;
}

child_const_iterator const& child_const_iterator::operator++()
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
	context * ctx_p,
	itemref_t baseuri_ref,
	itemref_t uri_ref)
:
	node(
		documentNode,
		sizeof(document_node),
		ctx_p->gen(),
		0,
		ctx_p->next_nodeid(),
		ctx_p->context_nodeid()),

	m_docid(ctx_p->context_docid()),
	m_baseuri_ref(baseuri_ref),
	m_uri_ref(uri_ref),
	m_nsseq_ref(0),
	m_childseq_ref(0),
	m_child_count(0)
{
}


rchandle<item_iterator> document_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> document_node::children(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> document_node::document_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> document_node::typed_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> document_node::string_value(
	context * ctx_p) const
{
	ostringstream oss;
	child_const_iterator it(ctx_p,this,m_childseq_ref);
	while (!it.done()) {
		rchandle<item_iterator> it_h =
			(*it)->string_value(ctx_p);
		item* i_p = **it_h;
		if (i_p->type()!=xs_string) continue;
		xs_stringValue* s_p = static_cast<xs_stringValue*>(i_p);
		oss << s_p->str();
	}
	rchandle<item_iterator> it_h =
		dynamic_cast<item_iterator*>(new singleton_iterator(ctx_p, oss.str()));
	return it_h;
}

ostream& document_node::put(
	ostream& os,
	context * ctx_p) const
{
	os << "<?xml version=\"1.0\"?>\n";
	child_const_iterator it(ctx_p,this,m_childseq_ref);
	while (!it.done()) {
		os << (*it)->put(os,ctx_p);
	}
	return os;
}


/*..........................................
 :  collection nodes                       :
 :.........................................*/

rchandle<item_iterator> collection_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> collection_node::collection_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> collection_node::children(context * ctx_p) const
{ return ctx_p->emptyseq; }


/*..........................................
 :  element nodes                          :
 :.........................................*/

element_node::element_node(
	context * ctx_p,
	itemref_t qname_ref)
:
	node(
		elementNode,							// typecode
		sizeof(element_node),			// the length
		ctx_p->gen(),							// generation number
		0,												// forwarding itemref
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid()),	// parent node id

	m_docid(ctx_p->context_docid()),
	m_qname_ref(qname_ref),			// element QName ref
	m_nsseq_ref(0),							// element in-scope namespaces ref
	m_attrseq_ref(0),						// attribute node seq ref
	m_attr_count(0),						// attribute node count
	m_childseq_ref(0),					// child node set ref
	m_child_count(0)						// child node count
{
}

element_node::element_node(
	context * ctx_p,
	char const* name,
	uint32_t length)
:
	node(
		elementNode,							// typecode
		sizeof(element_node),			// the length
		ctx_p->gen(),							// generation number
		0,												// forwarding itemref
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid()),	// parent node id

	m_docid(ctx_p->context_docid()),
	m_qname_ref(0),							// element QName ref
	m_nsseq_ref(0),							// element in-scope namespaces ref
	m_attrseq_ref(0),						// attribute node seq ref
	m_attr_count(0),						// attribute node count
	m_childseq_ref(0),					// child node set ref
	m_child_count(0)						// child node count
{
}

rchandle<item_iterator> element_node::attributes(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::children(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::namespace_bindings(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::namespace_nodes(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::node_name(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::parent(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> element_node::typed_value(context * ctx_p) const
{ return ctx_p->emptyseq; }
	
rchandle<item_iterator> element_node::string_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

ostream& element_node::put(ostream& os, context * ctx_p) const
{
	return os << "<../>";
}



/*..........................................
 :           attribute nodes               :
 :.........................................*/

attribute_node::attribute_node(
	context * ctx_p,
	itemref_t qname_ref)
:
	node(
		attributeNode,								// typecode
		sizeof(attribute_node),				// item length
		ctx_p->gen(),									// generation number
		0,														// forwarding itemref
		ctx_p->next_nodeid(),					// ordinal node id
		ctx_p->context_nodeid()),			// parent node id

	m_docid(ctx_p->context_docid()),
	m_qname_ref(qname_ref)
{
}

rchandle<item_iterator> attribute_node::base_uri(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> attribute_node::node_name(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> attribute_node::parent(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> attribute_node::typed_value(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> attribute_node::string_value(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

ostream& attribute_node::put(ostream& os, context * ctx_p) const
{
	return os << "@=\"\"";
}



/*..........................................
 :          namespace nodes                :
 :.........................................*/

namespace_node::namespace_node(
	context * ctx_p)
:
	node(
		namespaceNode,						// type
		sizeof(text_node),				// length
		ctx_p->gen(),							// generation number
		0,												// forwarding reference
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid())	// parent node id
{
}

namespace_node::namespace_node(
	context * ctx_p,
	string const& ns)
:
	node(
		namespaceNode,						// type
		sizeof(text_node),				// length
		ctx_p->gen(),							// generation number
		0,												// forwarding reference
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid())	// parent node id
{
}

rchandle<item_iterator> namespace_node::node_name(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> namespace_node::parent(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

rchandle<item_iterator> namespace_node::typed_value(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}
	
rchandle<item_iterator> namespace_node::string_value(
	context * ctx_p) const
{
	return ctx_p->emptyseq;
}

ostream& namespace_node::put(ostream& os, context * ctx_p) const
{
	return os << "xmlns:pre=\"..\"";
}

	
/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

pi_node::pi_node(
	context * ctx_p)
:
	node(
		processingInstructionNode,
		sizeof(pi_node),
		ctx_p->next_gen(),
		0,
		ctx_p->next_nodeid(),
		ctx_p->context_nodeid()),

	m_docid(ctx_p->context_docid())
{
}

rchandle<item_iterator> pi_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> pi_node::node_name(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> pi_node::parent(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> pi_node::typed_value(context * ctx_p) const
{ return ctx_p->emptyseq; }
	
rchandle<item_iterator> pi_node::string_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

ostream& pi_node::put(ostream& os, context * ctx_p) const
{
	return os << "<?..?>";
}



/*..........................................
 :          comment nodes                  :
 :.........................................*/

comment_node::comment_node(
	context * ctx_p)
:
	node(
		commentNode,									// typecode
		sizeof(attribute_node),				// item length
		ctx_p->gen(),									// generation number
		0,														// forwarding itemref
		ctx_p->next_nodeid(),					// ordinal node id
		ctx_p->context_nodeid()),			// parent node id

	m_docid(ctx_p->context_docid())
{
}

rchandle<item_iterator> comment_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> comment_node::parent(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> comment_node::typed_value(context * ctx_p) const
{ return ctx_p->emptyseq; }
	
rchandle<item_iterator> comment_node::string_value(context * ctx_p) const
{ return ctx_p->emptyseq; }

ostream& comment_node::put(ostream& os, context * ctx_p) const
{
	return os << "<!-- ... -->";
}



/*..........................................
 :             text nodes                  :
 :.........................................*/

void* text_node::operator new(
	size_t node_size,
	itemstore& istore)
{
	return istore.alloc(node_size);
}

void* text_node::operator new(
	size_t node_size,
	itemstore& istore,
	off_t offset)
{
	return &istore[offset];
}

void* text_node::operator new(
	size_t node_size,
	void * p)
{
	return p;
}

text_node::text_node(
	context * ctx_p,
	string const& content)
:
	node(
		textNode,									// type
		sizeof(text_node),				// length
		ctx_p->gen(),							// generation number
		0,												// forwarding reference
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid()),	// parent node id

	m_docid(ctx_p->context_docid())
{
	new(*ctx_p->istore()) xs_stringValue(*ctx_p->istore(),content);
}

rchandle<item_iterator> text_node::base_uri(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> text_node::parent(context * ctx_p) const
{ return ctx_p->emptyseq; }

rchandle<item_iterator> text_node::typed_value(
	context * ctx_p) const
{
	return string_value(ctx_p);
}
	
rchandle<item_iterator> text_node::string_value(
	context * ctx_p) const
{
	xs_stringValue* s_p = new(*ctx_p->istore()) xs_stringValue(*ctx_p->istore(),rest);
	rchandle<item_iterator> it_h =
		dynamic_cast<item_iterator*>(new singleton_iterator(ctx_p, s_p));
	return it_h;
}

ostream& text_node::put(
	ostream& os,
	context * ctx_p) const
{
	xs_stringValue* s_p = new(*ctx_p->istore()) xs_stringValue(*ctx_p->istore(),rest);
	return os << s_p->str();
}



}	/* namespace xqp */

