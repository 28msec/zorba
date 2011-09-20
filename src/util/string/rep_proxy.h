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

#ifndef ZORBA_RSTRING_REP_PROXY_H
#define ZORBA_RSTRING_REP_PROXY_H

#include <cassert>

#include <zorba/config.h>

#include "util/cxx_util.h"

namespace zorba {
namespace rstring_classes {

/**
 * A proxy for either default_rep or ptr_rep.
 */
template<class RepType>
class rep_proxy {
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

  enum { takes_pointer_ownership = RepType::takes_pointer_ownership };

  /**
   * Constructs a %rep_proxy.
   */
  rep_proxy() {
    set_rep( RepType::empty_rep() );
  }

  /**
   * Destroys a %rep_proxy.
   */
  ~rep_proxy() {
    assert( rep_ == RepType::empty_rep() );
  }

  /**
   * Disposes of this %rep_proxy and its associated string representation.
   *
   * @param a The allocator that was used to allocate the string
   * representation.
   */
  void dispose( allocator_type const &a ) {
    if ( rep_ )
      rep_->dispose( a );
    set_rep( RepType::empty_rep() );
  }

  /**
   * Makes the representation unsharable if necessary.  If it is currently
   * shared, it must be cloned.
   */
  void make_unsharable_if_necessary( allocator_type const &a ) {
    if ( rep_ != RepType::empty_rep() ) {
      typename RepType::count_type const count = rep_->count();
      if ( RepType::is_sharable( count ) ) {
        if ( RepType::is_shared( count ) ) {
          RepType *const new_rep = rep_->clone( a );
          rep_->dispose( a );
          set_rep( new_rep );
        }
        rep_->set_unsharable();
      }
    }
  }

  /**
   * This method is used only in the mutate method of rstring, when
   * copy-on-write is necessary. It creates a representation with zero length
   * and capacity >= to the given capacity. The actual capacity is computed
   * internally, taking into account the given "old" capacity.
   */
  void realloc( size_type cap, size_type old_cap, allocator_type const &a ) {
    assert( rep_ == RepType::empty_rep() );
    set_rep( RepType::alloc( a, cap, old_cap ) );
    rep_->set_length( 0 );
  }

  /**
   * Shares 2 string representations.
   *
   * @param that The %rep_proxy of the representation to share.
   * @param this_alloc This allocator.
   * @param that_alloc The allocator used by \a that.
   */
  void share( rep_proxy const &that, allocator_type const &this_alloc,
              allocator_type const &that_alloc ) {
    dispose( this_alloc );
    if ( that.rep_->is_sharable() && this_alloc == that_alloc ) {
      if ( that.rep_ != RepType::empty_rep() )
        that.rep_->inc();
      set_rep( that.rep_ );
    } else {
      set_rep( that.rep_->clone( this_alloc ) );
    }
  }

  /**
   * Swaps this string representation for another.
   *
   * @param that The %rep_proxy to swap with.
   */
  void swap( rep_proxy &that ) {
    RepType *const tmp = rep_;
    set_rep( that.rep_ );
    that.set_rep( tmp );
  }

  /**
   * Performs a destructive assignment.
   *
   * @param that The %rep_proxy to copy from.  It is set to the empty string.
   * @param this_alloc This allocator.
   * @param that_allor The allocator used by \a that.
   */
  void take( rep_proxy &that, allocator_type const &this_alloc,
             allocator_type const &that_alloc ) {
    if ( *this != that ) {
      dispose( this_alloc );
      if ( this_alloc == that_alloc ) {
        set_rep( that.rep_ );
        that.set_rep( RepType::empty_rep() );
      } else {
        set_rep( that.rep_->clone( this_alloc ) );
      }
    }
  }

  /**
   * Compares 2 %rep_proxy objects for equality.
   *
   * @param i The first %rep_proxy.
   * @param j The second %rep_proxy.
   * @return Returns \c true only if they're equal.
   */
  friend bool operator==( rep_proxy const &i, rep_proxy const &j ) {
    return i.rep_ == j.rep_;
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

  ////////// Delegate member functions ////////////////////////////////////////

  size_type capacity() const {
    return rep_->capacity(); 
  }

  void construct( size_type size, value_type c, allocator_type const &a ) {
    assert( rep_ == RepType::empty_rep() );
    set_rep( RepType::construct( size, c, a ) );
  }

  template<class IteratorType>
  void construct( IteratorType begin, IteratorType end,
                  allocator_type const &a ) {
    assert( rep_ == RepType::empty_rep() );
    set_rep( RepType::construct( begin, end, a ) );
  }

  pointer data() const {
    return rep_->data();
  }

  bool is_sharable() {
    return rep_->is_sharable();
  }

  bool is_shared() const {
    return rep_->is_shared();
  }

  size_type length() const {
    return rep_->length();
  }

  void reserve( size_type cap, allocator_type const &a ) {
    set_rep( rep_->reserve( cap, a ) );
  }

  void set_length( size_type n ) {
    rep_->set_length( n );
  }

  void set_sharable() {
    rep_->set_sharable();
  }

  void set_unsharable() {
    rep_->set_unsharable();
  }

  /////////////////////////////////////////////////////////////////////////////

private:
  RepType *rep_;

#ifdef ZORBA_DEBUG_STRING
  const_pointer debug_str_;
#endif /* ZORBA_DEBUG_STRING */

  void set_rep( RepType *r ) {
    rep_ = r;
#ifdef ZORBA_DEBUG_STRING
    debug_str_ = rep_ ? data() : nullptr;
#endif /* ZORBA_DEBUG_STRING */
  }

  // forbid these
  rep_proxy( rep_proxy const& );
  rep_proxy& operator=( rep_proxy const& );
};

} // rstring_classes
} // zorba

#endif /* ZORBA_RSTRING_REP_PROXY_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
