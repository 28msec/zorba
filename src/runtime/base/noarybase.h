/**
 * Copyright 2007 FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_NOARYBASE_H
#define XQP_NOARYBASE_H

#include "runtime/base/iterator.h"

namespace xqp
{
/**
 * Superclass for all iterators which have no child iterators
 * and no additional state variables.
 */
template <class IterType>
class NoaryBaseIterator : public Batcher<IterType>
{
public:
  NoaryBaseIterator ( const yy::location& loc );
  virtual ~NoaryBaseIterator();

  void resetImpl ( PlanState& planState );
  void releaseResourcesImpl ( PlanState& planState );

  virtual uint32_t getStateSize() const { return sizeof(PlanIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const { return getStateSize(); }
  virtual void setOffset(PlanState& planState, uint32_t& offset);
};


template <class IterType>
NoaryBaseIterator<IterType>::NoaryBaseIterator ( const yy::location& loc )
  :
  Batcher<IterType> ( loc )
{
}


template <class IterType>
NoaryBaseIterator<IterType>::~NoaryBaseIterator()
{
}


template <class IterType>
void
NoaryBaseIterator<IterType>::resetImpl ( PlanState& planState )
{
  PlanIteratorState* state;
  GET_STATE(PlanIteratorState, state, planState);
  state->reset();
}


template <class IterType>
void
NoaryBaseIterator<IterType>::releaseResourcesImpl(PlanState& planState)
{
  PlanIteratorState* state;
  GET_STATE(PlanIteratorState, state, planState);
  state->releaseResources();
}


template <class IterType>
void
NoaryBaseIterator<IterType>::setOffset (
    PlanState& planState,
    uint32_t& offset )
{
  this->stateOffset = offset;
  offset += getStateSize();
}


}; /* namespace xqp*/

#endif /* XQP_NOARYBASE_H */

