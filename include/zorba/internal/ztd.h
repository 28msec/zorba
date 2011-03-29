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

#ifndef ZORBA_INTERNAL_ZTD_H
#define ZORBA_INTERNAL_ZTD_H

#include <sstream>

namespace zorba {
namespace internal {
namespace ztd {

////////// c_str() /////////////////////////////////////////////////////////////

/**
 * Gets the \c char* to the given string.
 * 
 * @tparam StringType The string's type.
 * @param s The string to get the \c char* of.
 * @return Returns said \c char*.
 */
template<class StringType> inline
typename StringType::const_pointer c_str( StringType const &s ) {
  return s.c_str();
}

/**
 * Specialization of global c_str() for \c char* argument.
 *
 * @param s The C string to get the \c char* of.
 * @return Returns said \c char*.
 */
inline char const* c_str( char const *s ) {
  return s;
}

////////// To-string conversion ////////////////////////////////////////////////

/**
 * \internal
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
 * \internal
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

} // namespace ztd
} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_ZTD_H */
/* vim:set et sw=2 ts=2: */
