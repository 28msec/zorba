/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodes.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

/*______________________________________________________________________
|
| Includes classes supporting each of the 7 node types defined in:
| XQuery 1.0 and XPath 2.0 Data Model (NODE_TYPES)
| [http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/
 
#ifndef XQP_NODES_H
#define XQP_NODES_H

#include "abstract_nodes.h"
#include "values.h"

#include "../context/common.h"
#include "../runtime/iterator.h"
#include "../types/sequence_type.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"

#include <sys/types.h>

namespace xqp {

class context;
class itemstore;
class element_node;
class qname_value;

/*______________________________________________________________________
| 6.0 Node
|
|	 1.	Every node must have a unique identity, distinct from all
|	 		other nodes.
|	 2.	The children property of a node must not contain two consecutive
|	 		Text Nodes.
|	 3.	The children property of a node must not contain any empty
|	 		Text Nodes.
|	 4.	The children and attributes properties of a node must not contain
|	 		two nodes with the same identity.
|	
|	A set of accessors is defined on nodes in the data model. For 
|	consistency, all the accessors are defined on every kind of node, 
|	although several accessors return a constant empty sequence on some 
|	kinds of nodes. 
|	
|	Some typed values in the data model are undefined. Attempting to 
|	access an undefined property is always an error. Behavior in these 
|	cases is implementation-defined and the host language is responsible 
|	for determining the result. 
|_______________________________________________________________________*/

class node : public item, public abstract_node
{
	std::string decode(node_kind_t) const;

protected:
	uint32_t  m_gen;				// generation number
	itemref_t m_ref;				// forwarding reference for update
	nodeid_t  m_id;					// node ordinal id
	nodeid_t  m_parentid;		// parent node ordinal id

public:		// ctor,dtor
	node(
	  sequence_type_t,      // node type
	  uint32_t,							// value length
	  uint32_t,             // generation number
	  off_t,                // forwarding reference
	  nodeid_t,             // ordinal node id
	  nodeid_t);            // parent node id

	node() {}
	~node() {}

public:		// accessors
	uint32_t& gen() { return m_gen; }
	itemref_t& ref() { return m_ref; }
	nodeid_t& id() { return m_id; }
	nodeid_t& parentid() { return m_parentid; }

public:		// XQuery interface
	/**
	 *	The dm:node-kind accessor returns a string identifying the kind of 
	 *	node. It will be one of the following, depending on the kind of node: 
	 *	"attribute", "comment", "document", "element", "namespace" 
	 *	"processing-instruction", or "text". 
	 */
	enum node_kind_t node_kind() const;
	
	/**
	 *	The dm:string-value accessor returns the string value of a node.
	 */
	string string_value() const;

	/**
	 *	The dm:attributes accessor returns the attributes of a node as a 
	 *	sequence containing zero or more Attribute Nodes. The order of 
	 *	Attribute Nodes is stable but implementation dependent. 
	 */
	iterator_t attributes() const;
	
	/**
	 *	The dm:base-uri accessor returns the base URI of a node as a sequence 
	 *	containing zero or one URI reference. 
	 */
	iterator_t base_uri() const;
	
	/**
	 *	The dm:children accessor returns the children of a node as a sequence 
	 *	containing zero or more nodes. 
	 */
	iterator_t children() const;
	
	/**
	 *	The dm:document-uri accessor returns the absolute URI of the resource 
	 *	from which the Document Node was constructed, if the absolute URI is 
	 *	available. If there is no URI available, or if it cannot be made 
	 *	absolute when the Document Node is constructed, or if it is used on a 
	 *	node other than a Document Node, the empty sequence is returned. 
	 */
	iterator_t document_uri() const;
	
	/**
	 *	The dm:namespace-bindings accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a set of prefix/URI pairs.
	 *	The prefix for the default namespace is the zero length string.
	 *	Note: this accessor and the namespace-nodes accessor provide two views 
	 *	of the same information. 
	 */
	iterator_t namespace_bindings() const;
	
	/**
	 *	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a sequence containing zero or 
	 *	more Namespace Nodes. The order of Namespace Nodes is stable but 
	 *	implementation dependent. 
	 *	Note: this accessor and the namespace-bindings accessor provide two 
	 *	views of the same information.
	 */
	iterator_t namespace_nodes() const;
	
	/**
	 *	The dm:node-name accessor returns the name of the node as a sequence 
	 *	of zero or one xs:QNames. Note that the QName value includes an 
	 *	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	 */
	iterator_t node_name() const;
	
	/**
	 *	The dm:parent accessor returns the parent of a node as a sequence 
	 *	containing zero or one nodes. 
	 */
	iterator_t parent() const;
	
	/**
	 *	The dm:type-name accessor returns the name of the schema type of a 
	 *	node as a sequence of zero or one xs:QNames. 
	 */
	iterator_t type_name() const;
	
	/**
	 *	The dm:typed-value accessor returns the typed-value of the node as a 
	 *	sequence of zero or more atomic values. 
	 */
	iterator_t typed_value() const;
		
	/**
	 *	The dm:is-id accessor returns true if the node is an XML ID.
	 */
	bool is_id() const;
	
	/**
	 *	The dm:is-idrefs accessor returns true if the node is an 
	 *  XML IDREF or IDREFS. 
	 */
	bool is_idrefs() const;
		
	/**
	 *	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	 *	Part 1] introduced the nilled mechanism to signal that an element 
	 *	should be accepted as valid when it has no content even when it has a 
	 *	content type which does not require or even necessarily allow empty 
	 *	content. 
	 */
	bool nilled() const;

};
	

class child_iterator : public item_iterator
{
protected:
	node* parent_p;
	node* current_p;
	node* end_p;

public:
	child_iterator(context*, node* parent, node* current);
	~child_iterator() {}

public:
 	void open() {}
	void close() {}

	abstract_item* next(uint32_t delta = 1)
	{ ++(*this); return **this; }

	abstract_item* peek() const
	{ return **this; }

	bool done() const { return current_p >= end_p; }
	void rewind() {}

public:
	item* operator*() const;
	child_iterator& operator++();

};


class child_const_iterator : public item_const_iterator
{
protected:
	const node* parent_p;
	const node* current_p;
	const node* end_p;

public:
	child_const_iterator(const node* parent, const node* current);
	~child_const_iterator() {}

public:
 	void open() {}
	void close() {}
	abstract_item* next(uint32_t delta = 1) { ++(*this); return **this; }
	abstract_item* peek() { return **this; }
	bool done() const { return current_p >= end_p; }
	void rewind() {}

public:
	item* operator*();
	const child_const_iterator& operator++();

};


class namespace_iterator : public item_const_iterator
{
protected:
	const element_node* parent_p;

public:
	namespace_iterator(const element_node*);
	~namespace_iterator() {}

public:
 	void open() {}
	void close() {}
	abstract_item* next(uint32_t delta=1) { ++(*this); return **this; }
	abstract_item* peek() const { return **this; }
	bool done() const;
	void rewind() {}

public:
	abstract_item* operator*() const;
	namespace_iterator& operator++();

};


class attribute_node;
class namespace_node;

/*______________________________________________________________________
| 6.1 Document Node
|
|  1.	The children must consist exclusively of Element, Processing 
|			Instruction, Comment, and Text Nodes if it is not empty. Attribute, 
|			Namespace, and Document Nodes can never appear as children 
|  2.	If a node N is among the children of a Document Node D, then the 
|			parent of N must be D. 
|  3.	If a node N has a parent Document Node D, then N must be among 
|			the children of D. 
|  4.	The string-value property of a Document Node must be the 
|			concatenation of the string-values of all its Text Node descendants
|			in document order or, if the document has no such descendants, the 
|			zero-length string. 
|	
|	In the [Infoset], a document information item must have at least one 
|	child, its children must consist exclusively of element information 
|	items, processing instruction information items and comment 
|	information items, and exactly one of the children must be an element 
|	information item. This data model is more permissive: a Document Node 
|	may be empty, it may have more than one Element Node as a child, and 
|	it also permits Text Nodes as children. 
|	
|	Implementations that support DTD processing and access to the unparsed 
|	entity accessors use the unparsed-entities property to associate 
|	information about an unordered collection of unparsed entities with a 
|	Document Node. This property is accessed indirectly through the 
|	dm:unparsed-entity-system-id and dm:unparsed-entity-public-id 
|	functions. 
|_______________________________________________________________________*/

class document_node : public node, public abstract_document_node
{
	friend class child_iterator;

protected:
	nodeid_t m_baseuri;		// document base URI
	nodeid_t m_uri;				// document URI
	char rest[0];
	/*
    node child[0]
    ...
    node child[n-1]
	*/

public:
	document_node() {}
	document_node(context*, nodeid_t baseuri, nodeid_t uri);

public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// accessors
	string baseuri(context*) const;
	string uri(context*) const;
	iterator_t children(context*) const;

public:		// XQuery interface
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t document_uri() const;
	iterator_t children() const;
	iterator_t namespaces() const;
	iterator_t typed_value() const;

private:	// ctor,dtor
	document_node(document_node&) {}
	~document_node() {}

public:		// output and debugging
	std::ostream& put(std::ostream&) const;

};


/*______________________________________________________________________
|
| 6.2 Element Nodes
|
| 1.	The children must consist exclusively of Element, Processing 
|			Instruction, Comment, and Text Nodes if it is not empty. Attribute, 
|			Namespace, and Document Nodes can never appear as children 
| 2.	The Attribute Nodes of an element must have distinct xs:QNames.
| 3.-9.  Parent-child consistency.
| 10. If the dm:type-name of an Element Node is xs:untyped, then the 
|			nilled property must be false. 
| 11. If the nilled property is true, then the children property must 
|			not contain Element Nodes or Text Nodes. 
| 12. For every expanded QName that appears in the dm:node-name of the 
|			element, the dm:node-name of any Attribute Node among the attributes 
|			of the element, or in any value of type xs:QName or xs:NOTATION (or 
|			any type derived from those types) that appears in the typed-value 
|			of the element or the typed-value of any of its attributes, if the 
|			expanded QName has a non-empty URI, then there must be a prefix 
|			binding for this URI among the namespaces of this Element Node. 
|	    If any of the expanded QNames has an empty URI, then there must 
|			not be any binding among the namespaces of this Element Node which 
|			binds the empty prefix to a URI. 
| 13. Every element must include a Namespace Node and/or namespace 
|			binding for the prefix xml bound to the URI 
|			http://www.w3.org/XML/1998/namespace and there must be no other
|     prefix bound to that URI. 
| 14. The string-value property of an Element Node must be the 
|			concatenation of the string-values of all its Text Node descendants 
|			in document order or, if the element has no such descendants, the 
|			zero-length string. 
|_______________________________________________________________________*/

class element_node : public node, public abstract_element_node
{
	friend class child_iterator;

protected:
	nodeid_t m_qname;				// element QName
	nodeid_t m_nsseq;				// in-scope namespaces
	uint32_t m_node_offset;	// offset to first node
	char rest[0];
	/*
    attr[0]
    ...
    attr[m-1]
    node[0]      <- node_offset
    ...
    node[n-1]
	*/

public:
	element_node() {}

	element_node(
		context *,
		itemref_t qnamedi);

public:		// accessors
	qname_value& qname() const;											// element QName
	namespace_node* name_space_at(uint32_t) const;	// n-th namespace
	attribute_node* attr_at(uint32_t) const;				// n-th attribute
	node* node_at(uint32_t) const;									// n-th child
	uint32_t ns_count() const;											// number of namespaces
	uint32_t attr_count() const;										// number of attributes
	uint32_t child_count() const;										// number of children

public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery interface
	string string_value() const;
	iterator_t attributes() const;
	iterator_t base_uri() const;
	iterator_t children() const;
	iterator_t children(context*) const;
	iterator_t namespace_nodes() const;
	iterator_t node_name() const;
	iterator_t parent() const;
	iterator_t doc() const;
	iterator_t typed_value() const;

	bool is_nilled() const { return false; }
	bool is_id() const { return (m_type & ID_SUB5); }
	bool is_idref() const { return (m_type & IDREF_SUB5); }

private:	//ctor,dtor - lock out
	element_node(const element_node&) {}
	~element_node() {}

public:		// output and debugging
	std::ostream& put(std::ostream&) const;
	std::ostream& put(context*,std::ostream&) const;

};



/*______________________________________________________________________
|
| 6.3 Attribute Nodes
|	
|	 1. If an Attribute Node A is among the attributes of an element E, 
|			then the parent of A must be E. 
|	 2. If a Attribute Node A has a parent element E, then A must be 
|			among the attributes of E. 
|	
|	The data model permits Attribute Nodes without parents (to 
|	represent partial results during expression processing, for example). 
|	Such attributes must not appear among the attributes of any Element 
|	Node. 
|	
|	For convenience, the Element Node that owns this attribute is called 
|	its "parent" even though an Attribute Node is not a "child" of its 
|	parent element. 
|_______________________________________________________________________*/

class attribute_node : public node, public abstract_attribute_node
{
	friend class child_iterator;

protected:
	nodeid_t m_qname;
	char rest[0];
	/*
		char[] value
	*/

public:
  attribute_node() {}

	attribute_node(
		context *,
		nodeid_t qname);

	attribute_node(
		context *,
		nodeid_t qname,
		const std::string& val);

public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:	// XQuery interface
	bool is_id() const { return (m_type & ID_SUB5); }
	bool is_idref() const { return (m_type & IDREF_SUB5); }
	const char* name() const;
	
	iterator_t base_uri() const;
	iterator_t node_name() const;
	iterator_t parent() const;
	iterator_t typed_value() const;
	string string_value() const;

private:	//ctor,dtor - lock out
	attribute_node(attribute_node&);
  ~attribute_node();

public:		// output,debugging
	std::ostream& put(std::ostream&) const;

};



/*______________________________________________________________________
|
| 6.4 Namespace nodes
|	 1. If a Namespace Node N is among the namespaces of an element E, 
|			then the parent of N must be E. 
|	 2. If a Namespace Node N has a parent element E, then N must be 
|			among the namespaces of E. 
|	
|	The data model permits Namespace Nodes without parents. 
|_______________________________________________________________________*/
class namespace_node : public node, public abstract_namespace_node
{
	friend class child_iterator;

protected:
	nskey_t  m_nskey;
	uint32_t m_uri_offset;
	char rest[0];
	/*
		char[] prefix
		char[] uri  
	*/

public:
	namespace_node() {}
	namespace_node(context*,const std::string& prefix, const std::string& uri);

public:		// storage interface
	nskey_t& nskey() { return m_nskey; }

public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery interface
	iterator_t node_name() const;
	iterator_t parent() const;
	iterator_t typed_value() const;
	string string_value() const;

	std::string prefix() const;
	std::string uri() const;

private:	//ctor,dtor - lock out
	namespace_node(namespace_node&) {}
	~namespace_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&) const;

};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class pi_node : public node, public abstract_pi_node
{
	friend class child_iterator;

protected:
	uint32_t m_content_offset;
	char rest[0];
	/*
		char[] target
		char[] content
	*/

public:
	pi_node() {}
	pi_node(context *);

public:		// storage interface
	uint32_t& content() { return m_content_offset; }
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:		// XQuery interface
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t parent() const;
	iterator_t typed_value() const;
	iterator_t node_name() const;

private:	//ctor,dtor - lock out
	pi_node(pi_node&) {}
	~pi_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&) const;

};



/*______________________________________________________________________
| 6.6 Comment Nodes 
|_______________________________________________________________________*/

class comment_node : public node, public abstract_comment_node
{
	friend class child_iterator;

protected:
	char rest[0];
	/*
		char[] content
	*/

public:
	comment_node() {}
	comment_node(context *);
	
public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void operator delete(void*) {}

public:		// XQUery interface
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t parent() const;
	iterator_t typed_value() const;

private:	//ctor,dtor - lock out
	comment_node(comment_node&) {}
	~comment_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&) const;

};



/*______________________________________________________________________
| 6.7 Text Nodes 
| 
|   If the parent of a text node is not empty, the Text Node 
|   must not contain the zero-length string as its content.  In 
|   addition, Document and Element Nodes impose the constraint 
|   that two consecutive Text Nodes can never occur as adjacent 
|   siblings. When a Document or Element Node is constructed, 
|   Text Nodes that would be adjacent must be combined into a 
|   single Text Node. If the resulting Text Node is empty, it 
|   must never be placed among the children of its parent, it 
|   is simply discarded.
|_______________________________________________________________________*/

class text_node : public node, abstract_text_node
{
	friend class child_iterator;

protected:
	char rest[0];

public:	// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	text_node() {}
	text_node(context*, const std::string&);
	
public:		// accessors
	const char* content() const;
	std::string str() const;

public:		// XQuery interface
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t parent() const;
	iterator_t typed_value() const;

private:	//ctor,dtor
	text_node(text_node&) {}
	~text_node() {}

public:		// output/debugging
	std::ostream& put(std::ostream&) const;

};


// Zorba-specific node
//
class collection_node : public node
{
	friend class child_iterator;

public:
	iterator_t base_uri() const;
	iterator_t collection_uri() const;
	iterator_t children() const;

private:	// ctor,dtor - lock out
	collection_node(const collection_node&) {}
	collection_node() {}
	~collection_node() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os) const { return os; }

};



// node-like objects
//

class qname_value : public atomic_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	itemref_t m_uriref;
	char rest[0];
	/*
		char[] localname
	*/

public:
	void* operator new(size_t n,itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n,itemstore& i, itemref_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	qname_value() {}
	qname_value(itemstore&, itemref_t uriref, const std::string& qname);

public:
	std::string prefix() const;
	std::string localname() const;
	std::string uri(itemstore&) const;

private:	// ctor,dtor - lock out default and copy constructors
	qname_value(qname_value& qn) : atomic_value(xs_qname,0) {}
	~qname_value() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	string describe() const;

	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;
	std::string string_value() const;

};


class nsseq : public atomic_value
{
protected:
	uint32_t count;
	char rest[0];
	/*
		ns nodeid[0]
		ns nodeid[1]
		...
		ns nodeid[count-1]
	*/

public:
	void* operator new(size_t n,itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n,itemstore& i, itemref_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	nsseq() {}
	nsseq(itemstore&, const std::vector<nodeid_t>&);

public:

private:	// ctor,dtor - lock out default and copy constructors
	nsseq(nsseq& qn) : atomic_value(namespaceNodeSeq,0) {}
	~nsseq() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;

};



}	/* namespace xqp */
#endif /* XQP_NODE_VALUES_H */
