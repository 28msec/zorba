/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: SingletonIterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_SINGLETON_ITERATOR_H
#define XQP_SINGLETON_ITERATOR_H

#include "values/primitive_values.h"

namespace xqp {

typedef SingletonIterator<numericValue> numeric_singleton;
typedef SingletonIterator<stringValue> string_singleton;
typedef SingletonIterator<timeValue> time_singleton;
typedef SingletonIterator<binaryValue> binary_singleton;
typedef SingletonIterator<booleanValue> boolean_singleton;

} /* namespace xqp */
#endif /* XQP_SINGLETON_ITERATOR_H */

