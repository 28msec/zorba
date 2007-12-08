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
  template <class IterType>
  class UnaryBaseIterator : public Batcher<IterType>
  {
    protected:
      PlanIter_t theChild;

    public:
      UnaryBaseIterator ( const yy::location& loc, PlanIter_t& arg );
      virtual ~UnaryBaseIterator();

      void resetImpl ( PlanState& planState );
      void releaseResourcesImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return sizeof ( PlanIterator::PlanIteratorState ); }
      virtual uint32_t getStateSizeOfSubtree() const;
      virtual void setOffset ( PlanState& planState, uint32_t& offset );
  }; /* class UnaryBaseIterator */

  /* begin class UnaryBaseIterator */
  template <class IterType>
  UnaryBaseIterator<IterType>::UnaryBaseIterator ( const yy::location& loc, PlanIter_t& aChild )
      :
      Batcher<IterType> ( loc ), theChild ( aChild )
  {
#ifndef NDEBUG
    assert(aChild != 0);
#endif
  }


  template <class IterType>
  UnaryBaseIterator<IterType>::~UnaryBaseIterator()
  {
  }


  template <class IterType>
  void
  UnaryBaseIterator<IterType>::resetImpl ( PlanState& planState )
  {
    PlanIterator::PlanIteratorState* state;
    GET_STATE ( PlanIterator::PlanIteratorState, state, planState );
    state->reset();
    
    this->resetChild ( theChild, planState );
  }


  template <class IterType>
  void
  UnaryBaseIterator<IterType>::releaseResourcesImpl ( PlanState& planState )
  {
    this->releaseChildResources ( theChild, planState );
  }


  template <class IterType>
  uint32_t
  UnaryBaseIterator<IterType>::getStateSizeOfSubtree() const
  {
    return theChild->getStateSizeOfSubtree() + getStateSize();
  }


  template <class IterType>
  void
  UnaryBaseIterator<IterType>::setOffset (
      PlanState& planState,
      uint32_t& offset )
  {
    this->stateOffset = offset;
    offset += getStateSize();

    theChild->setOffset ( planState, offset );
  }
  /* end class UnaryBaseIterator */
}; /* namespace xqp*/

#endif /* XQP_UNARYBASE_H */

