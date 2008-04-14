#ifndef ZORBA_FN_CONTEXT_IMPL_H
#define ZORBA_FN_CONTEXT_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba
{
  
/*******************************************************************************

  CtxVariableIterator

  Used in the evaluation of external variables: For each external variable, the
  dynamic context maps the name of the variable to an iterator that computes the
  variable's value. CtxVariableIterator extracts this iterator from the dynamic
  context and just returns the items that it produces.

********************************************************************************/
class CtxVariableIteratorState : public  PlanIteratorState {
public:
  store::Iterator_t iter;
};

NARY_ITER_STATE (CtxVariableIterator, CtxVariableIteratorState);
  
}

#endif //ZORBA_FN_CONTEXT_IMPL_H
