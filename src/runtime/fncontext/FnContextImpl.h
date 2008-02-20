#ifndef XQP_FN_CONTEXT_IMPL_H
#define XQP_FN_CONTEXT_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/noarybase.h"

namespace xqp
{
  
/*******************************************************************************

  CtxVariableIterator

  Used in the evaluation of external variables: For each external variable, the
  dynamic context maps the name of the variable to an iterator that computes the
  variable's value. CtxVariableIterator extracts this iterator from the dynamic
  context and just returns the items that it produces.

********************************************************************************/
class CtxVariableIterator : public NoaryBaseIterator<CtxVariableIterator, PlanIteratorState>
{
private:
  xqpString theVarName;

public:
  CtxVariableIterator(const yy::location& loc, xqpString varName);

  virtual ~CtxVariableIterator();

  // inherit openImpl from NoaryBaseIterator
  Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;

  xqp_string getVarName() const { return theVarName; }
};
  
}

#endif //XQP_FN_CONTEXT_IMPL_H
