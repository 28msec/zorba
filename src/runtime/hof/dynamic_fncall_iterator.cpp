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

SERIALIZABLE_CLASS_VERSIONS(DynamicFnCallIterator)


/*******************************************************************************

********************************************************************************/
DynamicFnCallIteratorState::DynamicFnCallIteratorState()
{
}


/*******************************************************************************

********************************************************************************/
DynamicFnCallIteratorState::~DynamicFnCallIteratorState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen)
  {
    thePlan->reset(planState);
  }
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>*)this);

  ar & theIsPartialApply;
}


/*******************************************************************************

********************************************************************************/
uint32_t DynamicFnCallIterator::getStateSizeOfSubtree() const
{
  uint32_t size = NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>::
                  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<DynamicFnCallIteratorState>::
  createState(planState, theStateOffset, offset);

  StateTraitsImpl<DynamicFnCallIteratorState>::
  initState(planState, theStateOffset);

  DynamicFnCallIteratorState* state = 
  StateTraitsImpl<DynamicFnCallIteratorState>::
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
void DynamicFnCallIterator::resetImpl(PlanState& planState) const
{
  DynamicFnCallIteratorState* state = 
  StateTraitsImpl<DynamicFnCallIteratorState>::
  getState(planState, theStateOffset);
  
  if (state->theIsOpen)
  {
    state->thePlan->close(planState);
    state->theIsOpen = false;
  }
  
  NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>::
  resetImpl(planState);
}


/*******************************************************************************

********************************************************************************/
bool DynamicFnCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t targetItem;
  FunctionItem* fnItem;
  store::Item_t selectorItem1;
  store::Item_t selectorItem2;
  store::Item_t selectorItem3;
  bool isObjectNav;
  bool selectorError;

  TypeManager* tm = theSctx->get_typemanager();

  DynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFnCallIteratorState, state, planState);

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
          pos++;
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
      isObjectNav = targetItem->isObject();
      selectorError = false;

      if (!consumeNext(selectorItem1, theChildren[1], planState))
      {
        selectorError = true;
      }
      else
      {
        try
        {
          if (selectorItem1->isNode())
          {
            store::Iterator_t iter;
            
            selectorItem1->getTypedValue(selectorItem2, iter);

            if (iter != NULL)
            {
              if (!iter->next(selectorItem2) || iter->next(item))
              {
                selectorError = true;
              }
            }
          }
          else
          {
            selectorItem2.transfer(selectorItem1);
          }

          if (!selectorError)
          {
            if (!selectorItem2->isAtomic())
            {
              selectorError = true;
            }
            else
            {
              store::SchemaTypeCode selectorType = 
              (isObjectNav ? store::XS_STRING : store::XS_INTEGER);

              GenericCast::castToBuiltinAtomic(selectorItem3,
                                               selectorItem2,
                                               selectorType,
                                               NULL,
                                               loc);
              selectorError = false;
            }
          }
        }
        catch (...)
        {
          selectorError = true;
        }
      }
        
      if (selectorError)
      {
        item = (selectorItem1 == NULL ? selectorItem2 : selectorItem1);

        zstring selectorType = tm->create_value_type(item)->toSchemaString();

        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(XPTY0004_JSONIQ_SELECTOR), selectorType));
      }

      if (isObjectNav)
        result = targetItem->getObjectValue(selectorItem3);
      else
        result = targetItem->getArrayValue(selectorItem3->getIntegerValue());
      STACK_PUSH(result != NULL, state);
    }
    else
    {
      if (targetItem->isArray())
        state->theIterator = targetItem->getArrayValues();
      else if (targetItem->isObject())
        state->theIterator = targetItem->getObjectKeys();

      state->theIterator->open();

      while (state->theIterator->next(result))
      {
        STACK_PUSH(true, state);
      }

      state->theIterator->close();
    }
  }
  else
  {
    xqtref_t type = tm->create_value_type(targetItem);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23),
                 type->toSchemaString(),
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  STACK_END(state);
};


/*******************************************************************************

********************************************************************************/
NARY_ACCEPT(DynamicFnCallIterator)


}//zorba namespace
/* vim:set et sw=2 ts=2: */
