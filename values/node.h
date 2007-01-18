/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
 
#ifndef XQP_NODE_H
#define XQP_NODE_H

#include "values.h"
#include "../context/context.h"
#include "../runtime/item_iterator.h"
#include "../util/rchandle.h"

namespace xqp {


/*______________________________________________________________________
| Nodeid
|_______________________________________________________________________*/

class nodeid
{
public:
	nodeid() {}
	~nodeid() {}

public:
	bool operator==(nodeid const&) const;

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
protected:
	nodeid id;

public:	// 8 nodes types
	enum node_kind_t {
		doc_kind,
		elem_kind,
		attr_kind,
		ns_kind,
		pi_kind,
		text_kind,
		comment_kind,
		binary_kind,
		collection_kind,
		uninitialized_kind
	};

public:	// accessors
	/**
	 *	Return an opaque, implimentation-defined node identifier.
	 */
	nodeid get_nodeid() const;

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
	std::string string_value(context const&) const;
	
	/**
	 *	The dm:attributes accessor returns the attributes of a node as a 
	 *	sequence containing zero or more Attribute Nodes. The order of 
	 *	Attribute Nodes is stable but implementation dependent. 
	 */
	virtual item_iterator attributes(context const&) const;
	
	/**
	 *	The dm:base-uri accessor returns the base URI of a node as a sequence 
	 *	containing zero or one URI reference. 
	 */
	virtual item_iterator base_uri(context const&) const;
	
	/**
	 *	The dm:children accessor returns the children of a node as a sequence 
	 *	containing zero or more nodes. 
	 */
	virtual item_iterator children(context const&) const;
	
	/**
	 *	The dm:document-uri accessor returns the absolute URI of the resource 
	 *	from which the Document Node was constructed, if the absolute URI is 
	 *	available. If there is no URI available, or if it cannot be made 
	 *	absolute when the Document Node is constructed, or if it is used on a 
	 *	node other than a Document Node, the empty sequence is returned. 
	 */
	virtual item_iterator document_uri(context const&) const;
	
	/**
	 *	The dm:is-id accessor returns true if the node is an XML ID.
	 */
	virtual bool is_id(context const&) const;
	
	/**
	 *	The dm:is-idrefs accessor returns true if the node is an 
	 *  XML IDREF or IDREFS. 
	 */
	virtual bool is_idrefs(context const&) const;
	
	/**
	 *	The dm:namespace-bindings accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a set of prefix/URI pairs.
	 *	The prefix for the default namespace is the zero length string.
	 *	Note: this accessor and the namespace-nodes accessor provide two views 
	 *	of the same information. 
	 */
	virtual item_iterator namespace_bindings(context const&) const;
	
	/**
	 *	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a sequence containing zero or 
	 *	more Namespace Nodes. The order of Namespace Nodes is stable but 
	 *	implementation dependent. 
	 *	Note: this accessor and the namespace-bindings accessor provide two 
	 *	views of the same information.
	 */
	virtual item_iterator namespace_nodes(context const&) const;
	
	/**
	 *	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	 *	Part 1] introduced the nilled mechanism to signal that an element 
	 *	should be accepted as valid when it has no content even when it has a 
	 *	content type which does not require or even necessarily allow empty 
	 *	content. 
	 */
	virtual bool nilled(context const&) const;
	
	/**
	 *	The dm:node-name accessor returns the name of the node as a sequence 
	 *	of zero or one xs:QNames. Note that the QName value includes an 
	 *	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	 */
	virtual item_iterator node_name(context const&) const;
	
	/**
	 *	The dm:parent accessor returns the parent of a node as a sequence 
	 *	containing zero or one nodes. 
	 */
	virtual item_iterator parent(context const&) const;
	
	/**
	 *	The dm:type-name accessor returns the name of the schema type of a 
	 *	node as a sequence of zero or one xs:QNames. 
	 */
	virtual item_iterator type_name(context const&) const;
	
	/**
	 *	The dm:typed-value accessor returns the typed-value of the node as a 
	 *	sequence of zero or more atomic values. 
	 */
	virtual item_iterator typed_value(context const&) const;
	
	/**
	 *	The dm:unparsed-entity-public-id accessor returns the public 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, or if the entity 
	 *	has no public identifier, the empty sequence is returned. 
	 */
	virtual item_iterator unparsed_entity_public_id(
	  context const&,
	  std::string const& entity_name) const;

	/**
	 *	The dm:unparsed-entity-system-id accessor returns the system 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, the empty 
	 *	sequence is returned. 
	 */
	virtual item_iterator unparsed_entity_system_id(
	  context const&,
	  std::string const& entity_name) const;


public:	// ctor,dtor
	node(nodeid _id) : id(id) {}
	node(node& n) : id(n.id) {}
	node() : id() {}
	virtual ~node() {}

public:	// operator overloading
	//node& operator=(node&);
	//bool operator==(node&);
	//ostream& operator<<(ostream&);

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
class document_node : public node
{
public:
	nodeid get_nodeid() const;
	node_kind_t node_kind() const { return doc_kind; }
	std::string string_value(context const&) const;

	item_iterator base_uri(context const&) const;
	item_iterator children(context const&) const;
	item_iterator document_uri(context const&) const;
	item_iterator typed_value(context const&) const;

  item_iterator unparsed_entity_public_id(
    context const&,
    std::string const& entity_name) const;
	item_iterator unparsed_entity_system_id(
	  context const&,
	  std::string const& entity_name) const;

public:	//ctor,dtor
	document_node(nodeid id) : node(id) {}
	document_node() : node() {}
	~document_node() {}

};


class collection_node : public node
{
public:
	nodeid get_nodeid() const;
	node_kind_t node_kind() const { return collection_kind; }
	item_iterator base_uri(context const&) const;
	item_iterator collection_uri(context const&) const;
	item_iterator children(context const&) const;

public:	//ctor,dtor
	collection_node(nodeid id) : node(id) {}
	collection_node() : node() {}
	~collection_node() {}

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
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind() const { return elem_kind; }
	std::string string_value(context const&) const;

	item_iterator attributes(context const&) const;
	item_iterator base_uri(context const&) const;
	item_iterator children(context const&) const;
	item_iterator namespace_bindings(context const&) const;
	item_iterator namespace_nodes(context const&) const;
	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator type_name(context const&) const;
	item_iterator typed_value(context const&) const;
	item_iterator unparsed_entity_public_id(
	  context const&,
	  std::string const& entityname) const;
	item_iterator unparsed_entity_system_id(
	  context const&,
	  std::string const& entityname) const;

	bool is_id(context const&) const;
	bool is_idrefs(context const&) const;
	bool nilled(context const&) const;

public:	//ctor,dtor
	element_node(nodeid id) : node(id) {}
	element_node() : node() {}
	~element_node() {}

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
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind() const { return attr_kind; }
	std::string string_value(context const&) const;

	item_iterator base_uri(context const&) const;
	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator type_name(context const&) const;
	item_iterator typed_value(context const&) const;

	bool is_id(context const&) const;
	bool is_idrefs(context const&) const;

public:	//ctor,dtor
  attribute_node(nodeid id) : node(id) {}
  attribute_node() : node() {}
  ~attribute_node() {}

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
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind() const { return ns_kind; }
	std::string string_value(context const&) const;

	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;

public:	//ctor,dtor
	ns_node(nodeid id) : node(id) {}
	ns_node() : node() {}
	~ns_node() {}

};


/*______________________________________________________________________
| 6.5
|	Processing instructions have the following properties: 
|	
|	 * target
|	 * content
|	 * base-uri, possibly empty
|	 * parent, possibly empty
|	
|	Processing Instruction Nodes must satisfy the following constraints.
|	
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class pi_node : public node
{
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind(context const&) const { return pi_kind; }
	std::string string_value(context const&) const;

	item_iterator base_uri(context const&) const;
	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;

public:	//ctor,dtor
	pi_node(nodeid id) : node(id) {}
	pi_node() : node() {}
	~pi_node() {}

};


/*______________________________________________________________________
|
| Text Nodes have the following properties:
| 
|   * content
|   * parent, possibly empty.
| 
| Text Nodes must satisfy the following constraint:
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
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind(context const&) const { return text_kind; }
	std::string string_value(context const&) const;

	item_iterator base_uri(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator type_name(context const&) const;
	item_iterator typed_value(context const&) const;

public:	//ctor,dtor
	text_node(nodeid id) : node(id) {}
	text_node() : node() {}
	~text_node() {}

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

class binary_node : public node
{
public:	// accessors
	nodeid get_nodeid() const;
	node_kind_t node_kind(context const&) const { return text_kind; }
	std::string string_value(context const&) const;

	item_iterator base_uri(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator type_name(context const&) const;
	item_iterator typed_value(context const&) const;

public:	//ctor,dtor
	binary_node(nodeid id) : node(id) {}
	binary_node() : node() {}
	~binary_node() {}

};


}	/* namespace xqp */
#endif /* XQP_NODE_TYPES_H */
