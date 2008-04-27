/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_RUNTIME_UNARY_ITERATOR
#define ZORBA_RUNTIME_UNARY_ITERATOR

#include "common/shared_types.h"
#include "runtime/base/plan_iterator.h"

namespace zorba
{

/**
 * Superclass for all iterators which have one child iterator
 * and no additional state variables.
 */
template <class IterType, class StateType>
class UnaryBaseIterator : public Batcher<IterType>
{
protected:
  PlanIter_t theChild;

public:
  UnaryBaseIterator ( const QueryLoc& loc, PlanIter_t& arg );

  virtual ~UnaryBaseIterator();

  void openImpl(PlanState& planState, uint32_t& offset);
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual uint32_t getStateSize() const { return StateTraitsImpl<StateType>::getStateSize(); }
  virtual uint32_t getStateSizeOfSubtree() const;
};


template <class IterType, class StateType>
UnaryBaseIterator<IterType, StateType>::UnaryBaseIterator(
    const QueryLoc& loc,
    PlanIter_t& aChild)
  :
  Batcher<IterType> ( loc ), theChild ( aChild )
{
#ifndef NDEBUG
  assert(theChild != 0);
#endif
}


template <class IterType, class StateType>
UnaryBaseIterator<IterType, StateType>::~UnaryBaseIterator()
{
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  StateTraitsImpl<StateType>::createState(planState, this->stateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->stateOffset);

  theChild->open(planState, offset);
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<StateType>::reset(planState, this->stateOffset);
    
  theChild->reset( planState ); 
}


template <class IterType, class StateType>
void
  UnaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  theChild->close( planState );

  StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
}


template <class IterType, class StateType>
uint32_t
UnaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
{
  return theChild->getStateSizeOfSubtree() + getStateSize();
}


}; /* namespace zorba*/

#endif /* ZORBA_UNARYBASE_H */

