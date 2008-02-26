#ifndef XQP_EXTERNAL_FUNCTION_ADAPTERS_H
#define XQP_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace xqp {

class stateless_external_function_adapter : public external_function {
  public:
    stateless_external_function_adapter(const signature& sig, StatelessExternalFunction *function);
    ~stateless_external_function_adapter();

    virtual PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>& argv) const;

    virtual xqtref_t type_check(signature& s) const;

    virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

  private:
    StatelessExternalFunction *m_function;
};

} /* namespace xqp */
#endif  /* XQP_EXTERNAL_FUNCTION_ADAPTERS_H */
/* vim:set ts=2 sw=2: */
