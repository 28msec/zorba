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
#ifndef ZORBA_REPRESENTATIONS_H
#define ZORBA_REPRESENTATIONS_H

#include "zorbatypes/xqpstring.h"
//#include "zorbatypes/duration.h"
//#include "zorbatypes/datetime.h"
//#include "zorbatypes/gregorian.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/binary.h"

namespace zorba
{
  class DurationBase;
  typedef rchandle<DurationBase> DurationBase_t;
  /*______________________________________________________________________
  |
  | The mapping of basic schema types to C++ language types.
  |_______________________________________________________________________*/
  typedef xqpString           xqp_QName;
  typedef xqpString           xqp_NOTATION;
  typedef xqpString           xqp_anyURI;
  typedef xqpString           xqp_string;
  typedef xqpString           xqp_normalizedString;
  typedef xqpString           xqp_token;
  typedef xqpString           xqp_language;
  typedef xqpString           xqp_Name;
  typedef xqpString           xqp_NCName;
  typedef xqpString           xqp_ID;
  typedef xqpString           xqp_IDREF;
  typedef xqpString           xqp_IDREFS;
  typedef xqpString           xqp_ENTITY;
  typedef xqpString           xqp_ENTITIES;
  typedef xqpString           xqp_NMTOKEN;
  typedef xqpString           xqp_NMTOKENS;
  typedef Integer             xqp_integer;
  typedef Integer             xqp_uinteger;
  typedef int32_t             xqp_int;
  typedef uint32_t            xqp_uint;
  typedef long long           xqp_long;
  typedef unsigned long long  xqp_ulong;
  typedef short               xqp_short;
  typedef unsigned short      xqp_ushort;
  typedef char                xqp_byte;
  typedef unsigned char       xqp_ubyte;
  typedef Decimal             xqp_decimal;
  typedef Float               xqp_float;
  typedef Double              xqp_double;
  typedef bool                xqp_boolean;
  typedef DateTime            xqp_dateTime;
  typedef DateTime            xqp_date;
  typedef DateTime            xqp_time;
  typedef DateTime            xqp_gYearMonth;
  typedef DateTime            xqp_gYear;
  typedef DateTime            xqp_gMonthDay;
  typedef DateTime            xqp_gDay;
  typedef DateTime            xqp_gMonth;
  typedef DurationBase_t      xqp_duration;
  typedef DayTimeDuration_t   xqp_dayTimeDuration;
  typedef YearMonthDuration_t xqp_yearMonthDuration;
  typedef Base64              xqp_base64Binary;
  typedef Base16              xqp_hexBinary;

} /* namespace zorba */
#endif /* ZORBA_REPRESENTATIONS_H */
