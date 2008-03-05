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
      ~op_enclosed_expr() {}

    public:
      PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  }; /* class op_enclosed_expr */
  
  class op_docfilter_expr : public function {
    public:
      op_docfilter_expr(const signature&);
      ~op_docfilter_expr() {}

    public:
      PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  }; /* class op_docfilter_expr */
} /* namespace zorba */

#endif
