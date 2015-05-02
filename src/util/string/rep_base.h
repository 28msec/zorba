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

#ifndef ZORBA_RSTRING_REP_BASE_H
#define ZORBA_RSTRING_REP_BASE_H

#include <zorba/config.h>

#ifdef _MSC_VER
#pragma warning( disable : 4996 )
#endif

#include <memory>                       /* for allocator */
#include <string>                       /* for char_traits */

#include "util/atomic_int.h"

namespace zorba {
namespace rstring_classes {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %empty_rep_base contains storage for the empty string representation
 * shared by all derived string representation classes.
 */
class ZORBA_DLL_PUBLIC empty_rep_base {
protected:

  /**
   * A %rep_model models the data contained in all known derived string
   * representation classes so that the size of the empty string representation
   * is as large as the largest derived class.
   */
  struct rep_model {
    struct rep_base_model : atomic_int {
      size_t    cap_;
      size_t    len_;
    } rep_base;
    union derived_reps_model {
      struct rep_model {
        wchar_t data_[1];
      } rep;
      struct ptr_rep_model {
        char*   p_;
        bool    dispose_data_using_delete_;
      } ptr_rep;
    } derived_reps;
  };

  empty_rep_base() {
    // This is defined to prevent naked instance creation.
  }

  /**
   * Gets a pointer to the shared empty string representation.
   *
   * @return Returns said string representation.
   */
  static void* empty_rep() {
    return static_cast<void*>( empty_rep_storage_ );
  }

private:
  static char empty_rep_storage_[];
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %rep_base is the base class for all string representations.
 *
 * The reference-count has 3 states:
 * -1 : "unsharable": 1 reference, no ref-copies allowed, non-const.
 *  0 : one reference, non-const.
 * c>0: c + 1 references, const.
 *
 * @tparam RefCountType The reference-count class to use.
 * @tparam TraitsType   The character traits class to use.
 * @tparam Allocator    The allocator class to use.
 */
template<
  class RefCountType,
  class TraitsType = std::char_traits<char>,
  class Allocator = std::allocator<typename TraitsType::char_type>
>
class rep_base :
  protected empty_rep_base,
  // Use empty base class optimization: http://www.cantrip.org/emptyopt.html
  protected RefCountType {
public:
  typedef TraitsType traits_type;
  typedef typename traits_type::char_type value_type;
private:
  typedef typename Allocator::template rebind<value_type>::other char_allocator;
public:
  typedef Allocator allocator_type;
  typedef typename char_allocator::difference_type difference_type;
  typedef typename char_allocator::size_type size_type;

  typedef typename char_allocator::pointer pointer;
  typedef typename char_allocator::const_pointer const_pointer;
  typedef typename char_allocator::reference reference;
  typedef typename char_allocator::const_reference const_reference;

  typedef RefCountType ref_count_type;
  typedef typename RefCountType::value_type count_type;

  /**
   * Indicates whether construction or assignment from a non-const char* makes
   * the string take ownership of the char*.
   */
  enum { takes_pointer_ownership = false };

  ////////// capacity & length functions //////////////////////////////////////

  /**
   * Gets the capacity of this rep.
   *
   * @return Returns said capacity.
   */
  size_type capacity() const {
    return cap_;
  }

  /**
   * Sets the capacity of this rep.
   *
   * @param cap The new capacity.
   */
  void set_capacity( size_type cap ) {
    cap_ = cap;
  }

  /**
   * Gets the number of characters in this rep.
   *
   * @return Returns said number.
   */
  size_type length() const {
    return len_;
  }

  /**
   * Sets the number of characters in this rep.
   *
   * @param n The number of characters.
   */
  void set_length( size_type n ) {
    len_ = n;
  }

  ////////// reference-count functions ////////////////////////////////////////

  count_type count() const {
    return this->load();
  }

  /**
   * Increments the reference-count by 1.
   *
   * @return Returns the new reference-count.
   */
  count_type inc() {
    return this->operator++();
  }

  /**
   * Decrements the reference-count by 1.
   *
   * @return Returns the new reference-count.
   */
  count_type dec() {
    return this->operator--();
  }

  /**
   * Checks whether this representation is shared.
   *
   * @return Returns \c true only if it is.
   */
  bool is_shared() {
    return this->load() > 0;
  }

  /**
   * Checks if the given shared-count indicates whether some string's
   * representation is shared.
   *
   * @param count The shared-count to check.
   * @return Returns \c true only if it is.
   */
  static bool is_shared( count_type count ) {
    return count > 0;
  }

  /**
   * Checks whether this representation is sharable.
   *
   * @return Returns \c true only if it is.
   */
  bool is_sharable() {
    return this->load() >= 0;
  }

  /**
   * Checks if the given shared-count indicates whether some string's
   * representation is sharable.
   *
   * @param count The shared-count to check.
   * @return Returns \c true only if it is.
   */
  static bool is_sharable( count_type count ) {
    return count >= 0;
  }

  /**
   * Marks this representation as sharable.
   */
  void set_sharable() {
    this->store( 0 );
  }

  /**
   * Marks this representation as unsharable.
   */
  void set_unsharable() {
    this->store( -1 );
  }

  ////////// utility functions ////////////////////////////////////////////////

  /**
   * Assigns \a n copies of \a c to the range [to,to+n).
   *
   * @param to The start of the destination.
   * @param n The number of characters to assign.
   * @param c The character to assign.
   */
  static void assign( pointer to, size_type n, value_type c ) {
    if ( n == 1 )
      traits_type::assign( *to, c );
    else
      traits_type::assign( to, n, c );
  }

  /**
   * Copies characters from the range [from,from+n) to the (non-overlapping)
   * range [to,to+n).
   *
   * @param to The start of the destination.
   * @param from The start of the source.
   * @param n The number of characters to copy.
   */
  static void copy( pointer to, const_pointer from, size_type n ) {
    if ( n == 1 )
      traits_type::assign( *to, *from );
    else
      traits_type::copy( to, from, n );
  }

  /**
   * Copies characters from the range [from,from+n) to the (possibly
   * overlapping) range [to,to+n).
   *
   * @param to The start of the destination.
   * @param from The start of the source.
   * @param n The number of characters to copy.
   */
  static void move( pointer to, const_pointer from, size_type n ) {
    if ( n == 1 )
      traits_type::assign( *to, *from );
    else
      traits_type::move( to, from, n );
  }

protected:
  typedef typename Allocator::template rebind<char>::other raw_allocator;

  /**
   * Constructs a %rep_base.
   *
   * @param cap The capacity.
   */
  rep_base( size_type cap ) : cap_( cap ) {
    set_sharable();
  }

  /**
   * Destructs a %rep_base.  Declaring this \c protected ensures that a
   * derived class object can not be deleted via a %rep_base pointer.  The
   * destructor is not declared \c virtual since (a) deleting via a %rep_base
   * pointer should never need to be done anyway and (b) we don't want the
   * added space of the vtbl pointer.
   */
  ~rep_base() {
  }

  size_type cap_;
  size_type len_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace rstring_classes
} // namespace zorba

#ifdef _MSC_VER
#pragma warning( disable : 4996 )
#endif

#endif /* ZORBA_RSTRING_REP_BASE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
