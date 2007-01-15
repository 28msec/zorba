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

#include "../context/context.h"
#include "../types/qname.h"
#include "../types/types.h"
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
	~object() {}

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
	~value() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&,  context const&) const;

	virtual bool is_sequence() const;
	virtual bool is_empty() const;

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
	~item() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&,  context const&) const;

	virtual bool is_node() const;
	virtual bool is_atomic() const;

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

class atomic_value : public item
{
protected:
	// declared or annonymous type
	qnameid type_annotation;

public:
	atomic_value() {}
	~atomic_value() {}

public:
  virtual void put(std::ostream&, context const&) const;
  virtual void describe(std::ostream&, context const&) const;
	virtual enum type::typecode get_typecode() const;

};


/*______________________________________________________________________
|  
|	'node' values defined in 'nodes.h'
|	'function' values defined in 'funcval.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_VALUES_H */

