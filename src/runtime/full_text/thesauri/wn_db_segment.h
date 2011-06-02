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
#pragma once
#ifndef ZORBA_FULL_TEXT_WORDNET_DB_SEGMENT_H
#define ZORBA_FULL_TEXT_WORDNET_DB_SEGMENT_H

// standard
#include <cassert>
#include <cstddef>                              /* for ptrdiff_t */
#include <iterator>

#include "zorbamisc/config/stdint.h"

// local
#include "common/common.h"
#include "util/mmap_file.h"

namespace zorba {
namespace wordnet {

/**
 * An instance of this class is used to access either the lemma or synset
 * segments of a binary version of a WordNet thesaurus.
 *
 * By implementing fully-blown random access iterators for it, the STL
 * algorithms work, in particular binary_search() and equal_range() that
 * are used to do look-ups.
 */
class db_segment {
public:

  ////////// typedefs /////////////////////////////////////////////////////////

  typedef char const* value_type;
  typedef value_type* const_pointer;
  typedef value_type const_reference;

  typedef uint32_t size_type;
  typedef ptrdiff_t difference_type;

  enum id_t {
    lemma  = 0,
    synset = 1
  };

  ////////// constructors /////////////////////////////////////////////////////

  /**
   * Constructs a %db_segment.
   *
   * @param file The mmap_file to access the segment within.
   * @param id The desired segment ID.
   */
  db_segment( mmap_file const &file, id_t id );

  ////////// iterators ////////////////////////////////////////////////////////

  class const_iterator;
  friend class const_iterator;

  class const_iterator :
    public std::iterator<std::random_access_iterator_tag,value_type> {
  public:
    const_iterator() : seg_( nullptr ), i_( 0 ) {
    }

    // Forward iterator requirements

    const_reference operator*() const {
      return (*seg_)[ i_ ];
    }

    const_iterator& operator++() {
      return ++i_, *this;
    }

    const_iterator operator++(int) {
      return const_iterator( seg_, i_++ );
    }

    friend bool operator==( const_iterator const &i, const_iterator const &j ) {
      return i.i_ == j.i_;
    }

    friend bool operator!=( const_iterator const &i, const_iterator const &j ) {
      return !( i == j );
    }

    // Bidirectional iterator requirements

    const_iterator& operator--() {
      return --i_, *this;
    }

    const_iterator operator--(int) {
      return const_iterator( seg_, i_-- );
    }

    // Random access iterator requirements

    const_reference operator[]( int n ) const {
      return (*seg_)[ i_ + n ];
    }

    const_iterator operator+( int n ) {
      return const_iterator( seg_, i_ + n );
    }

    const_iterator& operator+=( int n ) {
      return i_ += n, *this;
    }

    const_iterator operator-( int n ) {
      return const_iterator( seg_, i_ - n );
    }

    const_iterator& operator-=( int n ) {
      return i_ -= n, *this;
    }

    friend difference_type operator-( const_iterator const &i,
                                      const_iterator const &j ) {
      return i.i_ - j.i_;
    }

    friend bool operator<( const_iterator const &i, const_iterator const &j ) {
      return i.i_ < j.i_;
    }

    friend bool operator<=( const_iterator const &i, const_iterator const &j ) {
      return i.i_ <= j.i_;
    }

    friend bool operator>( const_iterator const &i, const_iterator const &j ) {
      return i.i_ > j.i_;
    }

    friend bool operator>=( const_iterator const &i, const_iterator const &j ) {
      return i.i_ >= j.i_;
    }

    // default copy constructor is OK
    // default assignment operator is OK
  private:
    db_segment const *seg_;
    size_type i_;

    const_iterator( db_segment const *seg, size_type i ) :
      seg_( seg ), i_( i ) { }

    friend class db_segment;
  };

  ////////// member functions /////////////////////////////////////////////////

  /**
   * Creates a new const_iterator positioned at the first segment entry.
   *
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return const_iterator( this, 0 );
  }

  /**
   * Creates a new const_iterator positioned at one past the last segment
   * entry.
   *
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return const_iterator( this, num_entries_ );
  }

  /**
   * Gets the number of entries in this segment.
   *
   * @return Returns the number of entries in this segment.
   */
  size_type size() const {
    return num_entries_;
  }

  /**
   * Gets the ith entry.
   *
   * @param i The index of the entry to get.
   * @return Returns the ith entry.
   */
  const_reference operator[]( size_type i ) const {
    assert( i < num_entries_ );
    return begin_ + offset_[i];
  }

  //////////////////////////////////////////////////////////////////////////// 

private:
  typedef uint32_t offset_type;

  mmap_file::const_iterator const begin_;
  size_type num_entries_;
  offset_type const *offset_;
};

} // namespace wordnet
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_WORDNET_DB_SEGMENT_H */
/* vim:set et sw=2 ts=2: */
