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

#include "util/unordered_map.h"

using namespace std;

typedef unordered_map<string,int> map_type;
typedef pair<map_type::iterator,bool> insert_return_type;

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

#define ASSERT_TRUE_AND_NO_EXCEPTION( EXPR ) \
  try { ASSERT_TRUE( EXPR ); } \
  catch ( std::exception const &e ) { print_exception( #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

#define ASSERT_EXCEPTION( EXPR, EXCEPTION ) \
  try { EXPR; assert_true( #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { }

///////////////////////////////////////////////////////////////////////////////

static void test_at() {
  map_type m;
  m[ "a" ] = 1;
  m[ "b" ] = 2;
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "a" ) == 1 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "b" ) == 2 );
  ASSERT_EXCEPTION( m.at( "c" ), out_of_range );

  map_type const mc( m );
  ASSERT_TRUE_AND_NO_EXCEPTION( mc.at( "a" ) == 1 );
  ASSERT_TRUE_AND_NO_EXCEPTION( mc.at( "b" ) == 2 );
  ASSERT_EXCEPTION( mc.at( "c" ), out_of_range );
}

static void test_basics() {
  map_type m;

  ASSERT_TRUE( m.empty() );
  ASSERT_TRUE( m.size() == 0 );

  m[ "a" ] = 1;
  m[ "b" ] = 2;

  ASSERT_TRUE( !m.empty() );
  ASSERT_TRUE( m.size() == 2 );

  map_type m2( m );

  ASSERT_TRUE( !m2.empty() );
  ASSERT_TRUE( m2.size() == 2 );

  m2.clear();
  ASSERT_TRUE( m2.empty() );
  ASSERT_TRUE( m2.size() == 0 );

  // Ensure 'm' is unaffected by changes to 'm2'.
  ASSERT_TRUE( !m.empty() );
  ASSERT_TRUE( m.size() == 2 );
}

static void test_erase() {
  map_type m;
  map_type::iterator i;

  m[ "a" ] = 1;
  m[ "b" ] = 2;

  ASSERT_TRUE( m.erase( "a" ) == 1 );
  ASSERT_TRUE( m.erase( "a" ) == 0 );
  ASSERT_TRUE( !m.empty() );
  ASSERT_TRUE( m.size() == 1 );

  i = m.find( "b" );
  ASSERT_TRUE( m.erase( i ) == m.end() );
  ASSERT_TRUE( m.empty() );
  ASSERT_TRUE( m.size() == 0 );

  m[ "a" ] = 1;
  m[ "b" ] = 2;

  i = m.find( "a" );
  ASSERT_TRUE( m.erase( i )->first == "b" );
}

static void test_insert() {
  map_type m;
  insert_return_type ir;

  ir = m.insert( make_pair( "a", 1 ) );
  ASSERT_TRUE( ir.second == true );
  ASSERT_TRUE( ir.first->first == "a" );
  ASSERT_TRUE( ir.first->second == 1 );
  ASSERT_TRUE( !m.empty() );
  ASSERT_TRUE( m.size() == 1 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "a" ) == 1 );
  ASSERT_TRUE( m[ "a" ] == 1 );
  ASSERT_TRUE( m.count( "a" ) == 1 );
  ASSERT_TRUE( m.find( "a" )->first == "a" );
  ASSERT_TRUE( m.find( "a" )->second == 1 );
  ASSERT_TRUE( m.equal_range( "a" ).first->second == 1 );

  ir = m.insert( make_pair( "b", 2 ) );
  ASSERT_TRUE( ir.second == true );
  ASSERT_TRUE( ir.first->first == "b" );
  ASSERT_TRUE( ir.first->second == 2 );
  ASSERT_TRUE( !m.empty() );
  ASSERT_TRUE( m.size() == 2 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "b" ) == 2 );
  ASSERT_TRUE( m[ "b" ] == 2 );
  ASSERT_TRUE( m.count( "b" ) == 1 );
  ASSERT_TRUE( m.find( "b" )->first == "b" );
  ASSERT_TRUE( m.find( "b" )->second == 2 );
  ASSERT_TRUE( m.equal_range( "b" ).first->second == 2 );

  // Ensure "a" is still there.
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "a" ) == 1 );
  ASSERT_TRUE( m[ "a" ] == 1 );
  ASSERT_TRUE( m.count( "a" ) == 1 );
  ASSERT_TRUE( m.find( "a" )->first == "a" );
  ASSERT_TRUE( m.find( "a" )->second == 1 );
  ASSERT_TRUE( m.equal_range( "a" ).first->second == 1 );
}

static void test_local_iterator() {
  map_type m;

  char s[2];
  s[1] = '\0';
  for ( int i = 0; i < 26; ++i ) {
    *s = (char)('a' + i);
    m[ s ] = i + 1;
  }

  map_type::size_type b = m.bucket( "a" );
  ASSERT_TRUE( m.bucket_size( b ) > 0 );

  bool found_a = false;
  map_type::local_iterator i( m.begin( b ) );
  map_type::local_iterator const j( m.end( b ) );
  for ( ; i != j; ++i )
    if ( i->first == "a" ) {
      found_a = true;
      break;
    }
  ASSERT_TRUE( found_a );
}

static void test_rehash() {
  unordered_map<int,int> m;
  unordered_map<int,int>::size_type const initial_buckets = m.bucket_count();

  // Add elements until bucket_count() changes which implies a rehash was done.
  for ( int i = 0; m.bucket_count() == initial_buckets; ++i )
    m[ i ] = i;

  ASSERT_TRUE( m.bucket_count() > initial_buckets );

  // Ensure all the elements are still there.
  unordered_map<int,int>::size_type const size = m.size();
  for ( int i = 0; i < size; ++i )
    ASSERT_TRUE_AND_NO_EXCEPTION( m.at( i ) == i );
}

static void test_swap() {
  map_type m;
  m[ "a" ] = 1;
  m[ "b" ] = 2;

  map_type m2;
  m2[ "c" ] = 3;
  m2[ "d" ] = 4;
  m2[ "e" ] = 5;

  m.swap( m2 );

  ASSERT_TRUE( m.size() == 3 );
  ASSERT_TRUE( m2.size() == 2 );

  ASSERT_EXCEPTION( m.at( "a" ), out_of_range );
  ASSERT_EXCEPTION( m.at( "b" ), out_of_range );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "c" ) == 3 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "d" ) == 4 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m.at( "e" ) == 5 );

  ASSERT_TRUE_AND_NO_EXCEPTION( m2.at( "a" ) == 1 );
  ASSERT_TRUE_AND_NO_EXCEPTION( m2.at( "b" ) == 2 );
  ASSERT_EXCEPTION( m2.at( "c" ), out_of_range );
  ASSERT_EXCEPTION( m2.at( "d" ), out_of_range );
  ASSERT_EXCEPTION( m2.at( "e" ), out_of_range );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_unordered_map( int, char*[] ) {
  test_basics();
  test_at();
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
