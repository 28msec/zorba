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

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "context/dynamic_context.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/base/noarybase.h"
#include "runtime/core/var_iterators.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/iterator.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/temp_seq.h"

#include "util/string_util.h"

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(CtxVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclareIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclareIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarIsSetIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarIsSetIterator)

SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)

SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Declaration                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

CtxVarDeclareIterator::CtxVarDeclareIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    ulong varid,
    const store::Item_t& varName,
    bool isExtern,
    bool singleItem)
  :
  NaryBaseIterator<CtxVarDeclareIterator, PlanIteratorState>(sctx, loc, args),
  theVarId(varid),
  theVarName(varName),
  theIsExternal(isExtern),
  theSingleItem(singleItem)
{
}


void CtxVarDeclareIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CtxVarDeclareIterator, PlanIteratorState>*)this);

  ar & theVarId;
  ar & theVarName;
  ar & theIsExternal;
  ar & theSingleItem;
}


bool CtxVarDeclareIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  dynamic_context* dctx = planState.theLocalDynCtx;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!theIsExternal || !dctx->exists_variable(theVarId))
  {
    dctx->declare_variable(theVarId);

    if (!theChildren.empty())
    {
      if (theSingleItem)
      {
        store::Item_t item;

        if (! consumeNext(item, theChildren[0], planState))
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(VarValMustBeSingleItem_2), theVarName));
        }

        dctx->set_variable(theVarId, theVarName, loc, item);

        if (consumeNext(item, theChildren[0], planState))
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(VarValMustBeSingleItem_2), theVarName));
        }
      }
      else
      {
        store::Iterator_t planIter = new PlanIteratorWrapper(theChildren[0], planState);

        dctx->set_variable(theVarId, theVarName, loc, planIter);
      }
    }
  }

  STACK_END(state);
}


NARY_ACCEPT(CtxVarDeclareIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Initialization/Assignment                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


void CtxVarAssignIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>*)this);

  ar & theVarId;
  ar & theVarName;
  ar & theIsLocal;
  ar & theSingleItem;
}


bool CtxVarAssignIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theSingleItem)
  {
    if (! consumeNext(item, theChild, planState))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(VarValMustBeSingleItem_2), theVarName));
    }

    if (theIsLocal)
      planState.theLocalDynCtx->set_variable(theVarId, theVarName, loc, item);
    else
      planState.theGlobalDynCtx->set_variable(theVarId, theVarName, loc, item);

    if (consumeNext(item, theChild, planState))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(VarValMustBeSingleItem_2), theVarName));
    }
  }
  else
  {
    store::Iterator_t planIter = new PlanIteratorWrapper(theChild, planState);

    if (theIsLocal)
      planState.theLocalDynCtx->set_variable(theVarId, theVarName, loc, planIter);
    else
      planState.theGlobalDynCtx->set_variable(theVarId, theVarName, loc, planIter);
  }

  STACK_END (state);
}


UNARY_ACCEPT(CtxVarAssignIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog Var Existence Check                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


void CtxVarIsSetIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NoaryBaseIterator<CtxVarIsSetIterator, PlanIteratorState>*)this);

  ar & theVarId;
  ar & theVarName;
}


bool CtxVarIsSetIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  dynamic_context* dctx = planState.theGlobalDynCtx;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, dctx->exists_variable(theVarId)),
             state);

  STACK_END(state);
}


NOARY_ACCEPT(CtxVarIsSetIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Reference                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

CtxVarState::CtxVarState()
{
}


CtxVarState::~CtxVarState()
{
  if (theSourceIter != NULL)
    theSourceIter->close();
}


void CtxVarState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theSourceIter != NULL)
    theSourceIter->reset();
}


CtxVarIterator::CtxVarIterator(
    static_context* sctx,
    const QueryLoc& loc,
    ulong varid,
    const store::Item_t& varName,
    bool isLocal)
  :
  NoaryBaseIterator<CtxVarIterator, CtxVarState>(sctx, loc),
  theVarId(varid),
  theVarName(varName),
  theIsLocal(isLocal),
  theTargetPos(0)
{
}


void CtxVarIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NoaryBaseIterator<CtxVarIterator, CtxVarState>*)this);

  ar & theVarId;
  ar & theVarName;
  ar & theIsLocal;
  ar & theTargetPos;
  ar & theTargetPosIter;
  ar & theTargetLenIter;
}


bool CtxVarIterator::setTargetPos(xs_integer v)
{
  if (theTargetPos == Integer(0) && theTargetPosIter == NULL)
  {
    theTargetPos = v;
    return true;
  }
  return false;
}


bool CtxVarIterator::setTargetPosIter(const PlanIter_t& v)
{
  if (theTargetPos == Integer(0) && theTargetPosIter == NULL)
  {
    theTargetPosIter = v;
    return true;
  }
  return false;
}


bool CtxVarIterator::setTargetLenIter(const PlanIter_t& v)
{
  if (theTargetPos == Integer(0) && theTargetLenIter == NULL)
  {
    theTargetLenIter = v;
    return true;
  }
  return false;
}


uint32_t CtxVarIterator::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  if (theTargetPosIter != NULL)
  {
    size += theTargetPosIter->getStateSizeOfSubtree() + getStateSize();

   if (theTargetLenIter != NULL)
     size += theTargetLenIter->getStateSizeOfSubtree();

    return size;
  }
  else
  {
    return size + getStateSize();
  }
}


void CtxVarIterator::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  NoaryBaseIterator<CtxVarIterator, CtxVarState>::openImpl(planState, offset);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->open(planState, offset);

    if (theTargetLenIter != NULL)
      theTargetLenIter->open(planState, offset);
  }
}


void CtxVarIterator::resetImpl(PlanState& planState) const
{
  NoaryBaseIterator<CtxVarIterator, CtxVarState>::resetImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->reset(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->reset(planState);
  }
}


void CtxVarIterator::closeImpl(PlanState& planState)
{
  NoaryBaseIterator<CtxVarIterator, CtxVarState>::closeImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->close(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->close(planState);
  }
}



bool CtxVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varSingleItem;
  store::Item_t posItem;
  store::Item_t lenItem;
  xs_integer startPos;
  xs_integer len;

  dynamic_context* dctx = (theIsLocal ?
                           planState.theLocalDynCtx :
                           planState.theGlobalDynCtx);

  CtxVarState* state;
  DEFAULT_STACK_INIT(CtxVarState, state, planState);

  if (theTargetPosIter != NULL && theTargetLenIter == NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getIntegerValue();

    dctx->get_variable(theVarId, theVarName, loc, varSingleItem, state->theTempSeq);

    if (varSingleItem != NULL)
    {
      if (startPos == Integer(1))
      {
        result.transfer(varSingleItem);
        STACK_PUSH(true, state);
      }
    }
    else if (state->theTempSeq != NULL)
    {
      if (startPos > Integer(0))
      {
        state->theTempSeq->getItem(startPos, result);
      }

      if (result)
        STACK_PUSH(true, state);
    }
    else
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(theVarName->getStringValue(), ZED(VariabledUndeclared)));
    }
  } // if (theTargetPosIter != NULL && theTargetLenIter == NULL)

  else if (theTargetPosIter != NULL && theTargetLenIter != NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getIntegerValue();

    if (!consumeNext(lenItem, theTargetLenIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    len = lenItem->getIntegerValue();

    if (startPos <= Integer(0))
    {
      len += startPos - Integer(1);
      startPos = 1;
    }

    state->theLastPos = startPos + len;
    state->thePos = startPos;

    dctx->get_variable(theVarId, theVarName, loc, varSingleItem, state->theTempSeq);

    if (varSingleItem != NULL)
    {
      if (state->thePos == Integer(1) && state->thePos < state->theLastPos)
      {
        result.transfer(varSingleItem);
        STACK_PUSH(true, state);
      }
    }
    else if (state->theTempSeq != NULL)
    {
      while (state->thePos < state->theLastPos)
      {
        state->theTempSeq->getItem(state->thePos++, result);

        if (result)
          STACK_PUSH(true, state);
        else
          break;
      }
    }
    else
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(theVarName->getStringValue(), ZED(VariabledUndeclared)));
    }
  } // if (theTargetPosIter != NULL && theTargetLenIter != NULL)

  else if (theTargetPos > Integer(0))
  {
    result = NULL;

    startPos = theTargetPos;

    dctx->get_variable(theVarId, theVarName, loc, varSingleItem, state->theTempSeq);

    if (varSingleItem != NULL)
    {
      if (startPos == Integer(1))
      {
        result.transfer(varSingleItem);
        STACK_PUSH(true, state);
      }
    }
    else if (state->theTempSeq != NULL)
    {
      if (startPos > Integer(0))
      {
        state->theTempSeq->getItem(startPos, result);
      }

      if (result)
        STACK_PUSH(true, state);
    }
    else
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(theVarName->getStringValue(), ZED(VariabledUndeclared)));
    }
  } // if (theTargetPos > 0)

  else
  {
    dctx->get_variable(theVarId, theVarName, loc, result, state->theTempSeq);

    if (result != NULL)
    {
      STACK_PUSH(true, state);
    }
    else if (state->theTempSeq != NULL)
    {
      state->theSourceIter = state->theTempSeq->getIterator();
      state->theSourceIter->open();

      while (state->theSourceIter->next(result))
      {
        STACK_PUSH(true, state);
      }

      state->theSourceIter->close();
      state->theSourceIter = NULL;
    }
    else
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(theVarName->getStringValue(), ZED(VariabledUndeclared)));
    }
	}

  STACK_END(state);
}


void CtxVarIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  if (theTargetPosIter != NULL)
    theTargetPosIter->accept(v);

  if (theTargetLenIter != NULL)
    theTargetLenIter->accept(v);

  v.endVisit(*this);
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ForVarIterator::ForVarIterator(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* name)
  :
  NoaryBaseIterator<ForVarIterator, ForVarState >(sctx, loc),
  theVarName(name)
{
}


void ForVarIterator::bind(store::Item* value, PlanState& planState)
{
  ForVarState* state;
  state = StateTraitsImpl<ForVarState>::getState(planState, theStateOffset);

  state->theValue = value;
}


bool ForVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ForVarState* state;
  DEFAULT_STACK_INIT(ForVarState, state, planState);

  if ((result = state->theValue) != NULL)
  {
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


NOARY_ACCEPT(ForVarIterator);



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  LetVarIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

LetVarState::LetVarState()
{
}


LetVarState::~LetVarState()
{
  if (theSourceIter != NULL)
    theSourceIter->close();
}


void LetVarState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theSourceIter != NULL)
    theSourceIter->reset();
}


LetVarIterator::LetVarIterator(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* name)
  :
  NoaryBaseIterator<LetVarIterator, LetVarState>(sctx, loc),
  theVarName(name),
  theTargetPos(0)
{
}


void LetVarIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<LetVarIterator, LetVarState>*)this);
  ar & theVarName;
  ar & theTargetPos;
  ar & theTargetPosIter;
  ar & theTargetLenIter;
}


bool LetVarIterator::setTargetPos(xs_integer v)
{
  if (theTargetPos == Integer(0) && theTargetPosIter == NULL)
  {
    theTargetPos = v;
    return true;
  }
  return false;
}


bool LetVarIterator::setTargetPosIter(const PlanIter_t& v)
{
  if (theTargetPos == Integer(0) && theTargetPosIter == NULL)
  {
    theTargetPosIter = v;
    return true;
  }
  return false;
}


bool LetVarIterator::setTargetLenIter(const PlanIter_t& v)
{
  if (theTargetPos == Integer(0) && theTargetLenIter == NULL)
  {
    theTargetLenIter = v;
    return true;
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::bind(store::Iterator_t& it, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theSourceIter = it;
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::bind(store::TempSeq_t& value, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theTempSeq = value;

  if (theTargetPosIter == NULL)
  {
    if (theTargetPos > Integer(0))
    {
      value->getItem(theTargetPos, state->theItem);
    }
    else
    {
      state->theSourceIter = state->theTempSeq->getIterator();
      state->theSourceIter->open();
    }
  }
}


/*******************************************************************************
  This method is used to bind a window variable.
********************************************************************************/
void LetVarIterator::bind(
    store::TempSeq_t& value,
    PlanState& planState,
    ulong startPos,
    ulong endPos)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theTempSeq = value;

  if (theTargetPosIter == NULL)
  {
    if (theTargetPos > Integer(0))
    {
      value->getItem((Integer(startPos) + theTargetPos - Integer(1)), state->theItem);
    }
    else
    {
      state->theSourceIter = state->theTempSeq->getIterator(startPos, endPos, true);
      state->theSourceIter->open();
    }
  }
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  NoaryBaseIterator<LetVarIterator, LetVarState>::openImpl(planState, offset);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->open(planState, offset);

    if (theTargetLenIter != NULL)
      theTargetLenIter->open(planState, offset);
  }
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::resetImpl(PlanState& planState) const
{
  NoaryBaseIterator<LetVarIterator, LetVarState>::resetImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->reset(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->reset(planState);
  }
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::closeImpl(PlanState& planState)
{
  NoaryBaseIterator<LetVarIterator, LetVarState>::closeImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->close(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->close(planState);
  }
}


/*******************************************************************************

********************************************************************************/
bool LetVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t posItem;
  store::Item_t lenItem;
  xs_integer startPos;
  xs_integer len;

  LetVarState* state;
  DEFAULT_STACK_INIT(LetVarState, state, planState);

  if (theTargetPosIter != NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getIntegerValue();

    if (theTargetLenIter == NULL)
    {
      if (startPos > Integer(0))
        state->theTempSeq->getItem(startPos, result);

      if (result)
        STACK_PUSH(true, state);
    }
    else
    {
      if (!consumeNext(lenItem, theTargetLenIter, planState))
      {
        ZORBA_ASSERT(false);
      }

      len = lenItem->getIntegerValue();

      if (startPos <= Integer(0))
      {
        len += startPos - Integer(1);
        startPos = 1;
      }

      state->theLastPos = startPos + len;
      state->thePos = startPos;

      while (state->thePos < state->theLastPos)
      {
        state->theTempSeq->getItem(state->thePos++, result);

        if (result)
          STACK_PUSH(true, state);
        else
          break;
      }
    }
  }
  else if (theTargetPos > Integer(0))
  {
    result = state->theItem;
    if (result)
      STACK_PUSH(true, state);
  }
  else
  {
    assert(state->theSourceIter != NULL);
    while (state->theSourceIter->next(result))
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
uint32_t LetVarIterator::getStateSizeOfSubtree() const
{
  if (theTargetPosIter != NULL)
  {
    uint32_t size = theTargetPosIter->getStateSizeOfSubtree() + getStateSize();

   if (theTargetLenIter != NULL)
     size += theTargetLenIter->getStateSizeOfSubtree();

    return size;
  }
  else
  {
    return getStateSize();
  }
}


/*******************************************************************************

********************************************************************************/
void LetVarIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  if (theTargetPosIter != NULL)
    theTargetPosIter->accept(v);

  if (theTargetLenIter != NULL)
    theTargetLenIter->accept(v);

  v.endVisit(*this);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
