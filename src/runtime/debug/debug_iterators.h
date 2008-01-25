#ifndef XQP_DEBUG_ITERATORS_H
#define XQP_DEBUG_ITERATORS_H

#include "runtime/base/iterator.h"

namespace xqp {


class FnTraceIteratorState : public PlanIteratorState {
  public:
    Item_t theTagItem;
    xqp_string theTag;

    void init();
    void reset();
};

NARY_ITER_STATE(FnTraceIterator, FnTraceIteratorState);

} /* namespace xqp */

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
