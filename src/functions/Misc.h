#ifndef ZORBA_MISC_H
#define ZORBA_MISC_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {
  
class fn_trace_func : public function {
  public:
    fn_trace_func(const signature&);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_error : public function {
  public:
    fn_error(const signature& s);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature& s) const;
    bool validate_args(std::vector<PlanIter_t>& ) const;
};

class fn_resolve_uri : public function {
  public:
    fn_resolve_uri(const signature&);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

}

#endif /* ZORBA_MISC_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
