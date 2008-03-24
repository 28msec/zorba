#include "runtime/api/plan_iterator_wrapper.h"

#include "runtime/base/plan_iterator.h"

namespace zorba {
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

  store::Item_t
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
  PlanIteratorWrapper::close() throw()
  {
  }

} /* namespace zorba */
