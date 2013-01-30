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

#ifndef ZORBA_JSON_UTIL_H
#define ZORBA_JSON_UTIL_H

#include <iostream>

#include <zorba/config.h>

#include "string_util.h"
#include "omanip.h"

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

/**
 * Serializes the given string as a valid JSON string: any characters that must
 * be escaped are escaped.
 *
 * @param os The ostream to serialize to.
 * @param s The C string to serialize as JSON.
 * @return Returns \a os.
 */
std::ostream& serialize( std::ostream &os, char const *s );

// An ostream manipulator version of the above.
DEF_OMANIP1( serialize, char const* )

/**
 * Serializes the given string as a valid JSON string: any characters that must
 * be escaped are escaped.
 *
 * @tparam The string type.
 * @param os The ostream to serialize to.
 * @param s The string to serialize as JSON.
 * @return Returns \a os.
 */
template<class StringType> inline
typename std::enable_if<ztd::has_c_str<StringType,
                          char const* (StringType::*)() const>::value,
                        std::ostream&>::type
serialize( std::ostream &os, StringType const &s ) {
  return serialize( os, s.c_str() );
}

// An ostream manipulator version of the above.
template<class StringType>
DEF_OMANIP1( serialize, StringType const& )

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

#endif /* ZORBA_JSON_UTIL_H */
/* vim:set et sw=2 ts=2: */
