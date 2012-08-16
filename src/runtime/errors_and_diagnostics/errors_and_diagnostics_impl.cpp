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

#include <iostream>

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/user_exception.h"

#include "context/static_context.h"

#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "system/globalenv.h"
#include "zorbatypes/zstring.h"

#include "api/serialization/serializer.h"
#include "api/serializerimpl.h"

namespace zorba 
{

/*******************************************************************************
  3.1.1 fn:error
********************************************************************************/
bool
ErrorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  static const char* err_ns = "http://www.w3.org/2005/xqt-errors";
  store::Item_t err_qname;
  GENV_ITEMFACTORY->createQName(err_qname, err_ns, "err", "FOER0000");
  store::Item_t lTmpQName;
  store::Item_t lTmpErrorObject;
  store::Item_t lTmpDescr;
  zstring description;
  UserException::error_object_type lErrorObject; 

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() >= 1) 
  {
    if (consumeNext(lTmpQName, theChildren[0].getp(), planState))
      err_qname = lTmpQName;
  }

  if (theChildren.size() >= 2) 
  {
    consumeNext(lTmpDescr, theChildren[1].getp(), planState);
    description = lTmpDescr->getStringValue();
  }

  if (theChildren.size() == 3) 
  {
    while (consumeNext(lTmpErrorObject, theChildren[2].getp(), planState)) 
    {
      lErrorObject.push_back( Item( lTmpErrorObject.getp() ) );
    }
  }

  throw USER_EXCEPTION(
    err_qname, description.c_str(), ERROR_LOC( loc ), &lErrorObject
  );

  STACK_END(state);
}


/*******************************************************************************
  3.2.1 fn:trace
********************************************************************************/
bool
TraceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  TraceIteratorState *state;
  DEFAULT_STACK_INIT(TraceIteratorState, state, planState);

  state->theIndex = 1; // XQuery sequences start with 1

  if (!consumeNext(state->theTagItem, theChildren[1], planState)) 
  {
    throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o), ZED(EmptySequence), "fn:trace"),
      ERROR_LOC( loc )
    );
  }

  if (state->theSerializer == NULL)
  {
    state->theSerializer = new serializer(0);
    Zorba_SerializerOptions options;
    options.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    SerializerImpl::setSerializationParameters(*(state->theSerializer), options);
  }

  state->theOS = theSctx->get_trace_stream();

  while (consumeNext(result, theChildren[0], planState)) 
  {
    (*state->theOS) << state->theTagItem->getStringValue() 
      << " [" << state->theIndex << "]: ";

    {
      store::Item_t lTmp = result;

      // implicitly materialize non-seekable streamable strings to 
      // avoid nasty "streamable string has already been consumed"
      // errors during debugging
      if (lTmp->isStreamable() && !lTmp->isSeekable() &&
          lTmp->getTypeCode() == store::XS_STRING)
      {
        zstring lString = lTmp->getString();
        GENV_ITEMFACTORY->createString(lTmp, lString);
        result = lTmp;
      }

      store::TempSeq_t lSequence = GENV_STORE.createTempSeq(lTmp);
      store::Iterator_t seq_iter = lSequence->getIterator();
      seq_iter->open();
      state->theSerializer->serialize(seq_iter, (*state->theOS), true);
      seq_iter->close(); 
    }

    (*state->theOS) << std::endl;
    ++state->theIndex;

    STACK_PUSH(true, state);
  }


  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
