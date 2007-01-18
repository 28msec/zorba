/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tree.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

/*______________________________________________________________________
|
| Includes classes supporting each of the 7 node types defined in:
|   XQuery 1.0 and XPath 2.0 Data Model
|   [http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/
 
#ifndef XQP_TREE_H
#define XQP_TREE_H

#include "../context/context.h"
#include "../runtime/item_iterator.h"
#include "../values/node.h"
#include "../values/values.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"

namespace xqp {


class xqp_nodeid : public nodeid
{
public:
	uint64_t id;

	xqp_nodeid(uint64_t _id) : id(_id) {}
	xqp_nodeid() {}
	~xqp_nodeid() {}

	bool operator==(xqp_nodeid const& n) const
		{ return id==n.id;  }

};



/*______________________________________________________________________
| 6.0 Node
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

class xqp_node : public node
{
protected:	// node locator
	xqp_nodeid id;

public:	// accessors
	virtual node_kind_t node_kind() const = 0;
	virtual item_iterator node_name(context const&) const = 0;
	virtual item_iterator attributes(context const&) const;
	virtual item_iterator base_uri(context const&) const;
	virtual item_iterator children(context const&) const;
	virtual item_iterator document_uri(context const&) const;
	virtual item_iterator namespace_bindings(context const&) const;
	virtual item_iterator namespace_nodes(context const&) const;
	virtual item_iterator parent(context const&) const;
	virtual item_iterator typed_value(context const&) const;

	virtual bool is_id(context const&) const;
	virtual bool is_idrefs(context const&) const;
	virtual bool nilled(context const&) const;

	virtual item_type const& get_type(context const&) const;
	virtual std::string string_value(context const&) const;
	
	virtual item_iterator unparsed_entity_public_id(
	  context const&,
	  std::string const& entity_name) const;

	virtual item_iterator unparsed_entity_system_id(
	  context const&,
	  std::string const& entity_name) const;

public:	// ctor,dtor
	xqp_node(xqp_nodeid _id) : id(_id) {}
	xqp_node(xqp_node& n) : id(n.id) {}
	xqp_node() : id(0) {}
	~xqp_node() {}

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
class xqp_document : public document_node, public xqp_node
{
protected:
	std::string baseuri;
	std::vector<rchandle<xqp_node> > child_hv;
	hashmap<std::string> unparsed_entity_map;
	std::string docuri;

public:
	node_kind_t node_kind() const { return doc_kind; }
	
	item_iterator base_uri(context const&) const;
	item_iterator children(context const&) const;
	item_iterator document_uri(context const&) const;
	item_iterator typed_value(context const&) const;

	std::string string_value(context const&) const;
	
  item_iterator unparsed_entity_public_id(
    context const&,
    std::string const& entity_name) const;
	
	item_iterator unparsed_entity_system_id(
	  context const&,
	  std::string const& entity_name) const;

protected:
	bool get_entity(std::string const& entity, std::string & val);
	void put_entity(std::string const& entity, std::string const& val);

public:	//ctor,dtor

	xqp_document(
		xqp_nodeid id,
		std::string const& baseuri,
		std::string const& docuri);

	xqp_document(xqp_nodeid id) : xqp_node(id) {}
	xqp_document() {}
	~xqp_document() {}

public:
	class child_iterator : public item_iterator
	{
	protected:
		xqp_document const* parent_p;
		std::vector<rchandle<xqp_node> >::const_iterator child_it;
		std::vector<rchandle<xqp_node> >::const_iterator it_end;
		
	public:
		child_iterator(xqp_document const*);
		~child_iterator();
	
	public:
	 	void open();
		void close() {}
		rchandle<item> next();
		bool done();
		void rewind();

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

class xqp_attribute;
class xqp_ns;
class xqp_comment;
class xqp_text;
class xqp_pi;

class xqp_element : public element_node, public xqp_node
{
	friend class elem_child_iterator;
	friend class elem_attr_iterator;

protected:
	std::string baseuri;
	std::string nodename;
	rchandle<xqp_node> parent_h;
	item_type type;
	std::vector<rchandle<xqp_node> > child_hv;
	std::vector<rchandle<xqp_attribute> > attr_hv;
	std::vector<rchandle<xqp_ns> > ns_hv;
	bool nilled_b;
	bool id_b;
	bool idrefs_b;

public:	// accessors
	node_kind_t node_kind() const { return elem_kind; }
	
	item_iterator attributes(context const&) const;
	item_iterator base_uri(context const&) const;
	item_iterator children(context const&) const;
	item_iterator namespace_bindings(context const&) const;
	item_iterator namespace_nodes(context const&) const;
	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;
	
	bool is_id(context const&) const;
	bool is_idrefs(context const&) const;
	bool nilled(context const&) const;

	item_type const& get_type(context const&) const;
	std::string string_value(context const&) const;

protected:
	void add_element_node(rchandle<xqp_element>);
	void add_text_node(rchandle<xqp_text>);
	void add_text_node(std::string const&);
	void add_attribute_node(rchandle<xqp_attribute>);
	void add_ns_node(rchandle<xqp_ns>);
	void add_comment_node(rchandle<xqp_comment>);
	void add_pi_node(rchandle<xqp_pi>);

	bool get_nilled() const { return nilled_b; }
	bool get_id() const { return id_b; }
	bool get_idrefs() const { return idrefs_b; }

	void set_nilled(bool b) { nilled_b = b; }
	void set_id(bool b) { id_b = b; }
	void set_idrefs(bool b) { idrefs_b = b; }

public:	//ctor,dtor

	xqp_element(
		xqp_nodeid id,
		std::string const& baseuri,
		std::string const& nodename,
		rchandle<xqp_node> parent);

	xqp_element(xqp_nodeid id) : xqp_node(id) {}
	xqp_element() {}
	~xqp_element() {}

public:

	class child_iterator : public item_iterator
	{
	protected:
		xqp_element const* parent_p;
		std::vector<rchandle<xqp_node> >::const_iterator child_it;
		std::vector<rchandle<xqp_node> >::const_iterator it_end;
		
	public:
		child_iterator(xqp_element const*);
		~child_iterator();
	
	public:
	 	void open();
		void close() {}
		rchandle<item> next();
		bool done();
		void rewind();
	
	};
	
	
	class attr_iterator : public item_iterator
	{
	protected:
		xqp_element const* parent_p;
		std::vector<rchandle<xqp_node> >::const_iterator attr_it;
		std::vector<rchandle<xqp_node> >::const_iterator it_end;
		
	public:
		attr_iterator(xqp_element const*);
		~attr_iterator();
	
	public:
	 	void open();
		void close() {}
		rchandle<item> next();
		bool done();
		void rewind();
	
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

class xqp_attribute : public attribute_node, public xqp_node
{
protected:
	std::string nodename;
	rchandle<xqp_element> parent_h;
	item_type type;
	std::string val;
	bool id_b;
	bool idrefs_b;

public:	// accessors
	node_kind_t node_kind() const { return attr_kind; }
	
	item_iterator base_uri(context const&) const;
	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;

	bool is_id(context const&) const;
	bool is_idrefs(context const&) const;

	item_type const& get_type(context const&) const;
	std::string string_value(context const&) const;

public:	//ctor,dtor
  xqp_attribute(xqp_nodeid id) : xqp_node(id) {}
  xqp_attribute() {}
  ~xqp_attribute() {}

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
class xqp_ns : public ns_node, public xqp_node
{
protected:
	std::string prefix;
	std::string uri;
	rchandle<xqp_element> parent_h;

public:	// accessors
	node_kind_t node_kind() const { return ns_kind; }

	item_iterator node_name(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;
	
	std::string string_value(context const&) const;

public:	//ctor,dtor

	xqp_ns(
		xqp_nodeid id,
		std::string const& prefix,
		std::string const& uri,
		rchandle<xqp_element> parent);

	xqp_ns(xqp_nodeid id) : xqp_node(id) {}
	xqp_ns() {}
	~xqp_ns() {}

};



/*______________________________________________________________________
| 6.5 Processing Instruction Nodes
|	
|	 1. The string "?>" must not occur within the content.
|	 2. The target must be an NCName.
|_______________________________________________________________________*/
class xqp_pi : public pi_node, public xqp_node
{
protected:
	std::string target;
	std::string content;
	std::string baseuri;
	rchandle<xqp_element> parent_h;

public:	// accessors
	node_kind_t node_kind(context const*) const { return pi_kind; }
	
	item_iterator base_uri(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;
	item_iterator node_name(context const&) const;
	std::string string_value(context const&) const;

public:	//ctor,dtor

	xqp_pi(
		xqp_nodeid id,
		std::string const& target,
		std::string const& content,
		std::string const& baseuri,
		rchandle<xqp_element> parent);

	xqp_pi(xqp_nodeid id) : xqp_node(id) {}
	xqp_pi() {}
	~xqp_pi() {}

};



/*______________________________________________________________________
| 6.6 Text Nodes 
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

class xqp_text : public text_node, public xqp_node
{
protected:
	std::string content;
	rchandle<xqp_element> parent_h;
	
public:	// accessors
	node_kind_t node_kind(context const&) const { return text_kind; }
	
	item_iterator base_uri(context const&) const;
	item_iterator parent(context const&) const;
	item_iterator typed_value(context const&) const;
	
	item_type const& get_type(context const&) const;
	std::string string_value(context const&) const;

public:	//ctor,dtor

	xqp_text(
		xqp_nodeid,
		std::string const& content,
		rchandle<xqp_element> parent);

	xqp_text(xqp_nodeid id) : xqp_node(id) {}
	xqp_text() {}
	~xqp_text() {}

};


}	/** namespace xqp */
#endif /* XQP_TREE_H */
