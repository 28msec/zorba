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
#include <string>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class abstract_value
{
public:	
	sequence_type_t type() const { return xs_anyType; }

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class abstract_item : public abstract_value
{
public:
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "item()"; }

public:		// XQuery interface
	abstract_iterator atomized_value() const
	{ return abstract_iterator::emptySequence; }

	abstract_iterator effective_boolean_value() const
	{ return abstract_iterator::emptySequence; }

	std::string string_value() const { return ""; }
	bool is_node() const { return false; }
	bool is_atomic() const { return false; }

};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class abstract_atomic_value : public abstract_item
{
public:
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "atomic_value()"; }

public:		// XQuery interface
	abstract_iterator atomized_value() const
	{ return abstract_iterator::emptySequence; }

	abstract_iterator effective_boolean_value() const
	{ return abstract_iterator::emptySequence; }

	std::string string_value() const { return ""; }
	bool is_sequence() const { return false; }
	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};




/*______________________________________________________________________
|  
|	'node' values defined in 'abstract_nodes.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_ABSTRACT_VALUES_H */

