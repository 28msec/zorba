/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_VALUES_H
#define XQP_VALUES_H

#include "../runtime/iterator.h"
#include "../types/base_types.h"
#include "../util/rchandle.h"

#include <string>
#include <vector>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class object : public rcobject
{
public:
	object() {}
	virtual ~object() {}

};



/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class xquery_exception : public object
{
public:
	xquery_exception() {}
	~xquery_exception() {}

};


/*______________________________________________________________________
|  
|	'ft_value' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class ft_value : public object
{
public:
	ft_value() {}
	~ft_value() {}

};


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class value	: public object
{
public:
	value() {}
	virtual ~value() {}

public:
  virtual std::ostream& put(std::ostream&, context const&) const;
  virtual std::string describe(context const&) const;

	virtual bool is_sequence() const;
	virtual bool is_empty() const;

	virtual item_iterator atomized_value(context const&) const;
	virtual item_iterator effective_boolean_value(context const&) const;

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public value
{
public:
	item() {}
	virtual ~item() {}

public:
  virtual std::ostream& put(std::ostream&, context const&) const;
  virtual std::string describe(context const&) const;

	virtual bool is_node() const;
	virtual bool is_atomic() const;

	virtual item_iterator atomized_value(context const&) const;
	virtual item_iterator effective_boolean_value(context const&) const;

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

class atomic_value : public item
{
public:
	atomic_value() {}
	virtual ~atomic_value() {}

public:
  virtual std::ostream& put(std::ostream&, context const&) const;
  virtual std::string describe(context const&) const;
	virtual enum type::typecode get_typecode() const;

	bool is_sequence() const { return false; }
	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

	virtual item_iterator atomized_value(context const&) const;
	virtual item_iterator effective_boolean_value(context const&) const;

};


/*______________________________________________________________________
|  
|	'node' values defined in 'nodes.h'
|	'function' values defined in 'funcval.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_VALUES_H */

