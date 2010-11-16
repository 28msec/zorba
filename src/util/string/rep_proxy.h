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

namespace zorba {
namespace rstring_classes {

/**
 * A proxy for either the default rep or the ptr rep.
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
   *
   */
  rep_proxy() : rep_( RepType::empty_rep() ) {
    // do nothing
  }

  /**
   *
   */
  ~rep_proxy() {
    assert( rep_ == RepType::empty_rep() );
  }

  /**
   *
   */
  size_type capacity() const {
    return rep_->capacity(); 
  }

  /**
   *
   */
  void construct( size_type size, value_type c, allocator_type const &a ) {
    assert( rep_ == RepType::empty_rep() );
    rep_ = RepType::construct( size, c, a );
  }

  /**
   *
   */
  template<class IteratorType>
  void construct( IteratorType begin, IteratorType end,
                  allocator_type const &a ) {
    assert( rep_ == RepType::empty_rep() );
    rep_ = RepType::construct( begin, end, a );
  }

  /**
   *
   */
  pointer data() const {
    return rep_->data();
  }

  /**
   *
   */
  void dispose( allocator_type const &a ) {
    if ( rep_ && rep_ != RepType::empty_rep() )
      rep_->dispose( a );
    rep_ = RepType::empty_rep();
  }

  /**
   * Delegate to
   */
  bool is_sharable() {
    return rep_->is_sharable();
  }

  /**
   *
   */
  bool is_shared() const {
    return rep_->is_shared();
  }

  /**
   *
   */
  size_type length() const {
    return rep_->length();
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
          rep_ = new_rep;
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
    rep_ = RepType::alloc( a, cap, old_cap );
    rep_->set_length( 0 );
  }

  /**
   *
   */
  void reserve( size_type cap, allocator_type const &a ) {
    rep_ = rep_->reserve( cap, a );
  }

  /**
   *
   */
  void set_length( size_type n ) {
    rep_->set_length( n );
  }

  /**
   *
   */
  void set_sharable() {
    rep_->set_sharable();
  }

  /**
   *
   */
  void set_unsharable() {
    rep_->set_unsharable();
  }

  /**
   *
   */
  void share( rep_proxy const &that, allocator_type const &this_alloc,
              allocator_type const &that_alloc ) {
    dispose( this_alloc );
    if ( that.rep_->is_sharable() && this_alloc == that_alloc ) {
      if ( that.rep_ != RepType::empty_rep() )
        that.rep_->inc();
      rep_ = that.rep_;
    } else {
      rep_ = that.rep_->clone( this_alloc );
    }
  }

  /**
   *
   */
  void swap( rep_proxy &that ) {
    RepType *const tmp = rep_;
    rep_ = that.rep_;
    that.rep_ = tmp;
  }

  /**
   *
   */
  void take( rep_proxy &that, allocator_type const &this_alloc,
             allocator_type const &that_alloc ) {
    dispose( this_alloc );
    if ( this_alloc == that_alloc ) {
      rep_ = that.rep_;
      that.rep_ = RepType::empty_rep();
    } else {
      rep_ = that.rep_->clone( this_alloc );
    }
  }

  /**
   *
   */
  bool operator==( rep_proxy const &j ) {
    return rep_ == j.rep_;
  }

  /**
   *
   */
  bool operator!=( rep_proxy const &j ) {
    return !(*this == j);
  }

private:
  RepType *rep_;

  // disabled
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
