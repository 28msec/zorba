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

#ifndef ZORBA_FULL_TEXT_WORDNET_SYNSET_LIST_H
#define ZORBA_FULL_TEXT_WORDNET_SYNSET_LIST_H

// standard
#include <iterator>

// local
#include "wn_synset.h"
#include "wn_thes_seg.h"

namespace zorba {
namespace wordnet {

/**
 * This class, given a thes_seg::const_iterator, accesses the list of synsets a
 * word is in.  Once an instance is created, the list of synsets can be
 * iterated over.
 *
 * The format of a synset entry is:
 *
 *    synset        = {pos}{#lemmas}{lemma#}...{#rels}{rel}...
 *    pos           = 'a' | 'r' | 'n' | 'v'
 *    rel           = {pos}{type}{synset#}{source_target}
 *    source_target = {source}{target} | 0
 */
class synset_list {
  typedef unsigned char byte;           // for convenience
public:

  ////////// typedefs /////////////////////////////////////////////////////////

  typedef synset value_type;
  typedef value_type const* const_pointer;
  typedef value_type const& const_reference;

  typedef int size_type;

  ////////// constructors /////////////////////////////////////////////////////

  synset_list( thes_seg::const_iterator const &i );

  ////////// iterators ////////////////////////////////////////////////////////

  class const_iterator;
  friend class const_iterator;

  class const_iterator :
    public std::iterator<std::forward_iterator_tag,value_type> {
  public:
    const_iterator() { }

    const_reference operator*() const { return v_; }

    const_pointer operator->() const { return &v_; }

    const_iterator& operator++();

    const_iterator operator++(int) {
      const_iterator const temp( *this );
      return ++*this, temp;
    }

    friend bool operator==( const_iterator const &i, const_iterator const &j ) {
      return i.b_ == j.b_;
    }

    friend bool operator!=( const_iterator const &i, const_iterator const &j ) {
      return !( i == j );
    }

    // default copy constructor is OK
    // default assignment operator is OK
  private:
    const_iterator( byte const *b ) : b_( b ) {
      if ( b_ )
        operator++();
    }

    byte const *b_;
    value_type v_;

    static byte const end_value_;
    friend class synset_list;
  };

  ////////// member functions /////////////////////////////////////////////////

  const_iterator begin() const {
    return const_iterator( b_ );
  }

  const_iterator end() const {
    return const_iterator( 0 );
  }

  size_type size() const {
    return size_;
  }

private:
  byte const  *b_;
  size_type   size_;
};

} // namespace wordnet
} // namespace zorba

#endif /* ZORBA_FULL_TEXT_WORDNET_SYNSET_LIST_H */
/* vim:set et sw=2 ts=2: */
