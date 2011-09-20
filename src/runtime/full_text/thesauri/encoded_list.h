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
#ifndef ZORBA_ENCODED_LIST_H
#define ZORBA_ENCODED_LIST_H

#include <cstddef>                      /* for size_t */
#include <iterator>

#include "util/cxx_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %decoder_function is the base class for decoders that are used with an
 * encoded_list.  It is similar to std::binary_function.  The reason that
 * wasn't used is because decoder functions should pass the result via the
 * second argument rather than as a return type for efficiency of large result
 * types.  A class derived from this should have a function like:
 *
 *  void operator()( mem_ptr_type *pptr, result_type *result ) const;
 *
 * @tparam ResultType The type of the decoded result.
 */
template<typename ResultType>
struct decoder_function {
  typedef char const* mem_ptr_type;
  typedef ResultType result_type;
};

/**
 * An %encoded_list wraps a list of elements encoded in a chunk of memory.  Its
 * iterator can be used to iterate over the elements decoding them on the fly.
 *
 * @tparam DecoderType The decoder to use.
 */
template<class DecoderType>
class encoded_list {
public:
  typedef DecoderType decoder_type;
  typedef typename decoder_type::mem_ptr_type mem_ptr_type;

  typedef typename decoder_type::result_type value_type;
  typedef value_type const* const_pointer;
  typedef value_type const& const_reference;
  typedef std::size_t size_type;

  /**
   * Constructs an %encoded_list.
   *
   * @param size The number of elements in the list.
   * @param begin A pointer to the first byte of the list.
   * @param decoder The decoder to use.
   */
  encoded_list( size_type size, mem_ptr_type begin,
                decoder_type const &decoder = decoder_type() ) :
    size_( size ),
    begin_( size ? begin : 0 ),
    decoder_( decoder )
  {
  }

  /**
   * A %const_iterator is used to iterate over the elements of an encoded_list
   * decoding them on the fly.
   */
  class const_iterator :
    public std::iterator<std::forward_iterator_tag,value_type> {
  public:
    const_iterator() : remaining_( 0 ), cur_ptr_( nullptr ) { }

    const_reference operator*() const {
      return value_;
    }

    const_pointer operator->() const {
      return &value_;
    }

    const_iterator& operator++() {
      advance();
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator const temp( *this );
      ++*this;
      return temp;
    }

    friend bool operator==( const_iterator const &i, const_iterator const &j ) {
      return i.cur_ptr_ == j.cur_ptr_;
    }

    friend bool operator!=( const_iterator const &i, const_iterator const &j ) {
      return !(i == j);
    }

  private:
    const_iterator( size_type size, mem_ptr_type begin,
                    decoder_type const &decoder ) :
      remaining_( size ), cur_ptr_( begin ), decoder_( decoder )
    {
      advance();
    }

    void advance() {
      if ( remaining_ ) {
        decoder_( &cur_ptr_, &value_ );
        --remaining_;
      } else
        cur_ptr_ = nullptr;
    }

    size_type remaining_;
    mem_ptr_type cur_ptr_;
    decoder_type decoder_;
    value_type value_;

    friend class encoded_list;
  };

  /**
   * Creates an iterator at the beginning of the list.
   *
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return const_iterator( size_, begin_, decoder_ );
  }

  /**
   * Creates an iterator one past the end of the list.
   *
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return const_iterator( 0, 0, decoder_ );
  }

  /**
   * Gets the number of elements in the list.
   *
   * @return Returns said number.
   */
  size_type size() const {
    return size_;
  }

private:
  size_type size_;
  mem_ptr_type begin_;
  decoder_type decoder_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_ENCODED_LIST_H */
/* vim:set et sw=2 ts=2: */
