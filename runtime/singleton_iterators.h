/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: singleton_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_SINGLETON_ITERATOR_H
#define XQP_SINGLETON_ITERATOR_H

#include "values/primitive_values.h"

namespace xqp {

typedef singleton_iterator<numericValue> numeric_singleton;
typedef singleton_iterator<stringValue> string_singleton;
typedef singleton_iterator<timeValue> time_singleton;
typedef singleton_iterator<binaryValue> binary_singleton;
typedef singleton_iterator<booleanValue> boolean_singleton;

} /* namespace xqp */
#endif /* XQP_SINGLETON_ITERATOR_H */

