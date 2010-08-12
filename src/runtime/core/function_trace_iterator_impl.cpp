#include <iostream>

#include "runtime/core/function_trace_iterator.h"

#include "zorbaerrors/error_manager.h"
#include "errors/user_error.h"

namespace zorba {

bool FunctionTraceIterator::nextImpl(store::Item_t &result, PlanState &aPlanState) const
{
  try {
    PlanIteratorState* lState = 0;
    DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
    while (consumeNext(result, theChildren[0], aPlanState)) {
      STACK_PUSH(true, lState);
    }
    STACK_END(lState);
  } catch (error::ZorbaError& err) {
    if (!err.theStackTrace.empty()) {
      const error::ZorbaError::StackEntry_t lLast = err.theStackTrace.back();
      const QueryLoc& lLoc = lLast.second;
      if (lLoc.getFilename() != theFunctionLocation.getFilename()) {
        throw err;
      }
      if (lLoc.getLineBegin() > theFunctionLocation.getLineBegin()) {
        throw err;
      }
      if (lLoc.getLineBegin() == theFunctionLocation.getLineBegin()
        && lLoc.getColumnBegin() > theFunctionLocation.getColumnBegin()) {
        throw err;
      }
      if (lLoc.getLineEnd() < theFunctionLocation.getLineEnd()) {
        throw err;
      }
      if (lLoc.getLineEnd() == theFunctionLocation.getLineEnd()
        && lLoc.getColumnEnd() > theFunctionLocation.getColumnEnd()) {
        throw err;
      }
    }
    err.theStackTrace.push_back(error::ZorbaError::StackEntry_t(
        theFunctionName,
        loc));
    throw err;
  }
}

void FunctionTraceIterator::setFunctionName(const store::Item_t& aFunctionName)
{
  theFunctionName = aFunctionName;
}

void FunctionTraceIterator::setFunctionLocation(const QueryLoc &aFunctionLocation)
{
  theFunctionLocation = aFunctionLocation;
}

} // namespace zorba
