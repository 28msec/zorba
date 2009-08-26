#include "zorba_debug_iterator.h"

#include "context/static_context.h"
#include "debugger/zorba_debugger_runtime.h"
#include "debugger/zorba_debugger_commons.h"

using namespace zorba;

zorba::ZorbaDebugIterator::ZorbaDebugIterator( short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildvector )
:
NaryBaseIterator<ZorbaDebugIterator, PlanIteratorState>(sctx, loc, aChildvector), theDebuggerParent(0)
{
}

bool zorba::ZorbaDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
{
  SuspensionCause lCause = 0;
  PlanIteratorState* lState;
  ZorbaDebuggerCommons* lCommons;
  try {
    DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);
    while (consumeNext(result, theChildren[0], planState)) {
      lCommons = planState.theDebuggerCommons;
      if (lCommons->hasToBreakAt(loc) ||
        lCommons->hasToBreakAt(this) ||
        lCommons->hasToBrak(&lCause)) {
          try {
            lCause = lCause == 0 ? CAUSE_BREAKPOINT : lCause;
            lCommons->setCurrentIterator(this);
            lCommons->setCurrentStaticContext(getStaticContext(planState));
            lCommons->setCurrentDynamicContext(planState.dctx());
            lCommons->setBreak(false);
            lCommons->getRuntime()->suspendRuntime(loc, lCause);
            lCause = 0;
          } catch (...) {
            throw;
          }
      }
      STACK_PUSH(true, lState);
    }
    STACK_END(lState);
  } catch (error::ZorbaError& e) {
    throw e;
  }
  return false;
}

void zorba::ZorbaDebugIterator::accept( PlanIterVisitor& v ) const
{
  v.beginVisit(*this);
  std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
  for ( ; iter != lEnd; ++iter ) {
    ( *iter )->accept ( v );
  }
  v.endVisit(*this);
}

void zorba::ZorbaDebugIterator::openImpl( PlanState& planState, uint32_t& offset )
{
  NaryBaseIterator<ZorbaDebugIterator, PlanIteratorState>::openImpl(planState, offset);
}

bool zorba::ZorbaDebugIterator::isUpdating() const
{
  return true;
}

void zorba::ZorbaDebugIterator::setChildren( std::vector<PlanIter_t>& args )
{
  theChildren = args;
}

void zorba::ZorbaDebugIterator::addChild( ZorbaDebugIterator* child )
{
  //Preconditions
  ZORBA_ASSERT(child != NULL);

  theDebuggerChildren.push_back(child);

  //Postconditions
  ZORBA_ASSERT(theDebuggerChildren.back() == child);
}

void zorba::ZorbaDebugIterator::setParent( ZorbaDebugIterator* parent )
{
  theDebuggerParent = parent;

  //Postconditions
  ZORBA_ASSERT(getParent() == parent);
}

zorba::QueryLoc zorba::ZorbaDebugIterator::getQueryLocation() const
{
  return loc;
}

const ZorbaDebugIterator* zorba::ZorbaDebugIterator::getParent() const
{
  return theDebuggerParent;
}

const ZorbaDebugIterator* zorba::ZorbaDebugIterator::getOverIterator() const
{
  if (theDebuggerParent == NULL) {
    return NULL;
  }
  if (theDebuggerParent->theDebuggerChildren.back() == this) {
    return NULL;
  }
  std::vector<ZorbaDebugIterator*>::const_iterator lIter;
  const std::vector<ZorbaDebugIterator*> lSilblings =
    theDebuggerParent->theDebuggerParent->theDebuggerChildren;
  for (lIter = lSilblings.begin(); lIter != lSilblings.end(); lIter++) {
    if (*lIter == this) {
      ++lIter;
      return *lIter;
    }
  }

  //Should be never reached.
  ZORBA_ASSERT(false);
  return NULL;
}
