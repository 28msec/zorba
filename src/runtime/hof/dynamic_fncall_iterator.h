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
#ifndef ZORBA_RUNTIME_DYNAMIC_FNCALL_ITERATOR
#define ZORBA_RUNTIME_DYNAMIC_FNCALL_ITERATOR


#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/noarybase.h"

#include "zorbautils/hashset.h"
#include "zorbautils/hashmap_zstring.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
class ArgumentPlaceholderIterator: public NoaryBaseIterator<ArgumentPlaceholderIterator,PlanIteratorState>
{
public:
  SERIALIZABLE_CLASS(ArgumentPlaceholderIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ArgumentPlaceholderIterator,
  NoaryBaseIterator<ArgumentPlaceholderIterator, PlanIteratorState>);
  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NoaryBaseIterator<ArgumentPlaceholderIterator, PlanIteratorState>*)this);
  }

public:
   ArgumentPlaceholderIterator(
      static_context* sctx,
      const QueryLoc& loc)
    :
    NoaryBaseIterator<ArgumentPlaceholderIterator, PlanIteratorState>(sctx, loc)
  {
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const { return false; };
};


/*******************************************************************************

********************************************************************************/
class SingleDynamicFnCallIteratorState : public PlanIteratorState
{
public:
  PlanState  * thePlanState;
  PlanIter_t   thePlan;
  bool         theIsOpen;

  uint32_t     theUDFStateOffset;

  store::Iterator_t theIterator;

  SingleDynamicFnCallIteratorState();

  ~SingleDynamicFnCallIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


/*******************************************************************************
  The 1st child iterator returns the functionItem obj to invoke. The rest of
  the child iterators compute the args to pass to the invocation.
********************************************************************************/
class SingleDynamicFnCallIterator :
public NaryBaseIterator<SingleDynamicFnCallIterator, SingleDynamicFnCallIteratorState>
{
protected:
  bool theIsPartialApply;
  
public:
  SERIALIZABLE_CLASS(SingleDynamicFnCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingleDynamicFnCallIterator,
  NaryBaseIterator<SingleDynamicFnCallIterator, SingleDynamicFnCallIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  SingleDynamicFnCallIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& args,
      bool isPartialApply,
      xqtref_t coercionTargetType = NULL)
    :
    NaryBaseIterator<SingleDynamicFnCallIterator,
                     SingleDynamicFnCallIteratorState>(sctx, loc, args),
    theIsPartialApply(isPartialApply)
  {
  }

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void openImpl(PlanState& planState, uint32_t& offset);

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************

********************************************************************************/
class MultiDynamicFnCallIteratorState : public PlanIteratorState
{
public:
  PlanState      * thePlanState;
  PlanIter_t       thePlan;
  bool             theIsOpen;

  uint32_t          theUDFStateOffset;

  store::Iterator_t theIterator;

  std::unique_ptr<HashSet<zstring, HashMapZStringCmp> > theKeysSet;

public:
  MultiDynamicFnCallIteratorState();

  ~MultiDynamicFnCallIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


/*******************************************************************************
  The 1st child iterator returns the functionItem obj to invoke. The rest of
  the child iterators compute the args to pass to the invocation.
********************************************************************************/
class MultiDynamicFnCallIterator : 
public UnaryBaseIterator<MultiDynamicFnCallIterator,
                         MultiDynamicFnCallIteratorState>
{
public:
  SERIALIZABLE_CLASS(MultiDynamicFnCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MultiDynamicFnCallIterator,
  UnaryBaseIterator<MultiDynamicFnCallIterator, MultiDynamicFnCallIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  MultiDynamicFnCallIterator(
      static_context* sctx,
      const QueryLoc& loc,
      const PlanIter_t& arg)
    :
    UnaryBaseIterator<MultiDynamicFnCallIterator,
                      MultiDynamicFnCallIteratorState>(sctx, loc, arg)
  {
  }

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  zstring getNameAsString() const;

  void resetImpl(PlanState& planState) const;
};


}

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
