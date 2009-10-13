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
#include <iostream>

#include "common/common.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/utf8.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/collation_cache.h"

#include "compiler/api/compilercb.h"

#include "runtime/strings/StringsImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"


using namespace std;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(StringToCodepointsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(StringToCodepointsIterator)


SERIALIZABLE_CLASS_VERSIONS(FnTokenizeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnTokenizeIterator)


NARY_ACCEPT (StringToCodepointsIterator);

NARY_ACCEPT(FnTokenizeIterator);



/**
  *______________________________________________________________________
  *
  *  7.2.2 fn:string-to-codepoints
  *
  *  fn:string-to-codepoints($arg as xs:string?) as xs:integer*
  *_______________________________________________________________________*/
/* begin class StringToCodepointsIterator */
bool
StringToCodepointsIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  // TODO Optimization for large strings: large strings mean that a large integer vector should be store in the state that is not good.
  store::Item_t item;
  xqpStringStore_t inputStr;

  StringToCodepointsState* state;
  DEFAULT_STACK_INIT(StringToCodepointsState, state, planState);

  if (consumeNext(item, theChildren [0].getp(), planState )) {
    inputStr = item->getStringValue();
    if(!inputStr->empty())
    {
      state->setVector(inputStr->getCodepoints());
  
      while (state->getIterator() < state->getVectSize())
      {
        GENV_ITEMFACTORY->createInteger( 
          result,
          Integer::parseInt(state->getItem( state->getIterator() )) 
        );
        STACK_PUSH(true, state );
        state->setIterator( state->getIterator() + 1 );
      }
    }
  }
  STACK_END (state);
}

void
StringToCodepointsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  iter= 0;
  resVector.clear();
}

void
StringToCodepointsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  iter = 0;
  resVector.clear();
}

void
StringToCodepointsState::setIterator(xqp_uint value)
{
  iter = value;
}

xqp_uint
StringToCodepointsState::getIterator() {
  return iter;
}

void
StringToCodepointsState::setVector(checked_vector<xqp_uint> vect)
{
  resVector = vect;
}

xqp_uint
StringToCodepointsState::getItem(xqp_uint iter)
{
  return resVector[iter];
}

xqp_uint
StringToCodepointsState::getVectSize()
{
  return resVector.size();
}
/* end class StringToCodepointsIterator */

/**
  *______________________________________________________________________
  *
  *  7.6.4 fn:tokenize
  *
  *fn:tokenize($input    as xs:string?,
  *            $pattern  as xs:string) as xs:string*
  *fn:tokenize($input    as xs:string?,
  *            $pattern  as xs:string,
  *            $flags    as xs:string) as xs:string*
  *_______________________________________________________________________*/
 /*begin class FnTokenizeIterator*/
void
FnTokenizeIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  start_pos = 0;
  hasmatched = false;
}

void
FnTokenizeIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theString = xqp_string();
  start_pos = 0;
  hasmatched = false;
  thePattern = xqp_string();
  theFlags = xqp_string();
}

bool
FnTokenizeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t token;
  store::Item_t item;
  bool tmp;

  FnTokenizeIteratorState* state;
  DEFAULT_STACK_INIT(FnTokenizeIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
    state->theString = item->getStringValue().getp();

  if (!consumeNext(item, theChildren[1].getp(), planState))
    ZORBA_ASSERT (false);
  state->thePattern = item->getStringValue().getp();

  if(theChildren.size() == 3) {
    if (!consumeNext(item, theChildren[2].getp(), planState))
      ZORBA_ASSERT (false);
    state->theFlags = item->getStringValue().getp();
  }

  try{
    tmp = xqp_string().matches(state->thePattern, state->theFlags);
  }
  catch(zorbatypesException& ex){
    ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()), loc, ex.what(), "");
  }

  if(tmp)
    ZORBA_ERROR_LOC_DESC(FORX0003, loc,
                         "Regular expression matches zero-length string.");

  while ((xqp_uint)state->start_pos < state->theString.length ())
  {
    try {
      token = state->theString.tokenize(state->thePattern, state->theFlags, &state->start_pos, &state->hasmatched).getStore();
    }
    catch(zorbatypesException& ex) {
      ZORBA_ERROR_LOC_PARAM(error::DecodeZorbatypesError(ex.ErrorCode()), loc, ex.what(), "");
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, token), state);
  }
  if(state->hasmatched)
  {
    //the last token is empty (is after the last match)
    token = new xqpStringStore;
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, token), state);
  }
  STACK_END(state);
}
/*end class FnTokenizeIterator*/
} /* namespace zorba */

