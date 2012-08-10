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

#ifndef ZORBA_HASHTABLE_H
#define ZORBA_HASHTABLE_H

// standard
#include <algorithm>
#include <iterator>
#include <sys/types.h>
#include <utility>                      /* for pair */

// local
#include "util/cxx_util.h"
#include "util/stl_util.h"

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

/**
 * The base class for a hash-table implementation.
 *
 * @tparam KeyType They map's key type.
 * @tparam ValueType The type the keys are mapped to.
 * @tparam KeyExtract The unary_function to use to extract a key from a value.
 * @tparam KeyHash The unary_function to use for generating hash codes.
 * @tparam KeyEqual The binary_function to use to test for key equality.
 * @tparam Allocator The allocator to use.
 * @tparam RehashPolicy The rehash policy class to use.
 */
template<
  typename KeyType,
  typename ValueType,
  class KeyExtract,
  class KeyHash,
  class KeyEqual,
  class Allocator,
  class RehashPolicy
>
class hashtable_base {
protected:
  struct node;
  typedef RehashPolicy rehash_policy_type;
public:
  typedef KeyType key_type;
  typedef ValueType value_type;
  typedef KeyHash hasher;
  typedef KeyEqual key_equal;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;

  /**
   * Constructs a %hashtable_base.
   *
   * @param bucket_count The initial number of buckets to use.
   * @param hash The hash-code unary functor to use.
   * @param equal The key-equality functor to use.
   * @param alloc The allocator to use.
   */
  hashtable_base( size_type bucket_count, hasher const &hash,
                  key_equal const &equal, allocator_type const &alloc );

  /**
   * Copy constructor.
   *
   * @param that The %hashtable_base to copy from.
   */
  hashtable_base( hashtable_base const &that );

  /**
   * Destructor.
   */
  ~hashtable_base();

  /**
   * Assignment operator.
   *
   * @param that The %hashtable_base to assign from.
   * @return Returns \c *this.
   */
  hashtable_base& operator=( hashtable_base const &that );

  ////////// local_iterator ///////////////////////////////////////////////////

  class local_iterator :
    public std::iterator<std::forward_iterator_tag,value_type> {
  public:
    local_iterator() : cur_node_( nullptr ) { }

    reference operator*() const;
    pointer operator->() const;
    local_iterator& operator++();
    local_iterator operator++(int);

    friend bool operator==( local_iterator const &i, local_iterator const &j ) {
      return i.cur_node_ == j.cur_node_;
    }

    friend bool operator!=( local_iterator const &i, local_iterator const &j ) {
      return i.cur_node_ != j.cur_node_;
    }

  private:
    node *cur_node_;

    local_iterator( node *p ) : cur_node_( p ) { }
    friend class hashtable_base;
  };

  ////////// const_local_iterator /////////////////////////////////////////////

  class const_local_iterator :
    public std::iterator<std::forward_iterator_tag,value_type const> {
  public:
    const_local_iterator() : cur_node_( nullptr ) { }

    const_reference operator*() const;
    const_pointer operator->() const;
    const_local_iterator& operator++();
    const_local_iterator operator++(int);

    friend bool operator==( const_local_iterator const &i,
                            const_local_iterator const &j ) {
      return i.cur_node_ == j.cur_node_;
    }

    friend bool operator!=( const_local_iterator const &i,
                            const_local_iterator const &j ) {
      return i.cur_node_ != j.cur_node_;
    }

  private:
    node const *cur_node_;

    const_local_iterator( node const *p ) : cur_node_( p ) { }
    friend class hashtable_base;
  };

  ////////// iterator /////////////////////////////////////////////////////////

  class iterator : public std::iterator<std::forward_iterator_tag,value_type> {
  public:
    iterator() : cur_bkt_( nullptr ), cur_node_( nullptr ) { }

    reference operator*() const;
    pointer operator->() const;
    iterator& operator++();
    iterator operator++(int);

    friend bool operator==( iterator const &i, iterator const &j ) {
      return i.cur_node_ == j.cur_node_;
    }

    friend bool operator!=( iterator const &i, iterator const &j ) {
      return i.cur_node_ != j.cur_node_;
    }

  private:
    node **cur_bkt_;
    node *cur_node_;

    iterator( node **bkt, node *p );
    void inc_bucket();

    friend class hashtable_base;
    friend class const_iterator;
  };

  ////////// const_iterator ///////////////////////////////////////////////////

  class const_iterator :
    public std::iterator<std::forward_iterator_tag,value_type const> {
  public:
    const_iterator() : cur_bkt_( nullptr ), cur_node_( nullptr ) { }
    const_iterator( iterator const& );

    const_reference operator*() const;
    const_pointer operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int);

    friend bool operator==( const_iterator const &i, const_iterator const &j ) {
      return i.cur_node_ == j.cur_node_;
    }

    friend bool operator!=( const_iterator const &i, const_iterator const &j ) {
      return i.cur_node_ != j.cur_node_;
    }

  private:
    node **cur_bkt_;
    node *cur_node_;

    const_iterator( node **bkt, node *p );
    void inc_bucket();

    friend class hashtable_base;
  };

  ////////// iteration ////////////////////////////////////////////////////////

  /**
   * Creates an iterator positioned at the "first" element.  (Because this is
   * an \e unordered map, "first" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  iterator begin();

  /**
   * Creates an iterator positioned at the "first" element.  (Because this is
   * an \e unordered map, "first" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  const_iterator begin() const;

  /**
   * Creates an iterator positioned at the "first" element.  (Because this is
   * an \e unordered map, "first" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  const_iterator cbegin() const;

  /**
   * Creates an iterator positioned one past the "last" element.  (Because this
   * is an \e unordered map, "last" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  iterator end();

  /**
   * Creates a const_iterator positioned one past the "last" element.  (Because
   * this is an \e unordered map, "last" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  const_iterator end() const;

  /**
   * Creates a const_iterator positioned one past the "last" element.  (Because
   * this is an \e unordered map, "last" is arbitrary.)
   *
   * @return Returns said iterator.
   */
  const_iterator cend() const;

  /**
   * Creates a local_iterator positioned at the first element in the given
   * bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  local_iterator begin( size_type bkt );

  /**
   * Creates a const_local_iterator positioned at the first element in the
   * given bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  const_local_iterator begin( size_type bkt ) const;

  /**
   * Creates a const_local_iterator positioned at the first element in the
   * given bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  const_local_iterator cbegin( size_type bkt ) const;

  /**
   * Creates a local_iterator positioned at one past the last element in the
   * given bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  local_iterator end( size_type bkt );

  /**
   * Creates a const_local_iterator positioned at one past the last element in
   * the given bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  const_local_iterator end( size_type bkt ) const;

  /**
   * Creates a const_local_iterator positioned at one past the last element in
   * the given bucket.
   *
   * @param bkt The index of the bucket.
   * @return Returns said iterator.
   */
  const_local_iterator cend( size_type bkt ) const;

  ////////// modifiers ////////////////////////////////////////////////////////

  /**
   * Clears this %hashtable_base, i.e., erases all elements.
   */
  void clear();

  /**
   * Erases the element at \a pos.
   *
   * @param pos The %iterator positioned at the element to erase.
   * @return Returns an iterator positioned one past the erased element.
   */
  iterator erase( iterator pos );

  /**
   * Erases the element at \a pos.
   *
   * @param pos The %iterator positioned at the element to erase.
   * @return Returns an iterator positioned one past the erased element.
   */
  iterator erase( const_iterator pos );

  /**
   * Erases all the elements in the range [<em>first</em>,<em>last</em>).
   *
   * @param first The %iterator positioned at the first element to erase.
   * @param last The %iterator positioned one past the last element to erase.
   * @return Returns an iterator positioned one past the last erased element.
   */
  iterator erase( const_iterator first, const_iterator last );

  /**
   * Erases the element having the given key.
   *
   * @param key The key.
   * @return Returns the number of elements erased.
   */
  size_type erase( key_type const &key );

  /**
   * Attempts to insert a new value.
   *
   * @param value The value to insert.
   * @return If a value with the given key is already in the %hashtable_base,
   * returns [i,false] where \a i is positioned at the existing element;
   * otherwise returns [i,true] where \a i is positioned at the new element.
   */
  std::pair<iterator,bool> insert( value_type const &value );

  /**
   * Attempts to insert a new value.
   *
   * @param hint An iterator providing a hint as to where to attempt to insert
   * the new value.
   * @param value The value to insert.
   * @return If a value with the given key is already in the %hashtable_base,
   * returns [i,false] where \a i is positioned at the existing element;
   * otherwise returns [i,true] where \a i is positioned at the new element.
   */
  iterator insert( const_iterator hint, value_type const &value );

  /**
   * Attempts to insert the values provided by the given iterator.
   *
   * @tparam InputIterator The input iterator type.
   * @param first An iterator positioned at the first element to insert.
   * @param last An iterator positioned one past the last element to insert.
   */
  template<class InputIterator>
  void insert( InputIterator first, InputIterator last );

  /**
   * Rehashes the %hashtable_base.
   *
   * @param bucket_count The new number of buckets.
   */
  void rehash( size_type bucket_count );

  /**
   * Swaps this %hashtable_base with another.
   *
   * @param that The %hashtable_base to swap with.
   */
  void swap( hashtable_base &that );

  ////////// look-up //////////////////////////////////////////////////////////

  /**
   * Counts the number of elements having the given key.
   *
   * @param key The key to count.
   * @return Returns said number.
   */
  size_type count( key_type const &key ) const;

  /**
   * Attempts to find the given \a key.
   *
   * @param key The key to find.
   * @return If found, returns an iterator positioned at \a key; if not,
   * returns an iterator positioned at end().
   */
  iterator find( key_type const &key );

  /**
   * Attempts to find the given \a key.
   *
   * @param key The key to find.
   * @return If found, returns an iterator positioned at \a key; if not,
   * returns an iterator positioned at end().
   */
  const_iterator find( key_type const &key ) const;

  /**
   * Creates a pair of iterators giving the range of elements that have the
   * given key.
   *
   * @param key The key.
   * @return Returns said iterators.
   */
  std::pair<iterator,iterator> equal_range( key_type const &key );

  /**
   * Creates a pair of const_iterators giving the range of elements that have
   * the given key.
   *
   * @param key The key.
   * @return Returns said iterators.
   */
  std::pair<const_iterator,const_iterator>
  equal_range( key_type const &key ) const;

  ////////// buckets //////////////////////////////////////////////////////////

  /**
   * Gets the index of the bucket for the \a key.  Note that \a key isn't
   * necessarily in the %hashtable_base.
   *
   * @param key The key.
   * @return Returns an index in the range [0,max_bucket_count).
   */
  size_type bucket( key_type const &key ) const;

  /**
   * Gets the current number of buckets.
   *
   * @return Returns said number of buckets.
   */
  size_type bucket_count() const;

  /**
   * Gets the number of elements in the bucket specified by the given index.
   *
   * @param bucket_index The index of the bucket.
   * @return Returns said number of elements.
   */
  size_type bucket_size( size_type bucket_index ) const;

  /**
   * Gets the maximum possible number of buckets.
   *
   * @return Returns said number of buckets.
   */
  size_type max_bucket_count() const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  /**
   * Gets whether this %hashtable_base is empty.
   *
   * @return Returns \c true only if it's empty.
   */
  bool empty() const;

  /**
   * Gets the allocator being used.
   *
   * @return Returns said allocator.
   */
  allocator_type get_allocator() const;

  /**
   * Gets the hash function being used.
   *
   * @return Returns said function.
   */
  hasher hash_function() const;

  /**
   * Gets the key equality function being used.
   *
   * @return Returns said function.
   */
  key_equal key_eq() const;

  /**
   * Gets the current load factor.
   *
   * @return Returns said load factor.
   */
  float load_factor() const;

  /**
   * Gets the maximim load factor.
   *
   * @return Returns said load factor.
   */
  float max_load_factor() const;

  /**
   * Sets the load factor that affects the number of buckets.  If the new
   * number of buckets is greater than the old number, performs a rehash.
   *
   * @param load_factor The new maximum load factor.
   * @throws std::invalid_argument if \a load_factor &lt;= 0.
   */
  void max_load_factor( float load_factor );

  /**
   * Gets the maximum possible number of elements.
   *
   * @return Returns said number of elements.
   */
  size_type max_size() const;

  /**
   * Gets the number of elements.
   *
   * @return Returns said number of elements.
   */
  size_type size() const;

  /////////////////////////////////////////////////////////////////////////////

protected:
  struct node {
    value_type value_;
    node *next_;

    node() : value_( value_type() ), next_( nullptr ) { }
    node( value_type const &v ) : value_( v ), next_( nullptr ) { }
  };

  node* find_node( key_type const &key ) const {
    return find_node( bucket( key ), key );
  }

  node* find_node( node*, key_type const& ) const;

  node* find_node( size_type bkt, key_type const &key ) const {
    return find_node( buckets_[ bkt ], key );
  }

  std::pair<iterator,bool> insert( size_type bkt, value_type const &value );

private:
  typedef typename allocator_type::template rebind<node*>::other
    bucket_alloc_type;

  typedef typename allocator_type::template rebind<node>::other
    node_alloc_type;

  typedef typename hasher::result_type hash_code_type;

  node**  alloc_buckets( size_type n_bkt );
  void    dealloc_buckets( node**, size_type n_bkt );

  node*   alloc_node( value_type const& );
  void    dealloc_node( node* );
  void    dealloc_nodes( node**, size_type n_bkt );

  size_type bucket( key_type const &key, size_type n_bkt ) const {
    return bucket_for_code( hasher_( key ), n_bkt );
  }

  size_type bucket_for_code( hash_code_type code ) const {
    return bucket_for_code( code, n_bkt_ );
  }

  size_type bucket_for_code( hash_code_type code, size_type n_bkt ) const {
    return code % n_bkt;
  }

  void rehash_impl( size_type new_n_bkt );

  node **buckets_;
  KeyEqual equal_;
  hasher hasher_;
  KeyExtract key_of;
  size_type n_bkt_;
  size_type n_elt_;
  node_alloc_type node_alloc_;
  rehash_policy_type rehash_policy_;
};

#define ZORBA_HASHTABLE_TEMPLATE \
  template<typename K,typename V,class X,class H,class E,class A,class RP>

#define ZORBA_HASHTABLE_CLASS hashtable_base<K,V,X,H,E,A,RP>

////////// hashtable_base inline functions ////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE inline
ZORBA_HASHTABLE_CLASS::~hashtable_base() {
  clear();
  dealloc_buckets( buckets_, n_bkt_ );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::begin() {
  return iterator( buckets_, buckets_[0] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::begin() const {
  return const_iterator( buckets_, buckets_[0] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::cbegin() const {
  return begin();
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::local_iterator
ZORBA_HASHTABLE_CLASS::begin( size_type bkt ) {
  return local_iterator( buckets_[ bkt ] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator
ZORBA_HASHTABLE_CLASS::begin( size_type bkt ) const {
  return const_local_iterator( buckets_[ bkt ] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator
ZORBA_HASHTABLE_CLASS::cbegin( size_type bkt ) const {
  return begin( bkt );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::bucket( key_type const &key ) const {
  return bucket_for_code( hasher_( key ) );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::bucket_count() const {
  return n_bkt_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::bucket_size( size_type bkt ) const {
  return std::distance( begin( bkt ), end( bkt ) );
}

ZORBA_HASHTABLE_TEMPLATE inline
void ZORBA_HASHTABLE_CLASS::clear() {
  dealloc_nodes( buckets_, n_bkt_ );
  n_elt_ = 0;
}

ZORBA_HASHTABLE_TEMPLATE inline
bool ZORBA_HASHTABLE_CLASS::empty() const {
  return size() == 0;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::end() {
  return iterator( buckets_ + n_bkt_, buckets_[ n_bkt_ ] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::end() const {
  return const_iterator( buckets_ + n_bkt_, buckets_[ n_bkt_ ] );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_iterator
ZORBA_HASHTABLE_CLASS::cend() const {
  return end();
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::local_iterator
ZORBA_HASHTABLE_CLASS::end( size_type bkt ) {
  return local_iterator( nullptr );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator
ZORBA_HASHTABLE_CLASS::end( size_type bkt ) const {
  return const_local_iterator( nullptr );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator
ZORBA_HASHTABLE_CLASS::cend( size_type bkt ) const {
  return end( bkt );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::erase( iterator i ) {
  return erase( const_iterator( i ) );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::allocator_type
ZORBA_HASHTABLE_CLASS::get_allocator() const {
  return allocator_type( node_alloc_ );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::hasher
ZORBA_HASHTABLE_CLASS::hash_function() const {
  return hasher_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::iterator
ZORBA_HASHTABLE_CLASS::insert( const_iterator, value_type const &value ) {
  return insert( value ).first;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::key_equal
ZORBA_HASHTABLE_CLASS::key_eq() const {
  return equal_;
}

ZORBA_HASHTABLE_TEMPLATE inline
float ZORBA_HASHTABLE_CLASS::load_factor() const {
  return static_cast<float>( size() ) / static_cast<float>( bucket_count() );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::max_bucket_count() const {
  return max_size();
}

ZORBA_HASHTABLE_TEMPLATE inline
float ZORBA_HASHTABLE_CLASS::max_load_factor() const {
  return rehash_policy_.max_load_factor();
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::max_size() const {
  return node_alloc_.max_size();
}

ZORBA_HASHTABLE_TEMPLATE inline
void ZORBA_HASHTABLE_CLASS::rehash( size_type new_n_bkt ) {
  rehash_impl(
    std::max(
      rehash_policy_.adjust_buckets( new_n_bkt ),
      rehash_policy_.buckets_for_elements( n_elt_ + 1 )
    )
  );
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::size_type
ZORBA_HASHTABLE_CLASS::size() const {
  return n_elt_;
}

////////// local_iterator inline functions ////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::reference
ZORBA_HASHTABLE_CLASS::local_iterator::operator*() const {
  return cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::pointer
ZORBA_HASHTABLE_CLASS::local_iterator::operator->() const {
  return &cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::local_iterator&
ZORBA_HASHTABLE_CLASS::local_iterator::operator++() {
  cur_node_ = cur_node_->next_;
  return *this;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::local_iterator
ZORBA_HASHTABLE_CLASS::local_iterator::operator++(int) {
  local_iterator const temp( cur_node_ );
  cur_node_ = cur_node_->next_;
  return temp;
}

////////// const_local_iterator inline functions //////////////////////////////

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_reference
ZORBA_HASHTABLE_CLASS::const_local_iterator::operator*() const {
  return cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_pointer
ZORBA_HASHTABLE_CLASS::const_local_iterator::operator->() const {
  return &cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator&
ZORBA_HASHTABLE_CLASS::const_local_iterator::operator++() {
  cur_node_ = cur_node_->next_;
  return *this;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_local_iterator
ZORBA_HASHTABLE_CLASS::const_local_iterator::operator++(int) {
  const_local_iterator const temp( cur_node_ );
  cur_node_ = cur_node_->next_;
  return temp;
}

////////// iterator inline functions //////////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::reference
ZORBA_HASHTABLE_CLASS::iterator::operator*() const {
  return cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::pointer
ZORBA_HASHTABLE_CLASS::iterator::operator->() const {
  return &cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::iterator&
ZORBA_HASHTABLE_CLASS::iterator::operator++() {
  if ( !(cur_node_ = cur_node_->next_) )
    inc_bucket();
  return *this;
}

////////// const_iterator inline functions ////////////////////////////////////

ZORBA_HASHTABLE_TEMPLATE inline
ZORBA_HASHTABLE_CLASS::const_iterator::const_iterator( iterator const &i ) :
  cur_bkt_( i.cur_bkt_ ), cur_node_( i.cur_node_ )
{
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_reference
ZORBA_HASHTABLE_CLASS::const_iterator::operator*() const {
  return cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_pointer
ZORBA_HASHTABLE_CLASS::const_iterator::operator->() const {
  return &cur_node_->value_;
}

ZORBA_HASHTABLE_TEMPLATE inline
typename ZORBA_HASHTABLE_CLASS::const_iterator&
ZORBA_HASHTABLE_CLASS::const_iterator::operator++() {
  if ( !(cur_node_ = cur_node_->next_) )
    inc_bucket();
  return *this;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * A hash-table implementation for when KeyType is the same as ValueType.  This
 * is used as the base class for unordered_set.
 *
 * @tparam KeyType They map's key type.
 * @tparam ValueType The type the keys are mapped to.
 * @tparam KeyExtract The unary_function to use to extract a key from a value.
 * @tparam KeyHash The unary_function to use for generating hash codes.
 * @tparam KeyEqual The binary_function to use to test for key equality.
 * @tparam Allocator The allocator to use.
 * @tparam RehashPolicy The rehash policy class to use.
 */
template<
  typename KeyType,
  typename ValueType,
  class KeyExtract,
  class KeyHash,
  class KeyEqual,
  class Allocator,
  class RehashPolicy
>
class hashtable :
  public hashtable_base<KeyType,ValueType,KeyExtract,KeyHash,KeyEqual,Allocator,
                        RehashPolicy>
{
  typedef hashtable_base<KeyType,ValueType,KeyExtract,KeyHash,KeyEqual,
                         Allocator,RehashPolicy> base_type;
public:
  typedef typename base_type::key_type key_type;
  typedef typename base_type::value_type value_type;
  typedef typename base_type::hasher hasher;
  typedef typename base_type::key_equal key_equal;
  typedef typename base_type::allocator_type allocator_type;
  typedef typename base_type::size_type size_type;
  typedef typename base_type::difference_type difference_type;

  typedef typename base_type::pointer pointer;
  typedef typename base_type::const_pointer const_pointer;
  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;

  /**
   * Constructs a %hashtable.
   *
   * @param bucket_count The initial number of buckets to use.
   * @param hash The hash-code unary functor to use.
   * @param equal The key-equality functor to use.
   * @param alloc The allocator to use.
   */
  hashtable( size_type bucket_count, hasher const &hash, key_equal const &equal,
             allocator_type const &alloc ) :
    base_type( bucket_count, hash, equal, alloc )
  {
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Specialization of %hashtable for use when the "value" is actually a
 * <code>pair&lt;KeyType const,Value&gt;</code>.  This is used as the base
 * class for unordered_map.  This specialization also adds \c mapped_type,
 * \c at(), and \c operator[]() members.
 *
 * @tparam KeyType They map's key type.
 * @tparam PairType The <code>pair&lt;KeyType const,Value&gt;</code>.
 * @tparam KeyExtract The unary_function to use to extract a key from a pair.
 * @tparam KeyHash The unary_function to use for generating hash codes.
 * @tparam KeyEqual The binary_function to use to test for key equality.
 * @tparam Allocator The allocator to use.
 * @tparam RehashPolicy The rehash policy class to use.
 */
template<
  typename KeyType,
  class PairType,
  class KeyHash,
  class KeyEqual,
  class Allocator,
  class RehashPolicy
>
class hashtable<KeyType,PairType,select1st<PairType>,KeyHash,KeyEqual,
                Allocator,RehashPolicy> :
  public hashtable_base<KeyType,PairType,select1st<PairType>,KeyHash,KeyEqual,
                        Allocator,RehashPolicy>
{
  typedef hashtable_base<KeyType,PairType,select1st<PairType>,KeyHash,KeyEqual,
                         Allocator,RehashPolicy> base_type;
  typedef typename base_type::node node;
public:
  typedef typename base_type::key_type key_type;
  typedef typename base_type::value_type value_type;
  typedef typename PairType::second_type mapped_type;
  typedef typename base_type::hasher hasher;
  typedef typename base_type::key_equal key_equal;
  typedef typename base_type::allocator_type allocator_type;
  typedef typename base_type::size_type size_type;
  typedef typename base_type::difference_type difference_type;

  typedef typename base_type::pointer pointer;
  typedef typename base_type::const_pointer const_pointer;
  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;

  /**
   * Constructs a %hashtable.
   *
   * @param bucket_count The initial number of buckets to use.
   * @param hash The hash-code unary functor to use.
   * @param equal The key-equality functor to use.
   * @param alloc The allocator to use.
   */
  hashtable( size_type bucket_count, hasher const &hash, key_equal const &equal,
             allocator_type const &alloc ) :
    base_type( bucket_count, hash, equal, alloc )
  {
  }

  /**
   * Attempts to find the given \a key.
   *
   * @param key The key to find.
   * @return Returns a reference to the value associated with \a key.
   * @throws std::out_of_range if \a key is not found.
   */
  mapped_type& at( key_type const &key );

  /**
   * Attempts to find the given \a key.
   *
   * @param key The key to find.
   * @return Returns a reference to the value associated with \a key.
   * @throws std::out_of_range if \a key is not found.
   */
  mapped_type const& at( key_type const &key ) const;

  /**
   * Attempts to find the given \a key.
   *
   * @param key The key to find.
   * @return If found, returns a reference to the value associated with \a key;
   * if not, creates a new key/value pair and returns a reference to the newly
   * created value.
   */
  mapped_type& operator[]( key_type const &key );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba

#include "hashtable.tcc"

#endif  /* ZORBA_HASHTABLE_H */
/* vim:set et ts=2 sw=2: */
