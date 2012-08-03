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
#ifndef ZORBA_UUID_H
#define ZORBA_UUID_H

#include <algorithm>
#include <iostream>
#include <sys/types.h>

#include "zorbatypes/zstring.h"

namespace zorba {
namespace uuid {

///////////////////////////////////////////////////////////////////////////////

enum variant {
  ncs,                                  ///< NCS backward compatibility
  rfc4122,                              ///< RFC 4122
  microsoft,                            ///< Microsoft compatibility
  future                                ///< Reserved for future use
};

enum version {
  unknown,
  time_based,
  dce_security,
  name_based_md5,
  random_number_based,
  name_based_sha1
};

struct type {
  typedef uint8_t value_type;
  typedef value_type& reference;
  typedef value_type const& const_reference;
  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef pointer iterator;
  typedef const_pointer const_iterator;

  value_type data[16];

  iterator begin() {
    return data;
  }

  const_iterator begin() const {
    return data;
  }

  iterator end() {
    return data + size();
  }

  const_iterator end() const {
    return data + size();
  }

  size_type size() const {
    return sizeof( data );
  }

  void swap( type &that ) {
    std::swap_ranges( begin(), end(), that.begin() );
  }

  uuid::variant variant() const;
  uuid::version version() const;
};

////////// Functions //////////////////////////////////////////////////////////

/**
 * Creates a UUID.
 *
 * @param u A pointer to the result.
 */
void create( type *u );

/**
 * Swaps two UUIDs
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 */
inline void swap( type &u1, type &u2 ) {
  u1.swap( u2 );
}

/**
 * Compares two UUIDs for equality.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the two UUIDs are equal.
 */
inline bool operator==( type const &u1, type const &u2 ) {
  return std::equal( u1.begin(), u1.end(), u2.begin() );
}

/**
 * Compares two UUIDs for inequality.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the two UUIDs are not equal.
 */
inline bool operator!=( type const &u1, type const &u2 ) {
  return !(u1 == u2);
}

std::ostream& operator<<( std::ostream &os, type const &u );

///////////////////////////////////////////////////////////////////////////////

} // namespace uuid
} // namespace zorba

#endif /* ZORBA_UUID_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
