/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_BINARYBASE_H
#define XQP_BINARYBASE_H

#include "runtime/base/plan_iterator.h"

namespace xqp
{
	/**
	 * Superclass for all iterators which have two child iterators 
	 * and no additional state variables.
	 */
	template <class IterType, class StateType>
	class BinaryBaseIterator : public Batcher<IterType>
	{
		protected:
			PlanIter_t theChild0;
			PlanIter_t theChild1;

		public:
			BinaryBaseIterator ( const yy::location& loc, PlanIter_t& arg0, PlanIter_t& arg1 );
			virtual ~BinaryBaseIterator();

      void openImpl( PlanState& planState, uint32_t& offset);
			void resetImpl ( PlanState& planState );
			void closeImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return StateTraitsImpl<StateType>::getStateSize(); }
			virtual uint32_t getStateSizeOfSubtree() const;
	}; /* class BinaryBaseIterator */

	/* begin class BinaryBaseIterator */
	template <class IterType, class StateType>
	BinaryBaseIterator<IterType, StateType>::BinaryBaseIterator (
	    const yy::location& loc,
	    PlanIter_t& aChild0,
	    PlanIter_t& aChild1 )
			:
			Batcher<IterType> ( loc ), theChild0 ( aChild0 ), theChild1 ( aChild1 )
	{
#ifndef NDEBUG
    assert(aChild0 != 0);
    assert(aChild1 != 0);
#endif
	}


	template <class IterType, class StateType>
	BinaryBaseIterator<IterType, StateType>::~BinaryBaseIterator()
	{
	}


  template <class IterType, class StateType>
  void
  BinaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset )
  {
    StateTraitsImpl <StateType>::createState(planState, this->stateOffset, offset);
    StateTraitsImpl<StateType>::initState(planState, this->stateOffset);

    theChild0->open(planState, offset);
    theChild1->open(planState, offset);
  }


	template <class IterType, class StateType>
	void
	BinaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState )
	{
    StateTraitsImpl<StateType>::reset(planState, this->stateOffset);

    theChild0->reset( planState );
    theChild1->reset( planState );
	}


	template <class IterType, class StateType>
	void
	BinaryBaseIterator<IterType, StateType>::closeImpl ( PlanState& planState )
	{
    theChild0->close( planState );
    theChild1->close( planState );

    StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
	}

	template <class IterType, class StateType>
	uint32_t
	BinaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
	{
		return theChild0->getStateSizeOfSubtree() + theChild1->getStateSizeOfSubtree()
		       + this->getStateSize();
	}

  /* end class BinaryBaseIterator */
} /* namespace xqp */

#endif /* XQP_BINARYBASE_H */
/* vim:set ts=2 sw=2: */
