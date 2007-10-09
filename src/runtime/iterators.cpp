#include "iterators.h"

namespace xqp {
	/* begin class UnaryBaseIterator */
	template <class IterType>
	UnaryBaseIterator::UnaryBaseIterator
		(const yy::location& loc, Iterator_t& arg)
	:
		Batcher<IterType>(loc), iter(arg) 
	{}
	
	template <class IterType>
	UnaryBaseIterator<IterType>::~UnaryBaseIterator() {}
	
	template <class IterType>
	void 
	UnaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		BasicIterator::BasicIteratorState* state;
		GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
		state->reset();
		
		this->resetChild ( this->iter0, stateBlock );
	}

	template <class IterType>
	void 
	UnaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources ( this->iter, stateBlock );
	}

	template <class IterType>
	int32_t
	UnaryBaseIterator<IterType>::getStateSize() {
		return sizeof(BasicIterator::BasicIteratorState);
	}
	
	template <class IterType>
	int32_t
	UnaryBaseIterator<IterType>::getStateSizeOfSubtree() {
		return this->iter->getStateSizeOfSubtree()
						+ this->getStateSize();
	}
	
	template <class IterType>
	void
	UnaryBaseIterator<IterType>::setOffset(int32_t& offset) {
		this->stateOffset = offset;
		offset += this->getStateSize();
		
		this->iter->setOffset(offset);
	}
	/* end class UnaryBaseIterator */
	
	/* begin class BinaryBaseIterator */
	template <class IterType>
	BinaryBaseIterator<IterType>::BinaryBaseIterator
		( const yy::location& loc, Iterator_t& arg0, Iterator_t& arg1 )
	:
		Batcher<IterType> ( loc ),iter0 ( arg0 ),iter1 ( arg1 ) 
	{}

	template <class IterType>
	BinaryBaseIterator<IterType>::~BinaryBaseIterator() {}

	template <class IterType>
	void 
	BinaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		BasicIterator::BasicIteratorState* state;
		GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
		state->reset();
		
		this->resetChild ( this->iter0, stateBlock );
		this->resetChild ( this->iter1, stateBlock );
	}

	template <class IterType>
	void 
	BinaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources ( this->iter0, stateBlock );
		this->releaseChildResources ( this->iter1, stateBlock );
	}

	template <class IterType>
	int32_t
	BinaryBaseIterator<IterType>::getStateSize() {
		return sizeof(BasicIterator::BasicIteratorState);
	}
	
	template <class IterType>
	int32_t
	BinaryBaseIterator<IterType>::getStateSizeOfSubtree() {
		return this->iter0->getStateSizeOfSubtree()
						+ this->iter1->getStateSizeOfSubtree()
						+ this->getStateSize();
	}
	
	template <class IterType>
	void
	BinaryBaseIterator<IterType>::setOffset(int32_t& offset) {
		this->stateOffset = offset;
		offset += this->getStateSize();
		
		this->iter0->setOffset(offset);
		this->iter1->setOffset(offset);
	}
	/* end class BinaryBaseIterator */
	
	/* begin class NaryBaseIterator */
	template <class IterType>
	NaryBaseIterator<IterType>::NaryBaseIterator
		( const yy::location& loc, std::vector<Iterator_t>& args)
	:
		Batcher<IterType> ( loc ),iters ( args )
	{}

	template <class IterType>
	NaryBaseIterator<IterType>::~NaryBaseIterator() {}

	template <class IterType>
	void 
	NaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		BasicIterator::BasicIteratorState* state;
		GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
		state->reset();
		
		std::vector<Iterator_t>::iterator iter = this->iters.begin();
		for(; iter != this->iters.end(); ++iter) {
			this->resetChild(*iter, stateBlock);
		}
	}

	template <class IterType>
	void 
	BinaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		std::vector<Iterator_t>::iterator iter = this->iters.begin();
		for(; iter != this->iters.end(); ++iter) {
			this->releaseChildResources(*iter, stateBlock);
		}
	}

	template <class IterType>
	int32_t
	BinaryBaseIterator<IterType>::getStateSize() {
		return sizeof(BasicIterator::BasicIteratorState);
	}
	
	template <class IterType>
	int32_t
	BinaryBaseIterator<IterType>::getStateSizeOfSubtree() {
		int32_t size = 0;
	
		std::vector<Iterator_t>::const_iterator iter = this->argv.begin();
		for(; iter != this->iters.end(); ++iter) {
			size += (*iter)->getStateSizeOfSubtree();
		}
		
		return this->getStateSize() + size;
	}
	
	template <class IterType>
	void
	BinaryBaseIterator<IterType>::setOffset(int32_t& offset) {
		this->stateOffset = offset;
		offset += this->getStateSize();
		
		std::vector<Iterator_t>::iterator iter = this->argv.begin();
		for(; iter != this->iters.end(); ++iter) {
			(*iter)->setOffset(offset);
		}
	}
	/* end class NaryBaseIterator */
	
} /* namespace xqp */
