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
#pragma once
#ifndef ZORBA_RUNTIME_SCRIPTING_SCRIPTING_H
#define ZORBA_RUNTIME_SCRIPTING_SCRIPTING_H

#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/base/noarybase.h"
#include "runtime/base/unarybase.h"


namespace zorba 
{

/*******************************************************************************

********************************************************************************/
class SequentialIterator : public NaryBaseIterator<SequentialIterator,
                                                   PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SequentialIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SequentialIterator,
  NaryBaseIterator<SequentialIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

  SequentialIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children);

  ~SequentialIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************

********************************************************************************/
class LoopIterator : public UnaryBaseIterator<LoopIterator, PlanIteratorState>
{
public:
  SERIALIZABLE_CLASS(LoopIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LoopIterator,
  UnaryBaseIterator<LoopIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

  LoopIterator(
    static_context* sctx,
    const QueryLoc& loc,
    const PlanIter_t& child);

  ~LoopIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************

********************************************************************************/
class ExitIterator : public UnaryBaseIterator<ExitIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ExitIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ExitIterator,
  UnaryBaseIterator<ExitIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  ExitIterator(
      static_context* sctx,
      const QueryLoc& loc,
      const PlanIter_t& child);

  ~ExitIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
  theExitValue :
********************************************************************************/
class ExitCatcherIteratorState : public PlanIteratorState 
{
public:
  store::Iterator_t theExitValue;

  ExitCatcherIteratorState();

  ~ExitCatcherIteratorState();

  void reset(PlanState& planState);
};


class ExitCatcherIterator : public UnaryBaseIterator<ExitCatcherIterator, 
                                                     ExitCatcherIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ExitCatcherIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ExitCatcherIterator,
  UnaryBaseIterator<ExitCatcherIterator, ExitCatcherIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  ExitCatcherIterator(
      static_context* sctx,
      const QueryLoc& loc,
      const PlanIter_t& child);

  ~ExitCatcherIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************

********************************************************************************/
class FlowCtlIterator : public NoaryBaseIterator<FlowCtlIterator, PlanIteratorState>
{ 
protected:
  enum FlowCtlException::action act;

public:
  SERIALIZABLE_CLASS(FlowCtlIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FlowCtlIterator,
  NoaryBaseIterator<FlowCtlIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

  FlowCtlIterator(
      static_context* sctx,
      const QueryLoc& loc,
      enum FlowCtlException::action aAction);

  ~FlowCtlIterator();

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
/* vim:set et sw=2 ts=2: */
