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

#ifndef ZORBA_RSTRING_BUF_REP_H
#define ZORBA_RSTRING_BUF_REP_H

#include <cassert>
#include <stdexcept>

#include <zorba/config.h>

#include "rep_base.h"
#include "rep_proxy.h"
#include "util/cxx_util.h"
#include "util/void_int.h"

namespace zorba {
namespace rstring_classes {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %buf_rep is used to overlay a string onto an existing, fixed-capacity
 * character buffer.
 *
 * @tparam ResultRepType The representation type to be used for results.  For
 * operations that create new strings, e.g., operator+(), %buf_rep can not be
 * used because there is no existing buffer.
 */
template<class ResultRepType>
class buf_rep : public rep_base<void_int,typename ResultRepType::traits_type> {
  typedef rep_base<void_int,typename ResultRepType::traits_type> base_type;
  typedef typename base_type::raw_allocator raw_allocator;
public:
  typedef typename base_type::allocator_type allocator_type;
  typedef typename base_type::difference_type difference_type;
  typedef typename base_type::size_type size_type;
  typedef typename base_type::traits_type traits_type;

  typedef typename base_type::value_type value_type;
  typedef typename base_type::pointer pointer;
  typedef typename base_type::const_pointer const_pointer;
  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;

  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  typedef typename base_type::ref_count_type ref_count_type;
  typedef ResultRepType result_rep_type;

  /**
   *
   */
  static void assign( pointer to, size_type n, value_type c ) {
    base_type::assign( to, n, c );
  }

  /**
   *
   */
  static void copy( pointer to, const_pointer from, size_type n ) {
    base_type::copy( to, from, n );
  }

  /**
   *
   */
  static void move( pointer to, const_pointer from, size_type n ) {
    base_type::move( to, from, n );
  }

  /**
   * Constructs a %buf_rep.
   */
  buf_rep() : base_type( 0 ), p_( nullptr ) {
    this->set_length( 0 );
  }

  /**
   * Destroys this %buf_rep.
   */
  ~buf_rep() {
#ifdef ZORBA_DEBUG_STRING
    assert( !p_ );
#endif /* ZORBA_DEBUG_STRING */
  }

  // BUF_REP_CONSTRUCT_2CP_A_X
  /**
   * Constructs a %buf_rep from pointers.
   *
   * @param begin The pointer marking the beginning of the memory range.
   * @param end The pointer marking one past the end of the memory range.
   * @param a Not used.
   */
  void construct( const_pointer begin, const_pointer end,
                  allocator_type const &a );

  /**
   * Gets the string data.
   *
   * @return Returns said data.
   */
  pointer data() const {
    return p_;
  }

  /**
   * Disposes this %buf_rep.
   *
   * @param a The allocator that was used to create this %buf_rep.
   */
  void dispose( allocator_type const &a ) {
#ifdef ZORBA_DEBUG_STRING
    p_ = nullptr;
    this->set_capacity( 0 );
    this->set_length( 0 );
#endif /* ZORBA_DEBUG_STRING */
  }

  /**
   * Gets the singleton %buf_rep for the empty string.
   *
   * @return Returns said %buf_rep.
   */
  static buf_rep* empty_rep() {
    return 0;
  }

  /**
   * Reserves a minimum capacity.
   *
   * @param cap The minimum capacity to reserve.
   * @param a The allocator to use.
   * @throws std::length_error if \a cap &gt; \c capacity() since a %buf_rep
   * can not grow in size.
   */
  void reserve( size_type cap, allocator_type const &a ) {
    if ( cap > this->capacity() )
      throw std::length_error( "reserve" );
  }

protected:
  pointer p_;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Partial template specialization for buf_rep that will implant it directly
 * inside of rstring.
 */
template<class ResultRepType>
class rep_proxy< buf_rep<ResultRepType> > : public buf_rep<ResultRepType> {
  typedef buf_rep<ResultRepType> RepType;
public:
  typedef typename RepType::allocator_type allocator_type;
  typedef typename RepType::difference_type difference_type;
  typedef typename RepType::size_type size_type;
  typedef typename RepType::traits_type traits_type;

  typedef typename RepType::value_type value_type;
  typedef typename RepType::pointer pointer;
  typedef typename RepType::const_pointer const_pointer;
  typedef typename RepType::reference reference;
  typedef typename RepType::const_reference const_reference;

  typedef typename RepType::iterator iterator;
  typedef typename RepType::const_iterator const_iterator;
  typedef typename RepType::reverse_iterator reverse_iterator;
  typedef typename RepType::const_reverse_iterator const_reverse_iterator;

  typedef rep_proxy<typename RepType::result_rep_type> result_rep_type;

  /**
   * Default constructor.
   */
  rep_proxy() { }

  /**
   * A %buf_rep can not be unshared, so this does nothing.
   */
  void make_unsharable_if_necessary( allocator_type const& ) {
    // do nothing
  }

  /**
   * A %buf_rep can not be reallocated.
   */
  void realloc( size_type, size_type, allocator_type const& ) {
    throw std::length_error( "realloc" );
  }

  /**
   * Shares 2 string representations.
   *
   * @param that The %rep_proxy of the representation to share.
   */
  void share( rep_proxy const &that, allocator_type const&,
              allocator_type const& ) {
    this->p_ = that.p_;
    this->set_capacity( that.capacity() );
    this->set_length( that.length() );
  }

  // REP_PROXY_BUF_REP_SWAP_X
  /**
   * Swaps this string representation for another.
   *
   * @param that The %rep_proxy to swap with.
   */
  void swap( rep_proxy &that );

  // REP_PROXY_BUF_REP_TAKE_X
  /**
   * Performs a destructive assignment.
   *
   * @param that The %rep_proxy to copy from.  It is set to the empty string.
   * @param this_alloc This allocator.
   * @param that_allor The allocator used by \a that.
   */
  void take( rep_proxy &that, allocator_type const &this_alloc,
             allocator_type const &that_alloc );

  /**
   * Compares 2 %rep_proxy objects for equality.
   *
   * @param i The first %rep_proxy.
   * @param j The second %rep_proxy.
   * @return Returns \c true only if they're equal.
   */
  friend bool operator==( rep_proxy const &i, rep_proxy const &j ) {
    return  i.data() == j.data() &&
            i.capacity() == j.capacity() &&
            i.length() == j.length();
  }

  /**
   * Compares 2 %rep_proxy objects for inequality.
   *
   * @param i The first %rep_proxy.
   * @param j The second %rep_proxy.
   * @return Returns \c true only if they're not equal.
   */
  friend bool operator!=( rep_proxy const &i, rep_proxy const &j ) {
    return !(i == j);
  }

private:
  // forbid these
  rep_proxy( rep_proxy const& );
  rep_proxy& operator=( rep_proxy const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace rstring_classes
} // namespace zorba

#include "buf_rep.tcc"

#endif /* ZORBA_RSTRING_BUF_REP_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
