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

#ifndef ZORBA_FT_TOKEN_H
#define ZORBA_FT_TOKEN_H

#include <string>

namespace zorba {

/**
 * An FTToken is a full-text token from either an XML document or a query.
 */
struct FTToken {

  /**
   * The integral type used for token, paragraph, and sentence numbers.
   */
  typedef unsigned int_t;

  /**
   * The string type uses for the token itself.
   */
  typedef std::string word_t;

  /**
   * Constructs an FTToken for a token from an XML document.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 0.
   * @param para_no   The paragraph number.  Paragraph numbers start at 0.
   */
  FTToken( char const *utf8_s, int len,
           int_t pos_, int_t sent_, int_t para_ ) :
    word( utf8_s, len ), pos( pos_ ), sent( sent_ ), para( para_ )
  {
  }

  /**
   * Constructs an FTToken for a token from a query.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   */
  FTToken( char const *utf8_s, int len, int_t pos_ ) :
    word( utf8_s, len ), pos( pos_ ), sent( 0 ), para( 0 )
  {
  }

  /**
   * The token.
   */
  word_t word;

  /**
   * The token position within either the source XML document or query.
   */
  int_t pos;

  /**
   * The sentence number within the source XML document.  Sentence numbers
   * start at zero.  For query tokens, this is always zero.
   */
  int_t sent;

  /**
   * The paragraph number within the source XML document.  Paragraph numbers
   * start at zero.  For query tokens, this is always zero.
   */
  int_t para;
};

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
