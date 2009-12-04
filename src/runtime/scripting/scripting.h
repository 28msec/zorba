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
#ifndef ZORBA_RUNTIME_SCRIPTING_SCRIPTING_H
#define ZORBA_RUNTIME_SCRIPTING_SCRIPTING_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/util/flowctl_exception.h"


namespace zorba {

/**
 * Sequential Iterator
 * Author: Zorba Team
 */
class SequentialIterator : public NaryBaseIterator <SequentialIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SequentialIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SequentialIterator,
    NaryBaseIterator <SequentialIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <SequentialIterator, PlanIteratorState>*)this);
  }

  SequentialIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <SequentialIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~SequentialIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Loop Iterator
 * Author: Zorba Team
 */
class LoopIterator : public NaryBaseIterator <LoopIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LoopIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LoopIterator,
    NaryBaseIterator <LoopIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <LoopIterator, PlanIteratorState>*)this);
  }

  LoopIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <LoopIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~LoopIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * FlowCtlIterator
 * Author: Zorba Team
 */
class FlowCtlIterator : public NaryBaseIterator <FlowCtlIterator, PlanIteratorState>
{ 
protected:
  enum FlowCtlException::action act; //
public:
  SERIALIZABLE_CLASS(FlowCtlIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FlowCtlIterator,
    NaryBaseIterator <FlowCtlIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

  FlowCtlIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren,
    enum FlowCtlException::action aAction)
    : NaryBaseIterator <FlowCtlIterator, PlanIteratorState>
    (sctx, loc, aChildren),
    act(aAction) {}

  virtual ~FlowCtlIterator();

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
