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

#ifndef ZORBA_FULL_TEXT_WORDNET_THES_SEG_H
#define ZORBA_FULL_TEXT_WORDNET_THES_SEG_H

// standard
#include <cstddef>                              /* for ptrdiff_t */
#include <iterator>
#include <sys/types.h>                          /* for off_t */

// local
#include "util/mmap_file.h"

namespace zorba {
namespace wordnet {

/**
 * An instance of this class is used to access either the word, stop-word,
 * file, or meta-name index portions of a generated index.
 *
 * By implementing fully-blown random access iterators for it, the STL
 * algorithms work, in particular binary_search() and equal_range() that
 * are used to do look-ups.
 */
class thes_seg {
public:

  ////////// typedefs /////////////////////////////////////////////////////////

  typedef unsigned long size_type;
  typedef ptrdiff_t difference_type;

  typedef char const* value_type;
  typedef value_type* const_pointer;
  typedef value_type const_reference;

  enum seg_id {
    ts_lemma  = 0,
    ts_synset = 1
  };

  ////////// constructors /////////////////////////////////////////////////////

  thes_seg() { }

  thes_seg( mmap_file const &file, seg_id id ) {
    set_file( file, id );
  }

  ////////// member functions /////////////////////////////////////////////////

  /**
   * Sets the thesaurus file to use by setting data members to the proper
   * positions within the thesaurus file.
   *
   * @param file TODO
   * @param id TODO
   */
  void set_file( mmap_file const &file, seg_id id );

  size_type size() const { return num_entries_; }

  const_reference operator[]( size_type i ) const {
    return begin_ + offset_[i];
  }

  ////////// iterators ////////////////////////////////////////////////////////

  class const_iterator;
  friend class const_iterator;

  class const_iterator :
    public std::iterator<std::random_access_iterator_tag,value_type> {
  public:
    const_iterator() { }

    const_reference operator*() const { return (*seg_)[ i_ ]; }

    const_iterator& operator++() {
      return ++i_, *this;
    }

    const_iterator& operator--() {
      return --i_, *this;
    }

    const_iterator operator++(int) {
      return const_iterator( seg_, i_++ );
    }

    const_iterator operator--(int) {
      return const_iterator( seg_, i_-- );
    }

    const_iterator& operator+=( int n ) {
      return i_ += n, *this;
    }

    const_iterator& operator-=( int n ) {
      return i_ -= n, *this;
    }

    friend bool operator==( const_iterator const &i, const_iterator const &j ) {
      return i.i_ == j.i_;
    }

    friend bool operator!=( const_iterator const &i, const_iterator const &j ) {
      return !( i == j );
    }

    friend const_iterator operator+( const_iterator const &i, int n ) {
      return const_iterator( i.seg_, i.i_ + n );
    }

    friend const_iterator operator-( const_iterator const &i, int n ) {
      return const_iterator( i.seg_, i.i_ - n );
    }

    friend difference_type
    operator-( const_iterator const &i, const_iterator const &j ) {
      return i.i_ - j.i_;
    }

    // default copy constructor is OK
    // default assignment operator is OK
  private:
    thes_seg const *seg_;
    size_type i_;

    const_iterator( thes_seg const *seg, size_type i ) :
      seg_( seg ), i_( i ) { }

    friend class thes_seg;
  };

  const_iterator begin() const {
    return const_iterator( this, 0 );
  }

  const_iterator end() const {
    return const_iterator( this, num_entries_ );
  }

private:
  mmap_file::const_iterator  begin_;
  size_type                  num_entries_;
  off_t const                *offset_;
};

} // namespace wordnet
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_WORDNET_THES_SEG_H */
/* vim:set et sw=2 ts=2: */
