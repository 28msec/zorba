/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_VALUES_H
#define XQP_ABSTRACT_VALUES_H

#include "../runtime/abstract_iterator.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"
#include <string>
 
namespace xqp {

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class abstract_object
{
};


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class abstract_xquery_exception : public abstract_object
{
};


/*______________________________________________________________________
|  
|	'ft_value' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class abstract_ft_value : public abstract_object
{
};


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class abstract_value : public abstract_object
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

public:
	sequence_type_t type() const;
};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class abstract_item : public abstract_value
{
public:		// XQuery interface
	std::string string_value() const;
	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;

	bool is_node() const;
	bool is_atomic() const;
};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class abstract_atomic_value : public abstract_item
{
public:		// accessors
  std::ostream& put(std::ostream&) const;
  std::string describe() const;

public:		// XQuery interface
	std::string string_value() const;
	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;

	bool is_sequence() const;
	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;
};



/*______________________________________________________________________
|  
|	 abstract nodes defined in 'abstract_nodes.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_ABSTRACT_VALUES_H */

