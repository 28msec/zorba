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
#include "stdafx.h"

#include <zorba/locale.h>

#include "util/utf8_util.h"

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
    iso2788_value_ = t;
  } else {
    is_string_ = true;
    new( &string_value() ) string_t( rel_lower );
  }
}

relationship::relationship( relationship const &that ) {
  is_string_ = that.is_string_;
  if ( is_string_ )
    new( &string_value() ) string_t( that.string_value() );
  else
    iso2788_value_ = that.iso2788_value_;
}

relationship::~relationship() {
  if ( is_string_ )
    string_value().~string_t();
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
     b.is_string_ && a.string_value() == b.string_value()
  : !b.is_string_ && a.iso2788_value_ == b.iso2788_value_;
}

bool operator<( relationship const &a, relationship const &b ) {
  if ( a.is_string_ )
    return a.string_value() < b.get_string();
  if ( b.is_string_ )
    return a.get_string() < b.string_value();
  return a.iso2788_value_ < b.iso2788_value_;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba
/* vim:set et sw=2 ts=2: */
