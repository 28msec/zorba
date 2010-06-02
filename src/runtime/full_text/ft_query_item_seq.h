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
  FTQueryItemSeqIterator( FTQueryItemSeq* );
  ~FTQueryItemSeqIterator();

  index_t begin() const;
  FTTokenIterator_t clone() const;
  bool empty() const;
  index_t end() const;
  bool hasNext() const;
  Mark_t pos() const;
  void pos( Mark_t const& );
  void pos( FTTokenIterator_t const& );
  bool next( FTToken const** = 0 );
  void reset();

private:
  typedef std::list<Mark_t> MarkSeq;

  struct LocalMark : Mark {
    MarkSeq marks_;
    FTQueryItemSeq::iterator qi_;
  };

  void init();

  FTQueryItemSeq *const qi_seq_;
  FTQueryItemSeq::iterator qi_;
  bool const delete_seq_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_QUERY_ITEM_SEQ_H */
/* vim:set et sw=2 ts=2: */
