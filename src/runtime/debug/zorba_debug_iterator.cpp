#include "zorba_debug_iterator.h"

#include "context/static_context.h"
#include "debugger/zorba_debugger_runtime.h"
#include "debugger/zorba_debugger_commons.h"

using namespace zorba;

zorba::ZorbaDebugIterator::ZorbaDebugIterator( short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildvector )
:
NaryBaseIterator<ZorbaDebugIterator, PlanIteratorState>(sctx, loc, aChildvector)
{
}

bool zorba::ZorbaDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
{
  PlanIteratorState* lState;
  try {
    DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);
    while (consumeNext(result, theChildren[0], planState)) {
      if (planState.theDebuggerCommons->hasToBreakAt(loc)) {
        try {
          planState.theDebuggerCommons->setCurrentStaticContext(getStaticContext(planState));
          planState.theDebuggerCommons->setCurrentDynamicContext(planState.dctx());
          planState.theDebuggerCommons->getRuntime()->suspendRuntime(loc, CAUSE_BREAKPOINT);
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
  theDebuggerChildren.push_back(child);
}

void zorba::ZorbaDebugIterator::setParent( ZorbaDebugIterator* parent )
{
  theDebuggerParent = parent;
}

zorba::QueryLoc zorba::ZorbaDebugIterator::getQueryLocation() const
{
  return loc;
}
