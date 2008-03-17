#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class stateless_external_function_adapter : public external_function {
  public:
    stateless_external_function_adapter(const signature& sig, StatelessExternalFunction *function);
    ~stateless_external_function_adapter();

    virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    virtual xqtref_t type_check(signature& s) const;

    virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

  private:
    StatelessExternalFunction *m_function;
};

} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */
/* vim:set ts=2 sw=2: */
