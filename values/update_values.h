/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_UPDATE_VALUES_H
#define XQP_UPDATE_VALUES_H

#include "abstract_update_values.h"
#include "values.h"
#include "nodes.h"
#include "../runtime/abstract_iterator.h"
#include "../util/rchandle.h"


/*______________________________________________________________________
|  
|	Interface definition for update objects.
|	See for reference: "XQuery 1.0 Update Facility"
|	[http://www.w3.org/TR/xqupdate/]
|
|	The update actions are encapsulated by these objects
|	prior to snapshot update.
|_______________________________________________________________________*/


namespace xqp {

class abstract_qname;


/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

class update_value :	public object,
											public abstract_update_value
{
public:
	typedef const node* nodeptr;
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	nodeptr target_p;

public:
	update_value(nodeptr _target_p) : target_p(_target_p) {}
	~update_value() {}

public:
	const abstract_node* target() const { return target_p; }

};


/*______________________________________________________________________
|  
|	upd:insertBefore
|
|	'target' must be an element, text, processing instruction, 
|	or comment node with a non-empty parent property.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/

class insert_before_value : public update_value,
														public abstract_insert_before_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	insert_before_value(
		nodeptr target_p,
		const vector<nodeptr>& content_pv);

	~insert_before_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertAfter
|
|	'target' must be an element, text, processing instruction, 
|	or comment node with a non-empty parent property.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/
class insert_after_value :	public update_value,
														public abstract_insert_after_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	insert_after_value(
		nodeptr target_p,
		const std::vector<nodeptr>& content_pv);

	~insert_after_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertInto
|
|	'target' must be an element or document node.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/
class insert_into_value : public update_value,
													public abstract_insert_into_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	insert_into_value(
		nodeptr target_p,
		const std::vector<nodeptr>& content_pv);

	~insert_into_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertIntoAsFirst
|
|	'target' must be an element or document node.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/
class insert_into_as_first_value :	public update_value,
																		public abstract_insert_into_as_first_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	insert_into_as_first_value(
		nodeptr target_p,
		const std::vector<nodeptr>& content_pv);

	~insert_into_as_first_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertIntoAsLast
|
|	'target' must be an element or document node.
|
|	'content' must be a sequence containing only element, text, 
|	processing instruction, and comment nodes. 
|_______________________________________________________________________*/
class insert_into_as_last_value : public update_value,
																	public abstract_insert_into_as_last_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	insert_into_as_last_value(
		nodeptr target_p,
		const std::vector<nodeptr>& content_pv);

	~insert_into_as_last_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertAttributes
|_______________________________________________________________________*/
class insert_attributes_value : public update_value,
																public abstract_insert_attributes_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<attribute_node const*>& content_pv;

public:
	insert_attributes_value(
		nodeptr target_p,
		const std::vector<const attribute_node*>& content_pv);

	~insert_attributes_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:delete
|_______________________________________________________________________*/
class delete_value :	public update_value,
											public abstract_delete_value
{
public:
	delete_value(
		nodeptr target_p);

	~delete_value();

};


/*______________________________________________________________________
|  
|	upd:replaceNode
|
|	'target' must be a node that has a parent.  If 'target' is an 
|	attribute node, 'content' must consist of zero or more 
|	attribute nodes.
|	If 'target' is an element, text, comment, or processing
|	instruction node, 'content' must be consist of zero or
|	more element, text, comment, or processing instruction nodes. 
|_______________________________________________________________________*/
class replace_node_value :	public update_value,
														public abstract_replace_node_value
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	const std::vector<nodeptr>& content_pv;

public:
	replace_node_value(
		nodeptr target_p,
		const std::vector<nodeptr>& content_pv);

	~replace_node_value();

public:
	iterator_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:replaceValue
|
|	'target' must be an attribute, text, comment, or processing
|	instruction node.
|_______________________________________________________________________*/
class replace_value_value : public update_value,
														public abstract_replace_value_value
{
protected:
	std::string m_content;

public:
	replace_value_value(
		nodeptr target_p,
		const std::string& content);

	~replace_value_value();

public:
	string content() const { return m_content; }

};


/*______________________________________________________________________
|  
|	upd:replaceElementContent
|_______________________________________________________________________*/
class replace_element_content_value : public update_value,
																			public abstract_replace_element_content_value
{
protected:
	const text_node* content_p;
	
public:
	replace_element_content_value(
		nodeptr target_p,
		const text_node*);

	~replace_element_content_value();

public:
	const text_node* content() const { return content_p; }

};


/*______________________________________________________________________
|  
|	upd:rename
|_______________________________________________________________________*/
class rename_value :	public update_value,
											public abstract_rename_value
{
protected:
	const abstract_qname* name_p;

public:
	rename_value(
		nodeptr target_p,
		const qname_value*);

	~rename_value();

public:
	//const abstract_qame* qname() const { return name_p; }

};



} /* namespace xqp */
#endif /* XQP_UPDATE_VALUES_H */

