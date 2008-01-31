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
	template <class IterType, class StateType>
	class NaryBaseIterator : public Batcher<IterType>
	{
		protected:
			std::vector<PlanIter_t> theChildren;

		public:
			NaryBaseIterator ( const yy::location& loc, std::vector<PlanIter_t>& args );
			virtual ~NaryBaseIterator();

      void openImpl ( PlanState& planState, uint32_t& offset );
			void resetImpl ( PlanState& planState );
			void closeImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return sizeof ( StateType ); }
      virtual uint32_t getStateSizeOfSubtree() const;
	}; /* class BinaryBaseIterator */

	/* begin class NaryBaseIterator */
	template <class IterType, class StateType>
	NaryBaseIterator<IterType, StateType>::NaryBaseIterator (
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


	template <class IterType, class StateType>
	NaryBaseIterator<IterType, StateType>::~NaryBaseIterator()
	{
	}


  template <class IterType, class StateType>
  void
  NaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset )
  {
    this->stateOffset = offset;
    offset += getStateSize();

    // construct the state
    StateType* state = new (planState.theBlock + this->stateOffset) StateType;

    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
		std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
		for ( ; lIter!= theChildren.end(); ++lIter )
		{
      ( *lIter )->open( planState, offset );
		}

  }

	template <class IterType, class StateType>
	void
	NaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState )
	{
		StateType* state;
		GET_STATE ( StateType, state, planState );
		state->reset(planState);

    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
		std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
		for ( ; lIter!= theChildren.end(); ++lIter )
		{
      ( *lIter )->reset( planState );
		}
	}


	template <class IterType, class StateType>
	void
	NaryBaseIterator<IterType, StateType>::closeImpl ( PlanState& planState )
	{
    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
    for ( ; lIter!= theChildren.end(); ++lIter )
    {
      ( *lIter )->close( planState );
		}

    StateType* state;
    GET_STATE ( StateType, state, planState );
    state->~StateType();
	}


	template <class IterType, class StateType>
	uint32_t
	NaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
	{
		uint32_t size = 0;

    std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
    for (; lIter!= theChildren.end(); ++lIter )
    {
			size += ( *lIter )->getStateSizeOfSubtree();
		}

		return this->getStateSize() + size;
	}


	/* end class NaryBaseIterator */
} /* namespace xqp */

#endif /* XQP_NARYBASE_H */
