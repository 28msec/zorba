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
#pragma once
#ifndef ZORBA_RUNTIME_BINARYBASE_H
#define ZORBA_RUNTIME_BINARYBASE_H

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"


namespace zorba
{


/*******************************************************************************
  Superclass for all iterators which have 2 child iterators and no additional
  data members.
********************************************************************************/
template <class IterType, class StateType>
class BinaryBaseIterator : public Batcher<IterType>
{
protected:
  PlanIter_t theChild0;
  PlanIter_t theChild1;

public:
  SERIALIZABLE_ABSTRACT_CLASS(BinaryBaseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(BinaryBaseIterator, Batcher<IterType>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (Batcher<IterType>*)this);
    ar & theChild0;
    ar & theChild1;
  }

public:
  BinaryBaseIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& child0,
        PlanIter_t& child1)
    :
    Batcher<IterType>(sctx, loc),
    theChild0(child0),
    theChild1(child1)
  {
  }

  virtual ~BinaryBaseIterator() {}

  PlanIter_t& getChild0()
  {
    return theChild0;
  }

  PlanIter_t& getChild1()
  {
    return theChild1;
  }

  virtual uint32_t getStateSize() const
  {
    return StateTraitsImpl<StateType>::getStateSize();
  }

  virtual uint32_t getStateSizeOfSubtree() const
  {
    return (theChild0 ? theChild0->getStateSizeOfSubtree() : 0) +
           (theChild1 ? theChild1->getStateSizeOfSubtree() : 0) +
           this->getStateSize();
  }

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);
};


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  StateTraitsImpl<StateType>::createState(planState, this->theStateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->theStateOffset);

  if (theChild0)
    theChild0->open(planState, offset);

  if (theChild1)
    theChild1->open(planState, offset);
}


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<StateType>::reset(planState, this->theStateOffset);

  if (theChild0)
    theChild0->reset(planState);

  if (theChild1)
    theChild1->reset(planState);
}


template <class IterType, class StateType>
void
BinaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  if (theChild0)
    theChild0->close(planState);

  if (theChild1)
    theChild1->close(planState);

  StateTraitsImpl<StateType>::destroyState(planState, this->theStateOffset);
}


#define BINARY_ACCEPT(IterType)                 \
void IterType::accept(PlanIterVisitor& v) const \
{                                               \
  v.beginVisit(*this);                          \
  if (theChild0)                                \
    theChild0->accept(v);                       \
  if (theChild1)                                \
    theChild1->accept(v);                       \
  v.endVisit(*this);                            \
}


/*******************************************************************************
  Macro for defining iterators with N children and their own additional state
********************************************************************************/

#define BINARY_ITER_STATE(iterName, stateName)                          \
class iterName : public BinaryBaseIterator<iterName, stateName>         \
{                                                                       \
public:                                                                 \
  SERIALIZABLE_CLASS(iterName);                                         \
                                                                        \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(                                     \
  iterName, BinaryBaseIterator<iterName, stateName>);                   \
                                                                        \
  void serialize(::zorba::serialization::Archiver& ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (BinaryBaseIterator<iterName, stateName>*)this); \
  }                                                                     \
                                                                        \
public:                                                                 \
  iterName(                                                             \
        static_context* sctx,                                           \
        const QueryLoc& loc,                                            \
        PlanIter_t& child1,                                             \
        PlanIter_t& child2)                                             \
    :                                                                   \
    BinaryBaseIterator<iterName, stateName>(sctx, loc, child1, child2)  \
  { }                                                                   \
                                                                        \
  void accept(PlanIterVisitor& v) const;                                \
                                                                        \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


/*******************************************************************************
  Macro for defining iterators with 2 children and no additional state
********************************************************************************/

#define BINARY_ITER(name) \
BINARY_ITER_STATE(name, PlanIteratorState)



} /* namespace zorba */

#endif /* ZORBA_BINARYBASE_H */



/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
