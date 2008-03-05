/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef ZORBA_PLAN_VISITOR_H
#define ZORBA_PLAN_VISITOR_H

#include <vector>
#include "compiler/expression/expr.h"
#include "runtime/core/item_iterator.h"


/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace zorba {
  typedef rchandle<class LetVarIterator> ref_iter_t;
  template <class T> class hash64map;

  PlanIter_t codegen (const char *descr, expr *root, hash64map<std::vector<ref_iter_t> *> *param_var_map = NULL);

} /* namespace zorba */
#endif /* ZORBA_PLAN_VISITOR_H */
