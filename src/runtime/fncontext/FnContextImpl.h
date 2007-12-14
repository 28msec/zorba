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

    public:
      CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter);
      CtxVariableIterator ( const yy::location& loc, xqp_string varName);
      virtual ~CtxVariableIterator();

      Item_t nextImpl(PlanState& planState);

      virtual void accept(PlanIterVisitor&) const;
      
     private:
       xqp_string varName;
  };
  
}

#endif //XQP_FN_CONTEXT_IMPL_H
