/* -*- mode: c++; indent-tabs-mode: nil -*-
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

class context;
class itemstore;

/*______________________________________________________________________
|  
|  Base class for the zorba value hierarchy
|_______________________________________________________________________*/

class zorba_object : public object
{
public:
	zorba_object() {}
	~zorba_object() {}
};


/*______________________________________________________________________
|  
|	 'xquery_exception' encapsulate xquery exceptions
|_______________________________________________________________________*/

class zorba_xquery_exception : public zorba_object,
																public virtual xquery_exception
													
{
public:
	zorba_xquery_exception() {}
	~zorba_xquery_exception() {}
};


/*______________________________________________________________________
|  
|  'ft_value' encapsulates an xquery full-text search constraint.
|  Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|  [http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class zorba_ft_value : public zorba_object,
												public virtual ft_value
{
public:
	zorba_ft_value() {}
	~zorba_ft_value() {}
};


/*______________________________________________________________________
|  
|  'value' - top of the XQuery value hierarchy
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class zorba_sequence : public zorba_object,
												public virtual sequence
{
public:
	zorba_sequence() {}
	~zorba_sequence() {}

public:		// accessors
  virtual std::string describe() const { return "item*"; }
	virtual sequence_type_t type() const { return xs_anyTypeSeq; }
  virtual std::ostream& put(std::ostream& os) const { return os; }

};


/*______________________________________________________________________
|  
|  'item' - union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class zorba_item : public zorba_sequence//,
										//public virtual item
{
public:
	zorba_item() {}
	~zorba_item() {}

public:		// accessors
  virtual std::string describe() const { return "item"; }
	virtual sequence_type_t type() const { return xs_anyType; }

public:		// XQuery interface
	virtual string string_value() const { return ""; }
	virtual iterator_t atomized_value() const { return NULL; }
	virtual bool is_empty() const { return false; }
	virtual bool is_node() const { return false; }
	virtual bool is_atomic() const { return false; }
};



/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class zorba_atomic_value :	public zorba_item,
															public virtual atomic_value
{
public:
	zorba_atomic_value() {}
	~zorba_atomic_value() {}

public:		// accessors
  virtual std::string describe() const { return "xs_atomicValue"; }
	virtual sequence_type_t type() const { return xs_anyAtomicType; }

public:		// XQuery interface
	virtual iterator_t atomized_value() const { return NULL; }
	virtual string string_value() const { return ""; }

	virtual bool is_empty() const { return false; }
	virtual bool is_node() const { return false; }
	virtual bool is_atomic() const { return true; }
};


} /* namespace xqp */
#endif /* XQP_ZORBA_VALUES_H */

