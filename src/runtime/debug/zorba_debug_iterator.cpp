#include "zorba_debug_iterator.h"

#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "debugger/zorba_debugger_runtime.h"
#include "debugger/zorba_debugger_commons.h"

#include "runtime/fncontext/FnContextImpl.h"

namespace zorba {

ZorbaDebugIterator::ZorbaDebugIterator( short sctx,
                                        const QueryLoc& loc,
                                        std::vector<PlanIter_t>& aChildvector )
  : NaryBaseIterator<ZorbaDebugIterator,
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
  checked_vector<store::Item_t>::const_iterator lIter;
  store::Iterator_t lVarIter;
  store::Item_t     lVarItem;

  ZorbaDebugIteratorState* lState = 0;
  DEFAULT_STACK_INIT(ZorbaDebugIteratorState, lState, planState);

  while (consumeNext(result, theChildren[0], planState)) {

    // check whether we have to suspend 
    // (determined by location, iterator, or some other cause)
    if (lCommons->hasToBreakAt(loc) || lCommons->hasToBreakAt(this) ||
        lCommons->hasToBreak(&lCause)) {
        try {
          lCause = lCause == 0 ? CAUSE_BREAKPOINT : lCause;

#if 0
          lState->ccb.reset (new CompilerCB (*planState.theCompilerCB));
          lState->ccb->m_sctx = planState.theCompilerCB->m_sctx->create_child_context ();
          (*lState->ccb->m_context_map)[lState->ccb->m_cur_sctx] = lState->ccb->m_sctx; 

          lState->dctx.reset (new dynamic_context (planState.dctx ()));
          
          lState->eval_plan.reset ( new PlanWrapper ( 
                                      EvalIterator::compile (lState->ccb.get (),
                                                             "$param",
                                                             varnames,
                                                             vartypes),
                                                   lState->ccb.get (),
                                                   lState->dctx.get (),
                                                   planState.theStackDepth + 1));
          lState->eval_plan->checkDepth (loc);

          for (lIter = varnames.begin(); lIter != varnames.end(); ++lIter) {
            planState.dctx()->get_variable(*lIter, lVarItem, lVarIter);
            lState->dctx->add_variable(dynamic_context::var_key(lState->ccb->m_sctx->lookup_var(*lIter)), lVarIter);
          }

          while (lState->eval_plan->next (result)) {
            std::cout << "blub " << result->getStringValue() << std::endl;
          }
#endif

          
          // tell everybody that we are the iterator who suspended
          lCommons->setCurrentIterator(this);
          lCommons->setCurrentStaticContext(getStaticContext(planState));
          lCommons->setCurrentDynamicContext(planState.dctx());
          lCommons->setBreak(false);

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

void ZorbaDebugIterator::accept( PlanIterVisitor& v ) const
{
  v.beginVisit(*this);
  std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
  for ( ; iter != lEnd; ++iter ) {
    ( *iter )->accept ( v );
  }
  v.endVisit(*this);
}

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

} /* namespace zorba */
