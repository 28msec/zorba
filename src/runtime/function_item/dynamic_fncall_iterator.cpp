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

#include "runtime/function_item/dynamic_fncall_iterator.h"
#include "runtime/function_item/function_item.h"
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

#include "system/globalenv.h"

// TODO: remove, used for debugging purposes
#include "runtime/core/var_iterators.h"
#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/visitors/iterprinter.h"

namespace zorba
{


SERIALIZABLE_CLASS_VERSIONS(ArgumentPlaceholderIterator);

NOARY_ACCEPT(ArgumentPlaceholderIterator);


SERIALIZABLE_CLASS_VERSIONS(DynamicFnCallIterator);


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
DynamicFnCallIterator::~DynamicFnCallIterator()
{
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
  StateTraitsImpl<DynamicFnCallIteratorState>::createState(planState,
                                                           theStateOffset,
                                                           offset);

  StateTraitsImpl<DynamicFnCallIteratorState>::initState(planState, theStateOffset);

  DynamicFnCallIteratorState* state =
  StateTraitsImpl<DynamicFnCallIteratorState>::getState(planState, theStateOffset);

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
  StateTraitsImpl<DynamicFnCallIteratorState>::getState(planState, theStateOffset);
  
  if (state->theIsOpen)
  {
    state->thePlan->close(planState);
    state->theIsOpen = false;
  }
  
  NaryBaseIterator<DynamicFnCallIterator,DynamicFnCallIteratorState>::resetImpl(planState);
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
#ifdef ZORBA_WITH_JSON
  store::Item_t selectorItem1;
  store::Item_t selectorItem2;
  store::Item_t selectorItem3;
  bool isObjectNav;
  bool selectorError;
#endif
  
  TypeManager* tm = theSctx->get_typemanager(); // TODO: delete this when theCoercionTargetType is removed

  DynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFnCallIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  // otherwise XPTY0004 is raised
  if (!consumeNext(targetItem, theChildren[0], planState))
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

    // std::cerr << "--> " << this->toString() << " nextImpl() theChildren.size(): " << theChildren.size() << " fnItem arity: " << fnItem->getArity() << " fnItem var count: " << fnItem->getVariablesIterators().size() << std::endl;

    // if (theCoercionTargetType.getp())
    {
      xqtref_t fnItemType = tm->create_value_type(fnItem, loc);

      /*
      std::cerr << "--> dynamic fncall nextImpl(): " << theId << std::endl
                << "    fnItemType: " << fnItemType->toString() << std::endl
                << "    coercionType: " << (theCoercionTargetType.getp()? theCoercionTargetType->toString() : "NULL") << std::endl;
      if (theCoercionTargetType.getp())
      {
        std::cerr << "    fnItemType subtype of coercionType? " << TypeOps::is_subtype(tm, *fnItemType, *theCoercionTargetType, loc) << std::endl;
        std::cerr << "    coercionType subtype of fnItemType? " << TypeOps::is_subtype(tm, *theCoercionTargetType, *fnItemType, loc) << std::endl;
        std::cerr << "    fnItem subtype of coercionType? " << TypeOps::is_subtype(tm, fnItem, *theCoercionTargetType, loc) << std::endl;
        std::cerr << "    fnItem treatable as coercionType? " << TypeOps::is_treatable(tm, fnItem, *theCoercionTargetType, loc) << std::endl;
        
        std::cerr << "    fnItemType subtype of coercionType ignoring return? " << 
                     static_cast<const FunctionXQType*>(fnItemType.getp())->is_subtype(tm, *static_cast<const FunctionXQType*>(theCoercionTargetType.getp()), true) << std::endl;
      }
      */
      
      // if (!TypeOps::is_subtype(tm, *theCoercionTargetType, *fnItemType, loc))
      // if (!TypeOps::is_subtype(tm, *fnItemType, *theCoercionTargetType, loc))
      // if ( ! static_cast<const FunctionXQType*>(fnItemType.getp())->is_subtype(tm, *static_cast<const FunctionXQType*>(theCoercionTargetType.getp()), true))
      {
        /*
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23),
                  theCoercionTargetType->toSchemaString(),
                  fnItemType->toSchemaString()));
        */
      }
    }


    if (( ! fnItem->needsContextItem() && theChildren.size() - 1 - theDotVarsCount != fnItem->getArity())
        ||
        (fnItem->needsContextItem() && theChildren.size() - 1 != fnItem->getArity()))
    {
      // TODO: customize error message and take into account partial application
      RAISE_ERROR(err::XPTY0004, loc, ERROR_PARAMS("dynamic function invoked with incorrect number of arguments"));
    }

    if (theIsPartialApply)
    {
      for (unsigned int i=1, pos=0; i<theChildren.size() - theDotVarsCount; i++)
      {
        if (dynamic_cast<ArgumentPlaceholderIterator*>(theChildren[i].getp()) == NULL)
        {
          // TODO: The argument needs to be materialized only for local vars and only if the 
          // function item is returned and used outside of the current function. It might
          // be impossible to determine if the partially applied function item will be used outside 
          // of the current function, so it is quite probable that it always needs to be materialized.
          
          std::vector<store::Item_t> argValues;
          store::Item_t tempItem;
          while (consumeNext(tempItem, theChildren[i], planState))
            argValues.push_back(tempItem);
          store::TempSeq_t argSeq = GENV_STORE.createTempSeq(argValues);
          store::Iterator_t argSeqIter = argSeq->getIterator();
          PlanIter_t value = new PlanStateIteratorWrapper(argSeqIter);
          
          // PlanIter_t value = new PlanStateIteratorWrapper(theChildren[i].getp(), planState, state->theUDFStateOffset + sizeof(UDFunctionCallIteratorState));
          // std::cerr << "--> " << toString() << " created PlanStateIteratorWrapper: " << value->toString() << std::endl;
          fnItem->setArgumentValue(pos, value);
        }
        else
          pos++;
        
        /*
        std::cerr << "--> dynamic fncall: child argIter: " << theChildren[i]->toString() << std::endl;
        if (dynamic_cast<LetVarIterator*>(theChildren[i].getp()))
          std::cerr << "-->                 argIter is LetVarIterator with varName: " << dynamic_cast<LetVarIterator*>(theChildren[i].getp())->getVarName()->getStringValue() << std::endl;
        */
      }

      result = fnItem;
      STACK_PUSH(true, state);
    }
    else
    {
      state->thePlan = fnItem->getImplementation(theChildren);
      
      // must be opened after vars and params are set
      state->thePlan->open(planState, state->theUDFStateOffset);
      state->theIsOpen = true;

      while (consumeNext(result, state->thePlan, planState))
      {
        STACK_PUSH(true, state);
      }

      // need to close here early in case the plan is completely
      // consumed. Otherwise, the plan would still be opened
      // if destroyed from the state's destructor.
      state->thePlan->close(planState);
      state->theIsOpen = false;
    } // if (theIsPartialApply)

  } // if (targetItem->isFunction())
#ifdef ZORBA_WITH_JSON
  else if (targetItem->isJSONObject() || targetItem->isJSONArray())
  {
    if (theChildren.size() != 2)
    {
      RAISE_ERROR_NO_PARAMS(jerr::JNTY0018, loc);
    }

    isObjectNav = targetItem->isJSONObject();
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

    STACK_PUSH(true, state);
    
  } // else if (targetItem->isJSONObject() || targetItem->isJSONArray())
#endif
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
