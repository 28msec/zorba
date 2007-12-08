/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_NARYBASE_H
#define XQP_NARYBASE_H

#include "runtime/base/iterator.h"
#ifndef NDEBUG
# include <cassert>
#endif

namespace xqp
{
	/**
	 * Superclass for all iterators which have n child iterators 
	 * and no additional state variables.
	 */
	template <class IterType>
	class NaryBaseIterator : public Batcher<IterType>
	{
		protected:
			std::vector<PlanIter_t> theChildren;

		public:
			NaryBaseIterator ( const yy::location& loc, std::vector<PlanIter_t>& args );
			virtual ~NaryBaseIterator();

			void resetImpl ( PlanState& planState );
			void releaseResourcesImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return sizeof ( PlanIterator::PlanIteratorState ); }
      virtual uint32_t getStateSizeOfSubtree() const;
			virtual void setOffset ( PlanState& planState, uint32_t& offset );
	}; /* class BinaryBaseIterator */

	/* begin class NaryBaseIterator */
	template <class IterType>
	NaryBaseIterator<IterType>::NaryBaseIterator (
	    const yy::location& loc,
	    std::vector<PlanIter_t>& aChildren )
			:
			Batcher<IterType> ( loc ), theChildren ( aChildren )
	{
#ifndef NDEBUG
    std::vector<PlanIter_t>::const_iterator lEnd = aChildren.end();
    for(
        std::vector<PlanIter_t>::const_iterator lIter = aChildren.begin();
        lIter != lEnd;
        ++lIter)
    {
      assert(*lIter != 0);
    }
#endif
	}


	template <class IterType>
	NaryBaseIterator<IterType>::~NaryBaseIterator()
	{
	}


	template <class IterType>
	void
	NaryBaseIterator<IterType>::resetImpl ( PlanState& planState )
	{
		PlanIterator::PlanIteratorState* state;
		GET_STATE ( PlanIterator::PlanIteratorState, state, planState );
		state->reset();

		std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
		for ( 
         std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
         lIter!= theChildren.end(); 
         ++lIter )
		{
			this->resetChild ( *lIter, planState );
		}
	}


	template <class IterType>
	void
	NaryBaseIterator<IterType>::releaseResourcesImpl ( PlanState& planState )
	{
    std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
    for ( 
         std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
          lIter!= theChildren.end(); 
          ++lIter )
    {
			this->releaseChildResources ( *lIter, planState );
		}
	}


	template <class IterType>
	uint32_t
	NaryBaseIterator<IterType>::getStateSizeOfSubtree() const
	{
		uint32_t size = 0;

    std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
    for ( 
         std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
          lIter!= theChildren.end(); 
          ++lIter )
    {
			size += ( *lIter )->getStateSizeOfSubtree();
		}

		return this->getStateSize() + size;
	}


	template <class IterType>
	void
	NaryBaseIterator<IterType>::setOffset (
	    PlanState& planState,
	    uint32_t& offset )
	{
		this->stateOffset = offset;
		offset += this->getStateSize();

    std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
    for ( 
         std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
          lIter!= theChildren.end(); 
          ++lIter )
    {
			( *lIter )->setOffset ( planState, offset );
		}
	}
	/* end class NaryBaseIterator */
} /* namespace xqp */

#endif /* XQP_NARYBASE_H */
