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

#include <cctype>

#include "compiler/expression/ftnode.h"
#include "diagnostics/assert.h"
#include "store/api/store.h"
#include "util/cxx_util.h"
#include "util/stl_util.h"

#include "ft_stop_words_set.h"
#include "ft_token_matcher.h"
#include "ft_util.h"
#include "ft_wildcard.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline bool get_diacritics_insensitive( ftmatch_options const &options ) {
  if ( ftdiacritics_option const *const d = options.get_diacritics_option() )
    return d->get_mode() == ft_diacritics_mode::insensitive;
  return false;
}

inline bool get_stemming( ftmatch_options const &options ) {
  if ( ftstem_option const *const s = options.get_stem_option() )
    return s->get_mode() == ft_stem_mode::with;
  return false;
}

inline ft_stop_words_set const* get_stop_words( ftmatch_options const &options,
                                                iso639_1::type lang,
                                                static_context const& sctx ) {
  if ( ftstop_word_option const *const sw = options.get_stop_word_option() )
    return ft_stop_words_set::construct( *sw, lang, sctx );
  return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

ft_token_matcher::ft_token_matcher( ftmatch_options const &options,
                                    static_context const &sctx ) :
  case_option_( options.get_case_option() ),
  diacritics_insensitive_( get_diacritics_insensitive( options ) ),
  lang_( get_lang_from( &options ) ),
  stemming_( get_stemming( options ) ),
  stop_words_( get_stop_words( options, lang_, sctx ) ),
  wildcards_( get_wildcards_from( &options ) )
{
}

ft_token_matcher::~ft_token_matcher() {
  delete stop_words_;
}

///////////////////////////////////////////////////////////////////////////////

ft_token_matcher::match_stemmer::match_stemmer() :
  provider_( GENV_STORE.getStemmerProvider() )
{
  ZORBA_ASSERT( provider_ );
}

void ft_token_matcher::match_stemmer::
operator()( string_t const &word, iso639_1::type lang,
            string_t *result ) const {
  internal::Stemmer::ptr stemmer( provider_->get_stemmer( lang ) );
  if ( stemmer )
    stemmer->stem( word, lang, result );
  else
    *result = word;
}

///////////////////////////////////////////////////////////////////////////////

bool ft_token_matcher::match( FTToken const &dt, FTToken const &qt ) const {
  int dt_selector = FTToken::original;
  int qt_selector = FTToken::original;

  if ( stop_words_ ) {
    //
    // Perform stop-word comparison early so as not to waste time doing the
    // stuff below for stop-words.
    //
    // Perform stop-word comparison in lower-case since stop-word lists are in
    // lower-case.
    //
    if ( stop_words_->contains( qt.value( FTToken::lower ) ) )
      return true;
  }

  if ( stemming_ )
    return dt.value( stemmer_, lang_ ) == qt.value( stemmer_, lang_ );

  if ( case_option_ ) {
    switch ( case_option_->get_mode() ) {
      case ft_case_mode::insensitive:
        dt_selector |= FTToken::lower;
        qt_selector |= FTToken::lower;
        break;
      case ft_case_mode::sensitive:
        // do nothing
        break;
      case ft_case_mode::lower:
        qt_selector |= FTToken::lower;
        break;
      case ft_case_mode::upper:
        qt_selector |= FTToken::upper;
        break;
    }
  }

  if ( diacritics_insensitive_ ) {
    dt_selector |= FTToken::ascii;
    qt_selector |= FTToken::ascii;
  }

  if ( wildcards_ )
    return dt.value( dt_selector ) == qt.wildcard( qt_selector );

  return dt.value( dt_selector, lang_ ) == qt.value( qt_selector, lang_ );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
