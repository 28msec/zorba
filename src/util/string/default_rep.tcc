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

#ifndef ZORBA_RSTRING_DEFAULT_REP_TCC
#define ZORBA_RSTRING_DEFAULT_REP_TCC

#ifndef ZORBA_RSTRING_DEFAULT_REP_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_RSTRING_DEFAULT_REP_H */

#include <algorithm>
#include <stdexcept>

namespace zorba {
namespace rstring_classes {

template<class RefCountType,class TraitsType,class Allocator>
rep<RefCountType,TraitsType,Allocator>*
  rep<RefCountType,TraitsType,Allocator>::
alloc( allocator_type const &a, size_type cap, size_type old_cap ) {
  size_type const page_size = 4096;
  size_type const malloc_header_size = sizeof( void* ) * 4;
  if ( cap > old_cap && cap < old_cap * 2 )
    cap = old_cap * 2;
  size_type alloc_size = raw_size( cap );
  size_type const malloc_size = alloc_size + malloc_header_size;
  if ( malloc_size > page_size && cap > old_cap ) {
    size_type const extra = page_size - malloc_size % page_size;
    cap += extra / sizeof( value_type );
    alloc_size = raw_size( cap );
  }
  void *const place = raw_allocator( a ).allocate( alloc_size );
  return new( place ) rep( cap );
}

// REP_CLONE_A_ST_X
template<class RefCountType,class TraitsType,class Allocator>
rep<RefCountType,TraitsType,Allocator>*
  rep<RefCountType,TraitsType,Allocator>::
clone( allocator_type const &a, size_type add_capacity ) const {
  size_type const len = this->length();
  size_type const cap = this->capacity();
  rep *const r = alloc( a, cap + add_capacity, cap );
  if ( len )
    base_type::copy( r->data(), data(), len );
  r->set_length( len );
  return r;
}

// REP_CONSTRUCT_P_ST_VT_A_X
template<class RefCountType,class TraitsType,class Allocator>
rep<RefCountType,TraitsType,Allocator>*
  rep<RefCountType,TraitsType,Allocator>::
construct( size_type n, value_type c, allocator_type const &a ) {
  if ( !n && a == allocator_type() )
    return empty_rep();
  rep *const r = alloc( a, n );
  if ( n )
    base_type::assign( r->data(), n, c );
  r->set_length( n );
  return r;
}

// REP_CONSTRUCT_2II_A_FIT_X
template<class RefCountType,class TraitsType,class Allocator>
template<class ForwardIterator>
rep<RefCountType,TraitsType,Allocator>*
  rep<RefCountType,TraitsType,Allocator>::
construct( ForwardIterator begin, ForwardIterator end, allocator_type const &a,
           std::forward_iterator_tag ) {
  if ( begin == end && a == allocator_type() )
    return empty_rep();
  if ( !begin && begin != end )
    throw std::logic_error( "NULL not valid" );
  size_type const len = static_cast<size_type>( std::distance( begin, end ) );
  rep *const r = alloc( a, len );
  try {
    copy_chars( r->data(), begin, end );
  }
  catch ( ... ) {
    r->dispose( a );
    throw;
  }
  r->set_length( len );
  return r;
}

// ZS_CONSTRUCT_2II_A_IIT_X
template<class RefCountType,class TraitsType,class Allocator>
template<class InputIterator>
rep<RefCountType,TraitsType,Allocator>*
  rep<RefCountType,TraitsType,Allocator>::
construct( InputIterator begin, InputIterator end, allocator_type const &a,
           std::input_iterator_tag ) {
  if ( begin == end && a == allocator_type() )
    return empty_rep();
  value_type buf[ 128 ];
  size_type len = 0;
  while ( begin != end && len < sizeof( buf ) / sizeof( value_type ) ) {
    buf[ len++ ] = *begin;
    ++begin;
  }
  rep *r = alloc( a, len );
  copy( r->data(), buf, len );
  try {
    while ( begin != end ) {
      if ( len == r->capacity() ) {
        rep *const r2 = r->clone( a, 1 );
        r->dispose( a );
        r = r2;
      }
      r->data()[ len++ ] = *begin;
      ++begin;
    }
  }
  catch ( ... ) {
    r->dispose( a );
    throw;
  }
  r->set_length( len );
  return r;
}

} // namespace rstring_classes
} // namespace zorba

#endif /* ZORBA_RSTRING_DEFAULT_REP_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
