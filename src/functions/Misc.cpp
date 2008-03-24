#include "functions/Misc.h"

#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "runtime/debug/debug_iterators.h"
#include "runtime/misc/MiscImpl.h"

using namespace std;

namespace zorba {

fn_trace_func::fn_trace_func(const signature& sig)
  : function(sig) { }

PlanIter_t fn_trace_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if ( !validate_args ( argv ) )
	{
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  }
  return new FnTraceIterator ( loc, argv );
}

xqtref_t fn_trace_func::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

bool fn_trace_func::validate_args(std::vector<PlanIter_t>& argv) const
{
  return argv.size() == 2;
}

/*******************************************************************************
  3 The Error Function
********************************************************************************/

fn_error::fn_error (const signature &sig) : function (sig) {}

xqtref_t fn_error::type_check(signature&) const
{
  return GENV_TYPESYSTEM.NONE_TYPE;
}

PlanIter_t fn_error::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);

  return new FnErrorIterator(loc, argv);
}

bool fn_error::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 0 || argv.size() == 1 ||
             argv.size() == 2 || argv.size() == 3 );
}

/*******************************************************************************
  8.1 fn:resolve-uri
********************************************************************************/

fn_resolve_uri::fn_resolve_uri(const signature& sig)
  : function(sig) { }

PlanIter_t fn_resolve_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);

  return new FnResolveUriIterator ( loc, argv );
}

xqtref_t fn_resolve_uri::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool fn_resolve_uri::validate_args(std::vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2 );
}

}
/* vim:set ts=2 sw=2: */
