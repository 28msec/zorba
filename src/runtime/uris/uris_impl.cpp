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

#include <algorithm>

#include "common/common.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "runtime/uris/uris.h"

#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "util/uri_util.h"

using namespace std;

namespace zorba {

/******************************************************************************
*******************************************************************************/
bool
DecodeURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lString;
  store::Item_t lDecodePlus;
  store::Item_t lEncoding;
  zstring       lDecodedString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lString, theChildren[0].getp(), planState);
  consumeNext(lDecodePlus, theChildren[1].getp(), planState);
  consumeNext(lEncoding, theChildren[2].getp(), planState);

  lString->getStringValue2(lDecodedString);

  if (lDecodePlus->getBooleanValue())
  {
    std::replace( lDecodedString.begin(), lDecodedString.end(), '+', ' ' );
  }

  uri::decode(lDecodedString);

  // TODO: do encoding once the transcode_streambuf is there

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, lDecodedString), state );

  STACK_END (state);
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
