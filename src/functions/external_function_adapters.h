#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class stateless_external_function_adapter : public external_function {
  public:
    stateless_external_function_adapter(
      const signature& sig, 
      StatelessExternalFunction *function,
      bool aIsUpdating);
    ~stateless_external_function_adapter();

    virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    virtual expr_update_t getUpdateType() const { return theUpdateType; }

  private:
    StatelessExternalFunction *m_function;
    expr_update_t theUpdateType;
};

} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */
/* vim:set ts=2 sw=2: */
