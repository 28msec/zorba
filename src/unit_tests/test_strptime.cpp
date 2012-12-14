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
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#include "util/stl_util.h"
#include "util/strptime.h"
#include "zorbautils/locale.h"

using namespace std;
using namespace zorba;

namespace zloc = zorba::locale;

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
  cout << "+ exception: " << e.what() << endl;
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

static void test_ampm() {
  char const fmt[] = "%l%M %p";
  char const *bp;
  ztm tm;

  {
    string buf = "0123 ";
    buf += zloc::get_time_ampm( false );
    ::memset( &tm, 0, sizeof( tm ) );
    ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, fmt, &tm ) );
    ASSERT_TRUE( bp = buf.c_str() + buf.length() );
    ASSERT_TRUE( tm.tm_hour ==  1 );
    ASSERT_TRUE( tm.tm_min  == 23 );
  }
  {
    string buf = "0123 ";
    buf += zloc::get_time_ampm( true );
    ::memset( &tm, 0, sizeof( tm ) );
    ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, fmt, &tm ) );
    ASSERT_TRUE( bp = buf.c_str() + buf.length() );
    ASSERT_TRUE( tm.tm_hour == 13 );    // note 1300 hours
    ASSERT_TRUE( tm.tm_min  == 23 );
  }
}

///////////////////////////////////////////////////////////////////////////////

static void test_literals() {
  char const fmt[] = "JUNK %k %% JUNK %t JUNK %n %M";
  char const buf[] = "JUNK 14 % JUNK JUNK 15";
  size_t const len = ::strlen( buf );
  char const *bp;
  ztm tm;
  ::memset( &tm, 0, sizeof( tm ) );
  ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, fmt, &tm ) );
  ASSERT_TRUE( bp == buf + len );
  ASSERT_TRUE( tm.tm_hour == 14 );
  ASSERT_TRUE( tm.tm_min  == 15 );
}

///////////////////////////////////////////////////////////////////////////////

typedef char const* (*locale_fn_type)(unsigned);
typedef int ztm::*ztm_int_ptr;

static void test_locale( char const *conv, locale_fn_type locale_fn, int limit,
                         ztm_int_ptr ztm_mbr ) {
  ztm tm;
  for ( int i = 0; i < limit; ++i ) {
    char const *bp;
    {
      char const *const buf = (*locale_fn)( i );
      size_t const len = ::strlen( buf );
      ::memset( &tm, 0, sizeof( tm ) );
      ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, conv, &tm ) )
      ASSERT_TRUE( bp == buf + len );
      ASSERT_TRUE( tm.*ztm_mbr == i );
    }
    {
      string buf = (*locale_fn)( i );
      string::size_type const len = buf.length();
      buf += "JUNK";
      ::memset( &tm, 0, sizeof( tm ) );
      ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, conv, &tm ) )
      ASSERT_TRUE( bp == buf.c_str() + len );
      ASSERT_TRUE( tm.*ztm_mbr == i );
    }
  }
  ASSERT_EXCEPTION( ztd::strptime( "JUNK", conv, &tm ), invalid_argument );
}

///////////////////////////////////////////////////////////////////////////////

typedef int (*unary_fn_type)(int);

int identity( int i ) {
  return i;
}

int minus_1( int i ) {
  return i - 1;
}

int minus_1900( int i ) {
  return i - 1900;
}

int mod_12( int i ) {
  return i % 12;
}

int num_digits( int i ) {
  int n = !i;
  while ( i )
    i /= 10, ++n;
  return n;
}

static void test_range( char const *conv, int low, int high,
                        ztm_int_ptr ztm_mbr,
                        unary_fn_type unary_fn = &identity ) {
  ztd::itoa_buf_type buf;
  ztm tm;
  for ( int i = low; i <= high; ++i ) {
    ztd::itoa( i, buf );
    size_t const len = ::strlen( buf );
    char const *bp;
    ::memset( &tm, 0, sizeof( tm ) );
    ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, conv, &tm ) )
    ASSERT_TRUE( bp == buf + len );
    ASSERT_TRUE( tm.*ztm_mbr == (*unary_fn)(i) );
  }
  ASSERT_EXCEPTION( ztd::strptime( "JUNK", conv, &tm ), invalid_argument );

  ztd::itoa( --low, buf );
  ASSERT_EXCEPTION( ztd::strptime( buf   , conv, &tm ), invalid_argument );

  int const high2 = high + 1;
  if ( num_digits( high2 ) == num_digits( high ) ) {
    ztd::itoa( ++high, buf );
    ASSERT_EXCEPTION( ztd::strptime( buf   , conv, &tm ), invalid_argument );
  }
}

///////////////////////////////////////////////////////////////////////////////

static void test_D() {                  // %m/%d/%y
  ztm tm;
  char const *const buf = "1/2/12";
  size_t const len = ::strlen( buf );
  char const *bp;
  ::memset( &tm, 0, sizeof( tm ) );
  ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, "%D", &tm ) )
  ASSERT_TRUE( bp == buf + len );
  ASSERT_TRUE( tm.tm_mon == 0 );
  ASSERT_TRUE( tm.tm_mday == 2 );
  ASSERT_TRUE( tm.tm_year == 112 );     // years since 1900
}

static void test_F() {                  // %Y-%m-%d
  ztm tm;
  char const *const buf = "2012-1-2";
  size_t const len = ::strlen( buf );
  char const *bp;
  ::memset( &tm, 0, sizeof( tm ) );
  ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, "%F", &tm ) )
  ASSERT_TRUE( bp == buf + len );
  ASSERT_TRUE( tm.tm_mon == 0 );
  ASSERT_TRUE( tm.tm_mday == 2 );
  ASSERT_TRUE( tm.tm_year == 112 );     // years since 1900
}

static void test_j() {                  // dat of year: 001-366
  ztm tm;
  char const *const buf = "2012-1-2";
  size_t const len = ::strlen( buf );
  char const *bp;
  ::memset( &tm, 0, sizeof( tm ) );
  ASSERT_NO_EXCEPTION( bp = ztd::strptime( buf, "%F", &tm ) )
  ASSERT_TRUE( bp == buf + len );
  ASSERT_TRUE( tm.tm_yday == 0 );
}

static void test_zZ() {
  struct gmt_test {
    char const* s_off;
    long l_off;
  };
  static gmt_test const gmt_tests[] = {
     "0000",                        0,
     "0030",                  30 * 60,
     "0100",    1 * 60 * 60 +  0 * 60,
     "2300",   23 * 60 * 60 +  0 * 60,
     "2400",   24 * 60 * 60 +  0 * 60,
    "+0000",                        0,
    "+0030",                  30 * 60,
    "+0100",    1 * 60 * 60 +  0 * 60,
    "+2300",   23 * 60 * 60 +  0 * 60,
    "+2400",   24 * 60 * 60 +  0 * 60,
    "-0000",                        0,
    "-0030",                 -30 * 60,
    "-0100",   -1 * 60 * 60 +  0 * 60,
    "-2300",  -23 * 60 * 60 +  0 * 60,
    "GMT"  ,                        0,
    "UTC"  ,                        0,
    "UT"   ,                        0,
    "EDT"  ,   -4 * 60 * 60 +  0 * 60,
    "EST"  ,   -5 * 60 * 60 +  0 * 60,
    "CDT"  ,   -5 * 60 * 60 +  0 * 60,
    "CST"  ,   -6 * 60 * 60 +  0 * 60,
    "MDT"  ,   -6 * 60 * 60 +  0 * 60,
    "MST"  ,   -7 * 60 * 60 +  0 * 60,
    "PDT"  ,   -7 * 60 * 60 +  0 * 60,
    "PST"  ,   -8 * 60 * 60 +  0 * 60,
    0
  };

  ztm tm;
  for ( gmt_test const *t = gmt_tests; t->s_off; ++t ) {
    size_t const len = ::strlen( t->s_off );
    char const *bp;
    ::memset( &tm, 0, sizeof( tm ) );
    ASSERT_NO_EXCEPTION( bp = ztd::strptime( t->s_off, "%z", &tm ) );
    ASSERT_TRUE( bp == t->s_off + len );
    long const gmt_off = ztd::get_gmtoff( tm );
    ASSERT_TRUE( gmt_off == t->l_off );
    ASSERT_TRUE( tm.tm_isdst == (t->s_off[1] == 'D') );
  }

  static char const *const bad_gmts[] = {
    "*0000",
    "00A0",
    "9960",
    "XXX",
    0
  };
  for ( char const *const *t = bad_gmts; *t; ++t )
    ASSERT_EXCEPTION( ztd::strptime( *t, "%z", &tm ), invalid_argument );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_strptime( int, char*[] ) {

  test_locale( "%a", &zloc::get_weekday_abbr, 7, &ztm::tm_wday );
  test_locale( "%A", &zloc::get_weekday_name, 7, &ztm::tm_wday );
  test_locale( "%b", &zloc::get_month_abbr, 12, &ztm::tm_mon );
  test_locale( "%B", &zloc::get_month_name, 12, &ztm::tm_mon );

  test_range( "%d", 1,   31, &ztm::tm_mday );
  test_range( "%j", 1,  366, &ztm::tm_yday, &minus_1 );
  test_range( "%k", 0,   23, &ztm::tm_hour );
  test_range( "%H", 0,   23, &ztm::tm_hour );

  test_range( "%l", 1,   12, &ztm::tm_hour, &mod_12 );
  test_range( "%I", 1,   12, &ztm::tm_hour, &mod_12 );
  test_range( "%m", 1,   12, &ztm::tm_mon, &minus_1 );
  test_range( "%M", 0,   59, &ztm::tm_min );
  test_range( "%u", 1,    7, &ztm::tm_wday, &minus_1 );
  test_range( "%w", 0,    6, &ztm::tm_wday );
  test_range( "%Y", 0, 9999, &ztm::tm_year, &minus_1900 );

  test_D();
  test_F();
  test_zZ();
  test_literals();
  test_ampm();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
