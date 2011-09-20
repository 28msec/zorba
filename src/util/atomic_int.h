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
#pragma once
#ifndef ATOMIC_INT_H
#define ATOMIC_INT_H

#if defined( sun ) || defined( __sun )
# if defined( __SVR4 ) || defined( __svr4__ )
#   define __SOLARIS__ 1
# endif
#endif

//
// Test first for and prefer gcc's atomic operations over all others since
// they're an order of magnitude faster.
//
#if defined( __GNUC__ )
# if __GNUC__ * 100 + __GNUC_MINOR__ >= 402
#   include <ext/atomicity.h>
# else
#   include <bits/atomicity.h>
# endif
# if __GNUC__ * 100 + __GNUC_MINOR__ >= 420
#   define GNU_EXCHANGE_AND_ADD __gnu_cxx::__exchange_and_add_dispatch
# else
#   define GNU_EXCHANGE_AND_ADD __gnu_cxx::__exchange_and_add
# endif
#elif defined( __APPLE__ )
# include <libkern/OSAtomic.h>
#elif defined( __FreeBSD__ )
# include <sys/types.h>
# include <machine/atomic.h>
#elif defined( __NetBSD__ )
# include <sys/atomic.h>
#elif defined( __SOLARIS__ )
# include <atomic.h>
#elif defined( _WIN32 )
# include <windows.h>
# include <intrin.h>                    /* for _ReadBarrier() */
# pragma intrinsic(_ReadBarrier)
#else
# error "Unsupported operating system for atomic operations"
#endif

namespace zorba {

/**
 * An %atomic_int behaves like an ordinary \c int except that all modifications
 * and accesses are guaranteed to be thread-safe.
 *
 * The API is a subset of the forthcoming C++ standard addition of atomic types;
 * see: http://www.open-std.org/JTC1/sc22/wg21/docs/papers/2007/n2427.html
 */
class atomic_int {
public:
#if defined( __GNUC__ )
  typedef _Atomic_word value_type;
#elif defined( __APPLE__ ) || defined( __NetBSD__ ) || defined( __SOLARIS__ )
  typedef int32_t value_type;
#elif defined( __FreeBSD__ )
  typedef int value_type;
#elif defined( _WIN32 )
  typedef LONG value_type;
#endif

  /**
   * Constructs an %atomic_int.
   *
   * @param n The initial value.
   */
  explicit atomic_int( value_type n = 0 ) : value_( n ) {
  }

  /**
   * Atomically assigns a new value.
   *
   * @param n The new value.
   * @return Returns a reference to <code>this</code>.
   */
  atomic_int& operator=( value_type n ) {
    store_impl( n );
    return *this;
  }

  /**
   * Atomically reads the current value.
   *
   * @return Returns the current value.
   */
  value_type load() const {
    return load_impl();
  }

  /**
   * Atomically writes a new value.
   *
   * @param n The new value.
   */
  void store( value_type n ) {
    store_impl( n );
  }

  /**
   * Atomically pre-increments the value.
   *
   * @return Returns the new value.
   */
  value_type operator++() {
    return pre_inc();
  }

  /**
   * Atomically post-increments the value.
   *
   * @return Returns the old value.
   */
  value_type operator++(int) {
    return post_inc();
  }

  /**
   * Atomically pre-decrements the value.
   *
   * @return Returns the new value.
   */
  value_type operator--() {
    return pre_dec();
  }

  /**
   * Atomically post-decrements the value.
   *
   * @return Returns the old value.
   */
  value_type operator--(int) {
    return post_dec();
  }

  /**
   * Atomically adds a value.
   *
   * @return Returns the new value.
   */
  value_type operator+=( value_type n ) {
    return add( n );
  }

  /**
   * Atomically subtracts a value.
   *
   * @return Returns the new value.
   */
  value_type operator-=( value_type n ) {
    return add( -n );
  }

private:
  value_type value_;

  value_type load_impl() const {
#if defined( __FreeBSD__ )
    return atomic_load_acq_int( &value_ );
#else
    value_type const temp = *(value_type volatile*)&value_;
# if defined( __GNUC__ )
    _GLIBCXX_READ_MEM_BARRIER;
# elif defined( __APPLE__ )
    OSMemoryBarrier();
# elif defined( __NetBSD__ ) || defined( __SOLARIS__ )
    membar_consumer();
# elif defined( _WIN32 )
    _ReadBarrier();
# elif defined( __INTEL_COMPILER )
    __memory_barrier();
# endif
    return temp;
#endif
  }

  void store_impl( value_type n ) {
#if defined( __FreeBSD__ )
    atomic_store_rel_int( &value_, n );
#elif defined( _WIN32 )
    InterlockedExchange( &value_, n );
#else
# if defined( __GNUC__ )
    _GLIBCXX_WRITE_MEM_BARRIER;
# elif defined( __APPLE__ )
    OSMemoryBarrier();
# elif defined( __NetBSD__ ) || defined( __SOLARIS__ )
    membar_producer();
# elif defined( __INTEL_COMPILER )
    __memory_barrier();
# endif
    *(value_type volatile*)&value_ = n;
#endif
  }

  value_type add( value_type n ) {
#if defined( __GNUC__ )
    return GNU_EXCHANGE_AND_ADD( &value_, n ) + n;
#elif defined( __APPLE__ )
    return OSAtomicAdd32( n, &value_ );
#elif defined( __FreeBSD__ )
    return atomic_fetchadd_int( &value_, n ) + n;
#elif defined( __NetBSD__ )
    return (value_type)atomic_add_32_nv( (uint32_t*)&value_, n );
#elif defined( __SOLARIS__ )
    return atomic_add_32_nv( (uint32_t*)&value_, n );
#elif defined( _WIN32 )
    return InterlockedExchangeAdd( &value_, n ) + n;
#endif
  }

  value_type pre_dec() {
#if defined( __GNUC__ )
    return GNU_EXCHANGE_AND_ADD( &value_, -1 ) - 1;
#elif defined( __APPLE__ )
    return OSAtomicDecrement32( &value_ );
#elif defined( __FreeBSD__ )
    return atomic_fetchadd_int( &value_, -1 ) - 1;
#elif defined( __NetBSD__ )
    return (value_type)atomic_add_int_nv( (uint32_t*)&value_, -1 );
#elif defined( __SOLARIS__ )
    return atomic_add_int_nv( (uint32_t*)&value_, -1 );
#elif defined( _WIN32 )
    return InterlockedDecrement( &value_ );
#endif
  }

  value_type pre_inc() {
#if defined( __GNUC__ )
    return GNU_EXCHANGE_AND_ADD( &value_, 1 ) + 1;
#elif defined( __APPLE__ )
    return OSAtomicIncrement32( &value_ );
#elif defined( __FreeBSD__ )
    return atomic_fetchadd_int( &value_, 1 ) + 1;
#elif defined( __NetBSD__ )
    return (value_type)atomic_add_int_nv( (uint32_t*)&value_, 1 );
#elif defined( __SOLARIS__ )
    return atomic_add_32_nv( &value_, 1 );
#elif defined( _WIN32 )
    return InterlockedIncrement( &value_ );
#endif
  }

  value_type post_dec() {
#if defined( __GNUC__ )
    return GNU_EXCHANGE_AND_ADD( &value_, -1 );
#elif defined( __APPLE__ )
    return OSAtomicDecrement32( &value_ ) + 1;
#elif defined( __FreeBSD__ )
    return atomic_fetchadd_int( &value_, -1 );
#elif defined( __NetBSD__ )
    return (value_type)atomic_add_int_nv( (uint32_t*)&value_, -1 ) + 1;
#elif defined( __SOLARIS__ )
    return atomic_add_int_nv( &value_, -1 ) + 1;
#elif defined( _WIN32 )
    return InterlockedExchangeAdd( &value_, -1 );
#endif
  }

  value_type post_inc() {
#if defined( __GNUC__ )
    return GNU_EXCHANGE_AND_ADD( &value_, 1 );
#elif defined( __APPLE__ )
    return OSAtomicIncrement32( &value_ ) - 1;
#elif defined( __FreeBSD__ )
    return atomic_fetchadd_int( &value_, 1 );
#elif defined( __NetBSD__ )
    return (value_type)atomic_add_int_nv( (uint32_t*)&value_, 1 ) - 1;
#elif defined( __SOLARIS__ )
    return atomic_add_32_nv( &value_, 1 ) - 1;
#elif defined( _WIN32 )
    return InterlockedExchangeAdd( &value_, 1 );
#endif
  }

  // forbid because they can't be done atomically
  atomic_int( atomic_int const& );
  atomic_int& operator=( atomic_int& );
};

} // namespace zorba

#endif /* ATOMIC_INT_H */
/* vim:set et sw=2 ts=2: */
