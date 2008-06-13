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
#include "capi/item_factory.h"
#include "capi/item.h"
#include <zorba/zorba.h>
#include "zorbaerrors/error_manager.h"

using namespace zorba;

#define ITEMFACTORY_TRY try {
#define ITEMFACTORY_CATCH \
    return XQ_NO_ERROR;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }
 
#define FF static_cast<zorba::ItemFactory*>(factory->data)

namespace zorbac {

  XQUERY_ERROR
  ItemFactory::create_string(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      if (!*item) {
        std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
        std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

        lInnerItem->theItem = FF->createString(str);

        Item::assign_functions(lItem.get());

        (*item) = lItem.release();
        (*item)->data = lInnerItem.release();
      } else {
        static_cast<zorbac::Item*>((*item)->data)->theItem = FF->createString(str);
      }
      if (static_cast<zorbac::Item*>((*item)->data)->theItem.isNull()) 
        ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_anyuri(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createAnyURI(str);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_qname2(XQC_ItemFactory factory, 
                             const char* uri, 
                             const char* localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createQName(uri, localname);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_qname3(XQC_ItemFactory factory,
                             const char* uri, 
                             const char* prefix, 
                             const char* localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createQName(uri, prefix, localname);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item) 
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createBoolean(boolean != 0);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_ncname(XQC_ItemFactory factory, const char* ncname, XQC_Item_Ref item) 
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createNCName(ncname);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR 
  ItemFactory::create_base64binary(XQC_ItemFactory factory, const char* binary_data, size_t length, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createBase64Binary(binary_data, length);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR 
  ItemFactory::create_decimal(XQC_ItemFactory factory, double value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDecimalFromDouble(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR 
  ItemFactory::create_decimal_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDecimal(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_integer(XQC_ItemFactory factory, long long integer_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createInteger(integer_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_integer_char(XQC_ItemFactory factory, const char* integer_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createInteger(integer_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_long(XQC_ItemFactory factory, long long long_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createLong(long_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_int(XQC_ItemFactory factory, int int_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createInt(int_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_short(XQC_ItemFactory factory, short short_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createShort(short_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_byte(XQC_ItemFactory factory, char byte_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createByte(byte_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_date_char(XQC_ItemFactory factory, const char* date_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDate(date_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_date(XQC_ItemFactory factory, short year, short month, short day, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDate(year, month, day);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_datetime(XQC_ItemFactory factory, short year, short month, short day, 
                     short hour, short minute, double second, short timezone_hours, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDateTime(year, month, day, hour, minute, second, timezone_hours);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_datetime_char(XQC_ItemFactory factory, const char* datetime_value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDateTime(datetime_value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_double(XQC_ItemFactory factory, double value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDouble(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_double_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDouble(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_duration(XQC_ItemFactory factory, short year, short months, short days, 
                      short hours, short minutes, double seconds, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createDuration(year, months, days, hours, minutes, seconds);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_float(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createFloat(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_gday(XQC_ItemFactory factory, short day, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createGDay(day);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_gmonth(XQC_ItemFactory factory, short month, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createGMonth(month);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_gmonthday(XQC_ItemFactory factory, short month, short day, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createGMonthDay(month, day);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_gyear(XQC_ItemFactory factory, short year, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createGYear(year);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_gyearmonth(XQC_ItemFactory factory, short year, short month, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createGYearMonth(year, month);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_hexbinary(XQC_ItemFactory factory, const char* hex_data, size_t size, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createHexBinary(hex_data, size);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_negativeinteger(XQC_ItemFactory factory, long long value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createNegativeInteger(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_nonnegativeinteger(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createNonPositiveInteger(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_nonpositiveinteger(XQC_ItemFactory factory, long long value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createNonPositiveInteger(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_positiveinteger(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createPositiveInteger(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  XQUERY_ERROR
  ItemFactory::create_time_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createTime(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_time(XQC_ItemFactory factory, short hour, short minute, double second, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createTime(hour, minute, second);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_time_timezone(XQC_ItemFactory factory, short hour, short minute, double second, short timezone_hours, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createTime(hour, minute, second, timezone_hours);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_unsignedbyte(XQC_ItemFactory factory, const unsigned char value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createUnsignedByte(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_unsignedint(XQC_ItemFactory factory, unsigned int value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createUnsignedInt(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_unsignedlong(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createUnsignedLong(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_unsignedshort(XQC_ItemFactory factory, unsigned short value, XQC_Item_Ref item )
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createUnsignedShort(value);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  void
  ItemFactory::free(XQC_ItemFactory factory)
  {
    delete factory;
  }

  void
  ItemFactory::assign_functions(XQC_ItemFactory factory)
  {
    factory->create_string             = zorbac::ItemFactory::create_string;
    factory->create_anyuri             = zorbac::ItemFactory::create_anyuri;
    factory->create_qname2             = zorbac::ItemFactory::create_qname2;
    factory->create_qname3             = zorbac::ItemFactory::create_qname3;
    factory->create_boolean            = zorbac::ItemFactory::create_boolean;
    factory->create_ncname             = zorbac::ItemFactory::create_ncname;
    factory->create_base64binary       = zorbac::ItemFactory::create_base64binary;
    factory->create_decimal            = zorbac::ItemFactory::create_decimal;
    factory->create_decimal_char       = zorbac::ItemFactory::create_decimal_char;
    factory->create_integer            = zorbac::ItemFactory::create_integer;
    factory->create_integer_char       = zorbac::ItemFactory::create_integer_char;
    factory->create_long               = zorbac::ItemFactory::create_long;
    factory->create_int                = zorbac::ItemFactory::create_int;
    factory->create_short              = zorbac::ItemFactory::create_short;
    factory->create_byte               = zorbac::ItemFactory::create_byte;
    factory->create_date               = zorbac::ItemFactory::create_date;
    factory->create_date               = zorbac::ItemFactory::create_date;
    factory->create_datetime           = zorbac::ItemFactory::create_datetime;
    factory->create_datetime_char      = zorbac::ItemFactory::create_datetime_char;
    factory->create_double             = zorbac::ItemFactory::create_double;
    factory->create_double_char        = zorbac::ItemFactory::create_double_char;
    factory->create_duration           = zorbac::ItemFactory::create_duration;
    factory->create_float              = zorbac::ItemFactory::create_float;
    factory->create_gday               = zorbac::ItemFactory::create_gday;
    factory->create_gmonth             = zorbac::ItemFactory::create_gmonth;
    factory->create_gmonthday          = zorbac::ItemFactory::create_gmonthday;
    factory->create_gyear              = zorbac::ItemFactory::create_gyear;
    factory->create_gyearmonth         = zorbac::ItemFactory::create_gyearmonth;
    factory->create_hexbinary          = zorbac::ItemFactory::create_hexbinary;
    factory->create_negativeinteger    = zorbac::ItemFactory::create_negativeinteger;
    factory->create_nonnegativeinteger = zorbac::ItemFactory::create_nonnegativeinteger;
    factory->create_nonpositiveinteger = zorbac::ItemFactory::create_nonpositiveinteger;
    factory->create_positiveinteger    = zorbac::ItemFactory::create_positiveinteger;
    factory->create_time_char          = zorbac::ItemFactory::create_time_char;
    factory->create_time               = zorbac::ItemFactory::create_time;
    factory->create_time_timezone      = zorbac::ItemFactory::create_time_timezone;
    factory->create_unsignedbyte       = zorbac::ItemFactory::create_unsignedbyte;
    factory->create_unsignedint        = zorbac::ItemFactory::create_unsignedint;
    factory->create_unsignedlong       = zorbac::ItemFactory::create_unsignedlong;
    factory->create_unsignedshort      = zorbac::ItemFactory::create_unsignedshort;
    factory->free                      = zorbac::ItemFactory::free;
  }


} /* namespace zorbac */
