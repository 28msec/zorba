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
#ifndef ZORBA_TOKENIZER_H
#define ZORBA_TOKENIZER_H

#include <zorba/locale.h>

#include "util/cxx_util.h"

namespace zorba {

/**
 * A Tokenizer breaks a string into a stream of word tokens.  Each token is
 * assigned a token, sentence, and paragraph number.
 *
 * A Tokenizer determines word and sentence boundaries automatically, but must
 * be told when to increment the paragraph number.
 */
class Tokenizer {
public:
  typedef unsigned int_t;

  /**
   * A Callback is called once per token.
   */
  class Callback {
  public:
    typedef Tokenizer::int_t int_t;

    virtual ~Callback();

    /**
     * This member-function is called once per token.
     *
     * @param utf8_s    The UTF-8 token string.  It is not null-terminated.
     * @param utf8_len  The number of bytes in the token string.
     * @param token_no  The token number.  Token numbers start at 0.
     * @param sent_no   The sentence number.  Sentence numbers start at 1.
     * @param para_no   The paragraph number.  Paragraph numbers start at 1.
     * @param payload   Optional user-defined data.
     */
    virtual void operator()( char const *utf8_s, size_t utf8_len,
                             int_t token_no, int_t sent_no, int_t para_no,
                             void *payload = nullptr ) = 0;
  };

  /**
   * Destroys a Tokenizer.
   */
  virtual ~Tokenizer();

  /**
   * Creates a new Tokenizer.
   *
   * @param wildcards If <code>true</code>, allows XQuery wildcard syntax
   * characters to be part of tokens.
   * @return Returns said Tokenizer.
   */
  static Tokenizer* create( bool wildcards = false );

  /**
   * Gets the current token number.
   *
   * @return Returns said number.
   */
  int_t token() const {
    return token_no_;
  }

  /**
   * Sets the current token number.
   *
   * @param n The new number.
   */
  void token( int_t n ) {
    token_no_ = n;
  }

  /**
   * Gets the current sentence number.
   *
   * @return Returns said number.
   */
  int_t sent() const {
    return sent_no_;
  }

  /**
   * Sets the current sentence number.
   *
   * @param n The new number.
   */
  void sent( int_t n ) {
    sent_no_ = n;
  }

  /**
   * Gets the current paragraph number.
   *
   * @return Returns said number.
   */
  int_t para() const {
    return para_no_;
  }

  /**
   * Sets the current paragraph number.
   *
   * @param n The new number.
   */
  void para( int_t n ) {
    para_no_ = n;
  }

  /**
   * Tokenizes the given string.
   *
   * @param utf8_s    The UTF-8 string to tokenize.  It need not be
   *                  null-terminated.
   * @param len       The number of bytes in the token string.
   * @param lang      The language of the text.
   * @param callback  The Callback to call once per token.
   * @param payload   Optional user-defined data.
   */
  virtual void tokenize( char const *utf8_s, size_t len,
                         locale::iso639_1::type lang, Callback &callback,
                         void *payload = nullptr ) = 0;

protected:
  Tokenizer();

  int_t token_no_;
  int_t sent_no_;
  int_t para_no_;
};

} // namespace zorba
#endif  /* ZORBA_TOKENIZER_H */
