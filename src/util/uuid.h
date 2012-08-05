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

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %uuid contains the raw bytes for a UUID.  Note that this is intentially a
 * \c struct with no constructors, no destructor, and no user-defined
 * assignment operators so that it remains a POD.
 */
struct uuid {
  typedef uint8_t value_type;
  typedef value_type& reference;
  typedef value_type const& const_reference;
  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef pointer iterator;
  typedef const_pointer const_iterator;

  enum variant {
    ncs,                                ///< NCS backward compatibility
    rfc4122,                            ///< RFC 4122
    microsoft,                          ///< Microsoft compatibility
    future                              ///< Reserved for future use
  };

  enum version {
    unknown,
    time_based          = 0x10,
    dce_security        = 0x20,
    name_based_md5      = 0x30,
    random_number_based = 0x40,
    name_based_sha1     = 0x50
  };

  /**
   * The raw UUID data.
   */
  value_type data[16];

  /**
   * Creates a UUID.  The variant and version of the UUID created is
   * platform-dependent.
   *
   * @param result A pointer to the result.
   */
  static void create( uuid *result );

  /**
   * Creates an iterator to the beginning of the data.
   *
   * @return Returns said iterator.
   */
  iterator begin() {
    return data;
  }

  /**
   * Creates a const_iterator to the beginning of the data.
   *
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return data;
  }

  /**
   * Creates an iterator to one past the end of the data.
   *
   * @return Returns said iterator.
   */
  iterator end() {
    return data + size();
  }

  /**
   * Creates a const_iterator to one past the end of the data.
   *
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return data + size();
  }

  /**
   * Gets the size of the UUID data.
   *
   * @return Always returns 16.
   */
  size_type size() const {
    return sizeof( data );
  }

  /**
   * Swaps this UUID's data with that of another.
   *
   * @param that The other UUID to swap data with.
   */
  void swap( uuid &that ) {
    std::swap_ranges( begin(), end(), that.begin() );
  }

  /**
   * Gets the variant of this UUID.
   *
   * @return Returns said variant.
   */
  variant get_variant() const;

  /**
   * Gets the version of this UUID.
   *
   * @return Returns said version.
   */
  version get_version() const {
    return static_cast<version>( data[6] & 0xF0u );
  }
};

////////// Functions //////////////////////////////////////////////////////////

/**
 * Swaps two UUIDs' data.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 */
inline void swap( uuid &u1, uuid &u2 ) {
  u1.swap( u2 );
}

/**
 * Compares two UUIDs for equality.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the two UUIDs are equal.
 */
inline bool operator==( uuid const &u1, uuid const &u2 ) {
  return std::equal( u1.begin(), u1.end(), u2.begin() );
}

/**
 * Compares two UUIDs for inequality.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the two UUIDs are not equal.
 */
inline bool operator!=( uuid const &u1, uuid const &u2 ) {
  return !(u1 == u2);
}

/**
 * Compares two UUIDs for less-than.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the first UUID is less than the second.
 */
inline bool operator<( uuid const &u1, uuid const &u2 ) {
  return std::lexicographical_compare(
    u1.begin(), u1.end(), u2.begin(), u2.end()
  );
}

/**
 * Compares two UUIDs for less-than-or-equal-to.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the first UUID is less than or equal to the
 * second.
 */
inline bool operator<=( uuid const &u1, uuid const &u2 ) {
  return !(u2 < u1);
}

/**
 * Compares two UUIDs for greater-than.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the first UUID is greater than the second.
 */
inline bool operator>( uuid const &u1, uuid const &u2 ) {
  return u2 < u1;
}

/**
 * Compares two UUIDs for greater-than-or-equal-to.
 *
 * @param u1 The first UUID.
 * @param u2 The second UUID.
 * @return Returns \c true only if the first UUID is greater than or equal to
 * the second.
 */
inline bool operator>=( uuid const &u1, uuid const &u2 ) {
  return !(u1 < u2);
}

/**
 * Emits the given UUID to the given ostream in canonical UUID format.
 *
 * @param os The ostream to emit to.
 * @param u The UUID to emit.
 * @return Returns \a os.
 */
std::ostream& operator<<( std::ostream &os, uuid const &u );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_UUID_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
