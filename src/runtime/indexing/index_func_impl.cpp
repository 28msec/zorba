/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/URI.h"

#include "system/globalenv.h"

#include "runtime/indexing/index_func.h"
#include "runtime/indexing/index_util.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "store/api/item.h"
#include "store/api/index.h"


namespace zorba {

/*******************************************************************************
********************************************************************************/
bool
IndexKeysIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t    lQName;
  IndexDecl_t      indexDecl;
  store::Index*    lIndex;
  store::IndexKey  lKey;

  store::Item_t lKeyNodeName;
  GENV_ITEMFACTORY->createQName(lKeyNodeName,
      static_context::ZORBA_STORE_DYNAMIC_UNORDERED_MAP_FN_NS,
      "", "key");

  IndexKeysIteratorState* state;
  DEFAULT_STACK_INIT(IndexKeysIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0021_INDEX_NOT_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  lIndex = GENV_STORE.getIndex(lQName);

  if (!lIndex)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( lQName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  state->theIter = lIndex->keys();

  state->theIter->open();

  // generate result elements of the form
  // <key>
  //   <attribute value="key1_value"/>
  //   <attribute value="key2_value"/>
  //   <attribute value="key3_value"/>
  // </key>
  while (state->theIter->next(lKey))
  {
    IndexUtil::createIndexKeyElement(
        result, lKey, static_context::ZORBA_STORE_STATIC_INDEXES_DML_FN_NS
      );
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

