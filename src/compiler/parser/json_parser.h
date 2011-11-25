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

#ifndef ZORBA_JSON_PARSER_H
#define ZORBA_JSON_PARSER_H

#include <zorba/config.h>

#ifdef ZORBA_WITH_JSON

#include <exception>
#include <stack>
#include <string>

#include <zorba/internal/diagnostic.h>

#include "util/cxx_util.h"
#include "util/unicode_util.h"
#include "zorbatypes/zstring.h"

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

typedef internal::diagnostic::location location;

///////////////////////////////////////////////////////////////////////////////

/**
 * A JSON %token.  Tokens have a type, location at which they were found, and
 * sometimes a value.
 *
 * See: "RFC 4627: The application/json Media Type for JavaScript Object
 * Notation (JSON)."
 */
class token {
  // see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2333.html
  struct pointer_conversion { int valid; };
  typedef int pointer_conversion::*explicit_bool;
public:
  typedef zstring value_type;

  /**
   * The types of tokens in JSON.  The first 6 constants have values that
   * correspond to the actual structural characters used by JSON; the rest were
   * assigned non-standard, mnemonic values for convenience.
   */
  enum type {
    none,
    begin_array     = '[',
    begin_object    = '{',
    end_array       = ']',
    end_object      = '}',
    name_separator  = ':',
    value_separator = ',',
    string          = 'S',
    number          = 'N',
    json_false      = 'F',
    json_null       = '0',
    json_true       = 'T',
  };

  /**
   * Default constructor.
   */
  token();

  /**
   * Clears this %token.
   */
  void clear() {
    type_ = none;
    value_.clear();
  }

  /**
   * Gets the location at which this %token was found.
   *
   * @return Returns said location.
   */
  location const& get_loc() const {
    return loc_;
  }

  /**
   * Gets the type of this %token.
   *
   * @return Returns said type.
   */
  type get_type() const {
    return type_;
  }

  /**
   * Gets the value of this %token, if any.  Only %token types string and
   * number have a value.
   *
   * @return Returns said value or the empty string.
   */
  value_type const& get_value() const {
    return value_;
  }

  /**
   * Conversion to \c bool.
   *
   * @return Returns \c true only if this token's type is not \c none.
   */
  operator explicit_bool() const {
    return type_ ? &pointer_conversion::valid : nullptr;
  }

private:
  location loc_;
  type type_;
  value_type value_;

  friend class lexer;
};

/**
 * Emits the given token to an ostream.
 *
 * @param o The ostream to emit to.
 * @param t The token to emit.
 * @return Returns \a o.
 */
std::ostream& operator<<( std::ostream &o, token const &t );

/**
 * Compares two tokens for equality.
 *
 * @param t1 The first token.
 * @param t2 The second token.
 * @return Returns \c true only if the two tokens' types and values are equal.
 */
inline bool operator==( token const &t1, token const &t2 ) {
  return t1.get_type() == t2.get_type() && t1.get_value() == t2.get_value();
}

/**
 * Compares a token's type to another type for equality.
 *
 * @param t The token whose type to compare.
 * @param tt The type to compare to.
 * @return Returns \c true only if the token's type equals \a tt.
 */
inline bool operator==( token const &t, token::type tt ) {
  return t.get_type() == tt;
}

/**
 * Compares a token's type to another type for equality.
 *
 * @param tt The type to compare.
 * @param t The token whose type to compare to.
 * @return Returns \c true only if \a tt equals the token's type.
 */
inline bool operator==( token::type tt, token const &t ) {
  return t == tt;
}

/**
 * Compares a token's value to a C string for equality.
 *
 * @param t The token whose value to compare.
 * @param value The value to compare to.
 * @return Returns \c true only if the token's value equals \a value.
 */
inline bool operator==( token const &t, char const *value ) {
  return t.get_value() == value;
}

/**
 * Compares a C string to a token's value for equality.
 *
 * @param value The value to compare.
 * @param t The token whose value to compare to.
 * @return Returns \c true only if \a value equals the token's value.
 */
inline bool operator==( char const *value, token const &t ) {
  return t == value;
}

/**
 * Compares two tokens for inequality.
 *
 * @param t1 The first token.
 * @param t2 The second token.
 * @return Returns \c true if either the two tokens' types or values are not
 * equal.
 */
inline bool operator!=( token const &t1, token const &t2 ) {
  return !(t1 == t2);
}

/**
 * Compares a token's type to another type for inequality.
 *
 * @param t The token whose type to compare.
 * @param tt The type to compare to.
 * @return Returns \c true only if the token's type is not equal to \a tt.
 */
inline bool operator!=( token const &t, token::type tt ) {
  return !(t == tt);
}

/**
 * Compares a token's type to another type for inequality.
 *
 * @param tt The type to compare.
 * @param t The token whose type to compare to.
 * @return Returns \c true only if \a tt is not equal to the token's type.
 */
inline bool operator!=( token::type tt, token const &t ) {
  return !(tt == t);
}

/**
 * Compares a token's value to a C string for inequality.
 *
 * @param t The token whose value to compare.
 * @param value The value to compare to.
 * @return Returns \c true only if the token's value is not equal to \a value.
 */
inline bool operator!=( token const &t, char const *value ) {
  return !(t == value);
}

/**
 * Compares a token's value to a C string for inequality.
 *
 * @param value The value to compare.
 * @param t The token whose value to compare to.
 * @return Returns \c true only if \a value is not equal to the token's value.
 */
inline bool operator!=( char const *value, token const &t ) {
  return !(value == t);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An %exception is the root of the JSON %exception hierarchy.
 */
class exception : public std::exception {
public:
  ~exception() throw();

  /**
   * Gets the location in the JSON source whence this exception was thrown.
   */
  location const& get_loc() const {
    return loc_;
  }

  // inherited
  char const* what() const throw();

protected:
  exception( location const &loc, std::string const &message );

private:
  location loc_;
  std::string message_;
};

/**
 * This exception is thrown when an illegal character is encountered in a JSON
 * data stream.
 */
class illegal_character : public exception {
public:
  illegal_character( location const &loc, char c );
  ~illegal_character() throw();

  /**
   * Gets the illegal character.
   *
   * @return Returns said character.
   */
  char get_char() const {
    return c_;
  }

private:
  char c_;
};

/**
 * This exception is thrown when an illegal Unicode code-point escape sequence
 * (\uHHHH) is encountered.
 */
class illegal_codepoint : public exception {
public:
  illegal_codepoint( location const &loc, token::value_type const &cp );
  ~illegal_codepoint() throw();

  /**
   * Gets the illegal code-point.
   *
   * @return Returns said code-point.
   */
  token::value_type codepoint() const {
    return codepoint_;
  }

private:
  token::value_type codepoint_;
};

/**
 * This exception is thrown when an illegal character follows a backslash
 * (escape) within a string literal.  The legal escape characters are:
 * ["/\bfnrtu].
 */
class illegal_escape : public exception {
public:
  illegal_escape( location const &loc, char escape );
  ~illegal_escape() throw();

  /**
   * Gets the illegal escape character.
   *
   * @return Returns said character.
   */
  char get_escape() const {
    return esc_;
  }

private:
  char esc_;
};

/**
 * This exception is thrown when a literal other than \c false, \c null, or
 * \c true is encountered.
 */
class illegal_literal : public exception {
public:
  illegal_literal( location const &loc );
  ~illegal_literal() throw();
};

/**
 * This exception is thrown when an illegal number is encountered.
 */
class illegal_number : public exception {
public:
  illegal_number( location const &loc );
  ~illegal_number() throw();
};

/**
 * This exception is thrown when an unexpected token is encountered.
 */
class unexpected_token : public exception {
public:
  unexpected_token( token const &t );
  ~unexpected_token() throw();

  /**
   * Gets the unexpected token
   *
   * @return Returns said token.
   */
  token const& get_token() const {
    return token_;
  }

private:
  token token_;
};

/**
 * This exception is thrown when an EOF is encountered before a string's
 * terminating quote.
 */
class unterminated_string : public exception {
public:
  unterminated_string( location const &loc );
  ~unterminated_string() throw();
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %lexer extracts JSON tokens from an istream.
 */
class lexer {
public:
  typedef location::line_type line_type;
  typedef location::column_type column_type;

  /**
   * Constructs a %lexer on the given istream.
   *
   * @param in The istream to read from.
   */
  lexer( std::istream &in );

  /**
   * Gets the next token, if any.
   *
   * @param result A pointer to the token to get into.
   * @return Returns \c true only if there was a next token.
   * @throws exception upon error.
   */
  bool next( token *result );

  /**
   * Sets the file location.
   *
   * @param file The source file name.
   * @param line The source line number.
   * @param col  The source column number.
   */
  void set_loc( char const *file, line_type line, column_type col );

private:
  location cur_loc() const {
    return location( file_, line_, col_ );
  }

  bool get_char( char* = nullptr );
  bool peek_char( char* );
  unicode::code_point parse_codepoint();
  token::type parse_literal( char );
  void parse_number( char, token::value_type* );
  void parse_string( token::value_type* );

  std::istream *in_;
  std::string file_;
  line_type line_;
  column_type col_;
  location start_loc_;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %parser extracts JSON tokens from an istream while checking to ensure the
 * token sequence is valid.
 */
class parser {
public:
  /**
   * Constructs a %parser on the given istream.
   *
   * @param in The istream to read from.
   */
  parser( std::istream &in );

  /**
   * Gets the next token, if any.
   *
   * @param result A pointer to the token to get into.
   * @return Returns \c true only if there was a next token.
   * @throws exception upon error.
   */
  bool next( token *result );

private:
  enum state {
    A0, A1, // Array
    E0, E1, // Element
    J0, J1, // JSON
    M0, M1, // Member
    O0, O1, // Object
    P0, P1, // Pair
    V0      // Value
  };

  bool get_token( token *result );
  bool matches_token( token::type, token *result );
  token::type peek_token();
  void require_token( token::type, token *result );

  lexer lexer_;
  token peeked_token_;
  std::stack<state> state_stack_;
  state state_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

#endif /* ZORBA_WITH_JSON */
#endif /* ZORBA_JSON_PARSER_H */
/* vim:set et sw=2 ts=2: */
