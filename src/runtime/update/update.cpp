#include "runtime/update/update.h"

namespace zorba {

InsertIterator::InsertIterator (
  const QueryLoc& aLoc,
  store::UpdateConsts::InsertType aType,
  PlanIter_t aChild0,
  PlanIter_t aChild1)
:
  BinaryBaseIterator<InsertIterator, PlanIteratorState>(aLoc, aChild0, aChild1),
  theType(aType)
{}

store::Item_t
InsertIterator::nextImpl (PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END();
}

store::Item_t
DeleteIterator::nextImpl(PlanState& aPlanState) const
{ 
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END();
}

ReplaceIterator::ReplaceIterator (
  const QueryLoc& aLoc,
  store::UpdateConsts::ReplaceType aType,
  PlanIter_t aChild0,
  PlanIter_t aChild1)
:
  BinaryBaseIterator<ReplaceIterator, PlanIteratorState>(aLoc, aChild0, aChild1),
  theType(aType)
{}

store::Item_t
ReplaceIterator::nextImpl (PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END();
}

store::Item_t
RenameIterator::nextImpl(PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END();
}

TransformIterator::TransformIterator(
  const QueryLoc& aLoc,
  PlanIter_t aModifyIter,
  PlanIter_t aReturnIter)
:
  Batcher<TransformIterator>(aLoc),
  theModifyIter(aModifyIter),
  theReturnIter(aReturnIter)
{}

void
TransformIterator::addAssign(PlanIter_t anIter)
{
  theAssignIters.push_back(anIter); 
}

store::Item_t
TransformIterator::nextImpl(PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END();
}

void 
TransformIterator::openImpl ( PlanState& planState, uint32_t& offset ) {
  StateTraitsImpl<PlanIteratorState>::createState(planState, this->stateOffset, offset);

  std::vector<PlanIter_t>::iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->open(planState, offset );
  }
  theModifyIter->open( planState, offset );
  theReturnIter->open( planState , offset);
}

void 
TransformIterator::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->stateOffset);
  
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->reset(planState);
  }
  theModifyIter->reset( planState );
  theReturnIter->reset( planState );
}

void 
TransformIterator::closeImpl ( PlanState& planState ) const
{
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->close(planState);
  }
  theModifyIter->close( planState );
  theReturnIter->close( planState );

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, this->stateOffset);
}

uint32_t 
TransformIterator::getStateSizeOfSubtree() const {
  uint32_t lSize = getStateSize();
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lSize += (*lIter)->getStateSizeOfSubtree();
  }
  lSize += theModifyIter->getStateSizeOfSubtree();
  lSize += theReturnIter->getStateSizeOfSubtree();
  return lSize;
}
} // namespace zorba
