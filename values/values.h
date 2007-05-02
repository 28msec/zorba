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

#include <iostream>
#include <sstream>
#include <string>

namespace xqp {

class zorba;

/*______________________________________________________________________
|  
|	Base class for the abstract value hierarchy
|_______________________________________________________________________*/

class object : public rcobject
{
public:
  virtual std::string describe(zorba*) const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;
};


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class xquery_exception : public object
{
public:
  virtual std::string describe(zorba*) const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;
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
  virtual std::string describe(zorba*) const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;
};


/*______________________________________________________________________
|  
|	'item' - top of the XQuery value hierarchy,
|	         union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public object
{
public:
	virtual sequence_type_t type() const = 0;
  virtual std::string describe(zorba*) const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;

public:		// XQuery interface
	virtual iterator_t atomized_value(zorba*) const = 0;
	virtual iterator_t string_value(zorba*) const = 0;

	virtual bool is_empty() const = 0;
	virtual bool is_node() const = 0;
	virtual bool is_atomic() const = 0;

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_value :	virtual public item
{
public:		// accessors
	virtual sequence_type_t type() const = 0;
  virtual std::string describe(zorba*) const = 0;
  virtual std::ostream& put(zorba*,std::ostream& os) const = 0;

public:		// XQuery interface
	virtual iterator_t atomized_value(zorba*) const = 0;
	virtual iterator_t effective_boolean_value(zorba*) const = 0;
	virtual iterator_t string_value(zorba*) const = 0;

	bool is_empty() const = 0;
	bool is_node() const = 0;
	bool is_atomic() const = 0;

};


} /* namespace xqp */
#endif /* XQP_VALUES_H */

