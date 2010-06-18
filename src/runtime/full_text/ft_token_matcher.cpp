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
#include "runtime/full_text/ft_stop_words_set.h"
#include "runtime/full_text/ft_token_matcher.h"
#include "runtime/full_text/ft_wildcard_matcher.h"
#include "util/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline bool get_diacritics_insensitive( ftmatch_options const &options ) {
  if ( ftdiacritics_option const *const d = options.get_diacritics_option() )
    return d->get_mode() == ft_diacritics_mode::insensitive;
  return false;
}

inline lang::iso639_1::type get_lang( ftmatch_options const &options ) {
  if ( ftlanguage_option const *const l = options.get_language_option() )
    return l->get_language();
  cout << "default_lang=" << lang::iso639_1::string_of[ lang::get_default() ] << endl;
  return lang::get_default();
}

inline bool get_stemming( ftmatch_options const &options ) {
  if ( ftstem_option const *const s = options.get_stem_option() )
    return s->get_mode() == ft_stem_mode::with;
  return false;
}

inline ft_stop_words_set const* get_stop_words( ftmatch_options const &options,
                                                lang::iso639_1::type lang ) {
  if ( ftstop_word_option const *const sw = options.get_stop_word_option() ) {
    if ( sw->get_mode() != ft_stop_words_mode::without )
      return ft_stop_words_set::construct( *sw, lang );
  }
  return NULL;
}

inline bool get_wildcards( ftmatch_options const &options ) {
  if ( ftwild_card_option const *const wc = options.get_wild_card_option() )
    return wc->get_mode() == ft_wild_card_mode::with;
  return false;
}

///////////////////////////////////////////////////////////////////////////////

ft_token_matcher::ft_token_matcher( ftmatch_options const &options ) :
  options_( options ),
  diacritics_insensitive_( get_diacritics_insensitive( options ) ),
  lang_( get_lang( options ) ),
  stemming_( get_stemming( options ) ),
  stop_words_( get_stop_words( options, lang_ ) ),
  wildcards_( get_wildcards( options ) )
{
}

ft_token_matcher::~ft_token_matcher() {
  delete stop_words_;
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
    // Perform stop-word comparison case-insensitively.  Note, however, that
    // the XQuery Full Text spec currently isn't clear on whether this should
    // be done case-insensitively.  See W3C Bug 9858.
    //
    if ( stop_words_->contains( qt.value( FTToken::lower ) ) )
      return true;
  }

  if ( ftcase_option const *const c = options_.get_case_option() ) {
    switch ( c->get_mode() ) {
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

  if ( ftextension_option const *const e = options_.get_extension_option() ) {
    // TODO
  }

  if ( stemming_ ) {
    dt_selector |= FTToken::stem;
    qt_selector |= FTToken::stem;
  }

  if ( diacritics_insensitive_ ) {
    dt_selector |= FTToken::ascii;
    qt_selector |= FTToken::ascii;
  }

  if ( ftthesaurus_option const *const t = options_.get_thesaurus_option() ) {
    if ( !t->no_thesaurus() ) {
      // TODO
    }
  }

  if ( wildcards_ ) {
    return qt.matcher( qt_selector ).matches( dt.value( dt_selector ) );
  }

  return dt.value( dt_selector, lang_ ) == qt.value( qt_selector, lang_ );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
