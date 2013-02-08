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

#include <iostream>
#include <stdexcept>

#include "stdafx.h"

#include <zorba/internal/diagnostic.h>

using namespace std;
using namespace zorba::internal::diagnostic;

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
  catch ( EXCEPTION const& ) { } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

#define ASSERT_NO_EXCEPTION( EXPR ) \
  try { EXPR; } \
  catch ( std::exception const &e ) { print_exception( #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

#define MAKE_PARAMS(...) \
  (::zorba::internal::diagnostic::parameters(), __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////

static void test_simple() {
  {
    string s( "x$1y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xfooy" );
  }
  {
    string s( "x$1y" );
    parameters const p( MAKE_PARAMS( "" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
}

static void test_braces() {
  {
    string s( "x${1}y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xfooy" );
  }
  {
    string s( "x${ 1 }y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "x foo y" );
  }
  {
    string s( "x${1}y" );
    parameters const p( MAKE_PARAMS( "" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
  {
    string s( "x${ 1 }y" );
    parameters const p( MAKE_PARAMS( "" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
}

static void test_conditionals() {
  { // if-true-then
    string s( "x$1?2y" );
    parameters const p( MAKE_PARAMS( "foo", "bar" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbary" );
  }
  { // if-false-then
    string s( "x$1?2y" );
    parameters const p( MAKE_PARAMS( "", "bar" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
  { // if-true-then-else
    string s( "x$1?2:3y" );
    parameters const p( MAKE_PARAMS( "foo", "bar", "baz" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbary" );
  }
  { // if-false-then-else
    string s( "x$1?2:3y" );
    parameters const p( MAKE_PARAMS( "", "bar", "baz" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbazy" );
  }
  { // if-true-{then}
    string s( "x$1?{2}y" );
    parameters const p( MAKE_PARAMS( "foo", "bar" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbary" );
  }
  { // if-false-{then}
    string s( "x$1?{2}y" );
    parameters const p( MAKE_PARAMS( "", "bar" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
  { // if-true-{then}-{else}
    string s( "x$1?{2}:{3}y" );
    parameters const p( MAKE_PARAMS( "foo", "bar", "baz" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbary" );
  }
  { // if-false-{then}-{else}
    string s( "x$1?{2}:{3}y" );
    parameters const p( MAKE_PARAMS( "", "bar", "baz" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbazy" );
  }
}

static void test_escapes() {
  {
    string s( "x\\$$1y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "x$fooy" );
  }
  {
    string s( "x${\\11\\}}y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "x1foo}y" );
  }
  {
    string s( "x$1\\?y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xfoo?y" );
  }
  {
    string s( "x$1?{bar\\}}y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbar}y" );
  }
  {
    string s( "x$1?{bar\\}}y" );
    parameters const p( MAKE_PARAMS( "" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xy" );
  }
  {
    string s( "x$1?{bar\\}}\\:{y}z" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbar}:{y}z" );
  }
  {
    string s( "x$1?{bar\\}}:{2\\}}z" );
    parameters const p( MAKE_PARAMS( "", "bar" ) );
    ASSERT_NO_EXCEPTION( p.substitute( &s ) );
    ASSERT_TRUE( s == "xbar}z" );
  }
}

static void test_exceptions() {
  {
    string s( "x$1?y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_EXCEPTION( p.substitute( &s ), invalid_argument );
  }
  {
    string s( "x$1?{y" );
    parameters const p( MAKE_PARAMS( "foo" ) );
    ASSERT_EXCEPTION( p.substitute( &s ), invalid_argument );
  }
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_parameters( int, char*[] ) {
  test_simple();
  test_braces();
  test_conditionals();
  test_escapes();
  test_exceptions();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba
/* vim:set et sw=2 ts=2: */
