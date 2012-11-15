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
#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"

#include "types/root_typemanager.h"
#include "types/casting.h"
#include "types/typeops.h"

#include "system/globalenv.h"

// TODO: remove, used for debugging purposes
#include "runtime/core/var_iterators.h"

namespace zorba
{


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
bool DynamicFnCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t targetItem;
#ifdef ZORBA_WITH_JSON
  store::Item_t selectorItem1;
  store::Item_t selectorItem2;
  store::Item_t selectorItem3;
  bool isObjectNav;
  bool selectorError;
#endif
  FunctionItem* fnItem;
  std::vector<PlanIter_t> argIters;
  std::vector<PlanIter_t>::iterator ite;
  std::vector<PlanIter_t>::const_iterator ite2;
  std::vector<PlanIter_t>::const_iterator end2;

  TypeManager* tm = theSctx->get_typemanager();

  DynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFnCallIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  // otherwise XPTY0004 is raised
  if (!consumeNext(targetItem, theChildren[0], planState))
  {
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(XPTY0004_TypePromotion),
                 "empty-sequence()",
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  if (targetItem->isFunction())
  {
    if (consumeNext(item, theChildren[0], planState))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(XPTY0004_NoMultiSeqTypePromotion),
                   GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
    }

    fnItem = static_cast<FunctionItem*>(targetItem.getp());

    std::cerr << "--> dynamic fncall nextImpl(): " << theId << " theChildren.size(): " << theChildren.size() << " fnItem arity: " << fnItem->getArity() << " fnItem var count: " << fnItem->getVariablesIterators().size() << std::endl;

    if (theCoercionTargetType.getp())
    {
      const TypeManager* tm = theSctx->get_typemanager();

      xqtref_t fnItemType = tm->create_value_type(fnItem, loc);
      std::cerr << "--> dynamic fncall nextImpl(): " << theId << std::endl
                << "    fnItemType: " << fnItemType->toString() << std::endl
                << "    coercionType: " << (theCoercionTargetType.getp()? theCoercionTargetType->toString() : "NULL") << std::endl;

      if (theCoercionTargetType.getp())
      {
        std::cerr << "    fnItemType subtype of coercionType? " << TypeOps::is_subtype(tm, *fnItemType, *theCoercionTargetType, loc) << std::endl;
        std::cerr << "    coercionType subtype of fnItemType? " << TypeOps::is_subtype(tm, *theCoercionTargetType, *fnItemType, loc) << std::endl;
      }

      if (!TypeOps::is_subtype(tm, *theCoercionTargetType, *fnItemType, loc))
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(XPTY0004_TypePromotion),
                  theCoercionTargetType->toSchemaString(),
                  fnItemType->toSchemaString()));
      }

    }


    if (theChildren.size() - 1 != fnItem->getArity())
    {
      // TODO: customize error message and take into account partial application
      RAISE_ERROR(err::XPTY0004, loc, ERROR_PARAMS("dynamic function invoked with incorrect number of arguments"));
    }

    // argIters.resize(theChildren.size() - 1 + fnItem->getVariables().size());
    argIters.resize(theChildren.size() - 1);

    ite = argIters.begin();

    /*
    ite2 = fnItem->getVariablesIterators().begin();
    end2 = fnItem->getVariablesIterators().end();
    for (; ite2 != end2; ++ite2, ++ite)
    {
      std::cerr << "--> dynamic fncall: var argIter: " << (*ite2)->getId() << " = " << (*ite2)->getClassName() << std::endl;
      if (dynamic_cast<LetVarIterator*>(ite2->getp()))
        std::cerr << "-->                 argIter is LetVarIterator with varName: " << dynamic_cast<LetVarIterator*>(ite2->getp())->getVarName()->getStringValue() << std::endl;
      if (dynamic_cast<ForVarIterator*>(ite2->getp()))
        std::cerr << "-->                 argIter is ForVarIterator with varName: " << dynamic_cast<ForVarIterator*>(ite2->getp())->getVarName()->getStringValue() << std::endl;
      if (dynamic_cast<SingletonIterator*>(ite2->getp()))
        std::cerr << "-->                 argIter is SingletonIterator with value: " << dynamic_cast<SingletonIterator*>(ite2->getp())->getValue()->show() << std::endl;

      // (*ite2)->reset(planState); // TODO: do not reset on the first loop iteration
      *ite = *ite2;
    }
    */

    ite2 = theChildren.begin();
    end2 = theChildren.end();
    ++ite2;

    for (; ite2 != end2; ++ite2, ++ite)
    {
      std::cerr << "--> dynamic fncall: child argIter: " << (*ite2)->getId() << " = " << (*ite2)->getClassName() << std::endl;
      if (dynamic_cast<LetVarIterator*>(ite2->getp()))
        std::cerr << "-->                 argIter is LetVarIterator with varName: " << dynamic_cast<LetVarIterator*>(ite2->getp())->getVarName()->getStringValue() << std::endl;

      // (*ite2)->reset(planState); // TODO: do not reset on the first loop iteration
      *ite = *ite2;
    }

    state->thePlan = fnItem->getImplementation(argIters);

    std::cerr << "--> dynamic fncall: opening thePlan: " << state->thePlan->toString() << std::endl;

    // must be opened after vars and params are set
    state->thePlan->open(planState, state->theUDFStateOffset);
    state->theIsOpen = true;

    while(consumeNext(result, state->thePlan, planState))
    {
      STACK_PUSH(true, state);
    }

    // need to close here early in case the plan is completely
    // consumed. Otherwise, the plan would still be opened
    // if destroyed from the state's destructor.
    state->thePlan->close(planState);
    state->theIsOpen = false;
  }
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

            selectorError = ! GenericCast::castToAtomic(selectorItem3,
                                                        selectorItem2,
                                                        selectorType,
                                                        tm,
                                                        NULL,
                                                        loc);
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
  }
#endif
  else
  {
    xqtref_t type = tm->create_value_type(targetItem);

    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(XPTY0004_TypePromotion),
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
