/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: zorba_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_VALUES_H
#define XQP_ZORBA_VALUES_H

#include "../types/sequence_type.h"
#include "../util/rchandle.h"
#include "../values/values.h"

#include <string>
 
namespace xqp {

class zorba;

/*______________________________________________________________________
|  
|  Base class for the zorba value hierarchy
|_______________________________________________________________________*/

class zorba_object : public object
{
public:
	zorba_object() {}
	~zorba_object() {}

public:
	virtual std::string describe(zorba*) const { return "zorba_object"; }
	virtual std::ostream& put(zorba*,std::ostream& os) const { return os; }
};


/*______________________________________________________________________
|  
|	 'xquery_exception' encapsulate xquery exceptions
|_______________________________________________________________________*/
/*daniel
class zorba_exception : public zorba_object,
																virtual public xquery_exception
													
{
public:
	zorba_exception() {}
	~zorba_exception() {}

public:
	virtual std::string describe(zorba*) const { return "zorba_exception"; }
	virtual std::ostream& put(zorba*,std::ostream& os) const { return os; }
};
*/

/*______________________________________________________________________
|  
|  'ft_value' encapsulates an xquery full-text search constraint.
|  Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|  [http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class zorba_ft_value : public zorba_object,
												virtual public ft_value
{
public:
	zorba_ft_value() {}
	~zorba_ft_value() {}

public:
	virtual std::string describe(zorba*) const { return "zorba_tf_value"; }
	virtual std::ostream& put(zorba*,std::ostream& os) const { return os; }
};


/*______________________________________________________________________
|  
|  'item' - top of the XQuery value hierarchy,
|  					union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class zorba_item : public zorba_object,
										virtual public item
{
public:
	zorba_item() {}
	virtual ~zorba_item() {}

public:		// accessors
	virtual sequence_type_t type() const = 0;
  virtual std::string describe(zorba*) const = 0;

public:		// XQuery interface
	virtual iterator_t atomized_value(zorba*, yy::location &loc) const = 0;
	virtual iterator_t string_value(zorba*, yy::location &loc) const = 0;

	virtual bool is_empty() const { return false; }
	virtual bool is_node() const { return false; }
	virtual bool is_atomic() const { return false; }
};



/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class zorba_atomic_value : public zorba_item,
														virtual public atomic_value
{
public:
	zorba_atomic_value() {}
	virtual ~zorba_atomic_value() {}

public:		// accessors
	virtual sequence_type_t type() const = 0;
  virtual std::string describe(zorba*) const = 0;
  virtual std::string str(zorba*) const = 0;

public:		// XQuery interface
	virtual iterator_t atomized_value(zorba*, yy::location &loc) const = 0;
	virtual iterator_t effective_boolean_value(zorba*, yy::location &loc) const = 0;
	virtual iterator_t string_value(zorba*, yy::location &loc) const = 0;

	virtual bool is_empty() const { return false; }
	virtual bool is_node() const { return false; }
	virtual bool is_atomic() const { return true; }
};


} /* namespace xqp */
#endif /* XQP_ZORBA_VALUES_H */

