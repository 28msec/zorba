#include <iostream>
#include "errors/error_factory.h"
#include "runtime/debug/debug_iterators.h"

using namespace std;

namespace xqp {

FnTraceIterator::FnTraceIterator(const yy::location& loc, PlanIter_t aChild0, PlanIter_t aChild1)
  : BinaryBaseIterator<FnTraceIterator>(loc, aChild0, aChild1) { }

FnTraceIterator::~FnTraceIterator() { }

Item_t FnTraceIterator::nextImpl(PlanState& planState)
{
  Item_t lSequenceItem;

  FnTraceIteratorState *state;
  DEFAULT_STACK_INIT(FnTraceIteratorState, state, planState);

  state->theTagItem = consumeNext(theChild1, planState);
  if (state->theTagItem == NULL) {
    ZORBA_ERROR_ALERT(ZorbaError::FORG0006, &loc, false,
        "An empty sequence is not allowed as search item of fn:index-of");
  }

  while((lSequenceItem = consumeNext(theChild0, planState)) != NULL) {
    cerr << state->theTagItem->getStringProperty() << lSequenceItem->getStringProperty() << endl;
    STACK_PUSH(lSequenceItem, state);
  }

  STACK_END();
}

void FnTraceIterator::resetImpl(PlanState& planState)
{
  BinaryBaseIterator<FnTraceIterator>::resetImpl(planState);

  FnTraceIteratorState* state;
  GET_STATE(FnTraceIteratorState, state, planState);
  state->reset();
}

void FnTraceIterator::releaseResourcesImpl(PlanState& planState)
{
  BinaryBaseIterator<FnTraceIterator>::releaseResourcesImpl(planState);
  
  FnTraceIteratorState* state;
  GET_STATE(FnTraceIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}

void FnTraceIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<FnTraceIterator>::setOffset(planState, offset);
  FnTraceIteratorState* state = 
    new (planState.block + stateOffset) FnTraceIteratorState;
}

void FnTraceIterator::FnTraceIteratorState::init()
{
  PlanIterator::PlanIteratorState::init();
  theTagItem = NULL;
}

void FnTraceIterator::FnTraceIteratorState::reset()
{
  PlanIterator::PlanIteratorState::reset();
  theTagItem = NULL;
}

}
/* vim:set ts=2 sw=2: */
