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

#include <string>

#include "diagnostics/assert.h"
#include "runtime/full_text/ft_wildcard.h"
#include "runtime/full_text/stemmer.h"
#include "util/cxx_util.h"
#include "util/stl_util.h"
#include "util/unicode_util.h"
#include "util/utf8_util.h"
#include "zorbautils/locale.h"

#include "ft_token.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

FTToken::Stemmer::~Stemmer() {
  // out-of-line because it's virtual
}

///////////////////////////////////////////////////////////////////////////////

FTToken::FTToken( char const *utf8_s, int len,
                  int_t pos, int_t sent, int_t para,
                  store::Item const *item,
                  iso639_1::type lang ) :
  value_( utf8_s, len )
{
  init( lang, pos, sent, para, item );
}

FTToken::FTToken( char const *utf8_s, int len, int_t pos,
                  iso639_1::type lang ) :
  value_( utf8_s, len )
{
  init( lang, pos );
}

FTToken::FTToken( string_t const &utf8_s, int_t pos, iso639_1::type lang ) :
  value_( utf8_s )
{
  init( lang, pos );
}

FTToken& FTToken::operator=( FTToken const &from ) {
  if ( &from != this ) {
    free();
    copy( from );
  }
  return *this;
}

void FTToken::copy( FTToken const &from ) {
  init( from.lang_, from.pos_, from.sent_, from.dt_.para_, from.dt_.item_ );
  value_ = from.value_;
  if ( from.mod_values_ )
    mod_values_ = new mod_values_t( *from.mod_values_ );
}

void FTToken::free() {
  delete mod_values_;
  if ( is_query_token() )
    delete qt_.wildcard_;
}

FTToken::string_t& FTToken::get_mod_value( int selector ) const {
  int index;
  switch ( selector ) {
    case ascii         : index = 0; break;
    case lower         : index = 1; break;
    case upper         : index = 2; break;
    case ascii | lower : index = 3; break;
    case ascii | upper : index = 4; break;
    case stem          : index = 5; break;
    default:
      cerr << "BAD SELECTOR: 0x" << hex << selector << endl;
      ZORBA_ASSERT( false );
  }
  if ( !mod_values_ )
    mod_values_ = new mod_values_t( 6 );
  return (*mod_values_)[ index ];
}

void FTToken::init( iso639_1::type lang, int_t pos, int_t sent, int_t para,
                    store::Item const *item ) {
  lang_ = lang;
  pos_  = pos ;
  sent_ = sent;
  if ( is_query_token() ) {
    qt_.selector_ = original;
    qt_.wildcard_ = nullptr;
  } else {
    dt_.para_ = para;
    dt_.item_ = item;
  }
  mod_values_ = nullptr;
}

FTToken::string_t const& FTToken::value( Stemmer const &stemmer,
                                         iso639_1::type alt_lang ) const {
  string_t const &upper_value = value_impl( upper, alt_lang );
  if ( value_ == upper_value ) {
    //
    // The token is all in upper-case: assume it's an acronym so don't stem it.
    //
    return upper_value;
  }
  string_t &stem_value_ref = get_mod_value( stem );
  if ( stem_value_ref.empty() ) {
    iso639_1::type const stem_lang = lang_ ? lang_ : alt_lang;
    stemmer( value_impl( lower ).str(), stem_lang, &stem_value_ref );
  }
  return stem_value_ref;
}

FTToken::string_t const& FTToken::value_impl( int selector,
                                              iso639_1::type alt_lang ) const {
  string_t &mod_value_ref = get_mod_value( selector );
  if ( mod_value_ref.empty() ) {
    switch ( selector ) {
      case ascii:
        utf8::strip_diacritics( value_, &mod_value_ref );
        break;
      case lower:
        utf8::to_lower( value_, &mod_value_ref );
        break;
      case upper:
        utf8::to_upper( value_, &mod_value_ref );
        break;
      case ascii | lower:
        utf8::to_lower( value_impl( ascii ), &mod_value_ref );
        break;
      case ascii | upper:
        utf8::to_upper( value_impl( ascii ), &mod_value_ref );
        break;
    }
  }
  return mod_value_ref;
}

ft_wildcard const& FTToken::wildcard( int selector ) const {
  ZORBA_ASSERT( is_query_token() );
  if ( selector != qt_.selector_ ) {
    delete qt_.wildcard_;
    qt_.wildcard_ = nullptr;
  }
  if ( !qt_.wildcard_ ) {
    qt_.wildcard_ = new ft_wildcard( value( selector ) );
    qt_.selector_ = selector;
  }
  return *qt_.wildcard_;
}

///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<( ostream &o, FTToken const &t ) {
  return  o << "[FTToken: \"" << t.value() << "\" ("
            << iso639_1::string_of[ t.lang() ] << ") "
            << t.pos() << ',' << t.sent() << ',' << t.para() << ']';
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
