#include "runtime/base/plan_wrapper.h"

#include "runtime/base/plan_iterator.h"

namespace zorba {

  /*******************************************************************************
    class PlanWraper
   ********************************************************************************/
  PlanWrapper::PlanWrapper(PlanIter_t& aIter)
    : theIterator(aIter)
  {
    uint32_t stackSize = theIterator->getStateSizeOfSubtree();
    theStateBlock = new PlanState(stackSize);
    theClosed = true;
  }


  PlanWrapper::~PlanWrapper()
  {
    if(!theClosed)
      close();
    delete theStateBlock; 
    theStateBlock = NULL;
    theClosed = true;
  }

  void
  PlanWrapper::open()
  {
    assert(theClosed);
    if(!theClosed)
      return;

    uint32_t offset = 0;
    theIterator->open(*theStateBlock, offset);
    theClosed = false;
  }

  Item_t
  PlanWrapper::next()
  {
    assert(!theClosed);
    if(theClosed)
      return NULL;

    return PlanIterator::consumeNext(theIterator.getp(), *theStateBlock);
  }

  void
  PlanWrapper::reset()
  {
    theIterator->reset(*theStateBlock); 
    theClosed = false;
  }

  void
  PlanWrapper::close()
  {
    assert(!theClosed);
    if(theClosed)
      return;

    theIterator->close(*theStateBlock); 
    theClosed = true;
  }

} /* namespace zorba */
