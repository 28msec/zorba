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

#include "util/utf8_util.h"
#include "zorbautils/locale.h"

#include "xqftts_relationship.h"

namespace zorba {
namespace xqftts {

using namespace locale;

///////////////////////////////////////////////////////////////////////////////

relationship::relationship( string_t const &rel_string ) {
  zstring rel_lower;
  utf8::to_lower( rel_string, &rel_lower );
  if ( iso2788::rel_type const t = iso2788::find_rel( rel_lower ) ) {
    is_string_ = false;
    rel_iso2788_ = t;
  } else {
    is_string_ = true;
    new( &get_string() ) string_t( rel_lower );
  }
}

relationship::relationship( relationship const &that ) {
  if ( that.is_string_ ) {
    is_string_ = true;
    new( &get_string() ) string_t( that.get_string() );
  } else {
    is_string_ = false;
    rel_iso2788_ = that.rel_iso2788_;
  }
}

relationship::~relationship() {
  if ( is_string_ )
    get_string().~string_t();
}

relationship& relationship::operator=( relationship const &that ) {
  if ( &that != this ) {
    this->~relationship();
    new( this ) relationship( that );
  }
  return *this;
}

bool operator==( relationship const &a, relationship const &b ) {
  return a.is_string_ ?
     b.is_string_ && a.get_string() == b.get_string()
  : !b.is_string_ && a.rel_iso2788_ == b.rel_iso2788_;
}

bool operator<( relationship const &a, relationship const &b ) {
  return a.is_string_ ?
     b.is_string_ && a.get_string() < b.get_string()
  : !b.is_string_ && a.rel_iso2788_ < b.rel_iso2788_;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba

/* vim:set et sw=2 ts=2: */
