/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_PLAN_VISITOR_H
#define XQP_PLAN_VISITOR_H

#include "compiler/expression/expr.h"
#include "runtime/core/item_iterator.h"


/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

  PlanIter_t codegen (expr *root);

} /* namespace xqp */
#endif /* XQP_PLAN_VISITOR_H */
