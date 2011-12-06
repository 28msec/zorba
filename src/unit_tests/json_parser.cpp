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

#include <sstream>

#include "util/json_parser.h"

using namespace std;
using namespace zorba;
using namespace zorba::json;

///////////////////////////////////////////////////////////////////////////////

static int failures;

static bool assert_true( char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << "FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

#define ASSERT_TRUE( EXPR ) assert_true( #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_EXCEPTION( EXPR, EXCEPTION ) \
  try { EXPR; assert_true( #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { }

#define ASSERT_NO_EXCEPTION( EXPR ) \
  try { EXPR; } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

///////////////////////////////////////////////////////////////////////////////

static void test_illegal_character() {
  char const source[] = " x ";
  istringstream iss( source );
  lexer lex( iss );
  token t;
  ASSERT_EXCEPTION( lex.next( &t ), illegal_character );
}

static void test_illegal_codepoint() {
  static char const *const sources[] = {
    " \" \\u  \" ",
    " \" \\u0  \" ",
    " \" \\u00  \" ",
    " \" \\u000  \" ",
    " \" \\uG  \" ",
    " \" \\u\" ",
    0
  };

  for ( char const *const *s = sources; *s; ++s ) {
    istringstream iss( *s );
    lexer lex( iss );
    token t;
    ASSERT_EXCEPTION( lex.next( &t ), illegal_codepoint );
  }
}

static void test_illegal_escape() {
  char const source[] = "  \"  \\x  \"  ";
  istringstream iss( source );
  lexer lex( iss );
  token t;
  ASSERT_EXCEPTION( lex.next( &t ), illegal_escape );
}

static void test_illegal_literal() {
  static char const *const sources[] = {
    " f ",
    " fa ",
    " fal ",
    " fals ",
    " falsee ",
    " t ",
    " tr ",
    " tru ",
    " truee ",
    " n ",
    " nu ",
    " nul ",
    " nulll ",
    0
  };

  for ( char const *const *s = sources; *s; ++s ) {
    istringstream iss( *s );
    lexer lex( iss );
    token t;
    ASSERT_EXCEPTION( lex.next( &t ), illegal_literal );
  }
}

static void test_illegal_number() {
}

static void test_lexer_array() {
  char const source[] = "[ 1, \"2\", false, true, null ]";
  istringstream iss( source );
  lexer lex( iss );
  token t;

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::begin_array );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::number );
  ASSERT_TRUE( t.get_value() == "1" );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::string );
  ASSERT_TRUE( t.get_value() == "2" );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::json_false );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::json_true );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::json_null );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::end_array );

  ASSERT_TRUE( !lex.next( &t ) );
}

static void test_lexer_object() {
  char const source[] = "{ \"a\" : 1, \"b\" : \"2\" }";
  istringstream iss( source );
  lexer lex( iss );
  token t;

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::number );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( lex.next( &t ) );
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE( !lex.next( &t ) );
}

static void test_parser_array() {
  char const source[] = "[ 1, \"2\", false, true, null ]";
  istringstream iss( source );
  parser p( iss );
  token t;

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::begin_array );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::number );
  ASSERT_TRUE( t.get_value() == "1" );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::string );
  ASSERT_TRUE( t.get_value() == "2" );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::json_false );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::json_true );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::json_null );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::end_array );

  ASSERT_TRUE( !p.next( &t ) );
}

static void test_parser_object() {
  char const source[] = "{ \"a\" : 1, \"b\" : \"2\" }";
  istringstream iss( source );
  parser p( iss );
  token t;

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::number );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE( p.next( &t ) );
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE( !p.next( &t ) );
}

static void test_unexpected_token() {
  token t;
  {
    char const source[] = "{ 1 : 1 }";
    istringstream iss( source );
    parser p( iss );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::begin_object );
    ASSERT_EXCEPTION( p.next( &t ), unexpected_token );
  }
  {
    char const source[] = "{ \"a\" : 1, }";
    istringstream iss( source );
    parser p( iss );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::begin_object );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::string );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::name_separator );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::number );

    ASSERT_TRUE( p.next( &t ) );
    ASSERT_TRUE( t == token::value_separator );

    ASSERT_EXCEPTION( p.next( &t ), unexpected_token );
  }
}

static void test_unterminated_string() {
  char const source[] = "  \"hello  ";
  istringstream iss( source );
  lexer lex( iss );
  token t;

  ASSERT_EXCEPTION( lex.next( &t ), unterminated_string );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int json_parser( int, char*[] ) {
  test_lexer_array();
  test_lexer_object();

  test_parser_array();
  test_parser_object();

  test_illegal_character();
  test_illegal_codepoint();
  test_illegal_escape();
  test_illegal_literal();
  test_illegal_number();
  test_unexpected_token();
  test_unterminated_string();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
