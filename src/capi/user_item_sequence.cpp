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

#include <map>

#include "capi/error.h"
#include "capi/csequence.h"
#include "capi/user_item_sequence.h"
#include "diagnostics/xquery_diagnostics.h"
#include <zorba/item_sequence.h>
#include "diagnostics/assert.h"

using namespace zorba;

#define ZIS_TRY CAPI_TRY(UserItemSequence,setter)
#define ZIS_CATCH CAPI_CATCH

// pointer-to-members are eeeevil
typedef Item (ItemFactory::*ItemFactoryMemFn)(const String& aString);
#define CALL_ITEMFACTORY_FN(object,ptrToMember) ((object).*(ptrToMember))

namespace zorbac {

  namespace FactoryCreators {

    // Maps XQC_ItemTypes to from-string item create method
    static std::map<XQC_ItemType, ItemFactoryMemFn> methods;

    class CreatorInitializer {
      public:
        CreatorInitializer()
        {
          methods[XQC_ANY_URI_TYPE] = &ItemFactory::createAnyURI;
          methods[XQC_DATE_TYPE] = &ItemFactory::createDate;
          methods[XQC_DATE_TIME_TYPE] = &ItemFactory::createDateTime;
          methods[XQC_DECIMAL_TYPE] = &ItemFactory::createDecimal;
          methods[XQC_DOUBLE_TYPE] = &ItemFactory::createDouble;
          methods[XQC_DURATION_TYPE] = &ItemFactory::createDuration;
          methods[XQC_FLOAT_TYPE] = &ItemFactory::createFloat;
          methods[XQC_G_DAY_TYPE] = &ItemFactory::createGDay;
          methods[XQC_G_MONTH_TYPE] = &ItemFactory::createGMonth;
          methods[XQC_G_MONTH_DAY_TYPE] = &ItemFactory::createGMonthDay;
          methods[XQC_G_YEAR_TYPE] = &ItemFactory::createGYear;
          methods[XQC_G_YEAR_MONTH_TYPE] = &ItemFactory::createGYearMonth;
          methods[XQC_STRING_TYPE] = &ItemFactory::createString;
          methods[XQC_TIME_TYPE] = &ItemFactory::createTime;
        }
    };

    // Instance exists only to initialize methods
    static CreatorInitializer initer;
  } /* namespace FactoryCreators */

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
    theItemSetter.set_string      = UserItemSequence::set_string;
    theItemSetter.set_integer     = UserItemSequence::set_integer;
    theItemSetter.set_double      = UserItemSequence::set_double;
    theItemSetter.set_typed_value = UserItemSequence::set_typed_value;

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

  Iterator_t UserItemSequence::getIterator()
  {
    return new InternalIterator(this);
  }

  UserItemSequence::InternalIterator::InternalIterator(UserItemSequence  *item_sequence) : theItemSequence(item_sequence)
  {
    is_open = false;
  }

  void UserItemSequence::InternalIterator::open()
  {
    is_open = true;
    if (theItemSequence->theInitFunction) {
      theItemSequence->theInitFunction(&theItemSequence->theUserData, theItemSequence->theSequenceData);
    }
  }

  void UserItemSequence::InternalIterator::close()
  {
    is_open = false;
  }

  bool UserItemSequence::InternalIterator::isOpen() const
  {
    return is_open;
  }

  bool
  UserItemSequence::InternalIterator::next(Item& i)
  {
    ZORBA_ASSERT(is_open);
    XQC_Error lRes = theItemSequence->theNextFunction(
                                  theItemSequence->theArgs, 
                                  theItemSequence->theArgc, 
                                  &theItemSequence->theItemSetter,
                                  theItemSequence->theUserData, 
                                  theItemSequence->theSequenceData);
    if (lRes == XQC_END_OF_SEQUENCE)
      return false;
    if (lRes != XQC_NO_ERROR)
      throw ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR );

    // theItem will have been set by the user calling back to one
    // of the Zorba_ItemSetter methods.
    i = theItemSequence->theItem;
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

  XQC_Error
  UserItemSequence::set_typed_value(Zorba_ItemSetter* setter, XQC_ItemType type,
    const char* value)
  {
    ZIS_TRY {
      switch (type) {
        case XQC_ANY_URI_TYPE:
        case XQC_DATE_TYPE:
        case XQC_DATE_TIME_TYPE:
        case XQC_DECIMAL_TYPE:
        case XQC_DOUBLE_TYPE:
        case XQC_DURATION_TYPE:
        case XQC_FLOAT_TYPE:
        case XQC_G_DAY_TYPE:
        case XQC_G_MONTH_TYPE:
        case XQC_G_MONTH_DAY_TYPE:
        case XQC_G_YEAR_TYPE:
        case XQC_G_YEAR_MONTH_TYPE:
        case XQC_STRING_TYPE:
        case XQC_TIME_TYPE: {
          zorba::String lValue(value);
          me->theItem = CALL_ITEMFACTORY_FN
            (*(me->theFactory), FactoryCreators::methods[type])
            (lValue);
          break;
        }

        default:
          return XQC_NOT_IMPLEMENTED;
      }
    }
    ZIS_CATCH;
  }
} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
