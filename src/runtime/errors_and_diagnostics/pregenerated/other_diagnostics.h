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
#ifndef ZORBA_RUNTIME_ERRORS_AND_DIAGNOSTICS_OTHER_DIAGNOSTICS_H
#define ZORBA_RUNTIME_ERRORS_AND_DIAGNOSTICS_OTHER_DIAGNOSTICS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * op-zorba:read-line
 * Author: Zorba Team
 */
class ReadLineIterator : public NaryBaseIterator<ReadLineIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ReadLineIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ReadLineIterator,
    NaryBaseIterator<ReadLineIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ReadLineIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ReadLineIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ReadLineIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op-zorba:print
 * Author: Zorba Team
 */
class PrintIterator : public NaryBaseIterator<PrintIterator, PlanIteratorState>
{ 
protected:
  bool thePrintToConsole; //
public:
  SERIALIZABLE_CLASS(PrintIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrintIterator,
    NaryBaseIterator<PrintIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  PrintIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool aPrintToConsole = true)
    : 
    NaryBaseIterator<PrintIterator, PlanIteratorState>(sctx, loc, children),
    thePrintToConsole(aPrintToConsole)
  {}

  virtual ~PrintIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

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
