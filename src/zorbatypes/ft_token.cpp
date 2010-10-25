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

#include <string>

#include "runtime/full_text/ft_wildcard.h"
#include "util/stl_util.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/ft_token.h"
#include "zorbautils/stemmer.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

FTToken::FTToken( char const *utf8_s, int len,
                  int_t pos, int_t sent, int_t para,
                  store::Item const *item,
                  iso639_1::type lang ) :
  value_( new string_t( utf8_s, len ) )
{
  init( pos, sent, para, item, lang );
}

FTToken::FTToken( char const *utf8_s, int len, int_t pos, int_t sent,
                  iso639_1::type lang ) :
  value_( new string_t( utf8_s, len ) )
{
  init( pos, sent, QueryTokenMagicValue, NULL, lang );
}

FTToken& FTToken::operator=( FTToken const &from ) {
  if ( &from != this ) {
    free();
    copy( from );
  }
  return *this;
}

void FTToken::copy( FTToken const &from ) {
  init( from.pos_, from.sent_, from.para_, from.dt_.item_, from.lang_ );
  value_ = from.value_;
  if ( from.mod_values_ )
    mod_values_ = new mod_values_t( *from.mod_values_ );
}

inline void FTToken::fix_selector( int *selector ) {
  if ( *selector & stem ) {
    //
    // The stemmer we use operates on lower-case, non-diacritics-stripped words
    // only: therefore if stemming and any other selector is on, turn off all
    // but stemming.
    //
    *selector = stem;
  }
}

void FTToken::free() {
  delete mod_values_;
  if ( is_query_token() )
    delete qt_.wildcard_;
}

void FTToken::init( int_t pos, int_t sent, int_t para, store::Item const *item,
                    iso639_1::type lang ) {
  lang_ = lang;
  pos_  = pos ;
  para_ = para;
  sent_ = sent;
  if ( is_query_token() ) {
    qt_.wildcard_ = NULL;
    qt_.selector_ = original;
  } else {
    dt_.item_ = item;
  }
  mod_values_ = NULL;
}

void FTToken::strip_diacritics( string_t const &ts, string_t &result ) {
  static xqpStringStore const mode( "NFKD" );
  string_t const ts_normalized( *ts.normalize( &mode ) );

  string const &from = ts_normalized.str();
  string &to = result.str();
  to.clear();
  to.reserve( from.length() );

  FOR_EACH( string, i, from ) {
    char const c = *i;
    if ( isascii( c ) )
      to.push_back( c );
  }
}

FTToken::string_t const& FTToken::valueImpl( int selector,
                                             iso639_1::type alt_lang ) const {
  fix_selector( &selector );
  int index;
  switch ( selector ) {
    case ascii         : index = 0; break;
    case lower         : index = 1; break;
    case upper         : index = 2; break;
    case stem          : index = 3; break;
    case ascii | lower : index = 4; break;
    case ascii | upper : index = 5; break;
    default:
      cerr << "BAD SELECTOR: 0x" << hex << selector << endl;
      ZORBA_ASSERT( false );
  }

  if ( !mod_values_ )
    mod_values_ = new mod_values_t( 6 );

  string_rc &string_ref = (*mod_values_)[ index ];
  if ( !string_ref.getp() ) {
    switch ( selector ) {
      case ascii:
        string_ref = new string_t;
        strip_diacritics( *value_, *string_ref );
        break;
      case lower:
        string_ref = value_->lowercase();
        break;
      case upper:
        string_ref = value_->uppercase();
        break;
      case stem: {
        iso639_1::type const stem_lang = lang_ ? lang_ : alt_lang;
        if ( Stemmer const *const stemmer = Stemmer::get( stem_lang ) ) {
          string_ref = new string_t;
          stemmer->stem( valueImpl( lower ).str(), string_ref->str() );
        } else
          ZORBA_ASSERT( false );
        break;
      }
      case ascii | lower:
        string_ref = valueImpl( ascii ).lowercase();
        break;
      case ascii | upper:
        string_ref = valueImpl( ascii ).uppercase();
        break;
    }
  }
  return *string_ref;
}

ft_wildcard const& FTToken::wildcard( int selector ) const {
  ZORBA_ASSERT( is_query_token() );
  if ( selector != qt_.selector_ ) {
    delete qt_.wildcard_;
    qt_.wildcard_ = NULL;
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
