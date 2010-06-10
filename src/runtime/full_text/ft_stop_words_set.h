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
 
#ifndef ZORBA_RUNTIME_FULL_TEXT_FT_STOP_WORD_SET_H
#define ZORBA_RUNTIME_FULL_TEXT_FT_STOP_WORD_SET_H

#include <set>
#include <string>

#include "compiler/expression/ftnode.h"
#include "zorbautils/lang.h"

namespace zorba {

class ft_stop_words_set {
public:
  ~ft_stop_words_set() {
    if ( delete_ )
      delete word_set_;
  }

  static ft_stop_words_set const* construct( ftstop_word_option const&,
                                             lang::iso639_1::type );

  bool contains( std::string const &word ) const {
    return word_set_->find( word ) != word_set_->end();
  }

private:
  typedef std::set<std::string> set_t;

  set_t const *const word_set_;
  bool const delete_;

  ft_stop_words_set( set_t const *word_set, bool must_delete ) :
    word_set_( word_set ), delete_( must_delete )
  {
  }

  static set_t* get_default_word_set_for( lang::iso639_1::type );

  // forbid these
  ft_stop_words_set( ft_stop_words_set const& );
  ft_stop_words_set& operator=( ft_stop_words_set const& );
};

} // namespace zorba
#endif /* ZORBA_RUNTIME_FULL_TEXT_FT_STOP_WORD_SET_H */
/* vim:set et sw=2 ts=2: */
