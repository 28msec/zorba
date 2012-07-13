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
#ifndef ZORBA_RUNTIME_ERRORS_AND_DIAGNOSTICS_ERRORS_AND_DIAGNOSTICS_H
#define ZORBA_RUNTIME_ERRORS_AND_DIAGNOSTICS_ERRORS_AND_DIAGNOSTICS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:error
 * Author: Zorba Team
 */
class ErrorIterator : public NaryBaseIterator<ErrorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ErrorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ErrorIterator,
    NaryBaseIterator<ErrorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ErrorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ErrorIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ErrorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:trace
 * Author: Zorba Team
 */
class TraceIteratorState : public PlanIteratorState
{
public:
  store::Item_t theTagItem; //
  uint32_t theIndex; //
  std::ostream* theOS; //
  std::auto_ptr<serializer> theSerializer; //

  TraceIteratorState();

  ~TraceIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class TraceIterator : public NaryBaseIterator<TraceIterator, TraceIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TraceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TraceIterator,
    NaryBaseIterator<TraceIterator, TraceIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  TraceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TraceIterator, TraceIteratorState>(sctx, loc, children)
  {}

  virtual ~TraceIterator();

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
