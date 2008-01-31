/**
 * Copyright 2007 FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_UNARYBASE_H
#define XQP_UNARYBASE_H

#include "runtime/base/iterator.h"
#ifndef NDEBUG
# include <cassert>
#endif

namespace xqp
{

/**
 * Superclass for all iterators which have one child iterator
 * and no additional state variables.
 */
template <class IterType, class StateType>
class UnaryBaseIterator : public Batcher<IterType>
{
protected:
  PlanIter_t theChild;

public:
  UnaryBaseIterator ( const yy::location& loc, PlanIter_t& arg );
  virtual ~UnaryBaseIterator();

  void openImpl ( PlanState& planState, uint32_t& offset );
  void resetImpl ( PlanState& planState );
  void closeImpl ( PlanState& planState );

  virtual uint32_t getStateSize() const { return sizeof(StateType); }
  virtual uint32_t getStateSizeOfSubtree() const;
};


template <class IterType, class StateType>
UnaryBaseIterator<IterType, StateType>::UnaryBaseIterator(
    const yy::location& loc,
    PlanIter_t& aChild)
  :
  Batcher<IterType> ( loc ), theChild ( aChild )
{
#ifndef NDEBUG
  assert(aChild != 0);
#endif
}


template <class IterType, class StateType>
UnaryBaseIterator<IterType, StateType>::~UnaryBaseIterator()
{
}

template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset )
{
  this->stateOffset = offset;
  offset += getStateSize();
    
  // construct the state
  StateType* state = new (planState.theBlock + this->stateOffset) StateType;

  theChild->open(planState, offset);
}

template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState )
{
  StateType* state;
  GET_STATE ( StateType, state, planState );
  state->reset(planState);
    
  theChild->reset( planState ); 
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::closeImpl( PlanState& planState )
{
  theChild->close( planState );

  StateType* state;
  GET_STATE ( StateType, state, planState );
  state->~StateType();
}

template <class IterType, class StateType>
uint32_t
UnaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
{
  return theChild->getStateSizeOfSubtree() + getStateSize();
}



}; /* namespace xqp*/

#endif /* XQP_UNARYBASE_H */

