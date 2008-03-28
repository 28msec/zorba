/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf
 */

#ifndef ZORBA_CONSTRUCTOR_H
#define ZORBA_CONSTRUCTOR_H

#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {
  class op_enclosed_expr : public function {
    public:
      op_enclosed_expr(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
  }; /* class op_enclosed_expr */
  
  class op_docfilter_expr : public function {
    public:
      op_docfilter_expr(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
  }; /* class op_docfilter_expr */
} /* namespace zorba */

#endif
