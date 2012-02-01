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
#include <iomanip>

#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>

using namespace std;
using namespace zorba::internal;

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

///////////////////////////////////////////////////////////////////////////////

template<class C>
struct instances {
  static int count;
  instances()  { ++count; }
  ~instances() { --count; }
};

template<class C> int instances<C>::count = 0;

#define COUNT(C) instances<C>::count

struct A : instances<A> {
  virtual ~A() { }
};

struct B : A, instances<B> {
};

struct D {
  D( int *p = 0 ) : destroy_count( p ) { }

  void destroy() {
    if ( destroy_count )
      ++*destroy_count;
    delete this;
  }

  int *const destroy_count;
};

////////// Compile-time-only tests ////////////////////////////////////////////

static unique_ptr<A> f_A( unique_ptr<A> p ) {
  return unique_ptr<A>();
}

#if 0
static unique_ptr<B> f_B( unique_ptr<A> p ) {
  return unique_ptr<B>();
}
#endif

static void compile_test() {
  unique_ptr<A> a1;
  unique_ptr<A> a2( f_A( move( a1 ) ) );
  unique_ptr<B> b1;
#if 0
  unique_ptr<A> a3( f_B( move( b1 ) ) );
#endif
}

////////// Run-time tests /////////////////////////////////////////////////////

static void test_array() {
  {
    unique_ptr<A[]> a( new A[2] );
    ASSERT_TRUE( COUNT(A) == 2 );
  }
  ASSERT_TRUE( COUNT(A) == 0 );
}

static void test_basic() {
  {
    unique_ptr<A> a( new A );
    ASSERT_TRUE( COUNT(A) == 1 );
  }
  ASSERT_TRUE( COUNT(A) == 0 );
}

static void test_assignment() {
  unique_ptr<A> a1( new A );
  unique_ptr<A> a2;
  a2 = move( a1 );
  ASSERT_TRUE( COUNT(A) == 1 );
  ASSERT_TRUE( !a1 );
  ASSERT_TRUE( a2 );
}

static void test_copy_constructor() {
  unique_ptr<A> a1( new A );
  ASSERT_TRUE( COUNT(A) == 1 );
  unique_ptr<A> a2( move( a1 ) );
  ASSERT_TRUE( COUNT(A) == 1 );
  ASSERT_TRUE( !a1 );
  ASSERT_TRUE( a2 );
}

static void test_deleter_reference() {
  int destroy_count = 0;
  {
    ztd::destroy_delete<D> dd;
    unique_ptr<D,ztd::destroy_delete<D>&> d1( new D( &destroy_count ), dd );
    unique_ptr<D,ztd::destroy_delete<D>&> d2( new D( &destroy_count ), dd );
    ASSERT_TRUE( &d1.get_deleter() == &d2.get_deleter() );
  }
  ASSERT_TRUE( destroy_count == 2 );
}

static void test_derived() {
  {
    unique_ptr<A> a1( new B );
    ASSERT_TRUE( COUNT(A) == 1 );
    ASSERT_TRUE( COUNT(B) == 1 );
  }
  ASSERT_TRUE( COUNT(A) == 0 );
  ASSERT_TRUE( COUNT(B) == 0 );
  {
    unique_ptr<A> a1( new A );
    unique_ptr<B> b1( new B );
    ASSERT_TRUE( COUNT(A) == 2 );
    ASSERT_TRUE( COUNT(B) == 1 );
    a1 = move( b1 );
    ASSERT_TRUE( COUNT(A) == 1 );
    ASSERT_TRUE( COUNT(B) == 1 );
    ASSERT_TRUE( !b1 );
    ASSERT_TRUE( a1 );
  }
}

template<typename T>
void f( unique_ptr<T> p ) {
  ASSERT_TRUE( p );
  ASSERT_TRUE( COUNT(A) == 1 );
}

static void test_function_arg() {
  unique_ptr<A> a1( new A );
  ASSERT_TRUE( COUNT(A) == 1 );
  f( move( a1 ) );
  ASSERT_TRUE( COUNT(A) == 0 );
  ASSERT_TRUE( !a1 );
}

static void test_null_assignment() {
  unique_ptr<A> a1( new A );
  ASSERT_TRUE( COUNT(A) == 1 );
  a1 = 0;
  ASSERT_TRUE( COUNT(A) == 0 );
  ASSERT_TRUE( !a1 );
}

static void test_release() {
  A *p = 0;
  {
    unique_ptr<A> a1( new A );
    ASSERT_TRUE( COUNT(A) == 1 );
    p = a1.release();
    ASSERT_TRUE( COUNT(A) == 1 );
    ASSERT_TRUE( !a1 );
    ASSERT_TRUE( p );
  }
  ASSERT_TRUE( COUNT(A) == 1 );
  delete p;
  ASSERT_TRUE( COUNT(A) == 0 );
}

static void test_sizeof() {
  unique_ptr<A> a1;
  ASSERT_TRUE( sizeof( a1 ) == sizeof( void* ) );
  unique_ptr<D,ztd::destroy_delete<D> > d1;
  ASSERT_TRUE( sizeof( d1 ) == sizeof( void* ) );
}

static void test_swap() {
  A *p1 = new A;
  A *p2 = new A;
  unique_ptr<A> a1( p1 );
  unique_ptr<A> a2( p2 );
  ASSERT_TRUE( a1.get() == p1 );
  ASSERT_TRUE( a2.get() == p2 );
  a1.swap( a2 );
  ASSERT_TRUE( COUNT(A) == 2 );
  ASSERT_TRUE( a1.get() == p2 );
  ASSERT_TRUE( a2.get() == p1 );
  swap( a1, a2 );
  ASSERT_TRUE( COUNT(A) == 2 );
  ASSERT_TRUE( a1.get() == p1 );
  ASSERT_TRUE( a2.get() == p2 );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_unique_ptr( int, char*[] ) {
  compile_test();
  test_array();
  test_basic();
  test_assignment();
  test_copy_constructor();
  test_deleter_reference();
  test_derived();
  test_function_arg();
  test_null_assignment();
  test_release();
  test_sizeof();
  test_swap();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
