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

#include "diagnostics/util_macros.h"

#include "runtime/hof/dynamic_fncall_iterator.h"
#include "runtime/hof/function_item.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "types/root_typemanager.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "zorbatypes/integer.h"

#include "system/globalenv.h"


namespace zorba
{


SERIALIZABLE_CLASS_VERSIONS(ArgumentPlaceholderIterator)

NOARY_ACCEPT(ArgumentPlaceholderIterator)

SERIALIZABLE_CLASS_VERSIONS(SingleDynamicFnCallIterator)
DEF_GET_NAME_AS_STRING(SingleDynamicFnCallIterator)

SERIALIZABLE_CLASS_VERSIONS(MultiDynamicFnCallIterator)
DEF_GET_NAME_AS_STRING(MultiDynamicFnCallIterator)


/*******************************************************************************

********************************************************************************/
SingleDynamicFnCallIteratorState::SingleDynamicFnCallIteratorState()
{
}


/*******************************************************************************

********************************************************************************/
SingleDynamicFnCallIteratorState::~SingleDynamicFnCallIteratorState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


/*******************************************************************************

********************************************************************************/
void SingleDynamicFnCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


/*******************************************************************************

********************************************************************************/
void SingleDynamicFnCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen)
  {
    thePlan->close(planState);
    theIsOpen = false;
  }
}


/*******************************************************************************

********************************************************************************/
void SingleDynamicFnCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SingleDynamicFnCallIterator,
                     SingleDynamicFnCallIteratorState>*)this);

  ar & theIsPartialApply;
}


/*******************************************************************************

********************************************************************************/
uint32_t SingleDynamicFnCallIterator::getStateSizeOfSubtree() const
{
  uint32_t size =
  NaryBaseIterator<SingleDynamicFnCallIterator, SingleDynamicFnCallIteratorState>::
  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


/*******************************************************************************

********************************************************************************/
void SingleDynamicFnCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<SingleDynamicFnCallIteratorState>::
  createState(planState, theStateOffset, offset);

  StateTraitsImpl<SingleDynamicFnCallIteratorState>::
  initState(planState, theStateOffset);

  SingleDynamicFnCallIteratorState* state = 
  StateTraitsImpl<SingleDynamicFnCallIteratorState>::
  getState(planState, theStateOffset);

  state->theUDFStateOffset = offset;

  offset += sizeof(UDFunctionCallIteratorState);

  std::vector<PlanIter_t>::iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->open(planState, offset);
  }
}


/*******************************************************************************

********************************************************************************/
bool SingleDynamicFnCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t targetItem;
  FunctionItem* fnItem;
  store::Item_t selectorItem1;
  store::Item_t selectorItem2;
  store::Item_t selectorItem3;

  SingleDynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(SingleDynamicFnCallIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  // otherwise XPTY0004 is raised
  if (!consumeNext(targetItem, theChildren[0], planState) || targetItem == NULL)
  {
    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23),
                 "empty-sequence()",
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  if (targetItem->isFunction())
  {
    if (consumeNext(item, theChildren[0], planState))
    {
      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoMultiSeqTypePromotion_2),
                   GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
    }

    fnItem = static_cast<FunctionItem*>(targetItem.getp());

    if (theChildren.size() - 1 != fnItem->getArity())
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS("dynamic function invoked with incorrect number of arguments"));
    }

    if (theIsPartialApply)
    {
      fnItem = new FunctionItem(*fnItem);

      for (csize i = 1, pos = 0; i < theChildren.size(); ++i)
      {
        if (dynamic_cast<ArgumentPlaceholderIterator*>(theChildren[i].getp()) == NULL)
        {
          // The argument needs to be materialized only for local vars and only
          // if the function item is returned and used outside of the current
          // function. It might be impossible to determine if the partially
          // applied function item will be used outside of the current function,
          // so it is quite probable that it always needs to be materialized.          
          std::vector<store::Item_t> argValues;
          store::Item_t tempItem;

          while (consumeNext(tempItem, theChildren[i], planState))
            argValues.push_back(tempItem);

          store::TempSeq_t argSeq = GENV_STORE.createTempSeq(argValues);
          store::Iterator_t argSeqIter = argSeq->getIterator();
          PlanIter_t value = new PlanStateIteratorWrapper(argSeqIter);
                    
          fnItem->setArgumentValue(pos, value);
        }
        else
        {
          ++pos;
        }
      }

      result = fnItem;
      STACK_PUSH(true, state);
    }
    else
    {
      state->thePlan = fnItem->getImplementation(theChildren, planState.theCompilerCB);
      
      // must be opened after vars and params are set
      state->thePlan->open(planState, state->theUDFStateOffset);
      state->theIsOpen = true;

      while (consumeNext(result, state->thePlan, planState))
      {
        STACK_PUSH(true, state);
      }

      // Need to close here early in case the plan is completely consumed.
      // Otherwise, the plan would still be opened if destroyed from the
      // state's destructor.
      state->thePlan->close(planState);
      state->theIsOpen = false;
    } // if (!theIsPartialApply)
  } // if (targetItem->isFunction())

  else if (targetItem->isJSONItem())
  {
    if (theChildren.size() > 2)
    {
      RAISE_ERROR_NO_PARAMS(jerr::JNTY0018, loc);
    }
    else if (theChildren.size() == 2)
    {
      if (consumeNext(selectorItem1, theChildren[1], planState))
      {
        if (consumeNext(item, theChildren[1], planState))
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(NoSeqCastToTypeWithQuantOneOrQuestion)));
        }

        // Atomize the selector item
        switch (selectorItem1->getKind())
        {
        case store::Item::ATOMIC:
        {
          selectorItem2.transfer(selectorItem1);
          break;
        }
        case store::Item::NODE:
        {
          store::Iterator_t iter;
          selectorItem1->getTypedValue(selectorItem2, iter);

          if (iter != NULL && iter->next(selectorItem2))
          {
            if (iter->next(item))
            {
              RAISE_ERROR(err::XPTY0004, loc,
              ERROR_PARAMS(ZED(NoSeqCastToTypeWithQuantOneOrQuestion)));
            }
          }

          break;
        }
        case store::Item::OBJECT:
        {
          RAISE_ERROR(jerr::JNTY0004, loc, ERROR_PARAMS("object"));
        }
        case store::Item::ARRAY:
        {
          RAISE_ERROR(jerr::JNTY0004, loc, ERROR_PARAMS("array"));
        }
        case store::Item::FUNCTION:
        {
          store::Item_t fnName = selectorItem1->getFunctionName();
          RAISE_ERROR(err::FOTY0013, loc, 
          ERROR_PARAMS(fnName.getp() ?
                       result->getFunctionName()->getStringValue() :
                       zstring("???")));
        }
        default:
        {
          ZORBA_ASSERT(false);
        }
        }
        
        if (selectorItem2 != NULL)
        {
          if (targetItem->isObject())
          {
            GenericCast::castToBuiltinAtomic(selectorItem3,
                                             selectorItem2,
                                             store::XS_STRING,
                                             NULL,
                                             loc);
        
            result = targetItem->getObjectValue(selectorItem3);
          }
          else
          {
            GenericCast::castToBuiltinAtomic(selectorItem3,
                                             selectorItem2,
                                             store::XS_INTEGER,
                                             NULL,
                                             loc);

            result = targetItem->getArrayValue(selectorItem3->getIntegerValue());
          }

          STACK_PUSH(result != NULL, state);
        }
      } // there is a selector item
    } // 1 argument 
    else // no arguments
    {
      if (targetItem->isObject())
        state->theIterator = targetItem->getObjectKeys();
      else
        state->theIterator = targetItem->getArrayValues();

      state->theIterator->open();

      while (state->theIterator->next(result))
      {
        STACK_PUSH(true, state);
      }

      state->theIterator->close();
    }
  }
#if 0
  else if (theSctx->language_kind() == StaticContextConsts::language_kind_xquery)
  {
    xqtref_t type = theSctx->get_typemanager()->create_value_type(targetItem);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23),
                 type->toSchemaString(),
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }
#endif

  STACK_END(state);
};


/*******************************************************************************

********************************************************************************/
NARY_ACCEPT(SingleDynamicFnCallIterator)


/*******************************************************************************

********************************************************************************/
MultiDynamicFnCallIteratorState::MultiDynamicFnCallIteratorState()
{
}


/*******************************************************************************

********************************************************************************/
MultiDynamicFnCallIteratorState::~MultiDynamicFnCallIteratorState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


/*******************************************************************************

********************************************************************************/
void MultiDynamicFnCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


/*******************************************************************************

********************************************************************************/
void MultiDynamicFnCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theIsOpen)
  {
    thePlan->reset(planState);
  }

  if (theKeysSet.get())
  {
    theKeysSet->clear();
  }
}


/*******************************************************************************

********************************************************************************/
void MultiDynamicFnCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<MultiDynamicFnCallIterator, MultiDynamicFnCallIteratorState>*)this);
}


/*******************************************************************************

********************************************************************************/
uint32_t MultiDynamicFnCallIterator::getStateSizeOfSubtree() const
{
  uint32_t size =
  UnaryBaseIterator<MultiDynamicFnCallIterator, MultiDynamicFnCallIteratorState>::
  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


/*******************************************************************************

********************************************************************************/
void MultiDynamicFnCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<MultiDynamicFnCallIteratorState>::
  createState(planState, theStateOffset, offset);

  StateTraitsImpl<MultiDynamicFnCallIteratorState>::
  initState(planState, theStateOffset);

  MultiDynamicFnCallIteratorState* state = 
  StateTraitsImpl<MultiDynamicFnCallIteratorState>::
  getState(planState, theStateOffset);

  state->theUDFStateOffset = offset;

  offset += sizeof(UDFunctionCallIteratorState);

  theChild->open(planState, offset);
}


/*******************************************************************************

********************************************************************************/
void MultiDynamicFnCallIterator::resetImpl(PlanState& planState) const
{
  MultiDynamicFnCallIteratorState* state = 
  StateTraitsImpl<MultiDynamicFnCallIteratorState>::
  getState(planState, theStateOffset);
  
  if (state->theIsOpen)
  {
    state->thePlan->close(planState);
    state->theIsOpen = false;
  }
  
  UnaryBaseIterator<MultiDynamicFnCallIterator, MultiDynamicFnCallIteratorState>::
  resetImpl(planState);
}


/*******************************************************************************

********************************************************************************/
bool MultiDynamicFnCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t targetItem;
  FunctionItem* fnItem;
  zstring key;

  MultiDynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(MultiDynamicFnCallIteratorState, state, planState);

  while (consumeNext(targetItem, theChild, planState))
  {
    if (targetItem->isFunction())
    {
      fnItem = static_cast<FunctionItem*>(targetItem.getp());

      if (fnItem->getArity() != 0)
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS("dynamic function invoked with incorrect number of arguments"));
      }

      state->thePlan = fnItem->getImplementation(planState.theCompilerCB);
      
      // must be opened after vars and params are set
      state->thePlan->open(planState, state->theUDFStateOffset);
      state->theIsOpen = true;

      while (consumeNext(result, state->thePlan, planState))
      {
        STACK_PUSH(true, state);
      }

      // Need to close here early in case the plan is completely consumed.
      // Otherwise, the plan would still be opened if destroyed from the
      // state's destructor.
      state->thePlan->close(planState);
      state->theIsOpen = false;
    } // if (targetItem->isFunction())

    else if (targetItem->isJSONItem())
    {
      if (targetItem->isObject())
      {
        if (!state->theKeysSet.get())
          state->theKeysSet.reset(new HashSet<zstring, HashMapZStringCmp>(64, false));

        state->theIterator = targetItem->getObjectKeys();

        state->theIterator->open();

        while (state->theIterator->next(result))
        {
          key = result->getStringValue();

          if (!state->theKeysSet->exists(key))
          {
            state->theKeysSet->insert(key);
            STACK_PUSH(true, state);
          }
        }
      }
      else
      {
        state->theIterator = targetItem->getArrayValues();

        state->theIterator->open();

        while (state->theIterator->next(result))
        {
          STACK_PUSH(true, state);
        }
      }

      state->theIterator->close();
    } // jsoniq item
#if 0
    else if (theSctx->language_kind() == StaticContextConsts::language_kind_xquery)
    {
      xqtref_t type = theSctx->get_typemanager()->create_value_type(targetItem);

      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23),
                   type->toSchemaString(),
                   GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
    }
#endif
  }

  STACK_END(state);
};


/*******************************************************************************

********************************************************************************/
UNARY_ACCEPT(MultiDynamicFnCallIterator)


}//zorba namespace
/* vim:set et sw=2 ts=2: */
