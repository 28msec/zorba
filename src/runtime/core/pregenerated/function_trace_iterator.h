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
#ifndef ZORBA_RUNTIME_CORE_FUNCTION_TRACE_ITERATOR_H
#define ZORBA_RUNTIME_CORE_FUNCTION_TRACE_ITERATOR_H


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
class FunctionTraceIterator : public NaryBaseIterator<FunctionTraceIterator, PlanIteratorState>
{ 
protected:
  store::Item_t theFunctionName; //stores the name of the function it substitutes
  QueryLoc theFunctionLocation; //stores the location of the function call
  QueryLoc theFunctionCallLocation; //stores the location of the function which it calls
  unsigned int theFunctionArity; //stores the arity of the function being called
public:
  SERIALIZABLE_CLASS(FunctionTraceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionTraceIterator,
    NaryBaseIterator<FunctionTraceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionTraceIterator, PlanIteratorState>*)this);

    ar & theFunctionName;
    ar & theFunctionLocation;
    ar & theFunctionCallLocation;
    ar & theFunctionArity;
  }

  FunctionTraceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionTraceIterator, PlanIteratorState>(sctx, loc, children),
    theFunctionName(),
    theFunctionLocation(),
    theFunctionCallLocation(),
    theFunctionArity()
  {}

  virtual ~FunctionTraceIterator();

public:
  void setFunctionName(const store::Item_t& aFunctionName);
  void setFunctionCallLocation(const QueryLoc& aFunctionLocation);
  void setFunctionLocation(const QueryLoc& aFunctionLocation);
  void setFunctionArity(unsigned int arity);
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
