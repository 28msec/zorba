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
 #include "stdafx.h"

#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/scripting/scripting.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/flowctl_exception.h"

#include "system/globalenv.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)

SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)

SERIALIZABLE_CLASS_VERSIONS(LoopIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LoopIterator)

SERIALIZABLE_CLASS_VERSIONS(ExitIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ExitIterator)

SERIALIZABLE_CLASS_VERSIONS(ExitCatcherIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ExitCatcherIterator)



/*******************************************************************************

********************************************************************************/
SequentialIterator::SequentialIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<SequentialIterator, PlanIteratorState>(sctx, loc, children)
{
}


SequentialIterator::~SequentialIterator() 
{
}


void SequentialIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SequentialIterator, PlanIteratorState>*)this);
}


void SequentialIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


bool
SequentialIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ulong i = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for (; i < (ulong)theChildren.size(); ++i) 
  {
    while (consumeNext(result, theChildren[i].getp(), planState))
    {
      if (i == (ulong)theChildren.size() - 1)
      {
        STACK_PUSH(true, state);
        i = (ulong)theChildren.size() - 1;
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
LoopIterator::LoopIterator(
    static_context* sctx,
    const QueryLoc& loc,
    const PlanIter_t& child)
  : 
  UnaryBaseIterator<LoopIterator, PlanIteratorState>(sctx, loc, child)
{
}


LoopIterator::~LoopIterator() 
{
}


void LoopIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<LoopIterator, PlanIteratorState>*)this);
}


bool
LoopIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  bool lBreakLoop = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (!lBreakLoop) 
  {
    try 
    {
      while (! consumeNext(result, theChild, planState)) 
      {
        // bugfix: removed a goto in case
        // planState.theHasToQuit was true
        // this should not be needed because
        // the FlowCtlException::INTERRUPT 
        // exception is rethrown below
        theChild->reset(planState);
      }
    } 
    catch (FlowCtlException &e)
    {
      switch (e.act)
      {
      case FlowCtlException::BREAK:
        lBreakLoop = true;
        break;
      case FlowCtlException::CONTINUE:
        theChild->reset(planState);
        continue;
      default:
        throw;
      }
    }

    if (!lBreakLoop) 
    {
      STACK_PUSH(true, state);
    } 
  }

  STACK_END(state);
}


UNARY_ACCEPT(LoopIterator)


/*******************************************************************************

********************************************************************************/
ExitIterator::ExitIterator(
    static_context* sctx,
    const QueryLoc& loc,
    const PlanIter_t& child)
  : 
  UnaryBaseIterator<ExitIterator, PlanIteratorState>(sctx, loc, child)
{
}


ExitIterator::~ExitIterator() 
{
}


void ExitIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<ExitIterator, PlanIteratorState >*)this);
}


bool ExitIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  throw ExitException(new PlanIteratorWrapper(theChild, planState));
    
  STACK_END(state);
}


UNARY_ACCEPT(ExitIterator)


/*******************************************************************************

********************************************************************************/
ExitCatcherIteratorState::ExitCatcherIteratorState()
{
}


ExitCatcherIteratorState::~ExitCatcherIteratorState()
{
}


void ExitCatcherIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theExitValue)
    theExitValue->reset();
}


ExitCatcherIterator::ExitCatcherIterator(
    static_context* sctx,
    const QueryLoc& loc,
    const PlanIter_t& child)
  : 
  UnaryBaseIterator<ExitCatcherIterator, ExitCatcherIteratorState>(sctx, loc, child)
{
}


ExitCatcherIterator::~ExitCatcherIterator() 
{
}


void ExitCatcherIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<ExitCatcherIterator, ExitCatcherIteratorState >*)this);
}


bool ExitCatcherIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  ExitCatcherIteratorState* state;
  DEFAULT_STACK_INIT(ExitCatcherIteratorState, state, planState);

  for (;;)
  {
    bool success;
    try
    {
      success = consumeNext(result, theChild, planState);
    }
    catch (ExitException& e)
    {
      state->theExitValue = e.val;
      success = false;
    }

    if (success)
    {
      STACK_PUSH(true, state);
    }
    else
    {
      break;
    }
  }
  
  if (state->theExitValue != NULL)
  {
    while (state->theExitValue->next(result))
    {
      STACK_PUSH(true, state);
    }
  }
  
  STACK_END(state);
}


UNARY_ACCEPT(ExitCatcherIterator)


/*******************************************************************************

********************************************************************************/
FlowCtlIterator::FlowCtlIterator(
    static_context* sctx,
    const QueryLoc& loc,
    enum FlowCtlException::action aAction)
  : 
  NoaryBaseIterator<FlowCtlIterator, PlanIteratorState>(sctx, loc),
  act(aAction)
{
}


FlowCtlIterator::~FlowCtlIterator() 
{
}


void FlowCtlIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NoaryBaseIterator<FlowCtlIterator, PlanIteratorState >*)this);

  SERIALIZE_ENUM(enum FlowCtlException::action, act);
}


void FlowCtlIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);
  v.endVisit(*this);
}


bool FlowCtlIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  throw FlowCtlException(act);
    
  STACK_END(state);
}



}


/* vim:set et sw=2 ts=2: */
