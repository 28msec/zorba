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

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <zorba/zorba_exception.h>

#include "util/utf8_streambuf.h"

using namespace std;
using namespace zorba;

#define SMILEY_FACE           "\xF0\x9F\x98\x8A"
#define COPYRIGHT_UTF8        "\xC2\xA9"
#define ONE_THIRD_UTF8        "\xE2\x85\x93"

#define BAD_COPYRIGHT_1_UTF8  "\x42\xA9"
#define BAD_COPYRIGHT_2_UTF8  "\xC2\x79"

static char const *const tests_good[] = {
  "Hello, world!",
  "Copyright " COPYRIGHT_UTF8 " 2012",
  ONE_THIRD_UTF8 " cup sugar",
  "Smiley " SMILEY_FACE,
  "Smiley 2 " SMILEY_FACE SMILEY_FACE,
  SMILEY_FACE " Smiley",
  SMILEY_FACE SMILEY_FACE " 2 Smiley",
  0
};

static char const *const tests_bad[] = {
  "Copyright " BAD_COPYRIGHT_1_UTF8 " 2012",
  "Copyright " BAD_COPYRIGHT_2_UTF8 " 2012",
  0
};

///////////////////////////////////////////////////////////////////////////////

static int failures;

static bool assert_true( int no, char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << '#' << no << " FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

static void print_exception( int no, char const *expr, int line,
                             std::exception const &e ) {
  assert_true( no, expr, line, false );
  cout << "+ exception: " << e.what() << endl;
}

#define ASSERT_TRUE( NO, EXPR ) assert_true( NO, #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_TRUE_AND_NO_EXCEPTION( NO, EXPR ) \
  try { ASSERT_TRUE( NO, EXPR ); } \
  catch ( exception const &e ) { print_exception( NO, #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

#define ASSERT_EXCEPTION( NO, EXPR ) \
  try { EXPR; assert_true( NO, #EXPR, __LINE__, false ); } \
  catch ( ZorbaException const& ) { } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

///////////////////////////////////////////////////////////////////////////////

static bool test_getline( char const *test ) {
  istringstream iss( test );
  utf8::streambuf utf_buf( iss.rdbuf() );
  iss.ios::rdbuf( &utf_buf );
  iss.exceptions( ios::badbit );

  char buf[ 1024 ];
  iss.getline( buf, sizeof buf );
  if ( iss.gcount() ) {
    string const s( buf, static_cast<string::size_type>( iss.gcount() ) );
    return s == test;
  }
  return false;
}

static bool test_read( char const *test ) {
  istringstream iss( test );
  utf8::streambuf utf_buf( iss.rdbuf() );
  iss.ios::rdbuf( &utf_buf );
  iss.exceptions( ios::badbit );

  char buf[ 1024 ];
  iss.read( buf, sizeof buf );
  if ( iss.gcount() ) {
    string const s( buf, static_cast<string::size_type>( iss.gcount() ) );
    return s == test;
  }
  return false;
}

static bool test_insertion( char const *test ) {
  ostringstream oss;
  utf8::streambuf utf_buf( oss.rdbuf(), true );
  oss.ios::rdbuf( &utf_buf );
  oss.exceptions( ios::badbit );

  oss << test << flush;
  string const s( oss.str() );
  return s == test;
}

static bool test_put( char const *test ) {
  ostringstream oss;
  utf8::streambuf utf_buf( oss.rdbuf(), true );
  oss.ios::rdbuf( &utf_buf );
  oss.exceptions( ios::badbit );

  for ( char const *c = test; *c; ++c )
    oss.put( *c );

  string const s( oss.str() );
  return s == test;
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_utf8_streambuf( int, char*[] ) {
  int test_no = 0;
  for ( char const *const *s = tests_good; *s; ++s, ++test_no ) {
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_getline( *s ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_read( *s ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_insertion( *s ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_put( *s ) );
  }
  for ( char const *const *s = tests_bad; *s; ++s, ++test_no ) {
    ASSERT_EXCEPTION( test_no, test_getline( *s ) );
    ASSERT_EXCEPTION( test_no, test_read( *s ) );
    ASSERT_EXCEPTION( test_no, test_insertion( *s ) );
    ASSERT_EXCEPTION( test_no, test_put( *s ) );
  }
  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
