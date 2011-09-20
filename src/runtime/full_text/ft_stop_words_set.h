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
#pragma once
#ifndef ZORBA_FULL_TEXT_FT_STOP_WORD_SET_H
#define ZORBA_FULL_TEXT_FT_STOP_WORD_SET_H

#include <set>

#include <zorba/locale.h>

#include "compiler/expression/ftnode.h"
#include "zorbatypes/zstring.h"

namespace zorba {

/**
 * An %ft_stop_words_set is (as its name suggests) a set of stop-wors.
 */
class ft_stop_words_set {
public:
  ~ft_stop_words_set() {
    if ( delete_ )
      delete word_set_;
  }

  /**
   * Constructs an %ft_stop_words_set.
   *
   * @param option The ftstop_word_option to use to possibly add or remove
   * stop-words.
   * @param lang The language of the stop-words.
   * @return Returns a new %ft_stop_words_set.
   */
  static ft_stop_words_set const* construct( ftstop_word_option const &option,
                                             locale::iso639_1::type lang,
                                             static_context const& sctx );

  /**
   * Checks whether this %ft_stop_words_set contains the given word.
   *
   * @param word The word to check for.  It is assumed to have already been
   * converted to lower case.
   * @return Returns \c true only if this %ft_stop_words_set contains the given
   * word.
   */
  bool contains( zstring const &word ) const {
    return word_set_->find( word ) != word_set_->end();
  }

private:
  typedef std::set<zstring> set_t;

  set_t const *const word_set_;
  bool const delete_;

  ft_stop_words_set( set_t const *word_set, bool must_delete ) :
    word_set_( word_set ), delete_( must_delete )
  {
  }

  static void apply_word( zstring const&, set_t&, ft_stop_words_unex::type );
  static void apply_word( char const*, char const*, set_t&,
                          ft_stop_words_unex::type );

  static set_t* get_default_word_set_for( locale::iso639_1::type );

  // forbid these
  ft_stop_words_set( ft_stop_words_set const& );
  ft_stop_words_set& operator=( ft_stop_words_set const& );
};

} // namespace zorba
#endif /* ZORBA_FULL_TEXT_FT_STOP_WORD_SET_H */
/* vim:set et sw=2 ts=2: */
