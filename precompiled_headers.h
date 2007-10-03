#ifndef __PRECOMPILED_HEADERS_INCLUDED__
#define __PRECOMPILED_HEADERS_INCLUDED__

#ifdef USE_GCH

#include <string>
#include <vector>


#include "errors/Error.h"
#include "errors/errors.h"

#include "context/common.h"
#include "context/context.h"
#include "context/static_context.h"

#include "exprtree/expr.h"

#include "functions/function.h"

#include "parser/location.hh"
#include "parser/position.hh"
#include "parser/parsenodes.h"
#include "parser/symbol_table.h"
#include "parser/xquery_driver.h"

#include "runtime/batching.h"
#include "runtime/zorba.h"

#include "store/api/item.h"

#include "types/typecodes.h"
#include "types/casting.h"
#include "types/sequence_type.h"

#endif

#endif
