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

#include <zorba/error.h>

#include "zorbautils/unicode_util.h"

#include "zorbaerrors/error_manager.h"

using namespace std;
U_NAMESPACE_USE

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

UChar32 const SubChar = 0xFFFD;         // replacement character

/**
 * Converts a UTF-8 string to UTF-16.
 *
 * @param utf8_s          The UTF-8 string to convert.  It need not be
 *                        null-terminated.
 * @param utf8_len        The length of the UTF-8 string.
 * @param utf16_len_ptr   A pointer to an int32_t to receive the length of the
 *                        UTF-16 string.
 *
 * @return Returns a pointer to the UTF-16 string.  It is not null-terminated.
 * The caller is responsible for deleting the string.
 */
UChar* utf8_to_utf16( char const *utf8_s, int32_t utf8_len,
                      int32_t *utf16_len_ptr ) {
  int32_t utf16_len;
  UErrorCode err = U_ZERO_ERROR;
  u_strFromUTF8WithSub(                 // pre-flight to get utf16_len
    NULL, 0, &utf16_len,
    utf8_s, utf8_len,
    SubChar, NULL,
    &err
  );
  // must not check "err" here since ICU always returns "buffer overflow"

  UChar *const utf16_buf = new UChar[ utf16_len ];
  err = U_ZERO_ERROR;
  u_strFromUTF8WithSub(
    utf16_buf, utf16_len, utf16_len_ptr,
    utf8_s, utf8_len,
    SubChar, NULL,
    &err
  );
  if ( U_FAILURE( err ) )
    ZORBA_ERROR( XQP0034_ILLEGAL_UTF8_BYTE );
  return utf16_buf;
}

/**
 * Converts a UTF-16 string to UTF-8.
 *
 * @param utf16_s         The UTF-16 string to convert.  It need not be
 *                        null-terminated.
 * @param utf16_len       The length of the UTF-8 string.
 * @param utf8_len_ptr    A pointer to an int32_t to receive the length of the
 *                        UTF-8 string.
 *
 * @return Returns a pointer to the UTF-8 string.  It is not null-terminated.
 * The caller is responsible for deleting the string.
 */
char* utf16_to_utf8( UChar const *utf16_s, int32_t utf16_len,
                     int32_t *utf8_len_ptr ) {
  int32_t utf8_len;
  UErrorCode err = U_ZERO_ERROR;
  u_strToUTF8WithSub(                   // pre-flight to get utf8_len
    NULL, 0, &utf8_len,
    utf16_s, utf16_len,
    SubChar, NULL,
    &err
  );
  // must not check "err" here since ICU always returns "buffer overflow"

  char *const utf8_buf = new char[ utf8_len ];
  err = U_ZERO_ERROR;
  u_strToUTF8WithSub(
    utf8_buf, utf8_len, utf8_len_ptr,
    utf16_s, utf16_len,
    SubChar, NULL,
    &err
  );
  if ( U_FAILURE( err ) )
    ZORBA_ERROR( XQP0035_ILLEGAL_UTF16_BYTE );
  return utf8_buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
