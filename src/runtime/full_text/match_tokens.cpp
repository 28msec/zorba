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
#include "store/api/ft_token.h"

using namespace std;

namespace zorba {

/**
 * Test whether the 2 given tokens match given the match options.
 */
bool match_tokens( FTToken::string_t const &ti, FTToken::string_t const &tj,
                   ftmatch_options const &options ) {
  FTToken::string_t ti2, tj2;
  FTToken::string_t const *pi = &ti, *pj = &tj;

  if ( ftcase_option const *const c = options.get_case_option() ) {
    switch ( c->get_mode() ) {
      case ft_case_mode::insensitive:
        ti2 = *pi->lowercase(); pi = &ti2;
        tj2 = *pj->lowercase(); pj = &tj2;
        break;
      case ft_case_mode::sensitive:
        // do nothing
        break;
      case ft_case_mode::lower:
        tj2 = *pj->lowercase(); pj = &tj2;
        break;
      case ft_case_mode::upper:
        tj2 = *pj->uppercase(); pj = &tj2;
        break;
    }
  }

  if ( ftdiacritics_option const *const d = options.get_diacritics_option() ) {
    switch ( d->get_mode() ) {
      case ft_diacritics_mode::insensitive:
        // TODO
        break;
      case ft_diacritics_mode::sensitive:
        // do nothing
        break;
    }
  }

  if ( ftextension_option const *const e = options.get_extension_option() ) {
    // TODO
  }

  if ( ftlanguage_option const *const l = options.get_language_option() ) {
    // string const &lang = l->get_language();
    // TODO
  }

  if ( ftstem_option const *const s = options.get_stem_option() ) {
    switch ( s->get_mode() ) {
      case ft_stem_mode::with:
        // TODO
        break;
      case ft_stem_mode::without:
        // do nothing
        break;
    }
  }

  if ( ftstop_word_option const *const sw = options.get_stop_word_option() ) {
    switch ( sw->get_mode() ) {
      case ft_stop_words_mode::with:
        // TODO
        break;
      case ft_stop_words_mode::with_default:
        // TODO
        break;
      case ft_stop_words_mode::without:
        // do nothing
        break;
    }
  }

  if ( ftthesaurus_option const *const t = options.get_thesaurus_option() ) {
    // TODO
  }

  if ( ftwild_card_option const *const wc = options.get_wild_card_option() ) {
    switch ( wc->get_mode() ) {
      case ft_wild_card_mode::with:
        // TODO
        break;
      case ft_wild_card_mode::without:
        // do nothing
        break;
    }
  }

  return *pi == *pj;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
