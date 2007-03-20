/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_update_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan.Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_UPDATE_VALUES_H
#define XQP_ABSTRACT_UPDATE_VALUES_H

#include "abstract_values.h"
#include "abstract_nodes.h"
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

/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

class abstract_update_value
	: public abstract_object
{
public:
	typedef rchandle<abstract_iterator> iterator_t;
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
class abstract_insert_before_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
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
class abstract_insert_after_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
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
class abstract_insert_into_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
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
class abstract_insert_into_as_first_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
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
class abstract_insert_into_as_last_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
	iterator_t new_nodes() const;

};

/*______________________________________________________________________
|  
|	upd:insertAttributes
|_______________________________________________________________________*/
class abstract_insert_attributes_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
	iterator_t new_nodes() const;

};

/*______________________________________________________________________
|  
|	upd:delete
|_______________________________________________________________________*/
class abstract_delete_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;

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
class abstract_replace_node_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
	iterator_t new_nodes() const;

};

/*______________________________________________________________________
|  
|	upd:replaceValue
|
|	'target' must be an attribute, text, comment, or processing
|	instruction node.
|_______________________________________________________________________*/
class abstract_replace_value_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
	std::string content() const;

};

/*______________________________________________________________________
|  
|	upd:replaceElementContent
|_______________________________________________________________________*/
class abstract_replace_element_content_value
	: public abstract_update_value
{
public:
	const abstract_element_node* target() const;
	const abstract_text_node* content() const;
	
};

/*______________________________________________________________________
|  
|	upd:rename
|_______________________________________________________________________*/
class abstract_rename_value
	: public abstract_update_value
{
public:
	const abstract_node* target() const;
	const abstract_qname* qname() const;

};


} /* namespace xqp */
#endif /* XQP_ABSTRACT_UPDATE_VALUES_H */

