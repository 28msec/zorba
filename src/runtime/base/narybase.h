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
#ifndef ZORBA_NARY_ITERATOR
#define ZORBA_NARY_ITERATOR

#include <vector>

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/visitors/planitervisitor.h"

namespace zorba
{

class PlanIterVisitor;

extern const ::zorba::serialization::ClassVersion g_NaryBaseIterator_class_versions[];
extern const int g_NaryBaseIterator_class_versions_count;


/*******************************************************************************
  Superclass for all iterators which have n child iterators 
********************************************************************************/
template <class IterType, class StateType = PlanIteratorState>
class NaryBaseIterator : public Batcher<IterType>
{
protected:
  std::vector<PlanIter_t> theChildren;

public:
  SERIALIZABLE_CLASS_NO_FACTORY(NaryBaseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NaryBaseIterator, Batcher<IterType>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<IterType>*)this);
    ar & theChildren;
  }
public:
  NaryBaseIterator ( short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& args );

  virtual ~NaryBaseIterator(){}

  void openImpl ( PlanState& planState, uint32_t& offset );
  void resetImpl ( PlanState& planState ) const;
  void closeImpl ( PlanState& planState );

  virtual uint32_t getStateSize() const
  {
    return StateTraitsImpl<StateType>::getStateSize();
  }
 
  virtual uint32_t getStateSizeOfSubtree() const;

  virtual void accept(PlanIterVisitor& v) const;
};


template <class IterType, class StateType>
NaryBaseIterator<IterType, StateType>::NaryBaseIterator (
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& aChildren )
  :
  Batcher<IterType> ( sctx, loc ),
  theChildren ( aChildren )
{
#ifndef NDEBUG
  std::vector<PlanIter_t>::const_iterator lEnd = aChildren.end();
  for(std::vector<PlanIter_t>::const_iterator lIter = aChildren.begin();
      lIter != lEnd;
      ++lIter)
  {
    assert(*lIter != 0);
  }
#endif
}


template <class IterType, class StateType>
void NaryBaseIterator<IterType, StateType>::accept(PlanIterVisitor& v) const  
{
  v.beginVisit(*static_cast<const IterType*>(this));
  std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin(); 
  std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();   
  for ( ; iter != lEnd; ++iter ) 
  {                                     
    ( *iter )->accept ( v );                                           
  }                                                                    
  v.endVisit(*static_cast<const IterType*>(this));
}


template <class IterType, class StateType>
uint32_t
NaryBaseIterator<IterType, StateType>::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for (; lIter!= lEnd; ++lIter )
  {
    size += ( *lIter )->getStateSizeOfSubtree();
  }

  return this->getStateSize() + size;
}


template <class IterType, class StateType>
void
NaryBaseIterator<IterType, StateType>::openImpl ( PlanState& planState, uint32_t& offset ) 
{
  StateTraitsImpl<StateType>::createState(planState, this->stateOffset, offset);
  StateTraitsImpl<StateType>::initState(planState, this->stateOffset);

  //this->theSctx = planState.theCompilerCB->getStaticContext(this->sctx);

  std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
  std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
  for ( ; lIter!= lEnd; ++lIter )
	{
    ( *lIter )->open( planState, offset );
  }
}


template <class IterType, class StateType>
void
NaryBaseIterator<IterType, StateType>::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<StateType>::reset(planState, this->stateOffset);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter!= lEnd; ++lIter )
	{
    ( *lIter )->reset( planState );
  }
}


template <class IterType, class StateType>
void
NaryBaseIterator<IterType, StateType>::closeImpl ( PlanState& planState )
{
  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter!= lEnd; ++lIter )
  {
    ( *lIter )->close( planState );
  }

  StateTraitsImpl<StateType>::destroyState(planState, this->stateOffset);
}



/*******************************************************************************
  Macro for defining iterators with N children and their own additional state
********************************************************************************/

#define NARY_ITER_STATE(iterName, stateName)                             \
class iterName : public NaryBaseIterator<iterName, stateName >           \
{                                                                        \
public:                                                                  \
  iterName(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren) \
    :                                                                   \
    NaryBaseIterator<iterName, stateName >(sctx, loc, aChildren)        \
  { }                                                                   \
                                                                        \
 public:                                                                \
  SERIALIZABLE_CLASS(iterName)                                          \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, NaryBaseIterator<iterName, stateName >) \
  void serialize(::zorba::serialization::Archiver &ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NaryBaseIterator<iterName, stateName >*)this); \
  }                                                                     \
 public:                                                                \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


#define NARY_ITER_STATE_SCTX(iterName, stateName)                       \
class iterName : public NaryBaseIterator<iterName, stateName >          \
{                                                                       \
 public:                                                                \
  iterName(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)\
    :                                                                   \
    NaryBaseIterator<iterName, stateName >(sctx, loc, aChildren)        \
  { }                                                                   \
                                                                        \
 public:                                                                \
  SERIALIZABLE_CLASS(iterName)                                          \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, NaryBaseIterator<iterName, stateName >) \
  void serialize(::zorba::serialization::Archiver &ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NaryBaseIterator<iterName, stateName >*)this); \
  }                                                                     \
 public:                                                                \
  void openImpl(PlanState& planState, uint32_t& offset);                \
                                                                        \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


#define NARY_UPDATE_ITER_STATE(iterName, stateName)                      \
class iterName : public NaryBaseIterator<iterName, stateName >           \
{                                                                        \
public:                                                                  \
  iterName(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)\
    :                                                                   \
    NaryBaseIterator<iterName, stateName >(sctx, loc, aChildren)        \
  { }                                                                   \
                                                                        \
 public:                                                                \
  SERIALIZABLE_CLASS(iterName)                                          \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, NaryBaseIterator<iterName, stateName >) \
  void serialize(::zorba::serialization::Archiver &ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NaryBaseIterator<iterName, stateName >*)this); \
  }                                                                     \
 public:                                                                \
  bool isUpdating() const { return true; }                              \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


#define NARY_UPDATE_ITER_STATE_SCTX(iterName, stateName)                \
class iterName : public NaryBaseIterator<iterName, stateName >          \
{                                                                       \
 public:                                                                \
  iterName(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)\
    :                                                                   \
    NaryBaseIterator<iterName, stateName >(sctx, loc, aChildren)        \
  { }                                                                   \
                                                                        \
 public:                                                                \
  SERIALIZABLE_CLASS(iterName)                                          \
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(iterName, NaryBaseIterator<iterName, stateName >) \
  void serialize(::zorba::serialization::Archiver &ar)                  \
  {                                                                     \
    serialize_baseclass(ar, (NaryBaseIterator<iterName, stateName >*)this); \
  }                                                                     \
 public:                                                                \
  bool isUpdating() const { return true; }                              \
                                                                        \
  void openImpl(PlanState& planState, uint32_t& offset);                \
                                                                        \
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;    \
};


/*******************************************************************************
  Macro for defining iterators with N children and no additional state
********************************************************************************/

#define NARY_ITER(name) \
NARY_ITER_STATE(name, PlanIteratorState) 

#define NARY_ITER_SCTX(name) \
NARY_ITER_STATE_SCTX(name, PlanIteratorState) 

#define NARY_UPDATE_ITER(name) \
NARY_UPDATE_ITER_STATE(name, PlanIteratorState) 

#define NARY_UPDATE_ITER_SCTX(name) \
NARY_UPDATE_ITER_STATE_SCTX(name, PlanIteratorState) 

} /* namespace zorba */

#endif /* ZORBA_NARYBASE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
