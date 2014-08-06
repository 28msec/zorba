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
#ifndef ZORBA_RUNTIME_NARY_ITERATOR
#define ZORBA_RUNTIME_NARY_ITERATOR

#include <cassert>
#include <vector>

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"

namespace zorba
{

class PlanIterVisitor;


/*******************************************************************************
  Superclass for all iterators which have N child iterators and no additional
  data members.
********************************************************************************/
template <class IterType, class StateType>
class NaryBaseIterator : public PlanIterator
{
protected:
  std::vector<PlanIter_t> theChildren;

public:
  SERIALIZABLE_ABSTRACT_CLASS(NaryBaseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NaryBaseIterator, PlanIterator)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (PlanIterator*)this);
    ar & theChildren;
  }

public:
  NaryBaseIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& args);

  virtual ~NaryBaseIterator(){}

  std::vector<PlanIter_t>& getChildren()
  {
    return theChildren;
  }

  virtual uint32_t getStateSize() const
  {
    return StateTraitsImpl<StateType>::getStateSize();
  }

  virtual uint32_t getStateSizeOfSubtree() const;

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);
};


template <class IterType, class StateType>
NaryBaseIterator<IterType, StateType>::NaryBaseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
  :
  PlanIterator(sctx, loc),
  theChildren(children)
{
#ifndef NDEBUG
  std::vector<PlanIter_t>::const_iterator end = children.end();
  std::vector<PlanIter_t>::const_iterator ite = children.begin();
  for(; ite != end; ++ite)
  {
    assert(*ite != 0);
  }
#endif
}


template <class IterType, class StateType>
void NaryBaseIterator<IterType, StateType>::serialize_internal(
    ::zorba::serialization::Archiver& ar)
{
  if (ar.is_serialize_base_class()) 
    ar.set_serialize_base_class(false);

  NaryBaseIterator<IterType, StateType>::serialize(ar);
}


template <class IterType, class StateType>
uint32_t
NaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  std::vector<PlanIter_t>::const_iterator ite = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator end = theChildren.end();
  for (; ite != end; ++ite)
  {
    size += (*ite)->getStateSizeOfSubtree();
  }

  return this->getStateSize() + size;
}


template <class IterType, class StateType>
void NaryBaseIterator<IterType, StateType>::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  StateTraitsImpl<StateType>::createState(planState, this->theStateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->theStateOffset);

  std::vector<PlanIter_t>::iterator ite = theChildren.begin();
  std::vector<PlanIter_t>::iterator end = theChildren.end();
  for (; ite != end; ++ite)
	{
    (*ite)->open(planState, offset);
  }
}


template <class IterType, class StateType>
void NaryBaseIterator<IterType, StateType>::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<StateType>::reset(planState, this->theStateOffset);

  std::vector<PlanIter_t>::const_iterator ite = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator end = theChildren.end();
  for (; ite != end; ++ite)
	{
    (*ite)->reset(planState);
  }
}


template <class IterType, class StateType>
void NaryBaseIterator<IterType, StateType>::closeImpl(PlanState& planState)
{
  std::vector<PlanIter_t>::const_iterator ite = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator end = theChildren.end();
  for (; ite != end; ++ite)
  {
    (*ite)->close(planState);
  }

  StateTraitsImpl<StateType>::destroyState(planState, this->theStateOffset);
}


#define NARY_ACCEPT(IterType)                   \
void IterType::accept(PlanIterVisitor& v) const \
{                                               \
  v.beginVisit(*this);                                                  \
                                                                        \
  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();  \
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();     \
  for ( ; lIter != lEnd; ++lIter )                                      \
  {                                                                     \
    (*lIter)->accept(v);                                                \
  }                                                                     \
                                                                        \
  v.endVisit(*this);                                                    \
}


/*******************************************************************************
  Macro for defining iterators with N children and their own additional state
********************************************************************************/

#define NARY_ITER_STATE(iterName, stateName)                            \
class iterName : public NaryBaseIterator<iterName, stateName>           \
{                                                                       \
public:                                                                 \
  SERIALIZABLE_CLASS(iterName);                                         \
                                                                        \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(                                     \
  iterName, NaryBaseIterator<iterName, stateName>);                     \
                                                                        \
  void serialize(::zorba::serialization::Archiver& ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NaryBaseIterator<iterName, stateName>*)this); \
  }                                                                     \
                                                                        \
public:                                                                 \
  iterName(                                                             \
        static_context* sctx,                                           \
        const QueryLoc& loc,                                            \
        std::vector<PlanIter_t>& aChildren)                             \
    :                                                                   \
    NaryBaseIterator<iterName, stateName >(sctx, loc, aChildren)        \
  { }                                                                   \
                                                                        \
  void accept(PlanIterVisitor& v) const;                                \
  zstring getNameAsString() const;                                      \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


/*******************************************************************************
  Macro for defining iterators with N children and no additional state
********************************************************************************/

#define NARY_ITER(name) \
NARY_ITER_STATE(name, PlanIteratorState)


} /* namespace zorba */

#endif /* ZORBA_NARYBASE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
