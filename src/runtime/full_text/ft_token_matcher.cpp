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

#include <cctype>

#include "compiler/expression/ftnode.h"
#include "runtime/full_text/ft_stemmer.h"
#include "runtime/full_text/ft_stop_words_set.h"
#include "runtime/full_text/ft_token_matcher.h"
#include "store/api/ft_token.h"
#include "util/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static void strip_diacritics( FTToken::string_t const &ts,
                              FTToken::string_t &result ) {
  static xqpStringStore const mode( "NFKD" );
  FTToken::string_t const ts_normalized( *ts.normalize( &mode ) );

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

///////////////////////////////////////////////////////////////////////////////

ft_token_matcher::ft_token_matcher( ftmatch_options const &options ) :
  options_( options )
{
  lang::iso639_1::type lang_code;
  if ( ftlanguage_option const *const l = options_.get_language_option() )
    lang_code = l->get_language();
  else
    lang_code = lang::iso639_1::en; // TODO: change

  stemmer_ = NULL;
  if ( ftstem_option const *const s = options_.get_stem_option() ) {
    if ( s->get_mode() == ft_stem_mode::with )
      stemmer_ = ft_stemmer::get( lang_code );
  }

  stop_words_ = NULL;
  if ( ftstop_word_option const *const sw = options_.get_stop_word_option() ) {
    if ( sw->get_mode() != ft_stop_words_mode::without )
      stop_words_ = ft_stop_words_set::construct( *sw, lang_code );
  }
}

ft_token_matcher::~ft_token_matcher() {
  delete stemmer_;
  delete stop_words_;
}

///////////////////////////////////////////////////////////////////////////////

bool ft_token_matcher::match( FTToken::string_t const &dts,
                              FTToken::string_t const &qts ) const {
  FTToken::string_t dts2, qts2;
  FTToken::string_t const *pdts = &dts, *pqts = &qts;
  bool dt_is_lower = false, qt_is_lower = false;

#define LOWERCASE(TOKEN) \
  if ( !TOKEN##_is_lower ) { \
    TOKEN##s2 = *p##TOKEN##s->lowercase(), p##TOKEN##s = &TOKEN##s2; \
    TOKEN##_is_lower = true; \
  }

  if ( ftlanguage_option const *const l = options_.get_language_option() ) {
    // lang::iso639_1::type const lang_code = l->get_language();
    // TODO
  }

  if ( stop_words_ ) {
    //
    // Perform stop-word comparison early so as not to waste time doing the
    // stuff below for stop-words.
    //
    // Perform stop-word comparison case-insensitively.  Note, however, that
    // the XQuery Full Text spec currently isn't clear on whether this should
    // be done case-insensitively.  See W3C Bug 9858.
    //
    LOWERCASE(qt);
    if ( stop_words_->contains( pqts->str() ) )
      return true;
  }

  if ( ftcase_option const *const c = options_.get_case_option() ) {
    switch ( c->get_mode() ) {
      case ft_case_mode::insensitive:
        LOWERCASE(dt);
        LOWERCASE(qt);
        break;
      case ft_case_mode::sensitive:
        // do nothing
        break;
      case ft_case_mode::lower:
        LOWERCASE(qt);
        break;
      case ft_case_mode::upper:
        qts2 = *pqts->uppercase(), pqts = &qts2;
        break;
    }
  }

  if ( ftextension_option const *const e = options_.get_extension_option() ) {
    // TODO
  }

  if ( stemmer_ ) {
    LOWERCASE(dt);
    LOWERCASE(qt);
    stemmer_->stem( pdts->str(), dts2.str() ), pdts = &dts2;
    stemmer_->stem( pqts->str(), qts2.str() ), pqts = &qts2;
    //cerr << "d_stem=" << dts2.str() << endl;
    //cerr << "q_stem=" << qts2.str() << endl;
  }

  if ( ftdiacritics_option const *const d = options_.get_diacritics_option() ) {
    if ( d->get_mode() == ft_diacritics_mode::insensitive ) {
      strip_diacritics( *pdts, dts2 ), pdts = &dts2;
      strip_diacritics( *pqts, qts2 ), pqts = &qts2;
    }
  }

  if ( ftthesaurus_option const *const t = options_.get_thesaurus_option() ) {
    if ( !t->no_thesaurus() ) {
      // TODO
    }
  }

  if ( ftwild_card_option const *const wc = options_.get_wild_card_option() ) {
    if ( wc->get_mode() == ft_wild_card_mode::with ) {
      // TODO
    }
  }

  return *pdts == *pqts;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
