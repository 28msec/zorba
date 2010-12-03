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

#include "system/globalenv.h"

#include "util/converters/json_converter.h"

#include "context/static_context.h"

#include "runtime/convertors/convertors.h"

#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

#include "runtime/convertors/convertors.h"
#include "zorbautils/checked_vector.h"
#include "zorbatypes/URI.h"
#include "types/root_typemanager.h"
#include "api/unmarshaller.h"
#include "api/staticcontextimpl.h"

#include <zorba/zorba.h>


namespace zorba {


bool ZorbaJsonParseIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool parseOK = true;
  store::Item_t strItem;
  zstring strval;
  zstring error_log;

  ZorbaJsonParseIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaJsonParseIteratorState, state, planState);

  if( state->theBaseUri.empty() )
    state->theBaseUri = theSctx->get_base_uri();

  while (consumeNext(strItem, theChildren[0].getp(), planState))
  {
    strItem->getStringValue2(strval);

    if ( strval.empty() )
    {
      ZORBA_ERROR_LOC_PARAM(API0060_CONV_JSON_PARSE,
                            loc,
                            strItem->show().c_str(),
                            "The string representation of the value passed was empty.");
    }

    parseOK = JSON_parse(strval.c_str(),
                         strval.size(),
                         result,
                         state->theBaseUri,
                         error_log);

    if (parseOK && result &&
        result->isNode() &&
        result->getNodeKind() == store::StoreConsts::elementNode)
    {
      STACK_PUSH (true, state);
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM(API0060_CONV_JSON_PARSE, loc,
                            strval.c_str(), error_log.c_str());
    }
  }

  STACK_END (state);
}


bool ZorbaJsonSerializeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t elemItem;
  zstring str;
  zstring error_log;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState))
  {
    if( !elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
    {
      ZORBA_ERROR_LOC_PARAM(API0062_CONV_JSON_PARAM, loc,
                            elemItem->getStringValue().c_str() , "");
    }
    else
    {
      if( !JSON_serialize(elemItem, str, error_log) )
      {
        ZORBA_ERROR_LOC_PARAM(API0061_CONV_JSON_SERIALIZE, loc,
                              elemItem->getStringValue().c_str() , error_log);
      }
      else
      {
        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }

  STACK_END (state);
}


//Json:ParseML
bool ZorbaJsonParseMLIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool parseOK = true;
  store::Item_t strItem;
  zstring strval;
  zstring error_log;

  ZorbaJsonParseMLIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaJsonParseMLIteratorState, state, planState);

  if( state->theBaseUri.empty() )
    state->theBaseUri = theSctx->get_base_uri();

  while (consumeNext(strItem, theChildren[0].getp(), planState))
  {
    strItem->getStringValue2(strval);

    if( strval.empty() )
    {
      ZORBA_ERROR_LOC_PARAM(API0063_CONV_JSON_ML_PARSE,
                            loc,
                            strItem->show().c_str(),
                            "The string representation of the value passed was empty.");
    }

    parseOK = JSON_ML_parse(strval.c_str(),
                            strval.size(),
                            result,
                            state->theBaseUri.c_str(),
                            error_log);
    if(parseOK && result &&
       result->isNode() &&
       result->getNodeKind () == store::StoreConsts::elementNode)
    {
      STACK_PUSH (true, state);
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM(API0063_CONV_JSON_ML_PARSE,
                            loc,
                            strval.c_str(),
                            error_log.c_str());
    }
  }

  STACK_END (state);
}


bool ZorbaJsonSerializeMLIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t elemItem;
  zstring str;
  zstring error_log;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState))
  {
    if(!elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
    {
      ZORBA_ERROR_LOC_PARAM(API0065_CONV_JSON_ML_PARAM,
                            loc,
                            elemItem->getStringValue().c_str(),
                            "");
    }
    else
    {
      if( !JSON_ML_serialize(elemItem, str, error_log) )
      {
        ZORBA_ERROR_LOC_PARAM(API0064_CONV_JSON_ML_SERIALIZE,
                              loc,
                              elemItem->getStringValue().c_str(),
                              error_log.c_str());
      }
      else
      {
        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }
  STACK_END (state);
}


} /* namespace zorba */
