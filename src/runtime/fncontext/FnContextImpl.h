#ifndef ZORBA_FN_CONTEXT_IMPL_H
#define ZORBA_FN_CONTEXT_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/noarybase.h"

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
  Iterator_t iter;
};


class CtxVariableIterator : public NoaryBaseIterator<CtxVariableIterator, CtxVariableIteratorState>
{
private:
  xqpStringStore_t theVarName;

public:
  CtxVariableIterator(const QueryLoc& loc, xqpStringStore* varName);

  virtual ~CtxVariableIterator();


  void openImpl ( PlanState& planState, uint32_t& offset );
  store::Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;

  xqp_string getVarName() const { return theVarName.getp(); }
};
  
}

#endif //ZORBA_FN_CONTEXT_IMPL_H
