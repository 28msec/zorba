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
#include <iostream>
#include <stdexcept>
#include <string>

#include "util/cxx_util.h"
#include "util/string_util.h"

using namespace std;
using namespace zorba;

///////////////////////////////////////////////////////////////////////////////

static int failures;

static bool assert_true( int no, char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << '#' << no << " FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

#define ASSERT_TRUE( NO, EXPR ) assert_true( NO, #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_EXCEPTION( NO, EXPR, EXCEPTION ) \
  try { EXPR; assert_true( NO, #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

///////////////////////////////////////////////////////////////////////////////}

static void test_atoll( int no, string const &s ) {
  char const *last;
  ASSERT_EXCEPTION(
    no, ztd::atoll( s.data(), s.data() + s.size(), &last ), range_error
  );
}

static void test_atoull( int no, string const &s ) {
  char const *last;
  ASSERT_EXCEPTION(
    no, ztd::atoull( s.data(), s.data() + s.size(), &last ), range_error
  );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_ato_( int, char*[] ) {
  ascii::itoa_buf_type buf;
  string s;
  int test_no = 0;

  // test overflow
  s = ascii::itoa( numeric_limits<long long>::max(), buf );
  s += '0';
  test_atoll( test_no++, s );

  // test underflow
  s = ascii::itoa( numeric_limits<long long>::min(), buf );
  s += '0';
  test_atoll( test_no++, s );

  // test overflow
  s = ascii::itoa( numeric_limits<unsigned long long>::max(), buf );
  s += '0';
  test_atoull( test_no++, s );

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
