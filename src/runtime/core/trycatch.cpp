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
  : theIterator(NULL)
{}

TryCatchIteratorState::~TryCatchIteratorState() {}

void
TryCatchIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void
TryCatchIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  if ( theTargetSequence )
    theTargetSequence->purge(); // release the target sequence
  theIterator = NULL;
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

  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin(); 
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();
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
  
  // remember whether an error occured during the evaluatuion of the try body
  bool lErrorOccured = false; 
  
  TryCatchIteratorState* state;
  DEFAULT_STACK_INIT(TryCatchIteratorState, state, planState);
  
  try {
    Iterator_t lIterator = new PlanIteratorWrapper ( theChild, planState );
    lIterator->open();
    // eagerly materialize the whole stuff
    state->theTargetSequence = GENV_STORE.createTempSeq( lIterator, false );
    lIterator->close();
  } catch (error::ZorbaError& e) {
    lErrorOccured = true;

    ZORBA_ASSERT( e.isDynamicError() || e.isUserError() || e.isTypeError() );
  }

  if (lErrorOccured) {
    while ( (item = consumeNext(theCatchClauses[0].catch_expr.getp(), planState)) != NULL ) {
      STACK_PUSH( item, state );
    }
  } else {

    // now that no error occured, let's return the result
    state->theIterator = state->theTargetSequence->getIterator(); 
    state->theIterator->open();
    
    while (true) {
      item = state->theIterator->next();
      if ( item == NULL )
        break;
      STACK_PUSH( item, state );
    } 

    state->theIterator->close();
  }
  
  STACK_END();
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
