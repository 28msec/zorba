/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_UPDATE_VALUES_H
#define XQP_UPDATE_VALUES_H

#include "values.h"
#include "nodes.h"
#include "../types/qname.h"


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
class upd_insert_before : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_insert_before(
		context& ctx,
		node& target,
		vector<node> const& content);

	~upd_insert_before();

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
class upd_insert_after : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_insert_after(
		context& ctx,
		node& target,
		std::vector<node> const& content);

	~upd_insert_after();

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
class upd_insert_into : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_insert_into(
		context& ctx,
		node& target,
		std::vector<node> const& content);

	~upd_insert_into();

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
class upd_insert_into_as_first : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_insert_into_as_first(
		context& ctx,
		node& target,
		std::vector<node> const& content);

	~upd_insert_into_as_first();

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
class upd_insert_into_as_last : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_insert_into_as_last(
		context& ctx,
		node& target,
		std::vector<node> const& content);

	~upd_insert_into_as_last();

};

/*______________________________________________________________________
|  
|	upd:insertAttributes
|_______________________________________________________________________*/
class upd_insert_attributes : public update_value
{
protected:
	element_node target;
	std::vector<attribute_node> content;

public:
	upd_insert_attributes(
		context& ctx,
		element_node& target,
		std::vector<attribute_node> const& content);

	~upd_insert_attributes();

};

/*______________________________________________________________________
|  
|	upd:delete
|_______________________________________________________________________*/
class upd_delete : public update_value
{
protected:
	node target;

public:
	upd_delete(
		context& ctx,
		node& target);

	~upd_delete();

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
class upd_replace_node : public update_value
{
protected:
	node target;
	std::vector<node> content;

public:
	upd_replace_node(
		context& ctx,
		node& target,
		std::vector<node> const& content);

	~upd_replace_node();

};

/*______________________________________________________________________
|  
|	upd:replaceValue
|
|	'target' must be an attribute, text, comment, or processing
|	instruction node.
|_______________________________________________________________________*/
class upd_replace_value : public update_value
{
protected:
	node target;
	std::string content;

public:
	upd_replace_value(
		context& ctx,
		node& target,
		std::string const& content);

	~upd_replace_value();

};

/*______________________________________________________________________
|  
|	upd:replaceElementContent
|_______________________________________________________________________*/
class upd_replace_element_content : public update_value
{
protected:
	node target;
	text_node content;
	
public:
	upd_replace_element_content(
		context& ctx,
		node& target,
		text_node const& content);

	~upd_replace_element_content();

};

/*______________________________________________________________________
|  
|	upd:rename
|_______________________________________________________________________*/
class upd_rename : public update_value
{
public:
	upd_rename(
		context& ctx,
		node& target,
		QName& new_name);

	~upd_rename();

};



} /* namespace xqp */
#endif /* XQP_UPDATE_VALUES_H */

