/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_BINARYBASE_H
#define XQP_BINARYBASE_H

#include "runtime/base/iterator.h"

namespace xqp
{
	/**
	 * Superclass for all iterators which have two child iterators 
	 * and no additional state variables.
	 */
	template <class IterType>
	class BinaryBaseIterator : public Batcher<IterType>
	{
		protected:
			PlanIter_t theChild0;
			PlanIter_t theChild1;

		public:
			BinaryBaseIterator ( const yy::location& loc, PlanIter_t& arg0, PlanIter_t& arg1 );
			virtual ~BinaryBaseIterator();

			void resetImpl ( PlanState& planState );
			void releaseResourcesImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return sizeof ( PlanIterator::PlanIteratorState ); }
			virtual uint32_t getStateSizeOfSubtree() const;
			virtual void setOffset ( PlanState& planState, uint32_t& offset );
	}; /* class BinaryBaseIterator */

	/* begin class BinaryBaseIterator */
	template <class IterType>
	BinaryBaseIterator<IterType>::BinaryBaseIterator (
	    const yy::location& loc,
	    PlanIter_t& arg0,
	    PlanIter_t& arg1 )
			:
			Batcher<IterType> ( loc ), theChild0 ( arg0 ), theChild1 ( arg1 )
	{
	}


	template <class IterType>
	BinaryBaseIterator<IterType>::~BinaryBaseIterator()
	{
	}


	template <class IterType>
	void
	BinaryBaseIterator<IterType>::resetImpl ( PlanState& planState )
	{
		PlanIterator::PlanIteratorState* state;
		GET_STATE ( PlanIterator::PlanIteratorState, state, planState );
		state->reset();

		this->resetChild ( theChild0, planState );
		this->resetChild ( theChild1, planState );
	}


	template <class IterType>
	void
	BinaryBaseIterator<IterType>::releaseResourcesImpl ( PlanState& planState )
	{
		this->releaseChildResources ( theChild0, planState );
		this->releaseChildResources ( theChild1, planState );
	}

	template <class IterType>
	uint32_t
	BinaryBaseIterator<IterType>::getStateSizeOfSubtree() const
	{
		return theChild0->getStateSizeOfSubtree()
		       + theChild1->getStateSizeOfSubtree()
		       + this->getStateSize();
	}


	template <class IterType>
	void
	BinaryBaseIterator<IterType>::setOffset (
	    PlanState& planState,
	    uint32_t& offset )
	{
		this->stateOffset = offset;
		offset += this->getStateSize();

		theChild0->setOffset ( planState, offset );
		theChild1->setOffset ( planState, offset );
	}
  /* end class BinaryBaseIterator */
} /* namespace xqp */

#endif /* XQP_BINARYBASE_H */
