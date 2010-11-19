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

#include "zorbatypes/binary.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/zstring.h"

namespace zorba {

  class DurationBase;
  typedef rchandle<DurationBase> DurationBase_t;

  //
  // Mapping of basic schema types to C++ language types.
  //
  typedef zstring       xqp_anyURI;
  typedef Base64        xqp_base64Binary;
  typedef bool          xqp_boolean;
  typedef char          xqp_byte;
  typedef DateTime      xqp_date;
  typedef DateTime      xqp_dateTime;
  typedef Duration      xqp_dayTimeDuration;
  typedef Decimal       xqp_decimal;
  typedef Double        xqp_double;
  typedef Duration      xqp_duration;
  typedef zstring       xqp_ENTITIES;
  typedef zstring       xqp_ENTITY;
  typedef Float         xqp_float;
  typedef DateTime      xqp_gDay;
  typedef DateTime      xqp_gMonth;
  typedef DateTime      xqp_gMonthDay;
  typedef DateTime      xqp_gYear;
  typedef DateTime      xqp_gYearMonth;
  typedef Base16        xqp_hexBinary;
  typedef zstring       xqp_ID;
  typedef zstring       xqp_IDREF;
  typedef zstring       xqp_IDREFS;
  typedef int32_t       xqp_int;
  typedef Integer       xqp_integer;
  typedef zstring       xqp_language;
  typedef int64_t       xqp_long;
  typedef zstring       xqp_Name;
  typedef zstring       xqp_NCName;
  typedef zstring       xqp_NMTOKEN;
  typedef zstring       xqp_NMTOKENS;
  typedef zstring       xqp_normalizedString;
  typedef zstring       xqp_NOTATION;
  typedef zstring       xqp_QName;
  typedef int16_t       xqp_short;
  typedef zstring       xqp_string;
  typedef DateTime      xqp_time;
  typedef zstring       xqp_token;
  typedef unsigned char xqp_ubyte;
  typedef uint32_t      xqp_uint;
  typedef Integer       xqp_uinteger;
  typedef uint64_t      xqp_ulong;
  typedef uint16_t      xqp_ushort;
  typedef Duration      xqp_yearMonthDuration;

} // namespace zorba
#endif /* ZORBA_REPRESENTATIONS_H */
/* vim:set et sw=2 ts=2: */
