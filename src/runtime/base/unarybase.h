/**
 * Copyright 2007 FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_UNARYBASE_H
#define XQP_UNARYBASE_H

#include "runtime/base/iterator.h"

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
			Iterator_t theChild;

		public:
			UnaryBaseIterator ( const yy::location& loc, Iterator_t& arg );
			virtual ~UnaryBaseIterator();

			void resetImpl ( PlanState& planState );
			void releaseResourcesImpl ( PlanState& planState );

			virtual int32_t getStateSize();
			virtual int32_t getStateSizeOfSubtree();
			virtual void setOffset ( PlanState& planState, int32_t& offset );

			std::ostream& _show ( std::ostream& os ) const;
	}; /* class UnaryBaseIterator */

	/* begin class UnaryBaseIterator */
	template <class IterType>
	UnaryBaseIterator<IterType>::UnaryBaseIterator ( const yy::location& loc, Iterator_t& arg )
			:
			Batcher<IterType> ( loc ), theChild ( arg )
	{
	}


	template <class IterType>
	UnaryBaseIterator<IterType>::~UnaryBaseIterator()
	{
	}


	template <class IterType>
	void
	UnaryBaseIterator<IterType>::resetImpl ( PlanState& planState )
	{
		this->resetChild ( theChild, planState );

		PlanIterator::PlanIteratorState* state;
		GET_STATE ( PlanIterator::PlanIteratorState, state, planState );
		state->reset();
	}


	template <class IterType>
	void
	UnaryBaseIterator<IterType>::releaseResourcesImpl ( PlanState& planState )
	{
		this->releaseChildResources ( theChild, planState );
	}


	template <class IterType>
	int32_t
	UnaryBaseIterator<IterType>::getStateSize()
	{
		return sizeof ( PlanIterator::PlanIteratorState );
	}


	template <class IterType>
	int32_t
	UnaryBaseIterator<IterType>::getStateSizeOfSubtree()
	{
		return theChild->getStateSizeOfSubtree() + getStateSize();
	}


	template <class IterType>
	void
	UnaryBaseIterator<IterType>::setOffset (
	    PlanState& planState,
	    int32_t& offset )
	{
		this->stateOffset = offset;
		offset += getStateSize();

		theChild->setOffset ( planState, offset );
	}


	template <class IterType>
	std::ostream&
	UnaryBaseIterator<IterType>::_show ( std::ostream& os ) const
	{
		theChild->show ( os );
		return os;
	}
	/* end class UnaryBaseIterator */
}; /* namespace xqp*/

#endif /* XQP_UNARYBASE_H */

