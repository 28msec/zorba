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
#include <string>

#include "util/unordered_set.h"

using namespace std;

typedef unordered_set<string> set_type;
typedef pair<set_type::iterator,bool> insert_return_type;
typedef pair<set_type::iterator,set_type::iterator> equal_range_return_type;

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

///////////////////////////////////////////////////////////////////////////////

static void test_basics() {
  set_type set;
  insert_return_type ir;

  ASSERT_TRUE( set.empty() );
  ASSERT_TRUE( set.size() == 0 );

  ir = set.insert( "a" );
  if ( ASSERT_TRUE( ir.second ) )
    if ( ASSERT_TRUE( ir.first != set.end() ) )
      ASSERT_TRUE( *ir.first == "a" );

  ir = set.insert( "b" );
  if ( ASSERT_TRUE( ir.second ) )
    if ( ASSERT_TRUE( ir.first != set.end() ) )
      ASSERT_TRUE( *ir.first == "b" );

  ASSERT_TRUE( !set.empty() );
  ASSERT_TRUE( set.size() == 2 );

  set_type set2( set );

  ASSERT_TRUE( !set2.empty() );
  ASSERT_TRUE( set2.size() == 2 );

  set2.clear();
  ASSERT_TRUE( set2.empty() );
  ASSERT_TRUE( set2.size() == 0 );

  // Ensure 'set' is unaffected by changes to 'set2'.
  ASSERT_TRUE( !set.empty() );
  ASSERT_TRUE( set.size() == 2 );
}

static void test_erase() {
  set_type set;
  set_type::iterator i;

  set.insert( "a" );
  set.insert( "b" );

  ASSERT_TRUE( set.erase( "a" ) == 1 );
  ASSERT_TRUE( set.erase( "a" ) == 0 );
  ASSERT_TRUE( !set.empty() );
  ASSERT_TRUE( set.size() == 1 );

  if ( ASSERT_TRUE( (i = set.find( "b" )) != set.end() ) ) {
    set.erase( i );
    ASSERT_TRUE( set.empty() );
    ASSERT_TRUE( set.size() == 0 );
  }
}

static void test_insert() {
  set_type set;
  equal_range_return_type err;
  set_type::iterator i;
  insert_return_type ir;

  ir = set.insert( "a" );
  if ( ASSERT_TRUE( ir.second ) )
    ASSERT_TRUE( *ir.first == "a" );
  ASSERT_TRUE( !set.empty() );
  ASSERT_TRUE( set.size() == 1 );
  ASSERT_TRUE( set.count( "a" ) == 1 );

  if ( ASSERT_TRUE( (i = set.find( "a" )) != set.end() ) )
    ASSERT_TRUE( *i == "a" );
  err = set.equal_range( "a" );
  if ( ASSERT_TRUE( err.first != set.end() ) )
    ASSERT_TRUE( *err.first == "a" );

  ir = set.insert( "b" );
  if ( ASSERT_TRUE( ir.second ) )
    if ( ASSERT_TRUE( ir.first != set.end() ) )
      ASSERT_TRUE( *ir.first == "b" );
  ASSERT_TRUE( !set.empty() );
  ASSERT_TRUE( set.size() == 2 );
  ASSERT_TRUE( set.count( "b" ) == 1 );

  if ( ASSERT_TRUE( (i = set.find( "b" )) != set.end() ) )
    ASSERT_TRUE( *i == "b" );
  err = set.equal_range( "b" );
  if ( ASSERT_TRUE( err.first != set.end() ) )
    ASSERT_TRUE( *err.first == "b" );

  // Ensure "a" is still there.
  if ( ASSERT_TRUE( (i = set.find( "a" )) != set.end() ) )
    ASSERT_TRUE( *i == "a" );
  ASSERT_TRUE( set.count( "a" ) == 1 );
  err = set.equal_range( "a" );
  if ( ASSERT_TRUE( err.first != set.end() ) )
    ASSERT_TRUE( *err.first == "a" );
}

static void test_local_iterator() {
  set_type set;

  char s[2];
  s[1] = '\0';
  for ( int i = 0; i < 26; ++i ) {
    *s = (char)('a' + i);
    set.insert( s );
  }

  set_type::size_type b = set.bucket( "a" );
  ASSERT_TRUE( set.bucket_size( b ) > 0 );

  bool found_a = false;
  set_type::local_iterator i( set.begin( b ) );
  set_type::local_iterator const j( set.end( b ) );
  for ( ; i != j; ++i )
    if ( *i == "a" ) {
      found_a = true;
      break;
    }
  ASSERT_TRUE( found_a );
}

static void test_rehash() {
  unordered_set<int> set;
  unordered_set<int>::const_iterator i;

  unordered_set<int>::size_type const initial_buckets = set.bucket_count();

  // Add elements until bucket_count() changes which implies a rehash was done.
  for ( int n = 0; set.bucket_count() == initial_buckets; ++n )
    set.insert( n );

  ASSERT_TRUE( set.bucket_count() > initial_buckets );

  // Ensure all the elements are still there.
  unordered_set<int>::size_type const size = set.size();
  for ( int n = 0; n < size; ++n ) {
    if ( ASSERT_TRUE( (i = set.find( n )) != set.end() ) )
      ASSERT_TRUE( *i == n );
  }
}

static void test_swap() {
  unordered_set<string>::iterator i;

  set_type set;
  set.insert( "a" );
  set.insert( "b" );

  set_type set2;
  set2.insert( "c" );
  set2.insert( "d" );
  set2.insert( "e" );

  set.swap( set2 );

  ASSERT_TRUE( set.size() == 3 );
  ASSERT_TRUE( set2.size() == 2 );

  ASSERT_TRUE( set.find( "a" ) == set.end() );
  ASSERT_TRUE( set.find( "b" ) == set.end() );

  if ( ASSERT_TRUE( (i = set.find( "c" )) != set.end() ) )
    ASSERT_TRUE( *i == "c" );
  if ( ASSERT_TRUE( (i = set.find( "d" )) != set.end() ) )
    ASSERT_TRUE( *i == "d" );
  if ( ASSERT_TRUE( (i = set.find( "e" )) != set.end() ) )
    ASSERT_TRUE( *i == "e" );

  if ( ASSERT_TRUE( (i = set2.find( "a" )) != set2.end() ) )
    ASSERT_TRUE( *i == "a" );
  if ( ASSERT_TRUE( (i = set2.find( "b" )) != set2.end() ) )
    ASSERT_TRUE( *i == "b" );
  ASSERT_TRUE( set2.find( "c" ) == set2.end() );
  ASSERT_TRUE( set2.find( "d" ) == set2.end() );
  ASSERT_TRUE( set2.find( "e" ) == set2.end() );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_unordered_set( int, char*[] ) {
  test_basics();
  test_erase();
  test_insert();
  test_local_iterator();
  test_rehash();
  test_swap();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
