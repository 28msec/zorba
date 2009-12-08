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
#ifndef ZORBAC_ITEM_FACTORY_H
#define ZORBAC_ITEM_FACTORY_H

#include <zorba/zorbac.h>

namespace zorbac {

  class ItemFactory {
    public:
      static XQC_Error
      create_string(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

      static XQC_Error
      create_anyuri(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

      static XQC_Error
      create_qname2(XQC_ItemFactory factory, const char* uri, const char* localname, XQC_Item_Ref item); 
      
      static XQC_Error
      create_qname3(XQC_ItemFactory factory, 
                    const char* uri, const char* prefix,
                    const char* localname, XQC_Item_Ref item); 

      static XQC_Error
      create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item); 

      static XQC_Error
      create_ncname(XQC_ItemFactory factory, const char* ncname, XQC_Item_Ref item); 

      static XQC_Error 
      create_base64binary(XQC_ItemFactory factory, const char* binary_data, size_t length, XQC_Item_Ref item );
      
      static XQC_Error 
      create_decimal(XQC_ItemFactory factory, double value, XQC_Item_Ref item );

      static XQC_Error 
      create_decimal_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item );

      static XQC_Error
      create_integer(XQC_ItemFactory factory, long long integer_value, XQC_Item_Ref item );

      static XQC_Error
      create_integer_char(XQC_ItemFactory factory, const char* integer_value, XQC_Item_Ref item );
      
      static XQC_Error
      create_long(XQC_ItemFactory factory, long long long_value, XQC_Item_Ref item );
      
      static XQC_Error
      create_int(XQC_ItemFactory factory, int int_value, XQC_Item_Ref item );
      
      static XQC_Error
      create_short(XQC_ItemFactory factory, short short_value, XQC_Item_Ref item );
      
      static XQC_Error
      create_byte(XQC_ItemFactory factory, char byte_value, XQC_Item_Ref item );
      
      static XQC_Error
      create_date_char(XQC_ItemFactory factory, const char* date_value, XQC_Item_Ref item );

      static XQC_Error
      create_date(XQC_ItemFactory factory, short year, short month, short day, XQC_Item_Ref item );
      
      static XQC_Error
      create_datetime(XQC_ItemFactory factory, short year, short month, short day, 
                         short hour, short minute, double second, short timezone_hours, XQC_Item_Ref item );

      static XQC_Error
      create_datetime_char(XQC_ItemFactory factory, const char* datetime_value, XQC_Item_Ref item );

      static XQC_Error
      create_double(XQC_ItemFactory factory, double value, XQC_Item_Ref item );

      static XQC_Error
      create_double_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item );
      
      static XQC_Error
      create_duration(XQC_ItemFactory factory, short year, short months, short days, 
                          short hours, short minutes, double seconds, XQC_Item_Ref item );
      
      static XQC_Error
      create_float(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item );
      
      static XQC_Error
      create_gday(XQC_ItemFactory factory, short day, XQC_Item_Ref item );
      
      static XQC_Error
      create_gmonth(XQC_ItemFactory factory, short month, XQC_Item_Ref item );
      
      static XQC_Error
      create_gmonthday(XQC_ItemFactory factory, short month, short day, XQC_Item_Ref item );
      
      static XQC_Error
      create_gyear(XQC_ItemFactory factory, short year, XQC_Item_Ref item );
      
      static XQC_Error
      create_gyearmonth(XQC_ItemFactory factory, short year, short month, XQC_Item_Ref item );
      
      static XQC_Error
      create_hexbinary(XQC_ItemFactory factory, const char* hex_data, size_t size, XQC_Item_Ref item );
      
      static XQC_Error
      create_negativeinteger(XQC_ItemFactory factory, long long value, XQC_Item_Ref item );

      static XQC_Error
      create_nonnegativeinteger(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item );

      static XQC_Error
      create_nonpositiveinteger(XQC_ItemFactory factory, long long value, XQC_Item_Ref item );

      static XQC_Error
      create_positiveinteger(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item );

      static XQC_Error
      create_time_char(XQC_ItemFactory factory, const char* value, XQC_Item_Ref item );
      
      static XQC_Error
      create_time(XQC_ItemFactory factory, short hour, short minute, double second, XQC_Item_Ref item );
      
      static XQC_Error
      create_time_timezone(XQC_ItemFactory factory, 
                           short hour, short minute, double second, short timezone_hours, XQC_Item_Ref item );
      
      static XQC_Error
      create_unsignedbyte(XQC_ItemFactory factory, const unsigned char value, XQC_Item_Ref item );
      
      static XQC_Error
      create_unsignedint(XQC_ItemFactory factory, unsigned int value, XQC_Item_Ref item );
      
      static XQC_Error
      create_unsignedlong(XQC_ItemFactory factory, unsigned long long value, XQC_Item_Ref item );
      
      static XQC_Error
      create_unsignedshort(XQC_ItemFactory factory, unsigned short value, XQC_Item_Ref item );

      static void
      free(XQC_ItemFactory factory);

      static void
      assign_functions(XQC_ItemFactory factory);

  }; /* class ItemFactory */

} /* namespace zorbac */

#endif

