/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xdm.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

/*______________________________________________________________________
|
| X(uery) D(ata) M(odel) module.
|
| Includes classes supporting each of the 7 node types defined in:
|
|   XQuery 1.0 and XPath 2.0 Data Model (XDM)
|   [http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/
 
#ifndef XQP_XDM_H
#define XQP_XDM_H

#include "data_interface.h"
#include "item.h"
#include "../runtime/context.h"
#include "../util/rchandle.h"

namespace xqp {

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
public:	// 7 nodes types

	enum node_kind_t {
		attr_kind,
		comment_kind,
		doc_kind,
		elem_kind,
		ns_kind,
		pi_kind,
		text_kind
	};

protected:	// node locator

	uint64_t nodeid;

public:	// accessors
	/**
	 *	The dm:node-kind accessor returns a string identifying the kind of 
	 *	node. It will be one of the following, depending on the kind of node: 
	 *	"attribute", "comment", "document", "element", "namespace" 
	 *	"processing-instruction", or "text". 
	 */
	virtual node_kind_t node_kind() const = 0;
	
	/**
	 *	The dm:attributes accessor returns the attributes of a node as a 
	 *	sequence containing zero or more Attribute Nodes. The order of 
	 *	Attribute Nodes is stable but implementation dependent. 
	 */
	rchandle<item_iterator> attributes(context *const) const;
	
	/**
	 *	The dm:base-uri accessor returns the base URI of a node as a sequence 
	 *	containing zero or one URI reference. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;
	
	/**
	 *	The dm:children accessor returns the children of a node as a sequence 
	 *	containing zero or more nodes. 
	 */
	rchandle<item_iterator> children(context *const) const;
	
	/**
	 *	The dm:document-uri accessor returns the absolute URI of the resource 
	 *	from which the Document Node was constructed, if the absolute URI is 
	 *	available. If there is no URI available, or if it cannot be made 
	 *	absolute when the Document Node is constructed, or if it is used on a 
	 *	node other than a Document Node, the empty sequence is returned. 
	 */
	rchandle<item_iterator> document_uri(context *const) const;
	
	/**
	 *	The dm:is-id accessor returns true if the node is an XML ID.
	 */
	rchandle<item_iterator> is_id(context *const) const;
	
	/**
	 *	The dm:is-idrefs accessor returns true if the node is an 
	 *  XML IDREF or IDREFS. 
	 */
	rchandle<item_iterator> is_idrefs(context *const) const;
	
	/**
	 *	The dm:namespace-bindings accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a set of prefix/URI pairs.
	 *	The prefix for the default namespace is the zero length string.
	 *	Note: this accessor and the namespace-nodes accessor provide two views 
	 *	of the same information. 
	 */
	rchandle<item_iterator> namespace_bindings(context *const) const;
	
	/**
	 *	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	 *	namespaces associated with a node as a sequence containing zero or 
	 *	more Namespace Nodes. The order of Namespace Nodes is stable but 
	 *	implementation dependent. 
	 *	Note: this accessor and the namespace-bindings accessor provide two 
	 *	views of the same information.
	 */
	rchandle<item_iterator> namespace_nodes(context *const) const;
	
	/**
	 *	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	 *	Part 1] introduced the nilled mechanism to signal that an element 
	 *	should be accepted as valid when it has no content even when it has a 
	 *	content type which does not require or even necessarily allow empty 
	 *	content. 
	 */
	rchandle<item_iterator> nilled(context *const) const;
	
	/**
	 *	The dm:node-name accessor returns the name of the node as a sequence 
	 *	of zero or one xs:QNames. Note that the QName value includes an 
	 *	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	 */
	virtual rchandle<item_iterator> node_name(context *const) const = 0;
	
	/**
	 *	The dm:parent accessor returns the parent of a node as a sequence 
	 *	containing zero or one nodes. 
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	The dm:string-value accessor returns the string value of a node.
	 */
	std::string string_value(context *const) const;
	
	/**
	 *	The dm:type-name accessor returns the name of the schema type of a 
	 *	node as a sequence of zero or one xs:QNames. 
	 */
	rchandle<item_iterator> type_name(context *const) const;
	
	/**
	 *	The dm:typed-value accessor returns the typed-value of the node as a 
	 *	sequence of zero or more atomic values. 
	 */
	rchandle<item_iterator> typed_value(context *const) const;
	
	/**
	 *	The dm:unparsed-entity-public-id accessor returns the public 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, or if the entity 
	 *	has no public identifier, the empty sequence is returned. 
	 */
	rchandle<item_iterator> unparsed_entity_public_id(
	  context *const,
	  std::string const& entity_name) const;

	/**
	 *	The dm:unparsed-entity-system-id accessor returns the system 
	 *	identifier of an unparsed external entity declared in the specified 
	 *	document. If no entity with the name specified in $entityname exists, 
	 *	or if the entity is not an external unparsed entity, the empty 
	 *	sequence is returned. 
	 */
	rchandle<item_iterator> unparsed_entity_system_id(
	  context *const,
	  std::string const& entity_name) const;


public:	// ctor,dtor
	node(uint64_t _nodeid) : nodeid(_nodeid) {}
	node(node& n) : nodeid(n.nodeid) {}
	node() : nodeid(0) {}
	~node() {}

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
	/**
	 *	node-kind
	 *	@return "document".
	 */
	node_kind_t node_kind() const { return doc_kind; }
	
	/**
	 *	base_uri
	 *	@return the value of the base-uri property if it exists and is not 
	 *					empty, otherwise returns the empty sequence. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;
	
	/**
	 *	children
	 *	@returns the value of the children property.
	 */
	rchandle<item_iterator> children(context *const) const;
	
	/**
	 *	document_uri
	 *	@returns the absolute URI of the resource from which the Document 
	 *						Node was constructed, or the empty sequence if no such
	 *						absolute URI is available. 
	 */
	rchandle<item_iterator> document_uri(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the string-value property.
	 */
	std::string string_value(context *const) const;
	
	/**
	 *	typed-value
	 *	@return the value of the typed-value property.
	 */
	rchandle<item_iterator> typed_value(context *const) const;
	
	/**
	 *	unparsed-entity-public-id
	 *	@return the public identifier of the specified unparsed entity or 
	 *					the empty sequence if no such entity exists. 
	 */
  rchandle<item_iterator> unparsed_entity_public_id(
    context *const,
    std::string const& entity_name) const;
	
	/**
	 *	unparsed-entity-system-id
	 *	@return the system identifier of the specified unparsed entity or 
	 *					the empty sequence if no such entity exists. 
	 */
	rchandle<item_iterator> unparsed_entity_system_id(
	  context *const,
	  std::string const& entity_name) const;

public:	//ctor,dtor
	//document_node(infoset const&);
	//document_node(psvi const&);
	document_node(uint64_t _nodeid) : node(_nodeid) {}
	document_node() {}
	~document_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

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
	/**
	 *	node-kind
	 *	@return "element".
	 */
	node_kind_t node_kind() const { return elem_kind; }
	
	/**
	 *	attributes
	 *	@return the value of the attributes property. The order of 
	 *					Attribute Nodes is stable but implementation dependent. 
	 */
	rchandle<item_iterator> attributes(context *const) const;

	/**
	 *	base_uri
	 *	@return the value of the base-uri property if it exists and is not 
	 *					empty. Otherwise, if the element has a parent, returns the 
	 *					value of the dm:base-uri of its parent; otherwise, returns
	 *					the empty sequence. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;

	/**
	 *	children
	 *	@returns the value of the children property.
	 */
	rchandle<item_iterator> children(context *const) const;
	
	/**
	 *	is_id
	 *	@return the value of the is-id property.
	 */
	rchandle<item_iterator> is_id(context *const) const;

	/**
	 *	is_idrefs
	 *	@return the value of the is-idrefs property.
	 */
	rchandle<item_iterator> is_idrefs(context *const) const;

	/**
	 *	namespace-bindings
	 *	@return the value of the namespaces property as a set of 
	 *					prefix/URI pairs. 
	 */
	rchandle<item_iterator> namespace_bindings(context *const) const;
	
	/**
	 *	namespace-nodes
	 *	@return the value of the namespaces property as a sequence of 
	 *					Namespace Nodes. The order of Namespace Nodes is stable but 
	 *					implementation dependent. 
	 */
	rchandle<item_iterator> namespace_nodes(context *const) const;
	
	/**
	 *	nilled
	 *	@return the value of the nilled property.
	 */
	rchandle<item_iterator> nilled(context *const) const;

	/**
	 *	node-name
	 *	@return the value of the node-name property.
	 */
	rchandle<item_iterator> node_name(context *const) const;
	
	/**
	 *	parent
	 *	@return the value of the parent property.
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the string-value property.
	 */
	std::string string_value(context *const) const;

	/**
	 *	type-name
	 *	@return the value of the type-name property.
	 */
	rchandle<item_iterator> type_name(context *const) const;

	/**
	 *	typed-value
	 *	@return the value of the typed-value property.
	 */
	rchandle<item_iterator> typed_value(context *const) const;

	/**
	 *	unparsed-entity-public-id
	 *	@return the public identifier of the specified unparsed entity or 
	 *					the empty sequence if no such entity exists. 
	 */
	rchandle<item_iterator> unparsed_entity_public_id(
	  context *const,
	  std::string const& entityname) const;
	
	/**
	 *	unparsed-entity-system-id
	 *	@return the system identifier of the specified unparsed entity or 
	 *					the empty sequence if no such entity exists. 
	 */
	rchandle<item_iterator> unparsed_entity_system_id(
	  context *const,
	  std::string const& entityname) const;


public:	//ctor,dtor
	//element_node(infoset const&);
	//element_node(psvi const&);
	element_node(uint64_t _nodeid) : node(_nodeid) {}
	element_node() {}
	~element_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

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
	/**
	 *	node-kind
	 *	@return "attribute".
	 */
	node_kind_t node_kind() const { return attr_kind; }
	
	/**
	 *	base_uri
	 *	@return if the attribute has a parent, returns the value of the 
	 *					base_uri of its parent; otherwise it returns the empty
	 *					sequence. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;
	
	/**
	 *	is_id
	 *	@return the value of the is-id property.
	 */
	rchandle<item_iterator> is_id(context *const) const;

	/**
	 *	is_idrefs
	 *	@return the value of the is-idrefs property.
	 */
	rchandle<item_iterator> is_idrefs(context *const) const;

	/**
	 *	node-name
	 *	@return the value of the node-name property.
	 */
	rchandle<item_iterator> node_name(context *const) const;
	
	/**
	 *	parent
	 *	@return the value of the parent property.
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the string-value property.
	 */
	std::string string_value(context *const) const;

	/**
	 *	type-name
	 *	@return the value of the type-name property.
	 */
	rchandle<item_iterator> type_name(context *const) const;

	/**
	 *	typed-value
	 *	@return the value of the typed-value property.
	 */
	rchandle<item_iterator> typed_value(context *const) const;

public:	//ctor,dtor
	//attribute_node(infoset const&);
  //attribute_node(psvi const&);
  attribute_node(uint64_t _nodeid) : node(_nodeid) {}
  attribute_node() {}
  ~attribute_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

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
	/**
	 *	node-kind
	 *	@return "namespace".
	 */
	node_kind_t node_kind() const { return ns_kind; }

	/**
	 *	node-name
	 *	@return If the prefix is not empty, returns an xs:QName with the
	 *					value of the prefix property in the local-name and an empty
	 *					namespace name, otherwise returns the empty sequence. 
	 */
	rchandle<item_iterator> node_name(context *const) const;
	
	/**
	 *	parent
	 *	@return the value of the parent property.
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the uri property.
	 */
	std::string string_value(context *const) const;

	/**
	 *	typed-value
	 *
	 *	@return the value of the uri property as an xs:string.
	 */
	rchandle<item_iterator> typed_value(context *const) const;

public:	//ctor,dtor
	//ns_node(infoset const&);
	//ns_node(psvi const&);
	ns_node(uint64_t _nodeid) : node(_nodeid) {}
	ns_node() {}
	~ns_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

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
	/**
	 *	node-kind
	 *	@return "namespace".
	 */
	node_kind_t node_kind(context *const) const { return pi_kind; }
	
	/**
	 *	base_uri
	 *	@return the value of the base-uri property if it exists and is not 
	 *					empty. Otherwise, if the processing instruction has a parent,
	 *					returns the value of the dm:base-uri of its parent; otherwise,
	 *					returns the empty sequence. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;

	/**
	 *	node-name
	 *	@return If the prefix is not empty, returns an xs:QName with the
	 *					value of the prefix property in the local-name and an empty
	 *					namespace name, otherwise returns the empty sequence. 
	 */
	rchandle<item_iterator> node_name(context *const) const;
	
	/**
	 *	parent
	 *	@return the value of the parent property.
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the uri property.
	 */
	std::string string_value(context *const) const;

	/**
	 *	typed-value
	 *	@return the value of the uri property as an xs:string.
	 */
	rchandle<item_iterator> typed_value(context *const) const;

public:	//ctor,dtor
	//pi_node(infoset const&);
	//pi_node(psvi const&);
	pi_node(uint64_t _nodeid) : node(_nodeid) {}
	pi_node() {}
	~pi_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

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
	/**
	 *	node-kind
	 *	@return "text".
	 */
	node_kind_t node_kind(context *const) const { return text_kind; }
	
	/**
	 *	base_uri
	 *	@return the value of the base-uri property of the parent;
	 *         otherwise, returns the empty sequence. 
	 */
	rchandle<item_iterator> base_uri(context *const) const;
	
	/**
	 *	parent
	 *	@return the value of the parent property.
	 */
	rchandle<item_iterator> parent(context *const) const;
	
	/**
	 *	string-value
	 *	@return the value of the content property.
	 */
	std::string string_value(context *const) const;

	/**
	 *	type-name
	 *	@return xs:untypedAtomic.
	 */
	rchandle<item_iterator> type_name(context *const) const;

	/**
	 *	typed-value
	 *	@return the value of the content property as an xs:untypedAtomic.
	 */
	rchandle<item_iterator> typed_value(context *const) const;

public:	//ctor,dtor
	//text_node(infoset const&);
	//text_node(psvi const&);
	text_node(uint64_t _nodeid) : node(_nodeid) {}
	text_node() {}
	~text_node() {}

public:	// infoset map
	//rchandel<infoset> infoset_map() const;

};


}	/** namespace xqp */
#endif /* XQP_XDM_H */
