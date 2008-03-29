/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 * 
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/ContextFunctions.h
 *
 */

#ifndef ZORBA_CONTEXT_FUNCTIONS_H
#define ZORBA_CONTEXT_FUNCTIONS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba
{

class zorba;

// 16.3 fn:current-dateTime
class fn_current_dateTime : public function
{
  public:
    fn_current_dateTime(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.4 fn:current-date
class fn_current_date : public function
{
  public:
    fn_current_date(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.5 fn:current-time
class fn_current_time : public function
{
  public:
    fn_current_time(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.6 fn:implicit-timezone
class fn_implicit_timezone : public function
{
  public:
    fn_implicit_timezone(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.7 fn:default-collation
class fn_default_collation : public function
{
  public:
    fn_default_collation(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

} /* namespace zorba */
#endif  /* ZORBA_CONTEXT_FUNCTIONS_H */
