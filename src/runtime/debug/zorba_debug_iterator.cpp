#include "runtime/debug/zorba_debug_iterator.h"

#include "compiler/api/compilercb.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "debugger/zorba_debugger_runtime.h"
#include "debugger/zorba_debugger_commons.h"

#include "runtime/visitors/planitervisitor.h"
#include "runtime/eval/FnContextImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"


namespace zorba {

ZorbaDebugIterator::ZorbaDebugIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& aChildvector )
  : 
  NaryBaseIterator<ZorbaDebugIterator,
                   ZorbaDebugIteratorState> (sctx, loc, aChildvector),
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

  ZorbaDebugIteratorState* lState = 0;
  DEFAULT_STACK_INIT(ZorbaDebugIteratorState, lState, planState);

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
          lCommons->setDebugIteratorState(lState);

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

class DebugVarIterator : public store::Iterator {
public:
  DebugVarIterator(store::Item_t aItem)
    : theItem(aItem), theFinished(false)
  {
  }

  void open(){}
  void reset(){ theFinished = false; }
  void close(){}

  bool next(store::Item_t& result)
  {
    if (theFinished)
      return false;
    result = theItem;
    theFinished = true;
    return theFinished;
  }

private:
  store::Item_t theItem;
  bool theFinished;
};

std::list<std::pair<xqpString, xqpString> > ZorbaDebugIterator::eval(
  std::string aExpression, 
  PlanState& aPlanState, 
  ZorbaDebugIteratorState* aState) const
{
  aState->ccb.reset (new CompilerCB (*aPlanState.theCompilerCB));
  aState->ccb->m_sctx = aPlanState.theCompilerCB->m_sctx->create_child_context ();
  (*aState->ccb->m_context_map)[aState->ccb->m_cur_sctx] = aState->ccb->m_sctx; 
  checked_vector<store::Item_t>::const_iterator lIter;
  aState->dctx.reset (new dynamic_context (aPlanState.dctx ()));

  aState->eval_plan.reset ( new PlanWrapper ( 
    EvalIterator::compile (aState->ccb.get (),
    aExpression,
    varnames,
    vartypes),
    aState->ccb.get (),
    aState->dctx.get (),
    aPlanState.theStackDepth + 1));
  aState->eval_plan->checkDepth (loc);

  for (unsigned i = 0; i < theChildren.size () - 1; i++) {
    store::Iterator_t lIter = 
      new PlanIteratorWrapper (theChildren [i + 1], aPlanState);
    // TODO: is saving an open iterator efficient?
    // Then again if we close theChildren [1] here,
    // we won't be able to re-open it later via the PlanIteratorWrapper
    aState->dctx->add_variable (dynamic_context::var_key (
      aState->ccb->m_sctx->lookup_var (varnames [i])), lIter);
  }

  std::list<std::pair<xqpString, xqpString> > lResult;
  store::Item_t result;
  while (aState->eval_plan->next (result)) {
    lResult.push_back(
      std::pair<xqpString, xqpString>(xqpString(result->getStringValue().getp()),
        xqpString(result->getType()->getStringValue().getp())));
  }
  return lResult;
} 


}/* namespace zorba */
