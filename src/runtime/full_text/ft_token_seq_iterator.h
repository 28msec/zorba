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
#ifndef ZORBA_FULL_TEXT_FT_TOKEN_SEQ_ITERATOR_H
#define ZORBA_FULL_TEXT_FT_TOKEN_SEQ_ITERATOR_H

#include <vector>

#include "store/api/ft_token_iterator.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %FTTokenSeqIterator is-an FTTokenIterator that iterates over a simple
 * sequence of tokens.
 */
class FTTokenSeqIterator : public FTTokenIterator {
public:
  typedef std::vector<FTToken> FTTokens;

  FTTokenSeqIterator( FTTokens& );
  ~FTTokenSeqIterator();

  // inherited
  index_t begin() const;
  index_t end() const;
  bool hasNext() const;
  FTToken const* next();
  Mark_t pos() const;
  void pos( Mark_t const& );
  void reset();

private:
  struct LocalMark : Mark {
    LocalMark( index_t pos ) : pos_( pos ) { }
    index_t const pos_;
  };

  FTTokens tokens_;
  index_t pos_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_TOKEN_SEQ_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
