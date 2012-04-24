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
#ifndef ZORBA_RUNTIME_NOARY_ITERATOR
#define ZORBA_RUNTIME_NOARY_ITERATOR

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"


namespace zorba
{


/*******************************************************************************
  Superclass for all iterators which have no child iterators and no additional
  data members. 
********************************************************************************/
template <class IterType, class StateType>
class NoaryBaseIterator : public Batcher<IterType>
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(NoaryBaseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2(NoaryBaseIterator, Batcher<IterType>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (Batcher<IterType>*)this);
  }

public:
  NoaryBaseIterator(static_context* sctx, const QueryLoc& loc)
    :
    Batcher<IterType>(sctx, loc)
  {
  }

  virtual ~NoaryBaseIterator() { }

  virtual uint32_t getStateSize() const 
  {
    return StateTraitsImpl<StateType>::getStateSize(); 
  }

  virtual uint32_t getStateSizeOfSubtree() const 
  {
    return getStateSize(); 
  }

  virtual void openImpl(PlanState&, uint32_t& offset);

  virtual void resetImpl(PlanState& planState) const;

  virtual void closeImpl(PlanState& planState);
};



template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
#ifndef NDEBUG
  uint32_t saveOffset = this->theStateOffset;
#endif
  StateTraitsImpl<StateType>::createState(planState, this->theStateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->theStateOffset);

#ifndef NDEBUG
  if (saveOffset != 0 && saveOffset != this->theStateOffset)
  {
    std::cout << "saved offset = " << saveOffset
              << " current offset = " << this->theStateOffset << std::endl;
    ZORBA_ASSERT(false);
  }
#endif
}


template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<StateType>::reset(planState, this->theStateOffset);
}


template <class IterType, class StateType>
void
NoaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  StateTraitsImpl<StateType>::destroyState(planState, this->theStateOffset);
}


#define NOARY_ACCEPT(IterType)                  \
void IterType::accept(PlanIterVisitor& v) const \
{                                               \
  v.beginVisit(*this);                          \
  v.endVisit(*this);                            \
}
  

/*******************************************************************************
  Macro for defining iterators with N children and their own additional state
********************************************************************************/

#define NOARY_ITER_STATE(iterName, stateName)                           \
class iterName : public NoaryBaseIterator<iterName, stateName >         \
{                                                                       \
 public:                                                                \
  SERIALIZABLE_CLASS(iterName);                                         \
                                                                        \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, NoaryBaseIterator<iterName, stateName>) \
                                                                        \
  void serialize(::zorba::serialization::Archiver& ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NoaryBaseIterator<iterName, stateName>*)this); \
  }                                                                     \
                                                                        \
 public:                                                                \
  iterName(static_context* sctx, const QueryLoc& loc)                   \
    :                                                                   \
    NoaryBaseIterator<iterName, stateName>(sctx, loc)                   \
  { }                                                                   \
                                                                        \
  void accept(PlanIterVisitor& v) const;                                \
                                                                        \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


/*******************************************************************************
  Macro for defining iterators with N children and no additional state
********************************************************************************/

#define NOARY_ITER(name) \
NOARY_ITER_STATE(name, PlanIteratorState) 



};

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
