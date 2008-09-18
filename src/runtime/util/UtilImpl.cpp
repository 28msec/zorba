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

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/binary.h"

#include "runtime/util/UtilImpl.h"

#ifdef ZORBA_WITH_TIDY
  #include <tidy/tidy.h>
  #include <tidy/buffio.h>
#endif

namespace zorba {

bool
ZorbaSchemaTypeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    result = item->getType();
    STACK_PUSH(true, state );
  }

  STACK_END (state);
}

bool
ZorbaBase64DecodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t        lItem;
  Base64               lDecodedData;
  xqpStringStore_t     lResultString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lDecodedData = lItem->getBase64BinaryValue();
    lResultString = lDecodedData.decode().getStore();
    GENV_ITEMFACTORY->createString(result, lResultString);
    STACK_PUSH (true, state);
  }

  STACK_END (state);
}

bool
ZorbaBase64EncodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  Base64        lBase64;
  xqpStringStore* lTmpString;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState)) {
    lTmpString = lItem->getStringValueP();
    Base64::encode(lTmpString, lBase64);
    if (GENV_ITEMFACTORY->createBase64Binary(result, lBase64)) {
      STACK_PUSH (true, state);
    } else {
      ZORBA_ERROR_LOC(XQP0025_COULD_NOT_CREATE_ITEM, loc);
    } 
  }
  STACK_END (state);
}

#ifdef ZORBA_WITH_TIDY
bool
ZorbaTidyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;
  TidyDoc             tdoc;
  bool                ok;
  int                 rc = -1;
  TidyBuffer output = {0, 0, 0, 0};
  TidyBuffer errbuf = {0, 0, 0, 0};
  xqpStringStore_t    buf, err;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    tdoc = tidyCreate();

    ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
    if ( ok )
      rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
    if ( rc >= 0 )
      rc = tidyParseString( tdoc, item->getStringValue()->c_str() );     // Parse the input
    if ( rc >= 0 )
      rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
    if ( rc >= 0 )
      rc = tidyRunDiagnostics( tdoc );               // Kvetch
    if ( rc > 1 )                                    // If error, force output.
      rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
    if ( rc >= 0 )
      rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

    if ( rc >= 0 )
    {
      buf = new xqpStringStore((char*)output.bp, output.size);

      tidyBufFree( &output );
      tidyBufFree( &errbuf );
      tidyRelease( tdoc );

      STACK_PUSH(GENV_ITEMFACTORY->createString(result, buf), state );
//       if ( rc > 0 )
//         printf( "\nDiagnostics:\n\n%s", errbuf.bp );
//       printf( "\nAnd here is the result:\n\n%s", output.bp );
    }
    else
    {
      tidyBufFree( &output );
      tidyBufFree( &errbuf );
      tidyRelease( tdoc );
//       printf( "A severe error (%d) occurred.\n", rc );
      ZORBA_ERROR_LOC_PARAM(XQP0029_TIDY_ERROR, loc, "" , "");
    }
  }

  STACK_END (state);
}
#endif
} /* namespace zorba */
