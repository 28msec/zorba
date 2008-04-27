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
#ifndef ZORBA_NOARYBASE_H
#define ZORBA_NOARYBASE_H

#include "common/shared_types.h"
#include "runtime/base/plan_iterator.h"

namespace zorba
{
/**
 * Superclass for all iterators which have no child iterators
 * and no additional state variables.
 */
template <class IterType, class StateType>
class NoaryBaseIterator : public Batcher<IterType>
{
public:
  NoaryBaseIterator ( const QueryLoc& loc );

  virtual ~NoaryBaseIterator();

  void openImpl (PlanState&, uint32_t& offset);
  void resetImpl ( PlanState& planState ) const;
  void closeImpl ( PlanState& planState );

  virtual uint32_t getStateSize() const { return StateTraitsImpl<StateType>::getStateSize(); }
  virtual uint32_t getStateSizeOfSubtree() const { return getStateSize(); }
};


template <class IterType, class StateType>
NoaryBaseIterator<IterType, StateType>::NoaryBaseIterator ( const QueryLoc& loc )
  :
  Batcher<IterType> ( loc )
{
}


template <class IterType, class StateType>
NoaryBaseIterator<IterType, StateType>::~NoaryBaseIterator()
{
}


template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset )
{
  StateTraitsImpl<StateType>::createState(planState, this->stateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->stateOffset);
}


template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<StateType>::reset(planState, this->stateOffset);
}


template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
}



}; /* namespace zorba*/

#endif /* ZORBA_NOARYBASE_H */

