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
#ifndef ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H
#define ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H

#include <zorba/locale.h>

#include "compiler/expression/ftnode.h"
#include "context/static_context.h"
#include "zorbatypes/ft_token.h"
#include "zorbautils/stemmer.h"

#include "ft_stop_words_set.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ft_token_matcher is used to determine whether 2 tokens match according
 * to the query-specified match options.
 */
class ft_token_matcher {
public:
  ft_token_matcher( ftmatch_options const&, static_context const& );
  ~ft_token_matcher();

  /**
   * Tests whether the 2 given tokens match given the match options.
   *
   * @param dt The document token.
   * @param qt The query token.
   */
  bool match( FTToken const &dt, FTToken const &qt ) const;

private:
  class match_stemmer : public FTToken::Stemmer {
  public:
    match_stemmer();
    // inherited
    void operator()( string_t const&, locale::iso639_1::type, string_t* ) const;
  private:
    internal::StemmerProvider const *const provider_;
  };

  ftcase_option const *const case_option_;
  bool const diacritics_insensitive_;
  locale::iso639_1::type const lang_;
  bool const stemming_;
  match_stemmer const stemmer_;
  ft_stop_words_set const *const stop_words_;
  bool const wildcards_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H */
/* vim:set et sw=2 ts=2: */
