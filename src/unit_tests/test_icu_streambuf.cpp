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

#include "util/transcode_streambuf.h"

using namespace std;
using namespace zorba;

#define COPYRIGHT_ISO     "\xA9"
#define COPYRIGHT_UTF8    "\xC2\xA9"

#define ONE_THIRD_UTF8    "\xE2\x85\x93"
#define ONE_THIRD_UTF16BE "\x21\x53"

struct test {
  char const *ext_charset;
  char const *ext_str;
  int ext_len;
  char const *utf8_str;
};

static test const tests[] = {
  /*  0 */ { "ISO-8859-1", "Copyright " COPYRIGHT_ISO " 2011", 0, "Copyright " COPYRIGHT_UTF8 " 2011" },
  /*  1 */ { "UTF-16BE", ONE_THIRD_UTF16BE "\0 \0c\0u\0p", 10, ONE_THIRD_UTF8 " cup" },
  { 0, 0, 0, 0 }
};

static string make_ext_str( test const *t ) {
  if ( t->ext_len )
    return string( t->ext_str, t->ext_len );
  return string( t->ext_str );
}

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
  catch ( std::exception const &e ) { print_exception( NO, #EXPR, __LINE__, e ); }

///////////////////////////////////////////////////////////////////////////////

static bool test_getline( test const *t ) {
  string const ext_str( make_ext_str( t ) );
  istringstream iss( ext_str );
  icu_streambuf xbuf( t->ext_charset, iss.rdbuf() );
  iss.ios::rdbuf( &xbuf );

  char utf8_buf[ 1024 ];
  iss.getline( utf8_buf, sizeof utf8_buf );
  if ( iss.gcount() ) {
    string const utf8_str( utf8_buf );
    return utf8_str == t->utf8_str;
  }
  return false;
}

static bool test_read( test const *t ) {
  string const ext_str( make_ext_str( t ) );
  istringstream iss( ext_str );
  icu_streambuf xbuf( t->ext_charset, iss.rdbuf() );
  iss.ios::rdbuf( &xbuf );

  char utf8_buf[ 1024 ];
  iss.read( utf8_buf, sizeof utf8_buf );
  if ( iss.gcount() ) {
    string const utf8_str( utf8_buf, iss.gcount() );
    return utf8_str == t->utf8_str;
  }
  return false;
}

static bool test_insertion( test const *t ) {
  ostringstream oss;
  icu_streambuf xbuf( t->ext_charset, oss.rdbuf() );
  oss.ios::rdbuf( &xbuf );

  oss << t->utf8_str << flush;
  string const ext_str( oss.str() );

  string const expected_ext_str( make_ext_str( t ) );
  return ext_str == expected_ext_str;
}

static bool test_put( test const *t ) {
  ostringstream oss;
  icu_streambuf xbuf( t->ext_charset, oss.rdbuf() );
  oss.ios::rdbuf( &xbuf );

  for ( char const *c = t->utf8_str; *c; ++c )
    oss.put( *c );
  string const ext_str( oss.str() );

  string const expected_ext_str( make_ext_str( t ) );
  return ext_str == expected_ext_str;
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_icu_streambuf( int, char*[] ) {
  int test_no = 0;
  for ( test const *t = tests; t->utf8_str; ++t, ++test_no ) {
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_getline( t ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_read( t ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_insertion( t ) );
    ASSERT_TRUE_AND_NO_EXCEPTION( test_no, test_put( t ) );
  }
  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
