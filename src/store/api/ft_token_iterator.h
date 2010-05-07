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
    next_ = begin_;
  }

  /**
   * Constructs an FTTokenIterator.
   *
   * @param it      The other iterator.
   * @param begin   The index of the beginning token.
   * @param end     One greater than the index of the ending token.
   */
  FTTokenIterator( FTTokenIterator const &it, index_t begin, index_t end ) :
    tokens_( it.tokens_ ), begin_( begin ), end_( end )
  {
    next_ = begin_;
  }

  /**
   * Gets the beginning index.
   *
   * @return Returns said index.
   */
  index_t begin() const {
    return begin_;
  }

  /**
   * Gets one past the ending index.
   *
   * @return Returns said index.
   */
  index_t end() const {
    return end_;
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
    return next_ < end_;
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
        *ppToken = &((*tokens_)[ next_ ]);
      ++next_;
      return true;
    }
    return false;
  }

  /**
   * Gets the TODO
   */
  index_t index() const {
    return next_;
  }

  /**
   * Resets this iterator to the beginning.
   */
  void reset() {
    next_ = begin_;
  }

  /**
   * Gets the tokens over which this iterator is iterating.
   *
   * @return Returns said tokens.
   */
  FTTokens const& tokens() const {
    return *tokens_;
  }

private:
  FTTokens const *tokens_;              // pointer to allow operator=()
  index_t begin_, end_;                 // non-const to allow operator=()
  index_t next_;
};

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
