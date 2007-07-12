/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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

#include "values.h"
#include "itemid.h"
#include "util/rchandle.h"

#include <string>

namespace xqp {

class zorba;


// (see "ord-path" paper - for nodeid implementation (sigmod 2005-06)
// (check ms; good duo-decimal node number implementation)


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

class node : virtual public item
{
public:		// accessors
	virtual itemid_t id() const = 0;
	virtual itemid_t parentid() const = 0;
	virtual std::string toXML() const = 0;

public:		// XQuery interface
	virtual sequence_type_t node_kind() const = 0;

	virtual iterator_t string_value(zorba*) const = 0;
	virtual iterator_t base_uri(zorba*) const = 0;
	virtual iterator_t document_uri(zorba*) const = 0;
	virtual iterator_t type_name(zorba*) const = 0;
	virtual iterator_t typed_value(zorba*) const = 0;
	virtual iterator_t parent(zorba*) const = 0;
	virtual iterator_t node_name(zorba*) const = 0;
	virtual iterator_t attributes(zorba*) const = 0;
	virtual iterator_t children(zorba*) const = 0;
	virtual iterator_t namespace_nodes(zorba*) const = 0;

	virtual bool is_id() const = 0;
	virtual bool is_idrefs() const = 0;
	virtual bool nilled() const = 0;
	
	/* add: operator<(), operator==()    */
	/* remove: id(), parentid()          */

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

class document_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return documentNode; }

	virtual iterator_t string_value(zorba*) const = 0;
	virtual iterator_t base_uri(zorba*) const = 0;
	virtual iterator_t document_uri(zorba*) const = 0;
	virtual iterator_t typed_value(zorba*) const = 0;
	virtual iterator_t children(zorba*) const = 0;
	virtual iterator_t namespace_nodes(zorba*) const = 0;

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

class element_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return elementNode; }

	virtual iterator_t string_value(zorba*) const = 0;
	virtual iterator_t base_uri(zorba*) const = 0;
	virtual iterator_t parent(zorba*) const = 0;
	virtual iterator_t type_name(zorba*) const = 0;
	virtual iterator_t typed_value(zorba*) const = 0;
	virtual iterator_t node_name(zorba*) const = 0;
	virtual iterator_t attributes(zorba*) const = 0;
	virtual iterator_t children(zorba*) const = 0;
	virtual iterator_t namespace_nodes(zorba*) const = 0;

	virtual bool is_id() const = 0;
	virtual bool is_idrefs() const = 0;
	virtual bool nilled() const = 0;

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

class attribute_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return attributeNode; }

	virtual iterator_t string_value(zorba*) const = 0;
	virtual iterator_t type_name(zorba*) const = 0;
	virtual iterator_t typed_value(zorba*) const = 0;
	virtual iterator_t parent(zorba*) const = 0;
	virtual iterator_t node_name(zorba*) const = 0;

	virtual bool is_id() const = 0;
	virtual bool is_idrefs() const = 0;

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
class namespace_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return namespaceNode; }

	virtual iterator_t string_value(zorba*) const = 0;		// URI
	virtual iterator_t node_name(zorba*) const = 0;				// prefix
	virtual iterator_t typed_value(zorba*) const = 0;			// URI
	virtual iterator_t parent(zorba*) const = 0;
	
};


/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class pi_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return processingInstructionNode; }

	virtual iterator_t string_value(zorba*) const = 0;	// content
	virtual iterator_t base_uri(zorba*) const = 0;			// parent baseuri
	virtual iterator_t node_name(zorba*) const = 0;			// target
	virtual iterator_t typed_value(zorba*) const = 0;		// content
	virtual iterator_t parent(zorba*) const = 0;

};


/*______________________________________________________________________
| 6.6 Comment Nodes 
|_______________________________________________________________________*/

class comment_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return commentNode; }

	virtual iterator_t string_value(zorba*) const = 0;	// content
	virtual iterator_t base_uri(zorba*) const = 0;			// parent baseuri	
	virtual iterator_t node_name(zorba*) const = 0;			// 
	virtual iterator_t typed_value(zorba*) const = 0;		// content
	virtual iterator_t parent(zorba*) const = 0;

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

class text_node : virtual public node
{
public:
	virtual sequence_type_t node_kind() const
		{ return textNode; }

	virtual iterator_t string_value(zorba*) const = 0;	// content
	virtual iterator_t base_uri(zorba*) const = 0;				// parent baseuri
	virtual iterator_t typed_value(zorba*) const = 0;			// content
	virtual iterator_t parent(zorba*) const = 0;			

};

}	/* namespace xqp */
#endif /* XQP_NODES_H */

