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
#ifndef ZORBA_RUNTIME_CORE_DUMMY_ITERATOR_H
#define ZORBA_RUNTIME_CORE_DUMMY_ITERATOR_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      This is just a dummy iterator, which calls
 *      its children. This iterator is used to wrap
 *      inlined expressions to be able to add the call
 *      to the call stack in case of an exception.
 *    
 * Author: Zorba Team
 */
class DummyIterator : public NaryBaseIterator<DummyIterator, PlanIteratorState>
{ 
protected:
  store::Item_t theFunctionName; //stores the name of the function it substitutes
public:
  SERIALIZABLE_CLASS(DummyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DummyIterator,
    NaryBaseIterator<DummyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DummyIterator, PlanIteratorState>*)this);

    ar & theFunctionName;
  }

  DummyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DummyIterator, PlanIteratorState>(sctx, loc, children),
    theFunctionName()
  {}

  virtual ~DummyIterator();

public:
  void setFunctionName(store::Item_t aFunctionName);
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
