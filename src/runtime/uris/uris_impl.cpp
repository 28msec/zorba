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
#include "diagnostics/util_macros.h"

#include "runtime/uris/uris.h"

#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "zorba/transcode_stream.h"

#include "util/uri_util.h"

using namespace std;

namespace zorba {

/******************************************************************************
*******************************************************************************/
bool
DecodeURIIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lString, lDecodePlus, lEncoding;
  zstring       lDecodedString, lCharset;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lString, theChildren[0].getp(), planState);
  consumeNext(lDecodePlus, theChildren[1].getp(), planState);
  consumeNext(lEncoding, theChildren[2].getp(), planState);

  lString->getStringValue2(lDecodedString);
  lEncoding->getStringValue2(lCharset);

  if (lDecodePlus->getBooleanValue())
  {
    std::replace( lDecodedString.begin(), lDecodedString.end(), '+', ' ' );
  }

  uri::decode(lDecodedString);

  if (transcode::is_necessary(lCharset.c_str()))
  {
    if (!transcode::is_supported(lCharset.c_str()))
    {
      throw XQUERY_EXCEPTION(
        zerr::ZXQP0006_UNKNOWN_ENCODING,
        ERROR_PARAMS( lCharset ),
        ERROR_LOC( loc )
      );
    }

    try
    {
      transcode::stream<istringstream> lTranscoder(
          lCharset.c_str(),
          lDecodedString.c_str()
        );

      lDecodedString.clear();
      char buf[1024];
      while (lTranscoder.good())
      {
        lTranscoder.read(buf, 1024);
        lDecodedString.append(buf, lTranscoder.gcount());
      }
    }
    catch (ZorbaException& e)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZOSE0006_TRANSCODING_ERROR,
        ERROR_PARAMS( e.what() ),
        ERROR_LOC( loc )
      );
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, lDecodedString), state );

  STACK_END (state);
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
