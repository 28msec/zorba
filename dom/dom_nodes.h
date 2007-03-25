/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
 
#ifndef XQP_DOM_H
#define XQP_DOM_H

#include "dom_iterator.h"
#include "dom_qname.h"
#include "../context/common.h"
#include "../values/abstract_nodes.h"
#include "../values/abstract_values.h"
#include "../values/values.h"
#include "../runtime/abstract_iterator.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"

#include <sys/types.h>

namespace xqp {

class dom_element_node;
class dom_attribute_node;
class dom_namespace_node;


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

class dom_node : public abstract_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	dom_node* parent_p;

public:		// ctor,dtor
	dom_node() {}
	virtual ~dom_node() {}

public:		// output/debugging
	virtual std::ostream& put(std::ostream& os) const;

public:		// XQuery interface
	/**
	 *	The dm:node-kind accessor returns a string identifying the kind of 
	 *	node. It will be one of the following, depending on the kind of node: 
	 *	"attribute", "comment", "document", "element", "namespace" 
	 *	"processing-instruction", or "text". 
	 */
	virtual enum node_kind_t node_kind() const = 0;
	
	/**
	 *	The dm:string-value accessor returns the string value of a node.
	 */
	virtual string string_value() const = 0;

	/**
	 *	The dm:attributes accessor returns the attributes of a node as a 
	 *	sequence containing zero or more Attribute Nodes. The order of 
	 *	Attribute Nodes is stable but implementation dependent. 
	 */
	virtual iterator_t attributes() const = 0;
	
	/**
	 *	The dm:base-uri accessor returns the base URI of a node as a sequence 
	 *	containing zero or one URI reference. 
	 */
	virtual iterator_t base_uri() const = 0;
	
	/**
	 *	The dm:children accessor returns the children of a node as a sequence 
	 *	containing zero or more nodes. 
	 */
	virtual iterator_t children() const = 0;
	
	/**
	 *	The dm:document-uri accessor returns the absolute URI of the resource 
	 *	from which the Document Node was constructed, if the absolute URI is 
	 *	available. If there is no URI available, or if it cannot be made 
	 *	absolute when the Document Node is constructed, or if it is used on a 
	 *	node other than a Document Node, the empty sequence is returned. 
	 */
	virtual iterator_t document_uri() const = 0;
	
	/**
	 *	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a sequence containing zero or 
	 *	more Namespace Nodes. The order of Namespace Nodes is stable but 
	 *	implementation dependent. 
	 *	Note: this accessor and the namespace-bindings accessor provide two 
	 *	views of the same information.
	 */
	virtual iterator_t namespace_nodes() const = 0;
	
	/**
	 *	The dm:node-name accessor returns the name of the node as a sequence 
	 *	of zero or one xs:QNames. Note that the QName value includes an 
	 *	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	 */
	virtual iterator_t node_name() const = 0;
	
	/**
	 *	The dm:parent accessor returns the parent of a node as a sequence 
	 *	containing zero or one nodes. 
	 */
	virtual iterator_t parent() const
	{ return new dom_singleton_iterator((abstract_item*)parent_p); }
	
	/**
	 *	The dm:type-name accessor returns the name of the schema type of a 
	 *	node as a sequence of zero or one xs:QNames. 
	 */
	virtual iterator_t type_name() const = 0;
	
	/**
	 *	The dm:typed-value accessor returns the typed-value of the node as a 
	 *	sequence of zero or more atomic values. 
	 */
	virtual iterator_t typed_value() const = 0;
		
	/**
	 *	The dm:is-id accessor returns true if the node is an XML ID.
	 */
	virtual bool is_id() const = 0;
	
	/**
	 *	The dm:is-idrefs accessor returns true if the node is an 
	 *  XML IDREF or IDREFS. 
	 */
	virtual bool is_idrefs() const = 0;
		
	/**
	 *	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	 *	Part 1] introduced the nilled mechanism to signal that an element 
	 *	should be accepted as valid when it has no content even when it has a 
	 *	content type which does not require or even necessarily allow empty 
	 *	content. 
	 */
	virtual bool nilled() const = 0;

};
	


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

class dom_document_node : public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	std::string the_baseuri;
	std::string the_docuri;
	std::vector<dom_node*> childv;

public:
	dom_document_node(const std::string& baseuri, const std::string& docuri);
	dom_document_node(dom_document_node&);
	~dom_document_node() {}

public:		// accessors
	std::string baseuri() const { return the_baseuri; }
	std::string docuri() const { return the_docuri; }
	const std::vector<dom_node*>& get_childv() const { return childv; }
	void add_child(dom_node* dn_p) { childv.push_back(dn_p); }

public:		// XQuery interface
  enum node_kind_t node_kind() const { return doc_kind; }
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t document_uri() const;
	iterator_t children() const;
	iterator_t typed_value() const;

public:		// output and debugging
	std::ostream& put(std::ostream&) const;
	std::string describe() const { return "doc("+the_baseuri+the_docuri+")"; }
	
  iterator_t attributes() const { return NULL; }
  iterator_t namespace_nodes() const { return NULL; }
  iterator_t node_name() const { return NULL; }
  iterator_t type_name() const { return NULL; }
  bool is_id() const { return false; }
  bool is_idrefs() const { return false; }
  bool nilled() const { return false; }

public:		// iterator interface

	class child_iterator :	public abstract_iterator
	{
	protected:
		const dom_document_node* doc_p;
		std::vector<dom_node*>::const_iterator it;
		std::vector<dom_node*>::const_iterator end;
	public:
		child_iterator(const dom_document_node* _doc_p)
		:
			doc_p(_doc_p),
			it(doc_p->get_childv().begin()),
			end(doc_p->get_childv().end())
		{}
	
		~child_iterator() {}
	
	public:
	 	void open() {}
		void close() {}
	
		abstract_item* next(uint32_t delta = 1)
		{ ++(*this); return **this; }
	
		abstract_item* peek() const
		{ return **this; }
	
		bool done() const { return it==end; }
		void rewind() { it = doc_p->get_childv().begin(); }
	
	public:
		abstract_item* operator*() const
			{ return (abstract_item*)(*it); }
	
		child_iterator& operator++()
			{ ++it; return *this; }

		child_iterator operator++(int)
			{ child_iterator result = *this; it++; return result; }
	
	};

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

class dom_element_node :	public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	dom_qname* qname_p;
	atomic_value* value_p;
	std::vector<dom_namespace_node*> nsv;
	std::vector<dom_attribute_node*> attrv;
	std::vector<dom_node*> childv;

	bool id_b;
	bool idrefs_b;
	bool nilled_b;

public:
	const std::vector<dom_namespace_node*>& get_nsv() const { return nsv; }
	const std::vector<dom_attribute_node*>& get_attrv() const { return attrv; }
	const std::vector<dom_node*>& get_childv() const { return childv; }
	std::vector<dom_namespace_node*>& get_nsv() { return nsv; }
	std::vector<dom_attribute_node*>& get_attrv() { return attrv; }
	std::vector<dom_node*>& get_childv() { return childv; }
	
	void add_namespace(dom_namespace_node* ns_p) { nsv.push_back(ns_p); }
	void add_attribute(dom_attribute_node* at_p) { attrv.push_back(at_p); }
	void add_child(dom_node* node_p) { childv.push_back(node_p); }

public:
	dom_element_node(dom_qname*, atomic_value*);
	dom_element_node(const dom_element_node&);
	~dom_element_node() {}

public:		// XQuery interface
	enum node_kind_t node_kind() const { return elem_kind; }
	std::string string_value() const;
	iterator_t attributes() const;
	iterator_t base_uri() const;
	iterator_t document_uri() const;
	iterator_t children() const;
	iterator_t namespace_nodes() const;
	iterator_t node_name() const;
	iterator_t typed_value() const;
	iterator_t type_name() const { return NULL; }

	bool is_id() const { return id_b; }
	bool is_idrefs() const { return idrefs_b; }
	bool nilled() const { return false; }

public:		// output and debugging
	std::ostream& put(std::ostream&) const;
  std::string describe() const { return qname_p->describe(); }

public:		// iterators
	class child_iterator :	public abstract_iterator
	{
	protected:
		const dom_element_node* elem_p;
		std::vector<dom_node*>::const_iterator it;
		std::vector<dom_node*>::const_iterator end;
	
	public:
		child_iterator(const dom_element_node* _elem_p)
		:
			elem_p(_elem_p),
			it(elem_p->get_childv().begin()),
			end(elem_p->get_childv().end())
		{}
	
		~child_iterator() {}
	
	public:
	 	void open() {}
		void close() {}
	
		abstract_item* next(uint32_t delta = 1)
		{ ++(*this); return **this; }
	
		abstract_item* peek() const
		{ return **this; }
	
		bool done() const { return it==end; }
		void rewind() { it = elem_p->get_childv().begin(); }
	
	public:
		abstract_item* operator*() const
			{ return (abstract_item*)(*it); }
	
		child_iterator& operator++()
			{ ++it; return *this; }

		child_iterator operator++(int)
			{ child_iterator result = *this; it++; return result; }
	
	};
	
	
	class attribute_iterator :	public abstract_iterator
	{
	protected:
		const dom_element_node* elem_p;
		std::vector<dom_attribute_node*>::const_iterator it;
		std::vector<dom_attribute_node*>::const_iterator end;
	
	public:
		attribute_iterator(const dom_element_node* _elem_p)
		:
			elem_p(_elem_p),
			it(elem_p->get_attrv().begin()),
			end(elem_p->get_attrv().end())
		{}
	
		~attribute_iterator() {}
	
	public:
	 	void open() {}
		void close() {}
	
		abstract_item* next(uint32_t delta = 1)
		{ ++(*this); return **this; }
	
		abstract_item* peek() const
		{ return **this; }
	
		bool done() const { return it==end; }
		void rewind() { it = elem_p->get_attrv().begin(); }
	
	public:
		abstract_item* operator*() const
			{ return (abstract_item*)(*it); }

		attribute_iterator& operator++()
			{ ++it; return *this; }

		attribute_iterator operator++(int)
			{ attribute_iterator result = *this; it++; return result; }
	
	};
	
	
	class namespace_iterator :	public abstract_iterator
	{
	protected:
		const dom_element_node* elem_p;
		std::vector<dom_namespace_node*>::const_iterator it;
		std::vector<dom_namespace_node*>::const_iterator end;
	
	public:
		namespace_iterator(const dom_element_node* _elem_p)
		:
			elem_p(_elem_p),
			it(elem_p->get_nsv().begin()),
			end(elem_p->get_nsv().end())
		{}

		~namespace_iterator() {}
	
	public:
	 	void open() {}
		void close() {}
	
		abstract_item* next(uint32_t delta=1)
		{ ++(*this); return **this; }
	
		abstract_item* peek() const
		{ return **this; }
	
		bool done() const { return it==end; }
		void rewind() { it = elem_p->get_nsv().begin(); }
	
	public:
		abstract_item* operator*() const
			{ return (abstract_item*)(*it); }

		namespace_iterator& operator++()
			{ ++it; return *this; }

		namespace_iterator operator++(int)
			{ namespace_iterator result = *this; it++; return result; }
	
	};


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

class dom_attribute_node :	public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	dom_qname* qname_p;
	std::string value;
	bool id_b;
	bool idrefs_b;
	bool nilled_b;

public:
  dom_attribute_node(
		dom_qname*,
		const std::string& value,
		bool id_b = false,
		bool idref_b = false);

	dom_attribute_node(dom_attribute_node&);
  ~dom_attribute_node() {}

public:	// XQuery interface
	enum node_kind_t node_kind() const { return attr_kind; }
	bool is_id() const { return id_b; }
	bool is_idrefs() const { return idrefs_b; }
	bool nilled() const { return nilled_b; }

	iterator_t base_uri() const;
	iterator_t node_name() const;
	iterator_t typed_value() const;
	string string_value() const;

public:		// output,debugging
	std::ostream& put(std::ostream&) const;

	iterator_t attributes() const { return NULL; }
	iterator_t children() const { return NULL; }
	iterator_t document_uri() const { return NULL; }
	iterator_t namespace_nodes() const { return NULL; }
	iterator_t type_name() const { return NULL; }

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
class dom_namespace_node :	public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	std::string iprefix;
	std::string iuri;

public:
	dom_namespace_node(const std::string& prefix, const std::string& uri);
	dom_namespace_node(dom_namespace_node&);
	~dom_namespace_node() {}

public:		// XQuery interface
	enum node_kind_t node_kind() const { return ns_kind; }
	iterator_t node_name() const;
	iterator_t typed_value() const;
	string string_value() const;

public:		// output, debugging
	std::string prefix() const { return iprefix; }
	std::string uri() const { return iuri; }
	std::ostream& put(std::ostream&) const;

	iterator_t attributes() const { return NULL; }
	iterator_t base_uri() const { return NULL; }
	iterator_t children() const { return NULL; }
	iterator_t document_uri() const { return NULL; }
	iterator_t namespace_nodes() const { return NULL; }
	iterator_t type_name() const { return NULL; }
	bool is_id() const { return false; }
	bool is_idrefs() const { return false; }
	bool nilled() const { return false; }

};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class dom_pi_node : public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	std::string itarget;
	std::string icontent;

public:
	dom_pi_node(const std::string& target, const std::string& content);
	dom_pi_node(const dom_pi_node&);
	~dom_pi_node() {}

public:		// XQuery interface
	enum node_kind_t node_kind() const { return pi_kind; }
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t typed_value() const;

public:		// output, debugging
	std::string target() const { return itarget; }
	std::string content() const { return icontent; }
	std::ostream& put(std::ostream&) const;

	iterator_t attributes() const { return NULL; }
	iterator_t children() const { return NULL; }
	iterator_t document_uri() const { return NULL; }
	iterator_t namespace_nodes() const { return NULL; }
	iterator_t type_name() const { return NULL; }
	iterator_t node_name() const;
	
	bool is_id() const { return false; }
	bool is_idrefs() const { return false; }
	bool nilled() const { return false; }
};



/*______________________________________________________________________
| 6.6 Comment Nodes 
|_______________________________________________________________________*/

class dom_comment_node :	public dom_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	std::string the_content;

public:
	dom_comment_node(const std::string& content);
	dom_comment_node(const dom_comment_node&);
	~dom_comment_node() {}
	
public:		// XQuery interface
	enum node_kind_t node_kind() const { return comment_kind; }
	string string_value() const;
	iterator_t base_uri() const;
	iterator_t typed_value() const;

public:		// output, debugging
	std::string content() const { return the_content; }
	std::ostream& put(std::ostream&) const;

	iterator_t attributes() const { return NULL; }
	iterator_t children() const { return NULL; }
	iterator_t document_uri() const { return NULL; }
	iterator_t namespace_nodes() const { return NULL; }
	iterator_t node_name() const { return NULL; }
	iterator_t type_name() const { return NULL; }
	
	bool is_id() const { return false; }
	bool is_idrefs() const { return false; }
	bool nilled() const { return false; }

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

class dom_text_node : public dom_node
											//abstract_text_node
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	std::string the_content;

public:
	dom_text_node(const std::string& content);
	dom_text_node(const dom_text_node&);
	~dom_text_node() {}
	
public:		// accessors
	std::string string_value() const;
	iterator_t base_uri() const;
	iterator_t typed_value() const;

public:		// output/debugging
	std::string content() { return the_content; }
	std::ostream& put(std::ostream& os) const;

	enum node_kind_t node_kind() const { return text_kind; }
	iterator_t attributes() const { return NULL; }
	iterator_t children() const { return NULL; }
	iterator_t document_uri() const { return NULL; }
	iterator_t namespace_nodes() const { return NULL; }
	iterator_t node_name() const { return NULL; }
	iterator_t type_name() const { return NULL; }
	
	bool is_id() const { return false; }
	bool is_idrefs() const { return false; }
	bool nilled() const { return false; }

};


}	/* namespace xqp */
#endif /* XQP_DOM_NODES_H */
