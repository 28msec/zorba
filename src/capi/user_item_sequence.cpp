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
#include "capi/error.h"
#include "capi/capi_util.h"
#include "capi/csequence.h"
#include "capi/user_item_sequence.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/item_sequence.h>

using namespace zorba;

#define ZIS_TRY CAPI_TRY(UserItemSequence,setter)
#define ZIS_CATCH CAPI_CATCH

namespace zorbac {

  UserItemSequence::UserItemSequence
  (XQC_Sequence** args, unsigned int argc,
    external_function_init init_fn, external_function_next next_fn,
    external_function_free free_fn, void* sequence_data, ItemFactory* factory,
    XQC_ErrorHandler* handler)
    : theArgs(args),
      theArgc(argc),
      theInitFunction(init_fn),
      theNextFunction(next_fn),
      theFreeFunction(free_fn),
      theSequenceData(sequence_data),
      theFactory(factory),
      theErrorHandler(handler)
  {
    memset(&theItemSetter, 0, sizeof(Zorba_ItemSetter));
    theItemSetter.set_string  = UserItemSequence::set_string;
    theItemSetter.set_integer = UserItemSequence::set_integer;
    theItemSetter.set_double  = UserItemSequence::set_double;

    if (theInitFunction) {
      theInitFunction(&theUserData, theSequenceData);
    }
  }

  UserItemSequence::~UserItemSequence()
  {
    if (theFreeFunction) {
      theFreeFunction(theUserData, theSequenceData);
    }
    for (unsigned int i = 0; i < theArgc; i++) {
      theArgs[i]->free(theArgs[i]);
    }
    delete[] theArgs;
  }

  UserItemSequence*
  UserItemSequence::get(Zorba_ItemSetter* setter)
  {
    return (UserItemSequence*)
      (((char*)setter) - CLASS_OFFSET(UserItemSequence, theItemSetter));
  }

  bool
  UserItemSequence::next(zorba::Item& i)
  {
    XQC_Error lRes = theNextFunction(theArgs, theArgc, &theItemSetter,
      theUserData, theSequenceData);
    if (lRes == XQC_END_OF_SEQUENCE)
      return false;
    if (lRes != XQC_NO_ERROR) {
      ZORBA_ERROR(XQP0019_INTERNAL_ERROR);
    }

    // theItem will have been set by the user calling back to one
    // of the Zorba_ItemSetter methods.
    i = theItem;
    assert (!i.isNull());

    return true;
  }

  // Zorba_ItemSetter methods

  XQC_Error
  UserItemSequence::set_string(Zorba_ItemSetter* setter, const char* value)
  {
    ZIS_TRY {
      me->theItem = me->theFactory->createString(value);
    }
    ZIS_CATCH;
  }

  XQC_Error
  UserItemSequence::set_integer(Zorba_ItemSetter* setter, int value)
  {
    ZIS_TRY {
      me->theItem = me->theFactory->createInt(value);
    }
    ZIS_CATCH;
  }

  XQC_Error
  UserItemSequence::set_double(Zorba_ItemSetter* setter, double value)
  {
    ZIS_TRY {
      me->theItem = me->theFactory->createDouble(value);
    }
    ZIS_CATCH;
  }
} /* namespace zorbac */
