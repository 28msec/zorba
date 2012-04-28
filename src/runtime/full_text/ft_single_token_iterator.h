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
#ifndef ZORBA_FULL_TEXT_SINGLE_TOKEN_ITERATOR_H
#define ZORBA_FULL_TEXT_SINGLE_TOKEN_ITERATOR_H

#include "store/api/ft_token_iterator.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %FTSingleTokenIterator is-an FTTokenIterator that iterates over a single
 * token.  This might seem pointless, but it allows a single token to be passed
 * to a function that expects an FTTokenIterator.
 */
class FTSingleTokenIterator : public FTTokenIterator {
public:
  FTSingleTokenIterator( FTToken const&, index_t );

  // inherited
  index_t begin() const;
  index_t end() const;
  bool hasNext() const;
  Mark_t pos() const;
  void pos( Mark_t const& );
  FTToken const* next();
  void reset();

private:
  struct LocalMark : Mark {
    LocalMark( index_t pos ) : pos_( pos ) { }
    index_t const pos_;
  };

  FTToken const &token_;
  index_t const begin_;
  index_t pos_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_SINGLE_TOKEN_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
