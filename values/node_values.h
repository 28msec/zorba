/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
 
#ifndef XQP_NODE_VALUES_H
#define XQP_NODE_VALUES_H

#include "values.h"
#include "qname_value.h"

#include "../context/common.h"
#include "../runtime/iterator.h"
#include "../types/sequence_type.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"

namespace xqp {

class context;
class itemstore;

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

class node : public item
{
public:	// nodes types
	enum node_kind_t {
		doc_kind,
		elem_kind,
		attr_kind,
		ns_kind,
		pi_kind,
		text_kind,
		comment_kind,
		binary_kind,				// zorba-specific: binary node
		collection_kind,		// zorba-specific: collection node
		uninitialized_kind
	};
	std::string decode(node_kind_t) const;

protected:
	uint32_t _gen;				// generation number
	void* 	_ref;					// forwarding reference for update
	nodeid _id;						// node id
	nodeid _parentid;			// parent node id

public:		// storage interface
	uint32_t& gen() { return _ref; }
	void*& ref() { return _ref; }
	nodeid& id() { return _id; }
	nodeid& parentid() const { return _parentid; }

public:		// XQUery interface
	/**
	 *	The dm:node-kind accessor returns a string identifying the kind of 
	 *	node. It will be one of the following, depending on the kind of node: 
	 *	"attribute", "comment", "document", "element", "namespace" 
	 *	"processing-instruction", or "text". 
	 */
	virtual enum node_kind_t node_kind() const;
	
	/**
	 *	The dm:string-value accessor returns the string value of a node.
	 */
	virtual std::string string_value(context const*) const;
	
	/**
	 * Return the node data type.
	 */
	virtual sequence_type_t const& get_type(context *) const;

	/**
	 *	The dm:attributes accessor returns the attributes of a node as a 
	 *	sequence containing zero or more Attribute Nodes. The order of 
	 *	Attribute Nodes is stable but implementation dependent. 
	 */
	virtual rchandle<item_iterator> attributes(context *) const;
	
	/**
	 *	The dm:base-uri accessor returns the base URI of a node as a sequence 
	 *	containing zero or one URI reference. 
	 */
	virtual rchandle<item_iterator> base_uri(context *) const;
	
	/**
	 *	The dm:children accessor returns the children of a node as a sequence 
	 *	containing zero or more nodes. 
	 */
	virtual rchandle<item_iterator> children(context *) const;
	
	/**
	 *	The dm:document-uri accessor returns the absolute URI of the resource 
	 *	from which the Document Node was constructed, if the absolute URI is 
	 *	available. If there is no URI available, or if it cannot be made 
	 *	absolute when the Document Node is constructed, or if it is used on a 
	 *	node other than a Document Node, the empty sequence is returned. 
	 */
	virtual rchandle<item_iterator> document_uri(context *) const;
	
	/**
	 *	The dm:is-id accessor returns true if the node is an XML ID.
	 */
	virtual bool is_id(context *) const;
	
	/**
	 *	The dm:is-idrefs accessor returns true if the node is an 
	 *  XML IDREF or IDREFS. 
	 */
	virtual bool is_idrefs(context *) const;
	
	/**
	 *	The dm:namespace-bindings accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a set of prefix/URI pairs.
	 *	The prefix for the default namespace is the zero length string.
	 *	Note: this accessor and the namespace-nodes accessor provide two views 
	 *	of the same information. 
	 */
	virtual rchandle<item_iterator> namespace_bindings(context *) const;
	
	/**
	 *	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a sequence containing zero or 
	 *	more Namespace Nodes. The order of Namespace Nodes is stable but 
	 *	implementation dependent. 
	 *	Note: this accessor and the namespace-bindings accessor provide two 
	 *	views of the same information.
	 */
	virtual rchandle<item_iterator> namespace_nodes(context *) const;
	
	/**
	 *	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	 *	Part 1] introduced the nilled mechanism to signal that an element 
	 *	should be accepted as valid when it has no content even when it has a 
	 *	content type which does not require or even necessarily allow empty 
	 *	content. 
	 */
	virtual bool nilled(context *) const;
	
	/**
	 *	The dm:node-name accessor returns the name of the node as a sequence 
	 *	of zero or one xs:QNames. Note that the QName value includes an 
	 *	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	 */
	virtual rchandle<item_iterator> node_name(context *) const;
	
	/**
	 *	The dm:parent accessor returns the parent of a node as a sequence 
	 *	containing zero or one nodes. 
	 */
	virtual rchandle<item_iterator> parent(context *) const;
	
	/**
	 *	The dm:type-name accessor returns the name of the schema type of a 
	 *	node as a sequence of zero or one xs:QNames. 
	 */
	virtual rchandle<item_iterator> type_name(context *) const;
	
	/**
	 *	The dm:typed-value accessor returns the typed-value of the node as a 
	 *	sequence of zero or more atomic values. 
	 */
	virtual rchandle<item_iterator> typed_value(context *) const;
	
	/**
	 *	The dm:unparsed-entity-public-id accessor returns the public 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, or if the entity 
	 *	has no public identifier, the empty sequence is returned. 
	 */
	virtual rchandle<item_iterator> unparsed_entity_public_id(
	  context *,
	  std::string const& entity_name) const;

	/**
	 *	The dm:unparsed-entity-system-id accessor returns the system 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, the empty 
	 *	sequence is returned. 
	 */
	virtual rchandle<item_iterator> unparsed_entity_system_id(
	  context *,
	  std::string const& entity_name) const;

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

class document_node : public node
{
protected:
	nodeid _doc_id;
	uri_id _base_uri_id;
	uri_id _doc_uri_d;
	uint32_t _ns_count;
	uint32_t _child_count;
	char rest[0];

public:		// storage interface
	nodeid& docid() { return _docid; }
	uri_id& base_uri_id() { return _base_uri_id; }
	uri_id& doc_uri_id() { return _doc_uri_id; }
	uint32_t& ns_count() { return _ns_count; }
	uint32_t& child_count() { return _child_count; }

	char* baseuri() const;
	char* docuri() const;

	namespace_node& get_namespace(uint32_t);
	node& get_child(uint32_t);

	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);
	void operator delete() {}

public:		// XQuery interface
	node_kind_t node_kind() const { return doc_kind; }
	std::string string_value(context const*) const;
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> document_uri(context *) const;
	rchandle<item_iterator> children(context *) const;
	rchandle<item_iterator> namespaces(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

private:	// ctor,dtor
	document_node() {}
	document_node(document_node&) {}
	~document_node() {}

public:		// output and debugging
	std::ostream& put(std::ostream&,context *) const;

public:		// iterator interface

	class child_iterator : public item_iterator
	{
	protected:
		document_node const* parent_p;
	public:
		child_iterator(context *, document_node const*);
		~child_iterator();
	public:
	 	void open();
		void close();
		rchandle<item> next();
		rchandle<item> peek() const;
		bool done() const;
		void rewind();
	public:
		rchandle<item> operator*() const;
		child_iterator& operator++();
	};

};



/*______________________________________________________________________
| 6.1.5 Collection Node
|_______________________________________________________________________*/

class collection_node : public node
{
public:
	node_kind_t node_kind() const { return collection_kind; }
	rchandle<item_iterator> base_uri(context * ctx) const;
	rchandle<item_iterator> collection_uri(context * ctx) const;
	rchandle<item_iterator> children(context * ctx) const;

public:	//ctor,dtor
	collection_node(nodeid id);
	~collection_node();

public:
	std::ostream& put(std::ostream& os,context * ctx) const { return os; }

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

class element_node : public node
{
protected:
	nodeid _docid;						// cached parent docid
	uint32_t _ns_count;				// count of namespace nodes
	uint32_t _attr_count;			// count of attribute nodes
	uint32_t _child_count;		// count of child nodes
	
	char rest[0];

public:	// storage interface
	nodeid& docid() const { return _docid; }
	uint32_t& ns_count() const { return _ns_count; }
	uint32_t& attr_count() const { return _attr_count; }
	uint32_t& child_count() const { return _child_count; }

	namespace_node& namespace(uint32_t);
	attribute_node& attribute(uint32_t);
	node& child(uint32_t);

	// arena allocation
	void * operator new(size_t, itemstore&);
	void * operator new(size_t, void*);
	void operator delete() {}

public:	// data interface
	node_kind_t node_kind() const { return elem_kind; }
	std::string string_value(context const*) const;
	rchandle<QName> get_name() const;
	rchandle<item_iterator> attributes(context *) const;
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> children(context *) const;
	rchandle<item_iterator> namespace_bindings(context *) const;
	rchandle<item_iterator> namespace_nodes(context *) const;
	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> doc(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

	bool is_nilled() const;
	bool is_id() const { return type & ID_SUB5; }
	bool is_idref() const { return type & IDREF_SUB5; }

private:	//ctor,dtor - lock out
	element_node(element_node const&) {}
	element_node() {}
	~element_node() {}

public:	// output and debugging
	std::ostream& put(std::ostream&,context *) const;

public:	// iterator interface
	class child_iterator : public item_iterator
	{
	protected:
		element_node const* parent_p;
	public:
		child_iterator(context *,element_node const*);
		~child_iterator();
	public:
	 	void open();
		void close();
		rchandle<item> next();
		rchandle<item> peek() const;
		bool done() const;
		void rewind();
	public:
		rchandle<item> operator*() const;
		child_iterator& operator++();
	};
	
	class attr_iterator : public item_iterator
	{
	protected:
		element_node const* parent_p;
	public:
		attr_iterator(context *,element_node const*);
		~attr_iterator();
	public:
	 	void open();
		void close();
		rchandle<item> next();
		rchandle<item> peek() const;
		bool done() const;
		void rewind();
	public:
		rchandle<item> operator*() const;
		attr_iterator& operator++();
	};

	class namespace_iterator : public item_iterator
	{
	protected:
		element_node const* parent_p;
	public:
		namespace_iterator(context *,element_node const*);
		~namespace_iterator();
	public:
	 	void open();
		void close();
		rchandle<item> next();
		rchandle<item> peek() const;
		bool done() const;
		void rewind();
	public:
		rchandle<item> operator*() const;
		attr_iterator& operator++();
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

class attribute_node : public node
{
protected:
	char rest[0];

public:	// storage interface

	// arena allocation
	void * operator new(size_t, itemstore&);
	void * operator new(size_t, void*);
	void operator delete() {}

public:	// data interface
	node_kind_t node_kind() const { return attr_kind; }
	bool is_id() const { return type & ID_SUB5; }
	bool is_idref() const { return type & IDREF_SUB5; }
	rchandle<QName> get_name() const;
	
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	std::string string_value(context const*) const;

private:	//ctor,dtor - lock out
	attribute_node(attribute_node&);
  attribute_node(nodeid id);
  ~attribute_node();

public:		// output,debugging
	std::ostream& put(std::ostream&,context *) const;

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
class namespace_node : public node
{
protected:
	char rest[0];

public:		// storage interface
	node_kind_t node_kind() const { return ns_kind; }
	std::string get_prefix() const;
	std::string get_uri() const;

	// arena allocation
	void * operator new(size_t, itemstore&);
	void * operator new(size_t, void*);
	void operator delete() {}

public:		// XQuery interface
	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	std::string string_value(context const*) const;

private:	//ctor,dtor - lock out
	namespace_node(namespace_node&) {}
	namespace_node() {}
	~namespace_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class pi_node : public node
{
protected:
	char rest[0];

public:		// storage interface
	char * get_target() const;
	char * get_content() const;
	
	// arena allocation
	void * operator new(size_t, itemstore&);
	void * operator new(size_t, void*);

public:		// XQuery interface
	node_kind_t node_kind() const { return pi_kind; }
	std::string string_value(context const*) const;
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	rchandle<item_iterator> node_name(context *) const;

private:	//ctor,dtor - lock out
	pi_node(pi_node&) {}
	pi_node() {}
	~pi_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
| 6.6 Comment Nodes 
|_______________________________________________________________________*/

class comment_node : public node
{
protected:
	char rest[0];
	
public:		// storage interface

	// arena allocation
	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);

public:		// XQUery interface
	enum node_kind_t node_kind() const { return comment_kind; }
	std::string string_value(context const*) const;
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

private:	//ctor,dtor - lock out
	comment_node(comment_node&) {}
	comment_node() {}
	~comment_node() {}

public:		// output, debugging
	std::ostream& put(std::ostream&,context *) const;

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

class text_node : public node
{
protected:
	char rest[0];
	
public:		// storage interface
	char const* content() const { return rest; }
	uint32_t content_length() const;

	// arena allocation
	void* operator new(size_t node_size, itemstore&);
	void* operator new(size_t node_size, void*);
	void operator delete(void*) {}

public:		// accessors
	enum node_kind_t node_kind() const { return text_kind; }
	std::string string_value(context const*) const;
	
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

private://ctor,dtor
	text_node(text_node&) {}
	text_node() {}
	~text_node() {}

public:
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
|
| Binary Nodes have the following properties:
|   * content
|   * parent, possibly empty.
| 
| Binary Nodes must satisfy the following constraint:
|   If the parent of a binary node is not empty, the Binary Node 
|   must not contain zero-length data as its content.  In 
|   addition, Document and Element Nodes can have only one
|   Binary Node child.
|_______________________________________________________________________*/

// stub implementation
class binary_node : public node
{
protected:
	char rest[0];

public:	// accessors
	node_kind_t node_kind(context *) const { return binary_kind; }
	std::string string_value(context const*) const;
 
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> type_name(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

private:	//ctor,dtor
	binary_node(binary_node&) {}
	binary_node(nodeid id) {}
	~binary_node() {}


};


}	/* namespace xqp */
#endif /* XQP_NODE_VALUES_H */
