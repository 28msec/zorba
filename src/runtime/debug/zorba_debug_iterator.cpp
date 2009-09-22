#include "runtime/debug/zorba_debug_iterator.h"

#include "types/typeimpl.h"

#include "compiler/api/compilercb.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "debugger/zorba_debugger_runtime.h"
#include "debugger/zorba_debugger_commons.h"

#include "runtime/visitors/planitervisitor.h"
#include "runtime/eval/FnContextImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "api/serialization/serializer.h"
#include "api/xqueryimpl.h"


namespace zorba {

ZorbaDebugIterator::ZorbaDebugIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& aChildvector )
  : 
  NaryBaseIterator<ZorbaDebugIterator,
                   PlanIteratorState> (sctx, loc, aChildvector),
  theDebuggerParent(0)
{
}

// the debug iterator needs to know all variables, their keys
// and types. this is required for the eval command
// this function is called by the plan_visitor
void
ZorbaDebugIterator::setVariables(checked_vector<store::Item_t>& aVarNames,
                                 checked_vector<std::string>&   aVarKeys,
                                 checked_vector<xqtref_t>&      aVarTypes)
{
  varnames = aVarNames;
  var_keys = aVarKeys;
  vartypes = aVarTypes;
}

bool
zorba::ZorbaDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
{
  SuspensionCause lCause          = 0;
  ZorbaDebuggerCommons* lCommons  = planState.theDebuggerCommons;

  PlanWrapper_t   lWrapper = 0;

  PlanIteratorState* lState = 0;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  while (consumeNext(result, theChildren[0], planState)) {

    // check whether we have to suspend 
    // (determined by location, iterator, or some other cause)
    if (lCommons->hasToBreakAt(loc) || lCommons->hasToBreakAt(this) ||
        lCommons->hasToBreak(&lCause)) {
        try {
          lCause = lCause == 0 ? CAUSE_BREAKPOINT : lCause;
          
          // tell everybody that we are the iterator who suspended
          lCommons->setCurrentIterator(this);
          lCommons->setCurrentStaticContext(getStaticContext(planState));
          lCommons->setCurrentDynamicContext(planState.dctx());
          lCommons->setBreak(false);
          lCommons->setPlanState(&planState);

          // suspend
          lCommons->getRuntime()->suspendRuntime(loc, lCause);
          lCause = 0;
        } catch (...) {
          throw;
        }
    }
    // this iterator is the identity
    STACK_PUSH(true, lState);
  }
  STACK_END(lState);
}


NARY_ACCEPT(ZorbaDebugIterator);


bool ZorbaDebugIterator::isUpdating() const
{
  return true;
}


void ZorbaDebugIterator::setChildren( std::vector<PlanIter_t>& args )
{
  theChildren = args;
}

void ZorbaDebugIterator::addChild( ZorbaDebugIterator* child )
{
  //Preconditions
  ZORBA_ASSERT(child != NULL);

  theDebuggerChildren.push_back(child);

  //Postconditions
  ZORBA_ASSERT(theDebuggerChildren.back() == child);
}

void ZorbaDebugIterator::setParent( ZorbaDebugIterator* parent )
{
  theDebuggerParent = parent;

  //Postconditions
  ZORBA_ASSERT(getParent() == parent);
}

QueryLoc ZorbaDebugIterator::getQueryLocation() const
{
  return loc;
}

const ZorbaDebugIterator* ZorbaDebugIterator::getParent() const
{
  return theDebuggerParent;
}

const ZorbaDebugIterator* ZorbaDebugIterator::getOverIterator() const
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

std::list<std::pair<xqpString, xqpString> > ZorbaDebugIterator::eval(
  PlanState& aPlanState, const Zorba_SerializerOptions_t* aSerOptions) const
{
  theChildren[1]->reset(aPlanState);
  std::list<std::pair<xqpString, xqpString> > lResult;
  store::Item_t lRes;
  serializer ser(NULL);
  XQueryImpl::setSerializationParameters(&ser, aSerOptions);
  while (consumeNext(lRes, theChildren[1], aPlanState)) {
    std::stringstream lResStream;
    ser.serialize(lRes, lResStream);
    lResult.push_back(
      std::pair<xqpString, xqpString>(lResStream.str(),
      xqpString(lRes->getType()->getStringValue().getp())));
  }
  return lResult;
}

}/* namespace zorba */
