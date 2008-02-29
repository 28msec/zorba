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

#ifndef XQP_CONTEXT_FUNCTIONS_H
#define XQP_CONTEXT_FUNCTIONS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace xqp
{

class zorba;

// 16.1 fn:position
class fn_position : public function
{
  public:
    fn_position(const signature&);
    ~fn_position(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.2 fn:last
class fn_last : public function
{
  public:
    fn_last(const signature&);
    ~fn_last(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.3 fn:current-dateTime
class fn_current_dateTime : public function
{
  public:
    fn_current_dateTime(const signature&);
    ~fn_current_dateTime(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.4 fn:current-date
class fn_current_date : public function
{
  public:
    fn_current_date(const signature&);
    ~fn_current_date(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.5 fn:current-time
class fn_current_time : public function
{
  public:
    fn_current_time(const signature&);
    ~fn_current_time(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.6 fn:implicit-timezone
class fn_implicit_timezone : public function
{
  public:
    fn_implicit_timezone(const signature&);
    ~fn_implicit_timezone(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.7 fn:default-collation
class fn_default_collation : public function
{
  public:
    fn_default_collation(const signature&);
    ~fn_default_collation(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 16.8 fn:static-base-uri
class fn_static_base_uri : public function
{
  public:
    fn_static_base_uri(const signature&);
    ~fn_static_base_uri(){}
     
    PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

} /* namespace xqp */
#endif  /* XQP_CONTEXT_FUNCTIONS_H */
