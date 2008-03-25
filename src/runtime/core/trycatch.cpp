#include "runtime/core/trycatch.h"

#include "errors/errors.h"
#include "util/Assert.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planitervisitor.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"
#include "system/globalenv.h"
#include "types/node_test.h"

namespace zorba {
  
TryCatchIteratorState::TryCatchIteratorState()
  : theTempIterator(NULL),
  theCatchIterator(NULL)
{}

TryCatchIteratorState::~TryCatchIteratorState()
{
  if (theTempIterator != NULL) {
    theTempIterator->close();
    theTempIterator = NULL;
  }
}

void
TryCatchIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void
TryCatchIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  if ( theTargetSequence )
    theTargetSequence->purge(); // release the target sequence
  if (theTempIterator != NULL) {
    theTempIterator->close();
    theTempIterator = NULL;
  }
  theCatchIterator = NULL;
}

TryCatchIterator::TryCatchIterator(const QueryLoc& loc, PlanIter_t& aBlock, std::vector<CatchClause>& aCatchClauses)
  : UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> (loc, aBlock),
    theCatchClauses(aCatchClauses)
{ }

TryCatchIterator::~TryCatchIterator() {}

void
TryCatchIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<TryCatchIteratorState>::createState(planState,
                                                      this->stateOffset,
                                                      offset);

  StateTraitsImpl<TryCatchIteratorState>::initState(planState, this->stateOffset);
  
  theChild->open(planState, offset);

  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->open(planState, offset);
  } 

}

uint32_t
TryCatchIterator::getStateSizeOfSubtree() const
{
	uint32_t size = theChild->getStateSizeOfSubtree() + getStateSize();

  std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin(); 
  std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for (; lIter!= lEnd; ++lIter )
  {
		size += ( *lIter ).catch_expr->getStateSizeOfSubtree();
	}

  return size; 
}

store::Item_t
TryCatchIterator::nextImpl(PlanState& planState) const 
{

  store::Item_t item; // each item that will be returned 
  
  Iterator_t lIterator;
  
  TryCatchIteratorState* state;
  DEFAULT_STACK_INIT(TryCatchIteratorState, state, planState);
  
  try { 
    lIterator = new PlanIteratorWrapper ( theChild, planState );
    lIterator->open();
    state->theTargetSequence = GENV_STORE.createTempSeq( lIterator, false );
    state->theTempIterator = state->theTargetSequence->getIterator();
    state->theTempIterator->open();
  } catch (error::ZorbaError& e) {
    bool catchMatched = false;
    std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin(); 
    std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
    for (; lIter!= lEnd; ++lIter )
    {
      const CatchClause& cc = *lIter;
      const NodeNameTest& nt = *cc.node_name;
      if (nt.matches(&*e.theQName)) {
        state->theCatchIterator = cc.catch_expr;
        catchMatched = true;
        break;
      }
    }

    if (!catchMatched) {
      lIterator->close();
      throw e;
    }
  }
  lIterator->close();

  if (state->theTempIterator != NULL) {
    ZORBA_ASSERT(state->theCatchIterator == NULL);
    while (true) {
      item = state->theTempIterator->next();
      if ( item == NULL )
        break;
      STACK_PUSH( item, state );
    } 
  } else if (state->theCatchIterator != NULL) {
    ZORBA_ASSERT(state->theTempIterator == NULL);
    while((item = consumeNext(state->theCatchIterator.getp(), planState)) != NULL) {
      STACK_PUSH(item, state);
    }
  } else {
    ZORBA_ASSERT(false);
  }
 
  STACK_END (state);
}

void 
TryCatchIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<TryCatchIteratorState>::reset(planState, this->stateOffset);

  theChild->reset(planState);
  
  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->reset(planState);
  } 

}

void 
TryCatchIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);
  
  std::vector<TryCatchIterator::CatchClause>::iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->close(planState);
  } 

  StateTraitsImpl<TryCatchIteratorState>::destroyState(planState, this->stateOffset);
}

void TryCatchIterator::accept(PlanIterVisitor &v) const {
  v.beginVisit(*this);
  theChild->accept ( v );
  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->accept ( v );
  } 
  v.endVisit(*this);
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
