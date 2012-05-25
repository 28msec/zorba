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

#ifndef ZORBA_HASHTABLE_TCC
#define ZORBA_HASHTABLE_TCC

#include <algorithm>
#include <stdexcept>

#ifndef ZORBA_HASHTABLE_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_HASHTABLE_H */

namespace zorba {
namespace ztd {

////////// hashtable functions ////////////////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::node**
ZORBA_HASHTABLE_CLASS::alloc_buckets( size_type n_bkt ) {
  bucket_alloc_type alloc( node_alloc_ );
  //
  // Allocate one extra bucket to be a sentinel containing an arbitrary
  // non-null value.  Iteration relies on this.
  //
  node **const p = alloc.allocate( n_bkt + 1 );
  std::fill( p, p + n_bkt, static_cast<node*>( nullptr ) );
  p[ n_bkt ] = reinterpret_cast<node*>( 0x1000 );
  return p;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::node*
ZORBA_HASHTABLE_CLASS::alloc_node( value_type const &v ) {
  node *const p = node_alloc_.allocate( 1 );
  try {
    node_alloc_.construct( p, v );
    p->next_ = nullptr;
    return p;
  }
  catch ( ... ) {
    node_alloc_.deallocate( p, 1 );
    throw;
  }
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::dealloc_buckets( node **p, size_type n_bkt ) {
  bucket_alloc_type alloc( node_alloc_ );
  alloc.deallocate( p, n_bkt + 1 /* sentinel */ );
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::dealloc_node( node *p ) {
  node_alloc_.destroy( p );
  node_alloc_.deallocate( p, 1 );
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::dealloc_nodes( node **buckets, size_type n_bkt ) {
  for ( size_type bkt = 0; bkt < n_bkt; ++bkt ) {
    node *p = buckets[ bkt ];
    while ( p ) {
      node *const q = p;
      p = p->next_;
      dealloc_node( q );
    }
    buckets[ bkt ] = nullptr;
  }
}

ZORBA_HASHTABLE_TEMPLATE
ZORBA_HASHTABLE_CLASS::hashtable( size_type bucket_count,
                                  hasher const &hash,
                                  key_equal const &equal,
                                  allocator_type const &alloc ) :
  equal_( equal ),
  hasher_( hash ),
  n_bkt_( bucket_count ),
  n_elt_( 0 ),
  node_alloc_( alloc )
{
  buckets_ = alloc_buckets( n_bkt_ );
}

ZORBA_HASHTABLE_TEMPLATE
ZORBA_HASHTABLE_CLASS::hashtable( hashtable const &that ) :
  equal_( that.equal_ ),
  hasher_( that.hasher_ ),
  n_bkt_( that.n_bkt_ ),
  n_elt_( that.n_elt_ ),
  node_alloc_( that.node_alloc_ )
{
  buckets_ = alloc_buckets( n_bkt_ );
  try {
    for ( size_type bkt = 0; bkt < n_bkt_; ++bkt ) {
      node **tail = buckets_ + bkt;
      for ( node *p = that.buckets_[ bkt ]; p; p = p->next_ ) {
        *tail = alloc_node( *p );
        tail = &(*tail)->next_;
      }
    }
  }
  catch ( ... ) {
    clear();
    dealloc_buckets( buckets_, n_bkt_ );
    throw;
  }
}

ZORBA_HASHTABLE_TEMPLATE
ZORBA_HASHTABLE_CLASS&
ZORBA_HASHTABLE_CLASS::operator=( hashtable const &that ) {
  hashtable temp( that );
  this->swap( temp );
  return *this;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::mapped_type&
ZORBA_HASHTABLE_CLASS::at( key_type const &key ) {
  if ( node *const p = find_node( key ) )
    return p->second;
  throw std::out_of_range( "at()" );
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::mapped_type const&
ZORBA_HASHTABLE_CLASS::at( key_type const &key ) const {
  if ( node const *const p = find_node( key ) )
    return p->second;
  throw std::out_of_range( "at()" );
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::mapped_type&
ZORBA_HASHTABLE_CLASS::operator[]( key_type const &key ) {
  size_type const bkt = bucket( key );
  if ( node *const p = find_node( bkt, key ) )
    return p->second;
  return insert( bkt, std::make_pair( key, mapped_type() ) ).first->second;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::count( key_type const &key ) const {
  return !!find_node( key );
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::erase( const_iterator pos ) {
  iterator result( pos.cur_bkt_, pos.cur_node_ );
  ++result;

  node *cur = *pos.cur_bkt_;
  if ( cur == pos.cur_node_ )
    *pos.cur_bkt_ = cur->next_;
  else {
    node *next = cur->next_;
    while ( next != pos.cur_node_ ) {
      cur = next;
      next = cur->next_;
    }
    cur->next_ = next->next_;
  }

  dealloc_node( pos.cur_node_ );
  --n_elt_;

  return result;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::erase( const_iterator i, const_iterator j ) {
  while ( i != j )
    i = erase( i );
  return iterator( j.cur_bkt_, j.cur_node_ );
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::erase( key_type const &key ) {
  size_type const bkt = bucket( key );
  for ( node *p = buckets_[ bkt ], **pp = &buckets_[ bkt ]; p;
        pp = &p->next_, p = p->next_ ) {
    if ( equal_( p->first, key ) ) {
      *pp = p->next_;
      dealloc_node( p );
      --n_elt_;
      return 1;
    }
  }
  return 0;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::find( key_type const &key ) {
  size_type const bkt = bucket( key );
  if ( node *const p = find_node( bkt, key ) )
    return iterator( buckets_ + bkt, p );
  return end();
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::find( key_type const &key ) const {
  size_type const bkt = bucket( key );
  if ( node *const p = find_node( bkt, key ) )
    return const_iterator( buckets_ + bkt, p );
  return end();
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::node*
ZORBA_HASHTABLE_CLASS::find_node( node *p, key_type const &key ) const {
  for ( ; p; p = p->next_ )
    if ( equal_( p->first, key ) )
      return p;
  return nullptr;
}

ZORBA_HASHTABLE_TEMPLATE
std::pair<typename ZORBA_HASHTABLE_CLASS::iterator,
          typename ZORBA_HASHTABLE_CLASS::iterator>
ZORBA_HASHTABLE_CLASS::equal_range( key_type const &key ) {
  size_type const bkt = bucket( key );
  node **const head = buckets_ + bkt;
  if ( node *p = find_node( *head, key ) ) {
    node *q = p->next_;
    for ( ; q; q = q->next_ )
      if ( !equal_( q->first, key ) )
        break;
    iterator first( head, p );
    iterator last( head, q );
    if ( !q )
      last.inc_bucket();
    return std::make_pair( first, last );
  }
  return std::make_pair( end(), end() );
}

ZORBA_HASHTABLE_TEMPLATE
std::pair<typename ZORBA_HASHTABLE_CLASS::const_iterator,
          typename ZORBA_HASHTABLE_CLASS::const_iterator>
ZORBA_HASHTABLE_CLASS::equal_range( key_type const &key ) const {
  size_type const bkt = bucket( key );
  node **const head = buckets_ + bkt;
  if ( node *p = find_node( *head, key ) ) {
    node *q = p->next_;
    for ( ; q; q = q->next_ )
      if ( !equal_( q->first, key ) )
        break;
    const_iterator first( head, p );
    const_iterator last( head, q );
    if ( !q )
      last.inc_bucket();
    return std::make_pair( first, last );
  }
  return std::make_pair( end(), end() );
}

ZORBA_HASHTABLE_TEMPLATE
std::pair<typename ZORBA_HASHTABLE_CLASS::iterator,bool>
ZORBA_HASHTABLE_CLASS::insert( value_type const &value ) {
  key_type const &key = value.first;
  size_type const bkt = bucket( key );
  node *&head = buckets_[ bkt ];

  if ( node *const p = find_node( head, key ) )
    return std::make_pair( iterator( &head, p ), false );
  return insert( bkt, value );
}

ZORBA_HASHTABLE_TEMPLATE
std::pair<typename ZORBA_HASHTABLE_CLASS::iterator,bool>
ZORBA_HASHTABLE_CLASS::insert( size_type bkt, value_type const &value ) {
  //
  // Allocate the new node before doing the rehash (if any) so that we don't do
  // a rehash if the allocation throws an exception.
  //
  node *const p = alloc_node( value );

  size_type const new_n_bkt = rehash_policy_.need_rehash( n_bkt_, n_elt_, 1 );
  if ( new_n_bkt )
    bkt = bucket( value.first, new_n_bkt );

  try {
    if ( new_n_bkt )
      rehash( new_n_bkt );
    node *&head = buckets_[ bkt ];
    p->next_ = head;
    head = p;
    ++n_elt_;
    return std::make_pair( iterator( &head, p ), true );
  }
  catch ( ... ) {
    dealloc_node( p );
    throw;
  }
}

ZORBA_HASHTABLE_TEMPLATE
template<class InputIterator>
void ZORBA_HASHTABLE_CLASS::insert( InputIterator first, InputIterator last ) {
  size_type const n_ins = std::distance( first, last );
  size_type const new_n_bkt =
    rehash_policy_.need_rehash( n_bkt_, n_elt_, n_ins );
  if ( new_n_bkt )
    rehash( new_n_bkt );
  for ( ; first != last; ++first )
    insert( *first );
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::max_load_factor( float load_factor ) {
  if ( load_factor <= 0 )
    throw std::invalid_argument( "load_factor <= 0" );
  rehash_policy_ = rehash_policy_type( load_factor );
  size_type const n_bkt = rehash_policy_.buckets_for_elements( n_elt_ );
  if ( n_bkt > n_bkt_ )
    rehash( n_bkt );
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::rehash( size_type new_n_bkt ) {
  new_n_bkt = std::max(
    rehash_policy_.adjust_buckets( new_n_bkt ),
    rehash_policy_.buckets_for_elements( n_elt_ + 1 )
  );
  node **const new_buckets = alloc_buckets( new_n_bkt );
  try {
    for ( size_type bkt = 0; bkt < n_bkt_; ++bkt ) {
      node *&head = buckets_[ bkt ];
      while ( node *p = head ) {
        size_type const new_bkt = bucket( p->first, new_n_bkt );
        head = p->next_;
        p->next_ = new_buckets[ new_bkt ];
        new_buckets[ new_bkt ] = p;
      }
    }
    dealloc_buckets( buckets_, n_bkt_ );
    buckets_ = new_buckets;
    n_bkt_ = new_n_bkt;
  }
  catch ( ... ) {
    dealloc_nodes( new_buckets, new_n_bkt );
    dealloc_buckets( new_buckets, new_n_bkt );
    clear();
    throw;
  }
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::swap( hashtable &that ) {
  std::swap( buckets_, that.buckets_ );
  std::swap( equal_, that.equal_ );
  std::swap( hasher_, that.hasher_ );
  std::swap( n_bkt_, that.n_bkt_ );
  std::swap( n_elt_, that.n_elt_ );
  std::swap( node_alloc_, that.node_alloc_ );
  std::swap( rehash_policy_, that.rehash_policy_ );
}

////////// iterator functions /////////////////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE
ZORBA_HASHTABLE_CLASS::iterator::iterator( node **bkt, node *n ) :
  cur_bkt_( bkt ), cur_node_( n )
{
  while ( !cur_node_ )
    cur_node_ = *++cur_bkt_;
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::iterator::inc_bucket() {
  while ( !*++cur_bkt_ )
    ;
  cur_node_ = *cur_bkt_;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::iterator::operator++(int) {
  iterator const temp( cur_node_ );
  operator++();
  return temp;
}

////////// const_iterator functions ///////////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE
ZORBA_HASHTABLE_CLASS::const_iterator::const_iterator( node **bkt, node *n ) :
  cur_bkt_( bkt ), cur_node_( n )
{
  while ( !cur_node_ )
    cur_node_ = *++cur_bkt_;
}

ZORBA_HASHTABLE_TEMPLATE
void ZORBA_HASHTABLE_CLASS::const_iterator::inc_bucket() {
  while ( !*++cur_bkt_ )
    ;
  cur_node_ = *cur_bkt_;
}

ZORBA_HASHTABLE_TEMPLATE
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::const_iterator::operator++(int) {
  const_iterator const temp( cur_node_ );
  operator++();
  return temp;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba

#endif  /* ZORBA_HASHTABLE_TCC */
/* vim:set et ts=2 sw=2: */
