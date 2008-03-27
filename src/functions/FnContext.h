/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska
 */

#ifndef ZORBA_FN_CONTEXT_H
#define ZORBA_FN_CONTEXT_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"


namespace zorba {

  
  
class ctx_variable : public function
{
public:
  ctx_variable(const signature&);

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;

  bool requires_dyn_ctx () const { return true; }
};
  
}


#endif  /* ZORBA_FN_CONTEXT_H */
