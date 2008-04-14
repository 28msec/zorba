#ifndef XQP_PLAN_ITERATOR_WRAPPER_H
#define XQP_PLAN_ITERATOR_WRAPPER_H

#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba {

  class PlanState;

  /*******************************************************************************
    This is a "helper" wrapper that is used when we need to pass a plan iterator
    to the store. The wrapper wraps the plan iterator in order to provide a
    simpler interface that the store can use.

    The wrapper does not allocate a new state block, but it points to the same 
    block that contains the state of the wrapped plan iterator.
   ********************************************************************************/
  class PlanIteratorWrapper : public store::Iterator
  {
    private:
      const PlanIterator*   theIterator;
      PlanState*            theStateBlock;

    public:
      PlanIteratorWrapper(const PlanIterator* iter, PlanState& planState);

      virtual ~PlanIteratorWrapper();

      void open();
      store::Item_t next();
      void reset();
      void close() throw();
  };

} /* namespace zorba */
#endif
