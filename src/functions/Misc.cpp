#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "functions/Misc.h"
#include "runtime/debug/debug_iterators.h"

namespace zorba {

fn_trace_func::fn_trace_func(const signature& sig)
  : function(sig) { }

PlanIter_t fn_trace_func::operator()(const QueryLoc& loc, std::vector<PlanIter_t>& argv) const
{
  if ( !validate_args ( argv ) )
	{
    ZorbaAlertFactory::error_alert (
		   ZorbaError::XPST0017,
       &loc
		);
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

}
/* vim:set ts=2 sw=2: */
