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

#ifndef ZORBA_FULL_TEXT_QUERY_ITEM_SEQ_H
#define ZORBA_FULL_TEXT_QUERY_ITEM_SEQ_H

#include <list>

#include "store/api/ft_token_iterator.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * This corresponds to <code>element(fts::queryItem)</code>.
 */
typedef FTTokenIterator_t FTQueryItem;

/**
 * This corresponds to <code>element(fts::queryItem)*</code>.
 */
typedef std::list<FTQueryItem> FTQueryItemSeq;

///////////////////////////////////////////////////////////////////////////////

/**
 * An FTQueryItemSeqIterator is-an FTTokenIterator that iterates over an
 * FTQueryItemSeq.
 */
class FTQueryItemSeqIterator : public FTTokenIterator {
public:
  FTQueryItemSeqIterator( FTQueryItemSeq& );

  FTQueryItem& currentItem() const {
    return *qi_;
  }

  index_t begin() const;
  FTToken const& current() const;
  bool empty() const;
  index_t end() const;
  bool hasNext() const;
  void mark( bool );
  bool next( FTToken const **ppToken = 0 );
  void reset();

private:
  FTQueryItemSeq *qi_seq_;              // pointer to allow operator=()
  FTQueryItemSeq::iterator qi_, mark_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_QUERY_ITEM_SEQ_H */
/* vim:set et sw=2 ts=2: */
