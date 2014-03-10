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

#ifndef ZORBA_CSV_H
#define ZORBA_CSV_H

#include <zorba/internal/cxx_util.h>

#include "zorbatypes/zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses a CSV (Comma-Separated Values) stream.
 * See RFC 4180: "Common Format and MIME Type for Comma-Separated Values (CSV)
 * Files."
 */
class csv_parser {
public:
  /**
   * Constructs a %csv_parser.
   *
   * @param sep The value separator to use.
   * @param quote The quote character to use.  (The quote escape is a doubling
   * of this character.)
   */
  csv_parser( char sep = ',', char quote = '"' ) {
    is_ = nullptr;
    sep_ = sep;
    quote_ = quote_esc_ = quote;
  }

  /**
   * Constructs a %csv_parser.
   *
   * @param sep The value separator to use.
   * @param quote The quote character to use.
   * @param quote_esc The quote-escape character to use.  If it matches
   * \a quote, then a quote is escaped by doubling it.
   */
  csv_parser( char sep, char quote, char quote_esc ) {
    is_ = nullptr;
    sep_ = sep;
    quote_ = quote;
    quote_esc_ = quote_esc;
  }

  /**
   * Constructs a %csv_parser.
   *
   * @param is The istream to read from.
   * @param sep The value separator to use.
   * @param quote The quote character to use.  (The quote escape is a doubling
   * of this character.)
   */
  csv_parser( std::istream &is, char sep = ',', char quote = '"' ) {
    is_ = &is;
    sep_ = sep;
    quote_ = quote_esc_ = quote;
  }

  /**
   * Constructs a %csv_parser.
   *
   * @param is The istream to read from.
   * @param sep The value separator to use.
   * @param quote The quote character to use.
   * @param quote_esc The quote-escape character to use.  If it matches
   * \a quote, then a quote is escaped by doubling it.
   */
  csv_parser( std::istream &is, char sep, char quote, char quote_esc ) {
    is_ = &is;
    sep_ = sep;
    quote_ = quote;
    quote_esc_ = quote_esc;
  }

  /**
   * Parses the next value.
   *
   * @param value A pointer to the string to receive the next value.
   * @param eol Set to \c true only when \a value is set to the last value on a
   * line.
   * @param quoted If not \c null, set to \c true only when \a value was
   * quoted.
   * @return Returns \c true only if a value was parsed; \c false otherwise.
   */
  bool next_value( zstring *value, bool *eol, bool *quoted = nullptr ) const;

  /**
   * Sets the quote character to use.
   *
   * @param quote The quote character to use.
   */
  void set_quote( char quote ) {
    quote_ = quote;
  }

  /**
   * Sets the quote-escape character to use.  If it matches the quote
   * character, en a quote is escaped by doubling it.
   *
   * @param quote_esc The quote-escape character to use.
   */
  void set_quote_esc( char quote_esc ) {
    quote_esc_ = quote_esc;
  }

  /**
   * Sets the value-separator character to use.
   *
   * @param sep The value separator character to use.
   */
  void set_separator( char sep ) {
    sep_ = sep;
  }

  /**
   * Sets the istream to read from.
   *
   * @param is The istream to read from.
   */
  void set_stream( std::istream &is ) {
    is_ = &is;
  }

private:
  std::istream *is_;
  char quote_;
  char quote_esc_;
  char sep_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace std

#endif /* ZORBA_CSV_H */
/* vim:set et sw=2 ts=2: */
