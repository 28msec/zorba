#ifndef XQP_DEBUG_ITERATORS_H
#define XQP_DEBUG_ITERATORS_H

#include "context/common.h"
#include "runtime/base/binarybase.h"

namespace xqp {

class FnTraceIterator : public BinaryBaseIterator<FnTraceIterator> {
  public:
    FnTraceIterator(const yy::location& loc, PlanIter_t aChild0, PlanIter_t aChild1);

    virtual ~FnTraceIterator();

    Item_t nextImpl(PlanState& planState);

    void resetImpl(PlanState& planState);

    void releaseResourcesImpl(PlanState& planState);

    virtual uint32_t getStateSize() const { return sizeof(FnTraceIteratorState); }

    void setOffset(PlanState& planState, uint32_t& offset);

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    class FnTraceIteratorState : public PlanIteratorState {
      public:
        Item_t theTagItem;
        xqp_string theTag;

        void init();
        void reset();
    };
};

}

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
