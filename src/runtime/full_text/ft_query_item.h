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
#ifndef ZORBA_FULL_TEXT_FT_QUERY_ITEM_H
#define ZORBA_FULL_TEXT_FT_QUERY_ITEM_H

#include <list>

#include "store/api/ft_token_iterator.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * This corresponds to <code>element(fts::queryItem)</code>.  Note that the
 * specification defines \c queryItem to be a sequence of zero or more
 * <code>queryToken</code>s.
 */
typedef FTTokenIterator_t query_item_t;

/**
 * This corresponds to <code>element(fts::queryItem)*</code>.
 */
typedef std::list<query_item_t> query_item_star_t;

///////////////////////////////////////////////////////////////////////////////

/**
 * A %query_item_star_iterator is-an FTTokenIterator that iterates over a
 * query_item_star_t.
 */
class query_item_star_iterator : public FTTokenIterator {
public:
  query_item_star_iterator( query_item_star_t& );
  query_item_star_iterator( query_item_star_t* );
  ~query_item_star_iterator();

  // inherited
  index_t begin() const;
  index_t end() const;
  bool hasNext() const;
  Mark_t pos() const;
  void pos( Mark_t const& );
  FTToken const* next();
  void reset();

private:
  typedef std::list<Mark_t> MarkSeq;

  struct LocalMark : Mark {
    MarkSeq marks_;
    query_item_star_t::iterator qi_;
  };

  void init();

  query_item_star_t *const qi_star_;
  query_item_star_t::iterator qi_;
  bool const delete_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_QUERY_ITEM_H */
/* vim:set et sw=2 ts=2: */
