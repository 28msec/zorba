
// #include "runtime/iterators.h"
// #include "runtime/paths/path_iterators.h"

namespace xqp {

// /* begin class UnaryBaseIterator */
// template <class IterType>
// UnaryBaseIterator<IterType>::UnaryBaseIterator(const yy::location& loc, Iterator_t& arg)
// 	:
//   Batcher<IterType>(loc), theChild(arg) 
// {
// }
// 
// 	
// template <class IterType>
// UnaryBaseIterator<IterType>::~UnaryBaseIterator()
// {
// }
// 
// 	
// template <class IterType>
// void 
// UnaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
// {
//   BasicIterator::BasicIteratorState* state;
//   GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
//   state->reset();
// 		
//   this->resetChild ( theChild, stateBlock );
// }
// 
// 
// template <class IterType>
// void 
// UnaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
// {
//   this->releaseChildResources ( theChild, stateBlock );
// }
// 
// 
// template <class IterType>
// int32_t
// UnaryBaseIterator<IterType>::getStackSize()
// {
//   return sizeof(BasicIterator::BasicIteratorState);
// }
// 
// 	
// template <class IterType>
// int32_t
// UnaryBaseIterator<IterType>::getStackSizeOfSubtree()
// {
//   return theChild->getStackSizeOfSubtree() + getStackSize();
// }
// 
// 	
// template <class IterType>
// void
// UnaryBaseIterator<IterType>::setOffset(int32_t& offset)
// {
//   this->stateOffset = offset;
//   offset += getStackSize();
// 	
//   theChild->setOffset(offset);
// }
// /* end class UnaryBaseIterator */
// 
// 	
// /* begin class BinaryBaseIterator */
// template <class IterType>
// BinaryBaseIterator<IterType>::BinaryBaseIterator(
//     const yy::location& loc,
//     Iterator_t& arg0,
//     Iterator_t& arg1 )
//   :
//   Batcher<IterType> ( loc ), theChild0 ( arg0 ), theChild1 ( arg1 ) 
// {
// }
// 
// 
// template <class IterType>
// BinaryBaseIterator<IterType>::~BinaryBaseIterator()
// {
// }
// 
// 
// template <class IterType>
// void 
// BinaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
// {
//   BasicIterator::BasicIteratorState* state;
//   GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
//   state->reset();
// 		
//   this->resetChild ( theChild0, stateBlock );
//   this->resetChild ( theChild1, stateBlock );
// }
// 
// 
// template <class IterType>
// void 
// BinaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
// {
//   this->releaseChildResources ( theChild0, stateBlock );
//   this->releaseChildResources ( theChild1, stateBlock );
// }
// 
// 
// template <class IterType>
// int32_t
// BinaryBaseIterator<IterType>::getStackSize()
// {
//   return sizeof(BasicIterator::BasicIteratorState);
// }
// 
// 	
// template <class IterType>
// int32_t
// BinaryBaseIterator<IterType>::getStackSizeOfSubtree()
// {
//   return theChild0->getStackSizeOfSubtree()
//        + theChild1->getStackSizeOfSubtree()
//        + this->getStackSize();
// }
// 
// 	
// template <class IterType>
// void
// BinaryBaseIterator<IterType>::setOffset(int32_t& offset)
// {
//   this->stateOffset = offset;
//   offset += this->getStackSize();
// 		
//   theChild0->setOffset(offset);
//   theChild1->setOffset(offset);
// }
// /* end class BinaryBaseIterator */
// 
// 	
// /* begin class NaryBaseIterator */
// template <class IterType>
// NaryBaseIterator<IterType>::NaryBaseIterator(
//     const yy::location& loc,
//     std::vector<Iterator_t>& args)
//   :
//   Batcher<IterType> ( loc ), theChildren ( args )
// {
// }
// 
// 
// template <class IterType>
// NaryBaseIterator<IterType>::~NaryBaseIterator()
// {
// }
// 
// 
// template <class IterType>
// void 
// NaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
// {
//   BasicIterator::BasicIteratorState* state;
//   GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
//   state->reset();
// 		
//   std::vector<Iterator_t>::iterator iter = theChildren.begin();
//   for(; iter != theChildren.end(); ++iter) {
//     this->resetChild(*iter, stateBlock);
//   }
// }
// 
// 
// template <class IterType>
// void 
// NaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
// {
//   std::vector<Iterator_t>::iterator iter = theChildren.begin();
//   for(; iter != theChildren.end(); ++iter) {
//     this->releaseChildResources(*iter, stateBlock);
//   }
// }
// 
//   
// template <class IterType>
// int32_t
// NaryBaseIterator<IterType>::getStackSize()
// {
//   return sizeof(BasicIterator::BasicIteratorState);
// }
// 
// 	
// template <class IterType>
// int32_t
// NaryBaseIterator<IterType>::getStackSizeOfSubtree()
// {
//   int32_t size = 0;
// 	
//   std::vector<Iterator_t>::const_iterator iter = theChildren.begin();
//   for(; iter != theChildren.end(); ++iter) {
//     size += (*iter)->getStackSizeOfSubtree();
//   }
// 	
//   return this->getStackSize() + size;
// }
// 
// 	
// template <class IterType>
// void
// NaryBaseIterator<IterType>::setOffset(int32_t& offset)
// {
//   this->stateOffset = offset;
//   offset += this->getStackSize();
// 	
//   std::vector<Iterator_t>::iterator iter = theChildren.begin();
//   for(; iter != theChildren.end(); ++iter) {
//     (*iter)->setOffset(offset);
//   }
// }
// /* end class NaryBaseIterator */
	
} /* namespace xqp */
