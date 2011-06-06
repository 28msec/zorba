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

#pragma once
#ifndef ZORBA_SCHEMA_TYPES_H
#define ZORBA_SCHEMA_TYPES_H

#include "binary.h"
#include "decimal.h"
#include "floatimpl.h"
#include "integer.h"
#include "rchandle.h"
#include "zstring.h"

namespace zorba {

class DurationBase;
typedef rchandle<DurationBase> DurationBase_t;

///////////////////////////////////////////////////////////////////////////////

//
// Mapping of basic XML schema types to C++ language types.
//
typedef zstring       xs_anyURI;
typedef Base64        xs_base64Binary;
typedef bool          xs_boolean;
typedef char          xs_byte;
typedef DateTime      xs_date;
typedef DateTime      xs_dateTime;
typedef Duration      xs_dayTimeDuration;
typedef Decimal       xs_decimal;
typedef Double        xs_double;
typedef Duration      xs_duration;
typedef zstring       xs_ENTITIES;
typedef zstring       xs_ENTITY;
typedef Float         xs_float;
typedef DateTime      xs_gDay;
typedef DateTime      xs_gMonth;
typedef DateTime      xs_gMonthDay;
typedef DateTime      xs_gYear;
typedef DateTime      xs_gYearMonth;
typedef Base16        xs_hexBinary;
typedef zstring       xs_ID;
typedef zstring       xs_IDREF;
typedef zstring       xs_IDREFS;
typedef int32_t       xs_int;
typedef Integer       xs_integer;
typedef zstring       xs_language;
typedef int64_t       xs_long;
typedef zstring       xs_Name;
typedef zstring       xs_NCName;
typedef zstring       xs_NMTOKEN;
typedef zstring       xs_NMTOKENS;
typedef zstring       xs_normalizedString;
typedef zstring       xs_NOTATION;
typedef zstring       xs_QName;
typedef int16_t       xs_short;
typedef zstring       xs_string;
typedef DateTime      xs_time;
typedef zstring       xs_token;
typedef unsigned char xs_ubyte;
typedef uint32_t      xs_uint;
typedef Integer       xs_uinteger;
typedef uint64_t      xs_ulong;
typedef uint16_t      xs_ushort;
typedef Duration      xs_yearMonthDuration;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_SCHEMA_TYPES_H */
/* vim:set et sw=2 ts=2: */
