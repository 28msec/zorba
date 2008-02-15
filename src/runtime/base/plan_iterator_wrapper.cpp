#include "runtime/base/plan_iterator_wrapper.h"

#include "runtime/base/plan_iterator.h"

namespace xqp {
  /*******************************************************************************
    class PlanIteratorWrapper
   ********************************************************************************/
  PlanIteratorWrapper::PlanIteratorWrapper(const PlanIterator* iter, PlanState& state) 
    : theIterator(iter),
    theStateBlock(&state)
  {
  }


  PlanIteratorWrapper::~PlanIteratorWrapper()
  {
  }

  void
  PlanIteratorWrapper::open()
  {
  }

  Item_t
  PlanIteratorWrapper::next()
  {
    return PlanIterator::consumeNext(theIterator, *theStateBlock);
  }

  void
  PlanIteratorWrapper::reset()
  {
    theIterator->reset(*theStateBlock);
  }


  void
  PlanIteratorWrapper::close()
  {
  }

} /* namespace xqp */
