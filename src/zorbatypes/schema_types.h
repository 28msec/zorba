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
#include "schema_types_base.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

//
// Mapping of Zorba C++ classes to XML schema types.
//
typedef Base64    xs_base64Binary;
typedef DateTime  xs_date;
typedef DateTime  xs_dateTime;
typedef Duration  xs_dayTimeDuration;
typedef Decimal   xs_decimal;
typedef Double    xs_double;
typedef Duration  xs_duration;
typedef Float     xs_float;
typedef DateTime  xs_gDay;
typedef DateTime  xs_gMonth;
typedef DateTime  xs_gMonthDay;
typedef DateTime  xs_gYear;
typedef DateTime  xs_gYearMonth;
typedef Base16    xs_hexBinary;
typedef Integer   xs_integer;
typedef Integer   xs_negativeInteger;     // this isn't quite right
typedef UInteger  xs_nonNegativeInteger;  // i.e., "unsigned"
typedef Integer   xs_nonPositiveInteger;  // this isn't quite right either
typedef UInteger  xs_positiveInteger;
typedef DateTime  xs_time;
typedef UInteger  xs_uinteger;            // old, deprecated name
typedef Duration  xs_yearMonthDuration;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_SCHEMA_TYPES_H */
/* vim:set et sw=2 ts=2: */
