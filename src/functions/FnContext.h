#ifndef ZORBA_FN_CONTEXT_H
#define ZORBA_FN_CONTEXT_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"


namespace zorba {

  
  
class ctx_variable : public function
{
public:
  ctx_variable(const signature& sig) : function (sig) {}

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  bool requires_dyn_ctx () const { return true; }
};
  
class ctx_var_assign : public function
{
public:
  ctx_var_assign(const signature& sig) : function (sig) {}

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  bool requires_dyn_ctx () const { return true; }
};
  
}


#endif  /* ZORBA_FN_CONTEXT_H */
