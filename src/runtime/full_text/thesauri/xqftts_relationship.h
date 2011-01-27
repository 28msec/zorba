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

#ifndef ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H
#define ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H

#include "iso2788.h"
#include "zorbatypes/zstring.h"
#include "zorbaerrors/Assert.h"

namespace zorba {
namespace xqftts {

///////////////////////////////////////////////////////////////////////////////

/**
 * An XQFTTS %relationship can be either an ISO 2788 relationship or a string.
 */
class relationship {
public:
  typedef zstring string_t;

  relationship( string_t const &rel_string );
  relationship( relationship const &that );
  ~relationship();

  relationship& operator=( relationship const &that );

  bool empty() const {
    return is_string_ ? get_string().empty() : !rel_iso2788_;
  }

  iso2788::rel_type get_iso2788() const {
    return is_string_ ? iso2788::unknown : rel_iso2788_;
  }

  friend bool operator==( relationship const &a, relationship const &b );

  // Defined so that relationships can be put into sorted STL containers.
  friend bool operator< ( relationship const &a, relationship const &b );

private:
  union {
    iso2788::rel_type rel_iso2788_;
    // Using a struct guarantees correct struct/class alignment.
    struct { char buf[ sizeof( string_t ) ]; } rel_string_;
  };

  bool is_string_;

  string_t& get_string() const {
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

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_XQFTTS_RELATIONSHIP_H */
/* vim:set et sw=2 ts=2: */
