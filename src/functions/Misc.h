#ifndef ZORBA_MISC_H
#define ZORBA_MISC_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class fn_trace_func : public function {
  public:
    fn_trace_func(const signature&);
    ~fn_trace_func() {}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_error_func_1 : public function
{
  public:
    fn_error_func_1(const signature& s);
    ~fn_error_func_1() {}

  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature& s) const;
    bool validate_args(std::vector<PlanIter_t>& ) const;
};

class fn_error_func_2 : public function
{
  public:
    fn_error_func_2(const signature& s);
    ~fn_error_func_2() {}

  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature& s) const;
    bool validate_args(std::vector<PlanIter_t>& ) const;
};

class fn_error_func_3 : public function
{
  public:
    fn_error_func_3(const signature& s);
    ~fn_error_func_3() {}

  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature& s) const;
    bool validate_args(std::vector<PlanIter_t>& ) const;
};

}

#endif /* ZORBA_MISC_H */
/* vim:set ts=2 sw=2: */
