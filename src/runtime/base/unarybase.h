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
#ifndef ZORBA_RUNTIME_UNARY_ITERATOR
#define ZORBA_RUNTIME_UNARY_ITERATOR

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"


namespace zorba
{


/*******************************************************************************
  Superclass for all iterators which have one child iterator and no additional
  data members.
********************************************************************************/
template <class IterType, class StateType>
class UnaryBaseIterator : public Batcher<IterType>
{
protected:
  PlanIter_t theChild;

public:
  SERIALIZABLE_ABSTRACT_CLASS(UnaryBaseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(UnaryBaseIterator, Batcher<IterType>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (Batcher<IterType>*)this);
    ar & theChild;
  }

public:
  UnaryBaseIterator(
      static_context* sctx,
      const QueryLoc& loc,
      const PlanIter_t& child)
    :
    Batcher<IterType>(sctx, loc),
    theChild(child)
  {
#ifndef NDEBUG
    assert(theChild != 0);
#endif
  }

  virtual ~UnaryBaseIterator() {}

  const PlanIter_t& getChild()
  {
    return theChild;
  }

  virtual uint32_t getStateSize() const
  {
    return StateTraitsImpl<StateType>::getStateSize();
  }

  virtual uint32_t getStateSizeOfSubtree() const
  {
    return theChild->getStateSizeOfSubtree() + getStateSize();
  }

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);
};


template <class IterType, class StateType>
void UnaryBaseIterator<IterType, StateType>::serialize_internal(
    ::zorba::serialization::Archiver& ar)
{
  if (ar.is_serialize_base_class()) 
    ar.set_serialize_base_class(false);

  UnaryBaseIterator<IterType, StateType>::serialize(ar);
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  StateTraitsImpl<StateType>::createState(planState, this->theStateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->theStateOffset);

  theChild->open(planState, offset);
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<StateType>::reset(planState, this->theStateOffset);

  theChild->reset(planState);
}


template <class IterType, class StateType>
void
UnaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  theChild->close(planState);

  StateTraitsImpl<StateType>::destroyState(planState, this->theStateOffset);
}


#define UNARY_ACCEPT(IterType)                      \
void IterType::accept(PlanIterVisitor& v) const     \
{                                                   \
  v.beginVisit(*this);                              \
  theChild->accept(v);                              \
  v.endVisit(*this);                                \
}


/*******************************************************************************
  Macro for defining iterators with N children and their own additional state
********************************************************************************/

#define UNARY_ITER_STATE(iterName, stateName)                           \
class iterName : public UnaryBaseIterator<iterName, stateName>          \
{                                                                       \
public:                                                                 \
  SERIALIZABLE_CLASS(iterName);                                         \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, UnaryBaseIterator<iterName, stateName>); \
  void serialize(::zorba::serialization::Archiver& ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (UnaryBaseIterator<iterName, stateName>*)this); \
  }                                                                     \
                                                                        \
public:                                                                 \
  iterName(                                                             \
        static_context* sctx,                                           \
        const QueryLoc& loc,                                            \
        PlanIter_t& aChild)                                             \
    :                                                                   \
    UnaryBaseIterator<iterName, stateName>(sctx, loc, aChild)           \
  { }                                                                   \
                                                                        \
  void accept(PlanIterVisitor& v) const;                                \
                                                                        \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


/*******************************************************************************
  Macro for defining iterators with N children and no additional state
********************************************************************************/

#define UNARY_ITER(name) \
UNARY_ITER_STATE(name, PlanIteratorState)


}; /* namespace zorba*/

#endif /* ZORBA_UNARYBASE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
