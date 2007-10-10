/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @file runtime/iterators/iterators.h
 *
 */

#ifndef XQP_ITERATORS_H
#define XQP_ITERATORS_H

#include "runtime/batching.h"


namespace xqp {
	
template <class IterType>
class UnaryBaseIterator : public Batcher<IterType>
{
 protected:
  Iterator_t theChild;
		
 public:
  UnaryBaseIterator(const yy::location& loc, Iterator_t& arg);
  virtual ~UnaryBaseIterator();

  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);
			
  virtual int32_t getStackSize();
  virtual int32_t getStackSizeOfSubtree();
  virtual void setOffset(int32_t& offset);
}; /* class UnaryBaseIterator */

	
template <class IterType>
class BinaryBaseIterator : public Batcher<IterType>
{
 protected:
  Iterator_t theChild0;
  Iterator_t theChild1;
			
 public:
  BinaryBaseIterator(const yy::location& loc, Iterator_t& arg0, Iterator_t& arg1);
  virtual ~BinaryBaseIterator();

  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);
			
  virtual int32_t getStackSize();
  virtual int32_t getStackSizeOfSubtree();
  virtual void setOffset(int32_t& offset);
}; /* class BinaryBaseIterator */
	

template <class IterType>
class NaryBaseIterator : public Batcher<IterType>
{
 protected:
  std::vector<Iterator_t> theChildren;
			
 public:
  NaryBaseIterator(const yy::location& loc, std::vector<Iterator_t>& args);
  virtual ~NaryBaseIterator();

  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);
			
  virtual int32_t getStackSize();
  virtual int32_t getStackSizeOfSubtree();
  virtual void setOffset(int32_t& offset);
}; /* class BinaryBaseIterator */



/* begin class UnaryBaseIterator */
template <class IterType>
UnaryBaseIterator<IterType>::UnaryBaseIterator(const yy::location& loc, Iterator_t& arg)
	:
  Batcher<IterType>(loc), theChild(arg) 
{
}

	
template <class IterType>
UnaryBaseIterator<IterType>::~UnaryBaseIterator()
{
}

	
template <class IterType>
void 
UnaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
{
  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
		
  this->resetChild ( theChild, stateBlock );
}


template <class IterType>
void 
UnaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
{
  this->releaseChildResources ( theChild, stateBlock );
}


template <class IterType>
int32_t
UnaryBaseIterator<IterType>::getStackSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
UnaryBaseIterator<IterType>::getStackSizeOfSubtree()
{
  return theChild->getStackSizeOfSubtree() + getStackSize();
}

	
template <class IterType>
void
UnaryBaseIterator<IterType>::setOffset(int32_t& offset)
{
  this->stateOffset = offset;
  offset += getStackSize();
	
  theChild->setOffset(offset);
}
/* end class UnaryBaseIterator */

	
/* begin class BinaryBaseIterator */
template <class IterType>
BinaryBaseIterator<IterType>::BinaryBaseIterator(
    const yy::location& loc,
    Iterator_t& arg0,
    Iterator_t& arg1 )
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
BinaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
{
  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
		
  this->resetChild ( theChild0, stateBlock );
  this->resetChild ( theChild1, stateBlock );
}


template <class IterType>
void 
BinaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
{
  this->releaseChildResources ( theChild0, stateBlock );
  this->releaseChildResources ( theChild1, stateBlock );
}


template <class IterType>
int32_t
BinaryBaseIterator<IterType>::getStackSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
BinaryBaseIterator<IterType>::getStackSizeOfSubtree()
{
  return theChild0->getStackSizeOfSubtree()
       + theChild1->getStackSizeOfSubtree()
       + this->getStackSize();
}

	
template <class IterType>
void
BinaryBaseIterator<IterType>::setOffset(int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStackSize();
		
  theChild0->setOffset(offset);
  theChild1->setOffset(offset);
}
/* end class BinaryBaseIterator */

	
/* begin class NaryBaseIterator */
template <class IterType>
NaryBaseIterator<IterType>::NaryBaseIterator(
    const yy::location& loc,
    std::vector<Iterator_t>& args)
  :
  Batcher<IterType> ( loc ), theChildren ( args )
{
}


template <class IterType>
NaryBaseIterator<IterType>::~NaryBaseIterator()
{
}


template <class IterType>
void 
NaryBaseIterator<IterType>::resetImpl(int8_t* stateBlock)
{
  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
		
  std::vector<Iterator_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    this->resetChild(*iter, stateBlock);
  }
}


template <class IterType>
void 
NaryBaseIterator<IterType>::releaseResourcesImpl(int8_t* stateBlock)
{
  std::vector<Iterator_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    this->releaseChildResources(*iter, stateBlock);
  }
}

  
template <class IterType>
int32_t
NaryBaseIterator<IterType>::getStackSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
NaryBaseIterator<IterType>::getStackSizeOfSubtree()
{
  int32_t size = 0;
	
  std::vector<Iterator_t>::const_iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    size += (*iter)->getStackSizeOfSubtree();
  }
	
  return this->getStackSize() + size;
}

	
template <class IterType>
void
NaryBaseIterator<IterType>::setOffset(int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStackSize();
	
  std::vector<Iterator_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    (*iter)->setOffset(offset);
  }
}
/* end class NaryBaseIterator */


} /* namespace xqp */


#endif	/* XQP_ITERATORS_H */
