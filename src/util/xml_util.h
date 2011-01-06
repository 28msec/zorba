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

#ifndef ZORBA_XML_UTIL_H
#define ZORBA_XML_UTIL_H

#include "unicode_util.h"
#include "utf8_util.h"

namespace zorba {
namespace xml {

////////// types //////////////////////////////////////////////////////////////

/**
 * XML versions.
 */
enum version {
  v1_0,
  v1_1
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Checks whether the given code-point is valid for the given XML version.
 *
 * @param v The XML version to use.
 * @return Returns \c true only if the code-point is valid.
 */
template<class CodePointType>
inline bool is_valid( CodePointType c, version v = v1_0 ) {
  //
  // See "Extensible Markup Language (XML) 1.0 (Fifth Edition)", and
  // "Extensible Markup Language (XML) 1.1 (Second Edition)", section 2.2,
  // "Characters", [2] Char.
  //
  return  (c >= 0x000020 && c <= 0x00D7FF)  // common case first
      ||  (c == 0x9 || c == 0xA || c == 0xD)
      ||  (c >= 0x00E000 && c <= 0x00FFFD)
      ||  (c >= 0x010000 && c <= 0x10FFFF)
      ||  (v == v1_1 && c >= 0x01 && c <= 0x1F);
}

/**
 * Parses an XML entity reference.
 *
 * @param ref The C string pointing to the start of the entity reference.
 * @param c A pointer to the code-point result.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
ZORBA_DLL_PUBLIC
int parse_entity( char const *ref, unicode::code_point *c );

/**
 * Parses an XML entity reference and appends the UTF-8 encoding of the
 * resulting code-point to the given string.
 *
 * @tparam StringType The type of the output string.
 * @param ref The C string pointing to the start of the entity reference.
 * @param out A string to append to.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
template<class StringType> inline
int parse_entity( char const *ref, StringType *out ) {
  unicode::code_point c;
  int const result = parse_entity( ref, &c );
  if ( result != -1 )
    utf8::encode( c, out );
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

#endif /* ZORBA_XML_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
