/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#ifndef ZORBA_STORE_UTIL_H
#define ZORBA_STORE_UTIL_H

#include <vector>

#include <zorba/internal/ztd.h>

#include "store/api/item.h"
#include "zorbatypes/zstring.h"

namespace zorba { 

///////////////////////////////////////////////////////////////////////////////

namespace ztd {

// Specialization of ztd::to_string() for store::Item.
inline zstring to_string( store::Item const &i ) {
  return i.toString();
}

// Specialization of ztd::to_string() for store::Item_t.
inline zstring to_string( store::Item_t const &i ) {
  return !i ? "<null>" : to_string( *i );
}

} // namespace ztd

///////////////////////////////////////////////////////////////////////////////

/**
 * Convenience function for getting the value for the given key of a JSON
 * object.
 *
 * @param object The JSON object to get the value from.
 * @param key The key to get the value for.
 * @return Returns said value.
 */
store::Item_t get_json_value( store::Item_t const &object, char const *key );

/**
 * Convenience function for getting the value of a given JSON object.
 *
 * @param object The JSON object to get the value from.
 * @param option_name The name of the option to get the value for.
 * @param result A pointer to the Item to receive the value.
 * @return Returns \c true only if the option is present.
 */
inline bool get_json_option( store::Item_t const &object,
                             char const *option_name,
                             store::Item_t *result ) {
  *result = get_json_value( object, option_name );
  return !result->isNull();
}

/**
 * Pushes a newly created string Item onto the back of the given vector.
 *
 * @param v A pointer to the vector to push the new Item onto the back of.
 * @param s The string to create the string Item from.
 */
void push_back( std::vector<store::Item_t> *v, char const *s );

/**
 * Pushes a newly created string Item onto the back of the given vector.
 *
 * @tparam The stiring type.
 * @param v A pointer to the vector to push the new Item onto the back of.
 * @param s The string to create the string Item from.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(StringType),void>::type
push_back( std::vector<store::Item_t> *v, StringType const &s ) {
  push_back( v, s.c_str() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_STORE_UTIL_H */
/* vim:set et sw=2 ts=2: */
