/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#ifndef ZORBA_LATIN_TOKENIZER_H
#define ZORBA_LATIN_TOKENIZER_H

#include <zorba/config.h>

#ifdef ZORBA_NO_ICU

#include <zorba/tokenizer.h>
#include "zorbatypes/zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %LatinTokenizer is-a Tokenizer for tokenizing Latin (aka, Roman)
 * characters into tokens.
 */
class LatinTokenizer : public Tokenizer {
public:
  LatinTokenizer( State &state ) : Tokenizer( state ) { }

  // inherited
  void destroy() const;
  void properties( Properties* ) const;
  void tokenize_string( char const*, size_type, iso639_1::type, bool, Callback&,
                        Item const* );

private:
  typedef zstring string_type;

  enum token_type {
    t_generic,
    t_integer,
    t_floating_point,
    t_time
  };

  token_type t_type_;

  static bool is_word_begin_char( char );
  bool is_word_char( char );
  static char peek( char const *s, char const *end );
  bool send_token( string_type const &token, locale::iso639_1::type, Callback&,
                   Item const* );
};

///////////////////////////////////////////////////////////////////////////////

class LatinTokenizerProvider : public TokenizerProvider {
public:
  // inherited
  bool getTokenizer( locale::iso639_1::type, Tokenizer::State* = 0,
                     Tokenizer::ptr* = 0 ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_NO_ICU */
#endif /* ZORBA_LATIN_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
