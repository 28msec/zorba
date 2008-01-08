/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza
 */

#include "functions/DateTime.h"
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"

namespace xqp
{

fn_datetime_ctor::fn_datetime_ctor (
    const signature& sig )
    :
    function ( sig )
{
}

PlanIter_t fn_datetime_ctor::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv ) const
{
  return new FnDateTimeConstructorIterator(loc, argv[0], argv[1]);
}

bool fn_datetime_ctor::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return true;
}

TypeSystem::xqtref_t fn_datetime_ctor::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
}


} // namespace xqp

