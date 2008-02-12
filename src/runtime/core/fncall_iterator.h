#ifndef XQP_FNCALL_ITERATOR_H
#define XQP_FNCALL_ITERATOR_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace xqp {

class UDFunctionCallIteratorState : public PlanIteratorState {
  public:
    PlanState *theFnBodyStateBlock;
    PlanIterator *thePlan;

    UDFunctionCallIteratorState();
    ~UDFunctionCallIteratorState();

    void init(PlanState&);
    void reset(PlanState&);
};

class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator, 
                                                       UDFunctionCallIteratorState> {
  public:
    UDFunctionCallIterator(const yy::location& loc, 
                           std::vector<PlanIter_t>& args, 
                           const user_function *aUDF)
      : NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>(loc, args), 
        theUDF(aUDF) { }

    virtual ~UDFunctionCallIterator() { }

    Item_t nextImpl(PlanState& planState);

    virtual void accept(PlanIterVisitor& v) const;

  protected:

    const user_function *theUDF;
};

}

#endif /* XQP_FNCALL_ITERATOR_H */
/* vim:set ts=2 sw=2: */
