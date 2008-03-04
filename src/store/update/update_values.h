/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: update_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_UPDATE_VALUES_H
#define XQP_UPDATE_VALUES_H

#include <vector>

#include <zorba/item.h>
#include <zorba/rchandle.h>

#include "runtime/core/item_iterator.h"

/*______________________________________________________________________
|  
|	Interface definition for update objects.
|	See for reference: "XQuery 1.0 Update Facility"
|	[http://www.w3.org/TR/xqupdate/]
|
|	The update actions are encapsulated by these objects
|	prior to snapshot update.
|_______________________________________________________________________*/


namespace zorba {



/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

class update_value :	virtual public rcobject
{
protected:
	const node* target_p;

public:
	update_value(const node* _target_p) : target_p(_target_p) {}
	~update_value() {}

public:
	const node* target() const { return target_p; }

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

class insert_before_value : public update_value
{
protected:
	const std::vector<const node*>& content_pv;

public:
	insert_before_value(
		const node* target_p,
		const vector<const node*>& content_pv);

	~insert_before_value();

public:
	PlanIter_t new_nodes() const;

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
class insert_after_value :	public update_value
{
protected:
	const std::vector<const node*>& content_pv;

public:
	insert_after_value(
		const node* target_p,
		const std::vector<const node*>& content_pv);

	~insert_after_value();

public:
	PlanIter_t new_nodes() const;

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
class insert_into_value : public update_value
{
protected:
	const std::vector<const node*>& content_pv;

public:
	insert_into_value(
		const node* target_p,
		const std::vector<const node*>& content_pv);

	~insert_into_value();

public:
	PlanIter_t new_nodes() const;

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
class insert_into_as_first_value :	public update_value
{
protected:
	const std::vector<const node*>& content_pv;

public:
	insert_into_as_first_value(
		const node* target_p,
		const std::vector<const node*>& content_pv);

	~insert_into_as_first_value();

public:
	PlanIter_t new_nodes() const;

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
class insert_into_as_last_value : public update_value
{
protected:
	const std::vector<const node*>& content_pv;

public:
	insert_into_as_last_value(
		const node* target_p,
		const std::vector<const node*>& content_pv);

	~insert_into_as_last_value();

public:
	PlanIter_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:insertAttributes
|_______________________________________________________________________*/
class insert_attributes_value : public update_value
{
protected:
	const std::vector<const Item*>& content_pv;

public:
	insert_attributes_value(
		const Item* target_p,
		const std::vector<const Item*>& content_pv);

	~insert_attributes_value();

public:
	PlanIter_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:delete
|_______________________________________________________________________*/
class delete_value :	public update_value
{
public:
	delete_value(
		const Item* target_p);

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
class replace_node_value :	public update_value
{
protected:
	const std::vector<const Item*>& content_pv;

public:
	replace_node_value(
		const Item* target_p,
		const std::vector<const Item*>& content_pv);

	~replace_node_value();

public:
	PlanIter_t new_nodes() const;

};


/*______________________________________________________________________
|  
|	upd:replaceValue
|
|	'target' must be an attribute, text, comment, or processing
|	instruction node.
|_______________________________________________________________________*/
class replace_value_value : public update_value
{
protected:
	std::string theContent;

public:
	replace_value_value(
		const Item* target_p,
		const std::string& content);

	~replace_value_value();

public:
	string content() const { return theContent; }

};


/*______________________________________________________________________
|  
|	upd:replaceElementContent
|_______________________________________________________________________*/
class replace_element_content_value : public update_value
{
protected:
	const Item* theContent;
	
public:
	replace_element_content_value(
		const Item* target_p,
		const Item*);

	~replace_element_content_value();

public:
	const Item* content() const { return theContent; }

};


/*______________________________________________________________________
|  
|	upd:rename
|_______________________________________________________________________*/
class rename_value :	public update_value
{
protected:
	const Item* theName;

public:
	rename_value(
		const Item* target_p,
		const Item*);

	~rename_value();

public:
	//const qname* get_qname() const { return theName; }

};


} /* namespace zorba */
#endif /* XQP_UPDATE_VALUES_H */

