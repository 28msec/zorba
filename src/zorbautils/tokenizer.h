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

#ifndef ZORBA_TOKENIZER_H
#define ZORBA_TOKENIZER_H

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

  /**
   * A Callback is called once per token.
   */
  class Callback {
  public:
    virtual ~Callback();

    /**
     * This member-function is called once per token.
     *
     * @param utf8_s    The token string encoded in UTF-8.  It is not
     *                  null-terminated.
     * @param utf8_len  The number of chars in the token string.
     * @param token_no  The token number.  Token numbers start at 0.
     * @param sent_no   The sentence number.  Sentence numbers start at 0.
     * @param para_no   The paragraph number.  Paragraph numbers start at 0.
     */
    virtual void operator()( char const *utf8_s, int utf8_len,
                             int token_no, int sent_no, int para_no ) = 0;
  };

  /**
   * Destroys a Tokenizer.
   */
  virtual ~Tokenizer();

  /**
   * Increments the current paragraph number by 1.
   */
  void inc_para() {
    ++para_no_;
  }

  /**
   * Tokenizes the given string.
   *
   * @param utf8_s    The string to tokenize encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param callback  The Callback to call once per token.
   */
  virtual void tokenize( char const *utf8_s, int len, Callback &callback ) = 0;

protected:
  Tokenizer();

  int token_no_;
  int sent_no_;
  int para_no_;
};

} // namespace zorba
#endif  /* ZORBA_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
