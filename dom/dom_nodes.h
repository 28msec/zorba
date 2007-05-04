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

#include "dom_qname.h"
#include "context/common.h"
#include "context/dynamic_context.h"
#include "values/nodes.h"
#include "values/values.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

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

class dom_node : virtual public node
{
protected:
	itemid_t theID;
	const dom_node* parent_p;

public:	
	dom_node() {}
	virtual ~dom_node() {}

public:   // internal interface
	virtual sequence_type_t type() const = 0;
	virtual itemid_t id() const { return theID; }
	virtual itemid_t parentid() const { return parent_p ? parent_p->id() : 0; }

  virtual std::string str(zorba*) const { return ""; }
	virtual std::string get_base_uri(zorba*) const;
	virtual std::string get_document_uri(zorba*) const;
	virtual std::string get_typed_value(zorba*) const { return ""; };
	virtual const qname* get_node_name(zorba*) const { return 0; }
	virtual const qname* get_type_name(zorba*) const { return 0; }
	virtual const node* get_parent(zorba*) const { return 0; }

public:		// XQuery interface
	virtual iterator_t parent(zorba*) const;
	virtual iterator_t string_value(zorba*) const;
	virtual iterator_t base_uri(zorba*) const;
	virtual iterator_t document_uri(zorba*) const;

	virtual iterator_t node_name(zorba*) const { return 0; }
	virtual iterator_t type_name(zorba*) const { return 0; }
	virtual iterator_t typed_value(zorba*) const { return 0; }
	virtual iterator_t atomized_value(zorba*) const { return 0; }

	virtual iterator_t children(zorba*) const { return 0; }
	virtual iterator_t attributes(zorba*) const { return 0; }
	virtual iterator_t namespace_nodes(zorba*) const { return 0; }

	virtual bool is_id() const { return false; }
	virtual bool is_idrefs() const { return false; }
	virtual bool nilled() const { return false; }

	virtual bool is_empty() const { return false; }
	virtual bool is_node() const { return true; }
	virtual bool is_atomic() const { return false; }

public:		// output,serialization
	virtual std::string toXML() const { return ""; }
	virtual std::string toXML(zorba*) const = 0;
	virtual std::ostream& put(zorba*,std::ostream& ) const = 0;
	virtual std::string describe(zorba*) const = 0;

};
	

// iterators

class dom_child_iterator :	public item_iterator
{
protected:
	const dom_node* parent_p;
	std::vector<dom_node*>::const_iterator it;
	std::vector<dom_node*>::const_iterator end;

public:
	dom_child_iterator(const dom_node&);
	~dom_child_iterator();

public:
 	void open();
	void close();
	const item& next(uint32_t delta = 1);
	const item& peek() const;
	bool done() const;

public:
	const item& operator*() const;
	dom_child_iterator& operator++();
};


class dom_attribute_iterator :	public item_iterator
{
protected:
	const dom_node* elem_p;
	std::vector<dom_node*>::const_iterator it;
	std::vector<dom_node*>::const_iterator end;

public:
	dom_attribute_iterator(const dom_node&);
	~dom_attribute_iterator();

public:
 	void open();
	void close();
	const item& next(uint32_t delta = 1);
	const item& peek() const;
	bool done() const;

public:
	const item& operator*() const;
	dom_attribute_iterator& operator++();
};


class dom_namespace_iterator :	public item_iterator
{
protected:
	const dom_node* elem_p;
	std::vector<dom_node*>::const_iterator it;
	std::vector<dom_node*>::const_iterator end;

public:
	dom_namespace_iterator(const dom_node&);
	~dom_namespace_iterator();

public:
 	void open();
	void close();
	const item& next(uint32_t delta=1);
	const item& peek() const;
	bool done() const;

public:
	const item& operator*() const;
	dom_namespace_iterator& operator++();

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

class dom_document_node : public dom_node, public document_node
{
protected:
	std::string theBaseURI;
	std::string theDocURI;
	std::vector<dom_node*> childv;

public:
	dom_document_node(const std::string& baseuri,
										const std::string& docuri);
	dom_document_node(dom_document_node&);
	~dom_document_node() {}

public:		// internal interface		
	sequence_type_t type() const { return documentNode; }
	std::string str(zorba*) const;
	std::string get_base_uri(zorba*) const;
	std::string get_document_uri(zorba*) const;
	std::string get_typed_value(zorba*) const;
	const qname* get_type_name(zorba*) const;

	const std::vector<dom_node*>& get_childv() const { return childv; }
	void add_child(dom_node* dn_p) { childv.push_back(dn_p); }

public:		// XQuery interface
	iterator_t children(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }
	iterator_t namespace_nodes(zorba* z) const
		{ return dom_node::namespace_nodes(z); }

public:		// output, serialization
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

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

class dom_element_node : public dom_node, public element_node
{
protected:
	dom_qname* qname_p;
	atomic_value* value_p;

	std::vector<dom_node*> nsv;
	std::vector<dom_node*> attrv;
	std::vector<dom_node*> childv;

	bool id_b;
	bool idref_b;
	bool nilled_b;

public:
	dom_element_node(dom_qname*, atomic_value*);
	dom_element_node(const dom_element_node&);
	~dom_element_node() {}

public:		// internal interface		
	sequence_type_t type() const { return elementNode; }

	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;
	const qname* get_node_name(zorba*) const;
	const qname* get_type_name(zorba*) const;

	bool is_id() const { return id_b; }
	bool is_idrefs() const { return idref_b; }
	bool nilled() const { return nilled_b; }

	const std::vector<dom_node*>& get_nsv() const { return nsv; }
	const std::vector<dom_node*>& get_attrv() const { return attrv; }
	const std::vector<dom_node*>& get_childv() const { return childv; }

	std::vector<dom_node*>& get_nsv() { return nsv; }
	std::vector<dom_node*>& get_attrv() { return attrv; }
	std::vector<dom_node*>& get_childv() { return childv; }

	void add_namespace(dom_namespace_node*);
	void add_attribute(dom_attribute_node*);
	void add_child(dom_node*);

public:		// XQuery interface
	iterator_t node_name(zorba*) const;
	iterator_t type_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t attributes(zorba*) const;
	iterator_t children(zorba*) const;
	iterator_t namespace_nodes(zorba*) const;

	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:		// output, serialization 
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
  std::string describe(zorba*) const;

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

class dom_attribute_node : public dom_node,
														virtual public attribute_node 
{
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

public:	// internal interface
	sequence_type_t type() const { return attributeNode; }

	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;
	const qname* get_node_name(zorba*) const;
	const qname* get_type_name(zorba*) const;

	bool is_id() const { return id_b; }
	bool is_idrefs() const { return idrefs_b; }
	bool nilled() const { return nilled_b; }

public:	// XQuery interface
	iterator_t node_name(zorba*) const;
	iterator_t type_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:		// output, serialization
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;


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
class dom_namespace_node : public dom_node, public namespace_node
{
protected:
	std::string thePrefix;
	std::string theURI;

public:
	dom_namespace_node(const std::string& prefix, const std::string& uri);
	dom_namespace_node(dom_namespace_node&);
	~dom_namespace_node() {}

public:		// internal interface		
	sequence_type_t type() const { return namespaceNode; }

	std::string prefix() const { return thePrefix; }
	std::string uri() const { return theURI; }
	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;

	const qname* get_node_name(zorba*) const;

public:		// XQuery interface
	iterator_t node_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:		// output, seralization
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;


};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class dom_pi_node : public dom_node, public pi_node
{
protected:
	std::string theTarget;
	std::string theContent;

public:
	dom_pi_node(const std::string& target, const std::string& content);
	dom_pi_node(const dom_pi_node&);
	~dom_pi_node() {}

public:		// internal interface
	sequence_type_t type() const { return processingInstructionNode; }

	std::string target() const { return theTarget; }
	std::string content() const { return theContent; }
	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;

	const qname* get_node_name(zorba*) const;

public:		// XQuery interface
	iterator_t node_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	
	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:		// output, serialization
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

};



/*______________________________________________________________________
| 6.6 Comment Nodes 
|_______________________________________________________________________*/

class dom_comment_node : public dom_node,
													virtual public comment_node
{
protected:
	std::string theContent;

public:
	dom_comment_node(const std::string& content);
	dom_comment_node(const dom_comment_node&);
	~dom_comment_node() {}
	
public:		// internal interface		
	sequence_type_t type() const { return commentNode; }

	std::string content() const;
	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;

public:		// XQuery interface
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	
	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:
	std::string toXML(zorba*) const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

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

class dom_text_node : public dom_node, public text_node
{
protected:
	std::string theContent;

public:
	dom_text_node(const std::string& content);
	dom_text_node(const dom_text_node&);
	~dom_text_node() {}
	
public:		// internal interface		
	sequence_type_t type() const { return textNode; }

	std::string content() { return theContent; }
	std::string str(zorba*) const;
	std::string get_typed_value(zorba*) const;

public:		// XQuery interface
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

	iterator_t parent(zorba* z) const
		{ return dom_node::parent(z); }
	iterator_t string_value(zorba* z) const
		{ return dom_node::string_value(z); }
	iterator_t base_uri(zorba* z) const
		{ return dom_node::base_uri(z); }
	iterator_t document_uri(zorba* z) const
		{ return dom_node::document_uri(z); }

public:
	std::ostream& put(zorba*,std::ostream&) const;
	std::string toXML(zorba*) const;
	std::string describe(zorba*) const;

};


}	/* namespace xqp */
#endif /* XQP_DOM_NODES_H */
