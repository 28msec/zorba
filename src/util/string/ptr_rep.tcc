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

#ifndef ZORBA_RSTRING_PTR_REP_TCC
#define ZORBA_RSTRING_PTR_REP_TCC

#ifndef ZORBA_RSTRING_PTR_REP_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_RSTRING_PTR_REP_H */

#include <algorithm>
#include <stdexcept>                    /* for std::logic_error */

namespace zorba {
namespace rstring_classes {

// PTR_REP_CALC_CAP_2ST_X
template<class RefCountType,class TraitsType,class Allocator>
typename ptr_rep<RefCountType,TraitsType,Allocator>::size_type
  ptr_rep<RefCountType,TraitsType,Allocator>::
calc_cap( size_type cap, size_type old_cap ) {
  size_type const page_size = 4096;
  size_type const malloc_header_size = sizeof( void* ) * 4;
  if ( cap > old_cap && cap < old_cap * 2 )
    cap = old_cap * 2;
  size_type const malloc_size = data_size( cap ) + malloc_header_size;
  if ( malloc_size > page_size && cap > old_cap ) {
    size_type const extra = page_size - malloc_size % page_size;
    cap += extra / sizeof( value_type );
  }
  return cap;
}

// PTR_REP_CLONE_A_ST_X
template<class RefCountType,class TraitsType,class Allocator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
clone( allocator_type const &a, size_type add_capacity ) const {
  size_type const len = this->length();
  size_type const cap = this->capacity();
  ptr_rep *const r = alloc( a, cap + add_capacity, cap );
  if ( len )
    base_type::copy( r->data(), data(), len );
  r->set_length( len );
  return r;
}

// PTR_REP_CONSTRUCT_P_ST_VT_A_X
template<class RefCountType,class TraitsType,class Allocator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
construct( size_type size, value_type c, allocator_type const &a ) {
  if ( !size && a == allocator_type() )
    return empty_rep();
  ptr_rep *const r = alloc( a, size );
  if ( size )
    base_type::assign( r->data(), size, c );
  r->set_length( size );
  return r;
}

// PTR_REP_CONSTRUCT_2II_A_FIT_X
template<class RefCountType,class TraitsType,class Allocator>
template<class ForwardIterator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
construct( ForwardIterator i, ForwardIterator j, allocator_type const &a,
           std::forward_iterator_tag ) {
  if ( i == j && a == allocator_type() )
    return empty_rep();
  if ( !i && i != j )
    throw std::logic_error( "NULL not valid" );
  size_type const len = j - i;
  ptr_rep *const r = alloc( a, len );
  try {
    copy_chars( r->data(), i, j );
  }
  catch ( ... ) {
    r->dispose( a );
    throw;
  }
  r->set_length( len );
  return r;
}

// PTR_REP_CONSTRUCT_2II_A_IIT_X
template<class RefCountType,class TraitsType,class Allocator>
template<class InputIterator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
construct( InputIterator i, InputIterator j, allocator_type const &a,
           std::input_iterator_tag ) {
  if ( i == j && a == allocator_type() )
    return empty_rep();

  // special-case relatively small input
  value_type buf[ 128 ];
  size_type len = 0;
  while ( i != j && len < sizeof( buf ) / sizeof( value_type ) ) {
    buf[ len++ ] = *i;
    ++i;
  }
  ptr_rep *r = alloc( a, len );
  copy( r->data(), buf, len );

  try {
    while ( i != j ) {
      if ( len == r->capacity() ) {
        ptr_rep *const r2 = r->clone( a, 1 );
        r->dispose( a );
        r = r2;
      }
      r->data()[ len++ ] = *i;
      ++i;
    }
  }
  catch ( ... ) {
    r->dispose( a );
    throw;
  }
  r->set_length( len );
  return r;
}

// PTR_REP_CONSTRUCT_2P_A_X
template<class RefCountType,class TraitsType,class Allocator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
construct( pointer p, pointer q, allocator_type const &a ) {
  if ( p == q && a == allocator_type() )
    return empty_rep();
  if ( !p && q )
    throw std::logic_error( "NULL not valid" );
  size_type const len = q - p;
  ptr_rep *const r = alloc_rep_only( a, len );
  r->p_ = p;
  r->dispose_data_using_delete_ = true;
  r->set_length( len );
  return r;
}

// PTR_REP_RESERVE_ST_A_X
template<class RefCountType,class TraitsType,class Allocator>
ptr_rep<RefCountType,TraitsType,Allocator>*
  ptr_rep<RefCountType,TraitsType,Allocator>::
reserve( size_type cap, allocator_type const &a ) {
  if ( cap > this->capacity() ) {
    size_type const add_capacity = cap - this->capacity();
    if ( true || this->is_shared() ) {
      ptr_rep *const r = clone( a, add_capacity );
      dispose( a );
      return r;
    }
    allocator_type alloc = raw_allocator( a );
    cap = calc_cap( cap, this->capacity() );
    pointer const p = clone_data_only( alloc, cap );
    dispose_data_only( alloc );
    p_ = p;
    dispose_data_using_delete_ = false;
    this->cap_ = cap;
  }
  return this;
}

} // namespace rstring_classes
} // namespace zorba

#endif /* ZORBA_RSTRING_PTR_REP_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
