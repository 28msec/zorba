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

#ifndef ZORBA_HASHTABLE_REHASH_POLICY_H
#define ZORBA_HASHTABLE_REHASH_POLICY_H

// standard
#include <sys/types.h>

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

/**
 * Provides a rehashing policy for hash tables that always uses prime numbers
 * for the number of buckets.
 */
class prime_rehash_policy {
public:
  typedef std::size_t size_type;

  enum {
    /**
     * The default number of buckets to create.
     */
    default_bucket_count = 11           // a prime number
  };

  /**
   * Constructs a %prime_rehash_policy.
   *
   * @param max_load_factor The maximum load factor.
   */
  prime_rehash_policy( float max_load_factor = 0.8F );

  /**
   * Gets an adjusted bucket count for the given proposed number of buckets.
   *
   * @param n_bkt The proposed number of buckets.
   * @return Returns a bucket count adjusted so as to be more optimal.
   */
  size_type adjust_buckets( size_type n_bkt ) const;

  /**
   * Calculates the number of buckets needed for the given number of elements
   * under the maximum load factor.
   *
   * @param n_elt The number of elements.
   * @return Returns said number of buckets.
   */
  size_type buckets_for_elements( size_type n_elt ) const;

  /**
   * Gets the maximum load factor.
   *
   * @return Returns said load factor.
   */
  float max_load_factor() const;

  /**
   * Determines whether a rehash ought to be done.
   *
   * @param n_bkt The current number of buckets.
   * @param n_elt The current number of elements.
   * @param n_ins The number of elements to be inserted.
   * @return Returns a value &gt; 0 (where the value is the new bucket count)
   * if a rehash ought to be done; returns 0 if not.
   */
  size_type need_rehash( size_type n_bkt, size_type n_elt,
                         size_type n_ins ) const;

private:
  float growth_factor_;
  float max_load_factor_;
  mutable size_type next_resize_;
};

///////////////////////////////////////////////////////////////////////////////

inline prime_rehash_policy::size_type
prime_rehash_policy::buckets_for_elements( size_type n_elt ) const {
  return adjust_buckets( n_elt / max_load_factor_ );
}

inline float prime_rehash_policy::max_load_factor() const {
  return max_load_factor_;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace std

#endif  /* ZORBA_HASHTABLE_REHASH_POLICY_H */
/* vim:set et ts=2 sw=2: */
