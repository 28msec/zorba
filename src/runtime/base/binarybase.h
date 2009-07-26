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
#ifndef ZORBA_BINARYBASE_H
#define ZORBA_BINARYBASE_H

#include "common/shared_types.h"
#include "runtime/base/plan_iterator.h"

namespace zorba
{
extern const ::zorba::serialization::ClassVersion g_BinaryBaseIterator_class_versions[];
extern const int g_BinaryBaseIterator_class_versions_count;
/**
 * Superclass for all iterators which have two child iterators 
 * and no additional state variables.
 */
template <class IterType, class StateType>
class BinaryBaseIterator : public Batcher<IterType>
{
protected:
  PlanIter_t theChild0;
  PlanIter_t theChild1;

public:
  SERIALIZABLE_CLASS_NO_FACTORY(BinaryBaseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(BinaryBaseIterator, Batcher<IterType>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<IterType>*)this);
    ar & theChild0;
    ar & theChild1;
  }
public:
  BinaryBaseIterator ( short sctx, const QueryLoc& loc, PlanIter_t& arg0, PlanIter_t& arg1 );

  virtual ~BinaryBaseIterator();

  void openImpl(PlanState& planState, uint32_t& offset);
  void resetImpl(PlanState& planState ) const;
  void closeImpl(PlanState& planState );

  virtual uint32_t getStateSize() const 
  {
    return StateTraitsImpl<StateType>::getStateSize(); 
  }

  virtual uint32_t getStateSizeOfSubtree() const;
};



template <class IterType, class StateType>
BinaryBaseIterator<IterType, StateType>::BinaryBaseIterator (
    short sctx,
    const QueryLoc& loc,
    PlanIter_t& aChild0,
    PlanIter_t& aChild1 )
  :
  Batcher<IterType> ( sctx, loc ), theChild0 ( aChild0 ), theChild1 ( aChild1 )
{
#ifndef NDEBUG
  assert(aChild0 != 0);
  assert(aChild1 != 0);
#endif
}


template <class IterType, class StateType>
BinaryBaseIterator<IterType, StateType>::~BinaryBaseIterator()
{
}


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::openImpl (
    PlanState& planState,
    uint32_t& offset )
{
  StateTraitsImpl <StateType>::createState(planState, this->stateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->stateOffset);

  theChild0->open(planState, offset);
  theChild1->open(planState, offset);
}


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<StateType>::reset(planState, this->stateOffset);

  theChild0->reset( planState );
  theChild1->reset( planState );
}


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::closeImpl ( PlanState& planState )
{
  theChild0->close( planState );
  theChild1->close( planState );

  StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
}


template <class IterType, class StateType>
uint32_t
BinaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
{
  return theChild0->getStateSizeOfSubtree() + theChild1->getStateSizeOfSubtree()
       + this->getStateSize();
}


} /* namespace zorba */

#endif /* ZORBA_BINARYBASE_H */
/* vim:set ts=2 sw=2: */
