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

#ifndef ZORBA_UNICODE_UTIL_H
#define ZORBA_UNICODE_UTIL_H

#include <unicode/ustring.h>

namespace zorba {

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
                      int32_t *utf16_len_ptr );

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
                     int32_t *utf8_len_ptr );

} // namespace zorba
#endif /* ZORBA_UNICODE_UTIL_H */
/* vim:set et sw=2 ts=2: */
