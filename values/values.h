/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_VALUES_H
#define XQP_VALUES_H

#include "../context/common.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"
#include <sstream>

namespace xqp {

/*______________________________________________________________________
|  
|	Base class for the abstract value hierarchy
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
|	'sequence' - top of the XQuery value hierarchy
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class sequence : public object
{
public:
	virtual ~sequence() {}

public:		// accessors
	virtual sequence_type_t type() const = 0;
  virtual std::string describe() const = 0;

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public sequence
{
public:
	virtual ~item() {}

public:		// XQuery interface
	virtual iterator_t atomized_value() const = 0;
	virtual string string_value() const = 0;

	virtual bool is_empty() const = 0;
	virtual bool is_node() const = 0;
	virtual bool is_atomic() const = 0;

public:
  virtual std::ostream& put(std::ostream& os) const = 0;

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_value :	public item
{
protected:
	sequence_type_t theType;

public:
	atomic_value() : theType(xs_anyType) {}
	atomic_value(sequence_type_t type) : theType(type) {}
	virtual ~atomic_value() {}

public:		// accessors
	sequence_type_t type() const { return theType; }
  virtual std::string describe() const
		{ ostringstream oss; put(oss); return oss.str(); }
  virtual std::ostream& put(std::ostream& os) const = 0;

public:		// XQuery interface
	virtual iterator_t atomized_value() const = 0;
	virtual string string_value() const = 0;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


} /* namespace xqp */
#endif /* XQP_VALUES_H */

