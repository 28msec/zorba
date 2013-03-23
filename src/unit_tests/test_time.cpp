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

#include "util/ascii_util.h"
#include "util/stl_util.h"
#include "util/time_util.h"
#include "zorbatypes/zstring.h"

using namespace std;
using namespace zorba;
using namespace zorba::time;

///////////////////////////////////////////////////////////////////////////////

static int failures;
static int test_no;

static bool assert_true( int no, char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << '#' << no << " FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

#define ASSERT_TRUE( NO, EXPR ) assert_true( NO, #EXPR, __LINE__, !!(EXPR) )

///////////////////////////////////////////////////////////////////////////////

static void test_calc_week_in_year() {
  struct test_type {
    unsigned mday, mon, year;
    time::calendar::type cal;
    int expected;
  };
  static test_type const test[] = {
    /*  1 */ {  1, time::jan, 2013, calendar::AD,  1 },
    /*  2 */ {  2, time::jan, 2013, calendar::AD,  1 },
    /*  3 */ {  3, time::jan, 2013, calendar::AD,  1 },
    /*  4 */ {  4, time::jan, 2013, calendar::AD,  1 },
    /*  5 */ {  5, time::jan, 2013, calendar::AD,  1 },
    /*  6 */ {  6, time::jan, 2013, calendar::AD,  2 },
    /*  7 */ { 28, time::dec, 2013, calendar::AD, 52 },
    /*  8 */ { 31, time::dec, 2013, calendar::AD, 53 },

    /*  9 */ {  1, time::jan, 2013, calendar::ISO,  1 },
    /* 10 */ {  2, time::jan, 2013, calendar::ISO,  1 },
    /* 11 */ {  3, time::jan, 2013, calendar::ISO,  1 },
    /* 12 */ {  4, time::jan, 2013, calendar::ISO,  1 },
    /* 13 */ {  5, time::jan, 2013, calendar::ISO,  1 },
    /* 14 */ {  6, time::jan, 2013, calendar::ISO,  1 },
    /* 15 */ {  7, time::jan, 2013, calendar::ISO,  2 },

    // Test cases taken from http://en.wikipedia.org/wiki/ISO_week_date
    /* 16 */ {  1, time::jan, 2005, calendar::ISO, 53 },
    /* 17 */ {  2, time::jan, 2005, calendar::ISO, 53 },
    /* 18 */ { 31, time::dec, 2005, calendar::ISO, 52 },
    /* 19 */ {  1, time::jan, 2007, calendar::ISO,  1 },
    /* 20 */ { 30, time::dec, 2007, calendar::ISO, 52 },
    /* 21 */ { 31, time::dec, 2007, calendar::ISO,  1 },
    /* 22 */ {  1, time::jan, 2008, calendar::ISO,  1 },
    /* 23 */ { 28, time::dec, 2008, calendar::ISO, 52 },
    /* 24 */ { 29, time::dec, 2008, calendar::ISO,  1 },
    /* 25 */ { 30, time::dec, 2008, calendar::ISO,  1 },
    /* 26 */ { 31, time::dec, 2008, calendar::ISO,  1 },
    /* 27 */ { 31, time::dec, 2009, calendar::ISO, 53 },
    /* 28 */ {  1, time::jan, 2010, calendar::ISO, 53 },
    /* 29 */ {  2, time::jan, 2010, calendar::ISO, 53 },
    /* 30 */ {  3, time::jan, 2010, calendar::ISO, 53 },
    /* 31 */ {  4, time::jan, 2010, calendar::ISO,  1 },

    { 0, 0, 0, calendar::unknown, 0 }
  };

  for ( test_type const *t = test; t->mday; ++t ) {
    int w = calendar::calc_week_in_year( t->mday, t->mon, t->year, t->cal );
    ++test_no;
    ASSERT_TRUE( test_no,  w == t->expected );
  }
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_time( int, char*[] ) {

  test_calc_week_in_year();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
