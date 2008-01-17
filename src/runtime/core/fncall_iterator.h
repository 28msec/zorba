#ifndef XQP_FNCALL_ITERATOR_H
#define XQP_FNCALL_ITERATOR_H

#include "context/common.h"
#include "runtime/base/narybase.h"

namespace xqp {

class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator> {
  public:
    // TODO: add pointer to ud_function object as the the third arg.
    UDFunctionCallIterator(const yy::location& loc, std::vector<PlanIter_t>& args)
      : NaryBaseIterator<UDFunctionCallIterator>(loc, args) { }
    virtual ~UDFunctionCallIterator() { }

    Item_t nextImpl(PlanState& planState);

    void resetImpl(PlanState& planState);

    void releaseResourcesImpl(PlanState& planState);

    virtual uint32_t getStateSize() const { return sizeof(UDFunctionCallIteratorState); }

    void setOffset(PlanState& planState, uint32_t& offset);

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    class UDFunctionCallIteratorState : public PlanIteratorState {
      public:
        PlanState *theFnBodyStateBlock;

        void init();
        void reset();
    };
};

}

#endif /* XQP_FNCALL_ITERATOR_H */
/* vim:set ts=2 sw=2: */
