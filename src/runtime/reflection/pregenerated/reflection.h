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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_REFLECTION_REFLECTION_H
#define ZORBA_RUNTIME_REFLECTION_REFLECTION_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      reflection:invoke
 *    
 * Author: Zorba Team
 */
class InvokeIteratorState : public PlanIteratorState
{
public:
  PlanIter_t thePlan; //the function's plan
  PlanState* thePlanState; //the function's plan state
  store::Iterator_t theExitValue; //the exit value
  uint32_t theUDFStateOffset; //the UDF state offset

  InvokeIteratorState();

  ~InvokeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InvokeIterator : public NaryBaseIterator<InvokeIterator, InvokeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InvokeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InvokeIterator,
    NaryBaseIterator<InvokeIterator, InvokeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InvokeIterator, InvokeIteratorState>*)this);
  }

  InvokeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InvokeIterator, InvokeIteratorState>(sctx, loc, children)
  {}

  virtual ~InvokeIterator();

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
