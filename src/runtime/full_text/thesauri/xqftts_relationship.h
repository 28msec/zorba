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
#ifndef ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H
#define ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H

#include <iostream>

#include "iso2788.h"
#include "zorbatypes/zstring.h"
#include "diagnostics/assert.h"

namespace zorba {
namespace xqftts {

///////////////////////////////////////////////////////////////////////////////

/**
 * An XQFTTS %relationship can be either an ISO 2788 relationship or a string.
 */
class relationship {
public:
  typedef zstring string_t;

  /**
   * Constructs a %relationship from a string.
   *
   * @param rel_string The string to construct this %relationship from.  If the
   * string matches an ISO 2788 %relationship, then that is what's stored
   * internally; otherwise the string is stored as-is.
   */
  relationship( string_t const &rel_string );

  /**
   * Copy-constructor.
   *
   * @param that The %relationship to copy from.
   */
  relationship( relationship const &that );

  /**
   * Destructor.
   */
  ~relationship();

  /**
   * Assignment operator.
   *
   * @param that The %relationship to assign from.
   * @return Returns \c *this.
   */
  relationship& operator=( relationship const &that );

  /**
   * Checks whether this %relationship is "empty", i.e., no relationship.
   *
   * @return Returns \c true only if this %relationship is empty.
   */
  bool empty() const {
    return is_string_ ? string_value().empty() : !iso2788_value_;
  }

  /**
   * Gets the ISO 2788 equivalent for this %relationship.
   *
   * @return Returns the ISO 2788 equivalent or \c unknown for all string
   * relationships.
   */
  iso2788::rel_type get_iso2788() const {
    return is_string_ ? iso2788::unknown : iso2788_value_;
  }

  /**
   * Gets the string equivalent for this %relationship.
   *
   * @return Returns said string equivalent.
   */
  char const* get_string() const {
    return is_string_ ?
      string_value().c_str() : iso2788::string_of[ iso2788_value_ ];
  }

  /**
   * Compares to %relationship objects for equality.
   *
   * @param a The first %relationship.
   * @param b The second %relationship.
   * @return Returns \c true only if the two relationships are equal.
   */
  friend bool operator==( relationship const &a, relationship const &b );

  // Defined so that relationships can be put into sorted STL containers.
  friend bool operator< ( relationship const &a, relationship const &b );

private:
  union {
    iso2788::rel_type iso2788_value_;
    // Using a struct guarantees correct struct/class alignment.
    struct { char buf[ sizeof( string_t ) ]; } rel_string_;
  };

  bool is_string_;

  string_t& string_value() const {
    ZORBA_ASSERT( is_string_ );
    return *const_cast<string_t*>(
      reinterpret_cast<string_t const*>( &rel_string_ )
    );
  }
};

///////////////////////////////////////////////////////////////////////////////

inline bool operator!=( relationship const &a, relationship const &b ) {
  return !(a == b);
}

inline std::ostream& operator<<( std::ostream &o, relationship const &r ) {
  return o << r.get_string();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H */
/* vim:set et sw=2 ts=2: */
