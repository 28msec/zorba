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

#ifndef ZORBA_NAIVE_FT_TOKEN_ITERATOR_H
#define ZORBA_NAIVE_FT_TOKEN_ITERATOR_H

#include <vector>

#include "store/api/ft_token_iterator.h"

namespace zorba {

/**
 * A <code>NaiveFTTokenIterator</code> is-an FTTokenIterator for the naive
 * store.
 */
class ZORBA_DLL_PUBLIC NaiveFTTokenIterator : public FTTokenIterator {
public:
  typedef std::vector<FTToken> FTTokens;

  NaiveFTTokenIterator( FTTokens const &tokens, index_t begin, index_t end );

  index_t begin() const;
  FTToken const& current() const;
  bool empty() const;
  index_t end() const;
  bool hasNext() const;
  FTTokenIterator_t iterator() const;
  bool next( FTToken const **ppToken = 0 );
  index_t pos() const;
  void pos( index_t );
  void reset();

private:
  FTTokens const *tokens_;              // pointer to allow operator=()
  index_t begin_, end_;                 // non-const to allow operator=()
  index_t pos_;
};

} // namespace zorba
#endif  /* ZORBA_NAIVE_FT_TOKEN_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
