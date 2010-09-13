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
    if (err.theStackTrace.empty() && err.hasQueryLocation())
    {
      if (err.theQueryFileName != theFunctionLocation.getFilename().c_str())
        throw err;
      if (err.theQueryLine < theFunctionLocation.getLineBegin())
        throw err;
      if (err.theQueryLine > theFunctionLocation.getLineEnd())
        throw err;
      if (err.theQueryLine == theFunctionLocation.getLineBegin()) {
        if (err.theQueryColumn < theFunctionLocation.getColumnBegin())
          throw err;
        if (err.theQueryColumn > theFunctionLocation.getColumnEnd())
          throw err;
      }
    }
    err.theStackTrace.push_back(error::ZorbaError::StackEntry_t(
        theFunctionCallLocation,
        std::pair<store::Item_t, unsigned int>(theFunctionName, theFunctionArity))
                                );
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

void FunctionTraceIterator::setFunctionCallLocation(const QueryLoc &aFunctionLocation)
{
  theFunctionCallLocation = aFunctionLocation;
}

void FunctionTraceIterator::setFunctionArity(unsigned int arity)
{
  theFunctionArity = arity;
}

} // namespace zorba
