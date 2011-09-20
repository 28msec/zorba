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


namespace zorba 
{

/*******************************************************************************

********************************************************************************/
class DynamicFnCallIteratorState : public PlanIteratorState
{
public:
  PlanState  * thePlanState;
  PlanIter_t   thePlan;
  bool         theIsOpen;

  uint32_t     theUDFStateOffset;

  DynamicFnCallIteratorState();

  ~DynamicFnCallIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


/*******************************************************************************
  The 1st child iterator returns the functionItem obj to invoke. The rest of
  the child iterators compute the args to pass to the invocation.
********************************************************************************/
class DynamicFnCallIterator : public NaryBaseIterator<DynamicFnCallIterator,
                                                      DynamicFnCallIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DynamicFnCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DynamicFnCallIterator,
  NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>*)this);
  }

  DynamicFnCallIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args)
    :
    NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>(sctx, loc, args)
  {
  }

  virtual ~DynamicFnCallIterator();

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
