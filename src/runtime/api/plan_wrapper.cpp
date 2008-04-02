#include "runtime/api/plan_wrapper.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/api/runtimecb.h"
#include "context/static_context.h"

namespace zorba {

  /*******************************************************************************
    class PlanWraper
   ********************************************************************************/
  PlanWrapper::PlanWrapper(const PlanIter_t& aIter, CompilerCB* aCompilerCB, 
                           dynamic_context* aDynamicContext)
    : theIterator(aIter)
#ifndef NDEBUG
      , theIsOpened(false)
#endif
  {
    assert (aCompilerCB);

    uint32_t lStateSize = theIterator->getStateSizeOfSubtree();
    theStateBlock = new PlanState(lStateSize);

    // set the compiler cb in the state
    theStateBlock->theCompilerCB = aCompilerCB;

    // for the moment, let's keep the runtime cb here
    theStateBlock->theRuntimeCB = new RuntimeCB();
    theStateBlock->theRuntimeCB->theDynamicContext = aDynamicContext;

    // puh, we want to have the static context everywhere and not always pass both
    // control blocks in all functions
    theStateBlock->theRuntimeCB->theStaticContext = aCompilerCB->m_sctx;
    theStateBlock->theRuntimeCB->theCollationCache = aCompilerCB->m_sctx->get_collation_cache();
  }


  PlanWrapper::~PlanWrapper()
  {
#ifndef NDEBUG
    assert(!theIsOpened);
#endif

    theStateBlock->theRuntimeCB->theStaticContext->release_collation_cache(theStateBlock->theRuntimeCB->theCollationCache);

    // we created it
    delete theStateBlock->theRuntimeCB; 

    delete theStateBlock; theStateBlock = NULL;
  }

  void
  PlanWrapper::open()
  {
#ifndef NDEBUG
    assert(!theIsOpened);
#endif
    uint32_t offset = 0;
    theIterator->open(*theStateBlock, offset);

#ifndef NDEBUG
    theIsOpened = true;
#endif
  }

  store::Item_t
  PlanWrapper::next()
  {
#ifndef NDEBUG
    assert(theIsOpened);
#endif

    return PlanIterator::consumeNext(theIterator.getp(), *theStateBlock);
  }

  void
  PlanWrapper::reset()
  {
#ifndef NDEBUG
    assert(theIsOpened);
#endif
    theIterator->reset(*theStateBlock); 
  }

  void
  PlanWrapper::close() throw ()
  {
    theIterator->close(*theStateBlock); 

#ifndef NDEBUG
    theIsOpened = false;
#endif
  }

} /* namespace zorba */
