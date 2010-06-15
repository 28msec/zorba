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

#include <iostream>

#include "zorbatypes/xqpstring.h"
#include "zorbautils/lang.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An FTToken is a full-text token from either an XML document or a query.
 */
struct FTToken {

  /**
   * The integral type used for token, paragraph, and sentence numbers.
   */
  typedef unsigned int_t;

  /**
   * The string type for the token itself.
   */
  typedef xqpStringStore string_t;

  /**
   * Constructs an FTToken for a token from an XML document.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 0.
   * @param para_no   The paragraph number.  Paragraph numbers start at 0.
   * @param lang      The language of the soken string.
   */
  FTToken( char const *utf8_s, int len,
           int_t token_no, int_t sent_, int_t para_,
           lang::iso639_1::type lang_ = lang::iso639_1::unknown ) :
    word( utf8_s, len ), lang( lang_ ),
    pos( token_no ), sent( sent_ ), para( para_ )
  {
  }

  /**
   * Constructs an FTToken for a token from a query.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   * @param lang      The language of the soken string.
   */
  FTToken( char const *utf8_s, int len, int_t token_no,
           lang::iso639_1::type lang_ = lang::iso639_1::unknown ) :
    word( utf8_s, len ), lang( lang_ ), pos( token_no ), sent( 0 ), para( 0 )
  {
  }

  /**
   * The token.
   */
  string_t word;

  /**
   * The langauge of the token.
   */
  lang::iso639_1::type lang;

  /**
   * The token position within either the source XML document or query.  Token
   * positions start at 0.
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

///////////////////////////////////////////////////////////////////////////////

/**
 * Inserts a text representation of an FTToken into an ostream.
 *
 * @param o The ostream to insert into.
 * @param t The FTToken to insert.
 * @return Returns the given ostream.
 */
inline std::ostream& operator<<( std::ostream &o, FTToken const &t ) {
  return  o << "[FTToken: \"" << t.word << "\" ("
            << lang::iso639_1::string_of[ t.lang ] << ") "
            << t.pos << ',' << t.sent << ',' << t.para << ']';
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
