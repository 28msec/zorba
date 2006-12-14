/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xdm.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_XDM_H
#define XQP_XDM_H

#include "values.h"
#include "../types/xsd.h"

namespace xqp {

class atomic_value;
class node;
class uri;


class atomic_value_iterator
{
public:	// iterator interface
	/*______________________________________________________________________
	|	open
	|
	|	Allocate the iterator.
	|	@return error code
	|_______________________________________________________________________*/
	int open(uri&);

	/*______________________________________________________________________
	|	next
	|
	|	Return the next value for this iterator.
	|	@return error code
	|_______________________________________________________________________*/
	int next(atomic_value&);

	/*______________________________________________________________________
	|	done
	|
	|	Return true if the iterator has no more nodes.
	|_______________________________________________________________________*/
	bool done();

	/*______________________________________________________________________
	|	close
	|
	|	Release iterator resources.
	|	@return error code
	|_______________________________________________________________________*/
	int close();

};




class node_iterator
{
public:	// iterator interface
	/*______________________________________________________________________
	|	open
	|
	|	Allocate the iterator.
	|	@return error code
	|_______________________________________________________________________*/
	int open(uri&);

	/*______________________________________________________________________
	|	next
	|
	|	Return the next node for this iterator.
	|	@return error code
	|_______________________________________________________________________*/
	int next(node&);

	/*______________________________________________________________________
	|	done
	|
	|	Return true if the iterator has no more nodes.
	|_______________________________________________________________________*/
	bool done();

	/*______________________________________________________________________
	|	close
	|
	|	Release iterator resources.
	|	@return error code
	|_______________________________________________________________________*/
	int close();

};




/*______________________________________________________________________
|	
|	All nodes must satisfy the following general constraints:
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
class node
{
public:	// 7 nodes types
	enum node_kind_t {
		attribute,
		comment,
		document,
		element,
		namespace ,
		processing-instruction,
		text
	};

public:	// accessors
	/*______________________________________________________________________
	|
	|	The dm:attributes accessor returns the attributes of a node as a 
	|	sequence containing zero or more Attribute Nodes. The order of 
	|	Attribute Nodes is stable but implementation dependent. 
	|_______________________________________________________________________*/
	node_iterator attributes();
	
	/*______________________________________________________________________
	|
	|	The dm:base-uri accessor returns the base URI of a node as a sequence 
	|	containing zero or one URI reference. For more information about base 
	|	URIs, see [XML Base]. 
	|_______________________________________________________________________*/
	atomic_value_iterator base_uri() const;
	
	/*______________________________________________________________________
	|
	|	The dm:children accessor returns the children of a node as a sequence 
	|	containing zero or more nodes. 
	|_______________________________________________________________________*/
	node_iterator children() const;
	
	/*______________________________________________________________________
	|
	|	The dm:document-uri accessor returns the absolute URI of the resource 
	|	from which the Document Node was constructed, if the absolute URI is 
	|	available. If there is no URI available, or if it cannot be made 
	|	absolute when the Document Node is constructed, or if it is used on a 
	|	node other than a Document Node, the empty sequence is returned. 
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri() const;
	
	/*______________________________________________________________________
	|
	|	The dm:is-id accessor returns true if the node is an XML ID. Exactly 
	|	what constitutes an ID depends in part on how the data model was 
	|	constructed, see 6.2 Element Nodes and 6.3 Attribute Nodes. 
	|_______________________________________________________________________*/
	bool is_id() const;
	
	/*______________________________________________________________________
	|
	|	The dm:is-idrefs accessor returns true if the node is an XML IDREF or 
	|	IDREFS. Exactly what constitutes an IDREF or IDREFS depends in part on 
	|	how the data model was constructed, see 6.2 Element Nodes and 6.3 
	|	Attribute Nodes. 
	|_______________________________________________________________________*/
	bool is_idrefs() const;
	
	/*______________________________________________________________________
	|
	|	The dm:namespace-bindings accessor returns the dynamic, in-scope 
	|	namespaces associated with a node as a set of prefix/URI pairs, using 
	|	an implementation-dependent representation. 
	|	
	|	The prefix for the default namespace is the zero length string.
	|	
	|	Note: this accessor and the namespace-nodes accessor provide two views 
	|	of the same information. 
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings() const;
	
	/*______________________________________________________________________
	|
	|	The dm:namespace-nodes accessor returns the dynamic, in-scope 
	|	namespaces associated with a node as a sequence containing zero or 
	|	more Namespace Nodes. The order of Namespace Nodes is stable but 
	|	implementation dependent. 
	|	
	|	Note: this accessor and the namespace-bindings accessor provide two 
	|	views of the same information. Implementations that do not need to 
	|	expose Namespace Nodes might choose not to implement this accessor. 
	|_______________________________________________________________________*/
	node_iterator namespace_nodes() const;
	
	/*______________________________________________________________________
	|
	|	The dm:nilled accessor returns true if the node is "nilled". [Schema 
	|	Part 1] introduced the nilled mechanism to signal that an element 
	|	should be accepted as valid when it has no content even when it has a 
	|	content type which does not require or even necessarily allow empty 
	|	content. 
	|_______________________________________________________________________*/
	bool nilled() const;
	
	/*______________________________________________________________________
	|
	|	The dm:node-kind accessor returns a string identifying the kind of 
	|	node. It will be one of the following, depending on the kind of node: 
	|	"attribute", "comment", "document", "element", "namespace" 
	|	"processing-instruction", or "text". 
	|_______________________________________________________________________*/
	enum node_kind_t node_kind() const;
	
	/*______________________________________________________________________
	|
	|	The dm:node-name accessor returns the name of the node as a sequence 
	|	of zero or one xs:QNames. Note that the QName value includes an 
	|	optional prefix as described in 3.3.3 QNames and NOTATIONS. 
	|_______________________________________________________________________*/
	atomic_value_iterator node_name() const;
	
	/*______________________________________________________________________
	|
	|	The dm:parent accessor returns the parent of a node as a sequence 
	|	containing zero or one nodes. 
	|_______________________________________________________________________*/
	node_iterator parent() const;
	
	/*______________________________________________________________________
	|
	|	The dm:string-value accessor returns the string value of a node.
	|_______________________________________________________________________*/
	std::string string_value() const;
	
	/*______________________________________________________________________
	|
	|	The dm:type-name accessor returns the name of the schema type of a 
	|	node as a sequence of zero or one xs:QNames. 
	|_______________________________________________________________________*/
	atomic_value_iterator type_name() const;
	
	/*______________________________________________________________________
	|
	|	The dm:typed-value accessor returns the typed-value of the node as a 
	|	sequence of zero or more atomic values. 
	|_______________________________________________________________________*/
	atomic_value_iterator typed_value() const;
	
	/*______________________________________________________________________
	|
	|	The dm:unparsed-entity-public-id accessor returns the public 
	|	identifier of an unparsed external entity declared in the specified 
	|	document. If no entity with the name specified in $entityname exists, 
	|	or if the entity is not an external unparsed entity, or if the entity 
	|	has no public identifier, the empty sequence is returned. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-public-id(std::string const& entityname) const;

	/*______________________________________________________________________
	|
	|	The dm:unparsed-entity-system-id accessor returns the system 
	|	identifier of an unparsed external entity declared in the specified 
	|	document. If no entity with the name specified in $entityname exists, 
	|	or if the entity is not an external unparsed entity, the empty 
	|	sequence is returned. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-system-id(std::string const& entityname) const;

};





/*______________________________________________________________________
|
|	Documents have the following properties: 
|
|  * base-uri, possibly empty.
|  * children, possibly empty.
|  * unparsed-entities, possibly empty.
|  * document-uri, possibly empty.
|  * string-value
|  * typed-value
|	
|	Document Nodes must satisfy the following constraints.
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
	/*______________________________________________________________________
	|	attributes
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator attributes();
	
	/*______________________________________________________________________
	|	base_uri
	|
	|	@return the value of the base-uri property if it exists and is not 
	|					empty, otherwise returns the empty sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator  base_uri();
	
	/*______________________________________________________________________
	|	children
	|
	|	@returns the value of the children property.
	|_______________________________________________________________________*/
	node_iterator children();
	
	/*______________________________________________________________________
	|	document_uri
	|
	|	@returns the absolute URI of the resource from which the Document 
	|						Node was constructed, or the empty sequence if no such
	|						absolute URI is available. 
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri();

	/*______________________________________________________________________
	|	is_id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	bool is_id();
	
	/*______________________________________________________________________
	|	is_idrefs
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	bool is_idrefs();
	
	/*______________________________________________________________________
	|	namespace-bindings
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings();
	
	/*______________________________________________________________________
	|	namespace-nodes
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator namespace_nodes();
	
	/*______________________________________________________________________
	|	nilled
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	bool nilled();
	
	/*______________________________________________________________________
	|	node-kind
	|
	|	@return "document".
	|_______________________________________________________________________*/
	enum node_kind_t node_kind();
	
	/*______________________________________________________________________
	|	node-name
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator node_name();

	/*______________________________________________________________________
	|	parent
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator parent();
	
	/*______________________________________________________________________
	|	string-value
	|
	|	@return the value of the string-value property.
	|_______________________________________________________________________*/
	std::string string_value();
	
	/*______________________________________________________________________
	|	type-name
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator type_name();

	/*______________________________________________________________________
	|	typed-value
	|
	|	@return the value of the typed-value property.
	|_______________________________________________________________________*/
	atomic_value_iterator typed_value();
	
	/*______________________________________________________________________
	|	unparsed-entity-public-id
	|
	|	@return the public identifier of the specified unparsed entity or 
	|					the empty sequence if no such entity exists. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_public_id();
	
	/*______________________________________________________________________
	|	unparsed-entity-system-id
	|
	|	@return the system identifier of the specified unparsed entity or 
	|					the empty sequence if no such entity exists. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_system_id();


public:	//ctor,dtor
	/*______________________________________________________________________
	|
	|	Construct from infoset
	|_______________________________________________________________________*/
	document_node(infoset const&);

	/*______________________________________________________________________
	|
	|	Construct from PSVI
	|_______________________________________________________________________*/
	document_node(psvi const&);

	/*______________________________________________________________________
	|
	|	Deallocate
	|_______________________________________________________________________*/
	~document_node();


public:	// infoset map
	/*______________________________________________________________________
	|
	|	Infoset mapping
	|_______________________________________________________________________*/
	rchandel<infoset> infoset_map() const;

};





/*______________________________________________________________________
|	Elements have the following properties: 
|
|	 * base-uri, possibly empty.
|	 * node-name
|	 * parent, possibly empty
|	 * type-name
|	 * children, possibly empty
|	 * attributes, possibly empty
|	 * namespaces
|	 * nilled
|	 * string-value
|	 * typed-value
|	 * is-id
|	 * is-idrefs
|	
|	Element Nodes must satisfy the following constraints.
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
|			children of their parent.) 
|	
|	    The data model permits Element Nodes without parents (to 
|			represent partial results during expression processing, for example). 
|			Such Element Nodes must not appear among the children of any other 
|			node. 
| 5.	If an Attribute Node A is among the attributes of an element E, 
|			then the parent of A must be E. 
| 6.	If an Attribute Node A has a parent element E, then A must be 
|			among the attributes of E. 
|	    The data model permits Attribute Nodes without parents. Such 
|			Attribute Nodes must not appear among the attributes of any Element 
|			Node. 
| 7.	If a Namespace Node N is among the namespaces of an element E, 
|			then the parent of N must be E. 
| 8.	If a Namespace Node N has a parent element E, then N must be 
|			among the namespaces of E. 
|	    The data model permits Namespace Nodes without parents. Such 
|			Namespace Nodes must not appear among the namespaces of any Element 
|			Node. This constraint is irrelevant for implementations that do not 
|			support Namespace Nodes. 
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
|			any type derived from those types) that appears in the typed-value of 
|			the element or the typed-value of any of its attributes, if the 
|			expanded QName has a non-empty URI, then there must be a prefix 
|			binding for this URI among the namespaces of this Element Node. 
|	    If any of the expanded QNames has an empty URI, then there must 
|			not be any binding among the namespaces of this Element Node which 
|			binds the empty prefix to a URI. 
| 13. Every element must include a Namespace Node and/or namespace 
|			binding for the prefix xml bound to the URI 
|			http://www.w3.org/XML/1998/namespace and there must be no other prefix 
|			bound to that URI. 
| 14. The string-value property of an Element Node must be the 
|			concatenation of the string-values of all its Text Node descendants in 
|			document order or, if the element has no such descendants, the 
|			zero-length string. 
|_______________________________________________________________________*/
class element_node : public node
{
public:	// accessors
	/*______________________________________________________________________
	|	attributes
	|
	|	@return the value of the attributes property. The order of 
	|					Attribute Nodes is stable but implementation dependent. 
	|_______________________________________________________________________*/
	node_iterator attributes() const;

	/*______________________________________________________________________
	|	base_uri
	|
	|	@return the value of the base-uri property if it exists and is not 
	|					empty. Otherwise, if the element has a parent, returns the 
	|					value of the dm:base-uri of its parent; otherwise, returns
	|					the empty sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator base_uri() const;

	/*______________________________________________________________________
	|	children
	|
	|	@returns the value of the children property.
	|_______________________________________________________________________*/
	node_iterator children() const;
	
	/*______________________________________________________________________
	|	document_uri
	|
	|	@returns the empty sequence
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri() const;
	
	/*______________________________________________________________________
	|	is_id
	|
	|	@return the value of the is-id property.
	|_______________________________________________________________________*/
	bool is_id() const;

	/*______________________________________________________________________
	|	is_idrefs
	|
	|	@return the value of the is-idrefs property.
	|_______________________________________________________________________*/
	bool is_idrefs() const;

	/*______________________________________________________________________
	|	namespace-bindings
	|
	|	@return the value of the namespaces property as a set of 
	|					prefix/URI pairs. 
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings() const;
	
	/*______________________________________________________________________
	|	namespace-nodes
	|
	|	@return the value of the namespaces property as a sequence of 
	|					Namespace Nodes. The order of Namespace Nodes is stable but 
	|					implementation dependent. 
	|_______________________________________________________________________*/
	node_iterator namespace_nodes() const;
	
	/*______________________________________________________________________
	|	nilled
	|
	|	@return the value of the nilled property.
	|_______________________________________________________________________*/
	bool nilled() const;
	
	/*______________________________________________________________________
	|	node-kind
	|
	|	@return "element".
	|_______________________________________________________________________*/
	enum node_kind_t node_kind() const;

	/*______________________________________________________________________
	|	node-name
	|
	|	@return the value of the node-name property.
	|_______________________________________________________________________*/
	atomic_value_iterator node-name() const;
	
	/*______________________________________________________________________
	|	parent
	|
	|	@return the value of the parent property.
	|_______________________________________________________________________*/
	node_iterator parent() const;
	
	/*______________________________________________________________________
	|	string-value
	|
	|	@return the value of the string-value property.
	|_______________________________________________________________________*/
	std::string string-value() const;

	/*______________________________________________________________________
	|	type-name
	|
	|	@return the value of the type-name property.
	|_______________________________________________________________________*/
	atomic_value_iterator type-name() const;

	/*______________________________________________________________________
	|	typed-value
	|
	|	@return the value of the typed-value property.
	|_______________________________________________________________________*/
	atomic_value_iterator typed-value() const;

	/*______________________________________________________________________
	|	unparsed-entity-public-id
	|
	|	@return the public identifier of the specified unparsed entity or 
	|					the empty sequence if no such entity exists. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-public-id() const;
	
	/*______________________________________________________________________
	|	unparsed-entity-system-id
	|
	|	@return the system identifier of the specified unparsed entity or 
	|					the empty sequence if no such entity exists. 
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-system-id() const;


public:	//ctor,dtor
	/*______________________________________________________________________
	|
	|	Construct from infoset
	|_______________________________________________________________________*/
	element_node(infoset const&);

	/*______________________________________________________________________
	|
	|	Construct from PSVI
	|_______________________________________________________________________*/
	element_node(psvi const&);

	/*______________________________________________________________________
	|
	|	Deallocate
	|_______________________________________________________________________*/
	~element_node();


public:	// infoset map
	/*______________________________________________________________________
	|
	|	Infoset mapping
	|_______________________________________________________________________*/
	rchandel<infoset> infoset_map() const;

};





/*______________________________________________________________________
|
|	Attributes have the following properties: 
|
|	 * node-name
|	 * parent, possibly empty
|	 * type-name
|	 * string-value
|	 * typed-value
|	 * is-id
|	 * is-idrefs
|	
|	Attribute Nodes must satisfy the following constraints.
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
class attribute_node
{
public:	// accessors
	/*______________________________________________________________________
	|	attributes
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator attributes() const;

	/*______________________________________________________________________
	|	base_uri
	|
	|	@return if the attribute has a parent, returns the value of the 
	|					base_uri of its parent; otherwise it returns the empty
	|					sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator base_uri() const;

	/*______________________________________________________________________
	|	children
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	node_iterator children() const;
	
	/*______________________________________________________________________
	|	document_uri
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri() const;
	
	/*______________________________________________________________________
	|	is_id
	|
	|	@return the value of the is-id property.
	|_______________________________________________________________________*/
	bool is_id() const;

	/*______________________________________________________________________
	|	is_idrefs
	|
	|	@return the value of the is-idrefs property.
	|_______________________________________________________________________*/
	bool is_idrefs() const;

	/*______________________________________________________________________
	|	namespace-bindings
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings() const;
	
	/*______________________________________________________________________
	|	namespace-nodes
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	node_iterator namespace_nodes() const;
	
	/*______________________________________________________________________
	|	nilled
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	bool nilled() const;
	
	/*______________________________________________________________________
	|	node-kind
	|
	|	@return "attribute".
	|_______________________________________________________________________*/
	enum node_kind_t node_kind() const;

	/*______________________________________________________________________
	|	node-name
	|
	|	@return the value of the node-name property.
	|_______________________________________________________________________*/
	atomic_value_iterator node-name() const;
	
	/*______________________________________________________________________
	|	parent
	|
	|	@return the value of the parent property.
	|_______________________________________________________________________*/
	node_iterator parent() const;
	
	/*______________________________________________________________________
	|	string-value
	|
	|	@return the value of the string-value property.
	|_______________________________________________________________________*/
	std::string string-value() const;

	/*______________________________________________________________________
	|	type-name
	|
	|	@return the value of the type-name property.
	|_______________________________________________________________________*/
	atomic_value_iterator type-name() const;

	/*______________________________________________________________________
	|	typed-value
	|
	|	@return the value of the typed-value property.
	|_______________________________________________________________________*/
	atomic_value_iterator typed-value() const;

	/*______________________________________________________________________
	|	unparsed-entity-public-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-public-id() const;
	
	/*______________________________________________________________________
	|	unparsed-entity-system-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed-entity-system-id() const;

public:	//ctor,dtor
	/*______________________________________________________________________
	|
	|	Construct from infoset
	|_______________________________________________________________________*/
	attribute_node(infoset const&);

	/*______________________________________________________________________
	|
	|	Construct from PSVI
	|_______________________________________________________________________*/
	attribute_node(psvi const&);

	/*______________________________________________________________________
	|
	|	Deallocate
	|_______________________________________________________________________*/
	~attribute_node();

public:	// infoset map
	/*______________________________________________________________________
	|
	|	Infoset mapping
	|_______________________________________________________________________*/
	rchandel<infoset> infoset_map() const;

};





/*______________________________________________________________________
|
|	Each Namespace Node represents the binding of a namespace URI to a 
|	namespace prefix or to the default namespace. Implementations that do 
|	not use Namespace Nodes may represent the same information using the 
|	namespaces property of an element node. Namespaces have the following 
|	properties: 

|	 * prefix, possibly empty
|	 * uri
|	 * parent, possibly empty
|	
|	Namespace Nodes must satisfy the following constraints.
|	
|	 1. If a Namespace Node N is among the namespaces of an element E, 
|			then the parent of N must be E. 
|	 2. If a Namespace Node N has a parent element E, then N must be 
|			among the namespaces of E. 
|	
|	The data model permits Namespace Nodes without parents. 
|_______________________________________________________________________*/
class namespace_node : public node
{
public:	// accessors
	/*______________________________________________________________________
	|	attributes
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator attributes() const;

	/*______________________________________________________________________
	|	base_uri
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	atomic_value_iterator base_uri() const;

	/*______________________________________________________________________
	|	children
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	node_iterator children() const;
	
	/*______________________________________________________________________
	|	document_uri
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri() const;
	
	/*______________________________________________________________________
	|	is_id
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	bool is_id() const;

	/*______________________________________________________________________
	|	is_idrefs
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	bool is_idrefs() const;

	/*______________________________________________________________________
	|	namespace-bindings
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings() const;
	
	/*______________________________________________________________________
	|	namespace-nodes
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	node_iterator namespace_nodes() const;
	
	/*______________________________________________________________________
	|	nilled
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	bool nilled() const;
	
	/*______________________________________________________________________
	|	node-kind
	|
	|	@return "namespace".
	|_______________________________________________________________________*/
	enum node_kind_t node_kind() const;

	/*______________________________________________________________________
	|	node-name
	|
	|	@return If the prefix is not empty, returns an xs:QName with the
	|					value of the prefix property in the local-name and an empty
	|					namespace name, otherwise returns the empty sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator node-name() const;
	
	/*______________________________________________________________________
	|	parent
	|
	|	@return the value of the parent property.
	|_______________________________________________________________________*/
	node_iterator parent() const;
	
	/*______________________________________________________________________
	|	string-value
	|
	|	@return the value of the uri property.
	|_______________________________________________________________________*/
	std::string string_value() const;

	/*______________________________________________________________________
	|	type-name
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator type_name() const;

	/*______________________________________________________________________
	|	typed-value
	|
	|	@return the value of the uri property as an xs:string.
	|_______________________________________________________________________*/
	atomic_value_iterator typed_value() const;

	/*______________________________________________________________________
	|	unparsed-entity-public-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_public_id() const;
	
	/*______________________________________________________________________
	|	unparsed-entity-system-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_system_id() const;


public:	//ctor,dtor
	/*______________________________________________________________________
	|
	|	Construct from infoset
	|_______________________________________________________________________*/
	namespace_node(infoset const&);

	/*______________________________________________________________________
	|
	|	Construct from PSVI
	|_______________________________________________________________________*/
	namespace_node(psvi const&);

	/*______________________________________________________________________
	|
	|	Deallocate
	|_______________________________________________________________________*/
	~namespace_node();


public:	// infoset map
	/*______________________________________________________________________
	|
	|	Infoset mapping
	|_______________________________________________________________________*/
	rchandel<infoset> infoset_map() const;

};





/*______________________________________________________________________
|
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
class processing_instruction_node : public node
{
public:	// accessors
	/*______________________________________________________________________
	|	attributes
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	node_iterator attributes() const;

	/*______________________________________________________________________
	|	base_uri
	|
	|	@return the value of the base-uri property if it exists and is not 
	|					empty. Otherwise, if the processing instruction has a parent,
	|					returns the value of the dm:base-uri of its parent; otherwise,
	|					returns the empty sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator base_uri() const;

	/*______________________________________________________________________
	|	children
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	node_iterator children() const;
	
	/*______________________________________________________________________
	|	document_uri
	|
	|	@returns the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator document_uri() const;
	
	/*______________________________________________________________________
	|	is_id
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	bool is_id() const;

	/*______________________________________________________________________
	|	is_idrefs
	|
	|	@return the empty sequence
	|_______________________________________________________________________*/
	bool is_idrefs() const;

	/*______________________________________________________________________
	|	namespace-bindings
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	namespace_iterator namespace_bindings() const;
	
	/*______________________________________________________________________
	|	namespace-nodes
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	node_iterator namespace_nodes() const;
	
	/*______________________________________________________________________
	|	nilled
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	bool nilled() const;
	
	/*______________________________________________________________________
	|	node-kind
	|
	|	@return "namespace".
	|_______________________________________________________________________*/
	enum node_kind_t node_kind() const;

	/*______________________________________________________________________
	|	node-name
	|
	|	@return If the prefix is not empty, returns an xs:QName with the
	|					value of the prefix property in the local-name and an empty
	|					namespace name, otherwise returns the empty sequence. 
	|_______________________________________________________________________*/
	atomic_value_iterator node-name() const;
	
	/*______________________________________________________________________
	|	parent
	|
	|	@return the value of the parent property.
	|_______________________________________________________________________*/
	node_iterator parent() const;
	
	/*______________________________________________________________________
	|	string-value
	|
	|	@return the value of the uri property.
	|_______________________________________________________________________*/
	std::string string_value() const;

	/*______________________________________________________________________
	|	type-name
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator type_name() const;

	/*______________________________________________________________________
	|	typed-value
	|
	|	@return the value of the uri property as an xs:string.
	|_______________________________________________________________________*/
	atomic_value_iterator typed_value() const;

	/*______________________________________________________________________
	|	unparsed-entity-public-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_public_id() const;
	
	/*______________________________________________________________________
	|	unparsed-entity-system-id
	|
	|	@return the empty sequence.
	|_______________________________________________________________________*/
	atomic_value_iterator unparsed_entity_system_id() const;


public:	//ctor,dtor
	/*______________________________________________________________________
	|
	|	Construct from infoset
	|_______________________________________________________________________*/
	namespace_node(infoset const&);

	/*______________________________________________________________________
	|
	|	Construct from PSVI
	|_______________________________________________________________________*/
	namespace_node(psvi const&);

	/*______________________________________________________________________
	|
	|	Deallocate
	|_______________________________________________________________________*/
	~namespace_node();


public:	// infoset map
	/*______________________________________________________________________
	|
	|	Infoset mapping
	|_______________________________________________________________________*/
	rchandel<infoset> infoset_map() const;

};

}	/* namespace xqp */
#endif /* XQP_XDM_H */
