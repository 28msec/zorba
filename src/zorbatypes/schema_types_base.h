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
#ifndef ZORBA_SCHEMA_TYPES_BASE_H
#define ZORBA_SCHEMA_TYPES_BASE_H

#include "zorbamisc/config/stdint.h"

#include "zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

//
// Mapping of built-in C++ language types (plus zstring) to XML schema types.
//
typedef zstring   xs_anyURI;
typedef bool      xs_boolean;
typedef int8_t    xs_byte;
typedef zstring   xs_ENTITIES;
typedef zstring   xs_ENTITY;
typedef zstring   xs_ID;
typedef zstring   xs_IDREF;
typedef zstring   xs_IDREFS;
typedef int32_t   xs_int;
typedef zstring   xs_language;
typedef int64_t   xs_long;
typedef zstring   xs_Name;
typedef zstring   xs_NCName;
typedef zstring   xs_NMTOKEN;
typedef zstring   xs_NMTOKENS;
typedef zstring   xs_normalizedString;
typedef zstring   xs_NOTATION;
typedef zstring   xs_QName;
typedef int16_t   xs_short;
typedef zstring   xs_string;
typedef zstring   xs_token;
typedef uint8_t   xs_unsignedByte;
typedef uint32_t  xs_unsignedInt;
typedef uint64_t  xs_unsignedLong;
typedef uint16_t  xs_unsignedShort;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_SCHEMA_TYPES_BASE_H */
/* vim:set et sw=2 ts=2: */
