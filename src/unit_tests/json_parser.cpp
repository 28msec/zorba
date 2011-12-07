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

static void print_exception( char const *expr, int line,
                             std::exception const &e ) {
  assert_true( expr, line, false );
  cout << "+ exception: ";
  if ( json::exception const *j = dynamic_cast<json::exception const*>( &e ) ) {
    json::location const &loc = j->get_loc();
    if ( loc.file() && *loc.file() )
      cout << '"' << loc.file() << "\": ";
    cout << loc.line();
    if ( loc.column() )
      cout << ',' << loc.column();
    cout << ": ";
  }
  cout << e.what() << endl;
}

#define ASSERT_TRUE( EXPR ) assert_true( #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_EXCEPTION( EXPR, EXCEPTION ) \
  try { EXPR; assert_true( #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { }

#define ASSERT_NO_EXCEPTION( EXPR ) \
  try { EXPR; } \
  catch ( std::exception const &e ) { print_exception( #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

#define ASSERT_TRUE_AND_NO_EXCEPTION( EXPR ) \
  try { ASSERT_TRUE( EXPR ); } \
  catch ( std::exception const &e ) { print_exception( #EXPR, __LINE__, e ); } \
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

static void test_json_org_example() {
  char const source[] =
/*  1 */ "{" "\n"
/*  2 */ "  \"glossary\": {" "\n"
/*  3 */ "    \"title\": \"example glossary\"," "\n"
/*  4 */ "    \"GlossDiv\": {" "\n"
/*  5 */ "      \"title\": \"S\"," "\n"
/*  6 */ "      \"GlossList\": {" "\n"
/*  7 */ "        \"GlossEntry\": {" "\n"
/*  8 */ "          \"ID\": \"SGML\"," "\n"
/*  9 */ "          \"SortAs\": \"SGML\"," "\n"
/* 10 */ "          \"GlossTerm\": \"Standard Generalized Markup Language\"," "\n"
/* 11 */ "          \"Acronym\": \"SGML\"," "\n"
/* 12 */ "          \"Abbrev\": \"ISO 8879:1986\"," "\n"
/* 13 */ "          \"GlossDef\": {" "\n"
/* 14 */ "            \"para\": \"A meta-markup language, used to create markup languages such as DocBook.\"," "\n"
/* 15 */ "            \"GlossSeeAlso\": [\"GML\", \"XML\"]" "\n"
/* 16 */ "          }," "\n"
/* 17 */ "          \"GlossSee\": \"markup\"" "\n"
/* 18 */ "        }" "\n"
/* 19 */ "      }" "\n"
/* 20 */ "    }" "\n"
/* 21 */ "  }" "\n"
/* 22 */ "}" "\n" ;

  istringstream iss( source );
  parser p( iss );
  token t;

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  1: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  2: "glossary"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  2: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  2: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  3: "title"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  3: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  3: "example glossary"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  3: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  4: "GlossDiv"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  4: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  4: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  5: "title"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  5: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  5: "S"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  5: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  6: "GlossList"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  6: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  6: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  7: "GlossEntry"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  7: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  7: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  8: "ID"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  8: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  8: "SGML"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  8: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  9: "SortAs"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  9: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  9: "SGML"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  //  9: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 10: "GlossTerm"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 10: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 10: "Standard ..."
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 10: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 11: "Acronym"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 11: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 11: "SGML"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 11: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 12: "Abbrev"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 12: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 12: "ISO 8879:1986"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 12: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 13: "GlossDef"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 13: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 13: {
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 14: "para"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 14: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 14: "A meta-markup ..."
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 14: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: "GlossSeeAlso"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: [
  ASSERT_TRUE( t == token::begin_array );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: "GML"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: "XML"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 15: ]
  ASSERT_TRUE( t == token::end_array );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 16: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 16: ,
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 17: "GlossSee"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 17: :
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 17: "markup"
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 18: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 19: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 20: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 21: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );  // 22: }
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE( !p.next( &t ) );
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

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::begin_array );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::number );
  ASSERT_TRUE( t.get_value() == "1" );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::string );
  ASSERT_TRUE( t.get_value() == "2" );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::json_false );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::json_true );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::json_null );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::end_array );

  ASSERT_TRUE( !p.next( &t ) );
}

static void test_parser_object() {
  char const source[] = "{ \"a\" : 1, \"b\" : \"2\" }";
  istringstream iss( source );
  parser p( iss );
  token t;

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::begin_object );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::number );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::value_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::name_separator );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::string );

  ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
  ASSERT_TRUE( t == token::end_object );

  ASSERT_TRUE( !p.next( &t ) );
}

static void test_unexpected_token() {
  token t;
  {
    char const source[] = "{ 1 }";
    istringstream iss( source );
    parser p( iss );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::begin_object );
    ASSERT_EXCEPTION( p.next( &t ), unexpected_token );
  }
  {
    char const source[] = "{ \"a\" : 1, }";
    istringstream iss( source );
    parser p( iss );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::begin_object );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::string );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::name_separator );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::number );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::value_separator );

    ASSERT_EXCEPTION( p.next( &t ), unexpected_token );
  }
  {
    char const source[] = "{ \"t\" : true \"f\" : false }";
    istringstream iss( source );
    parser p( iss );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::begin_object );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::string );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::name_separator );

    ASSERT_TRUE_AND_NO_EXCEPTION( p.next( &t ) );
    ASSERT_TRUE( t == token::json_true );

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

  // lexer-only tests
  test_lexer_array();
  test_lexer_object();
  test_illegal_character();
  test_illegal_codepoint();
  test_illegal_escape();
  test_illegal_literal();
  test_illegal_number();
  test_unterminated_string();

  // parser tests
  test_parser_array();
  test_parser_object();
  test_unexpected_token();
  test_json_org_example();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
