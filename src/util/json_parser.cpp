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

#include "diagnostics/assert.h"

#include "ascii_util.h"
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

exception::exception( location const &loc, string const &message ) :
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
  exception( loc, BUILD_STRING( '\'', c, "': illegal character" ) ),
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
  exception( loc, BUILD_STRING( "\"\\", c, "\": illegal character escape" ) ),
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

token::token() :
  type_( none )
{
}

ostream& operator<<( ostream &o, token::type tt ) {
  switch ( tt ) {
    case token::string    : o << "string"; break;
    case token::number    : o << "number"; break;
    case token::json_false: o << "false" ; break;
    case token::json_null : o << "null"  ; break;
    case token::json_true : o << "true"  ; break;
    default               : o << static_cast<char>( tt );
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

lexer::lexer( istream &in ) :
  in_( &in ),
  line_( 1 ),
  col_( 1 )
{
}

bool lexer::get_char( char *c ) {
  char const temp = in_->get();
  if ( in_->good() ) {
    if ( temp == '\n' )
      ++line_, col_ = 1;
    else
      ++col_;
    if ( c )
      *c = temp;
    return true;
  }
  return false;
}

bool lexer::peek_char( char *c ) {
  *c = in_->peek();
  return in_->good();
}

bool lexer::next( token *t ) {
  while ( true ) {
    cur_loc_ = cur_loc();
    char c;
    if ( !get_char( &c ) )
      return false;
    switch ( c ) {
      case ' ':
      case '\n':
      case '\r':
      case '\t':
        continue;
      case '"':
        t->type_ = token::string;
        t->loc_ = cur_loc_;
        parse_string( &t->value_ );
        return true;
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
      case '9':
        t->type_ = token::number;
        t->loc_ = cur_loc_;
        parse_number( c, &t->value_ );
        return true;
      case 'f':
      case 'n':
      case 't':
        t->type_ = parse_literal( c );
        t->loc_ = cur_loc_;
        return true;
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
        throw illegal_character( cur_loc_, c );
    }
  } // while
}

unicode::code_point lexer::parse_codepoint() {
  static char const hex_digits[] = "0123456789ABCDEF";

  zstring cp_string( "\\u" );           // needed only for error message

  unicode::code_point cp = 0;
  for ( int i = 1; i <= 4; ++i ) {
    char c;
    if ( !get_char( &c ) || !ascii::is_xdigit( c ) )
      throw illegal_codepoint( cur_loc_, cp_string );
    cp_string += c;
    c = ascii::to_upper( c );
    char const *const p = std::strchr( hex_digits, c );
    assert( p );
    cp = (cp << 4) | (p - hex_digits);
  }
  return cp;
}

token::type lexer::parse_literal( char first_c ) {
  char const *literal;
  token::type tt;
  switch ( first_c ) {
    case 'f': literal = "false"; tt = token::json_false; break;
    case 'n': literal = "null" ; tt = token::json_null ; break;
    case 't': literal = "true" ; tt = token::json_true ; break;
    default : assert( false );
  }

  char c;
  while ( *++literal ) {
    if ( !get_char( &c ) || c != *literal )
      throw illegal_literal( cur_loc_ );
  }
  if ( peek_char( &c ) && ascii::is_alnum( c ) )
    throw illegal_literal( cur_loc_ );

  return tt;
}

void lexer::parse_number( char first_c, token::value_type *value ) {
  value->clear();

  // <number> ::= [-] <int> [<frac>] [<exp>]
  char c = first_c;
  if ( c == '-' ) {
    *value += c;
    if ( !get_char( &c ) )
      throw illegal_number( cur_loc_ );
  }

  // <int> := '0' | <1-9> <digit>*
  if ( !ascii::is_digit( c ) )
    throw illegal_number( cur_loc_ );
  *value += c;
  if ( c == '0' ) {
    if ( !get_char( &c ) )
      return;
  } else {
    while ( true ) {
      if ( !get_char( &c ) )
        return;
      if ( !ascii::is_digit( c ) )
        break;
      *value += c;
    }
  }

  // <frac> ::= '.' <digit>+
  if ( c == '.' ) {
    *value += c;
    if ( !get_char( &c ) || !ascii::is_digit( c ) )
      throw illegal_number( cur_loc_ );
    *value += c;
    while ( true ) {
      if ( !get_char( &c ) )
        return;
      if ( !ascii::is_digit( c ) )
        break;
      *value += c;
    }
  }

  // <exp>  ::= <e> [<sign>] <digit>+
  // <e>    ::= 'e' | 'E'
  // <sign> ::= '-' | '+'
  if ( c == 'e' || c == 'E' ) {
    *value += c;
    if ( !get_char( &c ) )
      throw illegal_number( cur_loc_ );
    if ( c == '+' || c == '-' ) {
      *value += c;
      if ( !get_char( &c ) )
        throw illegal_number( cur_loc_ );
    }
    if ( !ascii::is_digit( c ) )
      throw illegal_number( cur_loc_ );
    *value += c;
    while ( true ) {
      if ( !get_char( &c ) )
        return;
      if ( !ascii::is_digit( c ) )
        break;
      *value += c;
    }
  }

  in_->putback( c );
}

void lexer::parse_string( token::value_type *value ) {
  value->clear();
  bool got_backslash = false;
  location const start_loc( cur_loc_ );

  while ( true ) {
    cur_loc_ = cur_loc();
    char c;
    if ( !get_char( &c ) )
      throw unterminated_string( start_loc );
    if ( got_backslash ) {
      got_backslash = false;
      switch ( c ) {
        case '"':
        case '/':
        case '\\':
          *value += c;
          break;
        case 'b':
          *value += '\b';
          break;
        case 'f':
          *value += '\f';
          break;
        case 'n':
          *value += '\n';
          break;
        case 'r':
          *value += '\r';
          break;
        case 't':
          *value += '\t';
          break;
        case 'u':
          utf8::encode( parse_codepoint(), value );
          break;
        default:
          throw illegal_escape( cur_loc_, c );
      }
      continue;
    }

    switch ( c ) {
      case '\\':
        got_backslash = true;
        break;
      case '"':
        return;
      default:
        *value += c;
    }
  } // while
}

void lexer::set_loc( char const *file, line_type line, column_type col ) {
  if ( file )
    file_ = file;
  line_ = line;
  col_ = col;
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
  if ( get_token_debug( line, t ) && t->get_type() != tt )
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

parser::parser( istream &in ) : lexer_( in ) {
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
  return lexer_.next( t );
}

bool parser::matches_token( token::type tt, token *t ) {
  return peek_token() == tt && get_token( t );
}

token::type parser::peek_token() {
  if ( !peeked_token_ )
    lexer_.next( &peeked_token_ );
  return peeked_token_.get_type();
}

#if ! DEBUG_JSON_PARSER
void parser::require_token( token::type tt, token *t ) {
  if ( GET_TOKEN( t ) && t->get_type() != tt )
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
      case J0:  PUSH_STATE( J1 );
                switch ( PEEK_TOKEN() ) {
                  case token::begin_array : GOTO_STATE( A0 );
                  case token::begin_object: GOTO_STATE( O0 );
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

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

/* vim:set et sw=2 ts=2: */
