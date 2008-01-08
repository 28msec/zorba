/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_DATETIME_H
#define XQP_DATETIME_H

#include "functions/function.h"

namespace xqp
{

class fn_datetime_ctor : public function
{
  public:
    fn_datetime_ctor(const signature&);
    virtual ~fn_datetime_ctor() {};

  public:
    PlanIter_t operator()(const yy::location& loc,std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

} // namespace xqp

#endif
