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

#include "zorbaerrors/Assert.h"

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

SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarDeclIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarAssignIterator)

SERIALIZABLE_CLASS_VERSIONS(CtxVarExistsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CtxVarExistsIterator)

SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ForVarIterator)

SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LetVarIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Declaration                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarDeclIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME (varName, 0);

  planState.theDynamicContext->declare_variable(varName->getStringValue().str());

  STACK_END (state);
}


NARY_ACCEPT(CtxVarDeclIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog and Block-Local Var Initialization/Assignment                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarAssignIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t item;
  zstring varNameStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME(varName, 0);

  varName->getStringValue2(varNameStr);

	if (equals(varNameStr, ".", 1)) 
  {
    if (! CONSUME (item, 1))
			ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "context item must be a single item");

    planState.theDynamicContext->set_context_item(item, 0);

    if (CONSUME (item, 1))
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "context item must be a single item");
  }
  else if (theSingleItem)
  {
    if (! CONSUME (item, 1))
			ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "variable value must be a single item");

    planState.theDynamicContext->set_variable(varNameStr.str(), item);

    if (CONSUME (item, 1))
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "variable value must be a single item");
  }
  else
  {
    store::Iterator_t planIter = new PlanIteratorWrapper(theChildren[1], planState);
    planState.theDynamicContext->set_variable(varNameStr.str(), planIter);
  }

  STACK_END (state);
}


NARY_ACCEPT(CtxVarAssignIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog Var Existence Check                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool CtxVarExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t varItem;
  store::Iterator_t varIter;
  dynamic_context* dctx = planState.theDynamicContext;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  CONSUME(varName, 0);

	if(equals(varName->getStringValue(), ".", 1)) 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, dctx->context_item() != NULL),
               state);
	}
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, dctx->exists_variable(varName)),
               state);
  }
  STACK_END (state);
}


NARY_ACCEPT(CtxVarExistsIterator);


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
    PlanIter_t& varnameIter)
  :
  UnaryBaseIterator<CtxVarIterator, CtxVarState>(sctx, loc, varnameIter),
  theTargetPos(0)
{
}


void CtxVarIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (UnaryBaseIterator<CtxVarIterator, CtxVarState>*)this);
  ar & theVarName;
  ar & theTargetPos;
  ar & theTargetPosIter;
  ar & theTargetLenIter;
}


bool CtxVarIterator::setTargetPos(xs_long v) 
{
  if (theTargetPos == 0 && theTargetPosIter == NULL)
  {
    theTargetPos = v;
    return true;
  }
  return false;
}


bool CtxVarIterator::setTargetPosIter(const PlanIter_t& v) 
{
  if (theTargetPos == 0 && theTargetPosIter == NULL)
  {
    theTargetPosIter = v; 
    return true;
  }
  return false;
}


bool CtxVarIterator::setTargetLenIter(const PlanIter_t& v) 
{
  if (theTargetPos == 0 && theTargetLenIter == NULL)
  {
    theTargetLenIter = v; 
    return true;
  }
  return false;
}


void CtxVarIterator::openImpl(
    PlanState& planState,
    uint32_t& offset)
{
  UnaryBaseIterator<CtxVarIterator, CtxVarState>::openImpl(planState, offset);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->open(planState, offset);

    if (theTargetLenIter != NULL)
      theTargetLenIter->open(planState, offset);
  }
}


void CtxVarIterator::resetImpl(PlanState& planState) const
{
  UnaryBaseIterator<CtxVarIterator, CtxVarState>::resetImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->reset(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->reset(planState);
  }
}


void CtxVarIterator::closeImpl(PlanState& planState)
{
  UnaryBaseIterator<CtxVarIterator, CtxVarState>::closeImpl(planState);

  if (theTargetPosIter != NULL)
  {
    theTargetPosIter->close(planState);

    if (theTargetLenIter != NULL)
      theTargetLenIter->close(planState);
  }
}



bool CtxVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t varName;
  store::Item_t varSingleItem;
  store::Item_t posItem;
  store::Item_t lenItem;
  xs_long startPos;
  xs_long len;

  CtxVarState* state;
  DEFAULT_STACK_INIT(CtxVarState, state, planState);

  consumeNext(varName, theChild, planState);

  // looking for context item?
	if(equals(varName->getStringValue(), ".", 1)) 
  {  
    result = planState.theDynamicContext->context_item();
		if(result == NULL)
			ZORBA_ERROR_LOC_PARAM(XPDY0002, loc, "context item", "");

		STACK_PUSH(true, state);
	}
  else if (theTargetPosIter != NULL && theTargetLenIter == NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getLongValue();

    planState.theDynamicContext->get_variable(varName,
                                              loc,
                                              varSingleItem,
                                              state->theTempSeq);

    if (varSingleItem != NULL)
    {
      if (startPos == 1)
      {
        result.transfer(varSingleItem);
        STACK_PUSH(true, state);
      }
    }
    else if (state->theTempSeq != NULL)
    {
      if (startPos > 0)
      {
        state->theTempSeq->getItem(startPos, result);
      }
      
      if (result)
        STACK_PUSH(true, state);
    }
    else
    {
      std::string var_key = varName->getStringValue().str();
			ZORBA_ERROR_LOC_PARAM(XPDY0002, loc, var_key.substr(var_key.find(":") + 1), "");
    }
  } // if (theTargetPosIter != NULL && theTargetLenIter == NULL)

  else if (theTargetPosIter != NULL && theTargetLenIter != NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getLongValue();

    if (!consumeNext(lenItem, theTargetLenIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    len = lenItem->getLongValue();

    if (startPos <= 0)
    {
      len += startPos - 1;
      startPos = 1;
    }

    state->theLastPos = startPos + len;
    state->thePos = startPos;

    planState.theDynamicContext->get_variable(varName,
                                              loc,
                                              varSingleItem,
                                              state->theTempSeq);
    if (varSingleItem != NULL)
    {
      if (state->thePos == 1 && state->thePos < state->theLastPos)
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
      std::string var_key = varName->getStringValue().str();
			ZORBA_ERROR_LOC_PARAM(XPDY0002, loc, var_key.substr(var_key.find(":") + 1), "");
    }
  } // if (theTargetPosIter != NULL && theTargetLenIter != NULL)

  else
  {
    planState.theDynamicContext->get_variable(varName,
                                              loc,
                                              result,
                                              state->theTempSeq);
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
      std::string var_key = varName->getStringValue().str();
			ZORBA_ERROR_LOC_PARAM(XPDY0002, loc, var_key.substr(var_key.find(":") + 1), "");
    }
	}

  STACK_END (state);
}


uint32_t CtxVarIterator::getStateSizeOfSubtree() const
{
  uint32_t size = theChild->getStateSizeOfSubtree();

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


void CtxVarIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

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


bool LetVarIterator::setTargetPos(xs_long v) 
{
  if (theTargetPos == 0 && theTargetPosIter == NULL)
  {
    theTargetPos = v;
    return true;
  }
  return false;
}


bool LetVarIterator::setTargetPosIter(const PlanIter_t& v) 
{
  if (theTargetPos == 0 && theTargetPosIter == NULL)
  {
    theTargetPosIter = v; 
    return true;
  }
  return false;
}


bool LetVarIterator::setTargetLenIter(const PlanIter_t& v) 
{
  if (theTargetPos == 0 && theTargetLenIter == NULL)
  {
    theTargetLenIter = v; 
    return true;
  }
  return false;
}


void LetVarIterator::bind(store::Iterator_t& it, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theSourceIter = it;
}


void LetVarIterator::bind(store::TempSeq_t& value, PlanState& planState)
{
  LetVarState* state;
  state = StateTraitsImpl<LetVarState>::getState(planState, theStateOffset);

  state->theTempSeq = value;

  if (theTargetPosIter == NULL)
  {
    if (theTargetPos > 0)
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
    if (theTargetPos > 0)
    {
      value->getItem(startPos + theTargetPos - 1, state->theItem);
    }
    else
    {
      state->theSourceIter = state->theTempSeq->getIterator(startPos, endPos, true);
      state->theSourceIter->open();
    }
  }
}


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


bool LetVarIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t posItem;
  store::Item_t lenItem;
  xs_long startPos;
  xs_long len;

  LetVarState* state;
  DEFAULT_STACK_INIT(LetVarState, state, planState);

  if (theTargetPosIter != NULL)
  {
    result = NULL;

    if (!consumeNext(posItem, theTargetPosIter, planState))
    {
      ZORBA_ASSERT(false);
    }

    startPos = posItem->getLongValue();

    if (theTargetLenIter == NULL)
    {
      if (startPos > 0)
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

      len = lenItem->getLongValue();

      if (startPos <= 0)
      {
        len += startPos - 1;
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
  else if (theTargetPos > 0)
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


void LetVarIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  if (theTargetPosIter != NULL)
    theTargetPosIter->accept(v);

  if (theTargetLenIter != NULL)
    theTargetLenIter->accept(v);

  v.endVisit(*this);
}


} /* namespace zorba */
