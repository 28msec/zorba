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

#include "node.h"
#include "values.h"


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
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

class update_value : public object
{
protected:
	context& ctx;
	rchandle<node> target_h;

public:
	update_value(
		context& _ctx, rchandle<node> _target_h)
		:
		ctx(_ctx), target_h(_target_h)
	{}
	~update_value() {}

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
class upd_insert_before : public update_value
{
protected:
	std::vector<rchandle<node> >& content_hv;

public:
	upd_insert_before(
		context& ctx,
		rchandle<node> target_h,
		vector<rchandle<node> > & content_hv);

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
	std::vector<rchandle<node> > & content_hv;

public:
	upd_insert_after(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<node> > & content_hv);

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
	std::vector<rchandle<node> > & content_hv;

public:
	upd_insert_into(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<node> > & content_hv);

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
	std::vector<rchandle<node> > & content_hv;

public:
	upd_insert_into_as_first(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<node> > & content_hv);

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
	std::vector<rchandle<node> > & content_hv;

public:
	upd_insert_into_as_last(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<node> > & content_hv);

	~upd_insert_into_as_last();

};

/*______________________________________________________________________
|  
|	upd:insertAttributes
|_______________________________________________________________________*/
class upd_insert_attributes : public update_value
{
protected:
	std::vector<rchandle<attribute_node> > & content_hv;

public:
	upd_insert_attributes(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<attribute_node> > & content_hv);

	~upd_insert_attributes();

};

/*______________________________________________________________________
|  
|	upd:delete
|_______________________________________________________________________*/
class upd_delete : public update_value
{
public:
	upd_delete(
		context& ctx,
		rchandle<node> target_h);

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
	std::vector<rchandle<node> > & content_hv;

public:
	upd_replace_node(
		context& ctx,
		rchandle<node> target_h,
		std::vector<rchandle<node> > & content_hv);

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
	std::string content;

public:
	upd_replace_value(
		context& ctx,
		rchandle<node> target_h,
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
	rchandle<text_node> content_h;
	
public:
	upd_replace_element_content(
		context& ctx,
		rchandle<node> target_h,
		rchandle<text_node> content_h);

	~upd_replace_element_content();

};

/*______________________________________________________________________
|  
|	upd:rename
|_______________________________________________________________________*/
class upd_rename : public update_value
{
protected:
	rchandle<QName> new_name_h;

public:
	upd_rename(
		context& ctx,
		rchandle<node> target_h,
		rchandle<QName> new_name_h);

	~upd_rename();

};



} /* namespace xqp */
#endif /* XQP_UPDATE_VALUES_H */

