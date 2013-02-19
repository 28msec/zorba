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
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "stdafx.h"
#include <zorba/store_consts.h>

namespace zorba {
namespace store {

///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<( std::ostream &o, SchemaTypeCode c ) {
  static char const *const s[] = {
    "xs:anyAtomicType",       // 0
    "xs:string",              // 1
    "xs:normalizedString",    // 2
    "xs:token",               // 3
    "xs:language",            // 4
    "xs:NMTOKEN",             // 5
    "xs:Name",                // 6
    "xs:NCName",              // 7
    "xs:ID",                  // 8
    "xs:IDREF",               // 9
    "xs:ENTITY",              // 10
    "xs:untypedAtomic",       // 11
    "xs:dateTime",            // 12
    "xs:date",                // 13
    "xs:time",                // 14
    "xs:duration",            // 15
    "xs:dayTimeDuration",     // 16
    "xs:yearMonthDuration",   // 17
    "xs:float",               // 18
    "xs:double",              // 19
    "xs:decimal",             // 20
    "xs:integer",             // 21
    "xs:nonPositiveInteger",  // 22
    "xs:negativeInteger",     // 23
    "xs:long",                // 24
    "xs:int",                 // 25
    "xs:short",               // 26
    "xs:byte",                // 27
    "xs:nonNegativeInteger",  // 28
    "xs:unsignedLong",        // 29
    "xs:unsignedInt",         // 30
    "xs:unsignedShort",       // 31
    "xs:unsignedByte",        // 32
    "xs:positiveInteger",     // 33
    "xs:gYearMonth",          // 34
    "xs:gYear",               // 35
    "xs:gMonthDay",           // 36
    "xs:gDay",                // 37
    "xs:gMonth",              // 38
    "xs:boolean",             // 39
    "xs:base64Binary",        // 40
    "xs:hexBinary",           // 41
    "xs:anyURI",              // 42
    "xs:QNAME",               // 43
    "xs:NOTATION",            // 44
    "js:null",                // 45
    "xs:dateTimeStamp",       // 46
  };

  if ( c >= 0 && c < XS_LAST )
    o << s[ c ];
  else
    o << "[illegal type code: " << (int)c << ']';

  return o;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace store
} // namespace zorba

/* vim:set et sw=2 ts=2: */
