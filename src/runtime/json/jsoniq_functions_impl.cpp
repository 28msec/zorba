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

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include <zorba/store_consts.h>

namespace zorba {

/*******************************************************************************
********************************************************************************/
void JSONFlattenIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  while (!theStack.empty())
  {
    theStack.pop();
  }
}

bool
JSONFlattenIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lCurr;
  bool lFoundArray = false;

  JSONFlattenIteratorState* state;
  DEFAULT_STACK_INIT(JSONFlattenIteratorState, state, planState);

  consumeNext(lCurr, theChildren[0].getp(), planState);

  state->theStack.push(lCurr->values());
  state->theStack.top()->open();

  while (!state->theStack.empty())
  {
    while (state->theStack.top()->next(result))
    {
      if (result->isJSONArray())
      {
        state->theStack.push(result->values());
        state->theStack.top()->open();
        lFoundArray = true;
        break;
      }
      STACK_PUSH( true, state );
    }
    if (lFoundArray)
    {
      lFoundArray = false;
      continue;
    }
    state->theStack.top()->close();
    state->theStack.pop();
  }

  STACK_END (state);
}


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
    result = GENV_STORE.parseJSON(lInput->getStream());
  }
  else
  {
    std::stringstream lStr;
    lStr << lInput->getStringValue();

    result = GENV_STORE.parseJSON(lStr);
  }

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONNamesIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  JSONNamesIteratorState* state;
  DEFAULT_STACK_INIT(JSONNamesIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  state->thePairs = lInput->pairs();
  state->thePairs->open();

  while (state->thePairs->next(lInput))
  {
    result = lInput->getName();
    STACK_PUSH (true, state);
  }
  state->thePairs = NULL;

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONNameIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  result = lInput->getName();

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONPairsIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  JSONPairsIteratorState* state;
  DEFAULT_STACK_INIT(JSONPairsIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  state->thePairs = lInput->pairs();
  state->thePairs->open();

  while (state->thePairs->next(result))
  {
    STACK_PUSH (true, state);
  }
  state->thePairs = NULL;

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONSizeIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lJSONItem;
  xs_integer lSize;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lJSONItem, theChildren[0].getp(), planState);

  if (lJSONItem->isJSONPair())
  {
    throw XQUERY_EXCEPTION(
        zerr::JSDY0020,
        ERROR_PARAMS( ZED(BadArgTypeForFn_2o34o), "pair", "json:size" ),
        ERROR_LOC( loc )
      );
    // raise error
  }

  lSize = lJSONItem->getSize();

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, lSize), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONValuesIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  JSONValuesIteratorState* state;
  DEFAULT_STACK_INIT(JSONValuesIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  if (lInput->getJSONItemKind() == store::StoreConsts::jsonObject)
  {
    state->theValues = lInput->pairs();
    state->theValues->open();
    while (state->theValues->next(lInput))
    {
      result = lInput->getValue();
      STACK_PUSH (true, state);
    }
    state->theValues = NULL;
  }
  else if (lInput->getJSONItemKind() == store::StoreConsts::jsonArray)
  {
    state->theValues = lInput->values();
    state->theValues->open();
    while (state->theValues->next(result))
    {
      STACK_PUSH (true, state);
    }
    state->theValues = NULL;
  }
  else if (lInput->getJSONItemKind() == store::StoreConsts::jsonPair)
  {
    result = lInput->getValue();
    STACK_PUSH (true, state);
  }

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
JSONValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  result = lInput->getValue();

  STACK_PUSH(true, state);

  STACK_END (state);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
#endif /* ZORBA_WITH_JSON */
