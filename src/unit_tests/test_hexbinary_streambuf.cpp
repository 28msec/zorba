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

#include <zorba/util/hexbinary_stream.h>

using namespace std;
using namespace zorba;

struct test {
  char const *raw_str;
  char const *hb_str;
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

///////////////////////////////////////////////////////////////////////////////

static bool test_getline( test const *t ) {
  string const hb_str( t->hb_str );
  istringstream iss( hb_str );
  hexbinary::streambuf hb_sbuf( iss.rdbuf() );
  iss.ios::rdbuf( &hb_sbuf );

  char raw_buf[ 1024 ];
  iss.getline( raw_buf, sizeof raw_buf );
  if ( iss.gcount() ) {
    string const raw_str( raw_buf );
    return raw_str == t->raw_str;
  }
  return false;
}

static bool test_read( test const *t ) {
  string const hb_str( t->hb_str );
  istringstream iss( hb_str );
  hexbinary::streambuf hb_sbuf( iss.rdbuf() );
  iss.ios::rdbuf( &hb_sbuf );

  char raw_buf[ 1024 ];
  iss.read( raw_buf, sizeof raw_buf );
  if ( iss.gcount() ) {
    string const raw_str(
      raw_buf, static_cast<string::size_type>( iss.gcount() )
    );
    return raw_str == t->raw_str;
  }
  return false;
}

static bool test_insertion( test const *t ) {
  ostringstream oss;
  hexbinary::streambuf hb_sbuf( oss.rdbuf() );
  oss.ios::rdbuf( &hb_sbuf );

  oss << t->raw_str << flush;
  string const hb_str( oss.str() );

  string const expected_hb_str( t->hb_str );
  return hb_str == expected_hb_str;
}

static bool test_put( test const *t ) {
  ostringstream oss;
  { // local scope
  hexbinary::auto_attach<ostringstream> const raii( oss );

  for ( char const *c = t->raw_str; *c; ++c )
    oss.put( *c );
  } // local scope
  string const hb_str( oss.str() );

  string const expected_hb_str( t->hb_str );
  return hb_str == expected_hb_str;
}

///////////////////////////////////////////////////////////////////////////////

static test const tests[] = {
  /* 0 */ { "Now", "4E6F77" },
  /* 1 */ { "Now is the time", "4E6F77206973207468652074696D65" },
  { 0, 0 }
};

namespace zorba {
namespace UnitTests {

int test_hexbinary_streambuf( int, char*[] ) {
  int test_no = 0;
  for ( test const *t = tests; t->raw_str; ++t, ++test_no ) {
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
