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

#ifndef ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H
#define ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H

#include "compiler/expression/ftnode.h"
#include "runtime/full_text/ft_stop_words_set.h"
#include "zorbatypes/ft_token.h"
#include "zorbautils/locale.h"

namespace zorba {

class ft_token_matcher {
public:
  ft_token_matcher( ftmatch_options const& );
  ~ft_token_matcher();

  /**
   * Test whether the 2 given tokens match given the match options.
   *
   * @param dt The document token.
   * @param qt The query token.
   */
  bool match( FTToken const &dt, FTToken const &qt ) const;

private:
  ftmatch_options const &options_;
  bool const diacritics_insensitive_;
  locale::iso639_1::type const lang_;
  bool const stemming_;
  ft_stop_words_set const *const stop_words_;
  bool const wildcards_;
};

} // namespace zorba
#endif /* ZORBA_FULL_TEXT_FT_TOKEN_MATCHER_H */
/* vim:set et sw=2 ts=2: */
