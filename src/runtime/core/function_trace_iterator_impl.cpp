#include <iostream>

#include "runtime/core/function_trace_iterator.h"

#include "zorbaerrors/error_manager.h"
#include "errors/user_error.h"

namespace zorba {

void
FunctionTraceIterator::record_stack_trace(
    const QueryLoc& aLoc,
    const QueryLoc& aFuncCallLoc,
    const store::Item_t& aFunctionName,
    unsigned int aFunctionArity,
    error::ZorbaError* aError) const
{
  if (aError->theStackTrace.empty() && aError->hasQueryLocation())
  {
    if (aError->theQueryFileName != aLoc.getFilename().c_str())
      return;
    if (aError->theQueryLine < aLoc.getLineBegin())
      return;
    if (aError->theQueryLine > aLoc.getLineEnd())
      return;
    if (aError->theQueryLine == aLoc.getLineBegin()) {
      if (aError->theQueryColumn < aLoc.getColumnBegin())
        return;
      if (aError->theQueryColumn > aLoc.getColumnEnd())
        return;
    }
  }
  aError->theStackTrace.push_back(error::ZorbaError::StackEntry_t(
      aFuncCallLoc,
      std::pair<store::Item_t, unsigned int>(aFunctionName, aFunctionArity)));
  return;
}

bool FunctionTraceIterator::nextImpl(store::Item_t &result, PlanState &aPlanState) const
{
  try {
    PlanIteratorState* lState = 0;
    DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
    while (consumeNext(result, theChildren[0], aPlanState)) {
      STACK_PUSH(true, lState);
    }
    STACK_END(lState);
  } catch (error::ZorbaUserError& uerr) {
     // bugfix: for #3107911
     // it's important to not loose the information about the fact
     // that it's a user error here; otherwise, later catch clauses will
     // not be able to handle user errors anymore (e.g. try-catch expressions)
    record_stack_trace(theFunctionLocation, theFunctionCallLocation, theFunctionName, theFunctionArity, &uerr);
    throw uerr;
  } catch (error::ZorbaError& err) {
    record_stack_trace(theFunctionLocation, theFunctionCallLocation, theFunctionName, theFunctionArity, &err);
    throw err;
  }
  // never reached because either STACK_PUSH or STACK_END return a bool or record_stack_trace raises an error0
  return false;
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
