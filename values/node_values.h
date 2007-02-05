/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
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

#include "../runtime/iterator.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"

namespace xqp {

class context;


/*______________________________________________________________________
| Nodeid
|_______________________________________________________________________*/

class nodeid 
{
public:
	uint64_t id;

	nodeid(uint64_t _id) : id(_id) {}
	nodeid() : id(0) {}
	~nodeid() {}

	bool operator==(nodeid const& n) const { return id==n.id;  }

};



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
	nodeid id;
	nodeid parentid;

public:	// accessors
	/**
	 *	Get/set node identifiers.
	 */
	nodeid get_nodeid() const;
	nodeid get_parentid() const;
	void set_parentid(nodeid);

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
	virtual item_type const& get_type(context *) const;

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

public:	// ctor,dtor
	node(nodeid _id) : id(_id), parentid(0) {}
	node(nodeid _id, nodeid _parentid) : id(_id), parentid(_parentid) {}
	node(node& n) : id(n.id), parentid(n.parentid) {}
	node() : id(0), parentid(0) {}
	virtual ~node() {}

public:
	//node& operator=(node&);
	//bool operator==(node&);
	//ostream& operator<<(ostream&);

};


class attribute_node;
class comment_node;
class element_node;
class ns_node;
class pi_node;
class text_node;


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
	nodeid docid;
	std::string baseuri;
	std::string docuri;
	std::vector<nodeid> child_hv;
	hashmap<std::string> entitymap;

public:
	node_kind_t node_kind() const { return doc_kind; }
	std::string get_baseuri() const { return baseuri; }
	std::string get_docuri() const { return docuri; }
	uint32_t child_count() const { return child_hv.size(); }
	
public:	// evaluator interface
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> children(context *) const;
	rchandle<item_iterator> document_uri(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

	std::string string_value(context const*) const;
	
  rchandle<item_iterator> unparsed_entity_public_id(
    context *,
    std::string const& entity_name) const;
	
	rchandle<item_iterator> unparsed_entity_system_id(
	  context *,
	  std::string const& entity_name) const;

public:	// factory interface
	bool get_entity(std::string const& entity, std::string & val) const
		{ return entitymap.get(entity, val); }
	void put_entity(std::string const& entity, std::string const& val)
		{ entitymap.put(entity, val); }

	void add_node(rchandle<node>);
	void add_node(context *, nodeid);

public:	//ctor,dtor
	document_node(
		nodeid id,
		nodeid docid,
		std::string const& baseuri,
		std::string const& docuri);

	document_node(nodeid id);
	~document_node();

public:	// i/o interface
	std::ostream& put(std::ostream&,context *) const;

public:	// iterator interface
	class child_iterator : public item_iterator
	{
	protected:
		document_node const* parent_p;
		std::vector<nodeid>::const_iterator child_it;
		std::vector<nodeid>::const_iterator it_end;
		
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
| 3.	If a node N is among the children of an element E, then the 
|			parent of N must be E. 
| 4.	Exclusive of Attribute and Namespace Nodes, if a node N has a 
|			parent element E, then N must be among the children of E. (Attribute 
|			and Namespace Nodes have a parent, but they do not appear among the 
|			children of their parent.)  The data model permits Element Nodes
|     without parents (to represent partial results during expression
|     processing, for example).  Such Element Nodes must not appear
|     among the children of any other node. 
| 5.	If an Attribute Node A is among the attributes of an element E, 
|			then the parent of A must be E. 
| 6.	If an Attribute Node A has a parent element E, then A must be 
|			among the attributes of E.  The data model permits Attribute Nodes
|     without parents. Such Attribute Nodes must not appear among the
|     attributes of any Element Node. 
| 7.	If a Namespace Node N is among the namespaces of an element E, 
|			then the parent of N must be E. 
| 8.	If a Namespace Node N has a parent element E, then N must be 
|			among the namespaces of E.  The data model permits Namespace Nodes
|     without parents. Such Namespace Nodes must not appear among the
|     namespaces of any Element Node.
| 9.	If the dm:type-name of an Element Node is xs:untyped, then the 
|			dm:type-name of all its descendant elements must also be xs:untyped 
|			and the dm:type-name of all its Attribute Nodes must be 
|			xs:untypedAtomic. 
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
	friend class elem_child_iterator;
	friend class elem_attr_iterator;

protected:
	nodeid docid;
	rchandle<QName> name_h;
	item_type type;
	std::vector<nodeid> child_hv;
	std::vector<nodeid> attr_hv;
	std::vector<nodeid> ns_hv;
	bool nilled_b;
	bool id_b;
	bool idrefs_b;

public:	// storage interface
	nodeid get_docid() const { return docid; }

public:	// evaluator interface
	node_kind_t node_kind() const { return elem_kind; }
	rchandle<QName> get_name() const { return name_h; }
	uint32_t child_count() const { return child_hv.size(); }
	uint32_t attr_count() const { return attr_hv.size(); }
	uint32_t ns_count() const { return ns_hv.size(); }
	
	rchandle<item_iterator> attributes(context *) const;
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> children(context *) const;
	rchandle<item_iterator> namespace_bindings(context *) const;
	rchandle<item_iterator> namespace_nodes(context *) const;
	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> doc(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	
	bool is_id(context *) const;
	bool is_idrefs(context *) const;
	bool nilled(context *) const;

	item_type const& get_type(context *) const;
	std::string string_value(context const*) const;

public:	// factory interface
	void add_node(rchandle<node>);
	void add_node(context *, nodeid);

	bool get_nilled() const { return nilled_b; }
	bool get_id() const { return id_b; }
	bool get_idrefs() const { return idrefs_b; }

	void set_nilled(bool b) { nilled_b = b; }
	void set_id(bool b) { id_b = b; }
	void set_idrefs(bool b) { idrefs_b = b; }

public:	//ctor,dtor
	element_node(
		nodeid id,
		nodeid parentid,
		nodeid docid,
		rchandle<QName> name_h);

	element_node(nodeid id);
	~element_node();

public:	// i/o interface
	std::ostream& put(std::ostream&,context *) const;

public:	// iterator interface
	class child_iterator : public item_iterator
	{
	protected:
		element_node const* parent_p;
		std::vector<nodeid>::const_iterator child_it;
		std::vector<nodeid>::const_iterator it_end;
		
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
		std::vector<nodeid>::const_iterator attr_it;
		std::vector<nodeid>::const_iterator it_end;
		
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
	rchandle<QName> name_h;
	item_type type;
	std::string val;
	bool id_b;
	bool idrefs_b;

public:	// evaluator interface
	node_kind_t node_kind() const { return attr_kind; }
	item_type const& get_type(context *) const;
	rchandle<QName> get_name() const { return name_h; }
	std::string get_val() const { return val; }
	
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

	bool is_id(context *) const;
	bool is_idrefs(context *) const;

	std::string string_value(context const*) const;

public:	//ctor,dtor
	attribute_node(
		nodeid id,
		nodeid parentid,
		rchandle<QName> name_h,
		std::string const& val);

  attribute_node(nodeid id);
  ~attribute_node();

public:
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
|
| 6.4 Namespace nodes
|	
|	 1. If a Namespace Node N is among the namespaces of an element E, 
|			then the parent of N must be E. 
|	 2. If a Namespace Node N has a parent element E, then N must be 
|			among the namespaces of E. 
|	
|	The data model permits Namespace Nodes without parents. 
|_______________________________________________________________________*/
class ns_node : public node
{
protected:
	std::string prefix;
	std::string uri;

public:	// accessors
	node_kind_t node_kind() const { return ns_kind; }
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }

	rchandle<item_iterator> node_name(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	
	std::string string_value(context const*) const;

public:	//ctor,dtor

	ns_node(
		nodeid id,
		nodeid parent_id,
		std::string const& prefix,
		std::string const& uri);

	ns_node(nodeid id);
	~ns_node();

public:
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class pi_node : public node
{
protected:
	std::string target;
	std::string content;
	std::string baseuri;

public:	// accessors
	node_kind_t node_kind() const { return pi_kind; }
	std::string get_target() const { return target; }
	std::string get_content() const { return content; }
	
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	rchandle<item_iterator> node_name(context *) const;

	std::string string_value(context const*) const;

public:	//ctor,dtor

	pi_node(
		nodeid id,
		nodeid parentid,
		std::string const& target,
		std::string const& content,
		std::string const& baseuri);

	pi_node(nodeid id);
	~pi_node();

public:
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
| 6.6 Comment Nodes 
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

class comment_node : public node
{
protected:
	std::string content;
	
public:	// accessors
	enum node_kind_t node_kind() const { return comment_kind; }
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	
	std::string string_value(context const*) const;

public:	//ctor,dtor

	comment_node(
		nodeid,
		nodeid parentid,
		std::string const& content);

	comment_node(nodeid id);
	~comment_node();

public:
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
	std::string content;
	
public:	// accessors
	enum node_kind_t node_kind() const { return text_kind; }
	char const* get_content() const { return content.c_str(); }
	uint32_t get_content_length() const { return content.length(); }
	
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> typed_value(context *) const;
	rchandle<item_iterator> node_name(context *) const;
	
	std::string string_value(context const*) const;

public:	//ctor,dtor

	text_node(
		nodeid,
		nodeid parentid,
		std::string const& content);

	text_node(
		nodeid,
		nodeid parentid,
		char const* data,
		uint32_t datalen);

	text_node(nodeid id);
	~text_node();

public:
	std::ostream& put(std::ostream&,context *) const;

};



/*______________________________________________________________________
|
| Binary Nodes have the following properties:
| 
|   * content
|   * parent, possibly empty.
| 
| Binary Nodes must satisfy the following constraint:
| 
|   If the parent of a binary node is not empty, the Binary Node 
|   must not contain zero-length data as its content.  In 
|   addition, Document and Element Nodes can have only one
|   Binary Node child.
|_______________________________________________________________________*/

// stub implementation
class binary_node : public node
{
public:	// accessors
	node_kind_t node_kind(context *) const { return binary_kind; }
	std::string string_value(context const*) const;
 
	rchandle<item_iterator> base_uri(context *) const;
	rchandle<item_iterator> parent(context *) const;
	rchandle<item_iterator> type_name(context *) const;
	rchandle<item_iterator> typed_value(context *) const;

public:	//ctor,dtor
	binary_node(nodeid id);
	~binary_node();

};


}	/* namespace xqp */
#endif /* XQP_NODE_VALUES_H */
