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
#ifndef ZORBA_RUNTIME_DEBUG_DEBUG_H
#define ZORBA_RUNTIME_DEBUG_DEBUG_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

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

  TraceIteratorState();

  ~TraceIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class TraceIterator : public NaryBaseIterator <TraceIterator, TraceIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TraceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TraceIterator,
    NaryBaseIterator <TraceIterator, TraceIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <TraceIterator, TraceIteratorState>*)this);
  }

  TraceIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <TraceIterator, TraceIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~TraceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op-zorba:read-line
 * Author: Zorba Team
 */
class ReadLineIterator : public NaryBaseIterator <ReadLineIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ReadLineIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ReadLineIterator,
    NaryBaseIterator <ReadLineIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ReadLineIterator, PlanIteratorState>*)this);
  }

  ReadLineIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ReadLineIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ReadLineIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op-zorba:print
 * Author: Zorba Team
 */
class PrintIterator : public NaryBaseIterator <PrintIterator, PlanIteratorState>
{ 
protected:
  bool thePrintToConsole; //
public:
  SERIALIZABLE_CLASS(PrintIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrintIterator,
    NaryBaseIterator <PrintIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <PrintIterator, PlanIteratorState>*)this);

    ar & thePrintToConsole;
  }

  PrintIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren,
    bool aPrintToConsole = true)
    : NaryBaseIterator <PrintIterator, PlanIteratorState>
    (sctx, loc, aChildren),
    thePrintToConsole(aPrintToConsole) {}

  virtual ~PrintIterator();

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
