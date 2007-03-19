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
#include "../util/rchandle.h"
#include <string>
 
namespace xqp {


class abstract_item 
{
public:
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "item()"; }

public:		// XQuery interface
	rchandle<abstract_iterator> atomized_value() const { return NULL; }
	rchandle<abstract_iterator> effective_boolean_value() const { return NULL; }
	std::string string_value() const { return ""; }
	bool is_node() const { return false; }
	bool is_atomic() const { return false; }

};


} /* namespace xqp */
#endif /* XQP_ABSTRACT_VALUES_H */

