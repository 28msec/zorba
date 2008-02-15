/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_NARY_ITERATOR
#define XQP_NARY_ITERATOR

#include "runtime/base/plan_iterator.h"
#include "runtime/visitors/planitervisitor.h"

namespace xqp
{
	/**
	 * Superclass for all iterators which have n child iterators 
	 * and no additional state variables.
	 */
	template <class IterType, class StateType = PlanIteratorState>
	class NaryBaseIterator : public Batcher<IterType>
	{
		protected:
			std::vector<PlanIter_t> theChildren;

		public:
			NaryBaseIterator ( const yy::location& loc, std::vector<PlanIter_t>& args );
			virtual ~NaryBaseIterator(){}

      void openImpl ( PlanState& planState, uint32_t& offset );
			void resetImpl ( PlanState& planState ) const;
			void closeImpl ( PlanState& planState );

      virtual uint32_t getStateSize() const { return StateTraitsImpl<StateType>::getStateSize(); } 
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
  void
  NaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset ) 
  {
    StateTraitsImpl<StateType>::createState(planState, this->stateOffset, offset);
    StateTraitsImpl<StateType>::initState(planState, this->stateOffset);

    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
		std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
		for ( ; lIter!= lEnd; ++lIter )
		{
      ( *lIter )->open( planState, offset );
		}

  }

	template <class IterType, class StateType>
	void
	NaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState ) const
	{
    StateTraitsImpl<StateType>::reset(planState, this->stateOffset);

    std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
		std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
		for ( ; lIter!= lEnd; ++lIter )
		{
      ( *lIter )->reset( planState );
		}
	}


	template <class IterType, class StateType>
	void
	NaryBaseIterator<IterType, StateType>::closeImpl ( PlanState& planState )
	{
    std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
    for ( ; lIter!= lEnd; ++lIter )
    {
      ( *lIter )->close( planState );
		}

    StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
	}


	template <class IterType, class StateType>
	uint32_t
	NaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
	{
		uint32_t size = 0;

    std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
    for (; lIter!= lEnd; ++lIter )
    {
			size += ( *lIter )->getStateSizeOfSubtree();
		}

		return this->getStateSize() + size;
	}
	/* end class NaryBaseIterator */

#define NARY_ITER_STATE(iterName, stateName) class iterName \
  : public NaryBaseIterator<iterName, stateName > {\
public:\
  iterName(const yy::location& loc, std::vector<PlanIter_t>& aChildren) :\
    NaryBaseIterator<iterName, stateName >(loc, aChildren) \
  { } \
  virtual ~iterName() { } \
  \
  Item_t nextImpl(PlanState& aPlanState) const; \
  \
  virtual void accept(PlanIterVisitor& v) const \
  {  \
    v.beginVisit(*this); \
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin(); \
    std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end(); \
    for ( ; iter != lEnd; ++iter ) { \
      ( *iter )->accept ( v ); \
    } \
    v.endVisit(*this); \
  } \
};

#define NARY_ITER(name) NARY_ITER_STATE(name, PlanIteratorState) 

} /* namespace xqp */

#endif /* XQP_NARYBASE_H */
