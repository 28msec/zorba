#ifndef ZORBA_DEBUG_ITERATORS_H
#define ZORBA_DEBUG_ITERATORS_H

#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {


class FnTraceIteratorState : public PlanIteratorState {
  public:
    store::Item_t theTagItem;
    xqpString theTag;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTraceIterator, FnTraceIteratorState);

} /* namespace zorba */

#endif /* ZORBA_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
