#ifndef XQP_FN_CONTEXT_IMPL_H
#define XQP_FN_CONTEXT_IMPL_H

#include "context/common.h"
#include "runtime/base/unarybase.h"

namespace xqp
{
  
  /**
   * CtxVariable
   */
  class CtxVariableIterator : public UnaryBaseIterator<CtxVariableIterator>
  {
    private:
      bool theNegate;
      xqp_string theVarname;

    public:
      CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter);
      // danm: Since UnaryBaseIterator "cleverly" expects a PlanIter_t *reference*,
      // we can't pass a temporary object in the initialization list.
      // Try it, it won't compile...
      // We also can't pass a static NULL reference since UnaryBaseIterator asserts.
      // Bottom line -- there's no way we can omit the aIter argument.
      CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter, xqp_string varName);
      virtual ~CtxVariableIterator();

      Item_t nextImpl(PlanState& planState);

      virtual void accept(PlanIterVisitor&) const;
      
     private:
       xqp_string varName;
  };
  
}

#endif //XQP_FN_CONTEXT_IMPL_H
