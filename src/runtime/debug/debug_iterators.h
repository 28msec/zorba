#ifndef XQP_DEBUG_ITERATORS_H
#define XQP_DEBUG_ITERATORS_H

#include "common/shared_types.h"
#include <zorba/xqpString.h>
#include "runtime/base/narybase.h"

namespace xqp {


class FnTraceIteratorState : public PlanIteratorState {
  public:
    Item_t theTagItem;
    xqpString theTag;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTraceIterator, FnTraceIteratorState);

} /* namespace xqp */

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
