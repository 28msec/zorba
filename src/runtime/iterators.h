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

#include "runtime/core/batching.h"


namespace xqp {
	
template <class IterType>
class UnaryBaseIterator : public Batcher<IterType>
{
 protected:
  Iterator_t theChild;
		
 public:
  UnaryBaseIterator(const yy::location& loc, Iterator_t& arg);
  virtual ~UnaryBaseIterator();

  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
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

  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
}; /* class BinaryBaseIterator */
	

template <class IterType>
class NaryBaseIterator : public Batcher<IterType>
{
 protected:
  std::vector<Iterator_t> theChildren;
			
 public:
  NaryBaseIterator(const yy::location& loc, std::vector<Iterator_t>& args);
  virtual ~NaryBaseIterator();

  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset);
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
UnaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
		
  this->resetChild ( theChild, stateBlock );
}


template <class IterType>
void 
UnaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  this->releaseChildResources ( theChild, stateBlock );
}


template <class IterType>
int32_t
UnaryBaseIterator<IterType>::getStateSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
UnaryBaseIterator<IterType>::getStateSizeOfSubtree()
{
  return theChild->getStateSizeOfSubtree() + getStateSize();
}

	
template <class IterType>
void
UnaryBaseIterator<IterType>::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();
	
  theChild->setOffset(stateBlock, offset);
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
BinaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
		
  this->resetChild ( theChild0, stateBlock );
  this->resetChild ( theChild1, stateBlock );
}


template <class IterType>
void 
BinaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  this->releaseChildResources ( theChild0, stateBlock );
  this->releaseChildResources ( theChild1, stateBlock );
}


template <class IterType>
int32_t
BinaryBaseIterator<IterType>::getStateSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
BinaryBaseIterator<IterType>::getStateSizeOfSubtree()
{
  return theChild0->getStateSizeOfSubtree()
       + theChild1->getStateSizeOfSubtree()
       + this->getStateSize();
}

	
template <class IterType>
void
BinaryBaseIterator<IterType>::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
		
  theChild0->setOffset(stateBlock, offset);
  theChild1->setOffset(stateBlock, offset);
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
NaryBaseIterator<IterType>::resetImpl(IteratorTreeStateBlock& stateBlock)
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
NaryBaseIterator<IterType>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  std::vector<Iterator_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    this->releaseChildResources(*iter, stateBlock);
  }
}

  
template <class IterType>
int32_t
NaryBaseIterator<IterType>::getStateSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
template <class IterType>
int32_t
NaryBaseIterator<IterType>::getStateSizeOfSubtree()
{
  int32_t size = 0;
	
  std::vector<Iterator_t>::const_iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    size += (*iter)->getStateSizeOfSubtree();
  }
	
  return this->getStateSize() + size;
}

	
template <class IterType>
void
NaryBaseIterator<IterType>::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
	
  std::vector<Iterator_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    (*iter)->setOffset(stateBlock, offset);
  }
}
/* end class NaryBaseIterator */


} /* namespace xqp */


#endif	/* XQP_ITERATORS_H */
