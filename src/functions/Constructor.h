/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf
 */

#ifndef XQP_CONSTRUCTOR_H
#define XQP_CONSTRUCTOR_H

#include "functions/function.h"

namespace xqp {
  class op_enclosed_expr : public function {
    public:
      op_enclosed_expr(const signature&);
      ~op_enclosed_expr() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      TypeSystem::xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  }; /* class op_enclosed_expr */
} /* namespace xqp */

#endif
