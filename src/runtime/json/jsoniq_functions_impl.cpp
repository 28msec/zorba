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
#include <zorba/config.h>

#ifdef ZORBA_WITH_JSON

#include "stdafx.h"

#include <sstream>

#include "system/globalenv.h"

#include "runtime/json/jsoniq_functions.h"

#include "diagnostics/diagnostic.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorba/internal/diagnostic.h"

#include "context/static_context.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"

#include "store/api/pul.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"
#include <zorba/store_consts.h>

namespace zorba {


/*******************************************************************************

********************************************************************************/
bool
JSONParseIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  if (lInput->isStreamable())
  {
    result = GENV_STORE.parseJSON(lInput->getStream(), 0);
  }
  else
  {
    std::stringstream lStr;
    lStr << lInput->getStringValue();

    if (theRelativeLocation == QueryLoc::null)
    {
      try
      {
        result = GENV_STORE.parseJSON(lStr, 0);
      }
      catch (zorba::ZorbaException& e)
      {
        set_source(e, theChildren[0]->getLocation());
        throw;
      }
    }
    else
    {
      // pass the query location of the StringLiteral to the JSON
      // parser such that it can give better error locations.
      // Also, parseJSON already raises an XQueryException with the
      // location. Hence, no need to catch and rethrow the exception here
      zorba::internal::diagnostic::location lLoc;
      lLoc = ERROR_LOC(theRelativeLocation);
      result = GENV_STORE.parseJSON(lStr, &lLoc);
    }
  }

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
  json:names($o as object()) as xs:string*
********************************************************************************/
bool
JSONObjectNamesIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;
  store::Item_t pair;

  JSONObjectNamesIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectNamesIteratorState, state, planState);

  consumeNext(input, theChild.getp(), planState);

  state->thePairs = input->getPairs();
  state->thePairs->open();

  while (state->thePairs->next(pair))
  {
    result = pair->getName();
    STACK_PUSH (true, state);
  }
  state->thePairs = NULL;

  STACK_END (state);
}


/*******************************************************************************
  json:names($o as object()) as xs:string*
********************************************************************************/
bool
JSONObjectValuesIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;
  store::Item_t pair;

  JSONObjectValuesIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectValuesIteratorState, state, planState);

  consumeNext(input, theChild.getp(), planState);

  state->thePairs = input->getPairs();
  state->thePairs->open();

  while (state->thePairs->next(pair))
  {
    result = pair->getValue();
    STACK_PUSH (true, state);
  }
  state->thePairs = NULL;

  STACK_END (state);
}


/*******************************************************************************
  json:value($o as object(), $name as xs:string) as item()?
********************************************************************************/
bool
JSONObjectValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;
  store::Item_t lName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChild0.getp(), planState);
  consumeNext(lName, theChild1.getp(), planState);

  if (lInput->getPair(lName))
  {
    result = lInput->getPair(lName)->getValue();
  }
  else
  {
    result = NULL;
  }

  STACK_PUSH(result != 0, state);

  STACK_END (state);
}


/*******************************************************************************
  j:size($i as array()) as xs:integer*
********************************************************************************/
bool
JSONArraySizeIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lJSONItem;
  xs_integer lSize;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lJSONItem, theChild.getp(), planState);

  lSize = lJSONItem->getSize();

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, lSize), state);

  STACK_END(state);
}


/*******************************************************************************
  json:member($a as array(), $pos as xs:integer) as item()?
********************************************************************************/
bool
JSONArrayMemberIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;
  store::Item_t lPosition;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChild0.getp(), planState);
  consumeNext(lPosition, theChild1.getp(), planState);

  result = lInput->getMember(lPosition);

  STACK_PUSH(result != 0, state);

  STACK_END(state);
}


/*******************************************************************************
  json:members($a as array()) as item()*
********************************************************************************/
bool
JSONArrayMembersIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t array;

  JSONArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayMembersIteratorState, state, planState);

  consumeNext(array, theChild.getp(), planState);

  state->theMembers = array->getMembers();
  state->theMembers->open();
  while (state->theMembers->next(result))
  {
    STACK_PUSH(true, state);
  }
  state->theMembers->close();

  STACK_END(state);
}


/*******************************************************************************
  json:flatten($a as array()) as item()*

  op-zorba:flatten-internal($a as item()*) as item()*
********************************************************************************/
void JSONArrayFlattenIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  while (!theStack.empty())
  {
    theStack.pop();
  }
}


bool
JSONArrayFlattenIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t item;
  bool lFoundArray = false;

  JSONArrayFlattenIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayFlattenIteratorState, state, planState);

  consumeNext(item, theChild.getp(), planState);

  assert(item->isJSONArray());

  state->theStack.push(item->getMembers());
  state->theStack.top()->open();

  while (!state->theStack.empty())
  {
    while (state->theStack.top()->next(result))
    {
      if (result->isJSONArray())
      {
        state->theStack.push(result->getMembers());
        state->theStack.top()->open();
        lFoundArray = true;
        break;
      }
      
      STACK_PUSH(true, state);
    }
    
    if (lFoundArray)
    {
      lFoundArray = false;
      continue;
    }
    
    state->theStack.top()->close();
    state->theStack.pop();
  }

  STACK_END(state);
}


/*******************************************************************************
  op_zorba:json-item-accessor($i as json-item(), $s as xs:anyAtomic) as item()?
********************************************************************************/
bool
JSONItemAccessorIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;
  store::Item_t selector;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(input, theChild0.getp(), planState);
  consumeNext(selector, theChild1.getp(), planState);

  if (input->isJSONArray())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (!TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoTypePromotion_23),
                   type->toSchemaString(),
                   GENV_TYPESYSTEM.INTEGER_TYPE_ONE->toSchemaString()));
    }

    result = input->getMember(selector);
  }
  else if (input->isJSONObject())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (!TypeOps::is_subtype(type, store::XS_STRING) &&
        !TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC) &&
        !TypeOps::is_subtype(type, store::XS_ANY_URI))
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoTypePromotion_23),
                   type->toSchemaString(),
                   GENV_TYPESYSTEM.STRING_TYPE_ONE->toSchemaString()));
    }

    store::Item_t pair = input->getPair(selector);
    if (pair)
      result = pair->getValue();
    else
      result = NULL;
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  STACK_PUSH(result != 0, state);

  STACK_END(state);
}


/*******************************************************************************
  op_zorba:json-empty-item-accessor($i as json-item()) as item()?
********************************************************************************/
bool
JSONItemEmptyAccessorIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;

  JSONItemEmptyAccessorIteratorState* state;
  DEFAULT_STACK_INIT(JSONItemEmptyAccessorIteratorState, state, planState);

  consumeNext(input, theChild.getp(), planState);

  if (input->isJSONObject())
  {
    state->thePairs = input->getPairs();
    state->thePairs->open();
    while (state->thePairs->next(result))
    {
      result = result->getName();
      STACK_PUSH(true, state);
    }
    state->thePairs->close();
  }
  else if (input->isJSONArray())
  {
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, input->getSize()), state);
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  STACK_END(state);
}


/*******************************************************************************
  j:null()) as jdm:null
********************************************************************************/
bool
JSONNullIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createJSONNull(result), state);

  STACK_END(state);
}


#if 0
/*******************************************************************************
********************************************************************************/
bool
JSONInsertIntoIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lObject;
  store::Item_t lTmp;
  std::vector<store::Item_t> lPairs;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lObject, theChildren[0].getp(), planState);

  lCopyMode.set(true, 
    theSctx->construction_mode() == StaticContextConsts::cons_preserve,
    theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(lTmp, theChildren[1].getp(), planState))
  {
    if (lObject->getPair(lTmp->getName()))
    {
      RAISE_ERROR(jerr::JUDY0060, loc,
          ERROR_PARAMS(lTmp->getName()->getStringValue()));
    }

    lPairs.push_back(lTmp->copy(NULL, lCopyMode));
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONInsertInto(&loc, lObject, lPairs);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}
#endif


/*******************************************************************************
********************************************************************************/
bool
JSONInsertAsFirstIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lArray;
  store::Item_t lTmp;
  std::vector<store::Item_t> lMembers;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArray, theChildren[0].getp(), planState);

  lCopyMode.set(true, 
    theSctx->construction_mode() == StaticContextConsts::cons_preserve,
    theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(lTmp, theChildren[1].getp(), planState))
  {
    if (lTmp->isNode() || lTmp->isJSONObject() || lTmp->isJSONArray())
    {
      lTmp = lTmp->copy(NULL, lCopyMode);
    }
    lMembers.push_back(lTmp);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONInsertFirst(&loc, lArray, lMembers);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONInsertAfterIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lArray;
  store::Item_t lTmp;
  store::Item_t lPos;
  std::vector<store::Item_t> lMembers;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArray, theChildren[0].getp(), planState);
  consumeNext(lPos, theChildren[1].getp(), planState);

  if (lPos->getIntegerValue() <= xs_integer::zero())
  {
    RAISE_ERROR(jerr::JUDY0061, loc,
        ERROR_PARAMS(
          ZED(JUDY0061_ArrayNegativeOrZero),
          lPos->getIntegerValue()
        )
     );
  }
  else if (lArray->getSize() < lPos->getIntegerValue())
  {
    RAISE_ERROR(jerr::JUDY0061, loc,
        ERROR_PARAMS(
          ZED(JUDY0061_ArrayOutOfBounds),
          lPos->getIntegerValue(),
          lArray->getSize()
        )
     );
  }

  lCopyMode.set(true, 
    theSctx->construction_mode() == StaticContextConsts::cons_preserve,
    theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(lTmp, theChildren[2].getp(), planState))
  {
    if (lTmp->isNode() || lTmp->isJSONObject() || lTmp->isJSONArray())
    {
      lTmp = lTmp->copy(NULL, lCopyMode);
    }
    lMembers.push_back(lTmp);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONInsertAfter(&loc, lArray, lPos, lMembers);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONInsertBeforeIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lArray;
  store::Item_t lTmp;
  store::Item_t lPos;
  std::vector<store::Item_t> lMembers;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArray, theChildren[0].getp(), planState);
  consumeNext(lPos, theChildren[1].getp(), planState);

  if (lPos->getIntegerValue() <= xs_integer::zero())
  {
    RAISE_ERROR(jerr::JUDY0061, loc,
        ERROR_PARAMS(
          ZED(JUDY0061_ArrayNegativeOrZero),
          lPos->getIntegerValue()
        )
     );
  }
  else if (lArray->getSize() < lPos->getIntegerValue())
  {
    RAISE_ERROR(jerr::JUDY0061, loc,
        ERROR_PARAMS(
          ZED(JUDY0061_ArrayOutOfBounds),
          lPos->getIntegerValue(),
          lArray->getSize()
        )
     );
  }

  lCopyMode.set(true, 
    theSctx->construction_mode() == StaticContextConsts::cons_preserve,
    theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(lTmp, theChildren[2].getp(), planState))
  {
    if (lTmp->isNode() || lTmp->isJSONObject() || lTmp->isJSONArray())
    {
      lTmp = lTmp->copy(NULL, lCopyMode);
    }
    lMembers.push_back(lTmp);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONInsertBefore(&loc, lArray, lPos, lMembers);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONInsertAsLastIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lArray;
  store::Item_t lTmp;
  std::vector<store::Item_t> lMembers;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArray, theChildren[0].getp(), planState);

  lCopyMode.set(true, 
    theSctx->construction_mode() == StaticContextConsts::cons_preserve,
    theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(lTmp, theChildren[1].getp(), planState))
  {
    if (lTmp->isNode() || lTmp->isJSONObject() || lTmp->isJSONArray())
    {
      lTmp = lTmp->copy(NULL, lCopyMode);
    }
    lMembers.push_back(lTmp);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONInsertLast(&loc, lArray, lMembers);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONDeleteIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lTarget;
  store::Item_t lSelector;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lTarget, theChildren[0].getp(), planState);
  consumeNext(lSelector, theChildren[1].getp(), planState);

  if (lTarget->isJSONObject())
  {
    if (!lTarget->getPair(lSelector))
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(ZED(JUDY0061_Object), lSelector->getStringValue())
        );
    }

  }
  else if (lTarget->isJSONArray())
  {
    if (lSelector->getIntegerValue() <= xs_integer::zero())
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(
            ZED(JUDY0061_ArrayNegativeOrZero),
            lSelector->getIntegerValue()
          )
       );
    }
    else if (lTarget->getSize() < lSelector->getIntegerValue())
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(
            ZED(JUDY0061_ArrayOutOfBounds),
            lSelector->getIntegerValue(),
            lTarget->getSize()
          )
       );
    }
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONDelete(&loc, lTarget, lSelector);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONRenameIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lTarget;
  store::Item_t lSelector;
  store::Item_t lNewName;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lTarget, theChildren[0].getp(), planState);
  consumeNext(lSelector, theChildren[1].getp(), planState);
  consumeNext(lNewName, theChildren[2].getp(), planState);

  if (!lTarget->getPair(lSelector))
  {
    RAISE_ERROR(jerr::JUDY0061, loc,
        ERROR_PARAMS(ZED(JUDY0061_Object), lSelector->getStringValue())
      );
  }

  if (lTarget->getPair(lNewName))
  {
    RAISE_ERROR(jerr::JUDY0065, loc,
        ERROR_PARAMS(lNewName->getStringValue())
      );
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONRename(&loc, lTarget, lSelector, lNewName);

  result = pul.release();
  STACK_PUSH(result != NULL, state);


  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONReplaceValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lTarget;
  store::Item_t lSelector;
  store::Item_t lNewValue;
  std::auto_ptr<store::PUL> pul;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lTarget, theChildren[0].getp(), planState);
  consumeNext(lSelector, theChildren[1].getp(), planState);
  consumeNext(lNewValue, theChildren[2].getp(), planState);

  if (lTarget->isJSONObject())
  {
    if (!lTarget->getPair(lSelector))
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(ZED(JUDY0061_Object), lSelector->getStringValue())
        );
    }
  }
  else if (lTarget->isJSONArray())
  {
    if (lSelector->getIntegerValue() <= xs_integer::zero())
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(
            ZED(JUDY0061_ArrayNegativeOrZero),
            lSelector->getIntegerValue()
          )
       );
    }
    else if (lTarget->getSize() < lSelector->getIntegerValue())
    {
      RAISE_ERROR(jerr::JUDY0061, loc,
          ERROR_PARAMS(
            ZED(JUDY0061_ArrayOutOfBounds),
            lSelector->getIntegerValue(),
            lTarget->getSize()
          )
       );
    }
  }

  if (lNewValue->isNode() ||
      lNewValue->isJSONObject() ||
      lNewValue->isJSONArray())
  {
    lCopyMode.set(true, 
      theSctx->construction_mode() == StaticContextConsts::cons_preserve,
      theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
      theSctx->inherit_mode() == StaticContextConsts::inherit_ns);
    lNewValue = lNewValue->copy(NULL, lCopyMode);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  pul->addJSONReplaceValue(&loc, lTarget, lSelector, lNewValue);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
#endif /* ZORBA_WITH_JSON */
