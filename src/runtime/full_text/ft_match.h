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

#ifndef ZORBA_FULL_TEXT_FT_MATCH_H
#define ZORBA_FULL_TEXT_FT_MATCH_H

#include <algorithm>
#include <list>

#include "runtime/full_text/ft_token_span.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_string_match is a possible match of a sequence of query tokens with a
 * corresponding sequence of tokens in a document.  An ft_string_match may be
 * an ft_string_include or ft_string_exclude.
 */
struct ft_string_match : ft_token_span {

  /**
   * The query_pos attribute specifies the position of the query token in the
   * query.  This attribute is needed for FTOrders.
   */
  int_t query_pos;

  bool is_contiguous;
};

/**
 * An ft_string_include is an ft_string_match that describes an ft_token_span
 * that must be contained in the document.
 */
typedef ft_string_match ft_string_include;

/**
 * An ft_string_exclude is an ft_string_match that describes an ft_token_span
 * that must not be contained in the document.
 */
typedef ft_string_match ft_string_exclude;

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_match describes one result to the FTSelection.
 */
class ft_match {
public:
  typedef std::list<ft_string_match> string_matches_t;

  typedef string_matches_t includes_t;
  typedef string_matches_t excludes_t;

#if 0
  includes_t const& includes() const { return includes_; }
  excludes_t const& excludes() const { return excludes_; }
#endif

  mutable includes_t includes;
  excludes_t excludes;

  void sort_includes() const {
    // TODO: optimize later
    //if ( !includes_sorted_ ) {
      includes_sorted_ = true;
      includes.sort();
    //}
  }

  typedef string_matches_t ft_match::*string_match_ptr;

private:
  mutable bool includes_sorted_;
#if 0
  includes_t includes_;
  excludes_t excludes_;
#endif
};

/**
 * An ft_all_matches contains zero or more ft_match objects.
 */
typedef std::list<ft_match> ft_all_matches;

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_MATCH_H */
/* vim:set et sw=2 ts=2: */
