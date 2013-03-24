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
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "util/hexbinary_util.h"

using namespace std;
using namespace zorba;

struct test {
  char const *input;
  char const *expected;
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

#define ASSERT_NO_EXCEPTION( NO, EXPR ) \
  try { EXPR; } \
  catch ( exception const &e ) { print_exception( NO, #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

#define ASSERT_EXCEPTION( NO, EXPR, EXCEPTION ) \
  try { EXPR; assert_true( NO, #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

///////////////////////////////////////////////////////////////////////////////}

static void test_decode_buf_to_buf( int no, string const &in,
                                    string const &expected ) {
  hexbinary::size_type n = 0;
  char out[ 1024 ];
  ASSERT_NO_EXCEPTION( no, n = hexbinary::decode( in.data(), in.size(), out ) );
  ASSERT_TRUE( no, n == expected.size() );
  out[ n ] = '\0';
  ASSERT_TRUE( no, out == expected );
}

static void test_decode_buf_to_string( int no, string const &in,
                                       string const &expected ) {
  hexbinary::size_type n = 0;
  string out;
  ASSERT_NO_EXCEPTION(
    no, n = hexbinary::decode( in.data(), in.size(), &out )
  );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, out == expected );
}

static void test_decode_buf_to_vector( int no, string const &in,
                                       string const &expected ) {
  hexbinary::size_type n = 0;
  vector<char> out;
  ASSERT_NO_EXCEPTION(
    no, n = hexbinary::decode( in.data(), in.size(), &out )
  );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, !strncmp( &out[0], expected.data(), expected.size() ) );
}

static void test_decode_stream_to_stream( int no, string const &in,
                                          string const &expected ) {
  hexbinary::size_type n = 0;
  istringstream sin( in );
  ostringstream sout;
  ASSERT_NO_EXCEPTION( no, n = hexbinary::decode( sin, sout ) );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, sout.str().size() == expected.size() );
  ASSERT_TRUE( no, sout.str() == expected );
}

static void test_decode_stream_to_string( int no, string const &in,
                                          string const &expected ) {
  hexbinary::size_type n = 0;
  istringstream sin( in );
  string out;
  ASSERT_NO_EXCEPTION( no, n = hexbinary::decode( sin, &out ) );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, out == expected );
}

static void test_decode_stream_to_vector( int no, string const &in,
                                          string const &expected ) {
  hexbinary::size_type n = 0;
  istringstream sin( in );
  vector<char> out;
  ASSERT_NO_EXCEPTION( no, n = hexbinary::decode( sin, &out ) );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, !strncmp( &out[0], expected.data(), expected.size() ) );
}

static void test_decode_exception( int no, string const &in ) {
  char out[ 1024 ];
  ASSERT_EXCEPTION(
    no, hexbinary::decode( in.data(), in.size(), out ), invalid_argument
  );
}

///////////////////////////////////////////////////////////////////////////////

static void test_encode_buf_to_buf( int no, string const &in,
                                    string const &expected ) {
  char out[ 1024 ];
  hexbinary::size_type const n = hexbinary::encode( in.data(), in.size(), out );
  ASSERT_TRUE( no, n == expected.size() );
  out[ n ] = '\0';
  ASSERT_TRUE( no, out == expected );
}

static void test_encode_buf_to_string( int no, string const &in,
                                       string const &expected ) {
  string out;
  hexbinary::size_type const n =
    hexbinary::encode( in.data(), in.size(), &out );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, out == expected );
}

static void test_encode_buf_to_vector( int no, string const &in,
                                       string const &expected ) {
  vector<char> out;
  hexbinary::size_type const n =
    hexbinary::encode( in.data(), in.size(), &out );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, !strncmp( &out[0], expected.data(), expected.size() ) );
}

static void test_encode_stream_to_stream( int no, string const &in,
                                          string const &expected ) {
  istringstream sin( in );
  ostringstream sout;
  hexbinary::size_type const n = hexbinary::encode( sin, sout );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, sout.str().size() == expected.size() );
  ASSERT_TRUE( no, sout.str() == expected );
}

static void test_encode_stream_to_string( int no, string const &in,
                                          string const &expected ) {
  istringstream sin( in );
  string out;
  hexbinary::size_type const n = hexbinary::encode( sin, &out );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, out == expected );
}

static void test_encode_stream_to_vector( int no, string const &in,
                                          string const &expected ) {
  istringstream sin( in );
  vector<char> out;
  hexbinary::size_type const n = hexbinary::encode( sin, &out );
  ASSERT_TRUE( no, n == expected.size() );
  ASSERT_TRUE( no, out.size() == expected.size() );
  ASSERT_TRUE( no, !strncmp( &out[0], expected.data(), expected.size() ) );
}

///////////////////////////////////////////////////////////////////////////////

static test const encode_tests[] = {
  /* 0 */ { "Now is the time" , "4E6F77206973207468652074696D65"   },
  /* 1 */ { "Now is the time.", "4E6F77206973207468652074696D652E" },

  { 0, 0 }
};

static test const decode_tests[] = {
  /* 2 */ { "4E6F77206973207468652074696D65"  , "Now is the time"  },
  /* 3 */ { "4e6f77206973207468652074696d652e", "Now is the time." },

  { 0, 0 }
};

static char const *const decode_exception_tests[] = {
  /* 4 */ "A",
  /* 5 */ "AAA",
  /* 6 */ "``",
  /* 7 */ "!!",
  /* 8 */ "##",
  /* 9 */ "$$",
  0
};

namespace zorba {
namespace UnitTests {

int test_hexbinary( int, char*[] ) {
  int test_no = 0;

  for ( test const *t = encode_tests; t->input; ++t, ++test_no ) {
    test_encode_buf_to_buf( test_no, t->input, t->expected );
    test_encode_buf_to_string( test_no, t->input, t->expected );
    test_encode_buf_to_vector( test_no, t->input, t->expected );
    test_encode_stream_to_stream( test_no, t->input, t->expected );
    test_encode_stream_to_string( test_no, t->input, t->expected );
    test_encode_stream_to_vector( test_no, t->input, t->expected );
  }

  for ( test const *t = decode_tests; t->input; ++t, ++test_no ) {
    test_decode_buf_to_buf( test_no, t->input, t->expected );
    test_decode_buf_to_string( test_no, t->input, t->expected );
    test_decode_buf_to_vector( test_no, t->input, t->expected );
    test_decode_stream_to_stream( test_no, t->input, t->expected );
    test_decode_stream_to_string( test_no, t->input, t->expected );
    test_decode_stream_to_vector( test_no, t->input, t->expected );
  }

  for ( char const *const *t = decode_exception_tests; *t; ++t, ++test_no )
    test_decode_exception( test_no, *t );

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
