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

#ifndef ZORBA_RSTRING_DEFAULT_REP_H
#define ZORBA_RSTRING_DEFAULT_REP_H

#include <iterator>

#include "util/cxx_util.h"
#include "rep_base.h"

namespace zorba {
namespace rstring_classes {

/**
 * The default string representation.  This is most similar to that used by
 * std::string and for the same reason: it combines the %rep and the string
 * data into a single object that is allocated together; no additional pointer
 * is used to refer to the string data.  This saves space and halves the number
 * of heap allocations.
 *
 * The caveat is that it can not be used to "wrap" or take ownership of an
 * existing pointer to a C string: the C string must always be copied.
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
class rep : public rep_base<RefCountType,TraitsType,Allocator> {
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
  typedef rep<RefCountType,TraitsType,Allocator> result_rep_type;

  /**
   * Allocates a new %rep.
   *
   * @param a The allocator to use.
   * @param cap The string capacity.
   * @param old_cap The previous capacity, if any.
   */
  static rep* alloc( allocator_type const &a, size_type cap,
                     size_type old_cap = 0 );

  // REP_CLONE_A_ST_X
  /**
   * Clones this %rep.
   *
   * @param a The allocator to use.
   * @param add_capacity If > 0, creates a non-identical clone that has the
   * given added capacity.
   */
  rep* clone( allocator_type const &a, size_type add_capacity = 0 ) const;

  // REP_CONSTRUCT_P_ST_VT_A_X
  /**
   * Constructs a rep containing \a n copies of a character.
   *
   * @param n The number times to repeat the character.
   * @param c The character.
   * @param a The allocator to use.
   */
  static rep* construct( size_type size, value_type c,
                         allocator_type const &a );

  // REP_CONSTRUCT_2II_A_X
  /**
   * Constructs a %rep from either forward or input iterators.  This
   * function is a compile-time switch based on the iterator's tag.
   *
   * @tparam IteratorType The iterator type.
   * @param begin An iterator positioned at the beginning of a sequence.
   * @param end An iterator positioned one past the end of a sequence.
   * @param a The allocator to use.
   */
  template<class IteratorType>
  static rep* construct( IteratorType begin, IteratorType end,
                         allocator_type const &a ) {
    typedef typename std::iterator_traits<IteratorType>::iterator_category tag;
    return construct( begin, end, a, tag() );
  }

  /**
   * Gets the string data.
   *
   * @return Returns said data.
   */
  pointer data() const {
    return reinterpret_cast<pointer>( const_cast<rep*>( this ) + 1 );
  }

  /**
   * Disposes this %rep only if it's not being shared; otherwise decrements the
   * reference-count.
   *
   * @param a The allocator that was used to create this %rep.
   */
  void dispose( allocator_type const &a ) {
    if ( this != empty_rep() && this->dec() < 0 ) {
      raw_allocator( a ).deallocate(
        reinterpret_cast<char*>( this ), raw_size( this->capacity() )
      );
    }
  }

  /**
   * Gets the singleton %rep for the empty string.
   *
   * @return Returns said %rep.
   */
  static rep* empty_rep() {
    static_assert(
      sizeof( rep ) + sizeof( value_type )
        <= sizeof( empty_rep_base::rep_model ),
      "storage for string representation is too small"
    );
    return reinterpret_cast<rep*>( empty_rep_base::empty_rep() );
  }

  /**
   * Reserves a minimum capacity.
   *
   * @param cap The minimum capacity to reserve.
   * @param a The allocator to use.
   * @return Returns the possibly new %rep object.
   */
  rep* reserve( size_type cap, allocator_type const &a ) {
    if ( cap > this->capacity() /* || this->is_shared() */ ) {
      rep *const r = clone( a, cap - this->capacity() );
      dispose( a );
      return r;
    }
    return this;
  }

  /**
   * Sets the number of characters in this rep.
   * Additionally ensures that the string is terminated by a NULL character.
   *
   * @param n The number of characters.
   */
  void set_length( size_type n ) {
    base_type::set_length( n );
    data()[ n ] = value_type( 0 );
  }

protected:
  // REP_CONSTRUCT_2II_A_FIT_X
  /**
   * Constructs a %rep from forward iterators.
   *
   * @tparam ForwardIterator The forward iterator type.
   * @param begin The iterator marking the beginning of the range.
   * @param end The iterator marking one past the end of the range.
   * @param a The allocator to use.
   */
  template<class ForwardIterator>
  static rep* construct( ForwardIterator begin, ForwardIterator end,
                         allocator_type const &a, std::forward_iterator_tag );

  // REP_CONSTRUCT_2II_A_IIT_X
  /**
   * Constructs a %rep from input iterators.
   *
   * @param begin The iterator marking the beginning of the range.
   * @param end The iterator marking one past the end of the range.
   * @param a The allocator to use.
   */
  template<class InputIterator>
  static rep* construct( InputIterator begin, InputIterator end,
                         allocator_type const &a, std::input_iterator_tag );

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
   * @param begin The beginning pointer.
   * @param end The ending pointer.
   */
  static void copy_chars( pointer to, const_pointer begin, const_pointer end ) {
    base_type::copy( to, begin, end - begin );
  }

  /**
   * Constructs a %rep.
   *
   * @param cap The capacity.
   */
  rep( size_type cap ) : base_type( cap ) {
  }

  /**
   * Calculates the number of bytes needed to allocate a %rep.
   *
   * @return Returns said number of bytes.
   */
  static size_type raw_size( size_type cap ) {
    return sizeof( rep ) + (cap + 1) * sizeof( value_type );
  }
};

} // namespace rstring_classes
} // namespace zorba

#include "default_rep.tcc"

#endif /* ZORBA_RSTRING_DEFAULT_REP_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
