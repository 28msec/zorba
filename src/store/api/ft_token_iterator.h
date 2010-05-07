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

#ifndef ZORBA_FT_TOKEN_ITERATOR_H
#define ZORBA_FT_TOKEN_ITERATOR_H

#include <vector>

#include "store/api/ft_token.h"
#include "zorbaerrors/Assert.h"

namespace zorba {

/**
 * An <code>FTTokenIterator</code> iterates over a sequence of full-text
 * tokens.
 */
class ZORBA_DLL_PUBLIC FTTokenIterator {
public:
  typedef std::vector<FTToken> FTTokens;
  typedef FTTokens::size_type index_t;

  /**
   * Constructs an FTTokenIterator.
   *
   * @param tokens  The tokens.
   * @param begin   The index of the beginning token.
   * @param end     One greater than the index of the ending token.
   */
  FTTokenIterator( FTTokens const &tokens, index_t begin, index_t end ) :
    tokens_( &tokens ), begin_( begin ), end_( end )
  {
    ZORBA_ASSERT( end <= tokens_->size() );
    ZORBA_ASSERT( begin <= end );
    pos_ = begin_;
  }

  /**
   * Gets the current token.
   *
   * @return Returns said token.
   */
  FTToken const& current() const {
    ZORBA_ASSERT( hasNext() );
    return (*tokens_)[ pos_ ];
  }

  /**
   * Checks whether there are any tokens to iterate over.
   *
   * @return Returns <code>true</code> only if there are no tokens to iterate
   * over.
   */
  bool empty() const {
    return begin_ == end_;
  }

  /**
   * Checks whether there is a next token.
   *
   * @return Returns <code>true</code> only if there is a next token.
   */
  bool hasNext() const {
    return pos_ < end_;
  }

  /**
   * Creates a new iterator for the current element.
   */
  FTTokenIterator iterator() const {
    ZORBA_ASSERT( hasNext() );
    return FTTokenIterator( *tokens_, pos_, pos_ + 1 );
  }

  /**
   * Obtains the next token and advances the iterator.
   *
   * @param ppToken A pointer to the next token is put here; may be null to
   * advance the iterator only.
   * @return Returns <code>true</code> only if there is a next token.
   */
  bool next( FTToken const **ppToken = 0 ) {
    if ( hasNext() ) {
      if ( ppToken )
        *ppToken = &current();
      ++pos_;
      return true;
    }
    return false;
  }

  /**
   * Resets this iterator to the beginning.
   */
  void reset() {
    pos_ = begin_;
  }

private:
  FTTokens const *tokens_;              // pointer to allow operator=()
  index_t begin_, end_;                 // non-const to allow operator=()
  index_t pos_;
};

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
