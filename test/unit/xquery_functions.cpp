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
#include <sstream>

#include <zorba/xquery_functions.h>

using namespace std;
using namespace zorba;

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

static void test_tokenize() {
  Sequence<String> tokens( fn::tokenize( "a,b,c", "," ) );
  ostringstream oss;
  for ( String s; tokens.next( &s ); )
    oss << s;
  ASSERT_TRUE( oss.str() == "abc" );
}

int xquery_functions( int, char*[] ) {
  test_tokenize();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}
/* vim:set et sw=2 ts=2: */
