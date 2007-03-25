/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_DOM_VALUES_H
#define XQP_DOM_VALUES_H

#include "../values/abstract_values.h"
#include "../runtime/abstract_iterator.h"
#include "../types/sequence_type.h"

#include <string>
#include <vector>
 
namespace xqp {


/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class dom_object : public abstract_object
{
public:
	dom_object() {}
	~dom_object() {}

};


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class dom_xquery_exception :	public dom_object,
															public abstract_xquery_exception
{
protected:
	std::string msg;

public:
	dom_xquery_exception() {}
	dom_xquery_exception(const std::string& _msg) : msg(_msg) {}
	~dom_xquery_exception() {}

};


/*______________________________________________________________________
|  
|	'ft_value' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class dom_ft_value :	public dom_object,
											public abstract_ft_value
{
public:
	dom_ft_value() {}
	~dom_ft_value() {}

};


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class dom_value	: public dom_object,
									public abstract_value
{
public:
	sequence_type_t mType;

public:
	dom_value(sequence_type_t _type) : mType(_type) {}
	dom_value() {}
	~dom_value() {}

public:		// accessors
	sequence_type_t type() const { return mType; }

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class dom_item :	public dom_value,
									public abstract_item
{
public:
	dom_item(sequence_type_t type) : dom_value(type) {}
	dom_item() {}
	~dom_item() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "item()"; }

public:		// XQuery interface
	iterator_t atomized_value() const { return NULL; }
	std::string string_value() const { return ""; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return false; }
};



} /* namespace xqp */
#endif /* XQP_DOM_VALUES_H */

