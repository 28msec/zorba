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

#ifndef ZORBA_RSTRING_PTR_REP_H
#define ZORBA_RSTRING_PTR_REP_H

#include <iterator>

#include "util/cxx_util.h"
#include "rep_base.h"

namespace zorba {
namespace rstring_classes {

/**
 * A pointer string representation.  Unlike the default %rep, %ptr_rep contains
 * an additional pointer to the string data.  This increases the size of
 * %ptr_rep by the size of a pointer and doubles the number of allocations, but
 * the advantage is that it can be used to "wrap" or take ownership of an
 * existing pointer to a C string.
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
class ptr_rep : public rep_base<RefCountType,TraitsType,Allocator> {
  typedef rep_base<RefCountType,TraitsType,Allocator> base_type;
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
  typedef ptr_rep result_rep_type;

  /**
   * Indicates whether construction or assignment from a non-const char* makes
   * the string take ownership of the char*.
   */
  enum { takes_pointer_ownership = true };

  /////////////////////////////////////////////////////////////////////////////

  /**
   * Allocates a new %ptr_rep.
   *
   * @param a The allocator to use.
   * @param cap The string capacity.
   * @param old_cap The previous capacity, if any.
   */
  static ptr_rep* alloc( allocator_type const &a, size_type cap,
                         size_type old_cap = 0 ) {
    cap = calc_cap( cap, old_cap );
    ptr_rep *const r = alloc_rep_only( a, cap );
    r->p_ = alloc_data_only( a, cap );
    return r;
  }

  // PTR_REP_CLONE_A_ST_X
  /**
   * Clones this %ptr_rep.
   *
   * @param a The allocator to use.
   * @param add_capacity If > 0, creates a non-identical clone that has the
   * given added capacity.
   */
  ptr_rep* clone( allocator_type const &a, size_type add_capacity = 0 ) const;

  // PTR_REP_CONSTRUCT_P_ST_VT_A_X
  /**
   * Constructs a %ptr_rep.
   *
   * @param size The number of times to repeat the character.
   * @param c The character.
   * @param a The allocator to use.
   */
  static ptr_rep* construct( size_type size, value_type c,
                             allocator_type const &a );

  // PTR_REP_CONSTRUCT_2II_A_X
  /**
   * Constructs a %ptr_rep from either forward or input iterators.  This
   * function is a compile-time switch based on the iterator's tag.
   *
   * @tparam IteratorType The iterator type.
   * @param i The iterator marking the position of first character.
   * @param j The iterator marking the position of one past the last character.
   * @param a The allocator to use.
   */
  template<class IteratorType>
  static ptr_rep* construct( IteratorType i, IteratorType j,
                             allocator_type const &a ) {
    typedef typename std::iterator_traits<IteratorType>::iterator_category tag;
    return construct( i, j, a, tag() );
  }

  // PTR_REP_CONSTRUCT_2P_A_X
  /**
   * Constructs a %ptr_rep from a pointer range [p,q).  This version simply
   * "wraps around" the existing string -- no copy is made.
   *
   * @param p A pointer to the first character in the range.
   * @param q A pointer to one past the last character in the range.
   * @param a The allocator to use.
   */
  static ptr_rep* construct( pointer p, pointer q, allocator_type const &a );

  /**
   * Gets the string data.
   *
   * @return Returns said data.
   */
  pointer data() const {
    return p_;
  }

  /**
   * Disposes this %ptr_rep only if it's not being shared; otherwise decrements
   * the reference-count.
   *
   * @param a The allocator that was used to create this %ptr_rep.
   */
  void dispose( allocator_type const &a ) {
    if ( this != empty_rep() && this->dec() < 0 ) {
      allocator_type alloc = raw_allocator( a );
      dispose_data_only( alloc );
      alloc.deallocate( reinterpret_cast<char*>( this ), sizeof( ptr_rep ) );
    }
  }

  /**
   * Gets the singleton %ptr_rep for the empty string.
   *
   * @return Returns said %ptr_rep.
   */
  static ptr_rep* empty_rep() {
    static_assert(
      sizeof( ptr_rep ) <= sizeof( empty_rep_base::rep_model ),
      "storage for string representation is too small"
    );
    return reinterpret_cast<ptr_rep*>( empty_rep_base::empty_rep() );
  }

  // PTR_REP_RESERVE_ST_A_X
  /**
   * Sets a minimum capacity.
   *
   * @param cap The new capacity.
   * @param a The allocator to use.
   * @return Returns the possibly new %ptr_rep object.
   */
  ptr_rep* reserve( size_type cap, allocator_type const &a );

  /**
   * Sets the number of characters in this %ptr_rep.
   * Additionally ensures that the string is terminated by a NULL character.
   *
   * @param n The number of characters.
   */
  void set_length( size_type n ) {
    base_type::set_length( n );
    if ( data() )
      data()[ n ] = value_type( 0 );
  }

protected:
  /**
   * Constructs a %ptr_rep.
   *
   * @param cap The capacity.
   */
  ptr_rep( size_type cap = 0 ) :
    base_type( cap ), p_( nullptr ), dispose_data_using_delete_( false )
  {
  }

  /**
   * Allocates just new string data.
   *
   * @param a The allocator to use.
   * @param cap The string capacity.
   * @param old_cap The previous capacity, if any.
   */
  static pointer alloc_data_only( allocator_type const &a, size_type cap ) {
    return raw_allocator( a ).allocate( data_size( cap ) );
  }

  /**
   * Allocates just a new %ptr_rep without the string data.
   *
   * @param a The allocator to use.
   * @param cap The string capacity.
   */
  static ptr_rep* alloc_rep_only( allocator_type const &a, size_type cap ) {
    void *const place = raw_allocator( a ).allocate( sizeof( ptr_rep ) );
    return new( place ) ptr_rep( cap );
  }

  // PTR_REP_CALC_CAP_2ST_X
  /**
   * Calculates a good string capacity size.
   *
   * @param cap The string capacity.
   * @param old_cap The previous capacity.
   */
  static size_type calc_cap( size_type cap, size_type old_cap );

  /**
   * Clones the string data only.
   *
   * @param a The allocator to use.
   * @param cap The capacity for the clone.
   */
  pointer clone_data_only( allocator_type const &a, size_type cap ) const {
    pointer const p = alloc_data_only( a, cap );
    if ( size_type const len = this->length() )
      base_type::copy( p, data(), len );
    return p;
  }

  // PTR_REP_CONSTRUCT_2II_A_FIT_X
  /**
   * Constructs a %ptr_rep from forward iterators.
   *
   * @param i The iterator marking the position of first character.
   * @param j The iterator marking the position of one past the last character.
   * @param a The allocator to use.
   * @param tag The iterator tag.
   */
  template<class ForwardIterator>
  static ptr_rep* construct( ForwardIterator i, ForwardIterator j,
                             allocator_type const &a,
                             std::forward_iterator_tag tag );

  // PTR_REP_CONSTRUCT_2II_A_IIT_X
  /**
   * Constructs a %ptr_rep from input iterators.
   *
   * @param i The iterator marking the position of first character.
   * @param j The iterator marking the position of one past the last character.
   * @param a The allocator to use.
   * @param tag The iterator tag.
   */
  template<class InputIterator>
  static ptr_rep* construct( InputIterator i, InputIterator j,
                             allocator_type const &a,
                             std::input_iterator_tag tag );

  /**
   * Copies characters using iterators.
   *
   * @param to The characters are copied here.
   * @param i The beginning iterator.
   * @param j The ending iterator.
   */
  template<class IteratorType>
  static void copy_chars( pointer to, IteratorType i, IteratorType j ) {
    for ( ; i != j; ++to, ++i )
      traits_type::assign( *to, *i );
  }

  /**
   * Specialization of %copy_chars for the common case of pointers.
   *
   * @param to The characters are copied here.
   * @param p The beginning pointer.
   * @param q The ending pointer.
   */
  static void copy_chars( pointer to, const_pointer p, const_pointer q ) {
    base_type::copy( to, p, q - p );
  }

  /**
   * Calculates the number of bytes needed to allocate a %ptr_rep.
   *
   * @return Returns said number of bytes.
   */
  static size_type data_size( size_type cap ) {
    return (cap + 1) * sizeof( value_type );
  }

  /**
   * Disposes of the string data only.
   *
   * @param a The allocator to use.
   */
  void dispose_data_only( allocator_type &a ) {
    if ( data() ) {
      if ( dispose_data_using_delete_ )
        delete[] data();
      else
        a.deallocate(
          reinterpret_cast<char*>( data() ), data_size( this->capacity() )
        );
    }
  }

  /**
   * The pointer to the string data.
   */
  pointer p_;

  /**
   * If <code>true</code>, dispose of the string data using
   * <code>delete[]</code>
   */
  bool dispose_data_using_delete_;
};

} // namespace rstring_classes
} // namespace zorba

#include "ptr_rep.tcc"

#endif /* ZORBA_RSTRING_PTR_REP_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
