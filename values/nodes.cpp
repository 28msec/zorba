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

#include "../runtime/errors.h"
#include "../runtime/iterator.h"
#include "../runtime/zorba.h"
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

rchandle<abstract_iterator> node::attributes(
	dynamic_context*) const
{ return NULL; }

rchandle<abstract_iterator> node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> node::children(
	dynamic_context*) const
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
	zorba* zor_p,
	nodeid_t baseuri,
	nodeid_t uri)
:
	node( documentNode,							/* type								*/
				0,												/* length 						*/
				0,												/* forwarding ref			*/
				zor_p->gen(),							/* generation number	*/
				zor_p->next_nodeid(),			/* ordinal node id		*/
				zor_p->context_nodeid()),	/* parent node id			*/
	m_baseuri(baseuri),
	m_uri(uri)
{
cout << TRACE << endl;
	m_length = sizeof(document_node)>>2;
}

string document_node::baseuri() const { return ""; } 
string document_node::uri() const { return ""; } 
rchandle<abstract_iterator> document_node::base_uri() const { return NULL; } 
rchandle<abstract_iterator> document_node::document_uri() const { return NULL; } 
rchandle<abstract_iterator> document_node::typed_value() const { return NULL; } 

rchandle<abstract_iterator> document_node::children(
	dynamic_context*) const
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

ostream& document_node::put(zorba* z_p,ostream& os) const
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
			d_p->put(z_p,os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_node* a_p = new(i_p) attribute_node();
			a_p->put(z_p,os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_node* e_p = new(i_p) element_node();
			e_p->put(z_p,os);
			break;
		}
		case processingInstructionNode: {
			pi_node* pi_p = new(i_p) pi_node();
			pi_p->put(z_p,os);
			break;
		}
		case commentNode: {
			comment_node* c_p = new(i_p) comment_node();
			c_p->put(z_p,os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_node* t_p = new(i_p) text_node();
			t_p->put(z_p,os);
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

rchandle<abstract_iterator> collection_node::children(
	dynamic_context*) const
{ return NULL; }


/*..........................................
 :  element nodes                          :
 :.........................................*/

element_node::element_node(
	zorba* zorp,
	nodeid_t qname)
:
	node(
		elementNode,							// typecode
		0,	                     	// the length
		0,												// forwarding itemref
		zorp->gen(),							// generation number
		zorp->next_nodeid(),			// ordinal node id
		zorp->context_nodeid()),	// parent node id
	qnameID(qname),							// element QName id
	namespacesID(0)							// XXX in-scope namespaces
{
cout << TRACE << endl;
}

rchandle<abstract_iterator> element_node::attributes(
	dynamic_context*) const
{ return NULL; }

rchandle<abstract_iterator> element_node::base_uri() const
{ return NULL; }

rchandle<abstract_iterator> element_node::children(
	dynamic_context* dctx_p) const
{
	return new child_iterator(dctx_p, this, new(&rest[nodeOffset]) node());
}

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

ostream& element_node::put(zorba* zorp, ostream& os) const
{
  cout << TRACE << " : element_node" << endl;

  qname_value* q_p = zorp->get_qname(qnameID);
  q_p->put(os);
  
	node* n_p = new(rest) node();
	child_const_iterator it(this,n_p);
	for (; !it.done(); ++it) {
    abstract_item* i_p = *it;
		switch (i_p->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			document_node* d_p = new(i_p) document_node();
			d_p->put(zorp,os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_node* a_p = new(i_p) attribute_node();
			a_p->put(zorp,os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_node* e_p = new(i_p) element_node();
			e_p->put(zorp,os);
			break;
		}
		case processingInstructionNode: {
			pi_node* pi_p = new(i_p) pi_node();
			pi_p->put(zorp,os);
			break;
		}
		case commentNode: {
			comment_node* c_p = new(i_p) comment_node();
			c_p->put(zorp,os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_node* t_p = new(i_p) text_node();
			t_p->put(zorp,os);
			break;
		}
		default: {
		}}
	}
	return os;
}

node* element_node::node_at(uint32_t n) const
{
	child_const_iterator it((node*)this,new(&rest[nodeOffset]) node());
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
	zorba* zor_p,
	nodeid_t qname)
:
	node(
		attributeNode,								// typecode
		sizeof(attribute_node)>>2,		// item length
		0,														// forwarding itemref
		zor_p->gen(),									// generation number
		zor_p->next_nodeid(),					// ordinal node id
		zor_p->context_nodeid()),			// parent node id
	m_qname(qname)
{
cout << TRACE << endl;
}

attribute_node::attribute_node(
	zorba* zor_p,
	nodeid_t qname,
	string const& val)
:
	node(
		attributeNode,								// typecode
		sizeof(attribute_node)>>2,		// item length
		0,														// forwarding itemref
		zor_p->gen(),									// generation number
		zor_p->next_nodeid(),					// ordinal node id
		zor_p->context_nodeid()),			// parent node id
	m_qname(qname)
{
	itemstore& istore = *zor_p->istore();
	new(istore) xs_stringValue(istore,val);
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

ostream& attribute_node::put(zorba* z_p,ostream& os) const
{ return os << "@=\"\""; }


/*..........................................
 :          namespace nodes                :
 :.........................................*/

namespace_node::namespace_node(
	zorba* zor_p,
	const string& prefix,
	const string& uri)
:
	node(
		namespaceNode,						// type
		0,                    		// length
		0,												// forwarding reference
		zor_p->gen(),							// generation number
		zor_p->next_nodeid(),			// ordinal node id
		zor_p->context_nodeid())	// parent node id
{
	itemstore& istore = *zor_p->istore();
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

ostream& namespace_node::put(zorba* z_p,ostream& os) const
{
	return os << "xmlns:pre=\"..\"";
}

	
/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

pi_node::pi_node(
	zorba* zor_p)
:
	node(
		processingInstructionNode,
		sizeof(pi_node)>>2,
		0,
		zor_p->next_gen(),
		zor_p->next_nodeid(),
		zor_p->context_nodeid())
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

ostream& pi_node::put(zorba* z_p,ostream& os) const
{
	return os << "<?..?>";
}



/*..........................................
 :          comment nodes                  :
 :.........................................*/

comment_node::comment_node(
	zorba* zor_p)
:
	node(
		commentNode,									// typecode
		sizeof(comment_node)>>2,			// item length
		0,														// forwarding itemref
		zor_p->gen(),									// generation number
		zor_p->next_nodeid(),					// ordinal node id
		zor_p->context_nodeid())			// parent node id
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

ostream& comment_node::put(zorba* z_p,ostream& os) const
{
	return os << "<!-- ... -->";
}


/*..........................................
 :             text nodes                  :
 :.........................................*/

text_node::text_node(
	zorba* z_p,
	string const& content)
:
	node(
		textNode,									// type
		0,												// length
		0,												// forwarding reference
		z_p->gen(),								// generation number
		z_p->next_nodeid(),				// ordinal node id
		z_p->context_nodeid())		// parent node id
{
	itemstore& istore = *z_p->istore();
	new(istore) xs_stringValue(istore,content);
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

ostream& text_node::put(zorba* z_p,ostream& os) const
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

ostream& nsseq::put(zorba*,ostream& os) const
{
	return os;
}


/*..........................................
 :     child_iterator                      :
 :.........................................*/

child_iterator::child_iterator(
	dynamic_context* dctx_p,
	const node* _parent_p,
	node* _current_p)
:
	item_iterator(dctx_p),
	parent_p(_parent_p),
	current_p(_current_p)
{
	end_p = parent_p + parent_p->length();
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
	current_p += current_p->length();
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

