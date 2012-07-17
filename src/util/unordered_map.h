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
#ifndef ZORBA_UNORDERED_MAP_H
#define ZORBA_UNORDERED_MAP_H

#include <zorba/config.h>

#ifdef ZORBA_HAVE_UNORDERED_MAP
# include <unordered_map>               /* use the implementation version */
#else

// standard
#include <utility>                      /* for pair */

// local
#include "util/hash/hash.h"
#include "util/hash/hashtable.h"
#include "util/hash/rehash_policy.h"
#ifndef ZORBA_UNORDERED_MAP_REHASH_POLICY
# define ZORBA_UNORDERED_MAP_REHASH_POLICY zorba::ztd::prime_rehash_policy
#endif /* ZORBA_UNORDERED_MAP_REHASH_POLICY */
#include "cxx_util.h"
#include "stl_util.h"

namespace std {

///////////////////////////////////////////////////////////////////////////////

/**
 * This is an implementation of the C++ %unordered_map class, but for C++98.
 * As such, it lacks member functions that use r-value references.
 *
 * @tparam KeyType They map's key type.
 * @tparam ValueType The type the keys are mapped to.
 * @tparam KeyHash The unary_function to use for generating hash codes.
 * @tparam KeyEqual The binary_function to use to test for key equality.
 * @tparam Allocator The allocator to use.
 */
template<
  typename KeyType,
  typename ValueType,
  class KeyHash = std::hash<KeyType>,
  class KeyEqual = std::equal_to<KeyType>,
  class Allocator = std::allocator< std::pair<KeyType const,ValueType> >
>
class unordered_map :
  public zorba::ztd::hashtable<
    KeyType, std::pair<KeyType const,ValueType>,
    zorba::ztd::select1st<std::pair<KeyType const,ValueType> >,
    KeyHash, KeyEqual, Allocator, ZORBA_UNORDERED_MAP_REHASH_POLICY
  >
{
  typedef zorba::ztd::hashtable<
    KeyType, std::pair<KeyType const,ValueType>,
    zorba::ztd::select1st<std::pair<KeyType const,ValueType> >,
    KeyHash, KeyEqual, Allocator, ZORBA_UNORDERED_MAP_REHASH_POLICY
  > base_type;

  typedef typename base_type::rehash_policy_type rehash_policy_type;
public:
  typedef typename base_type::key_type key_type;
  typedef typename base_type::value_type value_type;
  typedef typename base_type::hasher hasher;
  typedef typename base_type::key_equal key_equal;
  typedef typename base_type::allocator_type allocator_type;

  typedef typename base_type::pointer pointer;
  typedef typename base_type::const_pointer const_pointer;
  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;

  typedef typename base_type::size_type size_type;
  typedef typename base_type::difference_type difference_type;

  typedef typename base_type::local_iterator local_iterator;
  typedef typename base_type::const_local_iterator const_local_iterator;
  typedef typename base_type::iterator iterator;
  typedef typename base_type::const_iterator const_iterator;

  /**
   * Constructs an %unordered_map.
   *
   * @param bucket_count The initial number of buckets.
   * @param hash The unary_function to use for generating hash codes.
   * @param equal The binary_function to use to test for key equality.
   * @param alloc The allocator to use.
   */
  explicit unordered_map(
    size_type bucket_count = rehash_policy_type::default_bucket_count,
    hasher const &hash = hasher(),
    key_equal const &equal = key_equal(),
    allocator_type const &alloc = allocator_type()
  ) :
    base_type( bucket_count, hash, equal, alloc )
  {
  }

  /**
   * Constructs an %unordered_map.
   *
   * @param alloc The allocator to use.
   */
  explicit unordered_map( allocator_type const &alloc ) : base_type( alloc ) {
  }

  /**
   * Copy-constructs an %unordered_map.
   *
   * @param that The %unordered_map to copy from.
   */
  unordered_map( unordered_map const &that ) : base_type( that ) {
  }

  /**
   * Assignment.
   *
   * @param that The %unordered_map to assign from.
   */
  unordered_map& operator=( unordered_map const &that ) {
    base_type::operator=( that );
    return *this;
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Global %swap operator for unordered_map.
 *
 * @param a The first unordered_map.
 * @param b The second unordered_map.
 */
template<typename K,typename M,class H,class E,class A> inline
void swap( unordered_map<K,M,H,E,A> &a, unordered_map<K,M,H,E,A> &b ) {
  a.swap( b );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace std

#endif /* ZORBA_HAVE_UNORDERED_MAP */
#endif /* ZORBA_UNORDERED_MAP_H */
/* vim:set et ts=2 sw=2: */
