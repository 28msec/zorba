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
#include <string>
#include <vector>

#include "zorbatypes/rchandle.h"
#include "zorbatypes/xqpstring.h"
#include "zorbautils/lang.h"

namespace zorba {

class ft_wildcard_matcher;

///////////////////////////////////////////////////////////////////////////////

/**
 * An FTToken is a full-text token from either an XML document or a query.
 */
class FTToken {
public:

  /**
   * The integral type used for token, paragraph, and sentence numbers.
   */
  typedef unsigned int_t;

  /**
   * Constructs an FTToken for a token from an XML document.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 0.
   * @param para_no   The paragraph number.  Paragraph numbers start at 0.
   * @param lang_code The language of the soken string.
   */
  FTToken( char const *utf8_s, int len,
           int_t token_no, int_t sent_no, int_t para_no,
           lang::iso639_1::type lang_code = lang::iso639_1::unknown );

  /**
   * Constructs an FTToken for a token from a query.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param token_no  The token number.  Token numbers start at 0.
   * @param lang_code The language of the soken string.
   */
  FTToken( char const *utf8_s, int len, int_t token_no,
           lang::iso639_1::type lang_code = lang::iso639_1::unknown );

  /**
   * Copy constructor.
   *
   * @param from  The FTToken to copy from.
   */
  FTToken( FTToken const &from ) {
    copy( from );
  }

  /**
   * Destroys and FTToken.
   */
  ~FTToken() {
    free();
  }

  /**
   * Assignment operator.
   */
  FTToken& operator=( FTToken const &from );

  /**
   * Gets the langauge of the token.
   */
  lang::iso639_1::type lang() const {
    return lang_;
  }

  /**
   * Gets the paragraph number within the source XML document.  Paragraph
   * numbers start at zero.  For query tokens, this is always zero.
   *
   * @return Returns said paragraph number.
   */
  int_t para() const {
    return is_query_token() ? 0 : para_;
  }

  /**
   * Gets the token position within either the source XML document or query.
   * Token positions start at 0.
   *
   * @return Retuns said token position.
   */
  int_t pos() const {
    return pos_;
  }

  /**
   * Gets the sentence number within the source XML document.  Sentence numbers
   * start at zero.  For query tokens, this is always zero.
   *
   * @return Returns said sentence number.
   */
  int_t sent() const {
    return is_query_token() ? 0 : dt_.sent_;
  }

  /**
   * The "bit-wise or" of these is used to select the token's value modified in
   * one-or-more ways.  Note that some combinations are nonsensical, e.g.,
   * <code>lower | upper</code> and will fail an assertion.
   */
  enum Selectors {
    original  = 0x00, ///< the original token
    ascii     = 0x01, ///< diacritics stripped
    lower     = 0x02, ///< lower-case
    upper     = 0x04, ///< upper-case
    stem      = 0x08, ///< stemmed
  };

  /**
   * Gets the token's value modified in one-or-more ways.
   *
   * @param selector  The "bit-wise or" of Selectors.
   * @param alt_lang  The language to use only if the token doesn't already
   *                  have a language.
   * @return Returns said value.
   */
  std::string const&
  value( int selector = original,
         lang::iso639_1::type alt_lang = lang::iso639_1::unknown ) const {
    if ( selector == original )         // optimize this case
      return value_->str();
    return valueImpl( selector, alt_lang ).str();
  }

  /**
   * Gets an ft_wildcard_matcher TODO
   *
   * @param selector The "bit-wise or" of Selectors.
   * @return Returns said ft_wildcard_matcher.
   */
  ft_wildcard_matcher const& matcher( int selector = original ) const;

private:
  typedef xqpStringStore string_t;
  typedef rchandle<string_t> string_rc;
  typedef std::vector<string_rc> mod_values_t;

  static int_t const QueryTokenMagicValue = static_cast<int_t>( ~0 );

  string_rc value_;                     ///< original value
  lang::iso639_1::type lang_;           ///< language (if any)
  int_t pos_;                           ///< position

  /**
   * The token's paragraph number.  If this is QueryTokenMagicValue, it means
   * this token is a query token.  (Query tokens don't have paragraph numbers.)
   * A separate \c bool isn't used because that would take more space.
   */
  int_t para_;

  /**
   * Data only for document tokens.
   */
  struct dt_data {
    int_t sent_;
  };

  /**
   * Data only for query tokens.
   */
  struct qt_data {

    /**
     * The smallest possible type to store a Selectors value.
     */
    typedef char selector_t;

    /**
     * The selector that was used at the time the ft_wildcard_matcher was
     * created.
     */
    mutable selector_t selector_;

    mutable ft_wildcard_matcher *matcher_;
  };

  /**
   * Union of document/query token data.
   */
  union {
    dt_data dt_;
    qt_data qt_;
  };

  /**
   * A cache of the various modified token values.  A pointer to a vector is
   * used rather than a vector in order to use less space for the majority of
   * tokens that will never need this.
   */
  mutable mod_values_t *mod_values_;

  inline bool is_query_token() const {
    return para_ == QueryTokenMagicValue;
  }

  static void fix_selector( int *selector );
  static void strip_diacritics( string_t const&, string_t &result );

  void copy( FTToken const& );
  void free();
  void init( lang::iso639_1::type, int_t, int_t, int_t );

  string_t const&
  valueImpl( int, lang::iso639_1::type = lang::iso639_1::unknown ) const;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Inserts a text representation of an FTToken into an ostream.
 *
 * @param o The ostream to insert into.
 * @param t The FTToken to insert.
 * @return Returns the given ostream.
 */
std::ostream& operator<<( std::ostream &o, FTToken const &t );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
