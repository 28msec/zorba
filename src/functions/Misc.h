#ifndef XQP_MISC_H
#define XQP_MISC_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace xqp {

class fn_trace_func : public function {
  public:
    fn_trace_func(const signature&);
    ~fn_trace_func() {}

    PlanIter_t operator() (const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

}

#endif /* XQP_MISC_H */
/* vim:set ts=2 sw=2: */
