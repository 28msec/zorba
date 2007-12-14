/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza
 */

#include "functions/DateTime.h"
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"

namespace xqp
{

// 10.4.5 op:duration-equal
op_duration_equal::op_duration_equal (
    const signature& sig )
    :
    function ( sig )
{
}

PlanIter_t op_duration_equal::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv ) const
{
  return new OpDurationEqualIterator(loc, argv[0], argv[1]);
}

bool op_duration_equal::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return true;
}

TypeSystem::xqtref_t op_duration_equal::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
}


} // namespace xqp

