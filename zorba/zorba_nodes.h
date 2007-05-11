/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_nodes.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
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
 
#ifndef XQP_ZORBA_NODES_H
#define XQP_ZORBA_NODES_H

#include "zorba_qname.h"
#include "nodereps.h"

#include "context/common.h"
#include "values/nodes.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "values/values.h"
#include "values/qname.h"
#include "util/rchandle.h"

namespace xqp {

class zorba_element_node;
class zorba_attribute_node;
class zorba_namespace_node;


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
|_______________________________________________________________________*/

class zorba_node : public zorba_item, virtual public node
{
public:		// ctor,dtor
	zorba_node() {}
	virtual ~zorba_node() {}

public:		// internal interface		
	virtual sequence_type_t type() const = 0;
	virtual itemid_t id() const = 0;
	virtual itemid_t parentid() const = 0;
	virtual std::string str(zorba*) const { return ""; }
	virtual std::string get_base_uri(zorba*) const { return ""; };
	virtual std::string get_document_uri(zorba*) const { return ""; };
	virtual std::string get_typed_value(zorba*) const { return ""; };
	virtual const qname* get_node_name(zorba*) const { return 0; }
	virtual const qname* get_type_name(zorba*) const { return 0; }
	virtual const node* get_parent(zorba*) const { return 0; }

public:		// XQuery interface
	virtual iterator_t string_value(zorba*) const { return 0; }
	virtual iterator_t base_uri(zorba*) const { return 0; }
	virtual iterator_t document_uri(zorba*) const { return 0; }
	virtual iterator_t attributes(zorba*) const { return 0; }
	virtual iterator_t children(zorba*) const { return 0; }
	virtual iterator_t namespace_nodes(zorba*) const { return 0; }
	virtual iterator_t node_name(zorba*) const { return 0; }
	virtual iterator_t parent(zorba*) const { return 0; }
	virtual iterator_t type_name(zorba*) const { return 0; }
	virtual iterator_t typed_value(zorba*) const { return 0; }
	virtual iterator_t atomized_value(zorba*) const { return 0; }

	virtual bool is_id() const { return false; }
	virtual bool is_idrefs() const { return false; }
	virtual bool nilled() const { return false; }

public:		// output,serialization
	virtual std::string toXML() const = 0;
	virtual std::ostream& put(zorba*,std::ostream& os) const = 0;
	virtual std::string describe(zorba*) const = 0;

};



class child_iterator : public item_iterator
{
protected:
	rchandle<child_noderep_iterator> itref;

public:
	child_iterator(const zorba_node&);
	~child_iterator() {}

public:
 	void open();
	void close();
	item& next(uint32_t delta = 1);
	item& peek() const;
	bool done() const;

public:
	item& operator*() const;
	child_iterator& operator++();

};



class attribute_iterator : public item_iterator
{
protected:
	rchandle<attribute_noderep_iterator> itref;

public:
	attribute_iterator(const zorba_element_node&);
	~attribute_iterator() {}

public:
 	void open();
	void close();
	bool done() const;
	item& next(uint32_t delta = 1);
	item& peek() const;

public:
	item& operator*() const;
	attribute_iterator& operator++();

};



class namespace_iterator : public item_iterator
{
protected:
	rchandle<namespace_noderep_iterator> itref;

public:
	namespace_iterator(const zorba_element_node&);
	~namespace_iterator() {}

public:
 	void open();
	void close();
	bool done() const;
	item& next(uint32_t delta = 1);
	item& peek() const;

public:
	item& operator*() const;
	namespace_iterator& operator++();

};



class zorba_document_node : public zorba_node, public document_node
{
protected:
	document_noderep* rep;

public:
	zorba_document_node(document_noderep*);
	zorba_document_node(zorba_document_node&);
	~zorba_document_node();

public:		// internal interface		
	sequence_type_t type() const { return documentNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	const qname* get_type_name(zorba*) const;
	std::string str(zorba*) const;
	std::string get_base_uri(zorba*) const;
	std::string get_document_uri(zorba*) const;
	std::string get_typed_value(zorba*) const;

public:		// XQuery interface
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t document_uri(zorba*) const;
	iterator_t children(zorba*) const;
	iterator_t namespace_nodes(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const; 
	
};



class zorba_element_node : public zorba_node, public element_node
{
protected:
	element_noderep* rep;

public:
	zorba_element_node(element_noderep*);
	zorba_element_node(const zorba_element_node&);
	~zorba_element_node() {}

public:		// internal interface		
	sequence_type_t type() const { return elementNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	std::string str(zorba*) const;
	std::string get_base_uri(zorba*) const;
	std::string get_document_uri(zorba*) const;
	std::string get_typed_value(zorba*) const;
	const qname* get_node_name(zorba*) const;
	const qname* get_type_name(zorba*) const;
	const node* get_parent(zorba*) const;

public:		// XQuery interface
	iterator_t parent(zorba*) const;
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t document_uri(zorba*) const;
	iterator_t node_name(zorba*) const;
	iterator_t type_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t attributes(zorba*) const;
	iterator_t children(zorba*) const;
	iterator_t namespace_nodes(zorba*) const;

	bool is_id() const;
	bool is_idrefs() const;
	bool nilled() const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
  std::string describe(zorba*) const;


};



class zorba_attribute_node : public zorba_node, public attribute_node
{
protected:
	attribute_noderep* rep;

public:
	zorba_attribute_node(attribute_noderep*);
	zorba_attribute_node(zorba_attribute_node&);
  ~zorba_attribute_node() {}

public:		// internal interface		
	sequence_type_t type() const { return attributeNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	std::string str(zorba*) const { return ""; }
	std::string get_base_uri(zorba*) const { return ""; }
	std::string get_typed_value(zorba*) const { return ""; }
	const qname* get_node_name(zorba*) const { return 0; }
	const qname* get_type_name(zorba*) const { return 0; }
	const node* get_parent(zorba*) const { return 0; }

public:	// XQuery interface
	iterator_t parent(zorba*) const;
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t node_name(zorba*) const;
	iterator_t type_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;

	bool is_id() const;
	bool is_idrefs() const;
	bool nilled() const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

};



class zorba_namespace_node : public zorba_node, public namespace_node
{
protected:
	namespace_noderep* rep;

public:
	zorba_namespace_node(namespace_noderep*);
	zorba_namespace_node(zorba_namespace_node&);
	~zorba_namespace_node() {}

public:		// internal interface		
	sequence_type_t type() const { return namespaceNode; }
	std::string prefix() const;
	std::string uri() const;
	itemid_t id() const;
	itemid_t parentid() const;
	std::string str(zorba*) const { return ""; }
	std::string get_typed_value(zorba*) const { return ""; };
	const qname* get_node_name(zorba*) const { return 0; }
	const node* get_parent(zorba*) const { return 0; }

public:		// XQuery interface
	iterator_t string_value(zorba*) const;
	iterator_t node_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t parent(zorba*) const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

};



class zorba_pi_node : public zorba_node, public pi_node
{
protected:
	pi_noderep* rep;

public:
	zorba_pi_node(pi_noderep*);
	zorba_pi_node(const zorba_pi_node&);
	~zorba_pi_node() {}

public:		// internal interface		
	sequence_type_t type() const { return processingInstructionNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	std::string target() const;
	std::string content() const;
	std::string str(zorba*) const { return ""; }
	std::string get_base_uri(zorba*) const { return ""; };
	std::string get_typed_value(zorba*) const { return ""; };
	const qname* get_node_name(zorba*) const { return 0; }
	const node* get_parent(zorba*) const { return 0; }

public:		// XQuery interface
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t node_name(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t parent(zorba*) const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

};



class zorba_comment_node : public zorba_node, public comment_node
{
protected:
	comment_noderep* rep;

public:
	zorba_comment_node(comment_noderep*);
	zorba_comment_node(const zorba_comment_node&);
	~zorba_comment_node() {}
	
public:		// internal interface		
	sequence_type_t type() const { return commentNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	const node* get_parent(zorba*) const { return 0; }
	std::string content() const;
	std::string str(zorba*) const;
	std::string get_base_uri(zorba*) const { return ""; };
	std::string get_typed_value(zorba*) const { return ""; };

public:		// XQuery interface
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t node_name(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t parent(zorba*) const;
	
public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream&) const;
	std::string describe(zorba*) const;

};



class zorba_text_node : public zorba_node, public text_node
{
protected:
	text_noderep* rep;

public:
	zorba_text_node(text_noderep*);
	zorba_text_node(const zorba_text_node&);
	~zorba_text_node() {}
	
public:		// internal interface		
	sequence_type_t type() const { return textNode; }
	itemid_t id() const;
	itemid_t parentid() const;
	const node* get_parent(zorba*) const { return 0; }
	std::string content() const;
	std::string str(zorba*) const { return ""; }
	std::string get_base_uri(zorba*) const { return ""; };
	std::string get_typed_value(zorba*) const { return ""; };

public:		// XQuery interface
	iterator_t string_value(zorba*) const;
	iterator_t base_uri(zorba*) const;
	iterator_t typed_value(zorba*) const;
	iterator_t atomized_value(zorba*) const;
	iterator_t parent(zorba*) const;

public:		// output, serialization
	std::string toXML() const;
	std::ostream& put(zorba*,std::ostream& os) const;
	std::string describe(zorba*) const;

};


}	/* namespace xqp */
#endif /* XQP_ZORBA_NODES_H */
