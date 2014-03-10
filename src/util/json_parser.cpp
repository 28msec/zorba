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

#include "stdafx.h"

#include "diagnostics/assert.h"

#include "ascii_util.h"
#include "stl_util.h"
#include "string_util.h"
#include "utf8_util.h"

#define DEBUG_JSON_PARSER 0
#if DEBUG_JSON_PARSER
# include "indent.h"
#endif /* DEBUG_JSON_PARSER */

#include "json_parser.h"

using namespace std;

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

char const *const type_string_of[] = {
  "none",
  "array",
  "boolean",
  "null",
  "number",
  "object",
  "string"
};

type map_type( token::type tt ) {
  switch ( tt ) {
    case token::string:
      return string;
    case token::number:
      return number;
    case token::json_false:
    case token::json_true:
      return boolean;
    case token::json_null:
      return null;
    default:
      return none;
  }
}

///////////////////////////////////////////////////////////////////////////////

exception::exception( location const &loc, std::string const &message ) :
  loc_( loc ), message_( message )
{
}

exception::~exception() throw() {
  // out-of-line since it's virtual
}

char const* exception::what() const throw() {
  return message_.c_str();
}

illegal_character::illegal_character( location const &loc, char c ) :
  exception(
    loc,
    BUILD_STRING( '\'', ascii::printable_char( c ), "': illegal character" )
  ),
  c_( c )
{
}

illegal_character::~illegal_character() throw() {
  // out-of-line since it's virtual
}

illegal_codepoint::illegal_codepoint( location const &loc,
                                      token::value_type const &cp ) :
  exception( loc, BUILD_STRING( '"', cp, "\": illegal codepoint" ) ),
  codepoint_( cp )
{
}

illegal_codepoint::~illegal_codepoint() throw() {
  // out-of-line since it's virtual
}

illegal_escape::illegal_escape( location const &loc, char c ) :
  exception(
    loc,
    BUILD_STRING(
      "\"\\", ascii::printable_char( c ), "\": illegal character escape"
    )
  ),
  esc_( c )
{
}

illegal_escape::~illegal_escape() throw() {
  // out-of-line since it's virtual
}

illegal_literal::illegal_literal( location const &loc ) :
  exception( loc, "illegal literal" )
{
}

illegal_literal::~illegal_literal() throw() {
  // out-of-line since it's virtual
}

illegal_number::illegal_number( location const &loc ) :
  exception( loc, "illegal number" )
{
}

illegal_number::~illegal_number() throw() {
  // out-of-line since it's virtual
}

unexpected_token::unexpected_token( token const &t ) :
  exception( t.get_loc(), BUILD_STRING( '"', t, "\": unexpected token" ) ),
  token_( t )
{
}

unexpected_token::~unexpected_token() throw() {
  // out-of-line since it's virtual
}

unterminated_string::unterminated_string( location const &loc ) :
  exception( loc, "unterminated string" )
{
}

unterminated_string::~unterminated_string() throw() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

token::token() : type_( none ), numeric_type_( non_numeric ) {
}

ostream& operator<<( ostream &o, token::type tt ) {
  switch ( tt ) {
    case token::string    : o << "string"; break;
    case token::number    : o << "number"; break;
    case token::json_false: o << "false" ; break;
    case token::json_null : o << "null"  ; break;
    case token::json_true : o << "true"  ; break;
    case token::none      : o << "<none>"; break;
    default               : o << static_cast<char>( tt );
  }
  return o;
}

std::ostream& operator<<( ostream &o, token::numeric_type nt ) {
  switch ( nt ) {
    case token::non_numeric   : o << "<non_numeric>" ; break;
    case token::integer       : o << "integer"       ; break;
    case token::decimal       : o << "decimal"       ; break;
    case token::floating_point: o << "floating_point"; break;
  }
  return o;
}

ostream& operator<<( ostream &o, token const &t ) {
  switch ( t.get_type() ) {
    case token::string: o << '"' << t.get_value() << '"'; break;
    case token::number: o <<        t.get_value()       ; break;
    default           : o <<        t.get_type()        ;
  }
  return o;
}

///////////////////////////////////////////////////////////////////////////////

inline bool lexer::peek_char( char *c ) {
  *c = in_->peek();
  return in_->good();
}

inline void lexer::set_cur_loc() {
  cur_loc_.set( line_, col_, line_, col_ );
}

inline location& set_loc_end( location *loc, location::line_type line_end,
                              location::column_type col_end ) {
  loc->set( loc->line(), loc->column(), line_end, col_end );
  return *loc;
}

inline void lexer::set_loc_range( location *loc ) {
  loc->set(
    cur_loc_.file(), cur_loc_.line(), cur_loc_.column(), prev_line_, prev_col_
  );
}

lexer::lexer( istream &in ) : in_( &in ) {
  line_ = prev_line_ = 1;
  col_ = prev_col_ = 1;
}

bool lexer::get_char( char *c ) {
  char const temp = in_->get();
  if ( in_->good() ) {
    prev_line_ = line_;
    prev_col_ = col_;
    if ( temp == '\n' )
      ++line_, col_ = 1;
    else
      ++col_;
    *c = temp;
    return true;
  }
  return false;
}

bool lexer::next( token *t, bool throw_exceptions ) {
  while ( true ) {
    set_cur_loc();
    char c;
    if ( !get_char( &c ) )
      return false;
    switch ( c ) {
      case ' ':
      case '\n':
      case '\r':
      case '\t':
        continue;
      case '"': {
        //
        // We need to remember the opening quote location here because
        // parse_string() calls set_cur_loc().
        //
        location::line_type const quote_line = cur_loc_.line();
        location::column_type const quote_col = cur_loc_.column();
        if ( !parse_string( throw_exceptions ) )
          return false;
        t->value_ = value_;
        t->type_ = token::string;
        t->loc_.set(
          cur_loc_.file(), quote_line, quote_col, prev_line_, prev_col_
        );
        return true;
      }
      case '-':
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': {
        token::numeric_type nt;
        if ( !(nt = parse_number( c, throw_exceptions )) )
          return false;
        t->value_ = value_;
        t->numeric_type_ = nt;
        t->type_ = token::number;
        set_loc_range( &t->loc_ );
        return true;
      }
      case 'f':   // false
      case 'n':   // null
      case 't': { // true
        token::type tt;
        if ( !(tt = parse_literal( c, throw_exceptions )) )
          return false;
        t->value_ = value_;
        t->type_ = tt;
        set_loc_range( &t->loc_ );
        return true;
      }
      case '[':
      case '{':
      case ']':
      case '}':
      case ':':
      case ',':
        t->type_ = static_cast<token::type>( c );
        t->loc_ = cur_loc_;
        return true;
      default:
        if ( throw_exceptions )
          throw illegal_character( cur_loc_, c );
        return false;
    }
  } // while
}

bool lexer::parse_codepoint( unicode::code_point *result,
                             bool throw_exceptions ) {
  static char const hex_digits[] = "0123456789ABCDEF";

  char c;
  zstring cp_string( "\\u" );           // needed only for error message
  unicode::code_point high_surrogate = 0;

  while ( true ) {
    unicode::code_point cp = 0;
    for ( int i = 1; i <= 4; ++i ) {
      if ( !get_char( &c ) )
        goto error_set_cur_loc_end_false;
      cp_string += c;
      if ( !ascii::is_xdigit( c ) )
        goto error_set_cur_loc_end;
      c = ascii::to_upper( c );
      char const *const p = std::strchr( hex_digits, c );
      assert( p );
      cp = (cp << 4) | (p - hex_digits);
    }

    if ( unicode::is_high_surrogate( cp ) ) {
      if ( high_surrogate )
        goto error_set_cur_loc_end;
      //
      // It's easier to parse the \u for the low surrogate here rather than
      // trying to manage state in parse_string().
      //
      if ( !get_char( &c ) )
        goto error_set_cur_loc_end_false;
      cp_string += c;
      if ( c != '\\' || !get_char( &c ) )
        goto error_set_cur_loc_end;
      cp_string += c;
      if ( c != 'u' )
        goto error_set_cur_loc_end;

      high_surrogate = cp;
      continue;
    }
    if ( unicode::is_low_surrogate( cp ) ) {
      if ( !high_surrogate )
        goto error_set_cur_loc_end;
      *result = unicode::convert_surrogate( high_surrogate, cp );
      return true;
    }
    if ( high_surrogate )
      goto error_set_cur_loc_end;

    *result = cp;
    return true;
  } // while

error_set_cur_loc_end:
  if ( throw_exceptions )
    throw illegal_codepoint( set_cur_loc_end(), cp_string );
  return false;

error_set_cur_loc_end_false:
  if ( throw_exceptions )
    throw illegal_codepoint( set_cur_loc_end( false ), cp_string );
  return false;
}

token::type lexer::parse_literal( char first_c, bool throw_exceptions ) {
  static token::value_type const false_value( "false" );
  static token::value_type const null_value ( "null"  );
  static token::value_type const true_value ( "true"  );

  token::type tt = token::none;
  switch ( first_c ) {
    case 'f': value_ = false_value; tt = token::json_false; break;
    case 'n': value_ = null_value ; tt = token::json_null ; break;
    case 't': value_ = true_value ; tt = token::json_true ; break;
    default : assert( false );
  }

  char c;
  for ( char const *s = value_.c_str(); *++s; ) {
    if ( !get_char( &c ) )
      goto error_set_cur_loc_end_false;
    if ( c != *s )
      goto error_set_cur_loc_end;
  }
  if ( peek_char( &c ) && (ascii::is_alnum( c ) || c == '_') )
    goto error_set_cur_loc_end_false;

  return tt;

error_set_cur_loc_end:
  if ( throw_exceptions )
    throw illegal_literal( set_cur_loc_end() );
  return token::none;

error_set_cur_loc_end_false:
  if ( throw_exceptions )
    throw illegal_literal( set_cur_loc_end( false ) );
  return token::none;
}

token::numeric_type lexer::parse_number( char first_c, bool throw_exceptions ) {
  token::numeric_type numeric_type;
  ztd::string_appender<token::value_type,64> value( &value_ );

  value_.clear();

  // <number> ::= [-] <int> [<frac>] [<exp>]
  char c = first_c;
  if ( c == '-' ) {
    value += c;
    if ( !get_char( &c ) )
      goto error_set_cur_loc_end_false;
  }

  // <int> := '0' | <1-9> <digit>*
  if ( !ascii::is_digit( c ) )
    goto error_set_cur_loc_end;
  value += c;
  numeric_type = token::integer;
  if ( c == '0' ) {
    if ( !peek_char( &c ) )
      goto done;
    if ( ascii::is_alnum( c ) )
      goto error_set_cur_loc_end_false;
  } else {
    while ( true ) {
      if ( !peek_char( &c ) )
        goto done;
      if ( ascii::is_alpha( c ) && c != 'e' && c != 'E' )
        goto error_set_cur_loc_end_false;
      if ( !ascii::is_digit( c ) )
        break;
      get_char( &c );
      value += c;
    }
  }

  // <frac> ::= '.' <digit>+
  if ( c == '.' ) {
    get_char( &c );
    value += c;
    if ( !get_char( &c ) )
      goto error_set_cur_loc_end_false;
    if ( !ascii::is_digit( c ) )
      goto error_set_cur_loc_end;
    value += c;
    numeric_type = token::decimal;
    while ( true ) {
      if ( !peek_char( &c ) )
        goto done;
      if ( ascii::is_alpha( c ) && c != 'e' && c != 'E' )
        goto error_set_cur_loc_end_false;
      if ( !ascii::is_digit( c ) )
        break;
      get_char( &c );
      value += c;
    }
  }

  // <exp>  ::= <e> [<sign>] <digit>+
  // <e>    ::= 'e' | 'E'
  // <sign> ::= '-' | '+'
  if ( c == 'e' || c == 'E' ) {
    get_char( &c );
    value += c;
    if ( !get_char( &c ) )
      goto error_set_cur_loc_end_false;
    if ( c == '+' || c == '-' ) {
      value += c;
      if ( !get_char( &c ) )
        goto error_set_cur_loc_end_false;
    }
    if ( !ascii::is_digit( c ) )
      goto error_set_cur_loc_end;
    value += c;
    numeric_type = token::floating_point;
    while ( true ) {
      if ( !peek_char( &c ) )
        goto done;
      if ( ascii::is_alpha( c ) )
        goto error_set_cur_loc_end_false;
      if ( !ascii::is_digit( c ) )
        break;
      get_char( &c );
      value += c;
    }
  }

done:
  return numeric_type;

error_set_cur_loc_end:
  if ( throw_exceptions )
    throw illegal_number( set_cur_loc_end() );
  return token::non_numeric;

error_set_cur_loc_end_false:
  if ( throw_exceptions )
    throw illegal_number( set_cur_loc_end( false ) );
  return token::non_numeric;
}

bool lexer::parse_string( bool throw_exceptions ) {
  bool got_backslash = false;
  location start_loc( cur_loc_ );
  ztd::string_appender<token::value_type,1024> value( &value_ );

  value_.clear();

  while ( true ) {
    //
    // We need to call set_cur_loc() here since strings can have invalid
    // code-points or escapes and we need to report the exact error location of
    // those not just the start of the string.
    //
    set_cur_loc();

    char c;
    if ( !get_char( &c ) ) {
      if ( throw_exceptions )
        throw unterminated_string( set_loc_end( &start_loc, line_, col_ ) );
      return false;
    }
    if ( got_backslash ) {
      got_backslash = false;
      switch ( c ) {
        case '"':
        case '/':
        case '\\':
          value += c;
          break;
        case 'b':
          value += '\b';
          break;
        case 'f':
          value += '\f';
          break;
        case 'n':
          value += '\n';
          break;
        case 'r':
          value += '\r';
          break;
        case 't':
          value += '\t';
          break;
        case 'u': {
          unicode::code_point cp;
          if ( !parse_codepoint( &cp, throw_exceptions ) )
            return false;
          value.flush();
          utf8::encode( cp, &value_ );
          break;
        }
        default:
          if ( throw_exceptions )
            throw illegal_escape( set_cur_loc_end(), c );
          return false;
      }
      continue;
    }

    switch ( c ) {
      case '\\':
        got_backslash = true;
        break;
      case '"':
        return true;
      default:
        value += c;
    }
  } // while
}

location& lexer::set_cur_loc_end( bool prev ) {
  return prev ?
    set_loc_end( &cur_loc_, prev_line_, prev_col_ )
  :
    set_loc_end( &cur_loc_, line_, col_ );
}

void lexer::set_loc( char const *file, line_type line, column_type col ) {
  line_ = line;
  col_ = col;
  if ( file ) {
    file_ = file;
    cur_loc_.set( file, line_, col_, line_, col_ );
  }
}

///////////////////////////////////////////////////////////////////////////////

#if DEBUG_JSON_PARSER

ostream& operator<<( ostream &o, parser::state s ) {
  static char const *const string_of[] = {
    "A0", "A1", "A2",
    "E0", "E1",
    "J0", "J1",
    "M0", "M1",
    "O0", "O1", "O2",
    "P0", "P1",
    "V0"
  };
  return o << string_of[ s ];
}

static void throw_unexpected_token( int line, token const &t ) {
  try {
    throw unexpected_token( t );
  }
  catch ( exception const &e ) {
    cerr << line << ": " << e.what() << endl;
    throw;
  }
}

bool parser::get_token_debug( int line, token *t ) {
  bool const got_token = get_token( t );
  cout << line << ": get_token => " << *t << endl;
  return got_token;
}

bool parser::matches_token_debug( int line, token::type tt, token *t ) {
  bool const matched = matches_token( tt, t );
  cout << line << ": token " << *t << " matches " << tt << " => " << (matched ? 'T' : 'F') << endl;
  return matched;
}

token::type parser::peek_token_debug( int line ) {
  token::type const tt = peek_token();
  cout << line << ": peek_token => " << peeked_token_ << endl;
  return tt;
}

void parser::require_token_debug( int line, token::type tt, token *t ) {
  if ( !get_token_debug( line, t ) || t->get_type() != tt )
    throw_unexpected_token( line, *t );
}

# define GET_TOKEN(T)               get_token_debug( __LINE__, T )
# define MATCHES_TOKEN(TT,T)        matches_token_debug( __LINE__, TT, T )
# define PEEK_TOKEN()               peek_token_debug( __LINE__ )
# define REQUIRE_TOKEN(TT,T)        require_token_debug( __LINE__, TT, T )
# define THROW_UNEXPECTED_TOKEN(T)  throw_unexpected_token( __LINE__, T )

# define GOTO_STATE(S)  \
    if (0) ; else {     \
      state_ = (S);     \
      cout << __LINE__ << ':' << indent << "GOTO_STATE( " << state_ << " )" << endl;                    \
      continue;         \
    }

# define PUSH_STATE(S)      \
    if (0) ; else {         \
      state_stack_.push(S); \
      cout << __LINE__ << ':' << indent << "PUSH_STATE( " << (S) << " )" << endl << inc_indent;             \
    }

# define POP_STATE()                            \
    if (0) ; else {                             \
      state_ = ztd::pop_stack( state_stack_ );  \
      cout << __LINE__ << ':' << indent << "POP_STATE() => " << state_ << endl << dec_indent;                                   \
    }

#else

# define GET_TOKEN(T)               get_token( T )
# define MATCHES_TOKEN(TT,T)        matches_token( TT, T )
# define PEEK_TOKEN()               peek_token()
# define REQUIRE_TOKEN(TT,T)        require_token( TT, T )
# define THROW_UNEXPECTED_TOKEN(T)  throw unexpected_token( T )

# define GOTO_STATE(S)              { state_ = (S); continue; }
# define PUSH_STATE(S)              state_stack_.push(S)
# define POP_STATE()                state_ = ztd::pop_stack( state_stack_ )

#endif /* DEBUG_JSON_PARSER */

///////////////////////////////////////////////////////////////////////////////

parser::parser( std::istream &in, bool allow_multiple ) :
  allow_multiple_( allow_multiple ),
  lexer_( in )
{
  init();
}

void parser::clear() {
  peeked_token_.clear();
  ztd::clear_stack( state_stack_ );
  init();
}

void parser::init() {
#if DEBUG_JSON_PARSER
  get_indent( cout ) = 0;
#endif /* DEBUG_JSON_PARSER */
  PUSH_STATE( J0 );
}

bool parser::get_token( token *t ) {
  if ( peeked_token_ ) {
    *t = peeked_token_;
    peeked_token_.clear();
    return true;
  }
  t->clear();
  return lexer_.next( t );
}

bool parser::matches_token( token::type tt, token *t ) {
  if ( peek_token() == tt )
    return get_token( t );
  *t = peeked_token_;
  return false;
}

token::type parser::peek_token() {
  if ( !peeked_token_ )
    lexer_.next( &peeked_token_ );
  return peeked_token_.get_type();
}

#if ! DEBUG_JSON_PARSER
void parser::require_token( token::type tt, token *t ) {
  if ( !get_token( t ) || t->get_type() != tt )
    THROW_UNEXPECTED_TOKEN( *t );
}
#endif /* DEBUG_JSON_PARSER */

bool parser::next( token *t ) {
  if ( state_stack_.empty() )
    return false;
  POP_STATE();
  while ( true ) {
    switch ( state_ ) {

      // <JSON> ::= <Array> | <Object>
      case J0:  PUSH_STATE( allow_multiple_ ? J0 : J1 );
                switch ( PEEK_TOKEN() ) {
                  case token::begin_array : GOTO_STATE( A0 );
                  case token::begin_object: GOTO_STATE( O0 );
                  case token::none        : break;
                  default: THROW_UNEXPECTED_TOKEN( peeked_token_ );
                }
      case J1:  return false;

      // <Array> ::= '[' <Element>* ']'
      case A0:  REQUIRE_TOKEN( token::begin_array, t );
                PUSH_STATE( A1 );
                return true;
      case A1:  if ( MATCHES_TOKEN( token::end_array, t ) )
                  return true;
                PUSH_STATE( A2 );
                GOTO_STATE( E0 );
      case A2:  REQUIRE_TOKEN( token::end_array, t );
                return true;

      // <Element> ::= <Value> [ ',' <Element> ]
      case E0:  PUSH_STATE( E1 );
                GOTO_STATE( V0 );
      case E1:  if ( MATCHES_TOKEN( token::value_separator, t ) ) {
                  PUSH_STATE( E0 );
                  return true;
                }
                POP_STATE();
                continue;

      // <Object> ::= '{' <Member>* '}'
      case O0:  REQUIRE_TOKEN( token::begin_object, t );
                PUSH_STATE( O1 );
                return true;
      case O1:  if ( MATCHES_TOKEN( token::end_object, t ) )
                  return true;
                PUSH_STATE( O2 );
                GOTO_STATE( M0 );
      case O2:  REQUIRE_TOKEN( token::end_object, t );
                return true;

      // <Member> ::= <Pair> [ ',' <Member> ]
      case M0:  PUSH_STATE( M1 );
                GOTO_STATE( P0 );
      case M1:  if ( MATCHES_TOKEN( token::value_separator, t ) ) {
                  PUSH_STATE( M0 );
                  return true;
                }
                POP_STATE();
                continue;

      // <Pair> ::= <String> ':' <Value>
      case P0:  REQUIRE_TOKEN( token::string, t );
                PUSH_STATE( P1 );
                return true;
      case P1:  REQUIRE_TOKEN( token::name_separator, t );
                PUSH_STATE( V0 );
                return true;

      // <Value> ::= <Array> | <Object> | <String> | <Number>
      //           | false | null | true
      case V0:  switch ( PEEK_TOKEN() ) {
                  case token::begin_array:
                    GOTO_STATE( A0 );
                  case token::begin_object:
                    GOTO_STATE( O0 );
                  case token::string:
                  case token::number:
                  case token::json_false:
                  case token::json_null:
                  case token::json_true:
                    GET_TOKEN( t );
                    return true;
                  default:
                    THROW_UNEXPECTED_TOKEN( peeked_token_ );
                }
    } // switch ( state_ )
  } // while
}

token::type parser::peek( token *t ) {
  if ( token::type const tt = PEEK_TOKEN() ) {
    if ( t )
      *t = peeked_token_;
    return tt;
  }
  return token::none;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

/* vim:set et sw=2 ts=2: */
