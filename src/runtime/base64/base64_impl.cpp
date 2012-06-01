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

#include <sstream>
#include <zorba/transcode_stream.h>

#include "system/globalenv.h"

#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/binary.h"

#include "runtime/base64/base64.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {

bool Base64DecodeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lItem;
  zstring lResultString;
  zstring lEncoding("UTF-8");
  const char* lContent;
  size_t lSize;
  result = NULL;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lItem, theChildren[0].getp(), planState);

  if (theChildren.size() == 2)
  {
    store::Item_t lEncodingItem;
    consumeNext(lEncodingItem, theChildren[1].getp(), planState);
    lEncoding = lEncodingItem->getStringValue();

    if (!transcode::is_supported(lEncoding.c_str()))
    {
      throw XQUERY_EXCEPTION(
        zerr::ZXQP0006_UNKNOWN_ENCODING,
        ERROR_PARAMS( lEncoding ),
        ERROR_LOC( loc )
      );
    }
  }

  if (lItem->isStreamable())
  {
    if (lItem->isEncoded())
    {
      lResultString = Base64::decode(lItem->getStream());
    }
    else
    {
      if (transcode::is_necessary(lEncoding.c_str()))
      {
        transcode::attach(lItem->getStream(), lEncoding.c_str());
        GENV_ITEMFACTORY->createStreamableString(
            result,
            lItem->getStream(),
            lItem->getStreamReleaser(),
            lItem->isSeekable());
      }
      else
      {
        GENV_ITEMFACTORY->createSharedStreamableString(
            result,
            lItem);
      }
    }
  }
  else
  {
    lContent = lItem->getBase64BinaryValue(lSize);

    if (lItem->isEncoded())
    {
      std::vector<char> encoded(lContent, lContent+lSize);
      std::vector<char> decoded;
      Base64::decode(encoded, decoded);
      lResultString.insert(0, &decoded[0], decoded.size());
    }
    else
    {
      lResultString.insert(0, lContent, lSize);
    }

    if (transcode::is_necessary(lEncoding.c_str()))
    {
      try
      {
        zstring lTranscodedString;
        transcode::stream<std::istringstream> lTranscoder(
            lEncoding.c_str(),
            lResultString.c_str()
          );
        char buf[1024];
        while (lTranscoder.good())
        {
          lTranscoder.read(buf, 1024);
          lTranscodedString.append(buf, lTranscoder.gcount());
        }
        GENV_ITEMFACTORY->createString(result, lTranscodedString);
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
    else
    {
      GENV_ITEMFACTORY->createString(result, lResultString);
    }
  }
  STACK_PUSH (true, state);

  STACK_END (state);
}


bool Base64EncodeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lItem;
  zstring       lTmpString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) 
  {
    lItem->getStringValue2(lTmpString);
    // create a base64Binary item
    // the content is the non-encoded string
    GENV_ITEMFACTORY->createBase64Binary(
          result, lTmpString.c_str(), lTmpString.size(), false
        );
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
