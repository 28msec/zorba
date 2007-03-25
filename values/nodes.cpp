/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "nodes.h"
#include "qname_value.h"
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
	case unknown_kind: return "unknown";
	default: return "??";
	}
}

node::node(
	sequence_type_t type,		// node type
	uint32_t length,				// item length
	itemref_t ref,					// forwarding item reference
	uint32_t gen,						// genration number
	nodeid_t id,						// ordinal node id
	nodeid_t parentid)			// parent node id
:
	item(type,length),
	m_ref(ref),
	m_gen(gen),
	m_id(id),
	m_parentid(parentid)
{
}

rchandle<abstract_iterator> node::attributes() const
{ return NULL; }

rchandle<abstract_iterator> node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> node::children() const
{ return NULL; }

rchandle<abstract_iterator> node::document_uri() const
{ return NULL; }

rchandle<abstract_iterator> node::namespace_bindings() const
{ return NULL; }

rchandle<abstract_iterator> node::namespace_nodes() const
{ return NULL; }

rchandle<abstract_iterator> node::parent() const
{ return NULL; }

rchandle<abstract_iterator> node::typed_value() const
{ return NULL; }

rchandle<abstract_iterator> node::type_name() const
{ return NULL; }

rchandle<abstract_iterator> node::node_name() const
{ return NULL; }

string node::string_value() const
{ return ""; }

bool node::is_id() const
{ return false; }

bool node::is_idrefs() const
{ return false; }

bool node::nilled() const
{ return false; }


/*..........................................
 :            document_node                :
 :.........................................*/

document_node::document_node(
	context * ctx_p,
	nodeid_t baseuri,
	nodeid_t uri)
:
	node( documentNode, 0, ctx_p->gen(), 0,
					ctx_p->next_nodeid(),
					ctx_p->context_nodeid()),
	m_baseuri(baseuri),
	m_uri(uri)
{
cout << TRACE << endl;
	m_length = sizeof(document_node)>>2;
}

string document_node::baseuri(context* ctx_p) const { return ""; }
string document_node::uri(context* ctx_p) const { return ""; }

rchandle<abstract_iterator> document_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> document_node::children() const
{ return NULL; }

rchandle<abstract_iterator> document_node::document_uri() const
{ return NULL; }

rchandle<abstract_iterator> document_node::typed_value() const
{ return NULL; }

string document_node::string_value() const
{
	ostringstream oss;
	node* n_p = new(rest) node();
	child_const_iterator it(this,n_p);
	for (; !it.done(); ++it) {
		oss << (*it)->string_value();
	}
	return oss.str();
}

ostream& document_node::put(ostream& os) const
{
	os << "<?xml version=\"1.0\"?>\n";
	node* n_p = new(rest) node();
	child_const_iterator it(this,n_p);
	for (; !it.done(); ++it) {
    item* i_p = *it;
		switch (i_p->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			document_node* d_p = new(i_p) document_node();
			d_p->put(os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_node* a_p = new(i_p) attribute_node();
			a_p->put(os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_node* e_p = new(i_p) element_node();
			e_p->put(os);
			break;
		}
		case processingInstructionNode: {
			pi_node* pi_p = new(i_p) pi_node();
			pi_p->put(os);
			break;
		}
		case commentNode: {
			comment_node* c_p = new(i_p) comment_node();
			c_p->put(os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_node* t_p = new(i_p) text_node();
			t_p->put(os);
			break;
		}
		default: {
  		cout << TRACE << " : unrecognized type = "
  		      << sequence_type::describe(i_p->type()) << endl;
		}}
	}
	return os;
}


/*..........................................
 :  collection nodes                       :
 :.........................................*/

rchandle<abstract_iterator> collection_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> collection_node::collection_uri() const
{ return NULL; }

rchandle<abstract_iterator> collection_node::children() const
{ return NULL; }


/*..........................................
 :  element nodes                          :
 :.........................................*/

element_node::element_node(
	context* ctx_p,
	nodeid_t qname)
:
	node(
		elementNode,								// typecode
		0,	                      	// the length
		ctx_p->gen(),								// generation number
		0,													// forwarding itemref
		ctx_p->next_nodeid(),				// ordinal node id
		ctx_p->context_nodeid()),		// parent node id
	m_qname(qname),								// element QName id
	m_nsseq(0)										// in-scope namespaces XXX replace this
{
cout << TRACE << endl;
}

rchandle<abstract_iterator> element_node::attributes() const
{ return NULL; }

rchandle<abstract_iterator> element_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> element_node::children(
	context* ctx_p) const
{
	return new child_iterator(ctx_p,(node*)this,new(&rest[m_node_offset]) node());
}

rchandle<abstract_iterator> element_node::children() const
{ return NULL; }

rchandle<abstract_iterator> element_node::namespace_nodes() const
{ return NULL; }

rchandle<abstract_iterator> element_node::node_name() const
{ return NULL; }

rchandle<abstract_iterator> element_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> element_node::typed_value() const
{ return NULL; }

string element_node::string_value() const
{ return ""; }

ostream& element_node::put(
	context* ctx_p,
	ostream& os) const
{
  cout << TRACE << " : element_node" << endl;
  itemstore& istore = *ctx_p->istore();
	itemref_t ref;
	Assert<bad_arg>(istore.get_itemref(m_qname,ref));
  qname_value* q_p = new(istore,ref) qname_value();
  q_p->put(os);
  
	node* n_p = new(rest) node();
	child_const_iterator it(this,n_p);
	for (; !it.done(); ++it) {
    abstract_item* i_p = *it;
		switch (i_p->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			document_node* d_p = new(i_p) document_node();
			d_p->put(os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_node* a_p = new(i_p) attribute_node();
			a_p->put(os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_node* e_p = new(i_p) element_node();
			e_p->put(os);
			break;
		}
		case processingInstructionNode: {
			pi_node* pi_p = new(i_p) pi_node();
			pi_p->put(os);
			break;
		}
		case commentNode: {
			comment_node* c_p = new(i_p) comment_node();
			c_p->put(os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_node* t_p = new(i_p) text_node();
			t_p->put(os);
			break;
		}
		default: {
		}}
	}
	return os;
}

node* element_node::node_at(uint32_t n) const
{
	child_const_iterator it((node*)this,new(&rest[m_node_offset]) node());
	uint32_t i = 0;
	for (; i<n && !it.done(); ++it);
	Assert<bad_arg>(i==n);
	return static_cast<node*>(*it);
}

namespace_node* element_node::name_space_at(uint32_t) const
{ return NULL; }


attribute_node* element_node::attr_at(uint32_t) const
{ return NULL; }


/*..........................................
 :           attribute nodes               :
 :.........................................*/

attribute_node::attribute_node(
	context * ctx_p,
	nodeid_t qname)
:
	node(
		attributeNode,								// typecode
		sizeof(attribute_node)>>2,		// item length
		ctx_p->gen(),									// generation number
		0,														// forwarding itemref
		ctx_p->next_nodeid(),					// ordinal node id
		ctx_p->context_nodeid()),			// parent node id
	m_qname(qname)
{
cout << TRACE << endl;
}

attribute_node::attribute_node(
	context * ctx_p,
	nodeid_t qname,
	string const& val)
:
	node(
		attributeNode,								// typecode
		sizeof(attribute_node)>>2,		// item length
		ctx_p->gen(),									// generation number
		0,														// forwarding itemref
		ctx_p->next_nodeid(),					// ordinal node id
		ctx_p->context_nodeid()),			// parent node id
	m_qname(qname)
{
	itemstore& istore = *ctx_p->istore();
	//lock()
	new(istore) xs_stringValue(istore,val);
	//unlock()
	cout << TRACE << endl;
}

rchandle<abstract_iterator> attribute_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> attribute_node::node_name() const
{ return NULL; }

rchandle<abstract_iterator> attribute_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> attribute_node::typed_value() const
{ return NULL; }

string attribute_node::string_value() const
{ return ""; }

ostream& attribute_node::put(ostream& os) const
{ return os << "@=\"\""; }


/*..........................................
 :          namespace nodes                :
 :.........................................*/

namespace_node::namespace_node(
	context* ctx_p,
	const string& prefix,
	const string& uri)
:
	node(
		namespaceNode,						// type
		0,                    		// length
		ctx_p->gen(),							// generation number
		0,												// forwarding reference
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid())	// parent node id
{
	itemstore& istore = *ctx_p->istore();
	xs_stringValue* p = new(istore) xs_stringValue(istore,prefix);
	m_uri_offset = istore.eos();
	xs_stringValue* q = new(istore) xs_stringValue(istore,uri);
	m_length = sizeof(namespace_node)>>2 + p->length() + q->length();
}

rchandle<abstract_iterator> namespace_node::node_name() const
{ return NULL; }

rchandle<abstract_iterator> namespace_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> namespace_node::typed_value() const
{ return NULL; }

string namespace_node::string_value() const
{ return ""; }

ostream& namespace_node::put(ostream& os) const
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
		sizeof(pi_node)>>2,
		ctx_p->next_gen(),
		0,
		ctx_p->next_nodeid(),
		ctx_p->context_nodeid())
{
}

rchandle<abstract_iterator> pi_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> pi_node::node_name() const
{ return NULL; }

rchandle<abstract_iterator> pi_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> pi_node::typed_value() const
{ return NULL; }

string pi_node::string_value() const
{ return ""; }

ostream& pi_node::put(ostream& os) const
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
		sizeof(comment_node)>>2,			// item length
		ctx_p->gen(),									// generation number
		0,														// forwarding itemref
		ctx_p->next_nodeid(),					// ordinal node id
		ctx_p->context_nodeid())			// parent node id
{
cout << TRACE << endl;
}

rchandle<abstract_iterator> comment_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> comment_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> comment_node::typed_value() const
{ return NULL; }

string comment_node::string_value() const
{ return ""; }

ostream& comment_node::put(ostream& os) const
{
	return os << "<!-- ... -->";
}


/*..........................................
 :             text nodes                  :
 :.........................................*/

text_node::text_node(
	context * ctx_p,
	string const& content)
:
	node(
		textNode,									// type
		0,												// length
		ctx_p->gen(),							// generation number
		0,												// forwarding reference
		ctx_p->next_nodeid(),			// ordinal node id
		ctx_p->context_nodeid())	// parent node id
{
	new(*ctx_p->istore()) xs_stringValue(*ctx_p->istore(),content);
cout << TRACE << endl;
}

rchandle<abstract_iterator> text_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> text_node::parent() const
{ return NULL; }

rchandle<abstract_iterator> text_node::typed_value() const
{ return NULL; }
	
string text_node::string_value() const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return s_p->str();
}

ostream& text_node::put(ostream& os) const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return os << s_p->str();
}

string text_node::str() const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return s_p->str();
}


/*..........................................
 :       nsseq = namespaceNodeSeq          :
 :.........................................*/

nsseq::nsseq(
	itemstore& istore,
	const vector<nodeid_t>& nsv)
:
	atomic_value(namespaceNodeSeq,0),
	count(nsv.size())
{
cout << TRACE << endl;
	vector<nodeid_t>::const_iterator it = nsv.begin();
	for (; it!=nsv.end(); ++it) { istore.put(*it); }
	m_length = sizeof(nsseq)/4 + count;
}

ostream& nsseq::put(ostream& os) const
{
	return os;
}


/*..........................................
 :     child_iterator                      :
 :.........................................*/

child_iterator::child_iterator(
	context* ctx_p,
	node* _parent_p,
	node* _current_p)
:
	item_iterator(ctx_p),
	parent_p(_parent_p),
	current_p(_current_p)
{
	end_p =
		reinterpret_cast<node *>(
			parent_p->length() +
				reinterpret_cast<uint32_t *>(parent_p));
}
	
item* child_iterator::operator*() const
{
	switch (current_p->type()) {
	case attributeNode: {
		return new(current_p) attribute_node();
	}
	case elementNode: {
		return new(current_p) element_node();
	}
	case processingInstructionNode: {
		return new(current_p) pi_node();
	}
	case commentNode: {
		return new(current_p) comment_node();
	}
	case textNode: {
		return new(current_p) text_node();
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
	const node* _parent_p,
	const node* _current_p)
:
	parent_p(_parent_p),
	current_p(_current_p)
{
cout << TRACE << " : parent length = " << parent_p->length() << endl;
	end_p =
		reinterpret_cast<const node*>(
			parent_p->length() +
				reinterpret_cast<const uint32_t*>(parent_p));
cout << TRACE << " : end_p = " << (uint32_t)end_p << endl;
}
	

item* child_const_iterator::operator*()
{
cout << TRACE << endl;

	while (true) {
		switch (current_p->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			return new(current_p) document_node();
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			return new(current_p) attribute_node();
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_node* e_p = new(current_p) element_node();
			return e_p;
		}
		case processingInstructionNode: {
			return new(current_p) pi_node();
		}
		case commentNode: {
			return new(current_p) comment_node();
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			return new(current_p) text_node();
		}
		default: {
			cout << TRACE << " : out of order node: "
					 << sequence_type::describe(current_p->type()) 
					 << " (" << current_p->length() << ')' << endl;
			switch (current_p->type()) {
			case xs_qname: {
				qname_value* q_p = new(current_p) qname_value();
				q_p->put(cout) << endl;
				break;
				}
			case xs_string: {
				xs_stringValue* s_p = new(current_p) xs_stringValue();
				s_p->put(cout) << endl;
				break;
				}
			default: {
				cout << "other\n";
				}
			}
			return (item*)current_p;
			//errors::err(errors::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD);
			//current_p =
			//	(const node*)(current_p->length() + (const uint32_t*)current_p);
			}
		}
	}
}

const child_const_iterator& child_const_iterator::operator++()
{
cout << TRACE << " : current_p = " << (uint32_t)(current_p) << endl;
	if (current_p >= end_p) {
cout << TRACE << " : iterator overrun" << endl;
		errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
	}
cout << TRACE << " : length = " << current_p->length() << endl;
	current_p = (const node*)(current_p->length()+(const uint32_t*)current_p);
cout << TRACE << " : current_p = " << (uint32_t)(current_p) << endl;
	return *this;
}



/*..........................................
 :     namespace_iterator                  :
 :.........................................*/

namespace_iterator::namespace_iterator(
	const element_node* _parent_p)
:
	parent_p(_parent_p)
{
}
	

abstract_item* namespace_iterator::operator*() const
{
cout << TRACE << endl;
	return NULL;
}

namespace_iterator& namespace_iterator::operator++()
{
	return *this;
}



}	/* namespace xqp */

