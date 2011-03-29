#ifndef ZORBA_XQUERY_STACK_TRACE_H
#define ZORBA_XQUERY_STACK_TRACE_H

#include <zorba/xquery_stack_trace.h>
#include "compiler/parser/query_loc.h"
#include "store/api/item.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void recordStackTrace( QueryLoc const &loc, QueryLoc const &call_loc,
                       store::Item_t const &fn_name,
                       XQueryStackTrace::fn_arity_type fn_arity,
                       ZorbaException &ze );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_XQUERY_STACK_TRACE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
