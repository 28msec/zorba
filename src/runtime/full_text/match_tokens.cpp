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

#include "compiler/expression/ftnode.h"
#include "runtime/full_text/ft_stop_words_set.h"
#include "store/api/ft_token.h"
#include "zorbautils/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static void stem_word( FTToken::string_t const &ts,
                       FTToken::string_t &result ) {
  // TODO: placeholder
}

static void strip_diacritics( FTToken::string_t const &ts,
                              FTToken::string_t &result ) {
  static xqpStringStore const mode( "NFKD" );
  FTToken::string_t const ts_normalized( *ts.normalize( &mode ) );
  string const &s = ts_normalized.str();
  string buf;
  buf.reserve( s.length() );
  FOR_EACH( string, i, s ) {
    char const c = *i;
    if ( isascii( c ) )
      buf.push_back( c );
  }
  result = buf;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Test whether the 2 given tokens match given the match options.
 *
 * @param dts         The document token string.
 * @param qts         The query token string.
 * @param options     The match options to use.
 * @param stop_words  The stop words to use.
 */
bool match_tokens( FTToken::string_t const &dts, FTToken::string_t const &qts,
                   ftmatch_options const &options,
                   ft_stop_words_set const *stop_words ) {
  FTToken::string_t dts2, qts2;
  FTToken::string_t const *pdts = &dts, *pqts = &qts;
  bool qt_is_lower = false;

  if ( ftlanguage_option const *const l = options.get_language_option() ) {
    // lang::iso639_1::type const lang_code = l->get_language();
    // TODO
  }

  if ( stop_words ) {
    //
    // Perform stop-word comparison early so as not to waste time doing the
    // stuff below for stop-words.
    //
    // Perform stop-word comparison case-insensitively.  Note, however, that
    // the XQuery Full Text spec currently isn't clear on whether this should
    // be done case-insensitively.  See W3C Bug 9858.
    //
    qts2 = *pqts->lowercase(), pqts = &qts2;
    if ( stop_words->contains( pqts->str() ) )
      return true;
    qt_is_lower = true;
  }

  if ( ftcase_option const *const c = options.get_case_option() ) {
    switch ( c->get_mode() ) {
      case ft_case_mode::insensitive:
        dts2 = *pdts->lowercase(), pdts = &dts2;
        qts2 = *pqts->lowercase(), pqts = &qts2;
        qt_is_lower = true;
        break;
      case ft_case_mode::sensitive:
        // do nothing
        break;
      case ft_case_mode::lower:
        if ( !qt_is_lower ) {
          qts2 = *pqts->lowercase(), pqts = &qts2;
          qt_is_lower = true;
        }
        break;
      case ft_case_mode::upper:
        qts2 = *pqts->uppercase(), pqts = &qts2;
        break;
    }
  }

  if ( ftextension_option const *const e = options.get_extension_option() ) {
    // TODO
  }

  if ( ftstem_option const *const s = options.get_stem_option() ) {
    if ( s->get_mode() == ft_stem_mode::with ) {
      stem_word( *pdts, dts2 ), pdts = &dts2;
      stem_word( *pqts, qts2 ), pqts = &qts2;
    }
  }

  if ( ftdiacritics_option const *const d = options.get_diacritics_option() ) {
    if ( d->get_mode() == ft_diacritics_mode::insensitive ) {
      strip_diacritics( *pdts, dts2 ), pdts = &dts2;
      strip_diacritics( *pqts, qts2 ), pqts = &qts2;
    }
  }

  if ( ftthesaurus_option const *const t = options.get_thesaurus_option() ) {
    if ( !t->no_thesaurus() ) {
      // TODO
    }
  }

  if ( ftwild_card_option const *const wc = options.get_wild_card_option() ) {
    if ( wc->get_mode() == ft_wild_card_mode::with ) {
      // TODO
    }
  }

  return *pdts == *pqts;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
