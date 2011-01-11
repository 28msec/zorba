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

#ifndef ZORBA_STRING_UTIL_H
#define ZORBA_STRING_UTIL_H

#include <cstring>
#include <sstream>
#include <string>

namespace zorba {

////////// String equality /////////////////////////////////////////////////////

/**
 * Faster C string equals.
 *
 * @param s1 The first string.
 * @param s2 The second NULL-terminated C string.
 * @param s2_n The number of characters to compare of \a s2.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
template<class StringType> inline
bool equals( StringType const &s1, char const *s2,
             typename StringType::size_type s2_n ) {
  typedef typename StringType::traits_type traits_type;
  return s1.size() == s2_n && traits_type::compare( s1.data(), s2, s2_n ) == 0;
}

/**
 * Faster C string equals.
 *
 * @param s1 The first NULL-terminated string.
 * @param s1_n The number of characters to compare of \a s1.
 * @param s2 The second string.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
template<class StringType> inline
bool equals( char const *s1, typename StringType::size_type s1_n,
             StringType const &s2 ) {
  typedef typename StringType::traits_type traits_type;
  return s1_n == s2.size() && traits_type::compare( s1, s2.data(), s1_n ) == 0;
}

/**
 * A macro for calling equals() with a second argument of a string literal.
 */
#define ZSTREQ(STRING,LITERAL) \
        zorba::equals( STRING, LITERAL, sizeof( LITERAL ) - 1 )

////////// To-string conversion ////////////////////////////////////////////////

/**
 * Converts an object to its string representation.
 *
 * @tparam T The object type.
 * @param t The object.
 * @return Returns a string representation of the object.
 */
template<typename T> inline
std::string to_string( T const &t ) {
  std::ostringstream o;
  o << t;
  return o.str();
}

/**
 * Converts an object to its string representation.
 *
 * @tparam T The object type.
 * @param t The object.
 * @Param out The string to receive the representation.
 */
template<typename T,class StringType> inline
void to_string( T const &t, StringType *out ) {
  std::ostringstream o;
  o << t;
  *out = o.str();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_STRING_UTIL_H */
/* vim:set et sw=2 ts=2: */
